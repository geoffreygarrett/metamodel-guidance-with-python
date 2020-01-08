/*
 * attitude3d_types.h
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

#ifndef RTW_HEADER_attitude3d_types_h_
#define RTW_HEADER_attitude3d_types_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
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

/* Parameters (default storage) */
typedef struct P_ P;

#endif                                 /* RTW_HEADER_attitude3d_types_h_ */
