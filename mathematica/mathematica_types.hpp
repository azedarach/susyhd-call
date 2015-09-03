// ====================================================================
// typedefs for some types used for linking to Mathematica using
// MathLink or WSTP
// ====================================================================

#ifndef MATHEMATICA_TYPES_H
#define MATHEMATICA_TYPES_H

#include "mathematica_config.h"

#ifdef ENABLE_MATHLINK_H
#include <mathlink.h>
#else
#include <wstp.h>
#endif

namespace mathematica {

#ifdef ENABLE_MATHLINK_H

typedef MLENV MathEnv;
typedef MLINK MathLink;

#else

typedef WSENV MathEnv;
typedef WSLINK MathLink;

#endif

} // namespace mathematica

#endif
