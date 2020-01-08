/*
 * attitude3d.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "attitude3d".
 *
 * Model version              : 1.53
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 * C source code generated on : Mon Dec  9 18:35:03 2019
 *
 * Target selection: rsim.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
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
#include "rtGetNaN.h"
#include "rt_defines.h"
#define MODEL_NAME                     attitude3d
#define NSAMPLE_TIMES                  (2)                       /* Number of sample times */
#define NINPUTS                        (0)                       /* Number of model inputs */
#define NOUTPUTS                       (0)                       /* Number of model outputs */
#define NBLOCKIO                       (48)                      /* Number of data output port signals */
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

/* Block signals for system '<S5>/Moving Minimum' */
typedef struct {
  real_T MovingMinimum;                /* '<S5>/Moving Minimum' */
} B_MovingMinimum_attitude3d_T;

/* Block states (default storage) for system '<S5>/Moving Minimum' */
typedef struct {
  dsp_MovingMinimum_attitude3d_T obj;  /* '<S5>/Moving Minimum' */
  dsp_private_RunningMinimum_at_T gobj_0;/* '<S5>/Moving Minimum' */
  dsp_private_RunningMinimum_at_T gobj_1;/* '<S5>/Moving Minimum' */
  boolean_T objisempty;                /* '<S5>/Moving Minimum' */
} DW_MovingMinimum_attitude3d_T;

/* Block signals (default storage) */
typedef struct {
  real_T r_target[3];                  /* '<Root>/From File' */
  real_T r_satellite[3];               /* '<Root>/From File1' */
  real_T r_comms[3];                   /* '<Root>/From File6' */
  real_T v_target[3];                  /* '<Root>/From File7' */
  real_T v_satellite[3];               /* '<Root>/From File2' */
  real_T v_comms[3];                   /* '<Root>/From File3' */
  real_T solar_v[3];                   /* '<Root>/From File4' */
  real_T integral_solar;               /* '<Root>/From File9' */
  real_T sight_solar;                  /* '<Root>/From File10' */
  real_T comms_v[3];                   /* '<Root>/From File11' */
  real_T integral_comms;               /* '<Root>/From File5' */
  real_T sight_comms;                  /* '<Root>/From File12' */
  real_T thrust_v_ref[3];              /* '<Root>/From File8' */
  real_T Divide;                       /* '<S10>/Divide' */
  real_T Divide_i;                     /* '<S9>/Divide' */
  real_T Product[3];                   /* '<S17>/Product' */
  real_T Product_f[3];                 /* '<S16>/Product' */
  real_T Product_b[3];                 /* '<S15>/Product' */
  real_T Product_k[3];                 /* '<S14>/Product' */
  real_T Product_p[3];                 /* '<S13>/Product' */
  real_T Saturation;                   /* '<S5>/Saturation' */
  real_T min_exclusion;                /* '<S5>/Product' */
  real_T Acos;                         /* '<S5>/Acos' */
  real_T Saturation_i;                 /* '<S6>/Saturation' */
  real_T min_exclusion_m;              /* '<S6>/Product' */
  real_T Acos_i;                       /* '<S6>/Acos' */
  real_T Saturation_k;                 /* '<S7>/Saturation' */
  real_T min_exclusion_g;              /* '<S7>/Product' */
  real_T Acos_i1;                      /* '<S7>/Acos' */
  real_T Switch;                       /* '<S8>/Switch' */
  real_T integral_pointing;            /* '<S8>/Integrator1' */
  real_T Divide_b;                     /* '<S8>/Divide' */
  real_T DotProduct1;                  /* '<S8>/Dot Product1' */
  real_T ManualSwitch1;                /* '<S8>/Manual Switch1' */
  real_T Switch1;                      /* '<S8>/Switch1' */
  real_T current_solar_e;              /* '<S8>/Product' */
  real_T ManualSwitch1_c;              /* '<S9>/Manual Switch1' */
  real_T current_solar_e_p;            /* '<S9>/Product' */
  real_T ManualSwitch1_m;              /* '<S10>/Manual Switch1' */
  real_T current_solar_e_pn;           /* '<S10>/Product' */
  real_T Clock1;                       /* '<S3>/Clock1' */
  real_T qA2B[4];                      /* '<S18>/MATLAB Function' */
  real_T y[4];                         /* '<S4>/Quaternion Normed' */
  real_T q_dot[4];                     /* '<S4>/Quaternion Differential' */
  boolean_T Compare;                   /* '<S20>/Compare' */
  B_MovingMinimum_attitude3d_T MovingMinimum_pn;/* '<S5>/Moving Minimum' */
  B_MovingMinimum_attitude3d_T MovingMinimum_p;/* '<S5>/Moving Minimum' */
  B_MovingMinimum_attitude3d_T MovingMinimum;/* '<S5>/Moving Minimum' */
} B;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T DiscreteFIRFilter_states[3];  /* '<S11>/Discrete FIR Filter' */
  real_T DiscreteFIRFilter_states_d[5];/* '<S12>/Discrete FIR Filter' */
  struct {
    void *PrevTimePtr;
  } FromFile_PWORK;                    /* '<Root>/From File' */

  struct {
    void *PrevTimePtr;
  } FromFile1_PWORK;                   /* '<Root>/From File1' */

  struct {
    void *PrevTimePtr;
  } FromFile6_PWORK;                   /* '<Root>/From File6' */

  struct {
    void *PrevTimePtr;
  } FromFile7_PWORK;                   /* '<Root>/From File7' */

  struct {
    void *PrevTimePtr;
  } FromFile2_PWORK;                   /* '<Root>/From File2' */

  struct {
    void *PrevTimePtr;
  } FromFile3_PWORK;                   /* '<Root>/From File3' */

  struct {
    void *PrevTimePtr;
  } FromFile4_PWORK;                   /* '<Root>/From File4' */

  struct {
    void *PrevTimePtr;
  } FromFile9_PWORK;                   /* '<Root>/From File9' */

  struct {
    void *PrevTimePtr;
  } FromFile10_PWORK;                  /* '<Root>/From File10' */

  struct {
    void *PrevTimePtr;
  } FromFile11_PWORK;                  /* '<Root>/From File11' */

  struct {
    void *PrevTimePtr;
  } FromFile5_PWORK;                   /* '<Root>/From File5' */

  struct {
    void *PrevTimePtr;
  } FromFile12_PWORK;                  /* '<Root>/From File12' */

  struct {
    void *PrevTimePtr;
  } FromFile8_PWORK;                   /* '<Root>/From File8' */

  struct {
    void *LoggedData[13];
  } Scope_PWORK;                       /* '<Root>/Scope' */

  struct {
    void *LoggedData[2];
  } Scope1_PWORK;                      /* '<Root>/Scope1' */

  struct {
    void *LoggedData[2];
  } Scope2_PWORK;                      /* '<Root>/Scope2' */

  struct {
    void *LoggedData[5];
  } Scope5_PWORK;                      /* '<Root>/Scope5' */

  struct {
    void *LoggedData[2];
  } Scope_PWORK_g;                     /* '<S4>/Scope' */

  struct {
    void *LoggedData;
  } Scope1_PWORK_o;                    /* '<S5>/Scope1' */

  struct {
    void *LoggedData;
  } Scope2_PWORK_o;                    /* '<S5>/Scope2' */

  struct {
    void *LoggedData;
  } Scope3_PWORK;                      /* '<S5>/Scope3' */

  struct {
    void *LoggedData;
  } Scope6_PWORK;                      /* '<S5>/Scope6' */

  struct {
    void *LoggedData;
  } Scope1_PWORK_k;                    /* '<S6>/Scope1' */

  struct {
    void *LoggedData;
  } Scope2_PWORK_i;                    /* '<S6>/Scope2' */

  struct {
    void *LoggedData;
  } Scope3_PWORK_e;                    /* '<S6>/Scope3' */

  struct {
    void *LoggedData;
  } Scope6_PWORK_l;                    /* '<S6>/Scope6' */

  struct {
    void *LoggedData;
  } Scope1_PWORK_p;                    /* '<S7>/Scope1' */

  struct {
    void *LoggedData;
  } Scope2_PWORK_a;                    /* '<S7>/Scope2' */

  struct {
    void *LoggedData;
  } Scope3_PWORK_f;                    /* '<S7>/Scope3' */

  struct {
    void *LoggedData;
  } Scope6_PWORK_c;                    /* '<S7>/Scope6' */

  struct {
    void *LoggedData;
  } Scope4_PWORK;                      /* '<S8>/Scope4' */

  struct {
    void *LoggedData;
  } Scope6_PWORK_cq;                   /* '<S8>/Scope6' */

  struct {
    void *LoggedData;
  } Scope7_PWORK;                      /* '<S8>/Scope7' */

  struct {
    void *LoggedData;
  } Scope8_PWORK;                      /* '<S8>/Scope8' */

  struct {
    void *LoggedData;
  } Scope9_PWORK;                      /* '<S8>/Scope9' */

  struct {
    void *LoggedData;
  } Scope6_PWORK_e;                    /* '<S9>/Scope6' */

  struct {
    void *LoggedData;
  } Scope6_PWORK_a;                    /* '<S10>/Scope6' */

  struct {
    void *LoggedData[2];
  } Scope_PWORK_b;                     /* '<S3>/Scope' */

  int_T Integrator_IWORK;              /* '<S4>/Integrator' */
  DW_MovingMinimum_attitude3d_T MovingMinimum_pn;/* '<S5>/Moving Minimum' */
  DW_MovingMinimum_attitude3d_T MovingMinimum_p;/* '<S5>/Moving Minimum' */
  DW_MovingMinimum_attitude3d_T MovingMinimum;/* '<S5>/Moving Minimum' */
} DW;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator1_CSTATE;           /* '<S10>/Integrator1' */
  real_T Integrator1_CSTATE_a;         /* '<S9>/Integrator1' */
  real_T Integrator_CSTATE[4];         /* '<S4>/Integrator' */
  real_T Integrator2_CSTATE;           /* '<S8>/Integrator2' */
  real_T Integrator1_CSTATE_f;         /* '<S8>/Integrator1' */
} X;

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator1_CSTATE;           /* '<S10>/Integrator1' */
  real_T Integrator1_CSTATE_a;         /* '<S9>/Integrator1' */
  real_T Integrator_CSTATE[4];         /* '<S4>/Integrator' */
  real_T Integrator2_CSTATE;           /* '<S8>/Integrator2' */
  real_T Integrator1_CSTATE_f;         /* '<S8>/Integrator1' */
} XDot;

/* State disabled  */
typedef struct {
  boolean_T Integrator1_CSTATE;        /* '<S10>/Integrator1' */
  boolean_T Integrator1_CSTATE_a;      /* '<S9>/Integrator1' */
  boolean_T Integrator_CSTATE[4];      /* '<S4>/Integrator' */
  boolean_T Integrator2_CSTATE;        /* '<S8>/Integrator2' */
  boolean_T Integrator1_CSTATE_f;      /* '<S8>/Integrator1' */
} XDis;

/* Parameters (default storage) */
struct P_ {
  real_T P;                            /* Variable: P
                                        * Referenced by: '<S3>/Constant'
                                        */
  real_T antenna_vb[3];                /* Variable: antenna_vb
                                        * Referenced by: '<Root>/Constant3'
                                        */
  real_T init_xBI[3];                  /* Variable: init_xBI
                                        * Referenced by: '<Root>/Constant4'
                                        */
  real_T init_yBI[3];                  /* Variable: init_yBI
                                        * Referenced by: '<Root>/Constant5'
                                        */
  real_T init_zBI[3];                  /* Variable: init_zBI
                                        * Referenced by: '<Root>/Constant6'
                                        */
  real_T solar_array_vb[3];            /* Variable: solar_array_vb
                                        * Referenced by: '<Root>/Constant7'
                                        */
  real_T star_sensor_1_vb[3];          /* Variable: star_sensor_1_vb
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T star_sensor_2_vb[3];          /* Variable: star_sensor_2_vb
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T thrust_no_shadow_weight;      /* Variable: thrust_no_shadow_weight
                                        * Referenced by: '<S8>/Constant12'
                                        */
  real_T thrust_shadow_weight;         /* Variable: thrust_shadow_weight
                                        * Referenced by: '<S8>/Constant10'
                                        */
  real_T thruster_vb[3];               /* Variable: thruster_vb
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T x_test[12];                   /* Variable: x_test
                                        * Referenced by: '<Root>/Test Design'
                                        */
  real_T NormalizeVector_maxzero;     /* Mask Parameter: NormalizeVector_maxzero
                                       * Referenced by: '<S23>/Switch'
                                       */
  real_T NormalizeVector1_maxzero;   /* Mask Parameter: NormalizeVector1_maxzero
                                      * Referenced by: '<S24>/Switch'
                                      */
  real_T NormalizeVector_maxzero_m; /* Mask Parameter: NormalizeVector_maxzero_m
                                     * Referenced by: '<S25>/Switch'
                                     */
  real_T NormalizeVector1_maxzero_i;
                                   /* Mask Parameter: NormalizeVector1_maxzero_i
                                    * Referenced by: '<S26>/Switch'
                                    */
  real_T NormalizeVector_maxzero_o; /* Mask Parameter: NormalizeVector_maxzero_o
                                     * Referenced by: '<S27>/Switch'
                                     */
  real_T NormalizeVector1_maxzero_c;
                                   /* Mask Parameter: NormalizeVector1_maxzero_c
                                    * Referenced by: '<S28>/Switch'
                                    */
  real_T NormalizeVector_maxzero_f; /* Mask Parameter: NormalizeVector_maxzero_f
                                     * Referenced by: '<S31>/Switch'
                                     */
  real_T NormalizeVector1_maxzero_c1;
                                  /* Mask Parameter: NormalizeVector1_maxzero_c1
                                   * Referenced by: '<S32>/Switch'
                                   */
  real_T NormalizeVector_maxzero_p; /* Mask Parameter: NormalizeVector_maxzero_p
                                     * Referenced by: '<S34>/Switch'
                                     */
  real_T NormalizeVector1_maxzero_d;
                                   /* Mask Parameter: NormalizeVector1_maxzero_d
                                    * Referenced by: '<S35>/Switch'
                                    */
  real_T NormalizeVector_maxzero_j; /* Mask Parameter: NormalizeVector_maxzero_j
                                     * Referenced by: '<S37>/Switch'
                                     */
  real_T NormalizeVector1_maxzero_g;
                                   /* Mask Parameter: NormalizeVector1_maxzero_g
                                    * Referenced by: '<S38>/Switch'
                                    */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S29>/Constant'
                                        */
  real_T Constant_Value_e;             /* Expression: 0
                                        * Referenced by: '<S30>/Constant'
                                        */
  real_T Constant_Value_c;             /* Expression: 0
                                        * Referenced by: '<S33>/Constant'
                                        */
  real_T Constant_Value_b;             /* Expression: 0
                                        * Referenced by: '<S36>/Constant'
                                        */
  real_T Constant_Value_k;             /* Expression: 0
                                        * Referenced by: '<S20>/Constant'
                                        */
  real_T Constant_Value_b5;            /* Expression: 1
                                        * Referenced by: '<S10>/Constant'
                                        */
  real_T Integrator1_IC;               /* Expression: 0
                                        * Referenced by: '<S10>/Integrator1'
                                        */
  real_T DiscreteFIRFilter_InitialStates;/* Expression: 0
                                          * Referenced by: '<S11>/Discrete FIR Filter'
                                          */
  real_T DiscreteFIRFilter_Coefficients[4];/* Expression: ones(1,integperiod)
                                            * Referenced by: '<S11>/Discrete FIR Filter'
                                            */
  real_T Constant_Value_o;             /* Expression: 1
                                        * Referenced by: '<S9>/Constant'
                                        */
  real_T Integrator1_IC_k;             /* Expression: 0
                                        * Referenced by: '<S9>/Integrator1'
                                        */
  real_T DiscreteFIRFilter_InitialStat_l;/* Expression: 0
                                          * Referenced by: '<S12>/Discrete FIR Filter'
                                          */
  real_T DiscreteFIRFilter_Coefficient_l[6];/* Expression: ones(1,integperiod)
                                             * Referenced by: '<S12>/Discrete FIR Filter'
                                             */
  real_T Gain1_Gain[4];                /* Expression: [1 -1 -1 -1]
                                        * Referenced by: '<S19>/Gain1'
                                        */
  real_T Gain1_Gain_m[4];              /* Expression: [1 -1 -1 -1]
                                        * Referenced by: '<S61>/Gain1'
                                        */
  real_T Constant_Value_l;             /* Expression: 1
                                        * Referenced by: '<S17>/Constant'
                                        */
  real_T Gain1_Gain_p[4];              /* Expression: [1 -1 -1 -1]
                                        * Referenced by: '<S56>/Gain1'
                                        */
  real_T Constant_Value_d;             /* Expression: 1
                                        * Referenced by: '<S16>/Constant'
                                        */
  real_T Gain1_Gain_i[4];              /* Expression: [1 -1 -1 -1]
                                        * Referenced by: '<S51>/Gain1'
                                        */
  real_T Constant_Value_g;             /* Expression: 1
                                        * Referenced by: '<S15>/Constant'
                                        */
  real_T Gain1_Gain_h[4];              /* Expression: [1 -1 -1 -1]
                                        * Referenced by: '<S46>/Gain1'
                                        */
  real_T Constant_Value_i;             /* Expression: 1
                                        * Referenced by: '<S14>/Constant'
                                        */
  real_T Gain1_Gain_a[4];              /* Expression: [1 -1 -1 -1]
                                        * Referenced by: '<S41>/Gain1'
                                        */
  real_T Constant_Value_bg;            /* Expression: 1
                                        * Referenced by: '<S13>/Constant'
                                        */
  real_T Constant_Value_p;             /* Expression: 1
                                        * Referenced by: '<S23>/Constant'
                                        */
  real_T Constant_Value_pb;            /* Expression: 1
                                        * Referenced by: '<S24>/Constant'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 1.0
                                        * Referenced by: '<S5>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 0
                                        * Referenced by: '<S5>/Saturation'
                                        */
  real_T Constant_Value_oj;            /* Expression: 1
                                        * Referenced by: '<S25>/Constant'
                                        */
  real_T Constant_Value_pw;            /* Expression: 1
                                        * Referenced by: '<S26>/Constant'
                                        */
  real_T Saturation_UpperSat_o;        /* Expression: 1.0
                                        * Referenced by: '<S6>/Saturation'
                                        */
  real_T Saturation_LowerSat_p;        /* Expression: 0
                                        * Referenced by: '<S6>/Saturation'
                                        */
  real_T Constant_Value_kd;            /* Expression: 1
                                        * Referenced by: '<S27>/Constant'
                                        */
  real_T Constant_Value_gs;            /* Expression: 1
                                        * Referenced by: '<S28>/Constant'
                                        */
  real_T Saturation_UpperSat_j;        /* Expression: 1.0
                                        * Referenced by: '<S7>/Saturation'
                                        */
  real_T Saturation_LowerSat_p4;       /* Expression: 0
                                        * Referenced by: '<S7>/Saturation'
                                        */
  real_T Constant9_Value;              /* Expression: 1
                                        * Referenced by: '<S8>/Constant9'
                                        */
  real_T Integrator2_IC;               /* Expression: 0
                                        * Referenced by: '<S8>/Integrator2'
                                        */
  real_T Integrator1_IC_b;             /* Expression: 0
                                        * Referenced by: '<S8>/Integrator1'
                                        */
  real_T Constant_Value_i2;            /* Expression: 1
                                        * Referenced by: '<S31>/Constant'
                                        */
  real_T Constant_Value_bf;            /* Expression: 1
                                        * Referenced by: '<S32>/Constant'
                                        */
  real_T Constant11_Value;             /* Expression: 1
                                        * Referenced by: '<S8>/Constant11'
                                        */
  real_T Constant_Value_os;            /* Expression: 1
                                        * Referenced by: '<S34>/Constant'
                                        */
  real_T Constant_Value_n;             /* Expression: 1
                                        * Referenced by: '<S35>/Constant'
                                        */
  real_T Saturation_UpperSat_e;        /* Expression: 1.0
                                        * Referenced by: '<S9>/Saturation'
                                        */
  real_T Saturation_LowerSat_n;        /* Expression: 0
                                        * Referenced by: '<S9>/Saturation'
                                        */
  real_T Constant11_Value_h;           /* Expression: 1
                                        * Referenced by: '<S9>/Constant11'
                                        */
  real_T Constant_Value_ku;            /* Expression: 1
                                        * Referenced by: '<S37>/Constant'
                                        */
  real_T Constant_Value_lf;            /* Expression: 1
                                        * Referenced by: '<S38>/Constant'
                                        */
  real_T Saturation_UpperSat_l;        /* Expression: 1.0
                                        * Referenced by: '<S10>/Saturation'
                                        */
  real_T Saturation_LowerSat_pj;       /* Expression: 0
                                        * Referenced by: '<S10>/Saturation'
                                        */
  real_T Constant11_Value_c;           /* Expression: 1
                                        * Referenced by: '<S10>/Constant11'
                                        */
  uint8_T ManualSwitch1_CurrentSetting;
                             /* Computed Parameter: ManualSwitch1_CurrentSetting
                              * Referenced by: '<S8>/Manual Switch1'
                              */
  uint8_T ManualSwitch1_CurrentSetting_k;
                           /* Computed Parameter: ManualSwitch1_CurrentSetting_k
                            * Referenced by: '<S9>/Manual Switch1'
                            */
  uint8_T ManualSwitch1_CurrentSetting_g;
                           /* Computed Parameter: ManualSwitch1_CurrentSetting_g
                            * Referenced by: '<S10>/Manual Switch1'
                            */
};

/* External data declarations for dependent source files */
extern const char *RT_MEMORY_ALLOCATION_ERROR;
extern B rtB;                          /* block i/o */
extern X rtX;                          /* states (continuous) */
extern DW rtDW;                        /* states (dwork) */
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
 * '<S2>'   : 'attitude3d/Interpolator '
 * '<S3>'   : 'attitude3d/Orbital Period Termination Condition'
 * '<S4>'   : 'attitude3d/Quaternion Propagator'
 * '<S5>'   : 'attitude3d/Star Sensor 1 Minimum Solar Exclusion'
 * '<S6>'   : 'attitude3d/Star Sensor 2 Minimum Solar Exclusion'
 * '<S7>'   : 'attitude3d/Star sensor 1 Minimum Planetary Exclusion'
 * '<S8>'   : 'attitude3d/Thrust Pointing Efficiency'
 * '<S9>'   : 'attitude3d/Total Pointing Efficiency (Comms)'
 * '<S10>'  : 'attitude3d/Total Pointing Efficiency (Solar)'
 * '<S11>'  : 'attitude3d/Windowed Integrator1'
 * '<S12>'  : 'attitude3d/Windowed Integrator2'
 * '<S13>'  : 'attitude3d/frame change'
 * '<S14>'  : 'attitude3d/frame change1'
 * '<S15>'  : 'attitude3d/frame change2'
 * '<S16>'  : 'attitude3d/frame change3'
 * '<S17>'  : 'attitude3d/frame change4'
 * '<S18>'  : 'attitude3d/frame2quat1'
 * '<S19>'  : 'attitude3d/transposeQuaternion1'
 * '<S20>'  : 'attitude3d/Orbital Period Termination Condition/Compare To Zero'
 * '<S21>'  : 'attitude3d/Quaternion Propagator/Quaternion Differential'
 * '<S22>'  : 'attitude3d/Quaternion Propagator/Quaternion Normed'
 * '<S23>'  : 'attitude3d/Star Sensor 1 Minimum Solar Exclusion/Normalize Vector'
 * '<S24>'  : 'attitude3d/Star Sensor 1 Minimum Solar Exclusion/Normalize Vector1'
 * '<S25>'  : 'attitude3d/Star Sensor 2 Minimum Solar Exclusion/Normalize Vector'
 * '<S26>'  : 'attitude3d/Star Sensor 2 Minimum Solar Exclusion/Normalize Vector1'
 * '<S27>'  : 'attitude3d/Star sensor 1 Minimum Planetary Exclusion/Normalize Vector'
 * '<S28>'  : 'attitude3d/Star sensor 1 Minimum Planetary Exclusion/Normalize Vector1'
 * '<S29>'  : 'attitude3d/Thrust Pointing Efficiency/Compare To Zero'
 * '<S30>'  : 'attitude3d/Thrust Pointing Efficiency/Compare To Zero1'
 * '<S31>'  : 'attitude3d/Thrust Pointing Efficiency/Normalize Vector'
 * '<S32>'  : 'attitude3d/Thrust Pointing Efficiency/Normalize Vector1'
 * '<S33>'  : 'attitude3d/Total Pointing Efficiency (Comms)/Compare To Zero'
 * '<S34>'  : 'attitude3d/Total Pointing Efficiency (Comms)/Normalize Vector'
 * '<S35>'  : 'attitude3d/Total Pointing Efficiency (Comms)/Normalize Vector1'
 * '<S36>'  : 'attitude3d/Total Pointing Efficiency (Solar)/Compare To Zero'
 * '<S37>'  : 'attitude3d/Total Pointing Efficiency (Solar)/Normalize Vector'
 * '<S38>'  : 'attitude3d/Total Pointing Efficiency (Solar)/Normalize Vector1'
 * '<S39>'  : 'attitude3d/frame change/quat product'
 * '<S40>'  : 'attitude3d/frame change/quat product1'
 * '<S41>'  : 'attitude3d/frame change/transposeQuaternion'
 * '<S42>'  : 'attitude3d/frame change/quat product/Cross Product'
 * '<S43>'  : 'attitude3d/frame change/quat product1/Cross Product'
 * '<S44>'  : 'attitude3d/frame change1/quat product'
 * '<S45>'  : 'attitude3d/frame change1/quat product1'
 * '<S46>'  : 'attitude3d/frame change1/transposeQuaternion'
 * '<S47>'  : 'attitude3d/frame change1/quat product/Cross Product'
 * '<S48>'  : 'attitude3d/frame change1/quat product1/Cross Product'
 * '<S49>'  : 'attitude3d/frame change2/quat product'
 * '<S50>'  : 'attitude3d/frame change2/quat product1'
 * '<S51>'  : 'attitude3d/frame change2/transposeQuaternion'
 * '<S52>'  : 'attitude3d/frame change2/quat product/Cross Product'
 * '<S53>'  : 'attitude3d/frame change2/quat product1/Cross Product'
 * '<S54>'  : 'attitude3d/frame change3/quat product'
 * '<S55>'  : 'attitude3d/frame change3/quat product1'
 * '<S56>'  : 'attitude3d/frame change3/transposeQuaternion'
 * '<S57>'  : 'attitude3d/frame change3/quat product/Cross Product'
 * '<S58>'  : 'attitude3d/frame change3/quat product1/Cross Product'
 * '<S59>'  : 'attitude3d/frame change4/quat product'
 * '<S60>'  : 'attitude3d/frame change4/quat product1'
 * '<S61>'  : 'attitude3d/frame change4/transposeQuaternion'
 * '<S62>'  : 'attitude3d/frame change4/quat product/Cross Product'
 * '<S63>'  : 'attitude3d/frame change4/quat product1/Cross Product'
 * '<S64>'  : 'attitude3d/frame2quat1/MATLAB Function'
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
