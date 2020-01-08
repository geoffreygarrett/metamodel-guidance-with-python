/*
 * attitude3d_data.c
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

#include "attitude3d.h"
#include "attitude3d_private.h"

/* Block parameters (default storage) */
P rtP = {
  /* Variable: P
   * Referenced by: '<S3>/Constant'
   */
  6529.2760716943494,

  /* Variable: antenna_vb
   * Referenced by: '<Root>/Constant3'
   */
  { 1.0, 0.0, 0.0 },

  /* Variable: init_xBI
   * Referenced by: '<Root>/Constant4'
   */
  { 1.0, 0.0, 0.0 },

  /* Variable: init_yBI
   * Referenced by: '<Root>/Constant5'
   */
  { 0.0, 1.0, 0.0 },

  /* Variable: init_zBI
   * Referenced by: '<Root>/Constant6'
   */
  { 0.0, 0.0, 1.0 },

  /* Variable: solar_array_vb
   * Referenced by: '<Root>/Constant7'
   */
  { 1.0, 0.0, 0.0 },

  /* Variable: star_sensor_1_vb
   * Referenced by: '<Root>/Constant'
   */
  { 0.70710678118654746, 0.70710678118654746, 0.0 },

  /* Variable: star_sensor_2_vb
   * Referenced by: '<Root>/Constant1'
   */
  { 0.70710678118654746, -0.70710678118654746, 0.0 },

  /* Variable: thrust_no_shadow_weight
   * Referenced by: '<S8>/Constant12'
   */
  1.0,

  /* Variable: thrust_shadow_weight
   * Referenced by: '<S8>/Constant10'
   */
  1.0,

  /* Variable: thruster_vb
   * Referenced by: '<Root>/Constant2'
   */
  { -1.0, 0.0, 0.0 },

  /* Variable: x_test
   * Referenced by: '<Root>/Test Design'
   */
  { 0.0, 3264.6380358471747, 6529.2760716943494, 0.00096230964017870015,
    0.00096230964017870015, 0.00096230964017870015, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0
  },

  /* Mask Parameter: NormalizeVector_maxzero
   * Referenced by: '<S23>/Switch'
   */
  0.0,

  /* Mask Parameter: NormalizeVector1_maxzero
   * Referenced by: '<S24>/Switch'
   */
  0.0,

  /* Mask Parameter: NormalizeVector_maxzero_m
   * Referenced by: '<S25>/Switch'
   */
  0.0,

  /* Mask Parameter: NormalizeVector1_maxzero_i
   * Referenced by: '<S26>/Switch'
   */
  0.0,

  /* Mask Parameter: NormalizeVector_maxzero_o
   * Referenced by: '<S27>/Switch'
   */
  0.0,

  /* Mask Parameter: NormalizeVector1_maxzero_c
   * Referenced by: '<S28>/Switch'
   */
  0.0,

  /* Mask Parameter: NormalizeVector_maxzero_f
   * Referenced by: '<S31>/Switch'
   */
  0.0,

  /* Mask Parameter: NormalizeVector1_maxzero_c1
   * Referenced by: '<S32>/Switch'
   */
  0.0,

  /* Mask Parameter: NormalizeVector_maxzero_p
   * Referenced by: '<S34>/Switch'
   */
  0.0,

  /* Mask Parameter: NormalizeVector1_maxzero_d
   * Referenced by: '<S35>/Switch'
   */
  0.0,

  /* Mask Parameter: NormalizeVector_maxzero_j
   * Referenced by: '<S37>/Switch'
   */
  0.0,

  /* Mask Parameter: NormalizeVector1_maxzero_g
   * Referenced by: '<S38>/Switch'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S29>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S30>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S33>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S36>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S20>/Constant'
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

  /* Expression: 0
   * Referenced by: '<S11>/Discrete FIR Filter'
   */
  0.0,

  /* Expression: ones(1,integperiod)
   * Referenced by: '<S11>/Discrete FIR Filter'
   */
  { 1.0, 1.0, 1.0, 1.0 },

  /* Expression: 1
   * Referenced by: '<S9>/Constant'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S9>/Integrator1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S12>/Discrete FIR Filter'
   */
  0.0,

  /* Expression: ones(1,integperiod)
   * Referenced by: '<S12>/Discrete FIR Filter'
   */
  { 1.0, 1.0, 1.0, 1.0, 1.0, 1.0 },

  /* Expression: [1 -1 -1 -1]
   * Referenced by: '<S19>/Gain1'
   */
  { 1.0, -1.0, -1.0, -1.0 },

  /* Expression: [1 -1 -1 -1]
   * Referenced by: '<S61>/Gain1'
   */
  { 1.0, -1.0, -1.0, -1.0 },

  /* Expression: 1
   * Referenced by: '<S17>/Constant'
   */
  1.0,

  /* Expression: [1 -1 -1 -1]
   * Referenced by: '<S56>/Gain1'
   */
  { 1.0, -1.0, -1.0, -1.0 },

  /* Expression: 1
   * Referenced by: '<S16>/Constant'
   */
  1.0,

  /* Expression: [1 -1 -1 -1]
   * Referenced by: '<S51>/Gain1'
   */
  { 1.0, -1.0, -1.0, -1.0 },

  /* Expression: 1
   * Referenced by: '<S15>/Constant'
   */
  1.0,

  /* Expression: [1 -1 -1 -1]
   * Referenced by: '<S46>/Gain1'
   */
  { 1.0, -1.0, -1.0, -1.0 },

  /* Expression: 1
   * Referenced by: '<S14>/Constant'
   */
  1.0,

  /* Expression: [1 -1 -1 -1]
   * Referenced by: '<S41>/Gain1'
   */
  { 1.0, -1.0, -1.0, -1.0 },

  /* Expression: 1
   * Referenced by: '<S13>/Constant'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S23>/Constant'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S24>/Constant'
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
   * Referenced by: '<S25>/Constant'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S26>/Constant'
   */
  1.0,

  /* Expression: 1.0
   * Referenced by: '<S6>/Saturation'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S6>/Saturation'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S27>/Constant'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S28>/Constant'
   */
  1.0,

  /* Expression: 1.0
   * Referenced by: '<S7>/Saturation'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S7>/Saturation'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S8>/Constant9'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S8>/Integrator2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S8>/Integrator1'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S31>/Constant'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S32>/Constant'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S8>/Constant11'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S34>/Constant'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S35>/Constant'
   */
  1.0,

  /* Expression: 1.0
   * Referenced by: '<S9>/Saturation'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S9>/Saturation'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S9>/Constant11'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S37>/Constant'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S38>/Constant'
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

  /* Computed Parameter: ManualSwitch1_CurrentSetting
   * Referenced by: '<S8>/Manual Switch1'
   */
  1U,

  /* Computed Parameter: ManualSwitch1_CurrentSetting_k
   * Referenced by: '<S9>/Manual Switch1'
   */
  1U,

  /* Computed Parameter: ManualSwitch1_CurrentSetting_g
   * Referenced by: '<S10>/Manual Switch1'
   */
  1U
};
