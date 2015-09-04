// ====================================================================
// Object responsible for setting up global environment and link to
// Mathematica kernel, using MathLink or WSTP.  Basically a wrapper for
// a limited number of the routines defined in mathlink.h or wstp.h
// ====================================================================

#ifndef MATHEMATICA_LINK_H
#define MATHEMATICA_LINK_H

#include "mathematica_error_code.hpp"
#include "mathematica_packet.hpp"
#include "mathematica_types.hpp"

namespace mathematica {

class MathematicaLink {
public:
   MathematicaLink(int argc, char* argv[]);
   MathematicaLink(const char*);
   ~MathematicaLink();

   // wrappers for Put<object> methods
   void put_function(const char* s, int n);
   void put_integer(int n);
   void put_string(const char* s);
   void put_symbol(const char* s);

   // wrappers for Get<object> methods
   int get_integer();

   // helper methods for handling packets
   void next_packet();
   void new_packet();
   void end_packet();
   void wait_for_packet_of_type(Packet_type);
   void flush();

   // wrapper for getting error code of last call
   int get_error();

private:
   MathEnv env;
   MathLink link;

   MathematicaLink(const MathematicaLink&);
   MathematicaLink& operator=(const MathematicaLink&);
};

} // namespace mathematica

#endif
