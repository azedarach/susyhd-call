// ====================================================================
// Theoretical uncertainty sources for SUSYHD
// ====================================================================

#ifndef SUSYHD_UNCERTAINTY_SOURCES_H
#define SUSYHD_UNCERTAINTY_SOURCES_H

namespace SUSYHD {

struct Uncertainty_sources {
   Uncertainty_sources()
      : standard_model(true)
      , susy(true)
      , eft(true)
      {}
   bool standard_model, susy, eft;
};

} // namespace SUSYHD

#endif
