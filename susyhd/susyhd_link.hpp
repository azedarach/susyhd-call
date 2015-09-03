// ====================================================================
// Header file for calling SUSYHD at the C++ level
// ====================================================================

/**
 * @file susyhd.hpp
 * @brief contains class for calling the SUSYHD package
 */

#ifndef SUSYHD_H
#define SUSYHD_H

#include "susyhd_input_parameters.hpp"
#include "susyhd_higher_order_corrections.hpp"
#include "susyhd_uncertainty_sources.hpp"

#include <memory>

namespace mathematica {
class MathematicaLink;
}

namespace SUSYHD {

enum Scheme : unsigned { DRbar, OS };

class SUSYHDLink {
public:
   SUSYHDLink();
   ~SUSYHDLink();

   double get_alphas_at_MZ() const;
   double get_OS_mt() const;

   void set_scheme(Scheme s) { input_scheme = s; }
   void set_Rscale(double scale) { input_scale = scale; }
   void set_split(bool flag) { use_split_susy = flag; }
   void set_hiOrd(const Higher_order_corrections& h) {
      corrections = h;
   }
   void set_RscaleSplit(double scale) { split_scale = scale; }
   void set_numerical(bool flag) { numerical_rges = flag; }
   void set_sources(const Uncertainty_sources& s) {
      theory_errors = s;
   }

   void set_sm_parameters_from_OS_mt(double, double);
   void set_sm_parameters_from_ytMSbar(double, double);

   double calculate_MHiggs(const SUSYHD_input_parameters&) const;
   double calculate_DeltaMHiggs(const SUSYHD_input_parameters&) const;

private:
   Scheme input_scheme;
   double input_scale;
   double split_scale;
   bool use_split_susy;
   bool numerical_rges;
   Higher_order_corrections corrections;
   Uncertainty_sources theory_errors;
   std::shared_ptr<mathematica::MathematicaLink> kernel_link;
};

} // namespace SUSYHD

#endif
