/*
 * rs_bicycle.c
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

#include <math.h>
#include "rs_bicycle.h"
#include "rs_bicycle_private.h"
#include "rs_bicycle_dt.h"

/* user code (top of parameter file) */
const int_T gblNumToFiles = 0;
const int_T gblNumFrFiles = 0;
const int_T gblNumFrWksBlocks = 0;
const char *gblSlvrJacPatternFileName =
  "rs_bicycle_rsim_rtw//rs_bicycle_Jpattern.mat";

/* Root inports information  */
const int_T gblNumRootInportBlks = 1;
const int_T gblNumModelInputs = 1;
extern rtInportTUtable *gblInportTUtables;
extern const char *gblInportFileName;
const int_T gblInportDataTypeIdx[] = { 0 };

const int_T gblInportDims[] = { 1, 1 } ;

const int_T gblInportComplex[] = { 0 };

const int_T gblInportInterpoFlag[] = { 1 };

const int_T gblInportContinuous[] = { 1 };

#include "simstruc.h"
#include "fixedpoint.h"

/* Block signals (default storage) */
B rtB;

/* Continuous states */
X rtX;

/* Block states (default storage) */
DW rtDW;

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Parent Simstruct */
static SimStruct model_S;
SimStruct *const rtS = &model_S;

/* Forward declaration for local functions */
static void rs_bicycle_SystemCore_release(dsp_MovingMaximum_rs_bicycle_T *obj);
static void rs_bicycle_SystemCore_delete(dsp_MovingMaximum_rs_bicycle_T *obj);
static void matlabCodegenHandle_matlabCodeg(dsp_MovingMaximum_rs_bicycle_T *obj);

/* Forward declaration for local functions */
static real_T AbstractSlidingWindowMinMaxCG_s(e_dsp_private_SlidingWindowMi_T
  *obj, real_T x);
static void rs_bicycl_SystemCore_release_or(dsp_MovingMaximum_rs_bicycl_o_T *obj);
static void rs_bicycle_SystemCore_delete_or(dsp_MovingMaximum_rs_bicycl_o_T *obj);
static void matlabCodegenHandle_matlabCo_or(dsp_MovingMaximum_rs_bicycl_o_T *obj);
static void rs_bicycle_SystemCore_release_o(dsp_MovingMinimum_rs_bicycle_T *obj);
static void rs_bicycle_SystemCore_delete_o(dsp_MovingMinimum_rs_bicycle_T *obj);
static void matlabCodegenHandle_matlabCod_o(dsp_MovingMinimum_rs_bicycle_T *obj);
static void rs_bicycle_SystemCore_release(dsp_MovingMaximum_rs_bicycle_T *obj)
{
  dsp_MovingMaximum_rs_bicycle_T *obj_0;
  e_dsp_private_SlidingWindowMa_T *obj_1;
  if (obj->isInitialized == 1) {
    obj_0 = obj;
    if (obj_0->isSetupComplete) {
      obj_0->NumChannels = -1;
      obj_1 = obj_0->pStat;
      if (obj_1->isInitialized == 1) {
        obj_1->isInitialized = 2;
      }
    }
  }
}

static void rs_bicycle_SystemCore_delete(dsp_MovingMaximum_rs_bicycle_T *obj)
{
  rs_bicycle_SystemCore_release(obj);
}

static void matlabCodegenHandle_matlabCodeg(dsp_MovingMaximum_rs_bicycle_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    rs_bicycle_SystemCore_delete(obj);
  }
}

/*
 * System initialize for atomic system:
 *    synthesized block
 *    synthesized block
 *    synthesized block
 *    synthesized block
 */
void rs_bicycle_MovingMaximum3_Init(DW_MovingMaximum3_rs_bicycle_T *localDW)
{
  dsp_MovingMaximum_rs_bicycle_T *obj;
  e_dsp_private_SlidingWindowMa_T *obj_0;
  int32_T i;

  /* InitializeConditions for MATLABSystem: '<Root>/Moving Maximum3' */
  obj = &localDW->obj;
  obj_0 = obj->pStat;
  if (obj_0->isInitialized == 1) {
    for (i = 0; i < 200; i++) {
      obj_0->pBuffer[i] = 0.0;
    }

    for (i = 0; i < 200; i++) {
      obj_0->pBufferIdx[i] = 0;
    }

    obj_0->pNumElements = 0;
    obj_0->pCount = 1;
    obj_0->pTop = 1;
  }

  /* End of InitializeConditions for MATLABSystem: '<Root>/Moving Maximum3' */
}

/*
 * Start for atomic system:
 *    synthesized block
 *    synthesized block
 *    synthesized block
 *    synthesized block
 */
void rs_bicycle_MovingMaximum3_Start(DW_MovingMaximum3_rs_bicycle_T *localDW)
{
  e_dsp_private_SlidingWindowMa_T *iobj_0;
  dsp_MovingMaximum_rs_bicycle_T *b_obj;
  dsp_MovingMaximum_rs_bicycle_T *obj;

  /* Start for MATLABSystem: '<Root>/Moving Maximum3' */
  localDW->obj.matlabCodegenIsDeleted = true;
  iobj_0 = &localDW->gobj_0;
  b_obj = &localDW->obj;
  b_obj->isInitialized = 0;
  b_obj->NumChannels = -1;
  b_obj->matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  b_obj = &localDW->obj;
  b_obj->isSetupComplete = false;
  b_obj->isInitialized = 1;
  obj = b_obj;
  obj->NumChannels = 1;
  iobj_0->isInitialized = 0;
  obj->pStat = iobj_0;
  iobj_0 = obj->pStat;
  iobj_0->isSetupComplete = false;
  iobj_0->isInitialized = 1;
  iobj_0->isSetupComplete = true;
  b_obj->isSetupComplete = true;
}

/*
 * Output and update for atomic system:
 *    synthesized block
 *    synthesized block
 *    synthesized block
 *    synthesized block
 */
void rs_bicycle_MovingMaximum3(real_T rtu_0, B_MovingMaximum3_rs_bicycle_T
  *localB, DW_MovingMaximum3_rs_bicycle_T *localDW)
{
  dsp_MovingMaximum_rs_bicycle_T *obj;
  e_dsp_private_SlidingWindowMa_T *obj_0;
  e_dsp_private_SlidingWindowMa_T *obj_1;
  real_T buf[200];
  int32_T bufIdx[200];
  int32_T numElements;
  int32_T cnt;
  int32_T top;
  int32_T winLen;
  int32_T placement;
  int32_T ind_vect[200];
  int32_T N;
  int32_T count;
  int32_T indVal;
  boolean_T cond;
  int32_T b_ind;
  e_dsp_private_SlidingWindowMa_T *obj_2;
  real_T y;
  int32_T i;
  boolean_T exitg1;

  /* MATLABSystem: '<Root>/Moving Maximum3' */
  obj = &localDW->obj;
  obj_0 = obj->pStat;
  if (obj_0->isInitialized != 1) {
    obj_1 = obj_0;
    obj_2 = obj_1;
    obj_2->isSetupComplete = false;
    obj_2->isInitialized = 1;
    obj_2->isSetupComplete = true;
    for (i = 0; i < 200; i++) {
      obj_1->pBuffer[i] = 0.0;
    }

    for (i = 0; i < 200; i++) {
      obj_1->pBufferIdx[i] = 0;
    }

    obj_1->pNumElements = 0;
    obj_1->pCount = 1;
    obj_1->pTop = 1;
  }

  for (i = 0; i < 200; i++) {
    buf[i] = obj_0->pBuffer[i];
  }

  for (i = 0; i < 200; i++) {
    bufIdx[i] = obj_0->pBufferIdx[i];
  }

  numElements = obj_0->pNumElements;
  cnt = obj_0->pCount;
  top = obj_0->pTop;
  if (numElements > 0) {
    i = bufIdx[top - 1];
    if ((cnt >= 0) && (i < cnt - MAX_int32_T)) {
      i = MAX_int32_T;
    } else if ((cnt < 0) && (i > cnt - MIN_int32_T)) {
      i = MIN_int32_T;
    } else {
      i = cnt - i;
    }

    if (i == 200) {
      if (top > 2147483646) {
        top = MAX_int32_T;
      } else {
        top++;
      }

      if (top > 200) {
        top = 1;
      }

      numElements--;
    }
  }

  if ((numElements < 0) && (top < MIN_int32_T - numElements)) {
    i = MIN_int32_T;
  } else if ((numElements > 0) && (top > MAX_int32_T - numElements)) {
    i = MAX_int32_T;
  } else {
    i = numElements + top;
  }

  if (i < -2147483647) {
    placement = MIN_int32_T;
  } else {
    placement = i - 1;
  }

  if (placement >= 200) {
    placement -= 200;
  }

  i = placement + 1;
  placement = i - 1;
  memset(&ind_vect[0], 0, 200U * sizeof(int32_T));
  N = numElements;
  if (numElements > 0) {
    count = 1;
    i = numElements - 1;
    if (i >= 0) {
      if (top < -2147483647) {
        winLen = MIN_int32_T;
      } else {
        winLen = top - 1;
      }
    }

    for (b_ind = i; b_ind >= 0; b_ind--) {
      if ((winLen < 0) && (b_ind < MIN_int32_T - winLen)) {
        indVal = MIN_int32_T;
      } else if ((winLen > 0) && (b_ind > MAX_int32_T - winLen)) {
        indVal = MAX_int32_T;
      } else {
        indVal = winLen + b_ind;
      }

      if (indVal >= 200) {
        indVal -= 200;
      }

      indVal++;
      ind_vect[count - 1] = indVal;
      if (count > 2147483646) {
        count = MAX_int32_T;
      } else {
        count++;
      }
    }

    winLen = 1;
    exitg1 = false;
    while ((!exitg1) && (winLen - 1 <= numElements - 1)) {
      count = winLen - 1;
      count = ind_vect[count];
      y = buf[count - 1];
      cond = (rtu_0 < y);
      if (cond) {
        exitg1 = true;
      } else {
        placement = count - 1;
        if (N < -2147483647) {
          N = MIN_int32_T;
        } else {
          N--;
        }

        winLen++;
      }
    }
  }

  buf[placement] = rtu_0;
  bufIdx[placement] = cnt;
  if (N > 2147483646) {
    numElements = MAX_int32_T;
  } else {
    numElements = N + 1;
  }

  y = buf[top - 1];
  if (cnt > 2147483646) {
    cnt = MAX_int32_T;
  } else {
    cnt++;
  }

  if (cnt > 1000000) {
    cnt -= 1000000;
    for (winLen = 0; winLen < 200; winLen++) {
      i = bufIdx[winLen];
      if (i < -2146483648) {
        i = MIN_int32_T;
      } else {
        i -= 1000000;
      }

      bufIdx[winLen] = i;
    }
  }

  for (i = 0; i < 200; i++) {
    obj_0->pBuffer[i] = buf[i];
  }

  for (i = 0; i < 200; i++) {
    obj_0->pBufferIdx[i] = bufIdx[i];
  }

  obj_0->pNumElements = numElements;
  obj_0->pCount = cnt;
  obj_0->pTop = top;
  localB->f9_v3_max = y;

  /* End of MATLABSystem: '<Root>/Moving Maximum3' */
}

/*
 * Termination for atomic system:
 *    synthesized block
 *    synthesized block
 *    synthesized block
 *    synthesized block
 */
void rs_bicycle_MovingMaximum3_Term(DW_MovingMaximum3_rs_bicycle_T *localDW)
{
  /* Terminate for MATLABSystem: '<Root>/Moving Maximum3' */
  matlabCodegenHandle_matlabCodeg(&localDW->obj);
}

static real_T AbstractSlidingWindowMinMaxCG_s(e_dsp_private_SlidingWindowMi_T
  *obj, real_T x)
{
  real_T m;
  real_T buf[500];
  int32_T bufIdx[500];
  int32_T numElements;
  int32_T cnt;
  int32_T top;
  int32_T winLen;
  int32_T placement;
  int32_T ind_vect[500];
  int32_T N;
  int32_T count;
  int32_T indVal;
  boolean_T cond;
  int32_T b_ind;
  real_T y;
  int32_T qY;
  boolean_T exitg1;
  memcpy(&buf[0], &obj->pBuffer[0], 500U * sizeof(real_T));
  memcpy(&bufIdx[0], &obj->pBufferIdx[0], 500U * sizeof(int32_T));
  numElements = obj->pNumElements;
  cnt = obj->pCount;
  top = obj->pTop;
  if (numElements > 0) {
    winLen = bufIdx[top - 1];
    if ((cnt >= 0) && (winLen < cnt - MAX_int32_T)) {
      winLen = MAX_int32_T;
    } else if ((cnt < 0) && (winLen > cnt - MIN_int32_T)) {
      winLen = MIN_int32_T;
    } else {
      winLen = cnt - winLen;
    }

    if (winLen == 500) {
      if (top > 2147483646) {
        top = MAX_int32_T;
      } else {
        top++;
      }

      if (top > 500) {
        top = 1;
      }

      numElements--;
    }
  }

  if ((numElements < 0) && (top < MIN_int32_T - numElements)) {
    winLen = MIN_int32_T;
  } else if ((numElements > 0) && (top > MAX_int32_T - numElements)) {
    winLen = MAX_int32_T;
  } else {
    winLen = numElements + top;
  }

  if (winLen < -2147483647) {
    placement = MIN_int32_T;
  } else {
    placement = winLen - 1;
  }

  if (placement >= 500) {
    placement -= 500;
  }

  winLen = placement + 1;
  placement = winLen - 1;
  memset(&ind_vect[0], 0, 500U * sizeof(int32_T));
  N = numElements;
  if (numElements > 0) {
    count = 1;
    winLen = numElements - 1;
    if (winLen >= 0) {
      if (top < -2147483647) {
        qY = MIN_int32_T;
      } else {
        qY = top - 1;
      }
    }

    for (b_ind = winLen; b_ind >= 0; b_ind--) {
      if ((qY < 0) && (b_ind < MIN_int32_T - qY)) {
        indVal = MIN_int32_T;
      } else if ((qY > 0) && (b_ind > MAX_int32_T - qY)) {
        indVal = MAX_int32_T;
      } else {
        indVal = qY + b_ind;
      }

      if (indVal >= 500) {
        indVal -= 500;
      }

      indVal++;
      ind_vect[count - 1] = indVal;
      if (count > 2147483646) {
        count = MAX_int32_T;
      } else {
        count++;
      }
    }

    winLen = 1;
    exitg1 = false;
    while ((!exitg1) && (winLen - 1 <= numElements - 1)) {
      count = winLen - 1;
      count = ind_vect[count];
      y = buf[count - 1];
      cond = (x > y);
      if (cond) {
        exitg1 = true;
      } else {
        placement = count - 1;
        if (N < -2147483647) {
          N = MIN_int32_T;
        } else {
          N--;
        }

        winLen++;
      }
    }
  }

  buf[placement] = x;
  bufIdx[placement] = cnt;
  if (N > 2147483646) {
    numElements = MAX_int32_T;
  } else {
    numElements = N + 1;
  }

  m = buf[top - 1];
  if (cnt > 2147483646) {
    cnt = MAX_int32_T;
  } else {
    cnt++;
  }

  if (cnt > 1000000) {
    cnt -= 1000000;
    for (placement = 0; placement < 500; placement++) {
      winLen = bufIdx[placement];
      if (winLen < -2146483648) {
        winLen = MIN_int32_T;
      } else {
        winLen -= 1000000;
      }

      bufIdx[placement] = winLen;
    }
  }

  memcpy(&obj->pBuffer[0], &buf[0], 500U * sizeof(real_T));
  memcpy(&obj->pBufferIdx[0], &bufIdx[0], 500U * sizeof(int32_T));
  obj->pNumElements = numElements;
  obj->pCount = cnt;
  obj->pTop = top;
  return m;
}

real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T tmp;
  real_T tmp_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
    tmp = fabs(u0);
    tmp_0 = fabs(u1);
    if (rtIsInf(u1)) {
      if (tmp == 1.0) {
        y = 1.0;
      } else if (tmp > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (tmp_0 == 0.0) {
      y = 1.0;
    } else if (tmp_0 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = (rtNaN);
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

static void rs_bicycl_SystemCore_release_or(dsp_MovingMaximum_rs_bicycl_o_T *obj)
{
  dsp_MovingMaximum_rs_bicycl_o_T *obj_0;
  e_dsp_private_SlidingWindow_o_T *obj_1;
  if (obj->isInitialized == 1) {
    obj_0 = obj;
    if (obj_0->isSetupComplete) {
      obj_0->NumChannels = -1;
      obj_1 = obj_0->pStat;
      if (obj_1->isInitialized == 1) {
        obj_1->isInitialized = 2;
      }
    }
  }
}

static void rs_bicycle_SystemCore_delete_or(dsp_MovingMaximum_rs_bicycl_o_T *obj)
{
  rs_bicycl_SystemCore_release_or(obj);
}

static void matlabCodegenHandle_matlabCo_or(dsp_MovingMaximum_rs_bicycl_o_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    rs_bicycle_SystemCore_delete_or(obj);
  }
}

static void rs_bicycle_SystemCore_release_o(dsp_MovingMinimum_rs_bicycle_T *obj)
{
  dsp_MovingMinimum_rs_bicycle_T *obj_0;
  e_dsp_private_SlidingWindowMi_T *obj_1;
  if (obj->isInitialized == 1) {
    obj_0 = obj;
    if (obj_0->isSetupComplete) {
      obj_0->NumChannels = -1;
      obj_1 = obj_0->pStat;
      if (obj_1->isInitialized == 1) {
        obj_1->isInitialized = 2;
      }
    }
  }
}

static void rs_bicycle_SystemCore_delete_o(dsp_MovingMinimum_rs_bicycle_T *obj)
{
  rs_bicycle_SystemCore_release_o(obj);
}

static void matlabCodegenHandle_matlabCod_o(dsp_MovingMinimum_rs_bicycle_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    rs_bicycle_SystemCore_delete_o(obj);
  }
}

/* System initialize for root system: '<Root>' */
void MdlInitialize(void)
{
  dsp_MovingMaximum_rs_bicycl_o_T *obj;
  e_dsp_private_SlidingWindow_o_T *obj_0;
  dsp_MovingMinimum_rs_bicycle_T *obj_1;
  e_dsp_private_SlidingWindowMi_T *obj_2;
  int32_T i;

  /* InitializeConditions for Integrator: '<Root>/Integrator' */
  if (ssIsFirstInitCond(rtS)) {
    rtX.Integrator_CSTATE = 0.0;
  }

  rtDW.Integrator_IWORK = 1;

  /* End of InitializeConditions for Integrator: '<Root>/Integrator' */

  /* InitializeConditions for Integrator: '<S10>/Integrator' */
  rtX.Integrator_CSTATE_a = rtP.Integrator_IC;

  /* InitializeConditions for UnitDelay: '<S2>/UD' */
  rtDW.UD_DSTATE = rtP.Difference_ICPrevInput;

  /* InitializeConditions for Integrator: '<Root>/Integrator1' */
  rtX.Integrator1_CSTATE = rtP.Integrator1_IC;

  /* InitializeConditions for Integrator: '<Root>/Integrator2' */
  rtX.Integrator2_CSTATE = rtP.Integrator2_IC;

  /* InitializeConditions for MATLABSystem: '<S9>/Moving Maximum' */
  obj = &rtDW.obj_g;
  obj_0 = obj->pStat;
  if (obj_0->isInitialized == 1) {
    obj_0->pBuffer[0] = 0.0;
    obj_0->pBuffer[1] = 0.0;
    obj_0->pBuffer[2] = 0.0;
    obj_0->pBuffer[3] = 0.0;
    obj_0->pBufferIdx[0] = 0;
    obj_0->pBufferIdx[1] = 0;
    obj_0->pBufferIdx[2] = 0;
    obj_0->pBufferIdx[3] = 0;
    obj_0->pNumElements = 0;
    obj_0->pCount = 1;
    obj_0->pTop = 1;
  }

  /* End of InitializeConditions for MATLABSystem: '<S9>/Moving Maximum' */

  /* InitializeConditions for MATLABSystem: '<Root>/Moving Minimum1' */
  obj_1 = &rtDW.obj;
  obj_2 = obj_1->pStat;
  if (obj_2->isInitialized == 1) {
    for (i = 0; i < 500; i++) {
      obj_2->pBuffer[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      obj_2->pBufferIdx[i] = 0;
    }

    obj_2->pNumElements = 0;
    obj_2->pCount = 1;
    obj_2->pTop = 1;
  }

  /* End of InitializeConditions for MATLABSystem: '<Root>/Moving Minimum1' */
  rs_bicycle_MovingMaximum3_Init(&rtDW.MovingMaximum);
  rs_bicycle_MovingMaximum3_Init(&rtDW.MovingMaximum2);
  rs_bicycle_MovingMaximum3_Init(&rtDW.MovingMaximum1);
  rs_bicycle_MovingMaximum3_Init(&rtDW.MovingMaximum3);
}

/* Start for root system: '<Root>' */
void MdlStart(void)
{
  e_dsp_private_SlidingWindow_o_T *iobj_0;
  dsp_MovingMaximum_rs_bicycl_o_T *b_obj;
  dsp_MovingMaximum_rs_bicycl_o_T *obj;
  e_dsp_private_SlidingWindowMi_T *iobj_0_0;
  dsp_MovingMinimum_rs_bicycle_T *b_obj_0;
  dsp_MovingMinimum_rs_bicycle_T *obj_0;

  /* Start for Constant: '<Root>/Initial Position' */
  rtB.init_position = rtP.init_position;

  /* Start for MATLABSystem: '<S9>/Moving Maximum' */
  rtDW.obj_g.matlabCodegenIsDeleted = true;
  iobj_0 = &rtDW.gobj_0_h;
  b_obj = &rtDW.obj_g;
  b_obj->isInitialized = 0;
  b_obj->NumChannels = -1;
  b_obj->matlabCodegenIsDeleted = false;
  rtDW.objisempty = true;
  b_obj = &rtDW.obj_g;
  b_obj->isSetupComplete = false;
  b_obj->isInitialized = 1;
  obj = b_obj;
  obj->NumChannels = 1;
  iobj_0->isInitialized = 0;
  obj->pStat = iobj_0;
  iobj_0 = obj->pStat;
  iobj_0->isSetupComplete = false;
  iobj_0->isInitialized = 1;
  iobj_0->isSetupComplete = true;
  b_obj->isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Moving Minimum1' */
  rtDW.obj.matlabCodegenIsDeleted = true;
  iobj_0_0 = &rtDW.gobj_0;
  b_obj_0 = &rtDW.obj;
  b_obj_0->isInitialized = 0;
  b_obj_0->NumChannels = -1;
  b_obj_0->matlabCodegenIsDeleted = false;
  rtDW.objisempty_g = true;
  b_obj_0 = &rtDW.obj;
  b_obj_0->isSetupComplete = false;
  b_obj_0->isInitialized = 1;
  obj_0 = b_obj_0;
  obj_0->NumChannels = 1;
  iobj_0_0->isInitialized = 0;
  obj_0->pStat = iobj_0_0;
  iobj_0_0 = obj_0->pStat;
  iobj_0_0->isSetupComplete = false;
  iobj_0_0->isInitialized = 1;
  iobj_0_0->isSetupComplete = true;
  b_obj_0->isSetupComplete = true;
  rs_bicycle_MovingMaximum3_Start(&rtDW.MovingMaximum);
  rs_bicycle_MovingMaximum3_Start(&rtDW.MovingMaximum2);
  rs_bicycle_MovingMaximum3_Start(&rtDW.MovingMaximum1);
  rs_bicycle_MovingMaximum3_Start(&rtDW.MovingMaximum3);
  MdlInitialize();
}

/* Outputs for root system: '<Root>' */
void MdlOutputs(int_T tid)
{
  dsp_MovingMaximum_rs_bicycl_o_T *obj;
  e_dsp_private_SlidingWindow_o_T *obj_0;
  e_dsp_private_SlidingWindow_o_T *obj_1;
  real_T buf[4];
  int32_T bufIdx[4];
  int32_T numElements;
  int32_T cnt;
  int32_T top;
  int32_T winLen;
  int32_T placement;
  int32_T ind_vect[4];
  int32_T N;
  int32_T count;
  int32_T indVal;
  boolean_T cond;
  int32_T b_ind;
  e_dsp_private_SlidingWindow_o_T *obj_2;
  real_T y;
  dsp_MovingMinimum_rs_bicycle_T *obj_3;
  e_dsp_private_SlidingWindowMi_T *obj_4;
  e_dsp_private_SlidingWindowMi_T *obj_5;
  e_dsp_private_SlidingWindowMi_T *obj_6;
  real_T Bias;
  int32_T qY;
  boolean_T exitg1;

  /* Read data from the mat file of inport block */
  if (gblInportFileName != (NULL)) {
    int_T currTimeIdx;
    int_T i;

    /*
     *  Read in data from mat file for root inport vel
     */
    if (gblInportTUtables[0].nTimePoints > 0) {
      if (1) {
        {
          real_T time = ssGetTaskTime(rtS,0);
          int k = 1;
          if (gblInportTUtables[0].nTimePoints == 1) {
            k = 0;
          }

          currTimeIdx = rt_getTimeIdx(gblInportTUtables[0].time, time,
            gblInportTUtables[0].nTimePoints,
            gblInportTUtables[0].currTimeIdx,
            1,
            0);
          gblInportTUtables[0].currTimeIdx = currTimeIdx;
          for (i = 0; i < 1; i++) {
            real_T* realPtr1 = (real_T*)gblInportTUtables[0].ur +
              i*gblInportTUtables[0].nTimePoints +currTimeIdx;
            real_T* realPtr2 = realPtr1 + 1*k;
            (void)rt_Interpolate_Datatype(
              realPtr1,
              realPtr2,
              &rtU.vel,
              time,
              gblInportTUtables[0].time[currTimeIdx],
              gblInportTUtables[0].time[currTimeIdx + k],
              gblInportTUtables[0].uDataType);
          }
        }
      }
    }
  }

  /* end read inport data from file */
  if (ssIsSampleHit(rtS, 1, 0)) {
    /* Constant: '<Root>/Initial Position' */
    rtB.init_position = rtP.init_position;
  }

  /* Integrator: '<Root>/Integrator' */
  if (rtDW.Integrator_IWORK != 0) {
    rtX.Integrator_CSTATE = rtB.init_position;
  }

  rtB.pos = rtX.Integrator_CSTATE;

  /* End of Integrator: '<Root>/Integrator' */

  /* MATLABSystem: '<S9>/Moving Maximum' */
  Bias = rtB.pos;
  obj = &rtDW.obj_g;
  obj_0 = obj->pStat;
  if (obj_0->isInitialized != 1) {
    obj_1 = obj_0;
    obj_2 = obj_1;
    obj_2->isSetupComplete = false;
    obj_2->isInitialized = 1;
    obj_2->isSetupComplete = true;
    obj_1->pBuffer[0] = 0.0;
    obj_1->pBuffer[1] = 0.0;
    obj_1->pBuffer[2] = 0.0;
    obj_1->pBuffer[3] = 0.0;
    obj_1->pBufferIdx[0] = 0;
    obj_1->pBufferIdx[1] = 0;
    obj_1->pBufferIdx[2] = 0;
    obj_1->pBufferIdx[3] = 0;
    obj_1->pNumElements = 0;
    obj_1->pCount = 1;
    obj_1->pTop = 1;
  }

  buf[0] = obj_0->pBuffer[0];
  buf[1] = obj_0->pBuffer[1];
  buf[2] = obj_0->pBuffer[2];
  buf[3] = obj_0->pBuffer[3];
  bufIdx[0] = obj_0->pBufferIdx[0];
  bufIdx[1] = obj_0->pBufferIdx[1];
  bufIdx[2] = obj_0->pBufferIdx[2];
  bufIdx[3] = obj_0->pBufferIdx[3];
  numElements = obj_0->pNumElements;
  cnt = obj_0->pCount;
  top = obj_0->pTop;
  if (numElements > 0) {
    placement = bufIdx[top - 1];
    if ((cnt >= 0) && (placement < cnt - MAX_int32_T)) {
      qY = MAX_int32_T;
    } else if ((cnt < 0) && (placement > cnt - MIN_int32_T)) {
      qY = MIN_int32_T;
    } else {
      qY = cnt - placement;
    }

    if (qY == 4) {
      if (top > 2147483646) {
        top = MAX_int32_T;
      } else {
        top++;
      }

      if (top > 4) {
        top = 1;
      }

      numElements--;
    }
  }

  if ((numElements < 0) && (top < MIN_int32_T - numElements)) {
    qY = MIN_int32_T;
  } else if ((numElements > 0) && (top > MAX_int32_T - numElements)) {
    qY = MAX_int32_T;
  } else {
    qY = numElements + top;
  }

  if (qY < -2147483647) {
    placement = MIN_int32_T;
  } else {
    placement = qY - 1;
  }

  if (placement >= 4) {
    placement -= 4;
  }

  qY = placement + 1;
  placement = qY - 1;
  ind_vect[0] = 0;
  ind_vect[1] = 0;
  ind_vect[2] = 0;
  ind_vect[3] = 0;
  N = numElements;
  if (numElements > 0) {
    count = 1;
    qY = numElements - 1;
    if (qY >= 0) {
      if (top < -2147483647) {
        winLen = MIN_int32_T;
      } else {
        winLen = top - 1;
      }
    }

    for (b_ind = qY; b_ind >= 0; b_ind--) {
      if ((winLen < 0) && (b_ind < MIN_int32_T - winLen)) {
        indVal = MIN_int32_T;
      } else if ((winLen > 0) && (b_ind > MAX_int32_T - winLen)) {
        indVal = MAX_int32_T;
      } else {
        indVal = winLen + b_ind;
      }

      if (indVal >= 4) {
        indVal -= 4;
      }

      indVal++;
      ind_vect[count - 1] = indVal;
      if (count > 2147483646) {
        count = MAX_int32_T;
      } else {
        count++;
      }
    }

    winLen = 1;
    exitg1 = false;
    while ((!exitg1) && (winLen - 1 <= numElements - 1)) {
      count = winLen - 1;
      count = ind_vect[count];
      y = buf[count - 1];
      cond = (Bias < y);
      if (cond) {
        exitg1 = true;
      } else {
        placement = count - 1;
        if (N < -2147483647) {
          N = MIN_int32_T;
        } else {
          N--;
        }

        winLen++;
      }
    }
  }

  buf[placement] = Bias;
  bufIdx[placement] = cnt;
  if (N > 2147483646) {
    numElements = MAX_int32_T;
  } else {
    numElements = N + 1;
  }

  Bias = buf[top - 1];
  if (cnt > 2147483646) {
    cnt = MAX_int32_T;
  } else {
    cnt++;
  }

  if (cnt > 1000000) {
    cnt -= 1000000;
    qY = bufIdx[0];
    if (qY < -2146483648) {
      qY = MIN_int32_T;
    } else {
      qY -= 1000000;
    }

    bufIdx[0] = qY;
    qY = bufIdx[1];
    if (qY < -2146483648) {
      qY = MIN_int32_T;
    } else {
      qY -= 1000000;
    }

    bufIdx[1] = qY;
    qY = bufIdx[2];
    if (qY < -2146483648) {
      qY = MIN_int32_T;
    } else {
      qY -= 1000000;
    }

    bufIdx[2] = qY;
    qY = bufIdx[3];
    if (qY < -2146483648) {
      qY = MIN_int32_T;
    } else {
      qY -= 1000000;
    }

    bufIdx[3] = qY;
  }

  obj_0->pBuffer[0] = buf[0];
  obj_0->pBuffer[1] = buf[1];
  obj_0->pBuffer[2] = buf[2];
  obj_0->pBuffer[3] = buf[3];
  obj_0->pBufferIdx[0] = bufIdx[0];
  obj_0->pBufferIdx[1] = bufIdx[1];
  obj_0->pBufferIdx[2] = bufIdx[2];
  obj_0->pBufferIdx[3] = bufIdx[3];
  obj_0->pNumElements = numElements;
  obj_0->pCount = cnt;
  obj_0->pTop = top;
  rtB.MovingMaximum_o = Bias;

  /* End of MATLABSystem: '<S9>/Moving Maximum' */

  /* Product: '<S9>/Divide' incorporates:
   *  Constant: '<Root>/Constant4'
   */
  rtB.frac_dist = rtB.MovingMaximum_o / rtP.env_route_length;

  /* Integrator: '<S10>/Integrator' */
  rtB.Integrator = rtX.Integrator_CSTATE_a;

  /* Clock: '<S10>/Clock7' */
  rtB.Clock7 = ssGetT(rtS);

  /* Switch: '<S10>/Switch' incorporates:
   *  Constant: '<S10>/Constant'
   */
  if (rtB.Clock7 > rtP.Switch_Threshold) {
    /* Product: '<S10>/Divide' */
    rtB.frac_forest = rtB.Integrator / rtB.Clock7;
    rtB.Switch = rtB.frac_forest;
  } else {
    rtB.Switch = rtP.Constant_Value;
  }

  /* End of Switch: '<S10>/Switch' */
  if (ssIsSampleHit(rtS, 1, 0)) {
    /* Product: '<S7>/Product' incorporates:
     *  Constant: '<Root>/Constant4'
     *  Constant: '<Root>/Constant5'
     */
    rtB.Product[0] = rtP.env_traffic_pos[0] * rtP.env_route_length;
    rtB.Product[1] = rtP.env_traffic_pos[1] * rtP.env_route_length;
  }

  /* Clock: '<Root>/Clock1' */
  rtB.Clock1 = ssGetT(rtS);

  /* Sum: '<S11>/Sum' */
  rtB.Sum[0] = rtB.pos - rtB.Product[0];

  /* Abs: '<S11>/Abs' */
  rtB.Abs[0] = fabs(rtB.Sum[0]);

  /* RelationalOperator: '<S8>/Relational Operator' incorporates:
   *  Constant: '<Root>/Constant6'
   */
  rtB.RelationalOperator[0] = (rtP.env_traffic_times[0] <= rtB.Clock1);

  /* Sum: '<S11>/Sum' */
  rtB.Sum[1] = rtB.pos - rtB.Product[1];

  /* Abs: '<S11>/Abs' */
  rtB.Abs[1] = fabs(rtB.Sum[1]);

  /* RelationalOperator: '<S8>/Relational Operator' incorporates:
   *  Constant: '<Root>/Constant6'
   */
  rtB.RelationalOperator[1] = (rtP.env_traffic_times[1] <= rtB.Clock1);
  if (ssIsSampleHit(rtS, 1, 0)) {
    /* Sum: '<S8>/Sum1' incorporates:
     *  Constant: '<Root>/Constant1'
     *  Constant: '<Root>/Constant6'
     */
    rtB.Sum1[0] = rtP.env_traffic_times[0] + rtP.env_traffic_durations[0];
    rtB.Sum1[1] = rtP.env_traffic_times[1] + rtP.env_traffic_durations[1];
  }

  /* Switch: '<S11>/Switch2' incorporates:
   *  Constant: '<S11>/Constant1'
   */
  Bias = 0.25 * rtP.env_route_length;

  /* RelationalOperator: '<S8>/Relational Operator1' */
  rtB.RelationalOperator1[0] = (rtB.Clock1 <= rtB.Sum1[0]);

  /* Logic: '<S8>/Logical Operator' */
  rtB.LogicalOperator[0] = (rtB.RelationalOperator[0] &&
    rtB.RelationalOperator1[0]);

  /* Switch: '<S8>/Switch1' incorporates:
   *  Constant: '<S8>/Constant'
   *  Constant: '<S8>/no1'
   */
  if (rtB.LogicalOperator[0]) {
    rtB.Switch1[0] = rtP.Constant_Value_d;
  } else {
    rtB.Switch1[0] = rtP.no1_Value;
  }

  /* Switch: '<S11>/Switch2' */
  if (rtB.Switch1[0] > rtP.Switch2_Threshold) {
    rtB.Switch2[0] = rtB.Abs[0];
  } else {
    rtB.Switch2[0] = Bias;
  }

  /* RelationalOperator: '<S8>/Relational Operator1' */
  rtB.RelationalOperator1[1] = (rtB.Clock1 <= rtB.Sum1[1]);

  /* Logic: '<S8>/Logical Operator' */
  rtB.LogicalOperator[1] = (rtB.RelationalOperator[1] &&
    rtB.RelationalOperator1[1]);

  /* Switch: '<S8>/Switch1' incorporates:
   *  Constant: '<S8>/Constant'
   *  Constant: '<S8>/no1'
   */
  if (rtB.LogicalOperator[1]) {
    rtB.Switch1[1] = rtP.Constant_Value_d;
  } else {
    rtB.Switch1[1] = rtP.no1_Value;
  }

  /* Switch: '<S11>/Switch2' */
  if (rtB.Switch1[1] > rtP.Switch2_Threshold) {
    rtB.Switch2[1] = rtB.Abs[1];
  } else {
    rtB.Switch2[1] = Bias;
  }

  /* MATLAB Function: '<S11>/Minimum Between Signals ' */
  /* :  y = min(u); */
  if ((rtB.Switch2[0] > rtB.Switch2[1]) || (rtIsNaN(rtB.Switch2[0]) && (!rtIsNaN
        (rtB.Switch2[1])))) {
    rtB.y = rtB.Switch2[1];
  } else {
    rtB.y = rtB.Switch2[0];
  }

  /* End of MATLAB Function: '<S11>/Minimum Between Signals ' */

  /* MATLABSystem: '<Root>/Moving Minimum1' */
  Bias = rtB.y;
  obj_3 = &rtDW.obj;
  obj_4 = obj_3->pStat;
  if (obj_4->isInitialized != 1) {
    obj_5 = obj_4;
    obj_6 = obj_5;
    obj_6->isSetupComplete = false;
    obj_6->isInitialized = 1;
    obj_6->isSetupComplete = true;
    for (numElements = 0; numElements < 500; numElements++) {
      obj_5->pBuffer[numElements] = 0.0;
    }

    for (numElements = 0; numElements < 500; numElements++) {
      obj_5->pBufferIdx[numElements] = 0;
    }

    obj_5->pNumElements = 0;
    obj_5->pCount = 1;
    obj_5->pTop = 1;
  }

  Bias = AbstractSlidingWindowMinMaxCG_s(obj_4, Bias);
  rtB.f3_traffic_dist = Bias;

  /* End of MATLABSystem: '<Root>/Moving Minimum1' */

  /* Product: '<S12>/Product' incorporates:
   *  Constant: '<S12>/reaction_time'
   *  Inport: '<Root>/Time Velocity Vectors'
   */
  rtB.Product_c = rtU.vel * rtP.reaction_time_Value;

  /* Math: '<S12>/Square' incorporates:
   *  Inport: '<Root>/Time Velocity Vectors'
   */
  rtB.Square = rtU.vel * rtU.vel;

  /* Clock: '<Root>/Clock5' */
  rtB.Clock5 = ssGetT(rtS);

  /* Sum: '<S1>/Sum' incorporates:
   *  Constant: '<Root>/Constant8'
   */
  rtB.Sum_n = rtP.env_t_rain_start - rtB.Clock5;

  /* Switch: '<S1>/Switch' incorporates:
   *  Constant: '<Root>/Constant10'
   *  Constant: '<Root>/Constant9'
   */
  if (rtB.Sum_n > rtP.Switch_Threshold_h) {
    rtB.static_friction = rtP.env_mu_s_dry;
  } else {
    rtB.static_friction = rtP.env_mu_s_wet;
  }

  /* End of Switch: '<S1>/Switch' */

  /* Product: '<S12>/Product1' incorporates:
   *  Constant: '<S12>/gravity'
   */
  rtB.Product1 = rtB.static_friction * rtP.g;

  /* Gain: '<S12>/Gain' */
  rtB.Gain = rtP.Gain_Gain * rtB.Product1;

  /* Product: '<S12>/Divide' */
  rtB.Divide = rtB.Square / rtB.Gain;

  /* Sum: '<S12>/Sum' */
  rtB.stopping_dist = rtB.Product_c + rtB.Divide;
  rs_bicycle_MovingMaximum3(rtB.stopping_dist, &rtB.MovingMaximum,
    &rtDW.MovingMaximum);
  if (ssIsSampleHit(rtS, 1, 0)) {
    /* UnitDelay: '<S2>/UD' */
    rtB.Uk1 = rtDW.UD_DSTATE;

    /* Sum: '<S2>/Diff' incorporates:
     *  Inport: '<Root>/Time Velocity Vectors'
     */
    rtB.Diff = rtU.vel - rtB.Uk1;

    /* RelationalOperator: '<S13>/Relational Operator' incorporates:
     *  Constant: '<S13>/Constant1'
     */
    rtB.RelationalOperator_p = (rtB.Diff >= rtP.Constant1_Value);

    /* RelationalOperator: '<S13>/Relational Operator2' incorporates:
     *  Constant: '<S13>/Constant3'
     */
    rtB.RelationalOperator2 = (rtB.Diff < rtP.Constant3_Value);
  }

  /* RelationalOperator: '<S13>/Relational Operator1' incorporates:
   *  Constant: '<S13>/Constant'
   *  Inport: '<Root>/Time Velocity Vectors'
   */
  rtB.RelationalOperator1_c = (rtU.vel >= rtP.Constant_Value_k);

  /* Logic: '<S13>/Logical Operator' */
  rtB.LogicalOperator_l = (rtB.RelationalOperator_p && rtB.RelationalOperator1_c);

  /* RelationalOperator: '<S13>/Relational Operator3' incorporates:
   *  Constant: '<S13>/Constant2'
   *  Inport: '<Root>/Time Velocity Vectors'
   */
  rtB.RelationalOperator3 = (rtU.vel < rtP.Constant2_Value);

  /* Logic: '<S13>/Logical Operator1' */
  rtB.LogicalOperator1 = (rtB.RelationalOperator2 && rtB.RelationalOperator3);

  /* Logic: '<S13>/Logical Operator2' */
  rtB.LogicalOperator2 = (rtB.LogicalOperator_l || rtB.LogicalOperator1);

  /* Switch: '<S13>/Switch' incorporates:
   *  Constant: '<S13>/Constant4'
   */
  if (rtB.LogicalOperator2) {
    /* Product: '<S13>/Product1' incorporates:
     *  Inport: '<Root>/Time Velocity Vectors'
     */
    rtB.cyclist_power_density = rtB.Diff * rtU.vel;
    rtB.Switch_h = rtB.cyclist_power_density;
  } else {
    rtB.Switch_h = rtP.Constant4_Value;
  }

  /* End of Switch: '<S13>/Switch' */
  rs_bicycle_MovingMaximum3(rtB.Switch_h, &rtB.MovingMaximum2,
    &rtDW.MovingMaximum2);

  /* Integrator: '<Root>/Integrator1' */
  rtB.f6_av_int = rtX.Integrator1_CSTATE;
  if (ssIsSampleHit(rtS, 1, 0)) {
    /* Product: '<S14>/Divide' incorporates:
     *  Constant: '<S14>/gravity'
     */
    rtB.Divide_l = rtB.Diff / rtP.g;

    /* Abs: '<S14>/Abs' */
    rtB.Abs_d = fabs(rtB.Divide_l);
  }

  /* Sum: '<S14>/Sum' */
  rtB.slipping = rtB.Abs_d - rtB.static_friction;
  rs_bicycle_MovingMaximum3(rtB.slipping, &rtB.MovingMaximum1,
    &rtDW.MovingMaximum1);

  /* Math: '<S16>/Exp' incorporates:
   *  Constant: '<S16>/Constant'
   *  Inport: '<Root>/Time Velocity Vectors'
   */
  rtB.Exp = rt_powd_snf(rtU.vel, rtP.Constant_Value_j);

  /* Abs: '<S16>/Abs' */
  rtB.Abs_h = fabs(rtB.Exp);
  rs_bicycle_MovingMaximum3(rtB.Abs_h, &rtB.MovingMaximum3, &rtDW.MovingMaximum3);

  /* Integrator: '<Root>/Integrator2' */
  rtB.f10_v3_int = rtX.Integrator2_CSTATE;

  /* Outport: '<Root>/F' incorporates:
   *  Inport: '<Root>/Time Velocity Vectors'
   */
  rtY.F[0] = rtB.frac_dist;
  rtY.F[1] = rtB.Switch;
  rtY.F[2] = rtB.f3_traffic_dist;
  rtY.F[3] = rtB.MovingMaximum.f9_v3_max;
  rtY.F[4] = rtB.MovingMaximum2.f9_v3_max;
  rtY.F[5] = rtB.f6_av_int;
  rtY.F[6] = rtB.MovingMaximum1.f9_v3_max;
  rtY.F[7] = rtU.vel;
  rtY.F[8] = rtB.MovingMaximum3.f9_v3_max;
  rtY.F[9] = rtB.f10_v3_int;

  /* Outport: '<Root>/S' incorporates:
   *  Inport: '<Root>/Time Velocity Vectors'
   */
  rtY.S[0] = rtB.Diff;
  rtY.S[1] = rtU.vel;
  rtY.S[2] = rtB.pos;
  if (ssIsSampleHit(rtS, 1, 0)) {
  }

  /* Clock: '<Root>/Clock2' */
  rtB.Clock2 = ssGetT(rtS);

  /* Sum: '<S5>/Sum2' incorporates:
   *  Constant: '<Root>/Constant6'
   */
  rtB.Sum2[0] = rtP.env_traffic_times[0] - rtB.Clock2;

  /* RelationalOperator: '<S5>/Relational Operator' incorporates:
   *  Constant: '<Root>/Constant6'
   */
  rtB.RelationalOperator_i[0] = (rtB.Clock2 <= rtP.env_traffic_times[0]);

  /* Sum: '<S5>/Sum1' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  rtB.Sum1_o[0] = (0.0 - rtB.Sum2[0]) - rtP.env_traffic_durations[0];

  /* Switch: '<S5>/Switch1' */
  if (rtB.RelationalOperator_i[0]) {
    rtB.Switch1_m[0] = rtB.Sum2[0];
  } else {
    rtB.Switch1_m[0] = rtB.Sum1_o[0];
  }

  /* Sum: '<S5>/Sum2' incorporates:
   *  Constant: '<Root>/Constant6'
   */
  rtB.Sum2[1] = rtP.env_traffic_times[1] - rtB.Clock2;

  /* RelationalOperator: '<S5>/Relational Operator' incorporates:
   *  Constant: '<Root>/Constant6'
   */
  rtB.RelationalOperator_i[1] = (rtB.Clock2 <= rtP.env_traffic_times[1]);

  /* Sum: '<S5>/Sum1' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  rtB.Sum1_o[1] = (0.0 - rtB.Sum2[1]) - rtP.env_traffic_durations[1];

  /* Switch: '<S5>/Switch1' */
  if (rtB.RelationalOperator_i[1]) {
    rtB.Switch1_m[1] = rtB.Sum2[1];
  } else {
    rtB.Switch1_m[1] = rtB.Sum1_o[1];
  }

  if (ssIsSampleHit(rtS, 1, 0)) {
    /* Product: '<S3>/Product' incorporates:
     *  Constant: '<Root>/Constant4'
     *  Constant: '<Root>/Constant7'
     */
    rtB.Product_j[0] = rtP.env_forest[0] * rtP.env_route_length;
    rtB.Product_j[1] = rtP.env_forest[1] * rtP.env_route_length;
  }

  /* Clock: '<Root>/Clock3' */
  rtB.Clock3 = ssGetT(rtS);

  /* Sum: '<S6>/Sum1' incorporates:
   *  Constant: '<Root>/Constant8'
   */
  rtB.Sum1_ou = rtP.env_t_rain_start - rtB.Clock3;

  /* Clock: '<Root>/Clock4' */
  rtB.Clock4 = ssGetT(rtS);

  /* Sum: '<S4>/Sum1' incorporates:
   *  Constant: '<Root>/Constant8'
   */
  rtB.Sum1_e = rtB.Clock4 - rtP.env_t_rain_start;

  /* Switch: '<S4>/Switch1' incorporates:
   *  Constant: '<S4>/no'
   *  Constant: '<S4>/yes'
   */
  if (rtB.Sum1_e > rtP.Switch1_Threshold) {
    rtB.raining = rtP.yes_Value;
  } else {
    rtB.raining = rtP.no_Value;
  }

  /* End of Switch: '<S4>/Switch1' */
  if (ssIsSampleHit(rtS, 1, 0)) {
  }

  /* RelationalOperator: '<S17>/Relational Operator' */
  rtB.RelationalOperator_h = (rtB.Product_j[0] <= rtB.pos);

  /* RelationalOperator: '<S17>/Relational Operator1' */
  rtB.RelationalOperator1_d = (rtB.pos <= rtB.Product_j[1]);

  /* Logic: '<S17>/Logical Operator' */
  rtB.LogicalOperator_k = (rtB.RelationalOperator_h && rtB.RelationalOperator1_d);

  /* Switch: '<S17>/Switch' incorporates:
   *  Constant: '<S17>/Constant'
   *  Constant: '<S17>/no'
   */
  if (rtB.LogicalOperator_k) {
    rtB.Switch_m = rtP.Constant_Value_o;
  } else {
    rtB.Switch_m = rtP.no_Value_e;
  }

  /* End of Switch: '<S17>/Switch' */
  UNUSED_PARAMETER(tid);
}

/* Update for root system: '<Root>' */
void MdlUpdate(int_T tid)
{
  /* Update for Integrator: '<Root>/Integrator' */
  rtDW.Integrator_IWORK = 0;
  if (ssIsSampleHit(rtS, 1, 0)) {
    /* Update for UnitDelay: '<S2>/UD' incorporates:
     *  Inport: '<Root>/Time Velocity Vectors'
     */
    rtDW.UD_DSTATE = rtU.vel;
  }

  UNUSED_PARAMETER(tid);
}

/* Derivatives for root system: '<Root>' */
void MdlDerivatives(void)
{
  XDot *_rtXdot;
  _rtXdot = ((XDot *) ssGetdX(rtS));

  /* Derivatives for Integrator: '<Root>/Integrator' incorporates:
   *  Inport: '<Root>/Time Velocity Vectors'
   */
  _rtXdot->Integrator_CSTATE = rtU.vel;

  /* Derivatives for Integrator: '<S10>/Integrator' */
  _rtXdot->Integrator_CSTATE_a = rtB.Switch_m;

  /* Derivatives for Integrator: '<Root>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = rtB.Switch_h;

  /* Derivatives for Integrator: '<Root>/Integrator2' */
  _rtXdot->Integrator2_CSTATE = rtB.Abs_h;
}

/* Projection for root system: '<Root>' */
void MdlProjection(void)
{
}

/* Termination for root system: '<Root>' */
void MdlTerminate(void)
{
  /* Terminate for MATLABSystem: '<S9>/Moving Maximum' */
  matlabCodegenHandle_matlabCo_or(&rtDW.obj_g);

  /* Terminate for MATLABSystem: '<Root>/Moving Minimum1' */
  matlabCodegenHandle_matlabCod_o(&rtDW.obj);
  rs_bicycle_MovingMaximum3_Term(&rtDW.MovingMaximum);
  rs_bicycle_MovingMaximum3_Term(&rtDW.MovingMaximum2);
  rs_bicycle_MovingMaximum3_Term(&rtDW.MovingMaximum1);
  rs_bicycle_MovingMaximum3_Term(&rtDW.MovingMaximum3);
}

/* Function to initialize sizes */
void MdlInitializeSizes(void)
{
  ssSetNumContStates(rtS, 4);          /* Number of continuous states */
  ssSetNumPeriodicContStates(rtS, 0); /* Number of periodic continuous states */
  ssSetNumY(rtS, 13);                  /* Number of model outputs */
  ssSetNumU(rtS, 1);                   /* Number of model inputs */
  ssSetDirectFeedThrough(rtS, 1);      /* The model is direct feedthrough */
  ssSetNumSampleTimes(rtS, 2);         /* Number of sample times */
  ssSetNumBlocks(rtS, 103);            /* Number of blocks */
  ssSetNumBlockIO(rtS, 66);            /* Number of block outputs */
  ssSetNumBlockParams(rtS, 37);        /* Sum of parameter "widths" */
}

/* Function to initialize sample times. */
void MdlInitializeSampleTimes(void)
{
  /* task periods */
  ssSetSampleTime(rtS, 0, 0.0);
  ssSetSampleTime(rtS, 1, 4.0);

  /* task offsets */
  ssSetOffsetTime(rtS, 0, 0.0);
  ssSetOffsetTime(rtS, 1, 0.0);
}

/* Function to register the model */
/* Turns off all optimizations on Windows because of issues with VC 2015 compiler.
   This function is not performance-critical, hence this is not a problem.
 */
#if defined(_MSC_VER)

#pragma optimize( "", off )

#endif

SimStruct * rs_bicycle(void)
{
  static struct _ssMdlInfo mdlInfo;
  (void) memset((char *)rtS, 0,
                sizeof(SimStruct));
  (void) memset((char *)&mdlInfo, 0,
                sizeof(struct _ssMdlInfo));
  ssSetMdlInfoPtr(rtS, &mdlInfo);

  /* timing info */
  {
    static time_T mdlPeriod[NSAMPLE_TIMES];
    static time_T mdlOffset[NSAMPLE_TIMES];
    static time_T mdlTaskTimes[NSAMPLE_TIMES];
    static int_T mdlTsMap[NSAMPLE_TIMES];
    static int_T mdlSampleHits[NSAMPLE_TIMES];

    {
      int_T i;
      for (i = 0; i < NSAMPLE_TIMES; i++) {
        mdlPeriod[i] = 0.0;
        mdlOffset[i] = 0.0;
        mdlTaskTimes[i] = 0.0;
        mdlTsMap[i] = i;
        mdlSampleHits[i] = 1;
      }
    }

    ssSetSampleTimePtr(rtS, &mdlPeriod[0]);
    ssSetOffsetTimePtr(rtS, &mdlOffset[0]);
    ssSetSampleTimeTaskIDPtr(rtS, &mdlTsMap[0]);
    ssSetTPtr(rtS, &mdlTaskTimes[0]);
    ssSetSampleHitPtr(rtS, &mdlSampleHits[0]);
  }

  ssSetSolverMode(rtS, SOLVER_MODE_SINGLETASKING);

  /*
   * initialize model vectors and cache them in SimStruct
   */

  /* block I/O */
  {
    ssSetBlockIO(rtS, ((void *) &rtB));
    (void) memset(((void *) &rtB), 0,
                  sizeof(B));
  }

  /* external inputs */
  {
    ssSetU(rtS, ((void*) &rtU));
    rtU.vel = 0.0;
  }

  /* external outputs */
  {
    ssSetY(rtS, &rtY);
    (void) memset((void *)&rtY, 0,
                  sizeof(ExtY));
  }

  /* states (continuous)*/
  {
    real_T *x = (real_T *) &rtX;
    ssSetContStates(rtS, x);
    (void) memset((void *)x, 0,
                  sizeof(X));
  }

  /* states (dwork) */
  {
    void *dwork = (void *) &rtDW;
    ssSetRootDWork(rtS, dwork);
    (void) memset(dwork, 0,
                  sizeof(DW));
  }

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    ssSetModelMappingInfo(rtS, &dtInfo);
    dtInfo.numDataTypes = 20;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Model specific registration */
  ssSetRootSS(rtS, rtS);
  ssSetVersion(rtS, SIMSTRUCT_VERSION_LEVEL2);
  ssSetModelName(rtS, "rs_bicycle");
  ssSetPath(rtS, "rs_bicycle");
  ssSetTStart(rtS, 0.0);
  ssSetTFinal(rtS, 200.0);
  ssSetStepSize(rtS, 4.0);
  ssSetFixedStepSize(rtS, 4.0);

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    ssSetRTWLogInfo(rtS, &rt_DataLoggingInfo);
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(ssGetRTWLogInfo(rtS), (NULL));
    rtliSetLogXSignalPtrs(ssGetRTWLogInfo(rtS), (NULL));
    rtliSetLogT(ssGetRTWLogInfo(rtS), "");
    rtliSetLogX(ssGetRTWLogInfo(rtS), "");
    rtliSetLogXFinal(ssGetRTWLogInfo(rtS), "");
    rtliSetLogVarNameModifier(ssGetRTWLogInfo(rtS), "rt_");
    rtliSetLogFormat(ssGetRTWLogInfo(rtS), 0);
    rtliSetLogMaxRows(ssGetRTWLogInfo(rtS), 0);
    rtliSetLogDecimation(ssGetRTWLogInfo(rtS), 1);

    /*
     * Set pointers to the data and signal info for each output
     */
    {
      static void * rt_LoggedOutputSignalPtrs[] = {
        &rtY.F[0],
        &rtY.S[0]
      };

      rtliSetLogYSignalPtrs(ssGetRTWLogInfo(rtS), ((LogSignalPtrsType)
        rt_LoggedOutputSignalPtrs));
    }

    {
      static int_T rt_LoggedOutputWidths[] = {
        10,
        3
      };

      static int_T rt_LoggedOutputNumDimensions[] = {
        1,
        1
      };

      static int_T rt_LoggedOutputDimensions[] = {
        10,
        3
      };

      static boolean_T rt_LoggedOutputIsVarDims[] = {
        0,
        0
      };

      static void* rt_LoggedCurrentSignalDimensions[] = {
        (NULL),
        (NULL)
      };

      static int_T rt_LoggedCurrentSignalDimensionsSize[] = {
        4,
        4
      };

      static BuiltInDTypeId rt_LoggedOutputDataTypeIds[] = {
        SS_DOUBLE,
        SS_DOUBLE
      };

      static int_T rt_LoggedOutputComplexSignals[] = {
        0,
        0
      };

      static RTWPreprocessingFcnPtr rt_LoggingPreprocessingFcnPtrs[] = {
        (NULL),
        (NULL)
      };

      static const char_T *rt_LoggedOutputLabels_0[] = { "" };

      static const char_T *rt_LoggedOutputBlockNames_0[] = { "rs_bicycle/F" };

      static const char_T *rt_LoggedOutputLabels_1[] = { "S" };

      static const char_T *rt_LoggedOutputBlockNames_1[] = { "rs_bicycle/S" };

      static RTWLogDataTypeConvert rt_RTWLogDataTypeConvert[] = {
        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 }
      };

      static RTWLogSignalInfo rt_LoggedOutputSignalInfo[] = {
        {
          1,
          rt_LoggedOutputWidths,
          rt_LoggedOutputNumDimensions,
          rt_LoggedOutputDimensions,
          rt_LoggedOutputIsVarDims,
          rt_LoggedCurrentSignalDimensions,
          rt_LoggedCurrentSignalDimensionsSize,
          rt_LoggedOutputDataTypeIds,
          rt_LoggedOutputComplexSignals,
          (NULL),
          rt_LoggingPreprocessingFcnPtrs,

          { rt_LoggedOutputLabels_0 },
          (NULL),
          (NULL),
          (NULL),

          { rt_LoggedOutputBlockNames_0 },

          { (NULL) },
          (NULL),
          rt_RTWLogDataTypeConvert
        },

        {
          1,
          rt_LoggedOutputWidths+1,
          rt_LoggedOutputNumDimensions+1,
          rt_LoggedOutputDimensions+1,
          rt_LoggedOutputIsVarDims+1,
          rt_LoggedCurrentSignalDimensions+1,
          rt_LoggedCurrentSignalDimensionsSize+1,
          rt_LoggedOutputDataTypeIds+1,
          rt_LoggedOutputComplexSignals+1,
          (NULL),
          rt_LoggingPreprocessingFcnPtrs+1,

          { rt_LoggedOutputLabels_1 },
          (NULL),
          (NULL),
          (NULL),

          { rt_LoggedOutputBlockNames_1 },

          { (NULL) },
          (NULL),
          rt_RTWLogDataTypeConvert+1
        }
      };

      rtliSetLogYSignalInfo(ssGetRTWLogInfo(rtS), rt_LoggedOutputSignalInfo);

      /* set currSigDims field */
      rt_LoggedCurrentSignalDimensions[0] = &rt_LoggedOutputWidths[0];
      rt_LoggedCurrentSignalDimensions[1] = &rt_LoggedOutputWidths[1];
    }

    rtliSetLogY(ssGetRTWLogInfo(rtS), "F,S");
  }

  {
    static struct _ssStatesInfo2 statesInfo2;
    ssSetStatesInfo2(rtS, &statesInfo2);
  }

  {
    static ssPeriodicStatesInfo periodicStatesInfo;
    ssSetPeriodicStatesInfo(rtS, &periodicStatesInfo);
  }

  ssSetChecksumVal(rtS, 0, 3655097565U);
  ssSetChecksumVal(rtS, 1, 2286547166U);
  ssSetChecksumVal(rtS, 2, 4195750601U);
  ssSetChecksumVal(rtS, 3, 3478017694U);
  return rtS;
}

/* When you use the on parameter, it resets the optimizations to those that you
   specified with the /O compiler option. */
#if defined(_MSC_VER)

#pragma optimize( "", on )

#endif
