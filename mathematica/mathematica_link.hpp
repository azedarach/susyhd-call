// ====================================================================
// Object responsible for setting up global environment and link to
// Mathematica kernel, using MathLink or WSTP.  Basically a wrapper for
// a limited number of the routines defined in mathlink.h or wstp.h
// ====================================================================

#ifndef MATHEMATICA_LINK_H
#define MATHEMATICA_LINK_H

#include "mathematica_types.hpp"

namespace mathematica {

class MathematicaLink {
public:
   MathematicaLink(int argc, char* argv[]);
   MathematicaLink(const char*);
   ~MathematicaLink();

   // wrappers for Put<object> methods
//   int put_function(const char* s, int n);
//   int put_string(const char* s);
//   int put_symbol(const char* s);

   // wrapper for getting error code of last call
//   int get_error();

private:
   MathEnv env;
   MathLink link;
};

} // namespace mathematica

#endif
