/*
 * rs_bicycle_private.h
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

#ifndef RTW_HEADER_rs_bicycle_private_h_
#define RTW_HEADER_rs_bicycle_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "rs_bicycle.h"
#if !defined(rt_VALIDATE_MEMORY)
#define rt_VALIDATE_MEMORY(S, ptr)     if(!(ptr)) {\
 ssSetErrorStatus(rtS, RT_MEMORY_ALLOCATION_ERROR);\
 }
#endif

#if !defined(rt_FREE)
#if !defined(_WIN32)
#define rt_FREE(ptr)                   if((ptr) != (NULL)) {\
 free((ptr));\
 (ptr) = (NULL);\
 }
#else

/* Visual and other windows compilers declare free without const */
#define rt_FREE(ptr)                   if((ptr) != (NULL)) {\
 free((void *)(ptr));\
 (ptr) = (NULL);\
 }
#endif
#endif

extern real_T rt_powd_snf(real_T u0, real_T u1);
extern void rs_bicycle_MovingMaximum3_Init(DW_MovingMaximum3_rs_bicycle_T
  *localDW);
extern void rs_bicycle_MovingMaximum3_Start(DW_MovingMaximum3_rs_bicycle_T
  *localDW);
extern void rs_bicycle_MovingMaximum3(real_T rtu_0,
  B_MovingMaximum3_rs_bicycle_T *localB, DW_MovingMaximum3_rs_bicycle_T *localDW);
extern void rs_bicycle_MovingMaximum3_Term(DW_MovingMaximum3_rs_bicycle_T
  *localDW);

#if defined(MULTITASKING)
#  error Model (rs_bicycle) was built in \
SingleTasking solver mode, however the MULTITASKING define is \
present. If you have multitasking (e.g. -DMT or -DMULTITASKING) \
defined on the Code Generation page of Simulation parameter dialog, please \
remove it and on the Solver page, select solver mode \
MultiTasking. If the Simulation parameter dialog is configured \
correctly, please verify that your template makefile is \
configured correctly.
#endif
#endif                                 /* RTW_HEADER_rs_bicycle_private_h_ */
