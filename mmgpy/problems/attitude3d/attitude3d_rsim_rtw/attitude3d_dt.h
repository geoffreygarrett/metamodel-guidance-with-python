/*
 * attitude3d_dt.h
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
  sizeof(struct_nois8vFfP57DutoSgf9HZD),
  sizeof(struct_rawc2dqRCLbbSQv98WCoDC),
  sizeof(struct_qj1aZXRxDpRc9BsHnZQAtC),
  sizeof(ENVIRONMENT),
  sizeof(dsp_MovingMinimum_attitude3d_T),
  sizeof(dsp_private_RunningMinimum_at_T),
  sizeof(dsp_MovingMaximum_attitude3d_T),
  sizeof(dsp_private_RunningMaximum_at_T)
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
  "struct_nois8vFfP57DutoSgf9HZD",
  "struct_rawc2dqRCLbbSQv98WCoDC",
  "struct_qj1aZXRxDpRc9BsHnZQAtC",
  "ENVIRONMENT",
  "dsp_MovingMinimum_attitude3d_T",
  "dsp_private_RunningMinimum_at_T",
  "dsp_MovingMaximum_attitude3d_T",
  "dsp_private_RunningMaximum_at_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&rtB.E), 17, 0, 1 },

  { (char_T *)(&rtB.Gain1[0]), 0, 0, 73 },

  { (char_T *)(&rtB.Compare), 8, 0, 1 },

  { (char_T *)(&rtB.MovingMaximum_p.MovingMaximum), 0, 0, 1 },

  { (char_T *)(&rtB.MovingMaximum.MovingMaximum), 0, 0, 1 },

  { (char_T *)(&rtB.MovingMinimum_p.MovingMinimum), 0, 0, 1 },

  { (char_T *)(&rtB.MovingMinimum.MovingMinimum), 0, 0, 1 }
  ,

  { (char_T *)(&rtDW.DiscreteFIRFilter_states[0]), 0, 0, 118 },

  { (char_T *)(&rtDW.Scope_PWORK.LoggedData), 11, 0, 43 },

  { (char_T *)(&rtDW.Integrator_IWORK), 10, 0, 1 },

  { (char_T *)(&rtDW.MovingMaximum_p.obj), 20, 0, 1 },

  { (char_T *)(&rtDW.MovingMaximum_p.gobj_0), 21, 0, 2 },

  { (char_T *)(&rtDW.MovingMaximum_p.objisempty), 8, 0, 1 },

  { (char_T *)(&rtDW.MovingMaximum.obj), 20, 0, 1 },

  { (char_T *)(&rtDW.MovingMaximum.gobj_0), 21, 0, 2 },

  { (char_T *)(&rtDW.MovingMaximum.objisempty), 8, 0, 1 },

  { (char_T *)(&rtDW.MovingMinimum_p.obj), 18, 0, 1 },

  { (char_T *)(&rtDW.MovingMinimum_p.gobj_0), 19, 0, 2 },

  { (char_T *)(&rtDW.MovingMinimum_p.objisempty), 8, 0, 1 },

  { (char_T *)(&rtDW.MovingMinimum.obj), 18, 0, 1 },

  { (char_T *)(&rtDW.MovingMinimum.gobj_0), 19, 0, 2 },

  { (char_T *)(&rtDW.MovingMinimum.objisempty), 8, 0, 1 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  22U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&rtP.P_E), 16, 0, 1 },

  { (char_T *)(&rtP.P_F), 14, 0, 1 },

  { (char_T *)(&rtP.P_X), 15, 0, 1 },

  { (char_T *)(&rtP.NormalizeVector_maxzero), 0, 0, 212 },

  { (char_T *)(&rtP.ManualSwitch1_CurrentSetting), 3, 0, 2 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  5U,
  rtPTransitions
};

/* [EOF] attitude3d_dt.h */
