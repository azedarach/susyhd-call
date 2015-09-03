// ====================================================================
// Packet types for Mathematica
// ====================================================================


#ifndef MATHEMATICA_PACKET_H
#define MATHEMATICA_PACKET_H

#include "mathematica_config.h"

#ifdef ENABLE_MATHLINK_H
#include <mathlink.h>
#else
#include <wstp.h>
#endif

namespace mathematica {

enum Packet_type : int {
   ILLEGAL_PKT = ILLEGALPKT,
   CALL_PKT = CALLPKT,
   EVALUATE_PKT = EVALUATEPKT,
   RETURN_PKT = RETURNPKT,
   INPUT_NAME_PKT = INPUTNAMEPKT,
   ENTER_TEXT_PKT = ENTERTEXTPKT,
   ENTER_EXPR_PKT = ENTEREXPRPKT,
   OUTPUT_NAME_PKT = OUTPUTNAMEPKT,
   RETURN_TEXT_PKT = RETURNTEXTPKT,
   RETURN_EXPR_PKT = RETURNEXPRPKT,
   DISPLAY_PKT = DISPLAYPKT,
   DISPLAY_END_PKT = DISPLAYENDPKT,
   MESSAGE_PKT = MESSAGEPKT,
   TEXT_PKT = TEXTPKT,
   INPUT_PKT = INPUTPKT,
   INPUT_STR_PKT = INPUTSTRPKT,
   MENU_PKT = MENUPKT,
   SYNTAX_PKT = SYNTAXPKT,
   SUSPEND_PKT = SUSPENDPKT,
   RESUME_PKT = RESUMEPKT,
   BEGIN_DLG_PKT = BEGINDLGPKT,
   END_DLG_PKT = ENDDLGPKT,
   FIRST_USER_PKT = FIRSTUSERPKT,
   LAST_USER_PKT = LASTUSERPKT
};

} // namespace mathematica

#endif
