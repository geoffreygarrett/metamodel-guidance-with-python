/*
 * attitude3d_types.h
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

#ifndef RTW_HEADER_attitude3d_types_h_
#define RTW_HEADER_attitude3d_types_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#ifndef DEFINED_TYPEDEF_FOR_ENVIRONMENT_
#define DEFINED_TYPEDEF_FOR_ENVIRONMENT_

typedef struct {
  real_T thrust_vector[3];
  real_T thrust_weight;
  real_T solar_occulted_integral;
  real_T solar_occulted_boolean;
  real_T solar_vector[3];
  real_T comms_occulted_integral;
  real_T comms_occulted_boolean;
  real_T comms_vector[3];
  real_T r_s[3];
  real_T v_s[3];
  real_T r_c[3];
  real_T v_c[3];
  real_T r_t[3];
  real_T v_t[3];
} ENVIRONMENT;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_nois8vFfP57DutoSgf9HZD_
#define DEFINED_TYPEDEF_FOR_struct_nois8vFfP57DutoSgf9HZD_

typedef struct {
  real_T star_sensor_1_vb[3];
  real_T star_sensor_2_vb[3];
  real_T thruster_vb[3];
  real_T antenna_vb[3];
  real_T solar_array_vb[3];
  real_T thrust_shadow_weight;
  real_T thrust_no_shadow_weight;
  real_T window_t;
  int16_T window_n;
} struct_nois8vFfP57DutoSgf9HZD;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_rawc2dqRCLbbSQv98WCoDC_
#define DEFINED_TYPEDEF_FOR_struct_rawc2dqRCLbbSQv98WCoDC_

typedef struct {
  real_T max_omega[3];
  real_T init_vel_vec[3];
  real_T init_pos_vec[3];
  real_T init_xBI[3];
  real_T init_yBI[3];
  real_T init_zBI[3];
} struct_rawc2dqRCLbbSQv98WCoDC;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_qj1aZXRxDpRc9BsHnZQAtC_
#define DEFINED_TYPEDEF_FOR_struct_qj1aZXRxDpRc9BsHnZQAtC_

typedef struct {
  real_T sun_grav_param;
  real_T target_grav_param;
  real_T target_mean_sma;
  real_T target_mean_radius;
  real_T satellite_h;
  real_T satellite_sma;
  real_T mean_motion;
  real_T P;
  real_T comms_mean_sma;
  real_T initial_classical_satellite[7];
  real_T initial_classical_target[7];
  real_T initial_classical_comms[7];
} struct_qj1aZXRxDpRc9BsHnZQAtC;

#endif

#ifndef typedef_dsp_private_RunningMinimum_at_T
#define typedef_dsp_private_RunningMinimum_at_T

typedef struct {
  int32_T isInitialized;
  boolean_T isSetupComplete;
  real_T pCumMin;
} dsp_private_RunningMinimum_at_T;

#endif                               /*typedef_dsp_private_RunningMinimum_at_T*/

#ifndef typedef_c_cell_wrap_attitude3d_T
#define typedef_c_cell_wrap_attitude3d_T

typedef struct {
  uint32_T f1[8];
} c_cell_wrap_attitude3d_T;

#endif                                 /*typedef_c_cell_wrap_attitude3d_T*/

#ifndef typedef_dsp_MovingMinimum_attitude3d_T
#define typedef_dsp_MovingMinimum_attitude3d_T

typedef struct {
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  c_cell_wrap_attitude3d_T inputVarSize;
  int32_T NumChannels;
  dsp_private_RunningMinimum_at_T *pStat;
} dsp_MovingMinimum_attitude3d_T;

#endif                                /*typedef_dsp_MovingMinimum_attitude3d_T*/

#ifndef typedef_dsp_private_RunningMaximum_at_T
#define typedef_dsp_private_RunningMaximum_at_T

typedef struct {
  int32_T isInitialized;
  boolean_T isSetupComplete;
  real_T pCumMax;
} dsp_private_RunningMaximum_at_T;

#endif                               /*typedef_dsp_private_RunningMaximum_at_T*/

#ifndef typedef_dsp_MovingMaximum_attitude3d_T
#define typedef_dsp_MovingMaximum_attitude3d_T

typedef struct {
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  c_cell_wrap_attitude3d_T inputVarSize;
  int32_T NumChannels;
  dsp_private_RunningMaximum_at_T *pStat;
} dsp_MovingMaximum_attitude3d_T;

#endif                                /*typedef_dsp_MovingMaximum_attitude3d_T*/

/* Parameters (default storage) */
typedef struct P_ P;

#endif                                 /* RTW_HEADER_attitude3d_types_h_ */
