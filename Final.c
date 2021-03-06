/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Final.c
 *
 * Code generated for Simulink model 'Final'.
 *
 * Model version                  : 1.180
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Wed May 13 10:38:00 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Final.h"
#include "Final_private.h"

/* Block signals (default storage) */
B_Final_T Final_B;

/* Continuous states */
X_Final_T Final_X;

/* Periodic continuous states */
PeriodicIndX_Final_T Final_PeriodicIndX;
PeriodicRngX_Final_T Final_PeriodicRngX;

/* Block states (default storage) */
DW_Final_T Final_DW;

/* External inputs (root inport signals with default storage) */
ExtU_Final_T Final_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_Final_T Final_Y;

/* Real-time model */
RT_MODEL_Final_T Final_M_;
RT_MODEL_Final_T *const Final_M = &Final_M_;
uint32_T plook_binx(real_T u, const real_T bp[], uint32_T maxIndex, real_T
                    *fraction)
{
  uint32_T bpIndex;

  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u <= bp[0U]) {
    bpIndex = 0U;
    *fraction = (u - bp[0U]) / (bp[1U] - bp[0U]);
  } else if (u < bp[maxIndex]) {
    bpIndex = binsearch_u32d(u, bp, maxIndex >> 1U, maxIndex);
    *fraction = (u - bp[bpIndex]) / (bp[bpIndex + 1U] - bp[bpIndex]);
  } else {
    bpIndex = maxIndex - 1U;
    *fraction = (u - bp[maxIndex - 1U]) / (bp[maxIndex] - bp[maxIndex - 1U]);
  }

  return bpIndex;
}

real_T intrp1d_l_pw(uint32_T bpIndex, real_T frac, const real_T table[])
{
  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  return (table[bpIndex + 1U] - table[bpIndex]) * frac + table[bpIndex];
}

int32_T plook_s32dd_binx(real_T u, const real_T bp[], uint32_T maxIndex, real_T *
  fraction)
{
  int32_T bpIndex;

  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u <= bp[0U]) {
    bpIndex = 0;
    *fraction = (u - bp[0U]) / (bp[1U] - bp[0U]);
  } else if (u < bp[maxIndex]) {
    bpIndex = binsearch_s32d(u, bp, maxIndex >> 1U, maxIndex);
    *fraction = (u - bp[(uint32_T)bpIndex]) / (bp[bpIndex + 1U] - bp[(uint32_T)
      bpIndex]);
  } else {
    bpIndex = (int32_T)(maxIndex - 1U);
    *fraction = (u - bp[maxIndex - 1U]) / (bp[maxIndex] - bp[maxIndex - 1U]);
  }

  return bpIndex;
}

real_T intrp2d_s32dl_pw(const int32_T bpIndex[], const real_T frac[], const
  real_T table[], const uint32_T stride)
{
  real_T yL_1d;
  uint32_T offset_1d;

  /* Column-major Interpolation 2-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  offset_1d = (uint32_T)(bpIndex[1U] * (int32_T)stride) + bpIndex[0U];
  yL_1d = (table[offset_1d + 1U] - table[offset_1d]) * frac[0U] +
    table[offset_1d];
  offset_1d += stride;
  return (((table[offset_1d + 1U] - table[offset_1d]) * frac[0U] +
           table[offset_1d]) - yL_1d) * frac[1U] + yL_1d;
}

real_T intrp1d_s32dl_pw(int32_T bpIndex, real_T frac, const real_T table[])
{
  uint32_T offset_0d;

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  offset_0d = (uint32_T)bpIndex;
  return (table[offset_0d + 1U] - table[offset_0d]) * frac + table[offset_0d];
}

real_T look1_plinlcpw(real_T u0, const real_T bp0[], const real_T table[],
                      uint32_T prevIndex[], uint32_T maxIndex)
{
  real_T frac;
  uint32_T bpIdx;

  /* Column-major Lookup 1-D
     Search method: 'linear'
     Use previous index: 'on'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Clip'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'linear'
     Extrapolation method: 'Clip'
     Use previous index: 'on'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    bpIdx = 0U;
    frac = 0.0;
  } else if (u0 < bp0[maxIndex]) {
    /* Linear Search */
    for (bpIdx = prevIndex[0U]; u0 < bp0[bpIdx]; bpIdx--) {
    }

    while (u0 >= bp0[bpIdx + 1U]) {
      bpIdx++;
    }

    frac = (u0 - bp0[bpIdx]) / (bp0[bpIdx + 1U] - bp0[bpIdx]);
  } else {
    bpIdx = maxIndex - 1U;
    frac = 1.0;
  }

  prevIndex[0U] = bpIdx;

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  return (table[bpIdx + 1U] - table[bpIdx]) * frac + table[bpIdx];
}

uint32_T binsearch_u32d(real_T u, const real_T bp[], uint32_T startIndex,
  uint32_T maxIndex)
{
  uint32_T bpIndex;
  uint32_T iRght;
  uint32_T bpIdx;

  /* Binary Search */
  bpIdx = startIndex;
  bpIndex = 0U;
  iRght = maxIndex;
  while (iRght - bpIndex > 1U) {
    if (u < bp[bpIdx]) {
      iRght = bpIdx;
    } else {
      bpIndex = bpIdx;
    }

    bpIdx = (iRght + bpIndex) >> 1U;
  }

  return bpIndex;
}

int32_T binsearch_s32d(real_T u, const real_T bp[], uint32_T startIndex,
  uint32_T maxIndex)
{
  uint32_T iRght;
  uint32_T iLeft;
  uint32_T bpIdx;

  /* Binary Search */
  bpIdx = startIndex;
  iLeft = 0U;
  iRght = maxIndex;
  while (iRght - iLeft > 1U) {
    if (u < bp[bpIdx]) {
      iRght = bpIdx;
    } else {
      iLeft = bpIdx;
    }

    bpIdx = (iRght + iLeft) >> 1U;
  }

  return (int32_T)iLeft;
}

/* State reduction function */
void local_stateReduction(real_T* x, int_T* p, int_T n, real_T* r)
{
  int_T i, j;
  for (i = 0, j = 0; i < n; ++i, ++j) {
    int_T k = p[i];
    real_T lb = r[j++];
    real_T xk = x[k]-lb;
    real_T rk = r[j]-lb;
    int_T q = (int_T) floor(xk/rk);
    if (q) {
      x[k] = xk-q*rk+lb;
    }
  }
}

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 6;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  Final_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  Final_step();
  Final_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  Final_step();
  Final_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  local_stateReduction(x, rtsiGetPeriodicContStateIndices(si), 1,
                       rtsiGetPeriodicContStateRanges(si));
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  int32_T u0_0;
  int32_T u1_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      u0_0 = 1;
    } else {
      u0_0 = -1;
    }

    if (u1 > 0.0) {
      u1_0 = 1;
    } else {
      u1_0 = -1;
    }

    y = atan2(u0_0, u1_0);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

/* Model step function */
void Final_step(void)
{
  real_T rtb_TrigonometricFunction;
  real_T rtb_u2rhoV2;
  uint32_T rtb_Prelookup_o1;
  real_T rtb_CM;
  real_T rtb_CD;
  real_T rtb_Gain_j;
  real_T rtb_Fz_tot;
  int32_T rtb_Prelookup_o1_g;
  real_T rtb_CM_el;
  real_T rtb_Product3_g;
  real_T rtb_gain2_f;
  real_T rtb_sincos_o2_a;
  real_T rtb_Square1;
  real_T rtb_Product_m;
  real_T rtb_Transpose[9];
  real_T rtb_sincos_o1_f[3];
  real_T rtb_UnaryMinus;
  real_T rtb_sincos_o2[3];
  real_T rtb_Product_h[3];
  real_T frac[2];
  int32_T bpIndex[2];
  real_T rtb_TrigonometricFunction_tmp;
  real_T rtb_Gain1_tmp;
  real_T rtb_Transpose_0[9];
  real_T rtb_sincos_o2_tmp;
  if (rtmIsMajorTimeStep(Final_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&Final_M->solverInfo,((Final_M->Timing.clockTick0+1)*
      Final_M->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(Final_M)) {
    Final_M->Timing.t[0] = rtsiGetT(&Final_M->solverInfo);
  }

  /* Trigonometry: '<S15>/sincos' incorporates:
   *  Integrator: '<S7>/Theta'
   *  Trigonometry: '<S11>/sincos'
   */
  rtb_sincos_o2_tmp = cos(Final_X.Theta_CSTATE);
  rtb_u2rhoV2 = sin(Final_X.Theta_CSTATE);

  /* Fcn: '<S15>/Fcn11' incorporates:
   *  Trigonometry: '<S15>/sincos'
   */
  rtb_Transpose[0] = rtb_sincos_o2_tmp;

  /* Fcn: '<S15>/Fcn21' */
  rtb_Transpose[1] = 0.0 * rtb_u2rhoV2;

  /* Fcn: '<S15>/Fcn31' */
  rtb_Transpose[2] = rtb_u2rhoV2;

  /* Fcn: '<S15>/Fcn12' incorporates:
   *  Trigonometry: '<S15>/sincos'
   */
  rtb_Transpose[3] = rtb_sincos_o2_tmp * 0.0;

  /* Fcn: '<S15>/Fcn22' */
  rtb_Transpose[4] = 0.0 * rtb_u2rhoV2 * 0.0 + 1.0;

  /* Fcn: '<S15>/Fcn32' */
  rtb_Transpose[5] = rtb_u2rhoV2 * 0.0;

  /* Fcn: '<S15>/Fcn13' */
  rtb_Transpose[6] = -rtb_u2rhoV2;

  /* Fcn: '<S15>/Fcn23' incorporates:
   *  Trigonometry: '<S15>/sincos'
   */
  rtb_Transpose[7] = 0.0 * rtb_sincos_o2_tmp;

  /* Fcn: '<S15>/Fcn33' incorporates:
   *  Trigonometry: '<S15>/sincos'
   */
  rtb_Transpose[8] = rtb_sincos_o2_tmp;

  /* Math: '<S12>/Transpose' */
  for (rtb_Prelookup_o1_g = 0; rtb_Prelookup_o1_g < 3; rtb_Prelookup_o1_g++) {
    rtb_Transpose_0[3 * rtb_Prelookup_o1_g] = rtb_Transpose[rtb_Prelookup_o1_g];
    rtb_Transpose_0[3 * rtb_Prelookup_o1_g + 1] =
      rtb_Transpose[rtb_Prelookup_o1_g + 3];
    rtb_Transpose_0[3 * rtb_Prelookup_o1_g + 2] =
      rtb_Transpose[rtb_Prelookup_o1_g + 6];
  }

  memcpy(&rtb_Transpose[0], &rtb_Transpose_0[0], 9U * sizeof(real_T));

  /* End of Math: '<S12>/Transpose' */

  /* Integrator: '<S7>/U,w' incorporates:
   *  Constant: '<S7>/U0'
   *  Constant: '<S7>/w0'
   *  SignalConversion generated from: '<S7>/U,w'
   */
  if (Final_DW.Uw_IWORK != 0) {
    Final_X.Uw_CSTATE[0] = 0.0;
    Final_X.Uw_CSTATE[1] = 0.0;
  }

  /* SignalConversion generated from: '<S8>/sincos' incorporates:
   *  Integrator: '<S7>/Theta'
   */
  rtb_sincos_o1_f[0] = 0.0;
  rtb_sincos_o1_f[1] = Final_X.Theta_CSTATE;
  rtb_sincos_o1_f[2] = 0.0;
  for (rtb_Prelookup_o1_g = 0; rtb_Prelookup_o1_g < 3; rtb_Prelookup_o1_g++) {
    /* Trigonometry: '<S8>/sincos' */
    rtb_Product_h[rtb_Prelookup_o1_g] = cos(rtb_sincos_o1_f[rtb_Prelookup_o1_g]);

    /* Product: '<S12>/Product' incorporates:
     *  Integrator: '<S7>/U,w'
     *  SignalConversion generated from: '<S12>/Product'
     */
    rtb_sincos_o2[rtb_Prelookup_o1_g] = rtb_Transpose[rtb_Prelookup_o1_g + 6] *
      Final_X.Uw_CSTATE[1] + (rtb_Transpose[rtb_Prelookup_o1_g + 3] * 0.0 +
      rtb_Transpose[rtb_Prelookup_o1_g] * Final_X.Uw_CSTATE[0]);

    /* Trigonometry: '<S8>/sincos' */
    rtb_sincos_o1_f[rtb_Prelookup_o1_g] = sin(rtb_sincos_o1_f[rtb_Prelookup_o1_g]);
  }

  /* Fcn: '<S8>/Fcn11' */
  rtb_Transpose[0] = rtb_Product_h[1] * rtb_Product_h[0];

  /* Fcn: '<S8>/Fcn21' incorporates:
   *  Fcn: '<S8>/Fcn22'
   */
  rtb_u2rhoV2 = rtb_sincos_o1_f[2] * rtb_sincos_o1_f[1];
  rtb_Transpose[1] = rtb_u2rhoV2 * rtb_Product_h[0] - rtb_Product_h[2] *
    rtb_sincos_o1_f[0];

  /* Fcn: '<S8>/Fcn31' incorporates:
   *  Fcn: '<S8>/Fcn32'
   */
  rtb_CM = rtb_Product_h[2] * rtb_sincos_o1_f[1];
  rtb_Transpose[2] = rtb_CM * rtb_Product_h[0] + rtb_sincos_o1_f[2] *
    rtb_sincos_o1_f[0];

  /* Fcn: '<S8>/Fcn12' */
  rtb_Transpose[3] = rtb_Product_h[1] * rtb_sincos_o1_f[0];

  /* Fcn: '<S8>/Fcn22' */
  rtb_Transpose[4] = rtb_u2rhoV2 * rtb_sincos_o1_f[0] + rtb_Product_h[2] *
    rtb_Product_h[0];

  /* Fcn: '<S8>/Fcn32' */
  rtb_Transpose[5] = rtb_CM * rtb_sincos_o1_f[0] - rtb_sincos_o1_f[2] *
    rtb_Product_h[0];

  /* Fcn: '<S8>/Fcn13' */
  rtb_Transpose[6] = -rtb_sincos_o1_f[1];

  /* Fcn: '<S8>/Fcn23' */
  rtb_Transpose[7] = rtb_sincos_o1_f[2] * rtb_Product_h[1];

  /* Fcn: '<S8>/Fcn33' */
  rtb_Transpose[8] = rtb_Product_h[2] * rtb_Product_h[1];

  /* Product: '<S1>/Product' */
  for (rtb_Prelookup_o1_g = 0; rtb_Prelookup_o1_g < 3; rtb_Prelookup_o1_g++) {
    rtb_Product_h[rtb_Prelookup_o1_g] = rtb_Transpose[rtb_Prelookup_o1_g + 6] *
      Final_ConstB.Gain[2] + (rtb_Transpose[rtb_Prelookup_o1_g + 3] *
      Final_ConstB.Gain[1] + rtb_Transpose[rtb_Prelookup_o1_g] *
      Final_ConstB.Gain[0]);
  }

  /* End of Product: '<S1>/Product' */

  /* Gain: '<S19>/1//2rhoV^2' incorporates:
   *  Constant: '<S29>/Constant3'
   *  Integrator: '<S7>/U,w'
   *  Product: '<S19>/Product2'
   *  Product: '<S24>/Product'
   *  Product: '<S24>/Product1'
   *  Product: '<S24>/Product2'
   *  Sum: '<S24>/Sum'
   *  Sum: '<S2>/Sum'
   */
  rtb_u2rhoV2 = (((Final_X.Uw_CSTATE[0] - 10.0) * (Final_X.Uw_CSTATE[0] - 10.0)
                  + 0.0 * 0.0) + Final_X.Uw_CSTATE[1] * Final_X.Uw_CSTATE[1]) *
    1.00649 * 0.5;

  /* Trigonometry: '<S21>/Incidence' incorporates:
   *  Integrator: '<S7>/U,w'
   */
  Final_Y.Alpha = rt_atan2d_snf(Final_X.Uw_CSTATE[1], Final_X.Uw_CSTATE[0]);

  /* Trigonometry: '<S22>/Trigonometric Function' incorporates:
   *  Trigonometry: '<S23>/Trigonometric Function'
   *  Trigonometry: '<S5>/Trigonometric Function'
   */
  rtb_TrigonometricFunction_tmp = sin(Final_Y.Alpha);
  rtb_Gain1_tmp = cos(Final_Y.Alpha);

  /* UnitConversion: '<S26>/Unit Conversion' */
  /* Unit Conversion - from: rad to: deg
     Expression: output = (57.2958*input) + (0) */
  rtb_CM = 57.295779513082323 * Final_Y.Alpha;

  /* PreLookup: '<S22>/Prelookup' */
  rtb_Prelookup_o1 = plook_binx(rtb_CM, Final_ConstP.pooled3, 9U, &rtb_CM);

  /* Interpolation_n-D: '<S22>/CD' */
  rtb_CD = intrp1d_l_pw(rtb_Prelookup_o1, rtb_CM, Final_ConstP.CD_Table);

  /* Interpolation_n-D: '<S22>/CL' */
  rtb_Gain_j = intrp1d_l_pw(rtb_Prelookup_o1, rtb_CM, Final_ConstP.CL_Table);

  /* UnitConversion: '<S27>/Unit Conversion' */
  /* Unit Conversion - from: rad to: deg
     Expression: output = (57.2958*input) + (0) */
  rtb_Fz_tot = 57.295779513082323 * Final_Y.Alpha;

  /* Interpolation_n-D: '<S23>/CD_el' incorporates:
   *  PreLookup: '<S23>/Prelookup1'
   */
  bpIndex[0] = plook_s32dd_binx(rtb_Fz_tot, Final_ConstP.pooled3, 9U,
    &rtb_Fz_tot);

  /* UnitConversion: '<S28>/Unit Conversion' incorporates:
   *  Gain: '<S3>/Gain1'
   *  Inport: '<Root>/Elevator command'
   */
  /* Unit Conversion - from: rad to: deg
     Expression: output = (57.2958*input) + (0) */
  rtb_CM_el = 0.017453292519943295 * Final_U.Elevatorcommand *
    57.295779513082323;

  /* PreLookup: '<S23>/Prelookup' */
  rtb_Prelookup_o1_g = plook_s32dd_binx(rtb_CM_el,
    Final_ConstP.Prelookup_BreakpointsData, 4U, &rtb_CM_el);

  /* Interpolation_n-D: '<S23>/CD_el' */
  frac[0] = rtb_Fz_tot;
  frac[1] = rtb_CM_el;
  bpIndex[1] = rtb_Prelookup_o1_g;
  rtb_Fz_tot = intrp2d_s32dl_pw(bpIndex, frac, Final_ConstP.CD_el_Table, 10U);

  /* Interpolation_n-D: '<S23>/CL_el' */
  rtb_gain2_f = intrp1d_s32dl_pw(rtb_Prelookup_o1_g, rtb_CM_el,
    Final_ConstP.CL_el_Table);

  /* Sum: '<S2>/Fx_tot' incorporates:
   *  Gain: '<S18>/gain1'
   *  Gain: '<S20>/gain1'
   *  Gain: '<S22>/coeffAdjust2'
   *  Gain: '<S23>/coeffAdjust'
   *  Gain: '<S23>/coeffAdjust1'
   *  Product: '<S18>/Product2'
   *  Product: '<S20>/Product2'
   *  Product: '<S22>/Product2'
   *  Product: '<S22>/Product3'
   *  Product: '<S23>/Product2'
   *  Product: '<S23>/Product3'
   *  Sum: '<S22>/Sum1'
   *  Sum: '<S23>/Sum1'
   *  Trigonometry: '<S22>/Trigonometric Function'
   */
  rtb_UnaryMinus = (-(rtb_Gain1_tmp * rtb_CD) + rtb_TrigonometricFunction_tmp *
                    rtb_Gain_j) * rtb_u2rhoV2 * 0.74 + (-(rtb_Gain1_tmp *
    rtb_Fz_tot) + rtb_TrigonometricFunction_tmp * -rtb_gain2_f) * rtb_u2rhoV2 *
    0.74;

  /* Gain: '<S20>/gain2 ' incorporates:
   *  Gain: '<S23>/coeffAdjust2'
   *  Product: '<S20>/Product3'
   *  Product: '<S23>/Product'
   *  Product: '<S23>/Product1'
   *  Sum: '<S23>/Sum'
   */
  rtb_gain2_f = (-(rtb_TrigonometricFunction_tmp * rtb_Fz_tot) + rtb_Gain1_tmp *
                 rtb_gain2_f) * rtb_u2rhoV2 * 0.74;

  /* Lookup_n-D: '<S5>/Thrust' incorporates:
   *  Inport: '<Root>/throttle'
   */
  rtb_Fz_tot = look1_plinlcpw(Final_U.throttle, Final_ConstP.Thrust_bp01Data,
    Final_ConstP.Thrust_tableData, &Final_DW.m_bpIndex, 6U);

  /* Product: '<S5>/Product3' */
  rtb_Product3_g = rtb_Gain1_tmp * rtb_Fz_tot;

  /* Product: '<S5>/Product1' */
  rtb_Fz_tot *= rtb_TrigonometricFunction_tmp;

  /* Trigonometry: '<S1>/Trigonometric Function' incorporates:
   *  Gain: '<S1>/Gain1'
   *  Integrator: '<S7>/Position'
   *  Product: '<S1>/Divide'
   */
  rtb_TrigonometricFunction = atan(-Final_X.Position_CSTATE[1] /
    Final_X.Position_CSTATE[0]);

  /* Sqrt: '<S2>/Sqrt' incorporates:
   *  Constant: '<S29>/Constant3'
   *  Gain: '<S2>/Gain'
   *  Product: '<S2>/Divide'
   */
  Final_Y.Airspeed = sqrt(2.0 * rtb_u2rhoV2 / 1.00649);

  /* Trigonometry: '<S2>/Cos' incorporates:
   *  Trigonometry: '<S6>/Cos'
   */
  rtb_Product_m = cos(rtb_TrigonometricFunction);

  /* Sum: '<S2>/Va' incorporates:
   *  Inport: '<Root>/Vreel'
   *  Product: '<S2>/Product'
   *  Trigonometry: '<S2>/Cos'
   */
  rtb_sincos_o2_a = rtb_Product_m * Final_Y.Airspeed - Final_U.Vreel;

  /* Math: '<S2>/Square1' */
  rtb_Square1 = rtb_sincos_o2_a * rtb_sincos_o2_a;

  /* Product: '<S2>/Divide1' incorporates:
   *  Constant: '<S2>/Add_Cable_Drag'
   *  Product: '<S2>/Product2'
   */
  rtb_sincos_o2_a = rtb_Gain_j / (20.0 * rtb_CD);

  /* Gain: '<S18>/gain2' incorporates:
   *  Math: '<S2>/Square'
   *  Product: '<S2>/Product1'
   */
  rtb_sincos_o2_a = rtb_Square1 * Final_ConstB.Gain1 * rtb_Gain_j *
    (rtb_sincos_o2_a * rtb_sincos_o2_a) * 0.74;

  /* Product: '<S6>/Product' */
  rtb_Product_m *= rtb_sincos_o2_a;

  /* Product: '<S6>/Product1' incorporates:
   *  Trigonometry: '<S6>/Sin'
   */
  rtb_sincos_o2_a *= sin(rtb_TrigonometricFunction);

  /* Sum: '<S7>/Sum' incorporates:
   *  Constant: '<S10>/Constant'
   *  Constant: '<S7>/gravity'
   *  Gain: '<S18>/gain2 '
   *  Gain: '<S22>/coeffAdjust1'
   *  Gain: '<S22>/coeffAdjust3'
   *  Gain: '<S6>/Gain'
   *  Integrator: '<S7>/Theta'
   *  Product: '<S11>/Product'
   *  Product: '<S18>/Product3'
   *  Product: '<S22>/Product'
   *  Product: '<S22>/Product1'
   *  Product: '<S7>/Product1'
   *  Sum: '<Root>/Sum2'
   *  Sum: '<Root>/Sum3'
   *  Sum: '<S1>/Sum2'
   *  Sum: '<S22>/Sum'
   *  Sum: '<S2>/Fz_tot'
   *  Trigonometry: '<S11>/sincos'
   *  Trigonometry: '<S22>/Trigonometric Function'
   *  UnaryMinus: '<S11>/Unary Minus'
   */
  Final_Y.fiftyTheta[0] = (((rtb_Product3_g + -rtb_Product_m) + rtb_UnaryMinus)
    + rtb_Product_h[0]) / 1.5 + -sin(Final_X.Theta_CSTATE) * 0.0;
  Final_Y.fiftyTheta[1] = ((((-(rtb_TrigonometricFunction_tmp * rtb_CD) +
    -(rtb_Gain1_tmp * rtb_Gain_j)) * rtb_u2rhoV2 * 0.74 + rtb_gain2_f) +
    (rtb_Fz_tot + rtb_sincos_o2_a)) + rtb_Product_h[2]) / 1.5 +
    rtb_sincos_o2_tmp * 0.0;

  /* Integrator: '<S7>/q' */
  Final_B.q = Final_X.q_CSTATE;

  /* Interpolation_n-D: '<S22>/CM' */
  rtb_CM = intrp1d_l_pw(rtb_Prelookup_o1, rtb_CM, Final_ConstP.CM_Table);

  /* Interpolation_n-D: '<S23>/CM_el' */
  rtb_CM_el = intrp1d_s32dl_pw(rtb_Prelookup_o1_g, rtb_CM_el,
    Final_ConstP.CM_el_Table);
  if (rtmIsMajorTimeStep(Final_M)) {
    /* Sum: '<Root>/Sum4' incorporates:
     *  Constant: '<S6>/TetherForce_M'
     */
    Final_B.Sum4 = 0.0;
  }

  /* Product: '<S9>/Product2' incorporates:
   *  Constant: '<S10>/Constant1'
   *  Constant: '<S10>/Constant2'
   *  Constant: '<S20>/Constant1'
   *  Gain: '<S18>/gain3'
   *  Gain: '<S20>/gain3'
   *  Product: '<S18>/Product4'
   *  Product: '<S20>/Product4'
   *  Product: '<S20>/Product8'
   *  Product: '<S9>/Product3'
   *  Sum: '<Root>/Sum1'
   *  Sum: '<S20>/Sum'
   *  Sum: '<S2>/M_tot'
   *  Sum: '<S9>/Sum1'
   */
  Final_B.Product2 = ((((rtb_u2rhoV2 * rtb_CM_el * 0.486328 + rtb_gain2_f * 0.0)
                        + rtb_u2rhoV2 * rtb_CM * 0.486328) + Final_B.Sum4) - 0.0
                      * Final_B.q) / 8.0;

  /* Outport: '<Root>/LonStatesBus' incorporates:
   *  Integrator: '<S7>/Position'
   *  Integrator: '<S7>/Theta'
   *  Integrator: '<S7>/U,w'
   */
  Final_Y.LonStatesBus[0] = Final_X.Theta_CSTATE;
  Final_Y.LonStatesBus[1] = Final_B.q;
  Final_Y.LonStatesBus[2] = Final_B.Product2;
  Final_Y.LonStatesBus[3] = Final_X.Position_CSTATE[0];
  Final_Y.LonStatesBus[5] = Final_X.Uw_CSTATE[0];
  Final_Y.LonStatesBus[7] = Final_Y.fiftyTheta[0];

  /* Sum: '<S7>/Sum1' incorporates:
   *  Gain: '<S7>/Matrix Gain'
   *  Integrator: '<S7>/U,w'
   *  Product: '<S7>/Product'
   */
  Final_B.Sum1[0] = (0.0 * Final_X.Uw_CSTATE[0] + -Final_X.Uw_CSTATE[1]) *
    Final_B.q + Final_Y.fiftyTheta[0];

  /* Outport: '<Root>/LonStatesBus' incorporates:
   *  Integrator: '<S7>/Position'
   *  Integrator: '<S7>/U,w'
   */
  Final_Y.LonStatesBus[4] = Final_X.Position_CSTATE[1];
  Final_Y.LonStatesBus[6] = Final_X.Uw_CSTATE[1];
  Final_Y.LonStatesBus[8] = Final_Y.fiftyTheta[1];

  /* Sum: '<S7>/Sum1' incorporates:
   *  Gain: '<S7>/Matrix Gain'
   *  Integrator: '<S7>/U,w'
   *  Product: '<S7>/Product'
   */
  Final_B.Sum1[1] = (0.0 * Final_X.Uw_CSTATE[1] + Final_X.Uw_CSTATE[0]) *
    Final_B.q + Final_Y.fiftyTheta[1];

  /* SignalConversion generated from: '<S7>/Position' */
  Final_B.TmpSignalConversionAtPositionIn[0] = rtb_sincos_o2[0];
  Final_B.TmpSignalConversionAtPositionIn[1] = rtb_sincos_o2[2];

  /* Outport: '<Root>/Altitude' incorporates:
   *  Gain: '<S1>/Gain1'
   *  Integrator: '<S7>/Position'
   */
  Final_Y.Altitude = -Final_X.Position_CSTATE[1];

  /* Gain: '<Root>/Gain' incorporates:
   *  Integrator: '<S7>/Theta'
   */
  Final_Y.fiftyTheta[1] = 50.0 * Final_X.Theta_CSTATE;

  /* Outport: '<Root>/Theta' incorporates:
   *  Integrator: '<S7>/Theta'
   */
  Final_Y.Theta = Final_X.Theta_CSTATE;

  /* SignalConversion generated from: '<Root>/Vector Concatenate' incorporates:
   *  Constant: '<Root>/roll'
   */
  Final_Y.fiftyTheta[0] = 0.0;
  if (rtmIsMajorTimeStep(Final_M)) {
    /* Update for Integrator: '<S7>/U,w' */
    Final_DW.Uw_IWORK = 0;
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(Final_M)) {
    rt_ertODEUpdateContinuousStates(&Final_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     */
    ++Final_M->Timing.clockTick0;
    Final_M->Timing.t[0] = rtsiGetSolverStopTime(&Final_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.001s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.001, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       */
      Final_M->Timing.clockTick1++;
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void Final_derivatives(void)
{
  XDot_Final_T *_rtXdot;
  _rtXdot = ((XDot_Final_T *) Final_M->derivs);

  /* Derivatives for Integrator: '<S7>/Theta' */
  _rtXdot->Theta_CSTATE = Final_B.q;

  /* Derivatives for Integrator: '<S7>/U,w' */
  _rtXdot->Uw_CSTATE[0] = Final_B.Sum1[0];

  /* Derivatives for Integrator: '<S7>/Position' */
  _rtXdot->Position_CSTATE[0] = Final_B.TmpSignalConversionAtPositionIn[0];

  /* Derivatives for Integrator: '<S7>/U,w' */
  _rtXdot->Uw_CSTATE[1] = Final_B.Sum1[1];

  /* Derivatives for Integrator: '<S7>/Position' */
  _rtXdot->Position_CSTATE[1] = Final_B.TmpSignalConversionAtPositionIn[1];

  /* Derivatives for Integrator: '<S7>/q' */
  _rtXdot->q_CSTATE = Final_B.Product2;
}

/* Model initialize function */
void Final_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Final_M->solverInfo, &Final_M->Timing.simTimeStep);
    rtsiSetTPtr(&Final_M->solverInfo, &rtmGetTPtr(Final_M));
    rtsiSetStepSizePtr(&Final_M->solverInfo, &Final_M->Timing.stepSize0);
    rtsiSetdXPtr(&Final_M->solverInfo, &Final_M->derivs);
    rtsiSetContStatesPtr(&Final_M->solverInfo, (real_T **) &Final_M->contStates);
    rtsiSetNumContStatesPtr(&Final_M->solverInfo, &Final_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&Final_M->solverInfo,
      &Final_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&Final_M->solverInfo,
      &Final_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&Final_M->solverInfo,
      &Final_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&Final_M->solverInfo, (&rtmGetErrorStatus(Final_M)));
    rtsiSetRTModelPtr(&Final_M->solverInfo, Final_M);
  }

  rtsiSetSimTimeStep(&Final_M->solverInfo, MAJOR_TIME_STEP);
  Final_M->intgData.y = Final_M->odeY;
  Final_M->intgData.f[0] = Final_M->odeF[0];
  Final_M->intgData.f[1] = Final_M->odeF[1];
  Final_M->intgData.f[2] = Final_M->odeF[2];
  Final_M->contStates = ((X_Final_T *) &Final_X);
  Final_M->periodicContStateIndices = ((int_T*) Final_PeriodicIndX);
  Final_M->periodicContStateRanges = ((real_T*) Final_PeriodicRngX);
  rtsiSetSolverData(&Final_M->solverInfo, (void *)&Final_M->intgData);
  rtsiSetSolverName(&Final_M->solverInfo,"ode3");
  rtmSetTPtr(Final_M, &Final_M->Timing.tArray[0]);
  Final_M->Timing.stepSize0 = 0.001;
  rtmSetFirstInitCond(Final_M, 1);

  /* InitializeConditions for Integrator: '<S7>/Theta' */
  Final_X.Theta_CSTATE = 0.017092;

  /* InitializeConditions for Integrator: '<S7>/U,w' */
  if (rtmIsFirstInitCond(Final_M)) {
    Final_X.Uw_CSTATE[0] = 0.0;
    Final_X.Uw_CSTATE[1] = 0.0;
  }

  Final_DW.Uw_IWORK = 1;

  /* End of InitializeConditions for Integrator: '<S7>/U,w' */

  /* InitializeConditions for Integrator: '<S7>/Position' */
  Final_X.Position_CSTATE[0] = -10.0;
  Final_X.Position_CSTATE[1] = -500.0;

  /* InitializeConditions for Integrator: '<S7>/q' */
  Final_X.q_CSTATE = 0.0;

  /* InitializeConditions for root-level periodic continuous states */
  {
    int_T rootPeriodicContStateIndices[1] = { 0 };

    real_T rootPeriodicContStateRanges[2] = { -3.1415926535897931,
      3.1415926535897931 };

    (void) memcpy((void*)Final_PeriodicIndX, rootPeriodicContStateIndices,
                  1*sizeof(int_T));
    (void) memcpy((void*)Final_PeriodicRngX, rootPeriodicContStateRanges,
                  2*sizeof(real_T));
  }

  /* set "at time zero" to false */
  if (rtmIsFirstInitCond(Final_M)) {
    rtmSetFirstInitCond(Final_M, 0);
  }
}

/* Model terminate function */
void Final_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
