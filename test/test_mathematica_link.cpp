// ====================================================================
// Test routines for link to Mathematica
// ====================================================================

#include "mathematica_error.hpp"
#include "mathematica_link.hpp"

#include <iostream>

int main()
{
   using namespace mathematica;

   const int a = 1;
   const int b = 1;

   int error_code = 0;
   int result = 0;
   try {
      MathematicaLink kernel_link("-linkname \"math -mathlink\"");

      kernel_link.put_function("EvaluatePacket", 1);

      kernel_link.put_function("Plus", 2);
      kernel_link.put_integer(a);
      kernel_link.put_integer(b);
      kernel_link.end_packet();

      kernel_link.wait_for_packet_of_type(mathematica::RETURN_PKT);

      result = kernel_link.get_integer();

   } catch (const Error& error) {
      error_code = 1;
      std::cout << error.what() << '\n';
   }

   if (a + b != result) {
      error_code = 1;
      std::cout << "Evaluating Plus[" << a << ", " << b
                << "] failed (result: " << result << ")\n";
   } else {
      std::cout << "Evaluating Plus[" << a << ", " << b
                << "] succeeded (result: " << result << ")\n";
   }

   return error_code;
}
