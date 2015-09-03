// ====================================================================
// Input parameters for SUSYHD
// ====================================================================

#ifndef SUSYHD_INPUT_PARAMETERS_H
#define SUSYHD_INPUT_PARAMETERS_H

namespace SUSYHD {

struct SUSYHD_input_parameters {
   double TanBeta;
   double M1;
   double M2;
   double M3;
   double Mu;
   double At;
   double mQ3;
   double mU3;
   double mD3;
   double mQ2;
   double mU2;
   double mD2;
   double mQ1;
   double mU1;
   double mD1;
   double mL3;
   double mE3;
   double mL2;
   double mE2;
   double mL1;
   double mE1;
   double mA;

   SUSYHD_input_parameters()
      : TanBeta(0.), M1(0.), M2(0.), M3(0.)
      , Mu(0.), At(0.), mQ3(0.), mU3(0.)
      , mD3(0.), mQ2(0.), mU2(0.), mD2(0.)
      , mQ1(0.), mU1(0.), mD1(0.), mL3(0.)
      , mE3(0.), mL2(0.), mE2(0.), mL1(0.)
      , mE1(0.), mA(0.)
      {}
};

} // namespace SUSYHD

#endif
