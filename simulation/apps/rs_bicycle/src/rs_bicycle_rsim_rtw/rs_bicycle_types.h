/*
 * rs_bicycle_types.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "rs_bicycle".
 *
 * Model version              : 1.71
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 * C source code generated on : Wed Oct 30 16:52:37 2019
 *
 * Target selection: rsim.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_rs_bicycle_types_h_
#define RTW_HEADER_rs_bicycle_types_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#ifndef typedef_e_dsp_private_SlidingWindowMa_T
#define typedef_e_dsp_private_SlidingWindowMa_T

typedef struct {
  int32_T isInitialized;
  boolean_T isSetupComplete;
  real_T pBuffer[200];
  int32_T pBufferIdx[200];
  int32_T pNumElements;
  int32_T pCount;
  int32_T pTop;
} e_dsp_private_SlidingWindowMa_T;

#endif                               /*typedef_e_dsp_private_SlidingWindowMa_T*/

#ifndef typedef_c_cell_wrap_rs_bicycle_T
#define typedef_c_cell_wrap_rs_bicycle_T

typedef struct {
  uint32_T f1[8];
} c_cell_wrap_rs_bicycle_T;

#endif                                 /*typedef_c_cell_wrap_rs_bicycle_T*/

#ifndef typedef_dsp_MovingMaximum_rs_bicycle_T
#define typedef_dsp_MovingMaximum_rs_bicycle_T

typedef struct {
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  c_cell_wrap_rs_bicycle_T inputVarSize;
  int32_T NumChannels;
  e_dsp_private_SlidingWindowMa_T *pStat;
} dsp_MovingMaximum_rs_bicycle_T;

#endif                                /*typedef_dsp_MovingMaximum_rs_bicycle_T*/

#ifndef typedef_e_dsp_private_SlidingWindowMi_T
#define typedef_e_dsp_private_SlidingWindowMi_T

typedef struct {
  int32_T isInitialized;
  boolean_T isSetupComplete;
  real_T pBuffer[500];
  int32_T pBufferIdx[500];
  int32_T pNumElements;
  int32_T pCount;
  int32_T pTop;
} e_dsp_private_SlidingWindowMi_T;

#endif                               /*typedef_e_dsp_private_SlidingWindowMi_T*/

#ifndef typedef_e_dsp_private_SlidingWindow_o_T
#define typedef_e_dsp_private_SlidingWindow_o_T

typedef struct {
  int32_T isInitialized;
  boolean_T isSetupComplete;
  real_T pBuffer[4];
  int32_T pBufferIdx[4];
  int32_T pNumElements;
  int32_T pCount;
  int32_T pTop;
} e_dsp_private_SlidingWindow_o_T;

#endif                               /*typedef_e_dsp_private_SlidingWindow_o_T*/

#ifndef typedef_dsp_MovingMinimum_rs_bicycle_T
#define typedef_dsp_MovingMinimum_rs_bicycle_T

typedef struct {
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  c_cell_wrap_rs_bicycle_T inputVarSize;
  int32_T NumChannels;
  e_dsp_private_SlidingWindowMi_T *pStat;
} dsp_MovingMinimum_rs_bicycle_T;

#endif                                /*typedef_dsp_MovingMinimum_rs_bicycle_T*/

#ifndef typedef_dsp_MovingMaximum_rs_bicycl_o_T
#define typedef_dsp_MovingMaximum_rs_bicycl_o_T

typedef struct {
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  c_cell_wrap_rs_bicycle_T inputVarSize;
  int32_T NumChannels;
  e_dsp_private_SlidingWindow_o_T *pStat;
} dsp_MovingMaximum_rs_bicycl_o_T;

#endif                               /*typedef_dsp_MovingMaximum_rs_bicycl_o_T*/

/* Parameters (default storage) */
typedef struct P_ P;

#endif                                 /* RTW_HEADER_rs_bicycle_types_h_ */
