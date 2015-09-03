// ====================================================================
// Higher order corrections for SUSYHD
// ====================================================================

#ifndef SUSYHD_HIGHER_ORDER_CORRECTIONS_H
#define SUSYHD_HIGHER_ORDER_CORRECTIONS_H

namespace SUSYHD {

struct Higher_order_corrections {
   Higher_order_corrections()
      : two_loop_at_as(true)
      , two_loop_at_at(true)
      , one_loop_ab_atau(true)
      , three_loop_as3(true)
      {}
   bool two_loop_at_as, two_loop_at_at, one_loop_ab_atau, three_loop_as3;
};

} // namespace SUSYHD

#endif
