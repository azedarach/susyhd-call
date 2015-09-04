// ====================================================================
// Implementation of C++ interface for calling SUSYHD
// ====================================================================

#include "susyhd_link.hpp"
#include "mathematica_link.hpp"

namespace SUSYHD {

SUSYHDLink::SUSYHDLink(mathematica::MathematicaLink* link)
   : input_scheme(DRbar)
   , input_scale(0.)
   , split_scale(0.)
   , use_split_susy(false)
   , numerical_rges(false)
   , corrections()
   , theory_errors()
   , kernel_link(link)
{
   load_susyhd_package();
}

SUSYHDLink::SUSYHDLink(mathematica::MathematicaLink* link, const char* package_name)
   : input_scheme(DRbar)
   , input_scale(0.)
   , split_scale(0.)
   , use_split_susy(false)
   , numerical_rges(false)
   , corrections()
   , theory_errors()
   , kernel_link(link)
{
   load_susyhd_package(package_name);
}

SUSYHDLink::~SUSYHDLink()
{
}

double SUSYHDLink::get_alphas_at_MZ() const
{
   // might not be possible...
   return 0.;
}

double SUSYHDLink::get_OS_mt() const
{
   // might not be possible...
   return 0.;
}

void SUSYHDLink::set_sm_parameters_from_OS_mt(double mt, double alphas)
{

}

void SUSYHDLink::set_sm_parameters_from_ytMSbar(double yt, double alphas)
{

}

double SUSYHDLink::calculate_MHiggs(const SUSYHD_input_parameters& input) const
{
   double mass = 0.;

   if (kernel_link) {
      kernel_link->put_function("EvaluatePacket", 1);

      kernel_link->put_function("SUSYHD`MHiggs", 7);

      // parameter values (temporary implementation)
      kernel_link->put_function("List", 22);
      kernel_link->put_real(input.TanBeta);
      kernel_link->put_real(input.M1);
      kernel_link->put_real(input.M2);
      kernel_link->put_real(input.M3);
      kernel_link->put_real(input.Mu);
      kernel_link->put_real(input.At);
      kernel_link->put_real(input.mQ3);
      kernel_link->put_real(input.mU3);
      kernel_link->put_real(input.mD3);
      kernel_link->put_real(input.mQ2);
      kernel_link->put_real(input.mU2);
      kernel_link->put_real(input.mD2);
      kernel_link->put_real(input.mQ1);
      kernel_link->put_real(input.mU1);
      kernel_link->put_real(input.mD1);
      kernel_link->put_real(input.mL3);
      kernel_link->put_real(input.mE3);
      kernel_link->put_real(input.mL2);
      kernel_link->put_real(input.mE2);
      kernel_link->put_real(input.mL1);
      kernel_link->put_real(input.mE1);
      kernel_link->put_real(input.mA);

      // option values
      kernel_link->put_function("Rule", 2);
      kernel_link->put_symbol("scheme");
      if (input_scheme == DRbar)
         kernel_link->put_string("DRbar");
      else
         kernel_link->put_string("OS");

      kernel_link->put_function("Rule", 2);
      kernel_link->put_symbol("hiOrd");
      kernel_link->put_function("List", 4);
      if (corrections.two_loop_at_as)
         kernel_link->put_integer(1);
      else
         kernel_link->put_integer(0);
      if (corrections.two_loop_at_at)
         kernel_link->put_integer(1);
      else
         kernel_link->put_integer(0);
      if (corrections.one_loop_ab_atau)
         kernel_link->put_integer(1);
      else
         kernel_link->put_integer(0);
      if (corrections.three_loop_as3)
         kernel_link->put_integer(1);
      else
         kernel_link->put_integer(0);

      kernel_link->put_function("Rule", 2);
      kernel_link->put_symbol("Rscale");
      kernel_link->put_real(input_scale);

      kernel_link->put_function("Rule", 2);
      kernel_link->put_symbol("split");
      if (use_split_susy)
         kernel_link->put_symbol("True");
      else
         kernel_link->put_symbol("False");

      kernel_link->put_function("Rule", 2);
      kernel_link->put_symbol("RscaleSplit");
      kernel_link->put_real(split_scale);

      kernel_link->put_function("Rule", 2);
      kernel_link->put_symbol("numerical");
      if (numerical_rges)
         kernel_link->put_symbol("True");
      else
         kernel_link->put_symbol("False");

      kernel_link->end_packet();

      kernel_link->wait_for_packet_of_type(mathematica::RETURN_PKT);

      mass = kernel_link->get_real();
   }

   return mass;
}

double SUSYHDLink::calculate_DeltaMHiggs(const SUSYHD_input_parameters& input) const
{
   // not yet implemented
   return 0.;
}

void SUSYHDLink::load_susyhd_package(const char* package_name)
{
   if (kernel_link) {
      kernel_link->put_function("EvaluatePacket", 1);
      kernel_link->put_function("Get", 1);
      kernel_link->put_string(package_name);
      kernel_link->end_packet();

      // discard null return packet
      kernel_link->wait_for_packet_of_type(mathematica::RETURN_PKT);
      kernel_link->new_packet();
   }
}

} // namespace SUSYHD
