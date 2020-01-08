/*
 * attitude3d.c
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

#include <math.h>
#include "attitude3d.h"
#include "attitude3d_private.h"
#include "attitude3d_dt.h"

/* user code (top of parameter file) */
const int_T gblNumToFiles = 0;
const int_T gblNumFrFiles = 1;
const int_T gblNumFrWksBlocks = 0;
const char *gblSlvrJacPatternFileName =
  "attitude3d_rsim_rtw//attitude3d_Jpattern.mat";

/* Root inports information  */
const int_T gblNumRootInportBlks = 1;
const int_T gblNumModelInputs = 3;
extern rtInportTUtable *gblInportTUtables;
extern const char *gblInportFileName;
const int_T gblInportDataTypeIdx[] = { 0 };

const int_T gblInportDims[] = { 3, 1 } ;

const int_T gblInportComplex[] = { 0 };

const int_T gblInportInterpoFlag[] = { 1 };

const int_T gblInportContinuous[] = { 1 };

FrFInfo attitude3d_gblFrFInfo[1];

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

/* Parent Simstruct */
static SimStruct model_S;
SimStruct *const rtS = &model_S;

/* Forward declaration for local functions */
static void attitude3d_SystemCore_release(dsp_MovingMinimum_attitude3d_T *obj);
static void attitude3d_SystemCore_delete(dsp_MovingMinimum_attitude3d_T *obj);
static void matlabCodegenHandle_matlabCodeg(dsp_MovingMinimum_attitude3d_T *obj);

/* Forward declaration for local functions */
static void attitude3d_SystemCore_release_m(dsp_MovingMaximum_attitude3d_T *obj);
static void attitude3d_SystemCore_delete_a(dsp_MovingMaximum_attitude3d_T *obj);
static void matlabCodegenHandle_matlabCod_g(dsp_MovingMaximum_attitude3d_T *obj);
static void attitude3d_SystemCore_release(dsp_MovingMinimum_attitude3d_T *obj)
{
  dsp_private_RunningMinimum_at_T *obj_0;
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    obj->NumChannels = -1;
    obj_0 = obj->pStat;
    if (obj_0->isInitialized == 1) {
      obj_0->isInitialized = 2;
    }
  }
}

static void attitude3d_SystemCore_delete(dsp_MovingMinimum_attitude3d_T *obj)
{
  attitude3d_SystemCore_release(obj);
}

static void matlabCodegenHandle_matlabCodeg(dsp_MovingMinimum_attitude3d_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    attitude3d_SystemCore_delete(obj);
  }
}

/*
 * System initialize for atomic system:
 *    synthesized block
 *    synthesized block
 */
void attitude3d_MovingMinimum_Init(DW_MovingMinimum_attitude3d_T *localDW)
{
  /* InitializeConditions for MATLABSystem: '<S4>/Moving Minimum' */
  if (localDW->obj.pStat->isInitialized == 1) {
    localDW->obj.pStat->pCumMin = (rtInf);
  }

  /* End of InitializeConditions for MATLABSystem: '<S4>/Moving Minimum' */
}

/*
 * Start for atomic system:
 *    synthesized block
 *    synthesized block
 */
void attitude3d_MovingMinimum_Start(DW_MovingMinimum_attitude3d_T *localDW)
{
  /* Start for MATLABSystem: '<S4>/Moving Minimum' */
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
  localDW->obj.NumChannels = 1;
  localDW->gobj_0.isInitialized = 0;
  localDW->obj.pStat = &localDW->gobj_0;
  localDW->obj.pStat->isSetupComplete = false;
  localDW->obj.pStat->isInitialized = 1;
  localDW->obj.pStat->pCumMin = (rtInf);
  localDW->obj.pStat->isSetupComplete = true;
  localDW->obj.isSetupComplete = true;
}

/*
 * Output and update for atomic system:
 *    synthesized block
 *    synthesized block
 */
void attitude3d_MovingMinimum(real_T rtu_0, B_MovingMinimum_attitude3d_T *localB,
  DW_MovingMinimum_attitude3d_T *localDW)
{
  real_T y_idx_1;

  /* MATLABSystem: '<S4>/Moving Minimum' */
  if (localDW->obj.pStat->isInitialized != 1) {
    localDW->obj.pStat->isSetupComplete = false;
    localDW->obj.pStat->isInitialized = 1;
    localDW->obj.pStat->pCumMin = (rtInf);
    localDW->obj.pStat->isSetupComplete = true;
    localDW->obj.pStat->pCumMin = (rtInf);
  }

  y_idx_1 = localDW->obj.pStat->pCumMin;
  y_idx_1 = fmin(y_idx_1, rtu_0);
  localDW->obj.pStat->pCumMin = y_idx_1;
  localB->MovingMinimum = y_idx_1;

  /* End of MATLABSystem: '<S4>/Moving Minimum' */
}

/*
 * Termination for atomic system:
 *    synthesized block
 *    synthesized block
 */
void attitude3d_MovingMinimum_Term(DW_MovingMinimum_attitude3d_T *localDW)
{
  /* Terminate for MATLABSystem: '<S4>/Moving Minimum' */
  matlabCodegenHandle_matlabCodeg(&localDW->obj);
}

static void attitude3d_SystemCore_release_m(dsp_MovingMaximum_attitude3d_T *obj)
{
  dsp_private_RunningMaximum_at_T *obj_0;
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    obj->NumChannels = -1;
    obj_0 = obj->pStat;
    if (obj_0->isInitialized == 1) {
      obj_0->isInitialized = 2;
    }
  }
}

static void attitude3d_SystemCore_delete_a(dsp_MovingMaximum_attitude3d_T *obj)
{
  attitude3d_SystemCore_release_m(obj);
}

static void matlabCodegenHandle_matlabCod_g(dsp_MovingMaximum_attitude3d_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    attitude3d_SystemCore_delete_a(obj);
  }
}

/*
 * System initialize for atomic system:
 *    synthesized block
 *    synthesized block
 */
void attitude3d_MovingMaximum_Init(DW_MovingMaximum_attitude3d_T *localDW)
{
  /* InitializeConditions for MATLABSystem: '<S6>/Moving Maximum' */
  if (localDW->obj.pStat->isInitialized == 1) {
    localDW->obj.pStat->pCumMax = (rtMinusInf);
  }

  /* End of InitializeConditions for MATLABSystem: '<S6>/Moving Maximum' */
}

/*
 * Start for atomic system:
 *    synthesized block
 *    synthesized block
 */
void attitude3d_MovingMaximum_Start(DW_MovingMaximum_attitude3d_T *localDW)
{
  /* Start for MATLABSystem: '<S6>/Moving Maximum' */
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
  localDW->obj.NumChannels = 1;
  localDW->gobj_0.isInitialized = 0;
  localDW->obj.pStat = &localDW->gobj_0;
  localDW->obj.pStat->isSetupComplete = false;
  localDW->obj.pStat->isInitialized = 1;
  localDW->obj.pStat->pCumMax = (rtMinusInf);
  localDW->obj.pStat->isSetupComplete = true;
  localDW->obj.isSetupComplete = true;
}

/*
 * Output and update for atomic system:
 *    synthesized block
 *    synthesized block
 */
void attitude3d_MovingMaximum(real_T rtu_0, B_MovingMaximum_attitude3d_T *localB,
  DW_MovingMaximum_attitude3d_T *localDW)
{
  real_T y_idx_1;

  /* MATLABSystem: '<S6>/Moving Maximum' */
  if (localDW->obj.pStat->isInitialized != 1) {
    localDW->obj.pStat->isSetupComplete = false;
    localDW->obj.pStat->isInitialized = 1;
    localDW->obj.pStat->pCumMax = (rtMinusInf);
    localDW->obj.pStat->isSetupComplete = true;
    localDW->obj.pStat->pCumMax = (rtMinusInf);
  }

  y_idx_1 = localDW->obj.pStat->pCumMax;
  y_idx_1 = fmax(y_idx_1, rtu_0);
  localDW->obj.pStat->pCumMax = y_idx_1;
  localB->MovingMaximum = y_idx_1;

  /* End of MATLABSystem: '<S6>/Moving Maximum' */
}

/*
 * Termination for atomic system:
 *    synthesized block
 *    synthesized block
 */
void attitude3d_MovingMaximum_Term(DW_MovingMaximum_attitude3d_T *localDW)
{
  /* Terminate for MATLABSystem: '<S6>/Moving Maximum' */
  matlabCodegenHandle_matlabCod_g(&localDW->obj);
}

/* System initialize for root system: '<Root>' */
void MdlInitialize(void)
{
  int32_T i;

  /* InitializeConditions for Integrator: '<S3>/Integrator' */
  if (ssIsFirstInitCond(rtS)) {
    rtX.Integrator_CSTATE[0] = 0.0;
    rtX.Integrator_CSTATE[1] = 0.0;
    rtX.Integrator_CSTATE[2] = 0.0;
    rtX.Integrator_CSTATE[3] = 0.0;
  }

  rtDW.Integrator_IWORK = 1;

  /* End of InitializeConditions for Integrator: '<S3>/Integrator' */
  for (i = 0; i < 59; i++) {
    /* InitializeConditions for DiscreteFir: '<S26>/Discrete FIR Filter' */
    rtDW.DiscreteFIRFilter_states[i] = rtP.DiscreteFIRFilter_InitialStates;

    /* InitializeConditions for DiscreteFir: '<S29>/Discrete FIR Filter' */
    rtDW.DiscreteFIRFilter_states_k[i] = rtP.DiscreteFIRFilter_InitialStat_i;
  }

  /* InitializeConditions for Integrator: '<S11>/Integrator1' */
  rtX.Integrator1_CSTATE = rtP.Integrator1_IC;

  /* InitializeConditions for Integrator: '<S10>/Integrator1' */
  rtX.Integrator1_CSTATE_a = rtP.Integrator1_IC_k;

  /* InitializeConditions for Integrator: '<S9>/Integrator2' */
  rtX.Integrator2_CSTATE = rtP.Integrator2_IC;

  /* InitializeConditions for Integrator: '<S9>/Integrator1' */
  rtX.Integrator1_CSTATE_f = rtP.Integrator1_IC_b;
  attitude3d_MovingMinimum_Init(&rtDW.MovingMinimum);
  attitude3d_MovingMinimum_Init(&rtDW.MovingMinimum_p);
  attitude3d_MovingMaximum_Init(&rtDW.MovingMaximum);
  attitude3d_MovingMaximum_Init(&rtDW.MovingMaximum_p);
}

/* Start for root system: '<Root>' */
void MdlStart(void)
{
  /* Start for FromFile: '<Root>/From File13' */
  {
    char fileName[509] = "ENVIRONMENT.mat";
    rt_RSimRemapFromFileName(fileName);

    {
      void *fp = (NULL);
      const char *errMsg = (NULL);
      errMsg = rtwMatFileLoaderCollectionCreateInstance( 0, &fp );
      if (errMsg != (NULL)) {
        ssSetErrorStatus(rtS, errMsg);
        return;
      }

      rtDW.FromFile13_PWORK.PrevTimePtr = fp;

      {
        unsigned char groundValue[] = { 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U } ;

        const int enumNStrings = 0;
        const char **enumStrings = (NULL);
        const int32_T *enumValues = (NULL);
        int_T dimensions[1] = { 3 };

        errMsg = rtwMatFileLoaderCollectionAddElement(0, fp, fileName,
          ".thrust_vector", 0, 0, 0, 0, groundValue, "double", 0, 1, dimensions,
          0, 0, 0, 0, 0, 0, 0, 0, enumNStrings, enumStrings, enumValues, 1, 1,
          "attitude3d/From File13" );
        if (errMsg != (NULL)) {
          ssSetErrorStatus(rtS, errMsg);
          return;
        }
      }

      {
        unsigned char groundValue[] = { 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U } ;

        const int enumNStrings = 0;
        const char **enumStrings = (NULL);
        const int32_T *enumValues = (NULL);
        int_T dimensions[1] = { 1 };

        errMsg = rtwMatFileLoaderCollectionAddElement(0, fp, fileName,
          ".thrust_weight", 0, 0, 0, 0, groundValue, "double", 0, 1, dimensions,
          0, 0, 0, 0, 0, 0, 0, 0, enumNStrings, enumStrings, enumValues, 1, 1,
          "attitude3d/From File13" );
        if (errMsg != (NULL)) {
          ssSetErrorStatus(rtS, errMsg);
          return;
        }
      }

      {
        unsigned char groundValue[] = { 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U } ;

        const int enumNStrings = 0;
        const char **enumStrings = (NULL);
        const int32_T *enumValues = (NULL);
        int_T dimensions[1] = { 1 };

        errMsg = rtwMatFileLoaderCollectionAddElement(0, fp, fileName,
          ".solar_occulted_integral", 0, 0, 0, 0, groundValue, "double", 0, 1,
          dimensions, 0, 0, 0, 0, 0, 0, 0, 0, enumNStrings, enumStrings,
          enumValues, 1, 1, "attitude3d/From File13" );
        if (errMsg != (NULL)) {
          ssSetErrorStatus(rtS, errMsg);
          return;
        }
      }

      {
        unsigned char groundValue[] = { 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U } ;

        const int enumNStrings = 0;
        const char **enumStrings = (NULL);
        const int32_T *enumValues = (NULL);
        int_T dimensions[1] = { 1 };

        errMsg = rtwMatFileLoaderCollectionAddElement(0, fp, fileName,
          ".solar_occulted_boolean", 0, 0, 0, 0, groundValue, "double", 0, 1,
          dimensions, 0, 0, 0, 0, 0, 0, 0, 0, enumNStrings, enumStrings,
          enumValues, 1, 1, "attitude3d/From File13" );
        if (errMsg != (NULL)) {
          ssSetErrorStatus(rtS, errMsg);
          return;
        }
      }

      {
        unsigned char groundValue[] = { 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U } ;

        const int enumNStrings = 0;
        const char **enumStrings = (NULL);
        const int32_T *enumValues = (NULL);
        int_T dimensions[1] = { 3 };

        errMsg = rtwMatFileLoaderCollectionAddElement(0, fp, fileName,
          ".solar_vector", 0, 0, 0, 0, groundValue, "double", 0, 1, dimensions,
          0, 0, 0, 0, 0, 0, 0, 0, enumNStrings, enumStrings, enumValues, 1, 1,
          "attitude3d/From File13" );
        if (errMsg != (NULL)) {
          ssSetErrorStatus(rtS, errMsg);
          return;
        }
      }

      {
        unsigned char groundValue[] = { 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U } ;

        const int enumNStrings = 0;
        const char **enumStrings = (NULL);
        const int32_T *enumValues = (NULL);
        int_T dimensions[1] = { 1 };

        errMsg = rtwMatFileLoaderCollectionAddElement(0, fp, fileName,
          ".comms_occulted_integral", 0, 0, 0, 0, groundValue, "double", 0, 1,
          dimensions, 0, 0, 0, 0, 0, 0, 0, 0, enumNStrings, enumStrings,
          enumValues, 1, 1, "attitude3d/From File13" );
        if (errMsg != (NULL)) {
          ssSetErrorStatus(rtS, errMsg);
          return;
        }
      }

      {
        unsigned char groundValue[] = { 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U } ;

        const int enumNStrings = 0;
        const char **enumStrings = (NULL);
        const int32_T *enumValues = (NULL);
        int_T dimensions[1] = { 1 };

        errMsg = rtwMatFileLoaderCollectionAddElement(0, fp, fileName,
          ".comms_occulted_boolean", 0, 0, 0, 0, groundValue, "double", 0, 1,
          dimensions, 0, 0, 0, 0, 0, 0, 0, 0, enumNStrings, enumStrings,
          enumValues, 1, 1, "attitude3d/From File13" );
        if (errMsg != (NULL)) {
          ssSetErrorStatus(rtS, errMsg);
          return;
        }
      }

      {
        unsigned char groundValue[] = { 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U } ;

        const int enumNStrings = 0;
        const char **enumStrings = (NULL);
        const int32_T *enumValues = (NULL);
        int_T dimensions[1] = { 3 };

        errMsg = rtwMatFileLoaderCollectionAddElement(0, fp, fileName,
          ".comms_vector", 0, 0, 0, 0, groundValue, "double", 0, 1, dimensions,
          0, 0, 0, 0, 0, 0, 0, 0, enumNStrings, enumStrings, enumValues, 1, 1,
          "attitude3d/From File13" );
        if (errMsg != (NULL)) {
          ssSetErrorStatus(rtS, errMsg);
          return;
        }
      }

      {
        unsigned char groundValue[] = { 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U } ;

        const int enumNStrings = 0;
        const char **enumStrings = (NULL);
        const int32_T *enumValues = (NULL);
        int_T dimensions[1] = { 3 };

        errMsg = rtwMatFileLoaderCollectionAddElement(0, fp, fileName, ".r_s", 0,
          0, 0, 0, groundValue, "double", 0, 1, dimensions, 0, 0, 0, 0, 0, 0, 0,
          0, enumNStrings, enumStrings, enumValues, 1, 1,
          "attitude3d/From File13" );
        if (errMsg != (NULL)) {
          ssSetErrorStatus(rtS, errMsg);
          return;
        }
      }

      {
        unsigned char groundValue[] = { 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U } ;

        const int enumNStrings = 0;
        const char **enumStrings = (NULL);
        const int32_T *enumValues = (NULL);
        int_T dimensions[1] = { 3 };

        errMsg = rtwMatFileLoaderCollectionAddElement(0, fp, fileName, ".v_s", 0,
          0, 0, 0, groundValue, "double", 0, 1, dimensions, 0, 0, 0, 0, 0, 0, 0,
          0, enumNStrings, enumStrings, enumValues, 1, 1,
          "attitude3d/From File13" );
        if (errMsg != (NULL)) {
          ssSetErrorStatus(rtS, errMsg);
          return;
        }
      }

      {
        unsigned char groundValue[] = { 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U } ;

        const int enumNStrings = 0;
        const char **enumStrings = (NULL);
        const int32_T *enumValues = (NULL);
        int_T dimensions[1] = { 3 };

        errMsg = rtwMatFileLoaderCollectionAddElement(0, fp, fileName, ".r_c", 0,
          0, 0, 0, groundValue, "double", 0, 1, dimensions, 0, 0, 0, 0, 0, 0, 0,
          0, enumNStrings, enumStrings, enumValues, 1, 1,
          "attitude3d/From File13" );
        if (errMsg != (NULL)) {
          ssSetErrorStatus(rtS, errMsg);
          return;
        }
      }

      {
        unsigned char groundValue[] = { 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U } ;

        const int enumNStrings = 0;
        const char **enumStrings = (NULL);
        const int32_T *enumValues = (NULL);
        int_T dimensions[1] = { 3 };

        errMsg = rtwMatFileLoaderCollectionAddElement(0, fp, fileName, ".v_c", 0,
          0, 0, 0, groundValue, "double", 0, 1, dimensions, 0, 0, 0, 0, 0, 0, 0,
          0, enumNStrings, enumStrings, enumValues, 1, 1,
          "attitude3d/From File13" );
        if (errMsg != (NULL)) {
          ssSetErrorStatus(rtS, errMsg);
          return;
        }
      }

      {
        unsigned char groundValue[] = { 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U } ;

        const int enumNStrings = 0;
        const char **enumStrings = (NULL);
        const int32_T *enumValues = (NULL);
        int_T dimensions[1] = { 3 };

        errMsg = rtwMatFileLoaderCollectionAddElement(0, fp, fileName, ".r_t", 0,
          0, 0, 0, groundValue, "double", 0, 1, dimensions, 0, 0, 0, 0, 0, 0, 0,
          0, enumNStrings, enumStrings, enumValues, 1, 1,
          "attitude3d/From File13" );
        if (errMsg != (NULL)) {
          ssSetErrorStatus(rtS, errMsg);
          return;
        }
      }

      {
        unsigned char groundValue[] = { 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U } ;

        const int enumNStrings = 0;
        const char **enumStrings = (NULL);
        const int32_T *enumValues = (NULL);
        int_T dimensions[1] = { 3 };

        errMsg = rtwMatFileLoaderCollectionAddElement(0, fp, fileName, ".v_t", 0,
          0, 0, 0, groundValue, "double", 0, 1, dimensions, 0, 0, 0, 0, 0, 0, 0,
          0, enumNStrings, enumStrings, enumValues, 1, 1,
          "attitude3d/From File13" );
        if (errMsg != (NULL)) {
          ssSetErrorStatus(rtS, errMsg);
          return;
        }
      }
    }
  }

  attitude3d_MovingMinimum_Start(&rtDW.MovingMinimum);
  attitude3d_MovingMinimum_Start(&rtDW.MovingMinimum_p);
  attitude3d_MovingMaximum_Start(&rtDW.MovingMaximum);
  attitude3d_MovingMaximum_Start(&rtDW.MovingMaximum_p);
  MdlInitialize();
}

/* Outputs for root system: '<Root>' */
void MdlOutputs(int_T tid)
{
  /* local block i/o variables */
  real_T rtb_Divide1;
  real_T rtb_Divide1_k;
  real_T A[4];
  int32_T idx;
  int32_T k;
  real_T t;
  real_T rtb_Product5;
  real_T rtb_qA2B_idx_2;
  real_T rtb_Divide_o_idx_0;
  real_T rtb_Divide_o_idx_1;
  real_T rtb_Divide_o_idx_2;
  real_T rtb_Gain1_d_idx_0;
  real_T rtb_Gain1_d_idx_2;
  real_T rtb_Gain1_d_idx_1;
  real_T rtb_vector_idx_0;
  real_T rtb_vector_idx_1;
  real_T rtb_vector_idx_2;
  boolean_T exitg1;

  /* Read data from the mat file of inport block */
  if (gblInportFileName != (NULL)) {
    int_T currTimeIdx;
    int_T i;

    /*
     *  Read in data from mat file for root inport omega
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
          for (i = 0; i < 3; i++) {
            real_T* realPtr1 = (real_T*)gblInportTUtables[0].ur +
              i*gblInportTUtables[0].nTimePoints +currTimeIdx;
            real_T* realPtr2 = realPtr1 + 1*k;
            (void)rt_Interpolate_Datatype(
              realPtr1,
              realPtr2,
              &rtU.omega[i],
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
  }

  /* FromFile: '<Root>/From File13' */
  {
    void *fp = (void *) rtDW.FromFile13_PWORK.PrevTimePtr;
    const char *errMsg = (NULL);
    if (fp != (NULL) && (ssIsMajorTimeStep(rtS) || !0) ) {
      real_T t = ssGetTaskTime(rtS,0);

      {
        void *y = &rtB.E.thrust_vector;
        errMsg = rtwMatFileLoaderCollectionGetOutput( 0, fp, 0, t,
          ssIsMajorTimeStep(rtS), &y );
        if (errMsg != (NULL)) {
          ssSetErrorStatus(rtS, errMsg);
          return;
        }
      }

      {
        void *y = &rtB.E.thrust_weight;
        errMsg = rtwMatFileLoaderCollectionGetOutput( 0, fp, 1, t,
          ssIsMajorTimeStep(rtS), &y );
        if (errMsg != (NULL)) {
          ssSetErrorStatus(rtS, errMsg);
          return;
        }
      }

      {
        void *y = &rtB.E.solar_occulted_integral;
        errMsg = rtwMatFileLoaderCollectionGetOutput( 0, fp, 2, t,
          ssIsMajorTimeStep(rtS), &y );
        if (errMsg != (NULL)) {
          ssSetErrorStatus(rtS, errMsg);
          return;
        }
      }

      {
        void *y = &rtB.E.solar_occulted_boolean;
        errMsg = rtwMatFileLoaderCollectionGetOutput( 0, fp, 3, t,
          ssIsMajorTimeStep(rtS), &y );
        if (errMsg != (NULL)) {
          ssSetErrorStatus(rtS, errMsg);
          return;
        }
      }

      {
        void *y = &rtB.E.solar_vector;
        errMsg = rtwMatFileLoaderCollectionGetOutput( 0, fp, 4, t,
          ssIsMajorTimeStep(rtS), &y );
        if (errMsg != (NULL)) {
          ssSetErrorStatus(rtS, errMsg);
          return;
        }
      }

      {
        void *y = &rtB.E.comms_occulted_integral;
        errMsg = rtwMatFileLoaderCollectionGetOutput( 0, fp, 5, t,
          ssIsMajorTimeStep(rtS), &y );
        if (errMsg != (NULL)) {
          ssSetErrorStatus(rtS, errMsg);
          return;
        }
      }

      {
        void *y = &rtB.E.comms_occulted_boolean;
        errMsg = rtwMatFileLoaderCollectionGetOutput( 0, fp, 6, t,
          ssIsMajorTimeStep(rtS), &y );
        if (errMsg != (NULL)) {
          ssSetErrorStatus(rtS, errMsg);
          return;
        }
      }

      {
        void *y = &rtB.E.comms_vector;
        errMsg = rtwMatFileLoaderCollectionGetOutput( 0, fp, 7, t,
          ssIsMajorTimeStep(rtS), &y );
        if (errMsg != (NULL)) {
          ssSetErrorStatus(rtS, errMsg);
          return;
        }
      }

      {
        void *y = &rtB.E.r_s;
        errMsg = rtwMatFileLoaderCollectionGetOutput( 0, fp, 8, t,
          ssIsMajorTimeStep(rtS), &y );
        if (errMsg != (NULL)) {
          ssSetErrorStatus(rtS, errMsg);
          return;
        }
      }

      {
        void *y = &rtB.E.v_s;
        errMsg = rtwMatFileLoaderCollectionGetOutput( 0, fp, 9, t,
          ssIsMajorTimeStep(rtS), &y );
        if (errMsg != (NULL)) {
          ssSetErrorStatus(rtS, errMsg);
          return;
        }
      }

      {
        void *y = &rtB.E.r_c;
        errMsg = rtwMatFileLoaderCollectionGetOutput( 0, fp, 10, t,
          ssIsMajorTimeStep(rtS), &y );
        if (errMsg != (NULL)) {
          ssSetErrorStatus(rtS, errMsg);
          return;
        }
      }

      {
        void *y = &rtB.E.v_c;
        errMsg = rtwMatFileLoaderCollectionGetOutput( 0, fp, 11, t,
          ssIsMajorTimeStep(rtS), &y );
        if (errMsg != (NULL)) {
          ssSetErrorStatus(rtS, errMsg);
          return;
        }
      }

      {
        void *y = &rtB.E.r_t;
        errMsg = rtwMatFileLoaderCollectionGetOutput( 0, fp, 12, t,
          ssIsMajorTimeStep(rtS), &y );
        if (errMsg != (NULL)) {
          ssSetErrorStatus(rtS, errMsg);
          return;
        }
      }

      {
        void *y = &rtB.E.v_t;
        errMsg = rtwMatFileLoaderCollectionGetOutput( 0, fp, 13, t,
          ssIsMajorTimeStep(rtS), &y );
        if (errMsg != (NULL)) {
          ssSetErrorStatus(rtS, errMsg);
          return;
        }
      }
    }
  }

  /* Sum: '<S20>/Sum of Elements' incorporates:
   *  Math: '<S20>/Math Function'
   */
  idx = 0;
  rtb_Product5 = (rtB.E.solar_vector[0] * rtB.E.solar_vector[0] +
                  rtB.E.solar_vector[1] * rtB.E.solar_vector[1]) +
    rtB.E.solar_vector[2] * rtB.E.solar_vector[2];

  /* Math: '<S20>/Math Function1' incorporates:
   *  Sum: '<S20>/Sum of Elements'
   *
   * About '<S20>/Math Function1':
   *  Operator: sqrt
   */
  if (rtb_Product5 < 0.0) {
    rtb_Product5 = -sqrt(fabs(rtb_Product5));
  } else {
    rtb_Product5 = sqrt(rtb_Product5);
  }

  /* End of Math: '<S20>/Math Function1' */

  /* Switch: '<S20>/Switch' incorporates:
   *  Constant: '<S20>/Constant'
   *  Product: '<S20>/Product'
   */
  if (rtb_Product5 > rtP.NormalizeVector_maxzero) {
    rtb_Gain1_d_idx_0 = rtB.E.solar_vector[0];
    rtb_Gain1_d_idx_1 = rtB.E.solar_vector[1];
    rtb_Gain1_d_idx_2 = rtB.E.solar_vector[2];
  } else {
    rtb_Gain1_d_idx_0 = rtB.E.solar_vector[0] * 0.0;
    rtb_Gain1_d_idx_1 = rtB.E.solar_vector[1] * 0.0;
    rtb_Gain1_d_idx_2 = rtB.E.solar_vector[2] * 0.0;
    rtb_Product5 = rtP.Constant_Value_p;
  }

  /* End of Switch: '<S20>/Switch' */

  /* Product: '<S20>/Divide' */
  rtb_vector_idx_0 = rtb_Gain1_d_idx_0 / rtb_Product5;
  rtb_vector_idx_1 = rtb_Gain1_d_idx_1 / rtb_Product5;
  rtb_vector_idx_2 = rtb_Gain1_d_idx_2 / rtb_Product5;
  if (ssIsSampleHit(rtS, 1, 0)) {
    /* MATLAB Function: '<S12>/MATLAB Function' incorporates:
     *  Constant: '<Root>/Constant5'
     *  Constant: '<Root>/Constant6'
     *  Constant: '<Root>/Constant7'
     */
    A[0] = (rtP.P_X.init_xBI[0] + rtP.P_X.init_yBI[1]) + rtP.P_X.init_zBI[2];
    A[1] = (rtP.P_X.init_xBI[0] - rtP.P_X.init_yBI[1]) - rtP.P_X.init_zBI[2];
    A[2] = (-rtP.P_X.init_xBI[0] + rtP.P_X.init_yBI[1]) - rtP.P_X.init_zBI[2];
    A[3] = (-rtP.P_X.init_xBI[0] - rtP.P_X.init_yBI[1]) + rtP.P_X.init_zBI[2];
    if (!rtIsNaN(A[0])) {
      idx = 1;
    } else {
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k < 5)) {
        if (!rtIsNaN(A[k - 1])) {
          idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }

    if (idx == 0) {
      idx = 1;
    } else {
      rtb_Product5 = A[idx - 1];
      for (k = idx; k < 4; k++) {
        if (rtb_Product5 < A[k]) {
          rtb_Product5 = A[k];
          idx = k + 1;
        }
      }
    }

    switch (idx) {
     case 1:
      rtb_Gain1_d_idx_1 = sqrt(A[0] + 1.0) * 0.5;
      rtb_Product5 = 1.0 / (4.0 * rtb_Gain1_d_idx_1);
      rtb_Gain1_d_idx_2 = (rtP.P_X.init_yBI[2] - rtP.P_X.init_zBI[1]) *
        rtb_Product5;
      rtb_qA2B_idx_2 = (rtP.P_X.init_zBI[0] - rtP.P_X.init_xBI[2]) *
        rtb_Product5;
      rtb_Gain1_d_idx_0 = (rtP.P_X.init_xBI[1] - rtP.P_X.init_yBI[0]) *
        rtb_Product5;
      break;

     case 2:
      rtb_Gain1_d_idx_2 = sqrt(A[1] + 1.0) * 0.5;
      rtb_Product5 = 1.0 / (4.0 * rtb_Gain1_d_idx_2);
      rtb_qA2B_idx_2 = (rtP.P_X.init_xBI[1] + rtP.P_X.init_yBI[0]) *
        rtb_Product5;
      rtb_Gain1_d_idx_0 = (rtP.P_X.init_zBI[0] + rtP.P_X.init_xBI[2]) *
        rtb_Product5;
      rtb_Gain1_d_idx_1 = (rtP.P_X.init_yBI[2] - rtP.P_X.init_zBI[1]) *
        rtb_Product5;
      break;

     case 3:
      rtb_qA2B_idx_2 = sqrt(A[2] + 1.0) * 0.5;
      rtb_Product5 = 1.0 / (4.0 * rtb_qA2B_idx_2);
      rtb_Gain1_d_idx_0 = (rtP.P_X.init_yBI[2] + rtP.P_X.init_zBI[1]) *
        rtb_Product5;
      rtb_Gain1_d_idx_1 = (rtP.P_X.init_zBI[0] - rtP.P_X.init_xBI[2]) *
        rtb_Product5;
      rtb_Gain1_d_idx_2 = (rtP.P_X.init_xBI[1] + rtP.P_X.init_yBI[0]) *
        rtb_Product5;
      break;

     default:
      rtb_Gain1_d_idx_0 = sqrt(A[3] + 1.0) * 0.5;
      rtb_Product5 = 1.0 / (4.0 * rtb_Gain1_d_idx_0);
      rtb_Gain1_d_idx_1 = (rtP.P_X.init_xBI[1] - rtP.P_X.init_yBI[0]) *
        rtb_Product5;
      rtb_Gain1_d_idx_2 = (rtP.P_X.init_zBI[0] + rtP.P_X.init_xBI[2]) *
        rtb_Product5;
      rtb_qA2B_idx_2 = (rtP.P_X.init_yBI[2] + rtP.P_X.init_zBI[1]) *
        rtb_Product5;
      break;
    }

    /* End of MATLAB Function: '<S12>/MATLAB Function' */

    /* Gain: '<S14>/Gain1' */
    rtB.Gain1[0] = rtP.Gain1_Gain[0] * rtb_Gain1_d_idx_1;
    rtB.Gain1[1] = rtP.Gain1_Gain[1] * rtb_Gain1_d_idx_2;
    rtB.Gain1[2] = rtP.Gain1_Gain[2] * rtb_qA2B_idx_2;
    rtB.Gain1[3] = rtP.Gain1_Gain[3] * rtb_Gain1_d_idx_0;
  }

  /* Integrator: '<S3>/Integrator' */
  if (rtDW.Integrator_IWORK != 0) {
    rtX.Integrator_CSTATE[0] = rtB.Gain1[0];
    rtX.Integrator_CSTATE[1] = rtB.Gain1[1];
    rtX.Integrator_CSTATE[2] = rtB.Gain1[2];
    rtX.Integrator_CSTATE[3] = rtB.Gain1[3];
  }

  /* MATLAB Function: '<S3>/Quaternion Normed' incorporates:
   *  Integrator: '<S3>/Integrator'
   */
  rtb_Gain1_d_idx_0 = 3.3121686421112381E-170;
  rtb_Gain1_d_idx_1 = fabs(rtX.Integrator_CSTATE[0]);
  if (rtb_Gain1_d_idx_1 > 3.3121686421112381E-170) {
    rtb_Product5 = 1.0;
    rtb_Gain1_d_idx_0 = rtb_Gain1_d_idx_1;
  } else {
    t = rtb_Gain1_d_idx_1 / 3.3121686421112381E-170;
    rtb_Product5 = t * t;
  }

  rtb_Gain1_d_idx_1 = fabs(rtX.Integrator_CSTATE[1]);
  if (rtb_Gain1_d_idx_1 > rtb_Gain1_d_idx_0) {
    t = rtb_Gain1_d_idx_0 / rtb_Gain1_d_idx_1;
    rtb_Product5 = rtb_Product5 * t * t + 1.0;
    rtb_Gain1_d_idx_0 = rtb_Gain1_d_idx_1;
  } else {
    t = rtb_Gain1_d_idx_1 / rtb_Gain1_d_idx_0;
    rtb_Product5 += t * t;
  }

  rtb_Gain1_d_idx_1 = fabs(rtX.Integrator_CSTATE[2]);
  if (rtb_Gain1_d_idx_1 > rtb_Gain1_d_idx_0) {
    t = rtb_Gain1_d_idx_0 / rtb_Gain1_d_idx_1;
    rtb_Product5 = rtb_Product5 * t * t + 1.0;
    rtb_Gain1_d_idx_0 = rtb_Gain1_d_idx_1;
  } else {
    t = rtb_Gain1_d_idx_1 / rtb_Gain1_d_idx_0;
    rtb_Product5 += t * t;
  }

  rtb_Gain1_d_idx_1 = fabs(rtX.Integrator_CSTATE[3]);
  if (rtb_Gain1_d_idx_1 > rtb_Gain1_d_idx_0) {
    t = rtb_Gain1_d_idx_0 / rtb_Gain1_d_idx_1;
    rtb_Product5 = rtb_Product5 * t * t + 1.0;
    rtb_Gain1_d_idx_0 = rtb_Gain1_d_idx_1;
  } else {
    t = rtb_Gain1_d_idx_1 / rtb_Gain1_d_idx_0;
    rtb_Product5 += t * t;
  }

  rtb_Product5 = rtb_Gain1_d_idx_0 * sqrt(rtb_Product5);
  rtB.y[0] = rtX.Integrator_CSTATE[0] / rtb_Product5;

  /* Gain: '<S13>/Gain1' */
  rtb_qA2B_idx_2 = rtP.Gain1_Gain_i[0] * rtB.y[0];

  /* Gain: '<S37>/Gain1' */
  A[0] = rtP.Gain1_Gain_f[0] * rtb_qA2B_idx_2;

  /* Gain: '<S13>/Gain1' */
  rtb_Gain1_d_idx_0 = rtb_qA2B_idx_2;

  /* MATLAB Function: '<S3>/Quaternion Normed' incorporates:
   *  Integrator: '<S3>/Integrator'
   */
  rtB.y[1] = rtX.Integrator_CSTATE[1] / rtb_Product5;

  /* Gain: '<S13>/Gain1' */
  rtb_qA2B_idx_2 = rtP.Gain1_Gain_i[1] * rtB.y[1];

  /* Gain: '<S37>/Gain1' */
  A[1] = rtP.Gain1_Gain_f[1] * rtb_qA2B_idx_2;

  /* Gain: '<S13>/Gain1' */
  rtb_Gain1_d_idx_1 = rtb_qA2B_idx_2;

  /* MATLAB Function: '<S3>/Quaternion Normed' incorporates:
   *  Integrator: '<S3>/Integrator'
   */
  rtB.y[2] = rtX.Integrator_CSTATE[2] / rtb_Product5;

  /* Gain: '<S13>/Gain1' */
  rtb_qA2B_idx_2 = rtP.Gain1_Gain_i[2] * rtB.y[2];

  /* Gain: '<S37>/Gain1' */
  A[2] = rtP.Gain1_Gain_f[2] * rtb_qA2B_idx_2;

  /* Gain: '<S13>/Gain1' */
  rtb_Gain1_d_idx_2 = rtb_qA2B_idx_2;

  /* MATLAB Function: '<S3>/Quaternion Normed' incorporates:
   *  Integrator: '<S3>/Integrator'
   */
  rtB.y[3] = rtX.Integrator_CSTATE[3] / rtb_Product5;

  /* Gain: '<S13>/Gain1' */
  rtb_qA2B_idx_2 = rtP.Gain1_Gain_i[3] * rtB.y[3];

  /* Gain: '<S37>/Gain1' */
  A[3] = rtP.Gain1_Gain_f[3] * rtb_qA2B_idx_2;

  /* Sum: '<S35>/Sum1' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<S30>/Constant'
   *  DotProduct: '<S35>/Dot Product'
   *  Product: '<S35>/Product2'
   */
  rtb_Product5 = A[0] * rtP.Constant_Value_o - ((rtP.P_F.star_sensor_1_vb[0] *
    A[1] + rtP.P_F.star_sensor_1_vb[1] * A[2]) + rtP.P_F.star_sensor_1_vb[2] *
    A[3]);

  /* Sum: '<S35>/Sum' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<S30>/Constant'
   *  Product: '<S35>/Product'
   *  Product: '<S35>/Product1'
   *  Product: '<S38>/Product'
   *  Product: '<S38>/Product1'
   *  Product: '<S38>/Product2'
   *  Product: '<S38>/Product3'
   *  Product: '<S38>/Product4'
   *  Product: '<S38>/Product5'
   *  Sum: '<S38>/Sum'
   *  Sum: '<S38>/Sum1'
   *  Sum: '<S38>/Sum2'
   */
  rtb_Divide_o_idx_0 = ((A[2] * rtP.P_F.star_sensor_1_vb[2] - A[3] *
    rtP.P_F.star_sensor_1_vb[1]) + A[0] * rtP.P_F.star_sensor_1_vb[0]) +
    rtP.Constant_Value_o * A[1];
  rtb_Divide_o_idx_1 = ((A[3] * rtP.P_F.star_sensor_1_vb[0] - A[1] *
    rtP.P_F.star_sensor_1_vb[2]) + A[0] * rtP.P_F.star_sensor_1_vb[1]) +
    rtP.Constant_Value_o * A[2];
  rtb_Divide_o_idx_2 = ((A[1] * rtP.P_F.star_sensor_1_vb[1] - A[2] *
    rtP.P_F.star_sensor_1_vb[0]) + A[0] * rtP.P_F.star_sensor_1_vb[2]) +
    rtP.Constant_Value_o * A[3];

  /* Sum: '<S36>/Sum1' incorporates:
   *  DotProduct: '<S36>/Dot Product'
   *  Product: '<S36>/Product2'
   *  Sum: '<S35>/Sum'
   */
  t = rtb_Product5 * rtb_Gain1_d_idx_0 - ((rtb_Gain1_d_idx_1 *
    rtb_Divide_o_idx_0 + rtb_Gain1_d_idx_2 * rtb_Divide_o_idx_1) +
    rtb_qA2B_idx_2 * rtb_Divide_o_idx_2);

  /* Product: '<S30>/Product' incorporates:
   *  Product: '<S36>/Product'
   *  Product: '<S36>/Product1'
   *  Product: '<S39>/Product'
   *  Product: '<S39>/Product1'
   *  Product: '<S39>/Product2'
   *  Product: '<S39>/Product3'
   *  Product: '<S39>/Product4'
   *  Product: '<S39>/Product5'
   *  Sum: '<S35>/Sum'
   *  Sum: '<S36>/Sum'
   *  Sum: '<S39>/Sum'
   *  Sum: '<S39>/Sum1'
   *  Sum: '<S39>/Sum2'
   */
  rtB.Product[0] = (((rtb_Divide_o_idx_1 * rtb_qA2B_idx_2 - rtb_Divide_o_idx_2 *
                      rtb_Gain1_d_idx_2) + rtb_Product5 * rtb_Gain1_d_idx_1) +
                    rtb_Gain1_d_idx_0 * rtb_Divide_o_idx_0) * (1.0 / t);
  rtB.Product[1] = (((rtb_Divide_o_idx_2 * rtb_Gain1_d_idx_1 -
                      rtb_Divide_o_idx_0 * rtb_qA2B_idx_2) + rtb_Product5 *
                     rtb_Gain1_d_idx_2) + rtb_Gain1_d_idx_0 * rtb_Divide_o_idx_1)
    * (1.0 / t);
  rtB.Product[2] = (((rtb_Divide_o_idx_0 * rtb_Gain1_d_idx_2 -
                      rtb_Divide_o_idx_1 * rtb_Gain1_d_idx_1) + rtb_Product5 *
                     rtb_qA2B_idx_2) + rtb_Gain1_d_idx_0 * rtb_Divide_o_idx_2) *
    (1.0 / t);

  /* Sum: '<S21>/Sum of Elements' incorporates:
   *  Math: '<S21>/Math Function'
   */
  rtb_Product5 = (rtB.Product[0] * rtB.Product[0] + rtB.Product[1] *
                  rtB.Product[1]) + rtB.Product[2] * rtB.Product[2];

  /* Math: '<S21>/Math Function1' incorporates:
   *  Sum: '<S21>/Sum of Elements'
   *
   * About '<S21>/Math Function1':
   *  Operator: sqrt
   */
  if (rtb_Product5 < 0.0) {
    rtb_Product5 = -sqrt(fabs(rtb_Product5));
  } else {
    rtb_Product5 = sqrt(rtb_Product5);
  }

  /* End of Math: '<S21>/Math Function1' */

  /* Switch: '<S21>/Switch' incorporates:
   *  Constant: '<S21>/Constant'
   *  Product: '<S21>/Product'
   */
  if (rtb_Product5 > rtP.NormalizeVector1_maxzero) {
    A[0] = rtB.Product[0];
    A[1] = rtB.Product[1];
    A[2] = rtB.Product[2];
    A[3] = rtb_Product5;
  } else {
    A[0] = rtB.Product[0] * 0.0;
    A[1] = rtB.Product[1] * 0.0;
    A[2] = rtB.Product[2] * 0.0;
    A[3] = rtP.Constant_Value_pb;
  }

  /* End of Switch: '<S21>/Switch' */

  /* DotProduct: '<S4>/Dot Product1' incorporates:
   *  Product: '<S21>/Divide'
   */
  rtb_Product5 = (A[0] / A[3] * rtb_vector_idx_0 + A[1] / A[3] *
                  rtb_vector_idx_1) + A[2] / A[3] * rtb_vector_idx_2;

  /* Saturate: '<S4>/Saturation' incorporates:
   *  DotProduct: '<S4>/Dot Product1'
   */
  if (rtb_Product5 > rtP.Saturation_UpperSat) {
    rtB.Saturation = rtP.Saturation_UpperSat;
  } else if (rtb_Product5 < rtP.Saturation_LowerSat) {
    rtB.Saturation = rtP.Saturation_LowerSat;
  } else {
    rtB.Saturation = rtb_Product5;
  }

  /* End of Saturate: '<S4>/Saturation' */

  /* Product: '<S4>/Product' */
  rtB.min_exclusion = rtB.E.solar_occulted_boolean * rtB.Saturation;

  /* Trigonometry: '<S4>/Acos' */
  if (rtB.min_exclusion > 1.0) {
    rtb_Product5 = 1.0;
  } else if (rtB.min_exclusion < -1.0) {
    rtb_Product5 = -1.0;
  } else {
    rtb_Product5 = rtB.min_exclusion;
  }

  rtB.Acos = acos(rtb_Product5);

  /* End of Trigonometry: '<S4>/Acos' */
  attitude3d_MovingMinimum(rtB.Acos, &rtB.MovingMinimum, &rtDW.MovingMinimum);

  /* Sum: '<S22>/Sum of Elements' incorporates:
   *  Math: '<S22>/Math Function'
   */
  rtb_Product5 = (rtB.E.solar_vector[0] * rtB.E.solar_vector[0] +
                  rtB.E.solar_vector[1] * rtB.E.solar_vector[1]) +
    rtB.E.solar_vector[2] * rtB.E.solar_vector[2];

  /* Math: '<S22>/Math Function1' incorporates:
   *  Sum: '<S22>/Sum of Elements'
   *
   * About '<S22>/Math Function1':
   *  Operator: sqrt
   */
  if (rtb_Product5 < 0.0) {
    rtb_Product5 = -sqrt(fabs(rtb_Product5));
  } else {
    rtb_Product5 = sqrt(rtb_Product5);
  }

  /* End of Math: '<S22>/Math Function1' */

  /* Switch: '<S22>/Switch' incorporates:
   *  Constant: '<S22>/Constant'
   *  Product: '<S22>/Product'
   */
  if (rtb_Product5 > rtP.NormalizeVector_maxzero_m) {
    A[0] = rtB.E.solar_vector[0];
    A[1] = rtB.E.solar_vector[1];
    A[2] = rtB.E.solar_vector[2];
    A[3] = rtb_Product5;
  } else {
    A[0] = rtB.E.solar_vector[0] * 0.0;
    A[1] = rtB.E.solar_vector[1] * 0.0;
    A[2] = rtB.E.solar_vector[2] * 0.0;
    A[3] = rtP.Constant_Value_oj;
  }

  /* End of Switch: '<S22>/Switch' */

  /* Product: '<S22>/Divide' */
  rtb_vector_idx_0 = A[0] / A[3];
  rtb_vector_idx_1 = A[1] / A[3];
  rtb_vector_idx_2 = A[2] / A[3];

  /* Gain: '<S42>/Gain1' */
  A[0] = rtP.Gain1_Gain_m[0] * rtb_Gain1_d_idx_0;
  A[1] = rtP.Gain1_Gain_m[1] * rtb_Gain1_d_idx_1;
  A[2] = rtP.Gain1_Gain_m[2] * rtb_Gain1_d_idx_2;
  A[3] = rtP.Gain1_Gain_m[3] * rtb_qA2B_idx_2;

  /* Sum: '<S40>/Sum1' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Constant: '<S31>/Constant'
   *  DotProduct: '<S40>/Dot Product'
   *  Product: '<S40>/Product2'
   */
  rtb_Product5 = A[0] * rtP.Constant_Value_i - ((rtP.P_F.star_sensor_2_vb[0] *
    A[1] + rtP.P_F.star_sensor_2_vb[1] * A[2]) + rtP.P_F.star_sensor_2_vb[2] *
    A[3]);

  /* Sum: '<S40>/Sum' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Constant: '<S31>/Constant'
   *  Product: '<S40>/Product'
   *  Product: '<S40>/Product1'
   *  Product: '<S43>/Product'
   *  Product: '<S43>/Product1'
   *  Product: '<S43>/Product2'
   *  Product: '<S43>/Product3'
   *  Product: '<S43>/Product4'
   *  Product: '<S43>/Product5'
   *  Sum: '<S43>/Sum'
   *  Sum: '<S43>/Sum1'
   *  Sum: '<S43>/Sum2'
   */
  rtb_Divide_o_idx_0 = ((A[2] * rtP.P_F.star_sensor_2_vb[2] - A[3] *
    rtP.P_F.star_sensor_2_vb[1]) + A[0] * rtP.P_F.star_sensor_2_vb[0]) +
    rtP.Constant_Value_i * A[1];
  rtb_Divide_o_idx_1 = ((A[3] * rtP.P_F.star_sensor_2_vb[0] - A[1] *
    rtP.P_F.star_sensor_2_vb[2]) + A[0] * rtP.P_F.star_sensor_2_vb[1]) +
    rtP.Constant_Value_i * A[2];
  rtb_Divide_o_idx_2 = ((A[1] * rtP.P_F.star_sensor_2_vb[1] - A[2] *
    rtP.P_F.star_sensor_2_vb[0]) + A[0] * rtP.P_F.star_sensor_2_vb[2]) +
    rtP.Constant_Value_i * A[3];

  /* Sum: '<S41>/Sum1' incorporates:
   *  DotProduct: '<S41>/Dot Product'
   *  Product: '<S41>/Product2'
   *  Sum: '<S40>/Sum'
   */
  t = rtb_Product5 * rtb_Gain1_d_idx_0 - ((rtb_Gain1_d_idx_1 *
    rtb_Divide_o_idx_0 + rtb_Gain1_d_idx_2 * rtb_Divide_o_idx_1) +
    rtb_qA2B_idx_2 * rtb_Divide_o_idx_2);

  /* Product: '<S31>/Product' incorporates:
   *  Product: '<S41>/Product'
   *  Product: '<S41>/Product1'
   *  Product: '<S44>/Product'
   *  Product: '<S44>/Product1'
   *  Product: '<S44>/Product2'
   *  Product: '<S44>/Product3'
   *  Product: '<S44>/Product4'
   *  Product: '<S44>/Product5'
   *  Sum: '<S40>/Sum'
   *  Sum: '<S41>/Sum'
   *  Sum: '<S44>/Sum'
   *  Sum: '<S44>/Sum1'
   *  Sum: '<S44>/Sum2'
   */
  rtB.Product_i[0] = (((rtb_Divide_o_idx_1 * rtb_qA2B_idx_2 - rtb_Divide_o_idx_2
                        * rtb_Gain1_d_idx_2) + rtb_Product5 * rtb_Gain1_d_idx_1)
                      + rtb_Gain1_d_idx_0 * rtb_Divide_o_idx_0) * (1.0 / t);
  rtB.Product_i[1] = (((rtb_Divide_o_idx_2 * rtb_Gain1_d_idx_1 -
                        rtb_Divide_o_idx_0 * rtb_qA2B_idx_2) + rtb_Product5 *
                       rtb_Gain1_d_idx_2) + rtb_Gain1_d_idx_0 *
                      rtb_Divide_o_idx_1) * (1.0 / t);
  rtB.Product_i[2] = (((rtb_Divide_o_idx_0 * rtb_Gain1_d_idx_2 -
                        rtb_Divide_o_idx_1 * rtb_Gain1_d_idx_1) + rtb_Product5 *
                       rtb_qA2B_idx_2) + rtb_Gain1_d_idx_0 * rtb_Divide_o_idx_2)
    * (1.0 / t);

  /* Sum: '<S23>/Sum of Elements' incorporates:
   *  Math: '<S23>/Math Function'
   */
  rtb_Product5 = (rtB.Product_i[0] * rtB.Product_i[0] + rtB.Product_i[1] *
                  rtB.Product_i[1]) + rtB.Product_i[2] * rtB.Product_i[2];

  /* Math: '<S23>/Math Function1' incorporates:
   *  Sum: '<S23>/Sum of Elements'
   *
   * About '<S23>/Math Function1':
   *  Operator: sqrt
   */
  if (rtb_Product5 < 0.0) {
    rtb_Product5 = -sqrt(fabs(rtb_Product5));
  } else {
    rtb_Product5 = sqrt(rtb_Product5);
  }

  /* End of Math: '<S23>/Math Function1' */

  /* Switch: '<S23>/Switch' incorporates:
   *  Constant: '<S23>/Constant'
   *  Product: '<S23>/Product'
   */
  if (rtb_Product5 > rtP.NormalizeVector1_maxzero_i) {
    A[0] = rtB.Product_i[0];
    A[1] = rtB.Product_i[1];
    A[2] = rtB.Product_i[2];
    A[3] = rtb_Product5;
  } else {
    A[0] = rtB.Product_i[0] * 0.0;
    A[1] = rtB.Product_i[1] * 0.0;
    A[2] = rtB.Product_i[2] * 0.0;
    A[3] = rtP.Constant_Value_pw;
  }

  /* End of Switch: '<S23>/Switch' */

  /* DotProduct: '<S5>/Dot Product1' incorporates:
   *  Product: '<S23>/Divide'
   */
  rtb_vector_idx_2 = (A[0] / A[3] * rtb_vector_idx_0 + A[1] / A[3] *
                      rtb_vector_idx_1) + A[2] / A[3] * rtb_vector_idx_2;

  /* Saturate: '<S5>/Saturation' incorporates:
   *  DotProduct: '<S5>/Dot Product1'
   */
  if (rtb_vector_idx_2 > rtP.Saturation_UpperSat_o) {
    rtB.Saturation_i = rtP.Saturation_UpperSat_o;
  } else if (rtb_vector_idx_2 < rtP.Saturation_LowerSat_p) {
    rtB.Saturation_i = rtP.Saturation_LowerSat_p;
  } else {
    rtB.Saturation_i = rtb_vector_idx_2;
  }

  /* End of Saturate: '<S5>/Saturation' */

  /* Product: '<S5>/Product' */
  rtB.min_exclusion_m = rtB.E.solar_occulted_boolean * rtB.Saturation_i;

  /* Trigonometry: '<S5>/Acos' */
  if (rtB.min_exclusion_m > 1.0) {
    rtb_Product5 = 1.0;
  } else if (rtB.min_exclusion_m < -1.0) {
    rtb_Product5 = -1.0;
  } else {
    rtb_Product5 = rtB.min_exclusion_m;
  }

  rtB.Acos_i = acos(rtb_Product5);

  /* End of Trigonometry: '<S5>/Acos' */
  attitude3d_MovingMinimum(rtB.Acos_i, &rtB.MovingMinimum_p,
    &rtDW.MovingMinimum_p);

  /* Gain: '<S6>/Gain1' */
  rtb_vector_idx_2 = rtP.Gain1_Gain_j * rtB.E.r_s[0];

  /* DotProduct: '<S6>/Dot Product2' incorporates:
   *  Math: '<S24>/Math Function'
   */
  t = rtb_vector_idx_2 * rtb_vector_idx_2;

  /* Gain: '<S6>/Gain1' */
  rtb_vector_idx_0 = rtb_vector_idx_2;
  rtb_vector_idx_2 = rtP.Gain1_Gain_j * rtB.E.r_s[1];

  /* DotProduct: '<S6>/Dot Product2' incorporates:
   *  Math: '<S24>/Math Function'
   */
  rtb_Divide_o_idx_0 = rtb_vector_idx_2 * rtb_vector_idx_2;

  /* Gain: '<S6>/Gain1' */
  rtb_vector_idx_1 = rtb_vector_idx_2;
  rtb_vector_idx_2 = rtP.Gain1_Gain_j * rtB.E.r_s[2];

  /* DotProduct: '<S6>/Dot Product2' incorporates:
   *  Math: '<S24>/Math Function'
   */
  rtb_Divide_o_idx_1 = rtb_vector_idx_2 * rtb_vector_idx_2;

  /* Sum: '<S24>/Sum of Elements' */
  rtb_Product5 = (t + rtb_Divide_o_idx_0) + rtb_Divide_o_idx_1;

  /* Math: '<S24>/Math Function1'
   *
   * About '<S24>/Math Function1':
   *  Operator: sqrt
   */
  if (rtb_Product5 < 0.0) {
    rtb_Product5 = -sqrt(fabs(rtb_Product5));
  } else {
    rtb_Product5 = sqrt(rtb_Product5);
  }

  /* End of Math: '<S24>/Math Function1' */

  /* Switch: '<S24>/Switch' incorporates:
   *  Constant: '<S24>/Constant'
   *  Product: '<S24>/Product'
   */
  if (rtb_Product5 > rtP.NormalizeVector_maxzero_o) {
    A[0] = rtb_vector_idx_0;
    A[1] = rtb_vector_idx_1;
    A[2] = rtb_vector_idx_2;
    A[3] = rtb_Product5;
  } else {
    A[0] = rtb_vector_idx_0 * 0.0;
    A[1] = rtb_vector_idx_1 * 0.0;
    A[2] = rtb_vector_idx_2 * 0.0;
    A[3] = rtP.Constant_Value_kd;
  }

  /* End of Switch: '<S24>/Switch' */

  /* Product: '<S24>/Divide' */
  rtb_vector_idx_0 = A[0] / A[3];
  rtb_vector_idx_1 = A[1] / A[3];
  rtb_vector_idx_2 = A[2] / A[3];

  /* Sum: '<S25>/Sum of Elements' incorporates:
   *  Math: '<S25>/Math Function'
   */
  rtb_Product5 = (rtB.Product[0] * rtB.Product[0] + rtB.Product[1] *
                  rtB.Product[1]) + rtB.Product[2] * rtB.Product[2];

  /* Math: '<S25>/Math Function1' incorporates:
   *  Sum: '<S25>/Sum of Elements'
   *
   * About '<S25>/Math Function1':
   *  Operator: sqrt
   */
  if (rtb_Product5 < 0.0) {
    rtb_Product5 = -sqrt(fabs(rtb_Product5));
  } else {
    rtb_Product5 = sqrt(rtb_Product5);
  }

  /* End of Math: '<S25>/Math Function1' */

  /* Switch: '<S25>/Switch' incorporates:
   *  Constant: '<S25>/Constant'
   *  Product: '<S25>/Product'
   */
  if (rtb_Product5 > rtP.NormalizeVector1_maxzero_c) {
    A[0] = rtB.Product[0];
    A[1] = rtB.Product[1];
    A[2] = rtB.Product[2];
    A[3] = rtb_Product5;
  } else {
    A[0] = rtB.Product[0] * 0.0;
    A[1] = rtB.Product[1] * 0.0;
    A[2] = rtB.Product[2] * 0.0;
    A[3] = rtP.Constant_Value_g;
  }

  /* End of Switch: '<S25>/Switch' */

  /* DotProduct: '<S6>/Dot Product1' incorporates:
   *  Product: '<S25>/Divide'
   */
  rtb_vector_idx_2 = (A[0] / A[3] * rtb_vector_idx_0 + A[1] / A[3] *
                      rtb_vector_idx_1) + A[2] / A[3] * rtb_vector_idx_2;

  /* Trigonometry: '<S6>/Acos' incorporates:
   *  DotProduct: '<S6>/Dot Product1'
   */
  if (rtb_vector_idx_2 > 1.0) {
    rtb_vector_idx_2 = 1.0;
  } else {
    if (rtb_vector_idx_2 < -1.0) {
      rtb_vector_idx_2 = -1.0;
    }
  }

  /* Switch: '<S6>/Switch' incorporates:
   *  Constant: '<Root>/Constant9'
   *  Constant: '<S6>/Constant10'
   *  Constant: '<S6>/Constant11'
   *  DotProduct: '<S6>/Dot Product2'
   *  Product: '<S6>/Divide'
   *  RelationalOperator: '<S6>/Greater Than'
   *  Sqrt: '<S6>/Sqrt'
   *  Sum: '<S6>/Sum'
   *  Trigonometry: '<S6>/Acos'
   *  Trigonometry: '<S6>/Atan'
   */
  if (atan(rtP.P_E.target_mean_radius / (rtP.P_E.target_mean_radius + sqrt
        (rtb_Divide_o_idx_1 + (rtb_Divide_o_idx_0 + t)))) > acos
      (rtb_vector_idx_2)) {
    rtB.Switch = rtP.Constant10_Value;
  } else {
    rtB.Switch = rtP.Constant11_Value;
  }

  /* End of Switch: '<S6>/Switch' */
  if (ssIsSampleHit(rtS, 1, 0)) {
    /* DiscreteFir: '<S26>/Discrete FIR Filter' */
    /* Consume delay line and beginning of input samples */
    t = rtB.Switch * rtP.DiscreteFIRFilter_Coefficients[0];
    for (idx = 0; idx < 59; idx++) {
      t += rtP.DiscreteFIRFilter_Coefficients[idx + 1] *
        rtDW.DiscreteFIRFilter_states[idx];
    }

    /* Update delay line for next frame */
    for (idx = 57; idx >= 0; idx--) {
      rtDW.DiscreteFIRFilter_states[idx + 1] = rtDW.DiscreteFIRFilter_states[idx];
    }

    rtDW.DiscreteFIRFilter_states[0] = rtB.Switch;

    /* End of DiscreteFir: '<S26>/Discrete FIR Filter' */

    /* Product: '<S6>/Divide1' incorporates:
     *  Constant: '<S6>/Constant12'
     */
    rtb_Divide1 = t / (real_T)rtP.P_F.window_n;
    attitude3d_MovingMaximum(rtb_Divide1, &rtB.MovingMaximum,
      &rtDW.MovingMaximum);
  }

  /* Gain: '<S7>/Gain1' */
  rtb_vector_idx_2 = rtP.Gain1_Gain_l * rtB.E.r_s[0];

  /* DotProduct: '<S7>/Dot Product2' incorporates:
   *  Math: '<S27>/Math Function'
   */
  t = rtb_vector_idx_2 * rtb_vector_idx_2;

  /* Gain: '<S7>/Gain1' */
  rtb_vector_idx_0 = rtb_vector_idx_2;
  rtb_vector_idx_2 = rtP.Gain1_Gain_l * rtB.E.r_s[1];

  /* DotProduct: '<S7>/Dot Product2' incorporates:
   *  Math: '<S27>/Math Function'
   */
  rtb_Divide_o_idx_0 = rtb_vector_idx_2 * rtb_vector_idx_2;

  /* Gain: '<S7>/Gain1' */
  rtb_vector_idx_1 = rtb_vector_idx_2;
  rtb_vector_idx_2 = rtP.Gain1_Gain_l * rtB.E.r_s[2];

  /* DotProduct: '<S7>/Dot Product2' incorporates:
   *  Math: '<S27>/Math Function'
   */
  rtb_Divide_o_idx_1 = rtb_vector_idx_2 * rtb_vector_idx_2;

  /* Sum: '<S27>/Sum of Elements' */
  rtb_Product5 = (t + rtb_Divide_o_idx_0) + rtb_Divide_o_idx_1;

  /* Math: '<S27>/Math Function1'
   *
   * About '<S27>/Math Function1':
   *  Operator: sqrt
   */
  if (rtb_Product5 < 0.0) {
    rtb_Product5 = -sqrt(fabs(rtb_Product5));
  } else {
    rtb_Product5 = sqrt(rtb_Product5);
  }

  /* End of Math: '<S27>/Math Function1' */

  /* Switch: '<S27>/Switch' incorporates:
   *  Constant: '<S27>/Constant'
   *  Product: '<S27>/Product'
   */
  if (rtb_Product5 > rtP.NormalizeVector_maxzero_e) {
    A[0] = rtb_vector_idx_0;
    A[1] = rtb_vector_idx_1;
    A[2] = rtb_vector_idx_2;
    A[3] = rtb_Product5;
  } else {
    A[0] = rtb_vector_idx_0 * 0.0;
    A[1] = rtb_vector_idx_1 * 0.0;
    A[2] = rtb_vector_idx_2 * 0.0;
    A[3] = rtP.Constant_Value_bu;
  }

  /* End of Switch: '<S27>/Switch' */

  /* Product: '<S27>/Divide' */
  rtb_vector_idx_0 = A[0] / A[3];
  rtb_vector_idx_1 = A[1] / A[3];
  rtb_vector_idx_2 = A[2] / A[3];

  /* Sum: '<S28>/Sum of Elements' incorporates:
   *  Math: '<S28>/Math Function'
   */
  rtb_Product5 = (rtB.Product_i[0] * rtB.Product_i[0] + rtB.Product_i[1] *
                  rtB.Product_i[1]) + rtB.Product_i[2] * rtB.Product_i[2];

  /* Math: '<S28>/Math Function1' incorporates:
   *  Sum: '<S28>/Sum of Elements'
   *
   * About '<S28>/Math Function1':
   *  Operator: sqrt
   */
  if (rtb_Product5 < 0.0) {
    rtb_Product5 = -sqrt(fabs(rtb_Product5));
  } else {
    rtb_Product5 = sqrt(rtb_Product5);
  }

  /* End of Math: '<S28>/Math Function1' */

  /* Switch: '<S28>/Switch' incorporates:
   *  Constant: '<S28>/Constant'
   *  Product: '<S28>/Product'
   */
  if (rtb_Product5 > rtP.NormalizeVector1_maxzero_e) {
    A[0] = rtB.Product_i[0];
    A[1] = rtB.Product_i[1];
    A[2] = rtB.Product_i[2];
    A[3] = rtb_Product5;
  } else {
    A[0] = rtB.Product_i[0] * 0.0;
    A[1] = rtB.Product_i[1] * 0.0;
    A[2] = rtB.Product_i[2] * 0.0;
    A[3] = rtP.Constant_Value_ov;
  }

  /* End of Switch: '<S28>/Switch' */

  /* DotProduct: '<S7>/Dot Product1' incorporates:
   *  Product: '<S28>/Divide'
   */
  rtb_vector_idx_2 = (A[0] / A[3] * rtb_vector_idx_0 + A[1] / A[3] *
                      rtb_vector_idx_1) + A[2] / A[3] * rtb_vector_idx_2;

  /* Trigonometry: '<S7>/Acos' incorporates:
   *  DotProduct: '<S7>/Dot Product1'
   */
  if (rtb_vector_idx_2 > 1.0) {
    rtb_vector_idx_2 = 1.0;
  } else {
    if (rtb_vector_idx_2 < -1.0) {
      rtb_vector_idx_2 = -1.0;
    }
  }

  /* Switch: '<S7>/Switch' incorporates:
   *  Constant: '<Root>/Constant8'
   *  Constant: '<S7>/Constant10'
   *  Constant: '<S7>/Constant11'
   *  DotProduct: '<S7>/Dot Product2'
   *  Product: '<S7>/Divide'
   *  RelationalOperator: '<S7>/Greater Than'
   *  Sqrt: '<S7>/Sqrt'
   *  Sum: '<S7>/Sum'
   *  Trigonometry: '<S7>/Acos'
   *  Trigonometry: '<S7>/Atan'
   */
  if (atan(rtP.P_E.target_mean_radius / (rtP.P_E.target_mean_radius + sqrt
        (rtb_Divide_o_idx_1 + (rtb_Divide_o_idx_0 + t)))) > acos
      (rtb_vector_idx_2)) {
    rtB.Switch_a = rtP.Constant10_Value_p;
  } else {
    rtB.Switch_a = rtP.Constant11_Value_f;
  }

  /* End of Switch: '<S7>/Switch' */
  if (ssIsSampleHit(rtS, 1, 0)) {
    /* DiscreteFir: '<S29>/Discrete FIR Filter' */
    /* Consume delay line and beginning of input samples */
    t = rtB.Switch_a * rtP.DiscreteFIRFilter_Coefficient_n[0];
    for (idx = 0; idx < 59; idx++) {
      t += rtP.DiscreteFIRFilter_Coefficient_n[idx + 1] *
        rtDW.DiscreteFIRFilter_states_k[idx];
    }

    /* Update delay line for next frame */
    for (idx = 57; idx >= 0; idx--) {
      rtDW.DiscreteFIRFilter_states_k[idx + 1] =
        rtDW.DiscreteFIRFilter_states_k[idx];
    }

    rtDW.DiscreteFIRFilter_states_k[0] = rtB.Switch_a;

    /* End of DiscreteFir: '<S29>/Discrete FIR Filter' */

    /* Product: '<S7>/Divide1' incorporates:
     *  Constant: '<S7>/Constant12'
     */
    rtb_Divide1_k = t / (real_T)rtP.P_F.window_n;
    attitude3d_MovingMaximum(rtb_Divide1_k, &rtB.MovingMaximum_p,
      &rtDW.MovingMaximum_p);
  }

  /* Switch: '<S11>/Switch' incorporates:
   *  Constant: '<S11>/Constant'
   *  Constant: '<S66>/Constant'
   *  RelationalOperator: '<S66>/Compare'
   */
  if (rtB.E.solar_occulted_integral == rtP.Constant_Value_b) {
    rtb_Product5 = rtP.Constant_Value_b5;
  } else {
    rtb_Product5 = rtB.E.solar_occulted_integral;
  }

  /* End of Switch: '<S11>/Switch' */

  /* Product: '<S11>/Divide' incorporates:
   *  Integrator: '<S11>/Integrator1'
   */
  rtB.Divide = 1.0 / rtb_Product5 * rtX.Integrator1_CSTATE;

  /* Switch: '<S10>/Switch' incorporates:
   *  Constant: '<S10>/Constant'
   *  Constant: '<S63>/Constant'
   *  RelationalOperator: '<S63>/Compare'
   */
  if (rtB.E.comms_occulted_integral == rtP.Constant_Value_c) {
    rtb_Product5 = rtP.Constant_Value_ok;
  } else {
    rtb_Product5 = rtB.E.comms_occulted_integral;
  }

  /* End of Switch: '<S10>/Switch' */

  /* Product: '<S10>/Divide' incorporates:
   *  Integrator: '<S10>/Integrator1'
   */
  rtB.Divide_i = 1.0 / rtb_Product5 * rtX.Integrator1_CSTATE_a;

  /* Switch: '<S9>/Switch' incorporates:
   *  Constant: '<S60>/Constant'
   *  Constant: '<S9>/Constant9'
   *  Integrator: '<S9>/Integrator2'
   *  RelationalOperator: '<S60>/Compare'
   */
  if (rtX.Integrator2_CSTATE == rtP.Constant_Value) {
    rtB.Switch_c = rtP.Constant9_Value;
  } else {
    rtB.Switch_c = rtX.Integrator2_CSTATE;
  }

  /* End of Switch: '<S9>/Switch' */

  /* Integrator: '<S9>/Integrator1' */
  rtB.integral_pointing = rtX.Integrator1_CSTATE_f;

  /* Product: '<S9>/Divide' */
  rtB.Divide_b = 1.0 / rtB.Switch_c * rtB.integral_pointing;
  if (ssIsSampleHit(rtS, 1, 0)) {
  }

  /* SignalConversion generated from: '<Root>/Bus Selector' */
  rtB.thrust_weight = rtB.E.thrust_weight;

  /* SignalConversion generated from: '<Root>/Bus Selector' */
  rtB.solar_occulted_integral = rtB.E.solar_occulted_integral;

  /* SignalConversion generated from: '<Root>/Bus Selector' */
  rtB.solar_occulted_boolean = rtB.E.solar_occulted_boolean;

  /* SignalConversion generated from: '<Root>/Bus Selector' */
  rtB.comms_occulted_integral = rtB.E.comms_occulted_integral;

  /* SignalConversion generated from: '<Root>/Bus Selector' */
  rtB.comms_occulted_boolean = rtB.E.comms_occulted_boolean;

  /* SignalConversion generated from: '<Root>/Bus Selector' */
  rtB.thrust_vector[0] = rtB.E.thrust_vector[0];

  /* SignalConversion generated from: '<Root>/Bus Selector' */
  rtB.r_s[0] = rtB.E.r_s[0];

  /* SignalConversion generated from: '<Root>/Bus Selector' */
  rtB.v_s[0] = rtB.E.v_s[0];

  /* SignalConversion generated from: '<Root>/Bus Selector' */
  rtB.r_c[0] = rtB.E.r_c[0];

  /* SignalConversion generated from: '<Root>/Bus Selector' */
  rtB.v_c[0] = rtB.E.v_c[0];

  /* SignalConversion generated from: '<Root>/Bus Selector' */
  rtB.r_t[0] = rtB.E.r_t[0];

  /* SignalConversion generated from: '<Root>/Bus Selector' */
  rtB.v_t[0] = rtB.E.v_t[0];

  /* SignalConversion generated from: '<Root>/Bus Selector' */
  rtB.thrust_vector[1] = rtB.E.thrust_vector[1];

  /* SignalConversion generated from: '<Root>/Bus Selector' */
  rtB.r_s[1] = rtB.E.r_s[1];

  /* SignalConversion generated from: '<Root>/Bus Selector' */
  rtB.v_s[1] = rtB.E.v_s[1];

  /* SignalConversion generated from: '<Root>/Bus Selector' */
  rtB.r_c[1] = rtB.E.r_c[1];

  /* SignalConversion generated from: '<Root>/Bus Selector' */
  rtB.v_c[1] = rtB.E.v_c[1];

  /* SignalConversion generated from: '<Root>/Bus Selector' */
  rtB.r_t[1] = rtB.E.r_t[1];

  /* SignalConversion generated from: '<Root>/Bus Selector' */
  rtB.v_t[1] = rtB.E.v_t[1];

  /* SignalConversion generated from: '<Root>/Bus Selector' */
  rtB.thrust_vector[2] = rtB.E.thrust_vector[2];

  /* SignalConversion generated from: '<Root>/Bus Selector' */
  rtB.r_s[2] = rtB.E.r_s[2];

  /* SignalConversion generated from: '<Root>/Bus Selector' */
  rtB.v_s[2] = rtB.E.v_s[2];

  /* SignalConversion generated from: '<Root>/Bus Selector' */
  rtB.r_c[2] = rtB.E.r_c[2];

  /* SignalConversion generated from: '<Root>/Bus Selector' */
  rtB.v_c[2] = rtB.E.v_c[2];

  /* SignalConversion generated from: '<Root>/Bus Selector' */
  rtB.r_t[2] = rtB.E.r_t[2];

  /* SignalConversion generated from: '<Root>/Bus Selector' */
  rtB.v_t[2] = rtB.E.v_t[2];
  if (ssIsSampleHit(rtS, 1, 0)) {
  }

  /* Gain: '<S57>/Gain1' */
  A[0] = rtP.Gain1_Gain_fe[0] * rtb_Gain1_d_idx_0;
  A[1] = rtP.Gain1_Gain_fe[1] * rtb_Gain1_d_idx_1;
  A[2] = rtP.Gain1_Gain_fe[2] * rtb_Gain1_d_idx_2;
  A[3] = rtP.Gain1_Gain_fe[3] * rtb_qA2B_idx_2;

  /* Sum: '<S55>/Sum1' incorporates:
   *  Constant: '<Root>/Constant4'
   *  Constant: '<S34>/Constant'
   *  DotProduct: '<S55>/Dot Product'
   *  Product: '<S55>/Product2'
   */
  rtb_Product5 = A[0] * rtP.Constant_Value_f - ((rtP.P_F.solar_array_vb[0] * A[1]
    + rtP.P_F.solar_array_vb[1] * A[2]) + rtP.P_F.solar_array_vb[2] * A[3]);

  /* Sum: '<S55>/Sum' incorporates:
   *  Constant: '<Root>/Constant4'
   *  Constant: '<S34>/Constant'
   *  Product: '<S55>/Product'
   *  Product: '<S55>/Product1'
   *  Product: '<S58>/Product'
   *  Product: '<S58>/Product1'
   *  Product: '<S58>/Product2'
   *  Product: '<S58>/Product3'
   *  Product: '<S58>/Product4'
   *  Product: '<S58>/Product5'
   *  Sum: '<S58>/Sum'
   *  Sum: '<S58>/Sum1'
   *  Sum: '<S58>/Sum2'
   */
  rtb_vector_idx_0 = ((A[2] * rtP.P_F.solar_array_vb[2] - A[3] *
                       rtP.P_F.solar_array_vb[1]) + A[0] *
                      rtP.P_F.solar_array_vb[0]) + rtP.Constant_Value_f * A[1];
  rtb_vector_idx_1 = ((A[3] * rtP.P_F.solar_array_vb[0] - A[1] *
                       rtP.P_F.solar_array_vb[2]) + A[0] *
                      rtP.P_F.solar_array_vb[1]) + rtP.Constant_Value_f * A[2];
  rtb_vector_idx_2 = ((A[1] * rtP.P_F.solar_array_vb[1] - A[2] *
                       rtP.P_F.solar_array_vb[0]) + A[0] *
                      rtP.P_F.solar_array_vb[2]) + rtP.Constant_Value_f * A[3];

  /* Sum: '<S56>/Sum1' incorporates:
   *  DotProduct: '<S56>/Dot Product'
   *  Product: '<S56>/Product2'
   *  Sum: '<S55>/Sum'
   */
  t = rtb_Product5 * rtb_Gain1_d_idx_0 - ((rtb_Gain1_d_idx_1 * rtb_vector_idx_0
    + rtb_Gain1_d_idx_2 * rtb_vector_idx_1) + rtb_qA2B_idx_2 * rtb_vector_idx_2);

  /* Product: '<S34>/Product' incorporates:
   *  Product: '<S56>/Product'
   *  Product: '<S56>/Product1'
   *  Product: '<S59>/Product'
   *  Product: '<S59>/Product1'
   *  Product: '<S59>/Product2'
   *  Product: '<S59>/Product3'
   *  Product: '<S59>/Product4'
   *  Product: '<S59>/Product5'
   *  Sum: '<S55>/Sum'
   *  Sum: '<S56>/Sum'
   *  Sum: '<S59>/Sum'
   *  Sum: '<S59>/Sum1'
   *  Sum: '<S59>/Sum2'
   */
  rtB.Product_o[0] = (((rtb_vector_idx_1 * rtb_qA2B_idx_2 - rtb_vector_idx_2 *
                        rtb_Gain1_d_idx_2) + rtb_Product5 * rtb_Gain1_d_idx_1) +
                      rtb_Gain1_d_idx_0 * rtb_vector_idx_0) * (1.0 / t);
  rtB.Product_o[1] = (((rtb_vector_idx_2 * rtb_Gain1_d_idx_1 - rtb_vector_idx_0 *
                        rtb_qA2B_idx_2) + rtb_Product5 * rtb_Gain1_d_idx_2) +
                      rtb_Gain1_d_idx_0 * rtb_vector_idx_1) * (1.0 / t);
  rtB.Product_o[2] = (((rtb_vector_idx_0 * rtb_Gain1_d_idx_2 - rtb_vector_idx_1 *
                        rtb_Gain1_d_idx_1) + rtb_Product5 * rtb_qA2B_idx_2) +
                      rtb_Gain1_d_idx_0 * rtb_vector_idx_2) * (1.0 / t);

  /* Gain: '<S52>/Gain1' */
  A[0] = rtP.Gain1_Gain_m4[0] * rtb_Gain1_d_idx_0;
  A[1] = rtP.Gain1_Gain_m4[1] * rtb_Gain1_d_idx_1;
  A[2] = rtP.Gain1_Gain_m4[2] * rtb_Gain1_d_idx_2;
  A[3] = rtP.Gain1_Gain_m4[3] * rtb_qA2B_idx_2;

  /* Sum: '<S50>/Sum1' incorporates:
   *  Constant: '<Root>/Constant3'
   *  Constant: '<S33>/Constant'
   *  DotProduct: '<S50>/Dot Product'
   *  Product: '<S50>/Product2'
   */
  rtb_Product5 = A[0] * rtP.Constant_Value_gd - ((rtP.P_F.antenna_vb[0] * A[1] +
    rtP.P_F.antenna_vb[1] * A[2]) + rtP.P_F.antenna_vb[2] * A[3]);

  /* Sum: '<S50>/Sum' incorporates:
   *  Constant: '<Root>/Constant3'
   *  Constant: '<S33>/Constant'
   *  Product: '<S50>/Product'
   *  Product: '<S50>/Product1'
   *  Product: '<S53>/Product'
   *  Product: '<S53>/Product1'
   *  Product: '<S53>/Product2'
   *  Product: '<S53>/Product3'
   *  Product: '<S53>/Product4'
   *  Product: '<S53>/Product5'
   *  Sum: '<S53>/Sum'
   *  Sum: '<S53>/Sum1'
   *  Sum: '<S53>/Sum2'
   */
  rtb_vector_idx_0 = ((A[2] * rtP.P_F.antenna_vb[2] - A[3] * rtP.P_F.antenna_vb
                       [1]) + A[0] * rtP.P_F.antenna_vb[0]) +
    rtP.Constant_Value_gd * A[1];
  rtb_vector_idx_1 = ((A[3] * rtP.P_F.antenna_vb[0] - A[1] * rtP.P_F.antenna_vb
                       [2]) + A[0] * rtP.P_F.antenna_vb[1]) +
    rtP.Constant_Value_gd * A[2];
  rtb_vector_idx_2 = ((A[1] * rtP.P_F.antenna_vb[1] - A[2] * rtP.P_F.antenna_vb
                       [0]) + A[0] * rtP.P_F.antenna_vb[2]) +
    rtP.Constant_Value_gd * A[3];

  /* Sum: '<S51>/Sum1' incorporates:
   *  DotProduct: '<S51>/Dot Product'
   *  Product: '<S51>/Product2'
   *  Sum: '<S50>/Sum'
   */
  t = rtb_Product5 * rtb_Gain1_d_idx_0 - ((rtb_Gain1_d_idx_1 * rtb_vector_idx_0
    + rtb_Gain1_d_idx_2 * rtb_vector_idx_1) + rtb_qA2B_idx_2 * rtb_vector_idx_2);

  /* Product: '<S33>/Product' incorporates:
   *  Product: '<S51>/Product'
   *  Product: '<S51>/Product1'
   *  Product: '<S54>/Product'
   *  Product: '<S54>/Product1'
   *  Product: '<S54>/Product2'
   *  Product: '<S54>/Product3'
   *  Product: '<S54>/Product4'
   *  Product: '<S54>/Product5'
   *  Sum: '<S50>/Sum'
   *  Sum: '<S51>/Sum'
   *  Sum: '<S54>/Sum'
   *  Sum: '<S54>/Sum1'
   *  Sum: '<S54>/Sum2'
   */
  rtB.Product_a[0] = (((rtb_vector_idx_1 * rtb_qA2B_idx_2 - rtb_vector_idx_2 *
                        rtb_Gain1_d_idx_2) + rtb_Product5 * rtb_Gain1_d_idx_1) +
                      rtb_Gain1_d_idx_0 * rtb_vector_idx_0) * (1.0 / t);
  rtB.Product_a[1] = (((rtb_vector_idx_2 * rtb_Gain1_d_idx_1 - rtb_vector_idx_0 *
                        rtb_qA2B_idx_2) + rtb_Product5 * rtb_Gain1_d_idx_2) +
                      rtb_Gain1_d_idx_0 * rtb_vector_idx_1) * (1.0 / t);
  rtB.Product_a[2] = (((rtb_vector_idx_0 * rtb_Gain1_d_idx_2 - rtb_vector_idx_1 *
                        rtb_Gain1_d_idx_1) + rtb_Product5 * rtb_qA2B_idx_2) +
                      rtb_Gain1_d_idx_0 * rtb_vector_idx_2) * (1.0 / t);

  /* Gain: '<S47>/Gain1' */
  A[0] = rtP.Gain1_Gain_n[0] * rtb_Gain1_d_idx_0;
  A[1] = rtP.Gain1_Gain_n[1] * rtb_Gain1_d_idx_1;
  A[2] = rtP.Gain1_Gain_n[2] * rtb_Gain1_d_idx_2;
  A[3] = rtP.Gain1_Gain_n[3] * rtb_qA2B_idx_2;

  /* Sum: '<S45>/Sum1' incorporates:
   *  Constant: '<Root>/Constant2'
   *  Constant: '<S32>/Constant'
   *  DotProduct: '<S45>/Dot Product'
   *  Product: '<S45>/Product2'
   */
  rtb_Product5 = A[0] * rtP.Constant_Value_m - ((rtP.P_F.thruster_vb[0] * A[1] +
    rtP.P_F.thruster_vb[1] * A[2]) + rtP.P_F.thruster_vb[2] * A[3]);

  /* Sum: '<S45>/Sum' incorporates:
   *  Constant: '<Root>/Constant2'
   *  Constant: '<S32>/Constant'
   *  Product: '<S45>/Product'
   *  Product: '<S45>/Product1'
   *  Product: '<S48>/Product'
   *  Product: '<S48>/Product1'
   *  Product: '<S48>/Product2'
   *  Product: '<S48>/Product3'
   *  Product: '<S48>/Product4'
   *  Product: '<S48>/Product5'
   *  Sum: '<S48>/Sum'
   *  Sum: '<S48>/Sum1'
   *  Sum: '<S48>/Sum2'
   */
  rtb_vector_idx_0 = ((A[2] * rtP.P_F.thruster_vb[2] - A[3] *
                       rtP.P_F.thruster_vb[1]) + A[0] * rtP.P_F.thruster_vb[0])
    + rtP.Constant_Value_m * A[1];
  rtb_vector_idx_1 = ((A[3] * rtP.P_F.thruster_vb[0] - A[1] *
                       rtP.P_F.thruster_vb[2]) + A[0] * rtP.P_F.thruster_vb[1])
    + rtP.Constant_Value_m * A[2];
  rtb_vector_idx_2 = ((A[1] * rtP.P_F.thruster_vb[1] - A[2] *
                       rtP.P_F.thruster_vb[0]) + A[0] * rtP.P_F.thruster_vb[2])
    + rtP.Constant_Value_m * A[3];

  /* Sum: '<S46>/Sum1' incorporates:
   *  DotProduct: '<S46>/Dot Product'
   *  Product: '<S46>/Product2'
   *  Sum: '<S45>/Sum'
   */
  t = rtb_Product5 * rtb_Gain1_d_idx_0 - ((rtb_Gain1_d_idx_1 * rtb_vector_idx_0
    + rtb_Gain1_d_idx_2 * rtb_vector_idx_1) + rtb_qA2B_idx_2 * rtb_vector_idx_2);

  /* Product: '<S32>/Product' incorporates:
   *  Product: '<S46>/Product'
   *  Product: '<S46>/Product1'
   *  Product: '<S49>/Product'
   *  Product: '<S49>/Product1'
   *  Product: '<S49>/Product2'
   *  Product: '<S49>/Product3'
   *  Product: '<S49>/Product4'
   *  Product: '<S49>/Product5'
   *  Sum: '<S45>/Sum'
   *  Sum: '<S46>/Sum'
   *  Sum: '<S49>/Sum'
   *  Sum: '<S49>/Sum1'
   *  Sum: '<S49>/Sum2'
   */
  rtB.Product_d[0] = (((rtb_vector_idx_1 * rtb_qA2B_idx_2 - rtb_vector_idx_2 *
                        rtb_Gain1_d_idx_2) + rtb_Product5 * rtb_Gain1_d_idx_1) +
                      rtb_Gain1_d_idx_0 * rtb_vector_idx_0) * (1.0 / t);
  rtB.Product_d[1] = (((rtb_vector_idx_2 * rtb_Gain1_d_idx_1 - rtb_vector_idx_0 *
                        rtb_qA2B_idx_2) + rtb_Product5 * rtb_Gain1_d_idx_2) +
                      rtb_Gain1_d_idx_0 * rtb_vector_idx_1) * (1.0 / t);
  rtB.Product_d[2] = (((rtb_vector_idx_0 * rtb_Gain1_d_idx_2 - rtb_vector_idx_1 *
                        rtb_Gain1_d_idx_1) + rtb_Product5 * rtb_qA2B_idx_2) +
                      rtb_Gain1_d_idx_0 * rtb_vector_idx_2) * (1.0 / t);
  if (ssIsSampleHit(rtS, 1, 0)) {
  }

  /* Gain: '<S17>/Gain' incorporates:
   *  Constant: '<S17>/Constant'
   *  DotProduct: '<S18>/Dot Product'
   *  Inport: '<Root>/x'
   *  Product: '<S18>/Product'
   *  Product: '<S18>/Product1'
   *  Product: '<S18>/Product2'
   *  Product: '<S19>/Product'
   *  Product: '<S19>/Product1'
   *  Product: '<S19>/Product2'
   *  Product: '<S19>/Product3'
   *  Product: '<S19>/Product4'
   *  Product: '<S19>/Product5'
   *  Sum: '<S18>/Sum'
   *  Sum: '<S18>/Sum1'
   *  Sum: '<S19>/Sum'
   *  Sum: '<S19>/Sum1'
   *  Sum: '<S19>/Sum2'
   */
  rtB.q_dot[0] = (rtB.y[0] * rtP.Constant_Value_bp - ((rtU.omega[0] * rtB.y[1] +
    rtU.omega[1] * rtB.y[2]) + rtU.omega[2] * rtB.y[3])) * rtP.Gain_Gain;
  rtB.q_dot[1] = (((rtB.y[2] * rtU.omega[2] - rtB.y[3] * rtU.omega[1]) + rtB.y[0]
                   * rtU.omega[0]) + rtP.Constant_Value_bp * rtB.y[1]) *
    rtP.Gain_Gain;
  rtB.q_dot[2] = (((rtB.y[3] * rtU.omega[0] - rtB.y[1] * rtU.omega[2]) + rtB.y[0]
                   * rtU.omega[1]) + rtP.Constant_Value_bp * rtB.y[2]) *
    rtP.Gain_Gain;
  rtB.q_dot[3] = (((rtB.y[1] * rtU.omega[1] - rtB.y[2] * rtU.omega[0]) + rtB.y[0]
                   * rtU.omega[2]) + rtP.Constant_Value_bp * rtB.y[3]) *
    rtP.Gain_Gain;
  if (ssIsSampleHit(rtS, 1, 0)) {
  }

  /* Sum: '<S61>/Sum of Elements' incorporates:
   *  Math: '<S61>/Math Function'
   */
  rtb_Product5 = (rtB.Product_d[0] * rtB.Product_d[0] + rtB.Product_d[1] *
                  rtB.Product_d[1]) + rtB.Product_d[2] * rtB.Product_d[2];

  /* Math: '<S61>/Math Function1'
   *
   * About '<S61>/Math Function1':
   *  Operator: sqrt
   */
  if (rtb_Product5 < 0.0) {
    rtb_Product5 = -sqrt(fabs(rtb_Product5));
  } else {
    rtb_Product5 = sqrt(rtb_Product5);
  }

  /* End of Math: '<S61>/Math Function1' */

  /* Switch: '<S61>/Switch' incorporates:
   *  Constant: '<S61>/Constant'
   *  Product: '<S61>/Product'
   */
  if (rtb_Product5 > rtP.NormalizeVector_maxzero_f) {
    A[0] = rtB.Product_d[0];
    A[1] = rtB.Product_d[1];
    A[2] = rtB.Product_d[2];
    A[3] = rtb_Product5;
  } else {
    A[0] = rtB.Product_d[0] * 0.0;
    A[1] = rtB.Product_d[1] * 0.0;
    A[2] = rtB.Product_d[2] * 0.0;
    A[3] = rtP.Constant_Value_i2;
  }

  /* End of Switch: '<S61>/Switch' */

  /* Product: '<S61>/Divide' */
  rtb_vector_idx_0 = A[0] / A[3];
  rtb_vector_idx_1 = A[1] / A[3];
  rtb_vector_idx_2 = A[2] / A[3];

  /* Sum: '<S62>/Sum of Elements' incorporates:
   *  Math: '<S62>/Math Function'
   */
  rtb_Product5 = (rtB.E.thrust_vector[0] * rtB.E.thrust_vector[0] +
                  rtB.E.thrust_vector[1] * rtB.E.thrust_vector[1]) +
    rtB.E.thrust_vector[2] * rtB.E.thrust_vector[2];

  /* Math: '<S62>/Math Function1'
   *
   * About '<S62>/Math Function1':
   *  Operator: sqrt
   */
  if (rtb_Product5 < 0.0) {
    rtb_Product5 = -sqrt(fabs(rtb_Product5));
  } else {
    rtb_Product5 = sqrt(rtb_Product5);
  }

  /* End of Math: '<S62>/Math Function1' */

  /* Switch: '<S62>/Switch' incorporates:
   *  Constant: '<S62>/Constant'
   *  Product: '<S62>/Product'
   */
  if (rtb_Product5 > rtP.NormalizeVector1_maxzero_c1) {
    A[0] = rtB.E.thrust_vector[0];
    A[1] = rtB.E.thrust_vector[1];
    A[2] = rtB.E.thrust_vector[2];
    A[3] = rtb_Product5;
  } else {
    A[0] = rtB.E.thrust_vector[0] * 0.0;
    A[1] = rtB.E.thrust_vector[1] * 0.0;
    A[2] = rtB.E.thrust_vector[2] * 0.0;
    A[3] = rtP.Constant_Value_bf;
  }

  /* End of Switch: '<S62>/Switch' */

  /* DotProduct: '<S9>/Dot Product1' incorporates:
   *  Product: '<S62>/Divide'
   */
  rtB.DotProduct1 = (A[0] / A[3] * rtb_vector_idx_0 + A[1] / A[3] *
                     rtb_vector_idx_1) + A[2] / A[3] * rtb_vector_idx_2;

  /* ManualSwitch: '<S9>/Manual Switch1' incorporates:
   *  Constant: '<S9>/Constant11'
   *  Sum: '<S9>/Subtract1'
   */
  if (rtP.ManualSwitch1_CurrentSetting == 1) {
    rtB.ManualSwitch1 = rtB.DotProduct1;
  } else {
    rtB.ManualSwitch1 = rtP.Constant11_Value_h - rtB.DotProduct1;
  }

  /* End of ManualSwitch: '<S9>/Manual Switch1' */
  if (ssIsSampleHit(rtS, 1, 0)) {
  }

  /* Product: '<S9>/Product' */
  rtB.current_solar_e = rtB.E.thrust_weight * rtB.ManualSwitch1;

  /* Sum: '<S64>/Sum of Elements' incorporates:
   *  Math: '<S64>/Math Function'
   */
  rtb_Product5 = (rtB.E.comms_vector[0] * rtB.E.comms_vector[0] +
                  rtB.E.comms_vector[1] * rtB.E.comms_vector[1]) +
    rtB.E.comms_vector[2] * rtB.E.comms_vector[2];

  /* Math: '<S64>/Math Function1'
   *
   * About '<S64>/Math Function1':
   *  Operator: sqrt
   */
  if (rtb_Product5 < 0.0) {
    rtb_Product5 = -sqrt(fabs(rtb_Product5));
  } else {
    rtb_Product5 = sqrt(rtb_Product5);
  }

  /* End of Math: '<S64>/Math Function1' */

  /* Switch: '<S64>/Switch' incorporates:
   *  Constant: '<S64>/Constant'
   *  Product: '<S64>/Product'
   */
  if (rtb_Product5 > rtP.NormalizeVector_maxzero_p) {
    A[0] = rtB.E.comms_vector[0];
    A[1] = rtB.E.comms_vector[1];
    A[2] = rtB.E.comms_vector[2];
    A[3] = rtb_Product5;
  } else {
    A[0] = rtB.E.comms_vector[0] * 0.0;
    A[1] = rtB.E.comms_vector[1] * 0.0;
    A[2] = rtB.E.comms_vector[2] * 0.0;
    A[3] = rtP.Constant_Value_os;
  }

  /* End of Switch: '<S64>/Switch' */

  /* Product: '<S64>/Divide' */
  rtb_vector_idx_0 = A[0] / A[3];
  rtb_vector_idx_1 = A[1] / A[3];
  rtb_vector_idx_2 = A[2] / A[3];

  /* Sum: '<S65>/Sum of Elements' incorporates:
   *  Math: '<S65>/Math Function'
   */
  rtb_Product5 = (rtB.Product_a[0] * rtB.Product_a[0] + rtB.Product_a[1] *
                  rtB.Product_a[1]) + rtB.Product_a[2] * rtB.Product_a[2];

  /* Math: '<S65>/Math Function1'
   *
   * About '<S65>/Math Function1':
   *  Operator: sqrt
   */
  if (rtb_Product5 < 0.0) {
    rtb_Product5 = -sqrt(fabs(rtb_Product5));
  } else {
    rtb_Product5 = sqrt(rtb_Product5);
  }

  /* End of Math: '<S65>/Math Function1' */

  /* Switch: '<S65>/Switch' incorporates:
   *  Constant: '<S65>/Constant'
   *  Product: '<S65>/Product'
   */
  if (rtb_Product5 > rtP.NormalizeVector1_maxzero_d) {
    A[0] = rtB.Product_a[0];
    A[1] = rtB.Product_a[1];
    A[2] = rtB.Product_a[2];
    A[3] = rtb_Product5;
  } else {
    A[0] = rtB.Product_a[0] * 0.0;
    A[1] = rtB.Product_a[1] * 0.0;
    A[2] = rtB.Product_a[2] * 0.0;
    A[3] = rtP.Constant_Value_n;
  }

  /* End of Switch: '<S65>/Switch' */

  /* DotProduct: '<S10>/Dot Product1' incorporates:
   *  Product: '<S65>/Divide'
   */
  rtb_vector_idx_2 = (A[0] / A[3] * rtb_vector_idx_0 + A[1] / A[3] *
                      rtb_vector_idx_1) + A[2] / A[3] * rtb_vector_idx_2;

  /* ManualSwitch: '<S10>/Manual Switch1' incorporates:
   *  Constant: '<S10>/Constant11'
   *  DotProduct: '<S10>/Dot Product1'
   *  Saturate: '<S10>/Saturation'
   *  Sum: '<S10>/Subtract1'
   */
  if (rtP.ManualSwitch1_CurrentSetting_k == 1) {
    /* Saturate: '<S10>/Saturation' incorporates:
     *  DotProduct: '<S10>/Dot Product1'
     */
    if (rtb_vector_idx_2 > rtP.Saturation_UpperSat_e) {
      rtB.ManualSwitch1_c = rtP.Saturation_UpperSat_e;
    } else if (rtb_vector_idx_2 < rtP.Saturation_LowerSat_n) {
      rtB.ManualSwitch1_c = rtP.Saturation_LowerSat_n;
    } else {
      rtB.ManualSwitch1_c = rtb_vector_idx_2;
    }
  } else {
    if (rtb_vector_idx_2 > rtP.Saturation_UpperSat_e) {
      /* Saturate: '<S10>/Saturation' */
      rtb_vector_idx_2 = rtP.Saturation_UpperSat_e;
    } else {
      if (rtb_vector_idx_2 < rtP.Saturation_LowerSat_n) {
        /* Saturate: '<S10>/Saturation' */
        rtb_vector_idx_2 = rtP.Saturation_LowerSat_n;
      }
    }

    rtB.ManualSwitch1_c = rtP.Constant11_Value_hv - rtb_vector_idx_2;
  }

  /* End of ManualSwitch: '<S10>/Manual Switch1' */
  if (ssIsSampleHit(rtS, 1, 0)) {
  }

  /* Product: '<S10>/Product' */
  rtB.current_solar_e_p = rtB.E.comms_occulted_boolean * rtB.ManualSwitch1_c;

  /* Sum: '<S67>/Sum of Elements' incorporates:
   *  Math: '<S67>/Math Function'
   */
  rtb_Product5 = (rtB.E.solar_vector[0] * rtB.E.solar_vector[0] +
                  rtB.E.solar_vector[1] * rtB.E.solar_vector[1]) +
    rtB.E.solar_vector[2] * rtB.E.solar_vector[2];

  /* Math: '<S67>/Math Function1' incorporates:
   *  Sum: '<S67>/Sum of Elements'
   *
   * About '<S67>/Math Function1':
   *  Operator: sqrt
   */
  if (rtb_Product5 < 0.0) {
    rtb_Product5 = -sqrt(fabs(rtb_Product5));
  } else {
    rtb_Product5 = sqrt(rtb_Product5);
  }

  /* End of Math: '<S67>/Math Function1' */

  /* Switch: '<S67>/Switch' incorporates:
   *  Constant: '<S67>/Constant'
   *  Product: '<S67>/Product'
   */
  if (rtb_Product5 > rtP.NormalizeVector_maxzero_j) {
    A[0] = rtB.E.solar_vector[0];
    A[1] = rtB.E.solar_vector[1];
    A[2] = rtB.E.solar_vector[2];
    A[3] = rtb_Product5;
  } else {
    A[0] = rtB.E.solar_vector[0] * 0.0;
    A[1] = rtB.E.solar_vector[1] * 0.0;
    A[2] = rtB.E.solar_vector[2] * 0.0;
    A[3] = rtP.Constant_Value_ku;
  }

  /* End of Switch: '<S67>/Switch' */

  /* Product: '<S67>/Divide' */
  rtb_vector_idx_0 = A[0] / A[3];
  rtb_vector_idx_1 = A[1] / A[3];
  rtb_vector_idx_2 = A[2] / A[3];

  /* Sum: '<S68>/Sum of Elements' incorporates:
   *  Math: '<S68>/Math Function'
   */
  rtb_Product5 = (rtB.Product_o[0] * rtB.Product_o[0] + rtB.Product_o[1] *
                  rtB.Product_o[1]) + rtB.Product_o[2] * rtB.Product_o[2];

  /* Math: '<S68>/Math Function1'
   *
   * About '<S68>/Math Function1':
   *  Operator: sqrt
   */
  if (rtb_Product5 < 0.0) {
    rtb_Product5 = -sqrt(fabs(rtb_Product5));
  } else {
    rtb_Product5 = sqrt(rtb_Product5);
  }

  /* End of Math: '<S68>/Math Function1' */

  /* Switch: '<S68>/Switch' incorporates:
   *  Constant: '<S68>/Constant'
   *  Product: '<S68>/Product'
   */
  if (rtb_Product5 > rtP.NormalizeVector1_maxzero_g) {
    A[0] = rtB.Product_o[0];
    A[1] = rtB.Product_o[1];
    A[2] = rtB.Product_o[2];
    A[3] = rtb_Product5;
  } else {
    A[0] = rtB.Product_o[0] * 0.0;
    A[1] = rtB.Product_o[1] * 0.0;
    A[2] = rtB.Product_o[2] * 0.0;
    A[3] = rtP.Constant_Value_l;
  }

  /* End of Switch: '<S68>/Switch' */

  /* DotProduct: '<S11>/Dot Product1' incorporates:
   *  Product: '<S68>/Divide'
   */
  rtb_vector_idx_2 = (A[0] / A[3] * rtb_vector_idx_0 + A[1] / A[3] *
                      rtb_vector_idx_1) + A[2] / A[3] * rtb_vector_idx_2;

  /* Saturate: '<S11>/Saturation' incorporates:
   *  DotProduct: '<S11>/Dot Product1'
   */
  if (rtb_vector_idx_2 > rtP.Saturation_UpperSat_l) {
    rtb_vector_idx_2 = rtP.Saturation_UpperSat_l;
  } else {
    if (rtb_vector_idx_2 < rtP.Saturation_LowerSat_pj) {
      rtb_vector_idx_2 = rtP.Saturation_LowerSat_pj;
    }
  }

  /* End of Saturate: '<S11>/Saturation' */

  /* Product: '<S11>/Product' incorporates:
   *  Abs: '<S11>/Abs'
   */
  rtB.current_solar_e_pn = rtB.E.solar_occulted_boolean * fabs(rtb_vector_idx_2);

  /* Clock: '<S2>/Clock1' */
  rtB.Clock1 = ssGetT(rtS);
  if (ssIsSampleHit(rtS, 1, 0)) {
    /* Scope: '<S2>/Scope' incorporates:
     *  Constant: '<S2>/Constant'
     */
    t = 0.999 * rtP.P_E.P;
  }

  /* RelationalOperator: '<S15>/Compare' incorporates:
   *  Constant: '<S15>/Constant'
   *  Constant: '<S2>/Constant'
   *  Sum: '<S2>/Sum'
   */
  rtB.Compare = (0.999 * rtP.P_E.P - rtB.Clock1 <= rtP.Constant_Value_k);

  /* Stop: '<S2>/Stop Simulation' */
  if (ssIsSampleHit(rtS, 1, 0) && rtB.Compare) {
    ssSetStopRequested(rtS, 1);
  }

  /* End of Stop: '<S2>/Stop Simulation' */
  UNUSED_PARAMETER(tid);
}

/* Update for root system: '<Root>' */
void MdlUpdate(int_T tid)
{
  /* Update for Integrator: '<S3>/Integrator' */
  rtDW.Integrator_IWORK = 0;
  UNUSED_PARAMETER(tid);
}

/* Derivatives for root system: '<Root>' */
void MdlDerivatives(void)
{
  XDot *_rtXdot;
  _rtXdot = ((XDot *) ssGetdX(rtS));

  /* Derivatives for Integrator: '<S3>/Integrator' */
  _rtXdot->Integrator_CSTATE[0] = rtB.q_dot[0];
  _rtXdot->Integrator_CSTATE[1] = rtB.q_dot[1];
  _rtXdot->Integrator_CSTATE[2] = rtB.q_dot[2];
  _rtXdot->Integrator_CSTATE[3] = rtB.q_dot[3];

  /* Derivatives for Integrator: '<S11>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = rtB.current_solar_e_pn;

  /* Derivatives for Integrator: '<S10>/Integrator1' */
  _rtXdot->Integrator1_CSTATE_a = rtB.current_solar_e_p;

  /* Derivatives for Integrator: '<S9>/Integrator2' */
  _rtXdot->Integrator2_CSTATE = rtB.E.thrust_weight;

  /* Derivatives for Integrator: '<S9>/Integrator1' */
  _rtXdot->Integrator1_CSTATE_f = rtB.current_solar_e;
}

/* Projection for root system: '<Root>' */
void MdlProjection(void)
{
}

/* Termination for root system: '<Root>' */
void MdlTerminate(void)
{
  /* Terminate for FromFile: '<Root>/From File13' */
  {
    const char *errMsg = (NULL);
    void *fp = (void *) rtDW.FromFile13_PWORK.PrevTimePtr;
    if (fp != (NULL)) {
      errMsg = rtwMatFileLoaderCollectionDestroyInstance( 0, fp );
      if (errMsg != (NULL)) {
        ssSetErrorStatus(rtS, errMsg);
        return;
      }
    }
  }

  attitude3d_MovingMinimum_Term(&rtDW.MovingMinimum);
  attitude3d_MovingMinimum_Term(&rtDW.MovingMinimum_p);
  attitude3d_MovingMaximum_Term(&rtDW.MovingMaximum);
  attitude3d_MovingMaximum_Term(&rtDW.MovingMaximum_p);
}

/* Function to initialize sizes */
void MdlInitializeSizes(void)
{
  ssSetNumContStates(rtS, 8);          /* Number of continuous states */
  ssSetNumPeriodicContStates(rtS, 0); /* Number of periodic continuous states */
  ssSetNumY(rtS, 0);                   /* Number of model outputs */
  ssSetNumU(rtS, 3);                   /* Number of model inputs */
  ssSetDirectFeedThrough(rtS, 1);      /* The model is direct feedthrough */
  ssSetNumSampleTimes(rtS, 2);         /* Number of sample times */
  ssSetNumBlocks(rtS, 430);            /* Number of blocks */
  ssSetNumBlockIO(rtS, 46);            /* Number of block outputs */
  ssSetNumBlockParams(rtS, 217);       /* Sum of parameter "widths" */
}

/* Function to initialize sample times. */
void MdlInitializeSampleTimes(void)
{
  /* task periods */
  ssSetSampleTime(rtS, 0, 0.0);
  ssSetSampleTime(rtS, 1, 10.0);

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

SimStruct * attitude3d(void)
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
    (void)memset(&rtU, 0, sizeof(ExtU));
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
    dtInfo.numDataTypes = 22;
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
  ssSetModelName(rtS, "attitude3d");
  ssSetPath(rtS, "attitude3d");
  ssSetTStart(rtS, 0.0);
  ssSetTFinal(rtS, 6530.0);
  ssSetStepSize(rtS, 10.0);
  ssSetFixedStepSize(rtS, 10.0);

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
    rtliSetLogT(ssGetRTWLogInfo(rtS), "tout");
    rtliSetLogX(ssGetRTWLogInfo(rtS), "");
    rtliSetLogXFinal(ssGetRTWLogInfo(rtS), "");
    rtliSetLogVarNameModifier(ssGetRTWLogInfo(rtS), "rt_");
    rtliSetLogFormat(ssGetRTWLogInfo(rtS), 4);
    rtliSetLogMaxRows(ssGetRTWLogInfo(rtS), 0);
    rtliSetLogDecimation(ssGetRTWLogInfo(rtS), 1);
    rtliSetLogY(ssGetRTWLogInfo(rtS), "");
    rtliSetLogYSignalInfo(ssGetRTWLogInfo(rtS), (NULL));
    rtliSetLogYSignalPtrs(ssGetRTWLogInfo(rtS), (NULL));
  }

  {
    static struct _ssStatesInfo2 statesInfo2;
    ssSetStatesInfo2(rtS, &statesInfo2);
  }

  {
    static ssPeriodicStatesInfo periodicStatesInfo;
    ssSetPeriodicStatesInfo(rtS, &periodicStatesInfo);
  }

  ssSetChecksumVal(rtS, 0, 846969622U);
  ssSetChecksumVal(rtS, 1, 3598695172U);
  ssSetChecksumVal(rtS, 2, 2962041261U);
  ssSetChecksumVal(rtS, 3, 1529343573U);
  return rtS;
}

/* When you use the on parameter, it resets the optimizations to those that you
   specified with the /O compiler option. */
#if defined(_MSC_VER)

#pragma optimize( "", on )

#endif
