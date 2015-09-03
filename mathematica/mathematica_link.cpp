
#include "mathematica_link.hpp"
#include "mathematica_error.hpp"
#include "mathematica_error_codes.hpp"

#ifdef ENABLE_MATHLINK_H
#define PREFIXED_MATH_FUNCTION(function) ML##function
#else
#define PREFIXED_MATH_FUNCTION(function) WS##function
#endif

namespace mathematica {

MathematicaLink::MathematicaLink(int argc, char* argv[])
{
   int error;
   env = PREFIXED_MATH_FUNCTION(Initialize)(0);
   if (env == static_cast<MathEnv>(0))
      throw InitializationError("Environment initialization failed in MathematicaLink(int argc, char* argv[])");
   link = PREFIXED_MATH_FUNCTION(OpenArgcArgv)(env, argc, argv, &error);
   if (link == static_cast<MathLink>(0) || error != SUCCESS) {
      PREFIXED_MATH_FUNCTION(Deinitialize)(env);
      throw LinkOpenError("Opening link failed in MathematicaLink(int argc, char* argv[])");
   }
}

MathematicaLink::MathematicaLink(const char* args)
{
   int error;
   env = PREFIXED_MATH_FUNCTION(Initialize)(0);
   if (env == static_cast<MathEnv>(0))
      throw InitializationError("Environment initialization failed in MathematicaLink(const char* args)");
   link = PREFIXED_MATH_FUNCTION(OpenString)(env, args, &error);
   if (link == static_cast<MathLink>(0) || error != SUCCESS) {
      PREFIXED_MATH_FUNCTION(Deinitialize)(env);
      throw LinkOpenError("Opening link failed in MathematicaLink(const char* args)");
   }
}

MathematicaLink::~MathematicaLink()
{
   PREFIXED_MATH_FUNCTION(Close)(link);
   PREFIXED_MATH_FUNCTION(Deinitialize)(env);
}

} // namespace mathematica
