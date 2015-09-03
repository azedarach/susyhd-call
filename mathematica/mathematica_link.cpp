
#include "mathematica_link.hpp"
#include "mathematica_error.hpp"

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

void MathematicaLink::put_function(const char* s, int n)
{
   PREFIXED_MATH_FUNCTION(PutFunction)(link, s, n);
}

void MathematicaLink::put_string(const char* s)
{
   PREFIXED_MATH_FUNCTION(PutString)(link, s);
}

void MathematicaLink::put_symbol(const char* s)
{
   PREFIXED_MATH_FUNCTION(PutSymbol)(link, s);
}

void MathematicaLink::put_integer(int n)
{
   PREFIXED_MATH_FUNCTION(PutInteger)(link, n);
}

void MathematicaLink::flush()
{
   PREFIXED_MATH_FUNCTION(Flush)(link);
}

int MathematicaLink::get_integer()
{
   int result;
   PREFIXED_MATH_FUNCTION(GetInteger)(link, &result);

   return result;
}

void MathematicaLink::next_packet()
{
   PREFIXED_MATH_FUNCTION(NextPacket)(link);
}

void MathematicaLink::new_packet()
{
   PREFIXED_MATH_FUNCTION(NewPacket)(link);
}

void MathematicaLink::end_packet()
{
   PREFIXED_MATH_FUNCTION(EndPacket)(link);
}

void MathematicaLink::wait_for_packet_of_type(Packet_type pkt)
{
   int p;
   while ((p = PREFIXED_MATH_FUNCTION(NextPacket)(link)) && p != pkt)
      PREFIXED_MATH_FUNCTION(NewPacket)(link);
}

int MathematicaLink::get_error()
{
   return PREFIXED_MATH_FUNCTION(Error)(link);
}

} // namespace mathematica
