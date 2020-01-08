/*
 * attitude3d.c
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

#include <math.h>
#include "attitude3d.h"
#include "attitude3d_private.h"
#include "attitude3d_dt.h"

/* user code (top of parameter file) */
const int_T gblNumToFiles = 0;
const int_T gblNumFrFiles = 13;
const int_T gblNumFrWksBlocks = 0;
const char *gblSlvrJacPatternFileName =
  "attitude3d_rsim_rtw//attitude3d_Jpattern.mat";

/* Root inports information  */
const int_T gblNumRootInportBlks = 0;
const int_T gblNumModelInputs = 0;
extern rtInportTUtable *gblInportTUtables;
extern const char *gblInportFileName;
const int_T gblInportDataTypeIdx[] = { -1 };

const int_T gblInportDims[] = { -1 } ;

const int_T gblInportComplex[] = { -1 };

const int_T gblInportInterpoFlag[] = { -1 };

const int_T gblInportContinuous[] = { -1 };

FrFInfo attitude3d_gblFrFInfo[13];

#include "simstruc.h"
#include "fixedpoint.h"

/* Block signals (default storage) */
B rtB;

/* Continuous states */
X rtX;

/* Block states (default storage) */
DW rtDW;

/* Parent Simstruct */
static SimStruct model_S;
SimStruct *const rtS = &model_S;

/* Forward declaration for local functions */
static void attitude3d_SystemCore_release(dsp_MovingMinimum_attitude3d_T *obj);
static void attitude3d_SystemCore_delete(dsp_MovingMinimum_attitude3d_T *obj);
static void matlabCodegenHandle_matlabCodeg(dsp_MovingMinimum_attitude3d_T *obj);

/* Forward declaration for local functions */
static real_T attitude3d_interp1(const real_T varargin_1[3], const real_T
  varargin_2[3], real_T varargin_3);
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
 *    synthesized block
 */
void attitude3d_MovingMinimum_Init(DW_MovingMinimum_attitude3d_T *localDW)
{
  /* InitializeConditions for MATLABSystem: '<S5>/Moving Minimum' */
  if (localDW->obj.pStat->isInitialized == 1) {
    localDW->obj.pStat->pCumMin = (rtInf);
  }

  /* End of InitializeConditions for MATLABSystem: '<S5>/Moving Minimum' */
}

/*
 * Start for atomic system:
 *    synthesized block
 *    synthesized block
 *    synthesized block
 */
void attitude3d_MovingMinimum_Start(DW_MovingMinimum_attitude3d_T *localDW)
{
  /* Start for MATLABSystem: '<S5>/Moving Minimum' */
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
 *    synthesized block
 */
void attitude3d_MovingMinimum(real_T rtu_0, B_MovingMinimum_attitude3d_T *localB,
  DW_MovingMinimum_attitude3d_T *localDW)
{
  real_T y_idx_1;

  /* MATLABSystem: '<S5>/Moving Minimum' */
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

  /* End of MATLABSystem: '<S5>/Moving Minimum' */
}

/*
 * Termination for atomic system:
 *    synthesized block
 *    synthesized block
 *    synthesized block
 */
void attitude3d_MovingMinimum_Term(DW_MovingMinimum_attitude3d_T *localDW)
{
  /* Terminate for MATLABSystem: '<S5>/Moving Minimum' */
  matlabCodegenHandle_matlabCodeg(&localDW->obj);
}

/* Function for MATLAB Function: '<Root>/Interpolator ' */
static real_T attitude3d_interp1(const real_T varargin_1[3], const real_T
  varargin_2[3], real_T varargin_3)
{
  real_T Vq;
  real_T y[3];
  real_T x[3];
  real_T r;
  int32_T low_i;
  real_T tmp;
  int32_T exitg1;
  y[0] = varargin_2[0];
  x[0] = varargin_1[0];
  y[1] = varargin_2[1];
  x[1] = varargin_1[1];
  y[2] = varargin_2[2];
  x[2] = varargin_1[2];
  Vq = (rtNaN);
  low_i = 0;
  do {
    exitg1 = 0;
    if (low_i < 3) {
      if (rtIsNaN(varargin_1[low_i])) {
        exitg1 = 1;
      } else {
        low_i++;
      }
    } else {
      if (varargin_1[1] < varargin_1[0]) {
        x[0] = varargin_1[2];
        x[2] = varargin_1[0];
        y[0] = varargin_2[2];
        y[2] = varargin_2[0];
      }

      if ((!rtIsNaN(varargin_3)) && (!(varargin_3 > x[2])) && (!(varargin_3 < x
            [0]))) {
        low_i = 0;
        if (varargin_3 >= varargin_1[1]) {
          low_i = 1;
        }

        r = (varargin_3 - x[low_i]) / (x[low_i + 1] - x[low_i]);
        if (r == 0.0) {
          Vq = y[low_i];
        } else if (r == 1.0) {
          Vq = y[low_i + 1];
        } else {
          tmp = y[low_i + 1];
          if (tmp == y[low_i]) {
            Vq = y[low_i];
          } else {
            Vq = (1.0 - r) * y[low_i] + tmp * r;
          }
        }
      }

      exitg1 = 1;
    }
  } while (exitg1 == 0);

  return Vq;
}

/* System initialize for root system: '<Root>' */
void MdlInitialize(void)
{
  int32_T i;

  /* InitializeConditions for Integrator: '<S10>/Integrator1' */
  rtX.Integrator1_CSTATE = rtP.Integrator1_IC;

  /* InitializeConditions for DiscreteFir: '<S11>/Discrete FIR Filter' */
  rtDW.DiscreteFIRFilter_states[0] = rtP.DiscreteFIRFilter_InitialStates;
  rtDW.DiscreteFIRFilter_states[1] = rtP.DiscreteFIRFilter_InitialStates;
  rtDW.DiscreteFIRFilter_states[2] = rtP.DiscreteFIRFilter_InitialStates;

  /* InitializeConditions for Integrator: '<S9>/Integrator1' */
  rtX.Integrator1_CSTATE_a = rtP.Integrator1_IC_k;

  /* InitializeConditions for DiscreteFir: '<S12>/Discrete FIR Filter' */
  for (i = 0; i < 5; i++) {
    rtDW.DiscreteFIRFilter_states_d[i] = rtP.DiscreteFIRFilter_InitialStat_l;
  }

  /* End of InitializeConditions for DiscreteFir: '<S12>/Discrete FIR Filter' */

  /* InitializeConditions for Integrator: '<S4>/Integrator' */
  if (ssIsFirstInitCond(rtS)) {
    rtX.Integrator_CSTATE[0] = 0.0;
    rtX.Integrator_CSTATE[1] = 0.0;
    rtX.Integrator_CSTATE[2] = 0.0;
    rtX.Integrator_CSTATE[3] = 0.0;
  }

  rtDW.Integrator_IWORK = 1;

  /* End of InitializeConditions for Integrator: '<S4>/Integrator' */

  /* InitializeConditions for Integrator: '<S8>/Integrator2' */
  rtX.Integrator2_CSTATE = rtP.Integrator2_IC;

  /* InitializeConditions for Integrator: '<S8>/Integrator1' */
  rtX.Integrator1_CSTATE_f = rtP.Integrator1_IC_b;
  attitude3d_MovingMinimum_Init(&rtDW.MovingMinimum);
  attitude3d_MovingMinimum_Init(&rtDW.MovingMinimum_p);
  attitude3d_MovingMinimum_Init(&rtDW.MovingMinimum_pn);
}

/* Start for root system: '<Root>' */
void MdlStart(void)
{
  /* Start for FromFile: '<Root>/From File' */
  {
    char fileName[509] = "env/r_target.mat";
    rt_RSimRemapFromFileName(fileName);

    {
      void *fp = (NULL);
      const char *errMsg = (NULL);
      errMsg = rtwMatFileLoaderCollectionCreateInstance( 0, &fp );
      if (errMsg != (NULL)) {
        ssSetErrorStatus(rtS, errMsg);
        return;
      }

      rtDW.FromFile_PWORK.PrevTimePtr = fp;

      {
        unsigned char groundValue[] = { 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U } ;

        const int enumNStrings = 0;
        const char **enumStrings = (NULL);
        const int32_T *enumValues = (NULL);
        int_T dimensions[1] = { 3 };

        errMsg = rtwMatFileLoaderCollectionAddElement(0, fp, fileName, "", 0, 0,
          0, 0, groundValue, "double", 0, 1, dimensions, 0, 0, 0, 0, 0, 0, 0, 0,
          enumNStrings, enumStrings, enumValues, 1, 1, "attitude3d/From File" );
        if (errMsg != (NULL)) {
          ssSetErrorStatus(rtS, errMsg);
          return;
        }
      }
    }
  }

  /* Start for FromFile: '<Root>/From File1' */
  {
    char fileName[509] = "env/r_satellite.mat";
    rt_RSimRemapFromFileName(fileName);

    {
      void *fp = (NULL);
      const char *errMsg = (NULL);
      errMsg = rtwMatFileLoaderCollectionCreateInstance( 0, &fp );
      if (errMsg != (NULL)) {
        ssSetErrorStatus(rtS, errMsg);
        return;
      }

      rtDW.FromFile1_PWORK.PrevTimePtr = fp;

      {
        unsigned char groundValue[] = { 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U } ;

        const int enumNStrings = 0;
        const char **enumStrings = (NULL);
        const int32_T *enumValues = (NULL);
        int_T dimensions[1] = { 3 };

        errMsg = rtwMatFileLoaderCollectionAddElement(0, fp, fileName, "", 0, 0,
          0, 0, groundValue, "double", 0, 1, dimensions, 0, 0, 0, 0, 0, 0, 0, 0,
          enumNStrings, enumStrings, enumValues, 1, 1, "attitude3d/From File1" );
        if (errMsg != (NULL)) {
          ssSetErrorStatus(rtS, errMsg);
          return;
        }
      }
    }
  }

  /* Start for FromFile: '<Root>/From File6' */
  {
    char fileName[509] = "env/r_comms.mat";
    rt_RSimRemapFromFileName(fileName);

    {
      void *fp = (NULL);
      const char *errMsg = (NULL);
      errMsg = rtwMatFileLoaderCollectionCreateInstance( 0, &fp );
      if (errMsg != (NULL)) {
        ssSetErrorStatus(rtS, errMsg);
        return;
      }

      rtDW.FromFile6_PWORK.PrevTimePtr = fp;

      {
        unsigned char groundValue[] = { 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U } ;

        const int enumNStrings = 0;
        const char **enumStrings = (NULL);
        const int32_T *enumValues = (NULL);
        int_T dimensions[1] = { 3 };

        errMsg = rtwMatFileLoaderCollectionAddElement(0, fp, fileName, "", 0, 0,
          0, 0, groundValue, "double", 0, 1, dimensions, 0, 0, 0, 0, 0, 0, 0, 0,
          enumNStrings, enumStrings, enumValues, 1, 1, "attitude3d/From File6" );
        if (errMsg != (NULL)) {
          ssSetErrorStatus(rtS, errMsg);
          return;
        }
      }
    }
  }

  /* Start for FromFile: '<Root>/From File7' */
  {
    char fileName[509] = "env/v_target.mat";
    rt_RSimRemapFromFileName(fileName);

    {
      void *fp = (NULL);
      const char *errMsg = (NULL);
      errMsg = rtwMatFileLoaderCollectionCreateInstance( 0, &fp );
      if (errMsg != (NULL)) {
        ssSetErrorStatus(rtS, errMsg);
        return;
      }

      rtDW.FromFile7_PWORK.PrevTimePtr = fp;

      {
        unsigned char groundValue[] = { 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U } ;

        const int enumNStrings = 0;
        const char **enumStrings = (NULL);
        const int32_T *enumValues = (NULL);
        int_T dimensions[1] = { 3 };

        errMsg = rtwMatFileLoaderCollectionAddElement(0, fp, fileName, "", 0, 0,
          0, 0, groundValue, "double", 0, 1, dimensions, 0, 0, 0, 0, 0, 0, 0, 0,
          enumNStrings, enumStrings, enumValues, 1, 1, "attitude3d/From File7" );
        if (errMsg != (NULL)) {
          ssSetErrorStatus(rtS, errMsg);
          return;
        }
      }
    }
  }

  /* Start for FromFile: '<Root>/From File2' */
  {
    char fileName[509] = "env/v_satellite.mat";
    rt_RSimRemapFromFileName(fileName);

    {
      void *fp = (NULL);
      const char *errMsg = (NULL);
      errMsg = rtwMatFileLoaderCollectionCreateInstance( 0, &fp );
      if (errMsg != (NULL)) {
        ssSetErrorStatus(rtS, errMsg);
        return;
      }

      rtDW.FromFile2_PWORK.PrevTimePtr = fp;

      {
        unsigned char groundValue[] = { 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U } ;

        const int enumNStrings = 0;
        const char **enumStrings = (NULL);
        const int32_T *enumValues = (NULL);
        int_T dimensions[1] = { 3 };

        errMsg = rtwMatFileLoaderCollectionAddElement(0, fp, fileName, "", 0, 0,
          0, 0, groundValue, "double", 0, 1, dimensions, 0, 0, 0, 0, 0, 0, 0, 0,
          enumNStrings, enumStrings, enumValues, 1, 1, "attitude3d/From File2" );
        if (errMsg != (NULL)) {
          ssSetErrorStatus(rtS, errMsg);
          return;
        }
      }
    }
  }

  /* Start for FromFile: '<Root>/From File3' */
  {
    char fileName[509] = "env/v_comms.mat";
    rt_RSimRemapFromFileName(fileName);

    {
      void *fp = (NULL);
      const char *errMsg = (NULL);
      errMsg = rtwMatFileLoaderCollectionCreateInstance( 0, &fp );
      if (errMsg != (NULL)) {
        ssSetErrorStatus(rtS, errMsg);
        return;
      }

      rtDW.FromFile3_PWORK.PrevTimePtr = fp;

      {
        unsigned char groundValue[] = { 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U } ;

        const int enumNStrings = 0;
        const char **enumStrings = (NULL);
        const int32_T *enumValues = (NULL);
        int_T dimensions[1] = { 3 };

        errMsg = rtwMatFileLoaderCollectionAddElement(0, fp, fileName, "", 0, 0,
          0, 0, groundValue, "double", 0, 1, dimensions, 0, 0, 0, 0, 0, 0, 0, 0,
          enumNStrings, enumStrings, enumValues, 1, 1, "attitude3d/From File3" );
        if (errMsg != (NULL)) {
          ssSetErrorStatus(rtS, errMsg);
          return;
        }
      }
    }
  }

  /* Start for FromFile: '<Root>/From File4' */
  {
    char fileName[509] = "env/solar_v.mat";
    rt_RSimRemapFromFileName(fileName);

    {
      void *fp = (NULL);
      const char *errMsg = (NULL);
      errMsg = rtwMatFileLoaderCollectionCreateInstance( 0, &fp );
      if (errMsg != (NULL)) {
        ssSetErrorStatus(rtS, errMsg);
        return;
      }

      rtDW.FromFile4_PWORK.PrevTimePtr = fp;

      {
        unsigned char groundValue[] = { 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U } ;

        const int enumNStrings = 0;
        const char **enumStrings = (NULL);
        const int32_T *enumValues = (NULL);
        int_T dimensions[1] = { 3 };

        errMsg = rtwMatFileLoaderCollectionAddElement(0, fp, fileName, "", 0, 0,
          0, 0, groundValue, "double", 0, 1, dimensions, 0, 0, 0, 0, 0, 0, 0, 0,
          enumNStrings, enumStrings, enumValues, 1, 1, "attitude3d/From File4" );
        if (errMsg != (NULL)) {
          ssSetErrorStatus(rtS, errMsg);
          return;
        }
      }
    }
  }

  /* Start for FromFile: '<Root>/From File9' */
  {
    char fileName[509] = "env/integral_solar.mat";
    rt_RSimRemapFromFileName(fileName);

    {
      void *fp = (NULL);
      const char *errMsg = (NULL);
      errMsg = rtwMatFileLoaderCollectionCreateInstance( 0, &fp );
      if (errMsg != (NULL)) {
        ssSetErrorStatus(rtS, errMsg);
        return;
      }

      rtDW.FromFile9_PWORK.PrevTimePtr = fp;

      {
        unsigned char groundValue[] = { 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U } ;

        const int enumNStrings = 0;
        const char **enumStrings = (NULL);
        const int32_T *enumValues = (NULL);
        int_T dimensions[1] = { 1 };

        errMsg = rtwMatFileLoaderCollectionAddElement(0, fp, fileName, "", 0, 0,
          0, 0, groundValue, "double", 0, 1, dimensions, 0, 0, 0, 0, 0, 0, 0, 0,
          enumNStrings, enumStrings, enumValues, 1, 1, "attitude3d/From File9" );
        if (errMsg != (NULL)) {
          ssSetErrorStatus(rtS, errMsg);
          return;
        }
      }
    }
  }

  /* Start for FromFile: '<Root>/From File10' */
  {
    char fileName[509] = "env/sight_solar.mat";
    rt_RSimRemapFromFileName(fileName);

    {
      void *fp = (NULL);
      const char *errMsg = (NULL);
      errMsg = rtwMatFileLoaderCollectionCreateInstance( 0, &fp );
      if (errMsg != (NULL)) {
        ssSetErrorStatus(rtS, errMsg);
        return;
      }

      rtDW.FromFile10_PWORK.PrevTimePtr = fp;

      {
        unsigned char groundValue[] = { 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U } ;

        const int enumNStrings = 0;
        const char **enumStrings = (NULL);
        const int32_T *enumValues = (NULL);
        int_T dimensions[1] = { 1 };

        errMsg = rtwMatFileLoaderCollectionAddElement(0, fp, fileName, "", 0, 0,
          0, 0, groundValue, "double", 0, 1, dimensions, 0, 0, 0, 0, 0, 0, 0, 0,
          enumNStrings, enumStrings, enumValues, 1, 1, "attitude3d/From File10" );
        if (errMsg != (NULL)) {
          ssSetErrorStatus(rtS, errMsg);
          return;
        }
      }
    }
  }

  /* Start for FromFile: '<Root>/From File11' */
  {
    char fileName[509] = "env/comms_v.mat";
    rt_RSimRemapFromFileName(fileName);

    {
      void *fp = (NULL);
      const char *errMsg = (NULL);
      errMsg = rtwMatFileLoaderCollectionCreateInstance( 0, &fp );
      if (errMsg != (NULL)) {
        ssSetErrorStatus(rtS, errMsg);
        return;
      }

      rtDW.FromFile11_PWORK.PrevTimePtr = fp;

      {
        unsigned char groundValue[] = { 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U } ;

        const int enumNStrings = 0;
        const char **enumStrings = (NULL);
        const int32_T *enumValues = (NULL);
        int_T dimensions[1] = { 3 };

        errMsg = rtwMatFileLoaderCollectionAddElement(0, fp, fileName, "", 0, 0,
          0, 0, groundValue, "double", 0, 1, dimensions, 0, 0, 0, 0, 0, 0, 0, 0,
          enumNStrings, enumStrings, enumValues, 1, 1, "attitude3d/From File11" );
        if (errMsg != (NULL)) {
          ssSetErrorStatus(rtS, errMsg);
          return;
        }
      }
    }
  }

  /* Start for FromFile: '<Root>/From File5' */
  {
    char fileName[509] = "env/integral_comms.mat";
    rt_RSimRemapFromFileName(fileName);

    {
      void *fp = (NULL);
      const char *errMsg = (NULL);
      errMsg = rtwMatFileLoaderCollectionCreateInstance( 0, &fp );
      if (errMsg != (NULL)) {
        ssSetErrorStatus(rtS, errMsg);
        return;
      }

      rtDW.FromFile5_PWORK.PrevTimePtr = fp;

      {
        unsigned char groundValue[] = { 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U } ;

        const int enumNStrings = 0;
        const char **enumStrings = (NULL);
        const int32_T *enumValues = (NULL);
        int_T dimensions[1] = { 1 };

        errMsg = rtwMatFileLoaderCollectionAddElement(0, fp, fileName, "", 0, 0,
          0, 0, groundValue, "double", 0, 1, dimensions, 0, 0, 0, 0, 0, 0, 0, 0,
          enumNStrings, enumStrings, enumValues, 1, 1, "attitude3d/From File5" );
        if (errMsg != (NULL)) {
          ssSetErrorStatus(rtS, errMsg);
          return;
        }
      }
    }
  }

  /* Start for FromFile: '<Root>/From File12' */
  {
    char fileName[509] = "env/sight_comms.mat";
    rt_RSimRemapFromFileName(fileName);

    {
      void *fp = (NULL);
      const char *errMsg = (NULL);
      errMsg = rtwMatFileLoaderCollectionCreateInstance( 0, &fp );
      if (errMsg != (NULL)) {
        ssSetErrorStatus(rtS, errMsg);
        return;
      }

      rtDW.FromFile12_PWORK.PrevTimePtr = fp;

      {
        unsigned char groundValue[] = { 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U } ;

        const int enumNStrings = 0;
        const char **enumStrings = (NULL);
        const int32_T *enumValues = (NULL);
        int_T dimensions[1] = { 1 };

        errMsg = rtwMatFileLoaderCollectionAddElement(0, fp, fileName, "", 0, 0,
          0, 0, groundValue, "double", 0, 1, dimensions, 0, 0, 0, 0, 0, 0, 0, 0,
          enumNStrings, enumStrings, enumValues, 1, 1, "attitude3d/From File12" );
        if (errMsg != (NULL)) {
          ssSetErrorStatus(rtS, errMsg);
          return;
        }
      }
    }
  }

  /* Start for FromFile: '<Root>/From File8' */
  {
    char fileName[509] = "env/thrust_v_ref.mat";
    rt_RSimRemapFromFileName(fileName);

    {
      void *fp = (NULL);
      const char *errMsg = (NULL);
      errMsg = rtwMatFileLoaderCollectionCreateInstance( 0, &fp );
      if (errMsg != (NULL)) {
        ssSetErrorStatus(rtS, errMsg);
        return;
      }

      rtDW.FromFile8_PWORK.PrevTimePtr = fp;

      {
        unsigned char groundValue[] = { 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U } ;

        const int enumNStrings = 0;
        const char **enumStrings = (NULL);
        const int32_T *enumValues = (NULL);
        int_T dimensions[1] = { 3 };

        errMsg = rtwMatFileLoaderCollectionAddElement(0, fp, fileName, "", 0, 0,
          0, 0, groundValue, "double", 0, 1, dimensions, 0, 0, 0, 0, 0, 0, 0, 0,
          enumNStrings, enumStrings, enumValues, 1, 1, "attitude3d/From File8" );
        if (errMsg != (NULL)) {
          ssSetErrorStatus(rtS, errMsg);
          return;
        }
      }
    }
  }

  attitude3d_MovingMinimum_Start(&rtDW.MovingMinimum);
  attitude3d_MovingMinimum_Start(&rtDW.MovingMinimum_p);
  attitude3d_MovingMinimum_Start(&rtDW.MovingMinimum_pn);
  MdlInitialize();
}

/* Outputs for root system: '<Root>' */
void MdlOutputs(int_T tid)
{
  /* local block i/o variables */
  real_T rtb_DiscreteFIRFilter;
  int32_T j;
  real_T A[4];
  real_T D;
  int32_T idx;
  real_T scale;
  real_T absxk;
  real_T t;
  int32_T i;
  real_T tmp[16];
  real_T A_0;
  real_T rtb_Switch_idx_3;
  real_T rtb_Switch_idx_0;
  real_T rtb_Switch_idx_2;
  real_T rtb_Switch_idx_1;
  real_T rtb_Divide_idx_0;
  real_T rtb_Divide_idx_1;
  real_T rtb_Divide_f_idx_2;
  boolean_T exitg1;

  /* FromFile: '<Root>/From File' */
  {
    void *fp = (void *) rtDW.FromFile_PWORK.PrevTimePtr;
    const char *errMsg = (NULL);
    if (fp != (NULL) && (ssIsMajorTimeStep(rtS) || !0) ) {
      real_T t = ssGetTaskTime(rtS,0);

      {
        void *y = &rtB.r_target[0];
        errMsg = rtwMatFileLoaderCollectionGetOutput( 0, fp, 0, t,
          ssIsMajorTimeStep(rtS), &y );
        if (errMsg != (NULL)) {
          ssSetErrorStatus(rtS, errMsg);
          return;
        }
      }
    }
  }

  /* FromFile: '<Root>/From File1' */
  {
    void *fp = (void *) rtDW.FromFile1_PWORK.PrevTimePtr;
    const char *errMsg = (NULL);
    if (fp != (NULL) && (ssIsMajorTimeStep(rtS) || !0) ) {
      real_T t = ssGetTaskTime(rtS,0);

      {
        void *y = &rtB.r_satellite[0];
        errMsg = rtwMatFileLoaderCollectionGetOutput( 0, fp, 0, t,
          ssIsMajorTimeStep(rtS), &y );
        if (errMsg != (NULL)) {
          ssSetErrorStatus(rtS, errMsg);
          return;
        }
      }
    }
  }

  /* FromFile: '<Root>/From File6' */
  {
    void *fp = (void *) rtDW.FromFile6_PWORK.PrevTimePtr;
    const char *errMsg = (NULL);
    if (fp != (NULL) && (ssIsMajorTimeStep(rtS) || !0) ) {
      real_T t = ssGetTaskTime(rtS,0);

      {
        void *y = &rtB.r_comms[0];
        errMsg = rtwMatFileLoaderCollectionGetOutput( 0, fp, 0, t,
          ssIsMajorTimeStep(rtS), &y );
        if (errMsg != (NULL)) {
          ssSetErrorStatus(rtS, errMsg);
          return;
        }
      }
    }
  }

  /* FromFile: '<Root>/From File7' */
  {
    void *fp = (void *) rtDW.FromFile7_PWORK.PrevTimePtr;
    const char *errMsg = (NULL);
    if (fp != (NULL) && (ssIsMajorTimeStep(rtS) || !0) ) {
      real_T t = ssGetTaskTime(rtS,0);

      {
        void *y = &rtB.v_target[0];
        errMsg = rtwMatFileLoaderCollectionGetOutput( 0, fp, 0, t,
          ssIsMajorTimeStep(rtS), &y );
        if (errMsg != (NULL)) {
          ssSetErrorStatus(rtS, errMsg);
          return;
        }
      }
    }
  }

  /* FromFile: '<Root>/From File2' */
  {
    void *fp = (void *) rtDW.FromFile2_PWORK.PrevTimePtr;
    const char *errMsg = (NULL);
    if (fp != (NULL) && (ssIsMajorTimeStep(rtS) || !0) ) {
      real_T t = ssGetTaskTime(rtS,0);

      {
        void *y = &rtB.v_satellite[0];
        errMsg = rtwMatFileLoaderCollectionGetOutput( 0, fp, 0, t,
          ssIsMajorTimeStep(rtS), &y );
        if (errMsg != (NULL)) {
          ssSetErrorStatus(rtS, errMsg);
          return;
        }
      }
    }
  }

  /* FromFile: '<Root>/From File3' */
  {
    void *fp = (void *) rtDW.FromFile3_PWORK.PrevTimePtr;
    const char *errMsg = (NULL);
    if (fp != (NULL) && (ssIsMajorTimeStep(rtS) || !0) ) {
      real_T t = ssGetTaskTime(rtS,0);

      {
        void *y = &rtB.v_comms[0];
        errMsg = rtwMatFileLoaderCollectionGetOutput( 0, fp, 0, t,
          ssIsMajorTimeStep(rtS), &y );
        if (errMsg != (NULL)) {
          ssSetErrorStatus(rtS, errMsg);
          return;
        }
      }
    }
  }

  /* FromFile: '<Root>/From File4' */
  {
    void *fp = (void *) rtDW.FromFile4_PWORK.PrevTimePtr;
    const char *errMsg = (NULL);
    if (fp != (NULL) && (ssIsMajorTimeStep(rtS) || !0) ) {
      real_T t = ssGetTaskTime(rtS,0);

      {
        void *y = &rtB.solar_v[0];
        errMsg = rtwMatFileLoaderCollectionGetOutput( 0, fp, 0, t,
          ssIsMajorTimeStep(rtS), &y );
        if (errMsg != (NULL)) {
          ssSetErrorStatus(rtS, errMsg);
          return;
        }
      }
    }
  }

  /* FromFile: '<Root>/From File9' */
  {
    void *fp = (void *) rtDW.FromFile9_PWORK.PrevTimePtr;
    const char *errMsg = (NULL);
    if (fp != (NULL) && (ssIsMajorTimeStep(rtS) || !0) ) {
      real_T t = ssGetTaskTime(rtS,0);

      {
        void *y = &rtB.integral_solar;
        errMsg = rtwMatFileLoaderCollectionGetOutput( 0, fp, 0, t,
          ssIsMajorTimeStep(rtS), &y );
        if (errMsg != (NULL)) {
          ssSetErrorStatus(rtS, errMsg);
          return;
        }
      }
    }
  }

  /* FromFile: '<Root>/From File10' */
  {
    void *fp = (void *) rtDW.FromFile10_PWORK.PrevTimePtr;
    const char *errMsg = (NULL);
    if (fp != (NULL) && (ssIsMajorTimeStep(rtS) || !0) ) {
      real_T t = ssGetTaskTime(rtS,0);

      {
        void *y = &rtB.sight_solar;
        errMsg = rtwMatFileLoaderCollectionGetOutput( 0, fp, 0, t,
          ssIsMajorTimeStep(rtS), &y );
        if (errMsg != (NULL)) {
          ssSetErrorStatus(rtS, errMsg);
          return;
        }
      }
    }
  }

  /* FromFile: '<Root>/From File11' */
  {
    void *fp = (void *) rtDW.FromFile11_PWORK.PrevTimePtr;
    const char *errMsg = (NULL);
    if (fp != (NULL) && (ssIsMajorTimeStep(rtS) || !0) ) {
      real_T t = ssGetTaskTime(rtS,0);

      {
        void *y = &rtB.comms_v[0];
        errMsg = rtwMatFileLoaderCollectionGetOutput( 0, fp, 0, t,
          ssIsMajorTimeStep(rtS), &y );
        if (errMsg != (NULL)) {
          ssSetErrorStatus(rtS, errMsg);
          return;
        }
      }
    }
  }

  /* FromFile: '<Root>/From File5' */
  {
    void *fp = (void *) rtDW.FromFile5_PWORK.PrevTimePtr;
    const char *errMsg = (NULL);
    if (fp != (NULL) && (ssIsMajorTimeStep(rtS) || !0) ) {
      real_T t = ssGetTaskTime(rtS,0);

      {
        void *y = &rtB.integral_comms;
        errMsg = rtwMatFileLoaderCollectionGetOutput( 0, fp, 0, t,
          ssIsMajorTimeStep(rtS), &y );
        if (errMsg != (NULL)) {
          ssSetErrorStatus(rtS, errMsg);
          return;
        }
      }
    }
  }

  /* FromFile: '<Root>/From File12' */
  {
    void *fp = (void *) rtDW.FromFile12_PWORK.PrevTimePtr;
    const char *errMsg = (NULL);
    if (fp != (NULL) && (ssIsMajorTimeStep(rtS) || !0) ) {
      real_T t = ssGetTaskTime(rtS,0);

      {
        void *y = &rtB.sight_comms;
        errMsg = rtwMatFileLoaderCollectionGetOutput( 0, fp, 0, t,
          ssIsMajorTimeStep(rtS), &y );
        if (errMsg != (NULL)) {
          ssSetErrorStatus(rtS, errMsg);
          return;
        }
      }
    }
  }

  /* FromFile: '<Root>/From File8' */
  {
    void *fp = (void *) rtDW.FromFile8_PWORK.PrevTimePtr;
    const char *errMsg = (NULL);
    if (fp != (NULL) && (ssIsMajorTimeStep(rtS) || !0) ) {
      real_T t = ssGetTaskTime(rtS,0);

      {
        void *y = &rtB.thrust_v_ref[0];
        errMsg = rtwMatFileLoaderCollectionGetOutput( 0, fp, 0, t,
          ssIsMajorTimeStep(rtS), &y );
        if (errMsg != (NULL)) {
          ssSetErrorStatus(rtS, errMsg);
          return;
        }
      }
    }
  }

  if (ssIsSampleHit(rtS, 1, 0)) {
  }

  /* Switch: '<S10>/Switch' incorporates:
   *  Constant: '<S10>/Constant'
   *  Constant: '<S36>/Constant'
   *  RelationalOperator: '<S36>/Compare'
   */
  if (rtB.integral_solar == rtP.Constant_Value_b) {
    D = rtP.Constant_Value_b5;
  } else {
    D = rtB.integral_solar;
  }

  /* End of Switch: '<S10>/Switch' */

  /* Product: '<S10>/Divide' incorporates:
   *  Integrator: '<S10>/Integrator1'
   */
  rtB.Divide = 1.0 / D * rtX.Integrator1_CSTATE;
  if (ssIsSampleHit(rtS, 1, 0)) {
    /* DiscreteFir: '<S11>/Discrete FIR Filter' */
    /* Consume delay line and beginning of input samples */
    i = 1;
    D = rtB.Divide * rtP.DiscreteFIRFilter_Coefficients[0];
    for (j = 0; j < 3; j++) {
      D += rtP.DiscreteFIRFilter_Coefficients[j + 1] *
        rtDW.DiscreteFIRFilter_states[j];
    }

    rtb_DiscreteFIRFilter = D;

    /* Update delay line for next frame */
    while (i >= 0) {
      rtDW.DiscreteFIRFilter_states[i + 1] = rtDW.DiscreteFIRFilter_states[i];
      i--;
    }

    rtDW.DiscreteFIRFilter_states[0] = rtB.Divide;

    /* End of DiscreteFir: '<S11>/Discrete FIR Filter' */
  }

  /* Switch: '<S9>/Switch' incorporates:
   *  Constant: '<S33>/Constant'
   *  Constant: '<S9>/Constant'
   *  RelationalOperator: '<S33>/Compare'
   */
  if (rtB.integral_comms == rtP.Constant_Value_c) {
    D = rtP.Constant_Value_o;
  } else {
    D = rtB.integral_comms;
  }

  /* End of Switch: '<S9>/Switch' */

  /* Product: '<S9>/Divide' incorporates:
   *  Integrator: '<S9>/Integrator1'
   */
  rtB.Divide_i = 1.0 / D * rtX.Integrator1_CSTATE_a;
  if (ssIsSampleHit(rtS, 1, 0)) {
    /* DiscreteFir: '<S12>/Discrete FIR Filter' */
    idx = 0;

    /* Consume delay line and beginning of input samples */
    D = rtB.Divide_i * rtP.DiscreteFIRFilter_Coefficient_l[0];
    for (j = 0; j < 5; j++) {
      D += rtP.DiscreteFIRFilter_Coefficient_l[j + 1] *
        rtDW.DiscreteFIRFilter_states_d[j];
    }

    rtb_DiscreteFIRFilter = D;

    /* Update delay line for next frame */
    for (i = 3; i >= 0; i--) {
      rtDW.DiscreteFIRFilter_states_d[i + 1] = rtDW.DiscreteFIRFilter_states_d[i];
    }

    rtDW.DiscreteFIRFilter_states_d[0] = rtB.Divide_i;

    /* End of DiscreteFir: '<S12>/Discrete FIR Filter' */
    /* MATLAB Function: '<S18>/MATLAB Function' incorporates:
     *  Constant: '<Root>/Constant4'
     *  Constant: '<Root>/Constant5'
     *  Constant: '<Root>/Constant6'
     */
    rtB.qA2B[0] = 0.0;
    rtB.qA2B[1] = 0.0;
    rtB.qA2B[2] = 0.0;
    rtB.qA2B[3] = 0.0;
    A[0] = (rtP.init_xBI[0] + rtP.init_yBI[1]) + rtP.init_zBI[2];
    A[1] = (rtP.init_xBI[0] - rtP.init_yBI[1]) - rtP.init_zBI[2];
    A[2] = (-rtP.init_xBI[0] + rtP.init_yBI[1]) - rtP.init_zBI[2];
    A[3] = (-rtP.init_xBI[0] - rtP.init_yBI[1]) + rtP.init_zBI[2];
    if (!rtIsNaN(A[0])) {
      idx = 1;
    } else {
      i = 2;
      exitg1 = false;
      while ((!exitg1) && (i < 5)) {
        if (!rtIsNaN(A[i - 1])) {
          idx = i;
          exitg1 = true;
        } else {
          i++;
        }
      }
    }

    if (idx == 0) {
      idx = 1;
    } else {
      D = A[idx - 1];
      for (i = idx; i < 4; i++) {
        if (D < A[i]) {
          D = A[i];
          idx = i + 1;
        }
      }
    }

    switch (idx) {
     case 1:
      rtB.qA2B[0] = sqrt(A[0] + 1.0) * 0.5;
      D = 1.0 / (4.0 * rtB.qA2B[0]);
      rtB.qA2B[1] = (rtP.init_yBI[2] - rtP.init_zBI[1]) * D;
      rtB.qA2B[2] = (rtP.init_zBI[0] - rtP.init_xBI[2]) * D;
      rtB.qA2B[3] = (rtP.init_xBI[1] - rtP.init_yBI[0]) * D;
      break;

     case 2:
      rtB.qA2B[1] = sqrt(A[1] + 1.0) * 0.5;
      D = 1.0 / (4.0 * rtB.qA2B[1]);
      rtB.qA2B[2] = (rtP.init_xBI[1] + rtP.init_yBI[0]) * D;
      rtB.qA2B[3] = (rtP.init_zBI[0] + rtP.init_xBI[2]) * D;
      rtB.qA2B[0] = (rtP.init_yBI[2] - rtP.init_zBI[1]) * D;
      break;

     case 3:
      rtB.qA2B[2] = sqrt(A[2] + 1.0) * 0.5;
      D = 1.0 / (4.0 * rtB.qA2B[2]);
      rtB.qA2B[3] = (rtP.init_yBI[2] + rtP.init_zBI[1]) * D;
      rtB.qA2B[0] = (rtP.init_zBI[0] - rtP.init_xBI[2]) * D;
      rtB.qA2B[1] = (rtP.init_xBI[1] + rtP.init_yBI[0]) * D;
      break;

     default:
      rtB.qA2B[3] = sqrt(A[3] + 1.0) * 0.5;
      D = 1.0 / (4.0 * rtB.qA2B[3]);
      rtB.qA2B[0] = (rtP.init_xBI[1] - rtP.init_yBI[0]) * D;
      rtB.qA2B[1] = (rtP.init_zBI[0] + rtP.init_xBI[2]) * D;
      rtB.qA2B[2] = (rtP.init_yBI[2] + rtP.init_zBI[1]) * D;
      break;
    }

    /* End of MATLAB Function: '<S18>/MATLAB Function' */
  }

  /* Integrator: '<S4>/Integrator' */
  if (rtDW.Integrator_IWORK != 0) {
    rtX.Integrator_CSTATE[0] = rtB.qA2B[0];
    rtX.Integrator_CSTATE[1] = rtB.qA2B[1];
    rtX.Integrator_CSTATE[2] = rtB.qA2B[2];
    rtX.Integrator_CSTATE[3] = rtB.qA2B[3];
  }

  /* MATLAB Function: '<S4>/Quaternion Normed' incorporates:
   *  Integrator: '<S4>/Integrator'
   */
  scale = 3.3121686421112381E-170;
  absxk = fabs(rtX.Integrator_CSTATE[0]);
  if (absxk > 3.3121686421112381E-170) {
    D = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    D = t * t;
  }

  absxk = fabs(rtX.Integrator_CSTATE[1]);
  if (absxk > scale) {
    t = scale / absxk;
    D = D * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    D += t * t;
  }

  absxk = fabs(rtX.Integrator_CSTATE[2]);
  if (absxk > scale) {
    t = scale / absxk;
    D = D * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    D += t * t;
  }

  absxk = fabs(rtX.Integrator_CSTATE[3]);
  if (absxk > scale) {
    t = scale / absxk;
    D = D * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    D += t * t;
  }

  D = scale * sqrt(D);
  rtB.y[0] = rtX.Integrator_CSTATE[0] / D;

  /* Gain: '<S19>/Gain1' */
  A_0 = rtP.Gain1_Gain[0] * rtB.y[0];

  /* Gain: '<S61>/Gain1' */
  rtb_Switch_idx_0 = rtP.Gain1_Gain_m[0] * A_0;

  /* Gain: '<S19>/Gain1' */
  A[0] = A_0;

  /* MATLAB Function: '<S4>/Quaternion Normed' incorporates:
   *  Integrator: '<S4>/Integrator'
   */
  rtB.y[1] = rtX.Integrator_CSTATE[1] / D;

  /* Gain: '<S19>/Gain1' */
  A_0 = rtP.Gain1_Gain[1] * rtB.y[1];

  /* Gain: '<S61>/Gain1' */
  rtb_Switch_idx_1 = rtP.Gain1_Gain_m[1] * A_0;

  /* Gain: '<S19>/Gain1' */
  A[1] = A_0;

  /* MATLAB Function: '<S4>/Quaternion Normed' incorporates:
   *  Integrator: '<S4>/Integrator'
   */
  rtB.y[2] = rtX.Integrator_CSTATE[2] / D;

  /* Gain: '<S19>/Gain1' */
  A_0 = rtP.Gain1_Gain[2] * rtB.y[2];

  /* Gain: '<S61>/Gain1' */
  rtb_Switch_idx_2 = rtP.Gain1_Gain_m[2] * A_0;

  /* Gain: '<S19>/Gain1' */
  A[2] = A_0;

  /* MATLAB Function: '<S4>/Quaternion Normed' incorporates:
   *  Integrator: '<S4>/Integrator'
   */
  rtB.y[3] = rtX.Integrator_CSTATE[3] / D;

  /* Gain: '<S19>/Gain1' */
  A_0 = rtP.Gain1_Gain[3] * rtB.y[3];

  /* Gain: '<S61>/Gain1' */
  rtb_Switch_idx_3 = rtP.Gain1_Gain_m[3] * A_0;

  /* Sum: '<S59>/Sum1' incorporates:
   *  Constant: '<Root>/Constant7'
   *  Constant: '<S17>/Constant'
   *  DotProduct: '<S59>/Dot Product'
   *  Product: '<S59>/Product2'
   */
  t = rtb_Switch_idx_0 * rtP.Constant_Value_l - ((rtP.solar_array_vb[0] *
    rtb_Switch_idx_1 + rtP.solar_array_vb[1] * rtb_Switch_idx_2) +
    rtP.solar_array_vb[2] * rtb_Switch_idx_3);

  /* Sum: '<S59>/Sum' incorporates:
   *  Constant: '<Root>/Constant7'
   *  Constant: '<S17>/Constant'
   *  Product: '<S59>/Product'
   *  Product: '<S59>/Product1'
   *  Product: '<S62>/Product'
   *  Product: '<S62>/Product1'
   *  Product: '<S62>/Product2'
   *  Product: '<S62>/Product3'
   *  Product: '<S62>/Product4'
   *  Product: '<S62>/Product5'
   *  Sum: '<S62>/Sum'
   *  Sum: '<S62>/Sum1'
   *  Sum: '<S62>/Sum2'
   */
  rtb_Divide_idx_0 = ((rtb_Switch_idx_2 * rtP.solar_array_vb[2] -
                       rtb_Switch_idx_3 * rtP.solar_array_vb[1]) +
                      rtb_Switch_idx_0 * rtP.solar_array_vb[0]) +
    rtP.Constant_Value_l * rtb_Switch_idx_1;
  rtb_Divide_idx_1 = ((rtb_Switch_idx_3 * rtP.solar_array_vb[0] -
                       rtb_Switch_idx_1 * rtP.solar_array_vb[2]) +
                      rtb_Switch_idx_0 * rtP.solar_array_vb[1]) +
    rtP.Constant_Value_l * rtb_Switch_idx_2;
  rtb_Switch_idx_0 = ((rtb_Switch_idx_1 * rtP.solar_array_vb[1] -
                       rtb_Switch_idx_2 * rtP.solar_array_vb[0]) +
                      rtb_Switch_idx_0 * rtP.solar_array_vb[2]) +
    rtP.Constant_Value_l * rtb_Switch_idx_3;

  /* Sum: '<S60>/Sum1' incorporates:
   *  DotProduct: '<S60>/Dot Product'
   *  Product: '<S60>/Product2'
   *  Sum: '<S59>/Sum'
   */
  scale = t * A[0] - ((A[1] * rtb_Divide_idx_0 + A[2] * rtb_Divide_idx_1) + A_0 *
                      rtb_Switch_idx_0);

  /* Sum: '<S63>/Sum' incorporates:
   *  Product: '<S63>/Product'
   *  Product: '<S63>/Product1'
   *  Sum: '<S59>/Sum'
   */
  D = rtb_Divide_idx_1 * A_0 - rtb_Switch_idx_0 * A[2];

  /* Product: '<S17>/Product' incorporates:
   *  Product: '<S60>/Product'
   *  Product: '<S60>/Product1'
   *  Product: '<S63>/Product2'
   *  Product: '<S63>/Product3'
   *  Product: '<S63>/Product4'
   *  Product: '<S63>/Product5'
   *  Sum: '<S59>/Sum'
   *  Sum: '<S60>/Sum'
   *  Sum: '<S63>/Sum1'
   *  Sum: '<S63>/Sum2'
   */
  rtB.Product[0] = ((t * A[1] + D) + A[0] * rtb_Divide_idx_0) * (1.0 / scale);
  rtB.Product[1] = (((rtb_Switch_idx_0 * A[1] - rtb_Divide_idx_0 * A_0) + t * A
                     [2]) + A[0] * rtb_Divide_idx_1) * (1.0 / scale);
  rtB.Product[2] = (((rtb_Divide_idx_0 * A[2] - rtb_Divide_idx_1 * A[1]) + t *
                     A_0) + A[0] * rtb_Switch_idx_0) * (1.0 / scale);

  /* Gain: '<S56>/Gain1' */
  rtb_Switch_idx_0 = rtP.Gain1_Gain_p[0] * A[0];
  rtb_Switch_idx_1 = rtP.Gain1_Gain_p[1] * A[1];
  rtb_Switch_idx_2 = rtP.Gain1_Gain_p[2] * A[2];
  rtb_Switch_idx_3 = rtP.Gain1_Gain_p[3] * A_0;

  /* Sum: '<S54>/Sum1' incorporates:
   *  Constant: '<Root>/Constant3'
   *  Constant: '<S16>/Constant'
   *  DotProduct: '<S54>/Dot Product'
   *  Product: '<S54>/Product2'
   */
  D = rtb_Switch_idx_0 * rtP.Constant_Value_d - ((rtP.antenna_vb[0] *
    rtb_Switch_idx_1 + rtP.antenna_vb[1] * rtb_Switch_idx_2) + rtP.antenna_vb[2]
    * rtb_Switch_idx_3);

  /* Sum: '<S54>/Sum' incorporates:
   *  Constant: '<Root>/Constant3'
   *  Constant: '<S16>/Constant'
   *  Product: '<S54>/Product'
   *  Product: '<S54>/Product1'
   *  Product: '<S57>/Product'
   *  Product: '<S57>/Product1'
   *  Product: '<S57>/Product2'
   *  Product: '<S57>/Product3'
   *  Product: '<S57>/Product4'
   *  Product: '<S57>/Product5'
   *  Sum: '<S57>/Sum'
   *  Sum: '<S57>/Sum1'
   *  Sum: '<S57>/Sum2'
   */
  scale = ((rtb_Switch_idx_2 * rtP.antenna_vb[2] - rtb_Switch_idx_3 *
            rtP.antenna_vb[1]) + rtb_Switch_idx_0 * rtP.antenna_vb[0]) +
    rtP.Constant_Value_d * rtb_Switch_idx_1;
  absxk = ((rtb_Switch_idx_3 * rtP.antenna_vb[0] - rtb_Switch_idx_1 *
            rtP.antenna_vb[2]) + rtb_Switch_idx_0 * rtP.antenna_vb[1]) +
    rtP.Constant_Value_d * rtb_Switch_idx_2;
  rtb_Divide_f_idx_2 = ((rtb_Switch_idx_1 * rtP.antenna_vb[1] - rtb_Switch_idx_2
    * rtP.antenna_vb[0]) + rtb_Switch_idx_0 * rtP.antenna_vb[2]) +
    rtP.Constant_Value_d * rtb_Switch_idx_3;

  /* Product: '<S55>/Product' */
  rtb_Divide_idx_0 = D * A[1];
  rtb_Divide_idx_1 = D * A[2];
  rtb_Switch_idx_0 = D * A_0;

  /* Sum: '<S55>/Sum1' incorporates:
   *  DotProduct: '<S55>/Dot Product'
   *  Product: '<S55>/Product2'
   *  Sum: '<S54>/Sum'
   */
  t = D * A[0] - ((A[1] * scale + A[2] * absxk) + A_0 * rtb_Divide_f_idx_2);

  /* Sum: '<S58>/Sum' incorporates:
   *  Product: '<S58>/Product'
   *  Product: '<S58>/Product1'
   *  Sum: '<S54>/Sum'
   */
  D = absxk * A_0 - rtb_Divide_f_idx_2 * A[2];

  /* Product: '<S16>/Product' incorporates:
   *  Product: '<S55>/Product1'
   *  Product: '<S58>/Product2'
   *  Product: '<S58>/Product3'
   *  Product: '<S58>/Product4'
   *  Product: '<S58>/Product5'
   *  Sum: '<S54>/Sum'
   *  Sum: '<S55>/Sum'
   *  Sum: '<S58>/Sum1'
   *  Sum: '<S58>/Sum2'
   */
  rtB.Product_f[0] = ((rtb_Divide_idx_0 + D) + A[0] * scale) * (1.0 / t);
  rtB.Product_f[1] = (((rtb_Divide_f_idx_2 * A[1] - scale * A_0) +
                       rtb_Divide_idx_1) + A[0] * absxk) * (1.0 / t);
  rtB.Product_f[2] = (((scale * A[2] - absxk * A[1]) + rtb_Switch_idx_0) + A[0] *
                      rtb_Divide_f_idx_2) * (1.0 / t);

  /* Gain: '<S51>/Gain1' */
  rtb_Switch_idx_0 = rtP.Gain1_Gain_i[0] * A[0];
  rtb_Switch_idx_1 = rtP.Gain1_Gain_i[1] * A[1];
  rtb_Switch_idx_2 = rtP.Gain1_Gain_i[2] * A[2];
  rtb_Switch_idx_3 = rtP.Gain1_Gain_i[3] * A_0;

  /* Sum: '<S49>/Sum1' incorporates:
   *  Constant: '<Root>/Constant2'
   *  Constant: '<S15>/Constant'
   *  DotProduct: '<S49>/Dot Product'
   *  Product: '<S49>/Product2'
   */
  D = rtb_Switch_idx_0 * rtP.Constant_Value_g - ((rtP.thruster_vb[0] *
    rtb_Switch_idx_1 + rtP.thruster_vb[1] * rtb_Switch_idx_2) + rtP.thruster_vb
    [2] * rtb_Switch_idx_3);

  /* Sum: '<S49>/Sum' incorporates:
   *  Constant: '<Root>/Constant2'
   *  Constant: '<S15>/Constant'
   *  Product: '<S49>/Product'
   *  Product: '<S49>/Product1'
   *  Product: '<S52>/Product'
   *  Product: '<S52>/Product1'
   *  Product: '<S52>/Product2'
   *  Product: '<S52>/Product3'
   *  Product: '<S52>/Product4'
   *  Product: '<S52>/Product5'
   *  Sum: '<S52>/Sum'
   *  Sum: '<S52>/Sum1'
   *  Sum: '<S52>/Sum2'
   */
  scale = ((rtb_Switch_idx_2 * rtP.thruster_vb[2] - rtb_Switch_idx_3 *
            rtP.thruster_vb[1]) + rtb_Switch_idx_0 * rtP.thruster_vb[0]) +
    rtP.Constant_Value_g * rtb_Switch_idx_1;
  absxk = ((rtb_Switch_idx_3 * rtP.thruster_vb[0] - rtb_Switch_idx_1 *
            rtP.thruster_vb[2]) + rtb_Switch_idx_0 * rtP.thruster_vb[1]) +
    rtP.Constant_Value_g * rtb_Switch_idx_2;
  rtb_Divide_f_idx_2 = ((rtb_Switch_idx_1 * rtP.thruster_vb[1] -
    rtb_Switch_idx_2 * rtP.thruster_vb[0]) + rtb_Switch_idx_0 * rtP.thruster_vb
                        [2]) + rtP.Constant_Value_g * rtb_Switch_idx_3;

  /* Product: '<S50>/Product' */
  rtb_Divide_idx_0 = D * A[1];
  rtb_Divide_idx_1 = D * A[2];
  rtb_Switch_idx_0 = D * A_0;

  /* Sum: '<S50>/Sum1' incorporates:
   *  DotProduct: '<S50>/Dot Product'
   *  Product: '<S50>/Product2'
   *  Sum: '<S49>/Sum'
   */
  t = D * A[0] - ((A[1] * scale + A[2] * absxk) + A_0 * rtb_Divide_f_idx_2);

  /* Sum: '<S53>/Sum' incorporates:
   *  Product: '<S53>/Product'
   *  Product: '<S53>/Product1'
   *  Sum: '<S49>/Sum'
   */
  D = absxk * A_0 - rtb_Divide_f_idx_2 * A[2];

  /* Product: '<S15>/Product' incorporates:
   *  Product: '<S50>/Product1'
   *  Product: '<S53>/Product2'
   *  Product: '<S53>/Product3'
   *  Product: '<S53>/Product4'
   *  Product: '<S53>/Product5'
   *  Sum: '<S49>/Sum'
   *  Sum: '<S50>/Sum'
   *  Sum: '<S53>/Sum1'
   *  Sum: '<S53>/Sum2'
   */
  rtB.Product_b[0] = ((rtb_Divide_idx_0 + D) + A[0] * scale) * (1.0 / t);
  rtB.Product_b[1] = (((rtb_Divide_f_idx_2 * A[1] - scale * A_0) +
                       rtb_Divide_idx_1) + A[0] * absxk) * (1.0 / t);
  rtB.Product_b[2] = (((scale * A[2] - absxk * A[1]) + rtb_Switch_idx_0) + A[0] *
                      rtb_Divide_f_idx_2) * (1.0 / t);

  /* Gain: '<S46>/Gain1' */
  rtb_Switch_idx_0 = rtP.Gain1_Gain_h[0] * A[0];
  rtb_Switch_idx_1 = rtP.Gain1_Gain_h[1] * A[1];
  rtb_Switch_idx_2 = rtP.Gain1_Gain_h[2] * A[2];
  rtb_Switch_idx_3 = rtP.Gain1_Gain_h[3] * A_0;

  /* Sum: '<S44>/Sum1' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Constant: '<S14>/Constant'
   *  DotProduct: '<S44>/Dot Product'
   *  Product: '<S44>/Product2'
   */
  D = rtb_Switch_idx_0 * rtP.Constant_Value_i - ((rtP.star_sensor_2_vb[0] *
    rtb_Switch_idx_1 + rtP.star_sensor_2_vb[1] * rtb_Switch_idx_2) +
    rtP.star_sensor_2_vb[2] * rtb_Switch_idx_3);

  /* Sum: '<S44>/Sum' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Constant: '<S14>/Constant'
   *  Product: '<S44>/Product'
   *  Product: '<S44>/Product1'
   *  Product: '<S47>/Product'
   *  Product: '<S47>/Product1'
   *  Product: '<S47>/Product2'
   *  Product: '<S47>/Product3'
   *  Product: '<S47>/Product4'
   *  Product: '<S47>/Product5'
   *  Sum: '<S47>/Sum'
   *  Sum: '<S47>/Sum1'
   *  Sum: '<S47>/Sum2'
   */
  scale = ((rtb_Switch_idx_2 * rtP.star_sensor_2_vb[2] - rtb_Switch_idx_3 *
            rtP.star_sensor_2_vb[1]) + rtb_Switch_idx_0 * rtP.star_sensor_2_vb[0])
    + rtP.Constant_Value_i * rtb_Switch_idx_1;
  absxk = ((rtb_Switch_idx_3 * rtP.star_sensor_2_vb[0] - rtb_Switch_idx_1 *
            rtP.star_sensor_2_vb[2]) + rtb_Switch_idx_0 * rtP.star_sensor_2_vb[1])
    + rtP.Constant_Value_i * rtb_Switch_idx_2;
  rtb_Divide_f_idx_2 = ((rtb_Switch_idx_1 * rtP.star_sensor_2_vb[1] -
    rtb_Switch_idx_2 * rtP.star_sensor_2_vb[0]) + rtb_Switch_idx_0 *
                        rtP.star_sensor_2_vb[2]) + rtP.Constant_Value_i *
    rtb_Switch_idx_3;

  /* Product: '<S45>/Product' */
  rtb_Divide_idx_0 = D * A[1];
  rtb_Divide_idx_1 = D * A[2];
  rtb_Switch_idx_0 = D * A_0;

  /* Sum: '<S45>/Sum1' incorporates:
   *  DotProduct: '<S45>/Dot Product'
   *  Product: '<S45>/Product2'
   *  Sum: '<S44>/Sum'
   */
  t = D * A[0] - ((A[1] * scale + A[2] * absxk) + A_0 * rtb_Divide_f_idx_2);

  /* Sum: '<S48>/Sum' incorporates:
   *  Product: '<S48>/Product'
   *  Product: '<S48>/Product1'
   *  Sum: '<S44>/Sum'
   */
  D = absxk * A_0 - rtb_Divide_f_idx_2 * A[2];

  /* Product: '<S14>/Product' incorporates:
   *  Product: '<S45>/Product1'
   *  Product: '<S48>/Product2'
   *  Product: '<S48>/Product3'
   *  Product: '<S48>/Product4'
   *  Product: '<S48>/Product5'
   *  Sum: '<S44>/Sum'
   *  Sum: '<S45>/Sum'
   *  Sum: '<S48>/Sum1'
   *  Sum: '<S48>/Sum2'
   */
  rtB.Product_k[0] = ((rtb_Divide_idx_0 + D) + A[0] * scale) * (1.0 / t);
  rtB.Product_k[1] = (((rtb_Divide_f_idx_2 * A[1] - scale * A_0) +
                       rtb_Divide_idx_1) + A[0] * absxk) * (1.0 / t);
  rtB.Product_k[2] = (((scale * A[2] - absxk * A[1]) + rtb_Switch_idx_0) + A[0] *
                      rtb_Divide_f_idx_2) * (1.0 / t);

  /* Gain: '<S41>/Gain1' */
  rtb_Switch_idx_0 = rtP.Gain1_Gain_a[0] * A[0];
  rtb_Switch_idx_1 = rtP.Gain1_Gain_a[1] * A[1];
  rtb_Switch_idx_2 = rtP.Gain1_Gain_a[2] * A[2];
  rtb_Switch_idx_3 = rtP.Gain1_Gain_a[3] * A_0;

  /* Sum: '<S39>/Sum1' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<S13>/Constant'
   *  DotProduct: '<S39>/Dot Product'
   *  Product: '<S39>/Product2'
   */
  D = rtb_Switch_idx_0 * rtP.Constant_Value_bg - ((rtP.star_sensor_1_vb[0] *
    rtb_Switch_idx_1 + rtP.star_sensor_1_vb[1] * rtb_Switch_idx_2) +
    rtP.star_sensor_1_vb[2] * rtb_Switch_idx_3);

  /* Sum: '<S39>/Sum' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<S13>/Constant'
   *  Product: '<S39>/Product'
   *  Product: '<S39>/Product1'
   *  Product: '<S42>/Product'
   *  Product: '<S42>/Product1'
   *  Product: '<S42>/Product2'
   *  Product: '<S42>/Product3'
   *  Product: '<S42>/Product4'
   *  Product: '<S42>/Product5'
   *  Sum: '<S42>/Sum'
   *  Sum: '<S42>/Sum1'
   *  Sum: '<S42>/Sum2'
   */
  scale = ((rtb_Switch_idx_2 * rtP.star_sensor_1_vb[2] - rtb_Switch_idx_3 *
            rtP.star_sensor_1_vb[1]) + rtb_Switch_idx_0 * rtP.star_sensor_1_vb[0])
    + rtP.Constant_Value_bg * rtb_Switch_idx_1;
  absxk = ((rtb_Switch_idx_3 * rtP.star_sensor_1_vb[0] - rtb_Switch_idx_1 *
            rtP.star_sensor_1_vb[2]) + rtb_Switch_idx_0 * rtP.star_sensor_1_vb[1])
    + rtP.Constant_Value_bg * rtb_Switch_idx_2;
  rtb_Divide_f_idx_2 = ((rtb_Switch_idx_1 * rtP.star_sensor_1_vb[1] -
    rtb_Switch_idx_2 * rtP.star_sensor_1_vb[0]) + rtb_Switch_idx_0 *
                        rtP.star_sensor_1_vb[2]) + rtP.Constant_Value_bg *
    rtb_Switch_idx_3;

  /* Product: '<S40>/Product' */
  rtb_Divide_idx_0 = D * A[1];
  rtb_Divide_idx_1 = D * A[2];
  rtb_Switch_idx_0 = D * A_0;

  /* Sum: '<S40>/Sum1' incorporates:
   *  DotProduct: '<S40>/Dot Product'
   *  Product: '<S40>/Product2'
   *  Sum: '<S39>/Sum'
   */
  t = D * A[0] - ((A[1] * scale + A[2] * absxk) + A_0 * rtb_Divide_f_idx_2);

  /* Sum: '<S43>/Sum' incorporates:
   *  Product: '<S43>/Product'
   *  Product: '<S43>/Product1'
   *  Sum: '<S39>/Sum'
   */
  D = absxk * A_0 - rtb_Divide_f_idx_2 * A[2];

  /* Product: '<S13>/Product' incorporates:
   *  Product: '<S40>/Product1'
   *  Product: '<S43>/Product2'
   *  Product: '<S43>/Product3'
   *  Product: '<S43>/Product4'
   *  Product: '<S43>/Product5'
   *  Sum: '<S39>/Sum'
   *  Sum: '<S40>/Sum'
   *  Sum: '<S43>/Sum1'
   *  Sum: '<S43>/Sum2'
   */
  rtB.Product_p[0] = ((rtb_Divide_idx_0 + D) + A[0] * scale) * (1.0 / t);
  rtB.Product_p[1] = (((rtb_Divide_f_idx_2 * A[1] - scale * A_0) +
                       rtb_Divide_idx_1) + A[0] * absxk) * (1.0 / t);
  rtB.Product_p[2] = (((scale * A[2] - absxk * A[1]) + rtb_Switch_idx_0) + A[0] *
                      rtb_Divide_f_idx_2) * (1.0 / t);
  if (ssIsSampleHit(rtS, 1, 0)) {
  }

  /* Clock: '<Root>/Clock' incorporates:
   *  Clock: '<S3>/Clock1'
   */
  t = ssGetT(rtS);

  /* MATLAB Function: '<Root>/Interpolator ' incorporates:
   *  Clock: '<Root>/Clock'
   *  Constant: '<Root>/Test Design'
   */
  scale = attitude3d_interp1(&rtP.x_test[0], &rtP.x_test[3], t);
  absxk = attitude3d_interp1(&rtP.x_test[0], &rtP.x_test[6], t);
  rtb_Divide_f_idx_2 = attitude3d_interp1(&rtP.x_test[0], &rtP.x_test[9], t);

  /* MATLAB Function: '<S4>/Quaternion Differential' incorporates:
   *  MATLAB Function: '<Root>/Interpolator '
   */
  tmp[0] = 0.0;
  D = 0.5 * -scale;
  tmp[4] = D;
  A_0 = 0.5 * -absxk;
  tmp[8] = A_0;
  tmp[12] = D;
  tmp[1] = 0.5 * rtb_Divide_f_idx_2;
  tmp[5] = 0.0;
  tmp[9] = 0.5 * scale;
  tmp[13] = A_0;
  tmp[2] = 0.5 * absxk;
  tmp[6] = D;
  tmp[10] = 0.0;
  D = 0.5 * -rtb_Divide_f_idx_2;
  tmp[14] = D;
  tmp[3] = 0.5 * scale;
  tmp[7] = 0.5 * absxk;
  tmp[11] = D;
  tmp[15] = 0.0;
  for (i = 0; i < 4; i++) {
    rtB.q_dot[i] = 0.0;
    rtB.q_dot[i] += tmp[i] * rtB.y[0];
    rtB.q_dot[i] += tmp[i + 4] * rtB.y[1];
    rtB.q_dot[i] += tmp[i + 8] * rtB.y[2];
    rtB.q_dot[i] += tmp[i + 12] * rtB.y[3];
  }

  /* End of MATLAB Function: '<S4>/Quaternion Differential' */
  if (ssIsSampleHit(rtS, 1, 0)) {
  }

  /* Sum: '<S23>/Sum of Elements' incorporates:
   *  Math: '<S23>/Math Function'
   */
  D = rtB.solar_v[0] * rtB.solar_v[0];
  D += rtB.solar_v[1] * rtB.solar_v[1];
  D += rtB.solar_v[2] * rtB.solar_v[2];

  /* Math: '<S23>/Math Function1'
   *
   * About '<S23>/Math Function1':
   *  Operator: sqrt
   */
  if (D < 0.0) {
    D = -sqrt(fabs(D));
  } else {
    D = sqrt(D);
  }

  /* End of Math: '<S23>/Math Function1' */

  /* Switch: '<S23>/Switch' incorporates:
   *  Constant: '<S23>/Constant'
   *  Product: '<S23>/Product'
   */
  if (D > rtP.NormalizeVector_maxzero) {
    rtb_Switch_idx_0 = rtB.solar_v[0];
    rtb_Switch_idx_1 = rtB.solar_v[1];
    rtb_Switch_idx_2 = rtB.solar_v[2];
    rtb_Switch_idx_3 = D;
  } else {
    rtb_Switch_idx_0 = rtB.solar_v[0] * 0.0;
    rtb_Switch_idx_1 = rtB.solar_v[1] * 0.0;
    rtb_Switch_idx_2 = rtB.solar_v[2] * 0.0;
    rtb_Switch_idx_3 = rtP.Constant_Value_p;
  }

  /* End of Switch: '<S23>/Switch' */

  /* Product: '<S23>/Divide' */
  scale = rtb_Switch_idx_0 / rtb_Switch_idx_3;
  absxk = rtb_Switch_idx_1 / rtb_Switch_idx_3;
  rtb_Divide_f_idx_2 = rtb_Switch_idx_2 / rtb_Switch_idx_3;

  /* Sum: '<S24>/Sum of Elements' incorporates:
   *  Math: '<S24>/Math Function'
   */
  D = rtB.Product_p[0] * rtB.Product_p[0];
  D += rtB.Product_p[1] * rtB.Product_p[1];
  D += rtB.Product_p[2] * rtB.Product_p[2];

  /* Math: '<S24>/Math Function1'
   *
   * About '<S24>/Math Function1':
   *  Operator: sqrt
   */
  if (D < 0.0) {
    D = -sqrt(fabs(D));
  } else {
    D = sqrt(D);
  }

  /* End of Math: '<S24>/Math Function1' */

  /* Switch: '<S24>/Switch' incorporates:
   *  Constant: '<S24>/Constant'
   *  Product: '<S24>/Product'
   */
  if (D > rtP.NormalizeVector1_maxzero) {
    rtb_Switch_idx_0 = rtB.Product_p[0];
    rtb_Switch_idx_1 = rtB.Product_p[1];
    rtb_Switch_idx_2 = rtB.Product_p[2];
    rtb_Switch_idx_3 = D;
  } else {
    rtb_Switch_idx_0 = rtB.Product_p[0] * 0.0;
    rtb_Switch_idx_1 = rtB.Product_p[1] * 0.0;
    rtb_Switch_idx_2 = rtB.Product_p[2] * 0.0;
    rtb_Switch_idx_3 = rtP.Constant_Value_pb;
  }

  /* End of Switch: '<S24>/Switch' */

  /* DotProduct: '<S5>/Dot Product1' incorporates:
   *  Product: '<S24>/Divide'
   */
  D = (rtb_Switch_idx_0 / rtb_Switch_idx_3 * scale + rtb_Switch_idx_1 /
       rtb_Switch_idx_3 * absxk) + rtb_Switch_idx_2 / rtb_Switch_idx_3 *
    rtb_Divide_f_idx_2;

  /* Saturate: '<S5>/Saturation' */
  if (D > rtP.Saturation_UpperSat) {
    rtB.Saturation = rtP.Saturation_UpperSat;
  } else if (D < rtP.Saturation_LowerSat) {
    rtB.Saturation = rtP.Saturation_LowerSat;
  } else {
    rtB.Saturation = D;
  }

  /* End of Saturate: '<S5>/Saturation' */
  if (ssIsSampleHit(rtS, 1, 0)) {
  }

  /* Product: '<S5>/Product' */
  rtB.min_exclusion = rtB.sight_solar * rtB.Saturation;

  /* Trigonometry: '<S5>/Acos' */
  if (rtB.min_exclusion > 1.0) {
    D = 1.0;
  } else if (rtB.min_exclusion < -1.0) {
    D = -1.0;
  } else {
    D = rtB.min_exclusion;
  }

  rtB.Acos = acos(D);

  /* End of Trigonometry: '<S5>/Acos' */
  attitude3d_MovingMinimum(rtB.Acos, &rtB.MovingMinimum, &rtDW.MovingMinimum);
  if (ssIsSampleHit(rtS, 1, 0)) {
  }

  /* Sum: '<S25>/Sum of Elements' incorporates:
   *  Math: '<S25>/Math Function'
   */
  D = rtB.solar_v[0] * rtB.solar_v[0];
  D += rtB.solar_v[1] * rtB.solar_v[1];
  D += rtB.solar_v[2] * rtB.solar_v[2];

  /* Math: '<S25>/Math Function1'
   *
   * About '<S25>/Math Function1':
   *  Operator: sqrt
   */
  if (D < 0.0) {
    D = -sqrt(fabs(D));
  } else {
    D = sqrt(D);
  }

  /* End of Math: '<S25>/Math Function1' */

  /* Switch: '<S25>/Switch' incorporates:
   *  Constant: '<S25>/Constant'
   *  Product: '<S25>/Product'
   */
  if (D > rtP.NormalizeVector_maxzero_m) {
    rtb_Switch_idx_0 = rtB.solar_v[0];
    rtb_Switch_idx_1 = rtB.solar_v[1];
    rtb_Switch_idx_2 = rtB.solar_v[2];
    rtb_Switch_idx_3 = D;
  } else {
    rtb_Switch_idx_0 = rtB.solar_v[0] * 0.0;
    rtb_Switch_idx_1 = rtB.solar_v[1] * 0.0;
    rtb_Switch_idx_2 = rtB.solar_v[2] * 0.0;
    rtb_Switch_idx_3 = rtP.Constant_Value_oj;
  }

  /* End of Switch: '<S25>/Switch' */

  /* Product: '<S25>/Divide' */
  scale = rtb_Switch_idx_0 / rtb_Switch_idx_3;
  absxk = rtb_Switch_idx_1 / rtb_Switch_idx_3;
  rtb_Divide_f_idx_2 = rtb_Switch_idx_2 / rtb_Switch_idx_3;

  /* Sum: '<S26>/Sum of Elements' incorporates:
   *  Math: '<S26>/Math Function'
   */
  D = rtB.Product_k[0] * rtB.Product_k[0];
  D += rtB.Product_k[1] * rtB.Product_k[1];
  D += rtB.Product_k[2] * rtB.Product_k[2];

  /* Math: '<S26>/Math Function1'
   *
   * About '<S26>/Math Function1':
   *  Operator: sqrt
   */
  if (D < 0.0) {
    D = -sqrt(fabs(D));
  } else {
    D = sqrt(D);
  }

  /* End of Math: '<S26>/Math Function1' */

  /* Switch: '<S26>/Switch' incorporates:
   *  Constant: '<S26>/Constant'
   *  Product: '<S26>/Product'
   */
  if (D > rtP.NormalizeVector1_maxzero_i) {
    rtb_Switch_idx_0 = rtB.Product_k[0];
    rtb_Switch_idx_1 = rtB.Product_k[1];
    rtb_Switch_idx_2 = rtB.Product_k[2];
    rtb_Switch_idx_3 = D;
  } else {
    rtb_Switch_idx_0 = rtB.Product_k[0] * 0.0;
    rtb_Switch_idx_1 = rtB.Product_k[1] * 0.0;
    rtb_Switch_idx_2 = rtB.Product_k[2] * 0.0;
    rtb_Switch_idx_3 = rtP.Constant_Value_pw;
  }

  /* End of Switch: '<S26>/Switch' */

  /* DotProduct: '<S6>/Dot Product1' incorporates:
   *  Product: '<S26>/Divide'
   */
  D = (rtb_Switch_idx_0 / rtb_Switch_idx_3 * scale + rtb_Switch_idx_1 /
       rtb_Switch_idx_3 * absxk) + rtb_Switch_idx_2 / rtb_Switch_idx_3 *
    rtb_Divide_f_idx_2;

  /* Saturate: '<S6>/Saturation' */
  if (D > rtP.Saturation_UpperSat_o) {
    rtB.Saturation_i = rtP.Saturation_UpperSat_o;
  } else if (D < rtP.Saturation_LowerSat_p) {
    rtB.Saturation_i = rtP.Saturation_LowerSat_p;
  } else {
    rtB.Saturation_i = D;
  }

  /* End of Saturate: '<S6>/Saturation' */
  if (ssIsSampleHit(rtS, 1, 0)) {
  }

  /* Product: '<S6>/Product' */
  rtB.min_exclusion_m = rtB.sight_solar * rtB.Saturation_i;

  /* Trigonometry: '<S6>/Acos' */
  if (rtB.min_exclusion_m > 1.0) {
    D = 1.0;
  } else if (rtB.min_exclusion_m < -1.0) {
    D = -1.0;
  } else {
    D = rtB.min_exclusion_m;
  }

  rtB.Acos_i = acos(D);

  /* End of Trigonometry: '<S6>/Acos' */
  attitude3d_MovingMinimum(rtB.Acos_i, &rtB.MovingMinimum_p,
    &rtDW.MovingMinimum_p);
  if (ssIsSampleHit(rtS, 1, 0)) {
  }

  /* Sum: '<S27>/Sum of Elements' incorporates:
   *  Math: '<S27>/Math Function'
   */
  D = rtB.solar_v[0] * rtB.solar_v[0];
  D += rtB.solar_v[1] * rtB.solar_v[1];
  D += rtB.solar_v[2] * rtB.solar_v[2];

  /* Math: '<S27>/Math Function1'
   *
   * About '<S27>/Math Function1':
   *  Operator: sqrt
   */
  if (D < 0.0) {
    D = -sqrt(fabs(D));
  } else {
    D = sqrt(D);
  }

  /* End of Math: '<S27>/Math Function1' */

  /* Switch: '<S27>/Switch' incorporates:
   *  Constant: '<S27>/Constant'
   *  Product: '<S27>/Product'
   */
  if (D > rtP.NormalizeVector_maxzero_o) {
    rtb_Switch_idx_0 = rtB.solar_v[0];
    rtb_Switch_idx_1 = rtB.solar_v[1];
    rtb_Switch_idx_2 = rtB.solar_v[2];
    rtb_Switch_idx_3 = D;
  } else {
    rtb_Switch_idx_0 = rtB.solar_v[0] * 0.0;
    rtb_Switch_idx_1 = rtB.solar_v[1] * 0.0;
    rtb_Switch_idx_2 = rtB.solar_v[2] * 0.0;
    rtb_Switch_idx_3 = rtP.Constant_Value_kd;
  }

  /* End of Switch: '<S27>/Switch' */

  /* Product: '<S27>/Divide' */
  scale = rtb_Switch_idx_0 / rtb_Switch_idx_3;
  absxk = rtb_Switch_idx_1 / rtb_Switch_idx_3;
  rtb_Divide_f_idx_2 = rtb_Switch_idx_2 / rtb_Switch_idx_3;

  /* Sum: '<S28>/Sum of Elements' incorporates:
   *  Math: '<S28>/Math Function'
   */
  D = rtB.Product_k[0] * rtB.Product_k[0];
  D += rtB.Product_k[1] * rtB.Product_k[1];
  D += rtB.Product_k[2] * rtB.Product_k[2];

  /* Math: '<S28>/Math Function1'
   *
   * About '<S28>/Math Function1':
   *  Operator: sqrt
   */
  if (D < 0.0) {
    D = -sqrt(fabs(D));
  } else {
    D = sqrt(D);
  }

  /* End of Math: '<S28>/Math Function1' */

  /* Switch: '<S28>/Switch' incorporates:
   *  Constant: '<S28>/Constant'
   *  Product: '<S28>/Product'
   */
  if (D > rtP.NormalizeVector1_maxzero_c) {
    rtb_Switch_idx_0 = rtB.Product_k[0];
    rtb_Switch_idx_1 = rtB.Product_k[1];
    rtb_Switch_idx_2 = rtB.Product_k[2];
    rtb_Switch_idx_3 = D;
  } else {
    rtb_Switch_idx_0 = rtB.Product_k[0] * 0.0;
    rtb_Switch_idx_1 = rtB.Product_k[1] * 0.0;
    rtb_Switch_idx_2 = rtB.Product_k[2] * 0.0;
    rtb_Switch_idx_3 = rtP.Constant_Value_gs;
  }

  /* End of Switch: '<S28>/Switch' */

  /* DotProduct: '<S7>/Dot Product1' incorporates:
   *  Product: '<S28>/Divide'
   */
  D = (rtb_Switch_idx_0 / rtb_Switch_idx_3 * scale + rtb_Switch_idx_1 /
       rtb_Switch_idx_3 * absxk) + rtb_Switch_idx_2 / rtb_Switch_idx_3 *
    rtb_Divide_f_idx_2;

  /* Saturate: '<S7>/Saturation' incorporates:
   *  DotProduct: '<S7>/Dot Product1'
   */
  if (D > rtP.Saturation_UpperSat_j) {
    rtB.Saturation_k = rtP.Saturation_UpperSat_j;
  } else if (D < rtP.Saturation_LowerSat_p4) {
    rtB.Saturation_k = rtP.Saturation_LowerSat_p4;
  } else {
    rtB.Saturation_k = D;
  }

  /* End of Saturate: '<S7>/Saturation' */
  if (ssIsSampleHit(rtS, 1, 0)) {
  }

  /* Product: '<S7>/Product' */
  rtB.min_exclusion_g = rtB.sight_solar * rtB.Saturation_k;

  /* Trigonometry: '<S7>/Acos' */
  if (rtB.min_exclusion_g > 1.0) {
    D = 1.0;
  } else if (rtB.min_exclusion_g < -1.0) {
    D = -1.0;
  } else {
    D = rtB.min_exclusion_g;
  }

  rtB.Acos_i1 = acos(D);

  /* End of Trigonometry: '<S7>/Acos' */
  attitude3d_MovingMinimum(rtB.Acos_i1, &rtB.MovingMinimum_pn,
    &rtDW.MovingMinimum_pn);
  if (ssIsSampleHit(rtS, 1, 0)) {
  }

  /* Switch: '<S8>/Switch' incorporates:
   *  Constant: '<S29>/Constant'
   *  Constant: '<S8>/Constant9'
   *  Integrator: '<S8>/Integrator2'
   *  RelationalOperator: '<S29>/Compare'
   */
  if (rtX.Integrator2_CSTATE == rtP.Constant_Value) {
    rtB.Switch = rtP.Constant9_Value;
  } else {
    rtB.Switch = rtX.Integrator2_CSTATE;
  }

  /* End of Switch: '<S8>/Switch' */

  /* Integrator: '<S8>/Integrator1' */
  rtB.integral_pointing = rtX.Integrator1_CSTATE_f;

  /* Product: '<S8>/Divide' */
  rtB.Divide_b = 1.0 / rtB.Switch * rtB.integral_pointing;
  if (ssIsSampleHit(rtS, 1, 0)) {
  }

  /* Sum: '<S31>/Sum of Elements' incorporates:
   *  Math: '<S31>/Math Function'
   */
  D = rtB.Product_b[0] * rtB.Product_b[0];
  D += rtB.Product_b[1] * rtB.Product_b[1];
  D += rtB.Product_b[2] * rtB.Product_b[2];

  /* Math: '<S31>/Math Function1'
   *
   * About '<S31>/Math Function1':
   *  Operator: sqrt
   */
  if (D < 0.0) {
    D = -sqrt(fabs(D));
  } else {
    D = sqrt(D);
  }

  /* End of Math: '<S31>/Math Function1' */

  /* Switch: '<S31>/Switch' incorporates:
   *  Constant: '<S31>/Constant'
   *  Product: '<S31>/Product'
   */
  if (D > rtP.NormalizeVector_maxzero_f) {
    rtb_Switch_idx_0 = rtB.Product_b[0];
    rtb_Switch_idx_1 = rtB.Product_b[1];
    rtb_Switch_idx_2 = rtB.Product_b[2];
    rtb_Switch_idx_3 = D;
  } else {
    rtb_Switch_idx_0 = rtB.Product_b[0] * 0.0;
    rtb_Switch_idx_1 = rtB.Product_b[1] * 0.0;
    rtb_Switch_idx_2 = rtB.Product_b[2] * 0.0;
    rtb_Switch_idx_3 = rtP.Constant_Value_i2;
  }

  /* End of Switch: '<S31>/Switch' */

  /* Product: '<S31>/Divide' */
  scale = rtb_Switch_idx_0 / rtb_Switch_idx_3;
  absxk = rtb_Switch_idx_1 / rtb_Switch_idx_3;
  rtb_Divide_f_idx_2 = rtb_Switch_idx_2 / rtb_Switch_idx_3;

  /* Sum: '<S32>/Sum of Elements' incorporates:
   *  Math: '<S32>/Math Function'
   */
  D = rtB.thrust_v_ref[0] * rtB.thrust_v_ref[0];
  D += rtB.thrust_v_ref[1] * rtB.thrust_v_ref[1];
  D += rtB.thrust_v_ref[2] * rtB.thrust_v_ref[2];

  /* Math: '<S32>/Math Function1'
   *
   * About '<S32>/Math Function1':
   *  Operator: sqrt
   */
  if (D < 0.0) {
    D = -sqrt(fabs(D));
  } else {
    D = sqrt(D);
  }

  /* End of Math: '<S32>/Math Function1' */

  /* Switch: '<S32>/Switch' incorporates:
   *  Constant: '<S32>/Constant'
   *  Product: '<S32>/Product'
   */
  if (D > rtP.NormalizeVector1_maxzero_c1) {
    rtb_Switch_idx_0 = rtB.thrust_v_ref[0];
    rtb_Switch_idx_1 = rtB.thrust_v_ref[1];
    rtb_Switch_idx_2 = rtB.thrust_v_ref[2];
    rtb_Switch_idx_3 = D;
  } else {
    rtb_Switch_idx_0 = rtB.thrust_v_ref[0] * 0.0;
    rtb_Switch_idx_1 = rtB.thrust_v_ref[1] * 0.0;
    rtb_Switch_idx_2 = rtB.thrust_v_ref[2] * 0.0;
    rtb_Switch_idx_3 = rtP.Constant_Value_bf;
  }

  /* End of Switch: '<S32>/Switch' */

  /* DotProduct: '<S8>/Dot Product1' incorporates:
   *  Product: '<S32>/Divide'
   */
  rtB.DotProduct1 = (rtb_Switch_idx_0 / rtb_Switch_idx_3 * scale +
                     rtb_Switch_idx_1 / rtb_Switch_idx_3 * absxk) +
    rtb_Switch_idx_2 / rtb_Switch_idx_3 * rtb_Divide_f_idx_2;

  /* ManualSwitch: '<S8>/Manual Switch1' incorporates:
   *  Constant: '<S8>/Constant11'
   *  Sum: '<S8>/Subtract1'
   */
  if (rtP.ManualSwitch1_CurrentSetting == 1) {
    rtB.ManualSwitch1 = rtB.DotProduct1;
  } else {
    rtB.ManualSwitch1 = rtP.Constant11_Value - rtB.DotProduct1;
  }

  /* End of ManualSwitch: '<S8>/Manual Switch1' */
  if (ssIsSampleHit(rtS, 1, 0)) {
  }

  /* Switch: '<S8>/Switch1' incorporates:
   *  Constant: '<S30>/Constant'
   *  Constant: '<S8>/Constant10'
   *  Constant: '<S8>/Constant12'
   *  RelationalOperator: '<S30>/Compare'
   */
  if (rtB.sight_solar == rtP.Constant_Value_e) {
    rtB.Switch1 = rtP.thrust_shadow_weight;
  } else {
    rtB.Switch1 = rtP.thrust_no_shadow_weight;
  }

  /* End of Switch: '<S8>/Switch1' */

  /* Product: '<S8>/Product' */
  rtB.current_solar_e = rtB.Switch1 * rtB.ManualSwitch1;

  /* Sum: '<S34>/Sum of Elements' incorporates:
   *  Math: '<S34>/Math Function'
   */
  D = rtB.comms_v[0] * rtB.comms_v[0];
  D += rtB.comms_v[1] * rtB.comms_v[1];
  D += rtB.comms_v[2] * rtB.comms_v[2];

  /* Math: '<S34>/Math Function1'
   *
   * About '<S34>/Math Function1':
   *  Operator: sqrt
   */
  if (D < 0.0) {
    D = -sqrt(fabs(D));
  } else {
    D = sqrt(D);
  }

  /* End of Math: '<S34>/Math Function1' */

  /* Switch: '<S34>/Switch' incorporates:
   *  Constant: '<S34>/Constant'
   *  Product: '<S34>/Product'
   */
  if (D > rtP.NormalizeVector_maxzero_p) {
    rtb_Switch_idx_0 = rtB.comms_v[0];
    rtb_Switch_idx_1 = rtB.comms_v[1];
    rtb_Switch_idx_2 = rtB.comms_v[2];
    rtb_Switch_idx_3 = D;
  } else {
    rtb_Switch_idx_0 = rtB.comms_v[0] * 0.0;
    rtb_Switch_idx_1 = rtB.comms_v[1] * 0.0;
    rtb_Switch_idx_2 = rtB.comms_v[2] * 0.0;
    rtb_Switch_idx_3 = rtP.Constant_Value_os;
  }

  /* End of Switch: '<S34>/Switch' */

  /* Product: '<S34>/Divide' */
  scale = rtb_Switch_idx_0 / rtb_Switch_idx_3;
  absxk = rtb_Switch_idx_1 / rtb_Switch_idx_3;
  rtb_Divide_f_idx_2 = rtb_Switch_idx_2 / rtb_Switch_idx_3;

  /* Sum: '<S35>/Sum of Elements' incorporates:
   *  Math: '<S35>/Math Function'
   */
  D = rtB.Product_f[0] * rtB.Product_f[0];
  D += rtB.Product_f[1] * rtB.Product_f[1];
  D += rtB.Product_f[2] * rtB.Product_f[2];

  /* Math: '<S35>/Math Function1'
   *
   * About '<S35>/Math Function1':
   *  Operator: sqrt
   */
  if (D < 0.0) {
    D = -sqrt(fabs(D));
  } else {
    D = sqrt(D);
  }

  /* End of Math: '<S35>/Math Function1' */

  /* Switch: '<S35>/Switch' incorporates:
   *  Constant: '<S35>/Constant'
   *  Product: '<S35>/Product'
   */
  if (D > rtP.NormalizeVector1_maxzero_d) {
    rtb_Switch_idx_0 = rtB.Product_f[0];
    rtb_Switch_idx_1 = rtB.Product_f[1];
    rtb_Switch_idx_2 = rtB.Product_f[2];
    rtb_Switch_idx_3 = D;
  } else {
    rtb_Switch_idx_0 = rtB.Product_f[0] * 0.0;
    rtb_Switch_idx_1 = rtB.Product_f[1] * 0.0;
    rtb_Switch_idx_2 = rtB.Product_f[2] * 0.0;
    rtb_Switch_idx_3 = rtP.Constant_Value_n;
  }

  /* End of Switch: '<S35>/Switch' */

  /* DotProduct: '<S9>/Dot Product1' incorporates:
   *  Product: '<S35>/Divide'
   */
  D = (rtb_Switch_idx_0 / rtb_Switch_idx_3 * scale + rtb_Switch_idx_1 /
       rtb_Switch_idx_3 * absxk) + rtb_Switch_idx_2 / rtb_Switch_idx_3 *
    rtb_Divide_f_idx_2;

  /* ManualSwitch: '<S9>/Manual Switch1' incorporates:
   *  Constant: '<S9>/Constant11'
   *  Saturate: '<S9>/Saturation'
   *  Sum: '<S9>/Subtract1'
   */
  if (rtP.ManualSwitch1_CurrentSetting_k == 1) {
    /* Saturate: '<S9>/Saturation' */
    if (D > rtP.Saturation_UpperSat_e) {
      rtB.ManualSwitch1_c = rtP.Saturation_UpperSat_e;
    } else if (D < rtP.Saturation_LowerSat_n) {
      rtB.ManualSwitch1_c = rtP.Saturation_LowerSat_n;
    } else {
      rtB.ManualSwitch1_c = D;
    }
  } else {
    if (D > rtP.Saturation_UpperSat_e) {
      /* Saturate: '<S9>/Saturation' */
      D = rtP.Saturation_UpperSat_e;
    } else {
      if (D < rtP.Saturation_LowerSat_n) {
        /* Saturate: '<S9>/Saturation' */
        D = rtP.Saturation_LowerSat_n;
      }
    }

    rtB.ManualSwitch1_c = rtP.Constant11_Value_h - D;
  }

  /* End of ManualSwitch: '<S9>/Manual Switch1' */
  if (ssIsSampleHit(rtS, 1, 0)) {
  }

  /* Product: '<S9>/Product' */
  rtB.current_solar_e_p = rtB.sight_comms * rtB.ManualSwitch1_c;

  /* Sum: '<S37>/Sum of Elements' incorporates:
   *  Math: '<S37>/Math Function'
   */
  D = rtB.solar_v[0] * rtB.solar_v[0];
  D += rtB.solar_v[1] * rtB.solar_v[1];
  D += rtB.solar_v[2] * rtB.solar_v[2];

  /* Math: '<S37>/Math Function1'
   *
   * About '<S37>/Math Function1':
   *  Operator: sqrt
   */
  if (D < 0.0) {
    D = -sqrt(fabs(D));
  } else {
    D = sqrt(D);
  }

  /* End of Math: '<S37>/Math Function1' */

  /* Switch: '<S37>/Switch' incorporates:
   *  Constant: '<S37>/Constant'
   *  Product: '<S37>/Product'
   */
  if (D > rtP.NormalizeVector_maxzero_j) {
    rtb_Switch_idx_0 = rtB.solar_v[0];
    rtb_Switch_idx_1 = rtB.solar_v[1];
    rtb_Switch_idx_2 = rtB.solar_v[2];
    rtb_Switch_idx_3 = D;
  } else {
    rtb_Switch_idx_0 = rtB.solar_v[0] * 0.0;
    rtb_Switch_idx_1 = rtB.solar_v[1] * 0.0;
    rtb_Switch_idx_2 = rtB.solar_v[2] * 0.0;
    rtb_Switch_idx_3 = rtP.Constant_Value_ku;
  }

  /* End of Switch: '<S37>/Switch' */

  /* Product: '<S37>/Divide' */
  scale = rtb_Switch_idx_0 / rtb_Switch_idx_3;
  absxk = rtb_Switch_idx_1 / rtb_Switch_idx_3;
  rtb_Divide_f_idx_2 = rtb_Switch_idx_2 / rtb_Switch_idx_3;

  /* Sum: '<S38>/Sum of Elements' incorporates:
   *  Math: '<S38>/Math Function'
   */
  D = rtB.Product[0] * rtB.Product[0];
  D += rtB.Product[1] * rtB.Product[1];
  D += rtB.Product[2] * rtB.Product[2];

  /* Math: '<S38>/Math Function1'
   *
   * About '<S38>/Math Function1':
   *  Operator: sqrt
   */
  if (D < 0.0) {
    D = -sqrt(fabs(D));
  } else {
    D = sqrt(D);
  }

  /* End of Math: '<S38>/Math Function1' */

  /* Switch: '<S38>/Switch' incorporates:
   *  Constant: '<S38>/Constant'
   *  Product: '<S38>/Product'
   */
  if (D > rtP.NormalizeVector1_maxzero_g) {
    rtb_Switch_idx_0 = rtB.Product[0];
    rtb_Switch_idx_1 = rtB.Product[1];
    rtb_Switch_idx_2 = rtB.Product[2];
    rtb_Switch_idx_3 = D;
  } else {
    rtb_Switch_idx_0 = rtB.Product[0] * 0.0;
    rtb_Switch_idx_1 = rtB.Product[1] * 0.0;
    rtb_Switch_idx_2 = rtB.Product[2] * 0.0;
    rtb_Switch_idx_3 = rtP.Constant_Value_lf;
  }

  /* End of Switch: '<S38>/Switch' */

  /* ManualSwitch: '<S10>/Manual Switch1' incorporates:
   *  Constant: '<S10>/Constant11'
   *  Sum: '<S10>/Subtract1'
   */
  if (rtP.ManualSwitch1_CurrentSetting_g == 1) {
    /* DotProduct: '<S10>/Dot Product1' incorporates:
     *  Product: '<S38>/Divide'
     */
    D = (rtb_Switch_idx_0 / rtb_Switch_idx_3 * scale + rtb_Switch_idx_1 /
         rtb_Switch_idx_3 * absxk) + rtb_Switch_idx_2 / rtb_Switch_idx_3 *
      rtb_Divide_f_idx_2;

    /* Saturate: '<S10>/Saturation' incorporates:
     *  DotProduct: '<S10>/Dot Product1'
     */
    if (D > rtP.Saturation_UpperSat_l) {
      rtB.ManualSwitch1_m = rtP.Saturation_UpperSat_l;
    } else if (D < rtP.Saturation_LowerSat_pj) {
      rtB.ManualSwitch1_m = rtP.Saturation_LowerSat_pj;
    } else {
      rtB.ManualSwitch1_m = D;
    }
  } else {
    /* DotProduct: '<S10>/Dot Product1' incorporates:
     *  Product: '<S38>/Divide'
     */
    D = (rtb_Switch_idx_0 / rtb_Switch_idx_3 * scale + rtb_Switch_idx_1 /
         rtb_Switch_idx_3 * absxk) + rtb_Switch_idx_2 / rtb_Switch_idx_3 *
      rtb_Divide_f_idx_2;

    /* Saturate: '<S10>/Saturation' incorporates:
     *  DotProduct: '<S10>/Dot Product1'
     */
    if (D > rtP.Saturation_UpperSat_l) {
      D = rtP.Saturation_UpperSat_l;
    } else {
      if (D < rtP.Saturation_LowerSat_pj) {
        D = rtP.Saturation_LowerSat_pj;
      }
    }

    rtB.ManualSwitch1_m = rtP.Constant11_Value_c - D;
  }

  /* End of ManualSwitch: '<S10>/Manual Switch1' */
  if (ssIsSampleHit(rtS, 1, 0)) {
  }

  /* Product: '<S10>/Product' */
  rtB.current_solar_e_pn = rtB.sight_solar * rtB.ManualSwitch1_m;

  /* Clock: '<S3>/Clock1' */
  rtB.Clock1 = t;
  if (ssIsSampleHit(rtS, 1, 0)) {
    /* Scope: '<S3>/Scope' incorporates:
     *  Constant: '<S3>/Constant'
     */
    D = 0.997 * rtP.P;
  }

  /* RelationalOperator: '<S20>/Compare' incorporates:
   *  Constant: '<S20>/Constant'
   *  Constant: '<S3>/Constant'
   *  Sum: '<S3>/Sum'
   */
  rtB.Compare = (0.997 * rtP.P - rtB.Clock1 <= rtP.Constant_Value_k);

  /* Stop: '<S3>/Stop Simulation' */
  if (ssIsSampleHit(rtS, 1, 0) && rtB.Compare) {
    ssSetStopRequested(rtS, 1);
  }

  /* End of Stop: '<S3>/Stop Simulation' */
  UNUSED_PARAMETER(tid);
}

/* Update for root system: '<Root>' */
void MdlUpdate(int_T tid)
{
  /* Update for Integrator: '<S4>/Integrator' */
  rtDW.Integrator_IWORK = 0;
  UNUSED_PARAMETER(tid);
}

/* Derivatives for root system: '<Root>' */
void MdlDerivatives(void)
{
  XDot *_rtXdot;
  _rtXdot = ((XDot *) ssGetdX(rtS));

  /* Derivatives for Integrator: '<S10>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = rtB.current_solar_e_pn;

  /* Derivatives for Integrator: '<S9>/Integrator1' */
  _rtXdot->Integrator1_CSTATE_a = rtB.current_solar_e_p;

  /* Derivatives for Integrator: '<S4>/Integrator' */
  _rtXdot->Integrator_CSTATE[0] = rtB.q_dot[0];
  _rtXdot->Integrator_CSTATE[1] = rtB.q_dot[1];
  _rtXdot->Integrator_CSTATE[2] = rtB.q_dot[2];
  _rtXdot->Integrator_CSTATE[3] = rtB.q_dot[3];

  /* Derivatives for Integrator: '<S8>/Integrator2' */
  _rtXdot->Integrator2_CSTATE = rtB.Switch1;

  /* Derivatives for Integrator: '<S8>/Integrator1' */
  _rtXdot->Integrator1_CSTATE_f = rtB.current_solar_e;
}

/* Projection for root system: '<Root>' */
void MdlProjection(void)
{
}

/* Termination for root system: '<Root>' */
void MdlTerminate(void)
{
  /* Terminate for FromFile: '<Root>/From File' */
  {
    const char *errMsg = (NULL);
    void *fp = (void *) rtDW.FromFile_PWORK.PrevTimePtr;
    if (fp != (NULL)) {
      errMsg = rtwMatFileLoaderCollectionDestroyInstance( 0, fp );
      if (errMsg != (NULL)) {
        ssSetErrorStatus(rtS, errMsg);
        return;
      }
    }
  }

  /* Terminate for FromFile: '<Root>/From File1' */
  {
    const char *errMsg = (NULL);
    void *fp = (void *) rtDW.FromFile1_PWORK.PrevTimePtr;
    if (fp != (NULL)) {
      errMsg = rtwMatFileLoaderCollectionDestroyInstance( 0, fp );
      if (errMsg != (NULL)) {
        ssSetErrorStatus(rtS, errMsg);
        return;
      }
    }
  }

  /* Terminate for FromFile: '<Root>/From File6' */
  {
    const char *errMsg = (NULL);
    void *fp = (void *) rtDW.FromFile6_PWORK.PrevTimePtr;
    if (fp != (NULL)) {
      errMsg = rtwMatFileLoaderCollectionDestroyInstance( 0, fp );
      if (errMsg != (NULL)) {
        ssSetErrorStatus(rtS, errMsg);
        return;
      }
    }
  }

  /* Terminate for FromFile: '<Root>/From File7' */
  {
    const char *errMsg = (NULL);
    void *fp = (void *) rtDW.FromFile7_PWORK.PrevTimePtr;
    if (fp != (NULL)) {
      errMsg = rtwMatFileLoaderCollectionDestroyInstance( 0, fp );
      if (errMsg != (NULL)) {
        ssSetErrorStatus(rtS, errMsg);
        return;
      }
    }
  }

  /* Terminate for FromFile: '<Root>/From File2' */
  {
    const char *errMsg = (NULL);
    void *fp = (void *) rtDW.FromFile2_PWORK.PrevTimePtr;
    if (fp != (NULL)) {
      errMsg = rtwMatFileLoaderCollectionDestroyInstance( 0, fp );
      if (errMsg != (NULL)) {
        ssSetErrorStatus(rtS, errMsg);
        return;
      }
    }
  }

  /* Terminate for FromFile: '<Root>/From File3' */
  {
    const char *errMsg = (NULL);
    void *fp = (void *) rtDW.FromFile3_PWORK.PrevTimePtr;
    if (fp != (NULL)) {
      errMsg = rtwMatFileLoaderCollectionDestroyInstance( 0, fp );
      if (errMsg != (NULL)) {
        ssSetErrorStatus(rtS, errMsg);
        return;
      }
    }
  }

  /* Terminate for FromFile: '<Root>/From File4' */
  {
    const char *errMsg = (NULL);
    void *fp = (void *) rtDW.FromFile4_PWORK.PrevTimePtr;
    if (fp != (NULL)) {
      errMsg = rtwMatFileLoaderCollectionDestroyInstance( 0, fp );
      if (errMsg != (NULL)) {
        ssSetErrorStatus(rtS, errMsg);
        return;
      }
    }
  }

  /* Terminate for FromFile: '<Root>/From File9' */
  {
    const char *errMsg = (NULL);
    void *fp = (void *) rtDW.FromFile9_PWORK.PrevTimePtr;
    if (fp != (NULL)) {
      errMsg = rtwMatFileLoaderCollectionDestroyInstance( 0, fp );
      if (errMsg != (NULL)) {
        ssSetErrorStatus(rtS, errMsg);
        return;
      }
    }
  }

  /* Terminate for FromFile: '<Root>/From File10' */
  {
    const char *errMsg = (NULL);
    void *fp = (void *) rtDW.FromFile10_PWORK.PrevTimePtr;
    if (fp != (NULL)) {
      errMsg = rtwMatFileLoaderCollectionDestroyInstance( 0, fp );
      if (errMsg != (NULL)) {
        ssSetErrorStatus(rtS, errMsg);
        return;
      }
    }
  }

  /* Terminate for FromFile: '<Root>/From File11' */
  {
    const char *errMsg = (NULL);
    void *fp = (void *) rtDW.FromFile11_PWORK.PrevTimePtr;
    if (fp != (NULL)) {
      errMsg = rtwMatFileLoaderCollectionDestroyInstance( 0, fp );
      if (errMsg != (NULL)) {
        ssSetErrorStatus(rtS, errMsg);
        return;
      }
    }
  }

  /* Terminate for FromFile: '<Root>/From File5' */
  {
    const char *errMsg = (NULL);
    void *fp = (void *) rtDW.FromFile5_PWORK.PrevTimePtr;
    if (fp != (NULL)) {
      errMsg = rtwMatFileLoaderCollectionDestroyInstance( 0, fp );
      if (errMsg != (NULL)) {
        ssSetErrorStatus(rtS, errMsg);
        return;
      }
    }
  }

  /* Terminate for FromFile: '<Root>/From File12' */
  {
    const char *errMsg = (NULL);
    void *fp = (void *) rtDW.FromFile12_PWORK.PrevTimePtr;
    if (fp != (NULL)) {
      errMsg = rtwMatFileLoaderCollectionDestroyInstance( 0, fp );
      if (errMsg != (NULL)) {
        ssSetErrorStatus(rtS, errMsg);
        return;
      }
    }
  }

  /* Terminate for FromFile: '<Root>/From File8' */
  {
    const char *errMsg = (NULL);
    void *fp = (void *) rtDW.FromFile8_PWORK.PrevTimePtr;
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
  attitude3d_MovingMinimum_Term(&rtDW.MovingMinimum_pn);
}

/* Function to initialize sizes */
void MdlInitializeSizes(void)
{
  ssSetNumContStates(rtS, 8);          /* Number of continuous states */
  ssSetNumPeriodicContStates(rtS, 0); /* Number of periodic continuous states */
  ssSetNumY(rtS, 0);                   /* Number of model outputs */
  ssSetNumU(rtS, 0);                   /* Number of model inputs */
  ssSetDirectFeedThrough(rtS, 0);      /* The model is not direct feedthrough */
  ssSetNumSampleTimes(rtS, 2);         /* Number of sample times */
  ssSetNumBlocks(rtS, 387);            /* Number of blocks */
  ssSetNumBlockIO(rtS, 48);            /* Number of block outputs */
  ssSetNumBlockParams(rtS, 132);       /* Sum of parameter "widths" */
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
    dtInfo.numDataTypes = 16;
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

  ssSetChecksumVal(rtS, 0, 3150072023U);
  ssSetChecksumVal(rtS, 1, 3767935592U);
  ssSetChecksumVal(rtS, 2, 1838606884U);
  ssSetChecksumVal(rtS, 3, 4003405232U);
  return rtS;
}

/* When you use the on parameter, it resets the optimizations to those that you
   specified with the /O compiler option. */
#if defined(_MSC_VER)

#pragma optimize( "", on )

#endif
