// ====================================================================
// Implementation of C++ interface for calling SUSYHD
// ====================================================================


#include "susyhd_link.hpp"

#include "mathematica_link.hpp"

namespace SUSYHD {

SUSYHDLink::SUSYHDLink()
   : kernel_link()
{
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
   return 0.;
}

double SUSYHDLink::calculate_DeltaMHiggs(const SUSYHD_input_parameters& input) const
{
   return 0.;
}

} // namespace SUSYHD
