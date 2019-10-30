/*
 * rs_bicycle.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "rs_bicycle".
 *
 * Model version              : 1.70
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 * C source code generated on : Wed Oct 30 16:45:18 2019
 *
 * Target selection: rsim.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_rs_bicycle_h_
#define RTW_HEADER_rs_bicycle_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef rs_bicycle_COMMON_INCLUDES_
# define rs_bicycle_COMMON_INCLUDES_
#include <stdlib.h>
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "rsim.h"
#include "rt_logging.h"
#include "dt_info.h"
#endif                                 /* rs_bicycle_COMMON_INCLUDES_ */

#include "rs_bicycle_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_nonfinite.h"
#include "rt_defines.h"
#define MODEL_NAME                     rs_bicycle
#define NSAMPLE_TIMES                  (2)                       /* Number of sample times */
#define NINPUTS                        (0)                       /* Number of model inputs */
#define NOUTPUTS                       (13)                      /* Number of model outputs */
#define NBLOCKIO                       (67)                      /* Number of data output port signals */
#define NUM_ZC_EVENTS                  (0)                       /* Number of zero-crossing events */
#ifndef NCSTATES
# define NCSTATES                      (4)                       /* Number of continuous states */
#elif NCSTATES != 4
# error Invalid specification of NCSTATES defined in compiler command
#endif

#ifndef rtmGetDataMapInfo
# define rtmGetDataMapInfo(rtm)        (NULL)
#endif

#ifndef rtmSetDataMapInfo
# define rtmSetDataMapInfo(rtm, val)
#endif

/* Block signals for system '<Root>/Moving Maximum3' */
typedef struct {
  real_T f9_v3_max;                    /* '<Root>/Moving Maximum3' */
} B_MovingMaximum3_rs_bicycle_T;

/* Block states (default storage) for system '<Root>/Moving Maximum3' */
typedef struct {
  e_dsp_private_SlidingWindowMa_T gobj_0;/* '<Root>/Moving Maximum3' */
  e_dsp_private_SlidingWindowMa_T gobj_1;/* '<Root>/Moving Maximum3' */
  dsp_MovingMaximum_rs_bicycle_T obj;  /* '<Root>/Moving Maximum3' */
  boolean_T objisempty;                /* '<Root>/Moving Maximum3' */
} DW_MovingMaximum3_rs_bicycle_T;

/* Block signals (default storage) */
typedef struct {
  real_T init_position;                /* '<Root>/Initial Position' */
  real_T pos;                          /* '<Root>/Integrator' */
  real_T frac_dist;                    /* '<S9>/Divide' */
  real_T Integrator;                   /* '<S10>/Integrator' */
  real_T Clock7;                       /* '<S10>/Clock7' */
  real_T Switch;                       /* '<S10>/Switch' */
  real_T Product[2];                   /* '<S7>/Product' */
  real_T Sum[2];                       /* '<S11>/Sum' */
  real_T Abs[2];                       /* '<S11>/Abs' */
  real_T Clock1;                       /* '<Root>/Clock1' */
  real_T Sum1[2];                      /* '<S8>/Sum1' */
  real_T Switch1[2];                   /* '<S8>/Switch1' */
  real_T Switch2[2];                   /* '<S11>/Switch2' */
  real_T vel;                          /* '<Root>/Pulse Generator' */
  real_T Product_c;                    /* '<S12>/Product' */
  real_T Square;                       /* '<S12>/Square' */
  real_T Clock5;                       /* '<Root>/Clock5' */
  real_T Sum_n;                        /* '<S1>/Sum' */
  real_T static_friction;              /* '<S1>/Switch' */
  real_T Product1;                     /* '<S12>/Product1' */
  real_T Gain;                         /* '<S12>/Gain' */
  real_T Divide;                       /* '<S12>/Divide' */
  real_T stopping_dist;                /* '<S12>/Sum' */
  real_T Uk1;                          /* '<S2>/UD' */
  real_T Diff;                         /* '<S2>/Diff' */
  real_T Switch_h;                     /* '<S13>/Switch' */
  real_T f6_av_int;                    /* '<Root>/Integrator1' */
  real_T Divide_l;                     /* '<S14>/Divide' */
  real_T Abs_d;                        /* '<S14>/Abs' */
  real_T slipping;                     /* '<S14>/Sum' */
  real_T Exp;                          /* '<S16>/Exp' */
  real_T Abs_h;                        /* '<S16>/Abs' */
  real_T f10_v3_int;                   /* '<Root>/Integrator2' */
  real_T Clock2;                       /* '<Root>/Clock2' */
  real_T Sum2[2];                      /* '<S5>/Sum2' */
  real_T Sum1_o[2];                    /* '<S5>/Sum1' */
  real_T Switch1_m[2];                 /* '<S5>/Switch1' */
  real_T Product_j[2];                 /* '<S3>/Product' */
  real_T Clock3;                       /* '<Root>/Clock3' */
  real_T Sum1_ou;                      /* '<S6>/Sum1' */
  real_T Clock4;                       /* '<Root>/Clock4' */
  real_T Sum1_e;                       /* '<S4>/Sum1' */
  real_T raining;                      /* '<S4>/Switch1' */
  real_T Switch_m;                     /* '<S17>/Switch' */
  real_T cyclist_power_density;        /* '<S13>/Product1' */
  real_T y;                            /* '<S11>/Minimum Between Signals ' */
  real_T frac_forest;                  /* '<S10>/Divide' */
  real_T MovingMaximum_o;              /* '<S9>/Moving Maximum' */
  real_T f3_traffic_dist;              /* '<Root>/Moving Minimum1' */
  boolean_T RelationalOperator[2];     /* '<S8>/Relational Operator' */
  boolean_T RelationalOperator1[2];    /* '<S8>/Relational Operator1' */
  boolean_T LogicalOperator[2];        /* '<S8>/Logical Operator' */
  boolean_T RelationalOperator_p;      /* '<S13>/Relational Operator' */
  boolean_T RelationalOperator1_c;     /* '<S13>/Relational Operator1' */
  boolean_T LogicalOperator_l;         /* '<S13>/Logical Operator' */
  boolean_T RelationalOperator2;       /* '<S13>/Relational Operator2' */
  boolean_T RelationalOperator3;       /* '<S13>/Relational Operator3' */
  boolean_T LogicalOperator1;          /* '<S13>/Logical Operator1' */
  boolean_T LogicalOperator2;          /* '<S13>/Logical Operator2' */
  boolean_T RelationalOperator_i[2];   /* '<S5>/Relational Operator' */
  boolean_T RelationalOperator_h;      /* '<S17>/Relational Operator' */
  boolean_T RelationalOperator1_d;     /* '<S17>/Relational Operator1' */
  boolean_T LogicalOperator_k;         /* '<S17>/Logical Operator' */
  B_MovingMaximum3_rs_bicycle_T MovingMaximum;/* '<Root>/Moving Maximum3' */
  B_MovingMaximum3_rs_bicycle_T MovingMaximum2;/* '<Root>/Moving Maximum3' */
  B_MovingMaximum3_rs_bicycle_T MovingMaximum1;/* '<Root>/Moving Maximum3' */
  B_MovingMaximum3_rs_bicycle_T MovingMaximum3;/* '<Root>/Moving Maximum3' */
} B;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  e_dsp_private_SlidingWindowMi_T gobj_0;/* '<Root>/Moving Minimum1' */
  e_dsp_private_SlidingWindowMi_T gobj_1;/* '<Root>/Moving Minimum1' */
  e_dsp_private_SlidingWindow_o_T gobj_0_h;/* '<S9>/Moving Maximum' */
  e_dsp_private_SlidingWindow_o_T gobj_1_j;/* '<S9>/Moving Maximum' */
  dsp_MovingMinimum_rs_bicycle_T obj;  /* '<Root>/Moving Minimum1' */
  dsp_MovingMaximum_rs_bicycl_o_T obj_g;/* '<S9>/Moving Maximum' */
  real_T UD_DSTATE;                    /* '<S2>/UD' */
  struct {
    void *LoggedData[6];
  } AuxilliaryScope_PWORK;             /* '<Root>/Auxilliary Scope' */

  struct {
    void *LoggedData[10];
  } PerformanceMetricScope_PWORK;      /* '<Root>/Performance Metric Scope' */

  struct {
    void *LoggedData[7];
  } Scope2_PWORK;                      /* '<Root>/Scope2' */

  struct {
    void *LoggedData[3];
  } SolutionScope_PWORK;               /* '<Root>/Solution Scope' */

  int32_T clockTickCounter;            /* '<Root>/Pulse Generator' */
  int_T Integrator_IWORK;              /* '<Root>/Integrator' */
  boolean_T objisempty;                /* '<S9>/Moving Maximum' */
  boolean_T objisempty_g;              /* '<Root>/Moving Minimum1' */
  DW_MovingMaximum3_rs_bicycle_T MovingMaximum;/* '<Root>/Moving Maximum3' */
  DW_MovingMaximum3_rs_bicycle_T MovingMaximum2;/* '<Root>/Moving Maximum3' */
  DW_MovingMaximum3_rs_bicycle_T MovingMaximum1;/* '<Root>/Moving Maximum3' */
  DW_MovingMaximum3_rs_bicycle_T MovingMaximum3;/* '<Root>/Moving Maximum3' */
} DW;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<Root>/Integrator' */
  real_T Integrator_CSTATE_a;          /* '<S10>/Integrator' */
  real_T Integrator1_CSTATE;           /* '<Root>/Integrator1' */
  real_T Integrator2_CSTATE;           /* '<Root>/Integrator2' */
} X;

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<Root>/Integrator' */
  real_T Integrator_CSTATE_a;          /* '<S10>/Integrator' */
  real_T Integrator1_CSTATE;           /* '<Root>/Integrator1' */
  real_T Integrator2_CSTATE;           /* '<Root>/Integrator2' */
} XDot;

/* State disabled  */
typedef struct {
  boolean_T Integrator_CSTATE;         /* '<Root>/Integrator' */
  boolean_T Integrator_CSTATE_a;       /* '<S10>/Integrator' */
  boolean_T Integrator1_CSTATE;        /* '<Root>/Integrator1' */
  boolean_T Integrator2_CSTATE;        /* '<Root>/Integrator2' */
} XDis;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T F[10];                        /* '<Root>/F' */
  real_T S[3];                         /* '<Root>/S' */
} ExtY;

/* Parameters (default storage) */
struct P_ {
  real_T env_forest[2];                /* Variable: env_forest
                                        * Referenced by: '<Root>/Constant7'
                                        */
  real_T env_mu_s_dry;                 /* Variable: env_mu_s_dry
                                        * Referenced by: '<Root>/Constant9'
                                        */
  real_T env_mu_s_wet;                 /* Variable: env_mu_s_wet
                                        * Referenced by: '<Root>/Constant10'
                                        */
  real_T env_route_length;             /* Variable: env_route_length
                                        * Referenced by:
                                        *   '<Root>/Constant4'
                                        *   '<S11>/Constant1'
                                        */
  real_T env_t_rain_start;             /* Variable: env_t_rain_start
                                        * Referenced by: '<Root>/Constant8'
                                        */
  real_T env_traffic_durations[2];     /* Variable: env_traffic_durations
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T env_traffic_pos[2];           /* Variable: env_traffic_pos
                                        * Referenced by: '<Root>/Constant5'
                                        */
  real_T env_traffic_times[2];         /* Variable: env_traffic_times
                                        * Referenced by: '<Root>/Constant6'
                                        */
  real_T g;                            /* Variable: g
                                        * Referenced by:
                                        *   '<S12>/gravity'
                                        *   '<S14>/gravity'
                                        */
  real_T init_position;                /* Variable: init_position
                                        * Referenced by: '<Root>/Initial Position'
                                        */
  real_T Difference_ICPrevInput;       /* Mask Parameter: Difference_ICPrevInput
                                        * Referenced by: '<S2>/UD'
                                        */
  real_T Constant4_Value;              /* Expression: 0
                                        * Referenced by: '<S13>/Constant4'
                                        */
  real_T Integrator_IC;                /* Expression: 0
                                        * Referenced by: '<S10>/Integrator'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S10>/Constant'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S10>/Switch'
                                        */
  real_T Constant_Value_d;             /* Expression: 1
                                        * Referenced by: '<S8>/Constant'
                                        */
  real_T no1_Value;                    /* Expression: 0
                                        * Referenced by: '<S8>/no1'
                                        */
  real_T Switch2_Threshold;            /* Expression: 0
                                        * Referenced by: '<S11>/Switch2'
                                        */
  real_T PulseGenerator_Amp;           /* Expression: 5
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period;        /* Expression: 5
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  real_T PulseGenerator_Duty;          /* Expression: 3
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  real_T PulseGenerator_PhaseDelay;    /* Expression: 0
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  real_T reaction_time_Value;          /* Expression: 0.5
                                        * Referenced by: '<S12>/reaction_time'
                                        */
  real_T Switch_Threshold_h;           /* Expression: 0
                                        * Referenced by: '<S1>/Switch'
                                        */
  real_T Gain_Gain;                    /* Expression: 2
                                        * Referenced by: '<S12>/Gain'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S13>/Constant1'
                                        */
  real_T Constant_Value_k;             /* Expression: 0
                                        * Referenced by: '<S13>/Constant'
                                        */
  real_T Constant3_Value;              /* Expression: 0
                                        * Referenced by: '<S13>/Constant3'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<S13>/Constant2'
                                        */
  real_T Integrator1_IC;               /* Expression: 0
                                        * Referenced by: '<Root>/Integrator1'
                                        */
  real_T Constant_Value_j;             /* Expression: 3
                                        * Referenced by: '<S16>/Constant'
                                        */
  real_T Integrator2_IC;               /* Expression: 0
                                        * Referenced by: '<Root>/Integrator2'
                                        */
  real_T yes_Value;                    /* Expression: 1
                                        * Referenced by: '<S4>/yes'
                                        */
  real_T no_Value;                     /* Expression: 0
                                        * Referenced by: '<S4>/no'
                                        */
  real_T Switch1_Threshold;            /* Expression: 0
                                        * Referenced by: '<S4>/Switch1'
                                        */
  real_T Constant_Value_o;             /* Expression: 1
                                        * Referenced by: '<S17>/Constant'
                                        */
  real_T no_Value_e;                   /* Expression: 0
                                        * Referenced by: '<S17>/no'
                                        */
};

/* External data declarations for dependent source files */
extern const char *RT_MEMORY_ALLOCATION_ERROR;
extern B rtB;                          /* block i/o */
extern X rtX;                          /* states (continuous) */
extern DW rtDW;                        /* states (dwork) */
extern ExtY rtY;                       /* external outputs */
extern P rtP;                          /* parameters */

/* Simulation Structure */
extern SimStruct *const rtS;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Duration' : Unused code path elimination
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
 * '<Root>' : 'rs_bicycle'
 * '<S1>'   : 'rs_bicycle/Current Static Friction'
 * '<S2>'   : 'rs_bicycle/Difference'
 * '<S3>'   : 'rs_bicycle/Forest Boundaries'
 * '<S4>'   : 'rs_bicycle/Raining Boolean'
 * '<S5>'   : 'rs_bicycle/Time From Traffic Encounter'
 * '<S6>'   : 'rs_bicycle/Time Until Raining'
 * '<S7>'   : 'rs_bicycle/Traffic Location(s)'
 * '<S8>'   : 'rs_bicycle/Traffic Passing'
 * '<S9>'   : 'rs_bicycle/aux1: Fraction of Route Distance'
 * '<S10>'  : 'rs_bicycle/aux2: Fraction Spent In Forest'
 * '<S11>'  : 'rs_bicycle/aux3: Closest Instantaenous Traffic'
 * '<S12>'  : 'rs_bicycle/aux4: Instantaneous Stopping Distance'
 * '<S13>'  : 'rs_bicycle/aux5: Cyclist Power Density Transfer'
 * '<S14>'  : 'rs_bicycle/aux6: Exceedance of Static Friction (slipping)'
 * '<S15>'  : 'rs_bicycle/aux7: Final Velocity'
 * '<S16>'  : 'rs_bicycle/aux8: Drag Power Compensation (V^3)'
 * '<S17>'  : 'rs_bicycle/aux2: Fraction Spent In Forest/In Forest Boolearn'
 * '<S18>'  : 'rs_bicycle/aux3: Closest Instantaenous Traffic/Minimum Between Signals '
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

#endif                                 /* RTW_HEADER_rs_bicycle_h_ */
