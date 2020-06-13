/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Final.h
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

#ifndef RTW_HEADER_Final_h_
#define RTW_HEADER_Final_h_
#include <string.h>
#include <math.h>
#ifndef Final_COMMON_INCLUDES_
# define Final_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* Final_COMMON_INCLUDES_ */

#include "Final_types.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T q;                            /* '<S7>/q' */
  real_T Sum4;                         /* '<Root>/Sum4' */
  real_T Product2;                     /* '<S9>/Product2' */
  real_T Sum1[2];                      /* '<S7>/Sum1' */
  real_T TmpSignalConversionAtPositionIn[2];/* '<S7>/Transform  to Earth Axes' */
} B_Final_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  uint32_T m_bpIndex;                  /* '<S5>/Thrust' */
  int_T Uw_IWORK;                      /* '<S7>/U,w' */
} DW_Final_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Theta_CSTATE;                 /* '<S7>/Theta' */
  real_T Uw_CSTATE[2];                 /* '<S7>/U,w' */
  real_T Position_CSTATE[2];           /* '<S7>/Position' */
  real_T q_CSTATE;                     /* '<S7>/q' */
} X_Final_T;

/* Periodic continuous state vector (global) */
typedef int_T PeriodicIndX_Final_T[1];
typedef real_T PeriodicRngX_Final_T[2];

/* State derivatives (default storage) */
typedef struct {
  real_T Theta_CSTATE;                 /* '<S7>/Theta' */
  real_T Uw_CSTATE[2];                 /* '<S7>/U,w' */
  real_T Position_CSTATE[2];           /* '<S7>/Position' */
  real_T q_CSTATE;                     /* '<S7>/q' */
} XDot_Final_T;

/* State disabled  */
typedef struct {
  boolean_T Theta_CSTATE;              /* '<S7>/Theta' */
  boolean_T Uw_CSTATE[2];              /* '<S7>/U,w' */
  boolean_T Position_CSTATE[2];        /* '<S7>/Position' */
  boolean_T q_CSTATE;                  /* '<S7>/q' */
} XDis_Final_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real_T Gain[3];                /* '<S1>/Gain' */
  const real_T Gain1;                  /* '<S2>/Gain1' */
} ConstB_Final_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Constant parameters (default storage) */
typedef struct {
  /* Pooled Parameter (Expression: aeroCoeff.alpha_vec)
   * Referenced by:
   *   '<S22>/Prelookup'
   *   '<S23>/Prelookup1'
   */
  real_T pooled3[10];

  /* Expression: aeroCoeff.CD
   * Referenced by: '<S22>/CD'
   */
  real_T CD_Table[10];

  /* Expression: aeroCoeff.CL
   * Referenced by: '<S22>/CL'
   */
  real_T CL_Table[10];

  /* Expression: aeroCoeff.def_vec
   * Referenced by: '<S23>/Prelookup'
   */
  real_T Prelookup_BreakpointsData[5];

  /* Expression: aeroCoeff.CD_el
   * Referenced by: '<S23>/CD_el'
   */
  real_T CD_el_Table[50];

  /* Expression: aeroCoeff.CL_el
   * Referenced by: '<S23>/CL_el'
   */
  real_T CL_el_Table[5];

  /* Expression: vehicle.Thrust*(1+tanh([-3:3]))
   * Referenced by: '<S5>/Thrust'
   */
  real_T Thrust_tableData[7];

  /* Expression: (1/6)*(3+([-3:3]))
   * Referenced by: '<S5>/Thrust'
   */
  real_T Thrust_bp01Data[7];

  /* Expression: aeroCoeff.CM
   * Referenced by: '<S22>/CM'
   */
  real_T CM_Table[10];

  /* Expression: aeroCoeff.CM_el
   * Referenced by: '<S23>/CM_el'
   */
  real_T CM_el_Table[5];
} ConstP_Final_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T Elevatorcommand;              /* '<Root>/Elevator command' */
  real_T Vreel;                        /* '<Root>/Vreel' */
  real_T throttle;                     /* '<Root>/throttle' */
} ExtU_Final_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T LonStatesBus[9];              /* '<Root>/LonStatesBus' */
  real_T Airspeed;                     /* '<Root>/Airspeed' */
  real_T fiftyTheta[2];                /* '<Root>/fiftyTheta' */
  real_T Theta;                        /* '<Root>/Theta' */
  real_T Alpha;                        /* '<Root>/Alpha' */
  real_T Altitude;                     /* '<Root>/Altitude' */
} ExtY_Final_T;

/* Real-time Model Data Structure */
struct tag_RTM_Final_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  X_Final_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[6];
  real_T odeF[3][6];
  ODE3_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    boolean_T firstInitCondFlag;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block signals (default storage) */
extern B_Final_T Final_B;

/* Continuous states (default storage) */
extern X_Final_T Final_X;

/* Block states (default storage) */
extern DW_Final_T Final_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_Final_T Final_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_Final_T Final_Y;
extern const ConstB_Final_T Final_ConstB;/* constant block i/o */

/* Constant parameters (default storage) */
extern const ConstP_Final_T Final_ConstP;

/* Model entry point functions */
extern void Final_initialize(void);
extern void Final_step(void);
extern void Final_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Final_T *const Final_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S14>/Unit Conversion' : Unused code path elimination
 * Block '<S21>/Airspeed' : Unused code path elimination
 * Block '<S25>/Product' : Unused code path elimination
 * Block '<S25>/Product1' : Unused code path elimination
 * Block '<S25>/Sum' : Unused code path elimination
 * Block '<S29>/Constant' : Unused code path elimination
 * Block '<S29>/Constant1' : Unused code path elimination
 * Block '<S29>/Constant2' : Unused code path elimination
 * Block '<S31>/Reshape1' : Unused code path elimination
 * Block '<S31>/pg,qg,rg' : Unused code path elimination
 * Block '<Root>/Power' : Unused code path elimination
 * Block '<S6>/Product2' : Unused code path elimination
 * Block '<S16>/Reshape (9) to [3x3] column-major' : Reshape block reduction
 * Block '<S13>/Unit Conversion' : Eliminated nontunable gain of 1
 * Block '<S17>/Reshape (9) to [3x3] column-major' : Reshape block reduction
 * Block '<S30>/Reshape1' : Reshape block reduction
 * Block '<S31>/Reshape' : Reshape block reduction
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Final'
 * '<S1>'   : 'Final/3DOF EOM'
 * '<S2>'   : 'Final/Aerodynamic Model'
 * '<S3>'   : 'Final/Degrees to Radians'
 * '<S4>'   : 'Final/Environment Model'
 * '<S5>'   : 'Final/Propulsion'
 * '<S6>'   : 'Final/TetherForce'
 * '<S7>'   : 'Final/3DOF EOM/3DOF (Body Axes)'
 * '<S8>'   : 'Final/3DOF EOM/Rotation Angles to Direction Cosine Matrix'
 * '<S9>'   : 'Final/3DOF EOM/3DOF (Body Axes)/Calculate qdot'
 * '<S10>'  : 'Final/3DOF EOM/3DOF (Body Axes)/Determine Force,  Mass & Inertia'
 * '<S11>'  : 'Final/3DOF EOM/3DOF (Body Axes)/Gravity'
 * '<S12>'  : 'Final/3DOF EOM/3DOF (Body Axes)/Transform  to Earth Axes'
 * '<S13>'  : 'Final/3DOF EOM/3DOF (Body Axes)/Velocity Conversion'
 * '<S14>'  : 'Final/3DOF EOM/3DOF (Body Axes)/Velocity Conversion1'
 * '<S15>'  : 'Final/3DOF EOM/3DOF (Body Axes)/Transform  to Earth Axes/Rotation Angles to Direction Cosine Matrix'
 * '<S16>'  : 'Final/3DOF EOM/3DOF (Body Axes)/Transform  to Earth Axes/Rotation Angles to Direction Cosine Matrix/Create 3x3 Matrix'
 * '<S17>'  : 'Final/3DOF EOM/Rotation Angles to Direction Cosine Matrix/Create 3x3 Matrix'
 * '<S18>'  : 'Final/Aerodynamic Model/Aero Forces and Moments'
 * '<S19>'  : 'Final/Aerodynamic Model/Dynamic Pressure'
 * '<S20>'  : 'Final/Aerodynamic Model/Elevator Forces and Moments'
 * '<S21>'  : 'Final/Aerodynamic Model/Incidence  & Airspeed'
 * '<S22>'  : 'Final/Aerodynamic Model/Lookup Aero Coeffs'
 * '<S23>'  : 'Final/Aerodynamic Model/Lookup Elevator Aero Coeffs'
 * '<S24>'  : 'Final/Aerodynamic Model/Dynamic Pressure/dot'
 * '<S25>'  : 'Final/Aerodynamic Model/Incidence  & Airspeed/dot'
 * '<S26>'  : 'Final/Aerodynamic Model/Lookup Aero Coeffs/Subsystem'
 * '<S27>'  : 'Final/Aerodynamic Model/Lookup Elevator Aero Coeffs/Subsystem'
 * '<S28>'  : 'Final/Aerodynamic Model/Lookup Elevator Aero Coeffs/Subsystem1'
 * '<S29>'  : 'Final/Environment Model/Constant Atmosphere'
 * '<S30>'  : 'Final/Environment Model/Constant Gravity'
 * '<S31>'  : 'Final/Environment Model/Constant Wind'
 */
#endif                                 /* RTW_HEADER_Final_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
