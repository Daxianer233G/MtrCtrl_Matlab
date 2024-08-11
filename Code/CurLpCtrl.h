/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: CurLpCtrl.h
 *
 * Code generated for Simulink model 'CurLpCtrl'.
 *
 * Model version                  : 5.1
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sun Aug 11 03:20:20 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_CurLpCtrl_h_
#define RTW_HEADER_CurLpCtrl_h_
#ifndef CurLpCtrl_COMMON_INCLUDES_
#define CurLpCtrl_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* CurLpCtrl_COMMON_INCLUDES_ */

#include "zero_crossing_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  int32_T UnitDelay_DSTATE[2];         /* '<S1>/Unit Delay' */
  int32_T sum_beta;                    /* '<S5>/sum_beta' */
  int32_T Product;                     /* '<S13>/Product' */
  int32_T Product1;                    /* '<S13>/Product1' */
  int32_T UnitDelay_DSTATE_d;          /* '<S14>/Unit Delay' */
  int32_T UnitDelay_DSTATE_o;          /* '<S15>/Unit Delay' */
  int32_T UnitDelay_DSTATE_c;          /* '<S30>/Unit Delay' */
  int32_T DiscreteTimeIntegrator_DSTATE;/* '<S30>/Discrete-Time Integrator' */
  int32_T TwoPi;                       /* '<S11>/Chart' */
  uint32_T CurLpCtrl_PREV_T[2];        /* '<Root>/CurLpCtrl' */
  uint32_T Switch2;                    /* '<S7>/Switch2' */
  uint32_T Switch3;                    /* '<S7>/Switch3' */
  uint32_T Switch4;                    /* '<S7>/Switch4' */
  uint32_T SinAngle;                   /* '<S11>/Chart' */
  uint32_T CosAngle;                   /* '<S11>/Chart' */
  uint32_T m_bpIndex;                  /* '<S11>/1-D Lookup Table1' */
  uint32_T m_bpIndex_a;                /* '<S11>/1-D Lookup Table' */
  uint32_T Udc_pu;                     /* '<S18>/Chart' */
  uint32_T SqrtThreeOverSix;           /* '<S18>/Chart' */
  uint32_T TwoTimeSqrtThreeOverThree;  /* '<S17>/Chart' */
  uint32_T PiTimeThreeOverTwo;         /* '<S11>/Chart' */
  uint32_T Pi;                         /* '<S11>/Chart' */
  uint32_T PiOverTow;                  /* '<S11>/Chart' */
  int8_T SinSign;                      /* '<S11>/Chart' */
  int8_T CosSign;                      /* '<S11>/Chart' */
  int8_T Neg;                          /* '<S11>/Chart' */
  int8_T Pos;                          /* '<S11>/Chart' */
  uint8_T DiscreteTimeIntegrator_SYSTEM_E;/* '<S30>/Discrete-Time Integrator' */
  boolean_T VoltMode_null;             /* '<Root>/_DataStoreBlk_2597' */
  boolean_T CurLpCtrl_RESET_ELAPS_T;   /* '<Root>/CurLpCtrl' */
} DW;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState CurLpCtrl_Trig_ZCE;       /* '<Root>/CurLpCtrl' */
} PrevZCX;

/* Constant parameters (default storage) */
typedef struct {
  /* Pooled Parameter (Expression: C_LUT_SinTable_sng_Null)
   * Referenced by:
   *   '<S11>/1-D Lookup Table'
   *   '<S11>/1-D Lookup Table1'
   */
  uint32_T pooled9[1024];

  /* Pooled Parameter (Expression: C_LUT_AngleTable_sng_Null)
   * Referenced by:
   *   '<S11>/1-D Lookup Table'
   *   '<S11>/1-D Lookup Table1'
   */
  uint32_T pooled10[1024];
} ConstP;

/* External inputs (root inport signals with default storage) */
typedef struct {
  int32_T IsSet;                       /* '<Root>/IsSet' */
  int32_T CurA;                        /* '<Root>/CurA' */
  int32_T CurC;                        /* '<Root>/CurC' */
  int32_T VirPosn;                     /* '<Root>/VirPosn' */
  int32_T Posn_rad;                    /* '<Root>/Posn_rad' */
  int32_T wm;                          /* '<Root>/wm' */
  uint32_T Udc;                        /* '<Root>/Udc' */
  boolean_T Trigger;                   /* '<Root>/Trigger' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  uint32_T S[3];                       /* '<Root>/S' */
} ExtY;

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T * volatile errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
  } Timing;
};

/* Block signals and states (default storage) */
extern DW rtDW;

/* Zero-crossing (trigger) state */
extern PrevZCX rtPrevZCX;

/* External inputs (root inport signals with default storage) */
extern ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY rtY;

/* Constant parameters (default storage) */
extern const ConstP rtConstP;

/* Model entry point functions */
extern void CurLpCtrl_initialize(void);
extern void CurLpCtrl_step(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S3>/Scope' : Unused code path elimination
 * Block '<S4>/Display2' : Unused code path elimination
 * Block '<S4>/Display3' : Unused code path elimination
 * Block '<S4>/Scope' : Unused code path elimination
 * Block '<S14>/Scope' : Unused code path elimination
 * Block '<S15>/Scope' : Unused code path elimination
 * Block '<S5>/Scope' : Unused code path elimination
 * Block '<S6>/Scope' : Unused code path elimination
 * Block '<S8>/Add' : Unused code path elimination
 * Block '<S8>/Gain' : Unused code path elimination
 * Block '<S17>/Add' : Unused code path elimination
 * Block '<S17>/Scope' : Unused code path elimination
 * Block '<S8>/Scope' : Unused code path elimination
 * Block '<S8>/Scope1' : Unused code path elimination
 * Block '<S8>/Scope2' : Unused code path elimination
 * Block '<S8>/Scope3' : Unused code path elimination
 * Block '<S8>/Scope4' : Unused code path elimination
 * Block '<S18>/Scope3' : Unused code path elimination
 * Block '<S19>/A' : Unused code path elimination
 * Block '<S19>/B' : Unused code path elimination
 * Block '<S19>/C' : Unused code path elimination
 * Block '<S19>/Constant1' : Unused code path elimination
 * Block '<S19>/Constant2' : Unused code path elimination
 * Block '<S19>/Constant3' : Unused code path elimination
 * Block '<S19>/Constant4' : Unused code path elimination
 * Block '<S19>/Sum' : Unused code path elimination
 * Block '<S19>/Sum1' : Unused code path elimination
 * Block '<S19>/Sum2' : Unused code path elimination
 * Block '<S20>/Scope' : Unused code path elimination
 * Block '<S8>/Sqrt' : Unused code path elimination
 * Block '<S8>/Square' : Unused code path elimination
 * Block '<S8>/Square1' : Unused code path elimination
 * Block '<S21>/A' : Unused code path elimination
 * Block '<S21>/B' : Unused code path elimination
 * Block '<S21>/C' : Unused code path elimination
 * Block '<S21>/Gain1' : Unused code path elimination
 * Block '<S21>/Gain2' : Unused code path elimination
 * Block '<S21>/Gain3' : Unused code path elimination
 * Block '<S21>/Sum' : Unused code path elimination
 * Block '<S21>/Sum1' : Unused code path elimination
 * Block '<S21>/Sum2' : Unused code path elimination
 * Block '<S22>/Add' : Unused code path elimination
 * Block '<S22>/Add1' : Unused code path elimination
 * Block '<S22>/Gain' : Unused code path elimination
 * Block '<S22>/Gain1' : Unused code path elimination
 * Block '<S1>/Scope' : Unused code path elimination
 * Block '<S1>/Scope1' : Unused code path elimination
 * Block '<S1>/Scope2' : Unused code path elimination
 * Block '<S30>/Modulation index threshold1' : Unused code path elimination
 * Block '<S33>/Scope' : Unused code path elimination
 * Block '<S11>/Scope' : Unused code path elimination
 * Block '<S12>/Scope' : Unused code path elimination
 * Block '<S12>/Scope1' : Unused code path elimination
 * Block '<S12>/Scope2' : Unused code path elimination
 * Block '<S12>/Scope3' : Unused code path elimination
 * Block '<S1>/Manual Switch1' : Eliminated due to constant selection input
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('MtrCtrl_24V/CurLpCtrl')    - opens subsystem MtrCtrl_24V/CurLpCtrl
 * hilite_system('MtrCtrl_24V/CurLpCtrl/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'MtrCtrl_24V'
 * '<S1>'   : 'MtrCtrl_24V/CurLpCtrl'
 * '<S2>'   : 'MtrCtrl_24V/CurLpCtrl/ClarkeTF'
 * '<S3>'   : 'MtrCtrl_24V/CurLpCtrl/CurCal'
 * '<S4>'   : 'MtrCtrl_24V/CurLpCtrl/CurPILp'
 * '<S5>'   : 'MtrCtrl_24V/CurLpCtrl/InversePark'
 * '<S6>'   : 'MtrCtrl_24V/CurLpCtrl/ParkTF'
 * '<S7>'   : 'MtrCtrl_24V/CurLpCtrl/PhaseCut'
 * '<S8>'   : 'MtrCtrl_24V/CurLpCtrl/SVPWM'
 * '<S9>'   : 'MtrCtrl_24V/CurLpCtrl/Subsystem10'
 * '<S10>'  : 'MtrCtrl_24V/CurLpCtrl/Subsystem4'
 * '<S11>'  : 'MtrCtrl_24V/CurLpCtrl/Subsystem5'
 * '<S12>'  : 'MtrCtrl_24V/CurLpCtrl/VDQLimit'
 * '<S13>'  : 'MtrCtrl_24V/CurLpCtrl/CurPILp/Subsystem'
 * '<S14>'  : 'MtrCtrl_24V/CurLpCtrl/CurPILp/Subsystem1'
 * '<S15>'  : 'MtrCtrl_24V/CurLpCtrl/CurPILp/Subsystem2'
 * '<S16>'  : 'MtrCtrl_24V/CurLpCtrl/CurPILp/Subsystem3'
 * '<S17>'  : 'MtrCtrl_24V/CurLpCtrl/SVPWM/Overmodulation'
 * '<S18>'  : 'MtrCtrl_24V/CurLpCtrl/SVPWM/Sector'
 * '<S19>'  : 'MtrCtrl_24V/CurLpCtrl/SVPWM/SelectRegion'
 * '<S20>'  : 'MtrCtrl_24V/CurLpCtrl/SVPWM/Sn'
 * '<S21>'  : 'MtrCtrl_24V/CurLpCtrl/SVPWM/SwitchTimeCalculation'
 * '<S22>'  : 'MtrCtrl_24V/CurLpCtrl/SVPWM/TempValueCalculation'
 * '<S23>'  : 'MtrCtrl_24V/CurLpCtrl/SVPWM/Overmodulation/Chart'
 * '<S24>'  : 'MtrCtrl_24V/CurLpCtrl/SVPWM/Overmodulation/Subsystem2'
 * '<S25>'  : 'MtrCtrl_24V/CurLpCtrl/SVPWM/Overmodulation/Subsystem2/Compare To Constant'
 * '<S26>'  : 'MtrCtrl_24V/CurLpCtrl/SVPWM/Sector/Chart'
 * '<S27>'  : 'MtrCtrl_24V/CurLpCtrl/SVPWM/Sector/Compare To Constant'
 * '<S28>'  : 'MtrCtrl_24V/CurLpCtrl/SVPWM/Sector/Compare To Constant1'
 * '<S29>'  : 'MtrCtrl_24V/CurLpCtrl/SVPWM/Sector/Compare To Constant2'
 * '<S30>'  : 'MtrCtrl_24V/CurLpCtrl/Subsystem10/Subsystem'
 * '<S31>'  : 'MtrCtrl_24V/CurLpCtrl/Subsystem10/Subsystem/Cartesian to Polar'
 * '<S32>'  : 'MtrCtrl_24V/CurLpCtrl/Subsystem10/Subsystem/Polar to Cartesian'
 * '<S33>'  : 'MtrCtrl_24V/CurLpCtrl/Subsystem10/Subsystem/Subsystem1'
 * '<S34>'  : 'MtrCtrl_24V/CurLpCtrl/Subsystem10/Subsystem/Cartesian to Polar/ReplicaOfSource'
 * '<S35>'  : 'MtrCtrl_24V/CurLpCtrl/Subsystem10/Subsystem/Polar to Cartesian/ReplicaOfSource'
 * '<S36>'  : 'MtrCtrl_24V/CurLpCtrl/Subsystem10/Subsystem/Subsystem1/Subsystem'
 * '<S37>'  : 'MtrCtrl_24V/CurLpCtrl/Subsystem4/SinCos'
 * '<S38>'  : 'MtrCtrl_24V/CurLpCtrl/Subsystem5/Chart'
 * '<S39>'  : 'MtrCtrl_24V/CurLpCtrl/VDQLimit/Compare To Constant'
 */
#endif                                 /* RTW_HEADER_CurLpCtrl_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
