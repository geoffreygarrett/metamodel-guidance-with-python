/*
 * attitude3d.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "attitude3d".
 *
 * Model version              : 1.106
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 * C source code generated on : Fri Dec 13 15:01:45 2019
 *
 * Target selection: rsim.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objective: Execution efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_attitude3d_h_
#define RTW_HEADER_attitude3d_h_
#include <stddef.h>
#include <math.h>
#include <string.h>
#ifndef attitude3d_COMMON_INCLUDES_
# define attitude3d_COMMON_INCLUDES_
#include <stdlib.h>
#include "rtwtypes.h"
#include "sl_fileio_rtw.h"
#include "simtarget/slSimTgtSlFileioRTW.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "rsim.h"
#include "rt_logging.h"
#include "dt_info.h"
#endif                                 /* attitude3d_COMMON_INCLUDES_ */

#include "attitude3d_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#include "rt_defines.h"
#define MODEL_NAME                     attitude3d
#define NSAMPLE_TIMES                  (2)                       /* Number of sample times */
#define NINPUTS                        (3)                       /* Number of model inputs */
#define NOUTPUTS                       (0)                       /* Number of model outputs */
#define NBLOCKIO                       (46)                      /* Number of data output port signals */
#define NUM_ZC_EVENTS                  (0)                       /* Number of zero-crossing events */
#ifndef NCSTATES
# define NCSTATES                      (8)                       /* Number of continuous states */
#elif NCSTATES != 8
# error Invalid specification of NCSTATES defined in compiler command
#endif

#ifndef rtmGetDataMapInfo
# define rtmGetDataMapInfo(rtm)        (NULL)
#endif

#ifndef rtmSetDataMapInfo
# define rtmSetDataMapInfo(rtm, val)
#endif

/* Block signals for system '<S4>/Moving Minimum' */
typedef struct {
  real_T MovingMinimum;                /* '<S4>/Moving Minimum' */
} B_MovingMinimum_attitude3d_T;

/* Block states (default storage) for system '<S4>/Moving Minimum' */
typedef struct {
  dsp_MovingMinimum_attitude3d_T obj;  /* '<S4>/Moving Minimum' */
  dsp_private_RunningMinimum_at_T gobj_0;/* '<S4>/Moving Minimum' */
  dsp_private_RunningMinimum_at_T gobj_1;/* '<S4>/Moving Minimum' */
  boolean_T objisempty;                /* '<S4>/Moving Minimum' */
} DW_MovingMinimum_attitude3d_T;

/* Block signals for system '<S6>/Moving Maximum' */
typedef struct {
  real_T MovingMaximum;                /* '<S6>/Moving Maximum' */
} B_MovingMaximum_attitude3d_T;

/* Block states (default storage) for system '<S6>/Moving Maximum' */
typedef struct {
  dsp_MovingMaximum_attitude3d_T obj;  /* '<S6>/Moving Maximum' */
  dsp_private_RunningMaximum_at_T gobj_0;/* '<S6>/Moving Maximum' */
  dsp_private_RunningMaximum_at_T gobj_1;/* '<S6>/Moving Maximum' */
  boolean_T objisempty;                /* '<S6>/Moving Maximum' */
} DW_MovingMaximum_attitude3d_T;

/* Block signals (default storage) */
typedef struct {
  ENVIRONMENT E;                       /* '<Root>/From File13' */
  real_T Gain1[4];                     /* '<S14>/Gain1' */
  real_T Product[3];                   /* '<S30>/Product' */
  real_T Saturation;                   /* '<S4>/Saturation' */
  real_T min_exclusion;                /* '<S4>/Product' */
  real_T Acos;                         /* '<S4>/Acos' */
  real_T Product_i[3];                 /* '<S31>/Product' */
  real_T Saturation_i;                 /* '<S5>/Saturation' */
  real_T min_exclusion_m;              /* '<S5>/Product' */
  real_T Acos_i;                       /* '<S5>/Acos' */
  real_T Switch;                       /* '<S6>/Switch' */
  real_T Switch_a;                     /* '<S7>/Switch' */
  real_T Divide;                       /* '<S11>/Divide' */
  real_T Divide_i;                     /* '<S10>/Divide' */
  real_T Switch_c;                     /* '<S9>/Switch' */
  real_T integral_pointing;            /* '<S9>/Integrator1' */
  real_T Divide_b;                     /* '<S9>/Divide' */
  real_T thrust_vector[3];
  real_T thrust_weight;
  real_T solar_occulted_integral;
  real_T solar_occulted_boolean;
  real_T comms_occulted_integral;
  real_T comms_occulted_boolean;
  real_T r_s[3];
  real_T v_s[3];
  real_T r_c[3];
  real_T v_c[3];
  real_T r_t[3];
  real_T v_t[3];
  real_T Product_o[3];                 /* '<S34>/Product' */
  real_T Product_a[3];                 /* '<S33>/Product' */
  real_T Product_d[3];                 /* '<S32>/Product' */
  real_T q_dot[4];                     /* '<S17>/Gain' */
  real_T DotProduct1;                  /* '<S9>/Dot Product1' */
  real_T ManualSwitch1;                /* '<S9>/Manual Switch1' */
  real_T current_solar_e;              /* '<S9>/Product' */
  real_T ManualSwitch1_c;              /* '<S10>/Manual Switch1' */
  real_T current_solar_e_p;            /* '<S10>/Product' */
  real_T current_solar_e_pn;           /* '<S11>/Product' */
  real_T Clock1;                       /* '<S2>/Clock1' */
  real_T y[4];                         /* '<S3>/Quaternion Normed' */
  boolean_T Compare;                   /* '<S15>/Compare' */
  B_MovingMaximum_attitude3d_T MovingMaximum_p;/* '<S6>/Moving Maximum' */
  B_MovingMaximum_attitude3d_T MovingMaximum;/* '<S6>/Moving Maximum' */
  B_MovingMinimum_attitude3d_T MovingMinimum_p;/* '<S4>/Moving Minimum' */
  B_MovingMinimum_attitude3d_T MovingMinimum;/* '<S4>/Moving Minimum' */
} B;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T DiscreteFIRFilter_states[59]; /* '<S26>/Discrete FIR Filter' */
  real_T DiscreteFIRFilter_states_k[59];/* '<S29>/Discrete FIR Filter' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */

  struct {
    void *PrevTimePtr;
  } FromFile13_PWORK;                  /* '<Root>/From File13' */

  struct {
    void *LoggedData[7];
  } Scope1_PWORK;                      /* '<Root>/Scope1' */

  struct {
    void *LoggedData[12];
  } Scope2_PWORK;                      /* '<Root>/Scope2' */

  struct {
    void *LoggedData;
  } Scope3_PWORK;                      /* '<Root>/Scope3' */

  struct {
    void *LoggedData[5];
  } Scope5_PWORK;                      /* '<Root>/Scope5' */

  struct {
    void *LoggedData;
  } Scope1_PWORK_o;                    /* '<S4>/Scope1' */

  struct {
    void *LoggedData;
  } Scope2_PWORK_o;                    /* '<S4>/Scope2' */

  struct {
    void *LoggedData;
  } Scope3_PWORK_n;                    /* '<S4>/Scope3' */

  struct {
    void *LoggedData;
  } Scope6_PWORK;                      /* '<S4>/Scope6' */

  struct {
    void *LoggedData;
  } Scope1_PWORK_k;                    /* '<S5>/Scope1' */

  struct {
    void *LoggedData;
  } Scope2_PWORK_i;                    /* '<S5>/Scope2' */

  struct {
    void *LoggedData;
  } Scope3_PWORK_e;                    /* '<S5>/Scope3' */

  struct {
    void *LoggedData;
  } Scope6_PWORK_l;                    /* '<S5>/Scope6' */

  struct {
    void *LoggedData;
  } Scope4_PWORK;                      /* '<S9>/Scope4' */

  struct {
    void *LoggedData;
  } Scope6_PWORK_c;                    /* '<S9>/Scope6' */

  struct {
    void *LoggedData;
  } Scope7_PWORK;                      /* '<S9>/Scope7' */

  struct {
    void *LoggedData;
  } Scope8_PWORK;                      /* '<S9>/Scope8' */

  struct {
    void *LoggedData;
  } Scope9_PWORK;                      /* '<S9>/Scope9' */

  struct {
    void *LoggedData;
  } Scope6_PWORK_e;                    /* '<S10>/Scope6' */

  struct {
    void *LoggedData[2];
  } Scope_PWORK_b;                     /* '<S2>/Scope' */

  int_T Integrator_IWORK;              /* '<S3>/Integrator' */
  DW_MovingMaximum_attitude3d_T MovingMaximum_p;/* '<S6>/Moving Maximum' */
  DW_MovingMaximum_attitude3d_T MovingMaximum;/* '<S6>/Moving Maximum' */
  DW_MovingMinimum_attitude3d_T MovingMinimum_p;/* '<S4>/Moving Minimum' */
  DW_MovingMinimum_attitude3d_T MovingMinimum;/* '<S4>/Moving Minimum' */
} DW;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator_CSTATE[4];         /* '<S3>/Integrator' */
  real_T Integrator1_CSTATE;           /* '<S11>/Integrator1' */
  real_T Integrator1_CSTATE_a;         /* '<S10>/Integrator1' */
  real_T Integrator2_CSTATE;           /* '<S9>/Integrator2' */
  real_T Integrator1_CSTATE_f;         /* '<S9>/Integrator1' */
} X;

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator_CSTATE[4];         /* '<S3>/Integrator' */
  real_T Integrator1_CSTATE;           /* '<S11>/Integrator1' */
  real_T Integrator1_CSTATE_a;         /* '<S10>/Integrator1' */
  real_T Integrator2_CSTATE;           /* '<S9>/Integrator2' */
  real_T Integrator1_CSTATE_f;         /* '<S9>/Integrator1' */
} XDot;

/* State disabled  */
typedef struct {
  boolean_T Integrator_CSTATE[4];      /* '<S3>/Integrator' */
  boolean_T Integrator1_CSTATE;        /* '<S11>/Integrator1' */
  boolean_T Integrator1_CSTATE_a;      /* '<S10>/Integrator1' */
  boolean_T Integrator2_CSTATE;        /* '<S9>/Integrator2' */
  boolean_T Integrator1_CSTATE_f;      /* '<S9>/Integrator1' */
} XDis;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T omega[3];                     /* '<Root>/x' */
} ExtU;

/* Parameters (default storage) */
struct P_ {
  struct_qj1aZXRxDpRc9BsHnZQAtC P_E;   /* Variable: P_E
                                        * Referenced by:
                                        *   '<Root>/Constant8'
                                        *   '<Root>/Constant9'
                                        *   '<S2>/Constant'
                                        */
  struct_nois8vFfP57DutoSgf9HZD P_F;   /* Variable: P_F
                                        * Referenced by:
                                        *   '<Root>/Constant'
                                        *   '<Root>/Constant1'
                                        *   '<Root>/Constant2'
                                        *   '<Root>/Constant3'
                                        *   '<Root>/Constant4'
                                        *   '<S6>/Constant12'
                                        *   '<S7>/Constant12'
                                        */
  struct_rawc2dqRCLbbSQv98WCoDC P_X;   /* Variable: P_X
                                        * Referenced by:
                                        *   '<Root>/Constant5'
                                        *   '<Root>/Constant6'
                                        *   '<Root>/Constant7'
                                        */
  real_T NormalizeVector_maxzero;     /* Mask Parameter: NormalizeVector_maxzero
                                       * Referenced by: '<S20>/Switch'
                                       */
  real_T NormalizeVector1_maxzero;   /* Mask Parameter: NormalizeVector1_maxzero
                                      * Referenced by: '<S21>/Switch'
                                      */
  real_T NormalizeVector_maxzero_m; /* Mask Parameter: NormalizeVector_maxzero_m
                                     * Referenced by: '<S22>/Switch'
                                     */
  real_T NormalizeVector1_maxzero_i;
                                   /* Mask Parameter: NormalizeVector1_maxzero_i
                                    * Referenced by: '<S23>/Switch'
                                    */
  real_T NormalizeVector_maxzero_o; /* Mask Parameter: NormalizeVector_maxzero_o
                                     * Referenced by: '<S24>/Switch'
                                     */
  real_T NormalizeVector1_maxzero_c;
                                   /* Mask Parameter: NormalizeVector1_maxzero_c
                                    * Referenced by: '<S25>/Switch'
                                    */
  real_T NormalizeVector_maxzero_e; /* Mask Parameter: NormalizeVector_maxzero_e
                                     * Referenced by: '<S27>/Switch'
                                     */
  real_T NormalizeVector1_maxzero_e;
                                   /* Mask Parameter: NormalizeVector1_maxzero_e
                                    * Referenced by: '<S28>/Switch'
                                    */
  real_T NormalizeVector_maxzero_f; /* Mask Parameter: NormalizeVector_maxzero_f
                                     * Referenced by: '<S61>/Switch'
                                     */
  real_T NormalizeVector1_maxzero_c1;
                                  /* Mask Parameter: NormalizeVector1_maxzero_c1
                                   * Referenced by: '<S62>/Switch'
                                   */
  real_T NormalizeVector_maxzero_p; /* Mask Parameter: NormalizeVector_maxzero_p
                                     * Referenced by: '<S64>/Switch'
                                     */
  real_T NormalizeVector1_maxzero_d;
                                   /* Mask Parameter: NormalizeVector1_maxzero_d
                                    * Referenced by: '<S65>/Switch'
                                    */
  real_T NormalizeVector_maxzero_j; /* Mask Parameter: NormalizeVector_maxzero_j
                                     * Referenced by: '<S67>/Switch'
                                     */
  real_T NormalizeVector1_maxzero_g;
                                   /* Mask Parameter: NormalizeVector1_maxzero_g
                                    * Referenced by: '<S68>/Switch'
                                    */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S60>/Constant'
                                        */
  real_T Constant_Value_c;             /* Expression: 0
                                        * Referenced by: '<S63>/Constant'
                                        */
  real_T Constant_Value_b;             /* Expression: 0
                                        * Referenced by: '<S66>/Constant'
                                        */
  real_T Constant_Value_k;             /* Expression: 0
                                        * Referenced by: '<S15>/Constant'
                                        */
  real_T Constant_Value_p;             /* Expression: 1
                                        * Referenced by: '<S20>/Constant'
                                        */
  real_T Gain1_Gain[4];                /* Expression: [1 -1 -1 -1]
                                        * Referenced by: '<S14>/Gain1'
                                        */
  real_T Gain1_Gain_i[4];              /* Expression: [1 -1 -1 -1]
                                        * Referenced by: '<S13>/Gain1'
                                        */
  real_T Gain1_Gain_f[4];              /* Expression: [1 -1 -1 -1]
                                        * Referenced by: '<S37>/Gain1'
                                        */
  real_T Constant_Value_o;             /* Expression: 1
                                        * Referenced by: '<S30>/Constant'
                                        */
  real_T Constant_Value_pb;            /* Expression: 1
                                        * Referenced by: '<S21>/Constant'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 1.0
                                        * Referenced by: '<S4>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 0
                                        * Referenced by: '<S4>/Saturation'
                                        */
  real_T Constant_Value_oj;            /* Expression: 1
                                        * Referenced by: '<S22>/Constant'
                                        */
  real_T Gain1_Gain_m[4];              /* Expression: [1 -1 -1 -1]
                                        * Referenced by: '<S42>/Gain1'
                                        */
  real_T Constant_Value_i;             /* Expression: 1
                                        * Referenced by: '<S31>/Constant'
                                        */
  real_T Constant_Value_pw;            /* Expression: 1
                                        * Referenced by: '<S23>/Constant'
                                        */
  real_T Saturation_UpperSat_o;        /* Expression: 1.0
                                        * Referenced by: '<S5>/Saturation'
                                        */
  real_T Saturation_LowerSat_p;        /* Expression: 0
                                        * Referenced by: '<S5>/Saturation'
                                        */
  real_T Constant10_Value;             /* Expression: 1
                                        * Referenced by: '<S6>/Constant10'
                                        */
  real_T Gain1_Gain_j;                 /* Expression: -1
                                        * Referenced by: '<S6>/Gain1'
                                        */
  real_T Constant_Value_kd;            /* Expression: 1
                                        * Referenced by: '<S24>/Constant'
                                        */
  real_T Constant_Value_g;             /* Expression: 1
                                        * Referenced by: '<S25>/Constant'
                                        */
  real_T Constant11_Value;             /* Expression: 0
                                        * Referenced by: '<S6>/Constant11'
                                        */
  real_T DiscreteFIRFilter_InitialStates;/* Expression: 0
                                          * Referenced by: '<S26>/Discrete FIR Filter'
                                          */
  real_T DiscreteFIRFilter_Coefficients[60];/* Expression: ones(1,integperiod)
                                             * Referenced by: '<S26>/Discrete FIR Filter'
                                             */
  real_T Constant10_Value_p;           /* Expression: 1
                                        * Referenced by: '<S7>/Constant10'
                                        */
  real_T Gain1_Gain_l;                 /* Expression: -1
                                        * Referenced by: '<S7>/Gain1'
                                        */
  real_T Constant_Value_bu;            /* Expression: 1
                                        * Referenced by: '<S27>/Constant'
                                        */
  real_T Constant_Value_ov;            /* Expression: 1
                                        * Referenced by: '<S28>/Constant'
                                        */
  real_T Constant11_Value_f;           /* Expression: 0
                                        * Referenced by: '<S7>/Constant11'
                                        */
  real_T DiscreteFIRFilter_InitialStat_i;/* Expression: 0
                                          * Referenced by: '<S29>/Discrete FIR Filter'
                                          */
  real_T DiscreteFIRFilter_Coefficient_n[60];/* Expression: ones(1,integperiod)
                                              * Referenced by: '<S29>/Discrete FIR Filter'
                                              */
  real_T Constant_Value_b5;            /* Expression: 1
                                        * Referenced by: '<S11>/Constant'
                                        */
  real_T Integrator1_IC;               /* Expression: 0
                                        * Referenced by: '<S11>/Integrator1'
                                        */
  real_T Constant_Value_ok;            /* Expression: 1
                                        * Referenced by: '<S10>/Constant'
                                        */
  real_T Integrator1_IC_k;             /* Expression: 0
                                        * Referenced by: '<S10>/Integrator1'
                                        */
  real_T Constant9_Value;              /* Expression: 1
                                        * Referenced by: '<S9>/Constant9'
                                        */
  real_T Integrator2_IC;               /* Expression: 0
                                        * Referenced by: '<S9>/Integrator2'
                                        */
  real_T Integrator1_IC_b;             /* Expression: 0
                                        * Referenced by: '<S9>/Integrator1'
                                        */
  real_T Gain1_Gain_fe[4];             /* Expression: [1 -1 -1 -1]
                                        * Referenced by: '<S57>/Gain1'
                                        */
  real_T Constant_Value_f;             /* Expression: 1
                                        * Referenced by: '<S34>/Constant'
                                        */
  real_T Gain1_Gain_m4[4];             /* Expression: [1 -1 -1 -1]
                                        * Referenced by: '<S52>/Gain1'
                                        */
  real_T Constant_Value_gd;            /* Expression: 1
                                        * Referenced by: '<S33>/Constant'
                                        */
  real_T Gain1_Gain_n[4];              /* Expression: [1 -1 -1 -1]
                                        * Referenced by: '<S47>/Gain1'
                                        */
  real_T Constant_Value_m;             /* Expression: 1
                                        * Referenced by: '<S32>/Constant'
                                        */
  real_T Constant_Value_bp;            /* Expression: 0
                                        * Referenced by: '<S17>/Constant'
                                        */
  real_T Gain_Gain;                    /* Expression: 1/2
                                        * Referenced by: '<S17>/Gain'
                                        */
  real_T Constant_Value_i2;            /* Expression: 1
                                        * Referenced by: '<S61>/Constant'
                                        */
  real_T Constant_Value_bf;            /* Expression: 1
                                        * Referenced by: '<S62>/Constant'
                                        */
  real_T Constant11_Value_h;           /* Expression: 1
                                        * Referenced by: '<S9>/Constant11'
                                        */
  real_T Constant_Value_os;            /* Expression: 1
                                        * Referenced by: '<S64>/Constant'
                                        */
  real_T Constant_Value_n;             /* Expression: 1
                                        * Referenced by: '<S65>/Constant'
                                        */
  real_T Saturation_UpperSat_e;        /* Expression: 1.0
                                        * Referenced by: '<S10>/Saturation'
                                        */
  real_T Saturation_LowerSat_n;        /* Expression: 0
                                        * Referenced by: '<S10>/Saturation'
                                        */
  real_T Constant11_Value_hv;          /* Expression: 1
                                        * Referenced by: '<S10>/Constant11'
                                        */
  real_T Constant_Value_ku;            /* Expression: 1
                                        * Referenced by: '<S67>/Constant'
                                        */
  real_T Constant_Value_l;             /* Expression: 1
                                        * Referenced by: '<S68>/Constant'
                                        */
  real_T Saturation_UpperSat_l;        /* Expression: 1.0
                                        * Referenced by: '<S11>/Saturation'
                                        */
  real_T Saturation_LowerSat_pj;       /* Expression: -1.0
                                        * Referenced by: '<S11>/Saturation'
                                        */
  uint8_T ManualSwitch1_CurrentSetting;
                             /* Computed Parameter: ManualSwitch1_CurrentSetting
                              * Referenced by: '<S9>/Manual Switch1'
                              */
  uint8_T ManualSwitch1_CurrentSetting_k;
                           /* Computed Parameter: ManualSwitch1_CurrentSetting_k
                            * Referenced by: '<S10>/Manual Switch1'
                            */
};

/* External data declarations for dependent source files */
extern const char *RT_MEMORY_ALLOCATION_ERROR;
extern B rtB;                          /* block i/o */
extern X rtX;                          /* states (continuous) */
extern DW rtDW;                        /* states (dwork) */
extern ExtU rtU;                       /* external inputs */
extern P rtP;                          /* parameters */

/* Simulation Structure */
extern SimStruct *const rtS;

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
 * '<Root>' : 'attitude3d'
 * '<S1>'   : 'attitude3d/Difference'
 * '<S2>'   : 'attitude3d/Orbital Period Termination Condition'
 * '<S3>'   : 'attitude3d/Quaternion Propagator'
 * '<S4>'   : 'attitude3d/Star Sensor 1 Minimum Solar Exclusion'
 * '<S5>'   : 'attitude3d/Star Sensor 2 Minimum Solar Exclusion'
 * '<S6>'   : 'attitude3d/Subsystem'
 * '<S7>'   : 'attitude3d/Subsystem1'
 * '<S8>'   : 'attitude3d/Subsystem2'
 * '<S9>'   : 'attitude3d/Thrust Pointing Efficiency'
 * '<S10>'  : 'attitude3d/Total Pointing Efficiency (Comms)'
 * '<S11>'  : 'attitude3d/Total Pointing Efficiency (Solar)'
 * '<S12>'  : 'attitude3d/frame2quat1'
 * '<S13>'  : 'attitude3d/transposeQuaternion1'
 * '<S14>'  : 'attitude3d/transposeQuaternion2'
 * '<S15>'  : 'attitude3d/Orbital Period Termination Condition/Compare To Zero'
 * '<S16>'  : 'attitude3d/Quaternion Propagator/Quaternion Normed'
 * '<S17>'  : 'attitude3d/Quaternion Propagator/qDot'
 * '<S18>'  : 'attitude3d/Quaternion Propagator/qDot/quat product'
 * '<S19>'  : 'attitude3d/Quaternion Propagator/qDot/quat product/Cross Product'
 * '<S20>'  : 'attitude3d/Star Sensor 1 Minimum Solar Exclusion/Normalize Vector'
 * '<S21>'  : 'attitude3d/Star Sensor 1 Minimum Solar Exclusion/Normalize Vector1'
 * '<S22>'  : 'attitude3d/Star Sensor 2 Minimum Solar Exclusion/Normalize Vector'
 * '<S23>'  : 'attitude3d/Star Sensor 2 Minimum Solar Exclusion/Normalize Vector1'
 * '<S24>'  : 'attitude3d/Subsystem/Normalize Vector'
 * '<S25>'  : 'attitude3d/Subsystem/Normalize Vector1'
 * '<S26>'  : 'attitude3d/Subsystem/Windowed Integrator3'
 * '<S27>'  : 'attitude3d/Subsystem1/Normalize Vector'
 * '<S28>'  : 'attitude3d/Subsystem1/Normalize Vector1'
 * '<S29>'  : 'attitude3d/Subsystem1/Windowed Integrator3'
 * '<S30>'  : 'attitude3d/Subsystem2/frame change5'
 * '<S31>'  : 'attitude3d/Subsystem2/frame change6'
 * '<S32>'  : 'attitude3d/Subsystem2/frame change7'
 * '<S33>'  : 'attitude3d/Subsystem2/frame change8'
 * '<S34>'  : 'attitude3d/Subsystem2/frame change9'
 * '<S35>'  : 'attitude3d/Subsystem2/frame change5/quat product'
 * '<S36>'  : 'attitude3d/Subsystem2/frame change5/quat product1'
 * '<S37>'  : 'attitude3d/Subsystem2/frame change5/transposeQuaternion'
 * '<S38>'  : 'attitude3d/Subsystem2/frame change5/quat product/Cross Product'
 * '<S39>'  : 'attitude3d/Subsystem2/frame change5/quat product1/Cross Product'
 * '<S40>'  : 'attitude3d/Subsystem2/frame change6/quat product'
 * '<S41>'  : 'attitude3d/Subsystem2/frame change6/quat product1'
 * '<S42>'  : 'attitude3d/Subsystem2/frame change6/transposeQuaternion'
 * '<S43>'  : 'attitude3d/Subsystem2/frame change6/quat product/Cross Product'
 * '<S44>'  : 'attitude3d/Subsystem2/frame change6/quat product1/Cross Product'
 * '<S45>'  : 'attitude3d/Subsystem2/frame change7/quat product'
 * '<S46>'  : 'attitude3d/Subsystem2/frame change7/quat product1'
 * '<S47>'  : 'attitude3d/Subsystem2/frame change7/transposeQuaternion'
 * '<S48>'  : 'attitude3d/Subsystem2/frame change7/quat product/Cross Product'
 * '<S49>'  : 'attitude3d/Subsystem2/frame change7/quat product1/Cross Product'
 * '<S50>'  : 'attitude3d/Subsystem2/frame change8/quat product'
 * '<S51>'  : 'attitude3d/Subsystem2/frame change8/quat product1'
 * '<S52>'  : 'attitude3d/Subsystem2/frame change8/transposeQuaternion'
 * '<S53>'  : 'attitude3d/Subsystem2/frame change8/quat product/Cross Product'
 * '<S54>'  : 'attitude3d/Subsystem2/frame change8/quat product1/Cross Product'
 * '<S55>'  : 'attitude3d/Subsystem2/frame change9/quat product'
 * '<S56>'  : 'attitude3d/Subsystem2/frame change9/quat product1'
 * '<S57>'  : 'attitude3d/Subsystem2/frame change9/transposeQuaternion'
 * '<S58>'  : 'attitude3d/Subsystem2/frame change9/quat product/Cross Product'
 * '<S59>'  : 'attitude3d/Subsystem2/frame change9/quat product1/Cross Product'
 * '<S60>'  : 'attitude3d/Thrust Pointing Efficiency/Compare To Zero'
 * '<S61>'  : 'attitude3d/Thrust Pointing Efficiency/Normalize Vector'
 * '<S62>'  : 'attitude3d/Thrust Pointing Efficiency/Normalize Vector1'
 * '<S63>'  : 'attitude3d/Total Pointing Efficiency (Comms)/Compare To Zero'
 * '<S64>'  : 'attitude3d/Total Pointing Efficiency (Comms)/Normalize Vector'
 * '<S65>'  : 'attitude3d/Total Pointing Efficiency (Comms)/Normalize Vector1'
 * '<S66>'  : 'attitude3d/Total Pointing Efficiency (Solar)/Compare To Zero'
 * '<S67>'  : 'attitude3d/Total Pointing Efficiency (Solar)/Normalize Vector'
 * '<S68>'  : 'attitude3d/Total Pointing Efficiency (Solar)/Normalize Vector1'
 * '<S69>'  : 'attitude3d/frame2quat1/MATLAB Function'
 */

/* user code (bottom of header file) */
extern const int_T gblNumToFiles;
extern const int_T gblNumFrFiles;
extern const int_T gblNumFrWksBlocks;
extern rtInportTUtable *gblInportTUtables;
extern const char *gblInportFileName;
extern const int_T gblNumRootInportBlks;
extern const int_T gblNumModelInputs;
extern const int_T gblInportDataTypeIdx[];
extern const int_T gblInportDims[];
extern const int_T gblInportComplex[];
extern const int_T gblInportInterpoFlag[];
extern const int_T gblInportContinuous[];

#endif                                 /* RTW_HEADER_attitude3d_h_ */
