// ====================================================================
// Test routines for link to SUSYHD
// ====================================================================

#include "mathematica_error.hpp"
#include "mathematica_link.hpp"
#include "susyhd_input_parameters.hpp"
#include "susyhd_link.hpp"

#include <iostream>
#include <cmath>

const std::size_t num_points = 20;
static std::size_t current = 0;

SUSYHD::SUSYHD_input_parameters get_test_parameters()
{
   SUSYHD::SUSYHD_input_parameters input;

   const double m0 = 2000. + current * 100.0;
   current++;

   input.TanBeta = 20.;
   input.M1 = m0;
   input.M2 = m0;
   input.M3 = m0;
   input.Mu = m0;
   input.At = std::sqrt(6.) * m0;
   input.mQ3 = m0;
   input.mU3 = m0;
   input.mD3 = m0;
   input.mQ2 = m0;
   input.mU2 = m0;
   input.mD2 = m0;
   input.mQ1 = m0;
   input.mU1 = m0;
   input.mD1 = m0;
   input.mL3 = m0;
   input.mE3 = m0;
   input.mL2 = m0;
   input.mE2 = m0;
   input.mL1 = m0;
   input.mE1 = m0;
   input.mA = m0;

   return input;
}

int main(int argc, const char* argv[])
{
   using namespace mathematica;
   using namespace SUSYHD;

   // read the name of the SUSYHD.m package if given
   bool susyhd_not_installed = false;
   if (argc > 1) {
      susyhd_not_installed = true;
   }

   try {
      MathematicaLink kernel_link("-linkname \"math -mathlink\"");

      SUSYHDLink susyhd = (susyhd_not_installed ?
                           SUSYHDLink(&kernel_link, argv[1]) :
                           SUSYHDLink(&kernel_link));

      for (std::size_t i = 0; i < num_points; ++i) {
         SUSYHD_input_parameters input = get_test_parameters();
         double MHiggs = susyhd.calculate_MHiggs(input);
         double DeltaMHiggs = susyhd.calculate_DeltaMHiggs(input);

         std::cout << "MHiggs = " << MHiggs
                   << " +/- " << DeltaMHiggs << '\n';
      }

   } catch (const Error& error) {
      std::cout << error.what() << '\n';
   }
}
