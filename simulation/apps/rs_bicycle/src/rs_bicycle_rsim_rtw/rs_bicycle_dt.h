/*
 * rs_bicycle_dt.h
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

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T),
  sizeof(dsp_MovingMaximum_rs_bicycle_T),
  sizeof(e_dsp_private_SlidingWindowMa_T),
  sizeof(dsp_MovingMinimum_rs_bicycle_T),
  sizeof(e_dsp_private_SlidingWindowMi_T),
  sizeof(dsp_MovingMaximum_rs_bicycl_o_T),
  sizeof(e_dsp_private_SlidingWindow_o_T)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T",
  "dsp_MovingMaximum_rs_bicycle_T",
  "e_dsp_private_SlidingWindowMa_T",
  "dsp_MovingMinimum_rs_bicycle_T",
  "e_dsp_private_SlidingWindowMi_T",
  "dsp_MovingMaximum_rs_bicycl_o_T",
  "e_dsp_private_SlidingWindow_o_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&rtB.init_position), 0, 0, 58 },

  { (char_T *)(&rtB.RelationalOperator[0]), 8, 0, 18 },

  { (char_T *)(&rtB.MovingMaximum.f9_v3_max), 0, 0, 1 },

  { (char_T *)(&rtB.MovingMaximum2.f9_v3_max), 0, 0, 1 },

  { (char_T *)(&rtB.MovingMaximum1.f9_v3_max), 0, 0, 1 },

  { (char_T *)(&rtB.MovingMaximum3.f9_v3_max), 0, 0, 1 }
  ,

  { (char_T *)(&rtDW.gobj_0), 17, 0, 2 },

  { (char_T *)(&rtDW.gobj_0_h), 19, 0, 2 },

  { (char_T *)(&rtDW.obj), 16, 0, 1 },

  { (char_T *)(&rtDW.obj_g), 18, 0, 1 },

  { (char_T *)(&rtDW.UD_DSTATE), 0, 0, 1 },

  { (char_T *)(&rtDW.AuxilliaryScope_PWORK.LoggedData[0]), 11, 0, 26 },

  { (char_T *)(&rtDW.Integrator_IWORK), 10, 0, 1 },

  { (char_T *)(&rtDW.objisempty), 8, 0, 2 },

  { (char_T *)(&rtDW.MovingMaximum.gobj_0), 15, 0, 2 },

  { (char_T *)(&rtDW.MovingMaximum.obj), 14, 0, 1 },

  { (char_T *)(&rtDW.MovingMaximum.objisempty), 8, 0, 1 },

  { (char_T *)(&rtDW.MovingMaximum2.gobj_0), 15, 0, 2 },

  { (char_T *)(&rtDW.MovingMaximum2.obj), 14, 0, 1 },

  { (char_T *)(&rtDW.MovingMaximum2.objisempty), 8, 0, 1 },

  { (char_T *)(&rtDW.MovingMaximum1.gobj_0), 15, 0, 2 },

  { (char_T *)(&rtDW.MovingMaximum1.obj), 14, 0, 1 },

  { (char_T *)(&rtDW.MovingMaximum1.objisempty), 8, 0, 1 },

  { (char_T *)(&rtDW.MovingMaximum3.gobj_0), 15, 0, 2 },

  { (char_T *)(&rtDW.MovingMaximum3.obj), 14, 0, 1 },

  { (char_T *)(&rtDW.MovingMaximum3.objisempty), 8, 0, 1 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  26U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&rtP.env_forest[0]), 0, 0, 37 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  1U,
  rtPTransitions
};

/* [EOF] rs_bicycle_dt.h */
