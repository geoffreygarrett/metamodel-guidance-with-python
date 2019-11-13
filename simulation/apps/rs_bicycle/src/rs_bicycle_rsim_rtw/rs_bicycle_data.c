/*
 * rs_bicycle_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "rs_bicycle".
 *
 * Model version              : 1.71
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 * C source code generated on : Thu Oct 31 17:14:02 2019
 *
 * Target selection: rsim.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objective: Execution efficiency
 * Validation result: Not run
 */

#include "rs_bicycle.h"
#include "rs_bicycle_private.h"

/* Block parameters (default storage) */
P rtP = {
  /* Variable: env_forest
   * Referenced by: '<Root>/Constant7'
   */
  { 0.4, 0.6 },

  /* Variable: env_mu_s_dry
   * Referenced by: '<Root>/Constant9'
   */
  0.7,

  /* Variable: env_mu_s_wet
   * Referenced by: '<Root>/Constant10'
   */
  0.4,

  /* Variable: env_route_length
   * Referenced by:
   *   '<Root>/Constant4'
   *   '<S11>/Constant1'
   */
  1000.0,

  /* Variable: env_t_rain_start
   * Referenced by: '<Root>/Constant8'
   */
  100.0,

  /* Variable: env_traffic_durations
   * Referenced by: '<Root>/Constant1'
   */
  { 10.0, 20.0 },

  /* Variable: env_traffic_pos
   * Referenced by: '<Root>/Constant5'
   */
  { 0.25, 0.75 },

  /* Variable: env_traffic_times
   * Referenced by: '<Root>/Constant6'
   */
  { 45.0, 135.0 },

  /* Variable: g
   * Referenced by:
   *   '<S12>/gravity'
   *   '<S14>/gravity'
   */
  9.81,

  /* Variable: init_position
   * Referenced by: '<Root>/Initial Position'
   */
  0.0,

  /* Mask Parameter: Difference_ICPrevInput
   * Referenced by: '<S2>/UD'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S10>/Integrator'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S10>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S10>/Switch'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S8>/Constant'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S8>/no1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S11>/Switch2'
   */
  0.0,

  /* Expression: 0.5
   * Referenced by: '<S12>/reaction_time'
   */
  0.5,

  /* Expression: 0
   * Referenced by: '<S1>/Switch'
   */
  0.0,

  /* Expression: 2
   * Referenced by: '<S12>/Gain'
   */
  2.0,

  /* Expression: 0
   * Referenced by: '<S13>/Constant1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S13>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S13>/Constant3'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S13>/Constant2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S13>/Constant4'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Integrator1'
   */
  0.0,

  /* Expression: 3
   * Referenced by: '<S16>/Constant'
   */
  3.0,

  /* Expression: 0
   * Referenced by: '<Root>/Integrator2'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S4>/yes'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S4>/no'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S4>/Switch1'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S17>/Constant'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S17>/no'
   */
  0.0
};
