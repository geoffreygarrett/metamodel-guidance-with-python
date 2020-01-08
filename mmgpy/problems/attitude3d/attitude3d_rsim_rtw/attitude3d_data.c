/*
 * attitude3d_data.c
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

#include "attitude3d.h"
#include "attitude3d_private.h"

/* Block parameters (default storage) */
P rtP = {
  /* Variable: P_E
   * Referenced by:
   *   '<Root>/Constant8'
   *   '<Root>/Constant9'
   *   '<S2>/Constant'
   */
  {
    1.327124e+20,
    42828370000000.0,
    228000000000.0,
    3389500.0,
    200000.0,
    3589500.0,
    0.00096230964017870015,
    6529.2760716943494,
    149598023000.0,

    { 3589500.0, 0.0, 0.0, 0.0, 0.0, 4.71238898038469, 42828370000000.0 },

    { 228000000000.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.327124e+20 },

    { 149598023000.0, 0.0, 0.0, 0.0, 0.0, 1.5707963267948966, 1.327124e+20 }
  },

  /* Variable: P_F
   * Referenced by:
   *   '<Root>/Constant'
   *   '<Root>/Constant1'
   *   '<Root>/Constant2'
   *   '<Root>/Constant3'
   *   '<Root>/Constant4'
   *   '<S6>/Constant12'
   *   '<S7>/Constant12'
   */
  {
    { 0.70710678118654746, 0.70710678118654746, 0.0 },

    { 0.70710678118654746, -0.70710678118654746, 0.0 },

    { -1.0, 0.0, 0.0 },

    { 1.0, 0.0, 0.0 },

    { 0.0, 1.0, 0.0 },
    1.0,
    1.0,
    600.0,
    60
  },

  /* Variable: P_X
   * Referenced by:
   *   '<Root>/Constant5'
   *   '<Root>/Constant6'
   *   '<Root>/Constant7'
   */
  {
    { 0.009623096401787, 0.009623096401787, 0.009623096401787 },

    { 3454.2104534214441, -6.3452816630458479e-13, 0.0 },

    { -6.5938045283091366e-10, -3589500.0, 0.0 },

    { 1.0, -1.8369701987210297e-16, 0.0 },

    { 1.83697019872103e-16, 1.0, -0.0 },

    { 0.0, 0.0, 1.0 }
  },

  /* Mask Parameter: NormalizeVector_maxzero
   * Referenced by: '<S20>/Switch'
   */
  0.0,

  /* Mask Parameter: NormalizeVector1_maxzero
   * Referenced by: '<S21>/Switch'
   */
  0.0,

  /* Mask Parameter: NormalizeVector_maxzero_m
   * Referenced by: '<S22>/Switch'
   */
  0.0,

  /* Mask Parameter: NormalizeVector1_maxzero_i
   * Referenced by: '<S23>/Switch'
   */
  0.0,

  /* Mask Parameter: NormalizeVector_maxzero_o
   * Referenced by: '<S24>/Switch'
   */
  0.0,

  /* Mask Parameter: NormalizeVector1_maxzero_c
   * Referenced by: '<S25>/Switch'
   */
  0.0,

  /* Mask Parameter: NormalizeVector_maxzero_e
   * Referenced by: '<S27>/Switch'
   */
  0.0,

  /* Mask Parameter: NormalizeVector1_maxzero_e
   * Referenced by: '<S28>/Switch'
   */
  0.0,

  /* Mask Parameter: NormalizeVector_maxzero_f
   * Referenced by: '<S61>/Switch'
   */
  0.0,

  /* Mask Parameter: NormalizeVector1_maxzero_c1
   * Referenced by: '<S62>/Switch'
   */
  0.0,

  /* Mask Parameter: NormalizeVector_maxzero_p
   * Referenced by: '<S64>/Switch'
   */
  0.0,

  /* Mask Parameter: NormalizeVector1_maxzero_d
   * Referenced by: '<S65>/Switch'
   */
  0.0,

  /* Mask Parameter: NormalizeVector_maxzero_j
   * Referenced by: '<S67>/Switch'
   */
  0.0,

  /* Mask Parameter: NormalizeVector1_maxzero_g
   * Referenced by: '<S68>/Switch'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S60>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S63>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S66>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S15>/Constant'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S20>/Constant'
   */
  1.0,

  /* Expression: [1 -1 -1 -1]
   * Referenced by: '<S14>/Gain1'
   */
  { 1.0, -1.0, -1.0, -1.0 },

  /* Expression: [1 -1 -1 -1]
   * Referenced by: '<S13>/Gain1'
   */
  { 1.0, -1.0, -1.0, -1.0 },

  /* Expression: [1 -1 -1 -1]
   * Referenced by: '<S37>/Gain1'
   */
  { 1.0, -1.0, -1.0, -1.0 },

  /* Expression: 1
   * Referenced by: '<S30>/Constant'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S21>/Constant'
   */
  1.0,

  /* Expression: 1.0
   * Referenced by: '<S4>/Saturation'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S4>/Saturation'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S22>/Constant'
   */
  1.0,

  /* Expression: [1 -1 -1 -1]
   * Referenced by: '<S42>/Gain1'
   */
  { 1.0, -1.0, -1.0, -1.0 },

  /* Expression: 1
   * Referenced by: '<S31>/Constant'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S23>/Constant'
   */
  1.0,

  /* Expression: 1.0
   * Referenced by: '<S5>/Saturation'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S5>/Saturation'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S6>/Constant10'
   */
  1.0,

  /* Expression: -1
   * Referenced by: '<S6>/Gain1'
   */
  -1.0,

  /* Expression: 1
   * Referenced by: '<S24>/Constant'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S25>/Constant'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S6>/Constant11'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S26>/Discrete FIR Filter'
   */
  0.0,

  /* Expression: ones(1,integperiod)
   * Referenced by: '<S26>/Discrete FIR Filter'
   */
  { 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0 },

  /* Expression: 1
   * Referenced by: '<S7>/Constant10'
   */
  1.0,

  /* Expression: -1
   * Referenced by: '<S7>/Gain1'
   */
  -1.0,

  /* Expression: 1
   * Referenced by: '<S27>/Constant'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S28>/Constant'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S7>/Constant11'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S29>/Discrete FIR Filter'
   */
  0.0,

  /* Expression: ones(1,integperiod)
   * Referenced by: '<S29>/Discrete FIR Filter'
   */
  { 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0 },

  /* Expression: 1
   * Referenced by: '<S11>/Constant'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S11>/Integrator1'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S10>/Constant'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S10>/Integrator1'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S9>/Constant9'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S9>/Integrator2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S9>/Integrator1'
   */
  0.0,

  /* Expression: [1 -1 -1 -1]
   * Referenced by: '<S57>/Gain1'
   */
  { 1.0, -1.0, -1.0, -1.0 },

  /* Expression: 1
   * Referenced by: '<S34>/Constant'
   */
  1.0,

  /* Expression: [1 -1 -1 -1]
   * Referenced by: '<S52>/Gain1'
   */
  { 1.0, -1.0, -1.0, -1.0 },

  /* Expression: 1
   * Referenced by: '<S33>/Constant'
   */
  1.0,

  /* Expression: [1 -1 -1 -1]
   * Referenced by: '<S47>/Gain1'
   */
  { 1.0, -1.0, -1.0, -1.0 },

  /* Expression: 1
   * Referenced by: '<S32>/Constant'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S17>/Constant'
   */
  0.0,

  /* Expression: 1/2
   * Referenced by: '<S17>/Gain'
   */
  0.5,

  /* Expression: 1
   * Referenced by: '<S61>/Constant'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S62>/Constant'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S9>/Constant11'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S64>/Constant'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S65>/Constant'
   */
  1.0,

  /* Expression: 1.0
   * Referenced by: '<S10>/Saturation'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S10>/Saturation'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S10>/Constant11'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S67>/Constant'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S68>/Constant'
   */
  1.0,

  /* Expression: 1.0
   * Referenced by: '<S11>/Saturation'
   */
  1.0,

  /* Expression: -1.0
   * Referenced by: '<S11>/Saturation'
   */
  -1.0,

  /* Computed Parameter: ManualSwitch1_CurrentSetting
   * Referenced by: '<S9>/Manual Switch1'
   */
  1U,

  /* Computed Parameter: ManualSwitch1_CurrentSetting_k
   * Referenced by: '<S10>/Manual Switch1'
   */
  1U
};
