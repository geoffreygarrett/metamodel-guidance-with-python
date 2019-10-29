/*
 * rtwdemo_rsim_i.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "rtwdemo_rsim_i".
 *
 * Model version              : 1.34
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 * C source code generated on : Tue Oct 29 10:15:23 2019
 *
 * Target selection: rsim.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include <math.h>
#include "rtwdemo_rsim_i.h"
#include "rtwdemo_rsim_i_private.h"
#include "rtwdemo_rsim_i_dt.h"

/* user code (top of parameter file) */
const int_T gblNumToFiles = 0;
const int_T gblNumFrFiles = 0;
const int_T gblNumFrWksBlocks = 0;
const char *gblSlvrJacPatternFileName =
  "rtwdemo_rsim_i_rsim_rtw//rtwdemo_rsim_i_Jpattern.mat";

/* Root inports information  */
const int_T gblNumRootInportBlks = 3;
const int_T gblNumModelInputs = 5;
extern rtInportTUtable *gblInportTUtables;
extern const char *gblInportFileName;
const int_T gblInportDataTypeIdx[] = { 0, 0, 0 };

const int_T gblInportDims[] = { 2, 1, 1, 1, 2, 1 } ;

const int_T gblInportComplex[] = { 0, 0, 0 };

const int_T gblInportInterpoFlag[] = { 1, 1, 0 };

const int_T gblInportContinuous[] = { 1, 1, 1 };

#include "simstruc.h"
#include "fixedpoint.h"

/* Block states (default storage) */
DW rtDW;

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Parent Simstruct */
static SimStruct model_S;
SimStruct *const rtS = &model_S;

/* Start for root system: '<Root>' */
void MdlStart(void)
{
}

/* Outputs for root system: '<Root>' */
void MdlOutputs(int_T tid)
{
  /* local block i/o variables */
  real_T rtb_Add;
  real_T rtb_Gain;
  real_T rtb_Add1;
  real_T rtb_Gain1_idx_0;
  real_T rtb_Gain1_idx_1;

  /* Read data from the mat file of inport block */
  if (gblInportFileName != (NULL)) {
    real_T time = ssGetT(rtS);
    int_T currTimeIdx;
    int_T i;

    /*
     *  Read in data from mat file for root inport In1
     */
    if (gblInportTUtables[0].nTimePoints > 0) {
      {
        {
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
          for (i = 0; i < 2; i++) {
            real_T* realPtr1 = (real_T*)gblInportTUtables[0].ur +
              i*gblInportTUtables[0].nTimePoints +currTimeIdx;
            real_T* realPtr2 = realPtr1 + 1*k;
            (void)rt_Interpolate_Datatype(
              realPtr1,
              realPtr2,
              &rtU.In1[i],
              time,
              gblInportTUtables[0].time[currTimeIdx],
              gblInportTUtables[0].time[currTimeIdx + k],
              gblInportTUtables[0].uDataType);
          }
        }
      }
    }

    /*
     *  Read in data from mat file for root inport In2
     */
    if (gblInportTUtables[1].nTimePoints > 0) {
      {
        {
          int k = 1;
          if (gblInportTUtables[1].nTimePoints == 1) {
            k = 0;
          }

          currTimeIdx = rt_getTimeIdx(gblInportTUtables[1].time, time,
            gblInportTUtables[1].nTimePoints,
            gblInportTUtables[1].currTimeIdx,
            1,
            0);
          gblInportTUtables[1].currTimeIdx = currTimeIdx;
          for (i = 0; i < 1; i++) {
            real_T* realPtr1 = (real_T*)gblInportTUtables[1].ur +
              i*gblInportTUtables[1].nTimePoints +currTimeIdx;
            real_T* realPtr2 = realPtr1 + 1*k;
            (void)rt_Interpolate_Datatype(
              realPtr1,
              realPtr2,
              &rtU.In2,
              time,
              gblInportTUtables[1].time[currTimeIdx],
              gblInportTUtables[1].time[currTimeIdx + k],
              gblInportTUtables[1].uDataType);
          }
        }
      }
    }

    /*
     *  Read in data from mat file for root inport In3
     */
    if (gblInportTUtables[2].nTimePoints > 0) {
      {
        {
          currTimeIdx = rt_getTimeIdx(gblInportTUtables[2].time, time,
            gblInportTUtables[2].nTimePoints,
            gblInportTUtables[2].currTimeIdx,
            0,
            0);
          gblInportTUtables[2].currTimeIdx = currTimeIdx;
          for (i = 0; i < 2; i++) {
            if (currTimeIdx == -7) {
              rtU.In3[i] = 0.0;
            } else {
              real_T* realPtr1 = (real_T*)gblInportTUtables[2].ur +
                i*gblInportTUtables[2].nTimePoints +currTimeIdx;
              rtU.In3[i] = *realPtr1;
            }
          }
        }
      }
    }
  }

  /* end read inport data from file */

  /* Math: '<Root>/Math Function' incorporates:
   *  Inport: '<Root>/In1'
   *
   * About '<Root>/Math Function':
   *  Operator: magnitude^2
   */
  rtb_Add = rtU.In1[0] * rtU.In1[0];

  /* Math: '<Root>/Math Function1' incorporates:
   *  Inport: '<Root>/In1'
   *
   * About '<Root>/Math Function1':
   *  Operator: magnitude^2
   */
  rtb_Gain = rtU.In1[1] * rtU.In1[1];

  /* Sum: '<Root>/Add' */
  rtb_Add += rtb_Gain;

  /* Outport: '<Root>/Out1' */
  rtY.Out1 = rtb_Add;

  /* Gain: '<Root>/Gain' incorporates:
   *  Inport: '<Root>/In2'
   */
  rtb_Gain = 2.0 * rtU.In2;

  /* Outport: '<Root>/Out2' */
  rtY.Out2 = rtb_Gain;

  /* Gain: '<Root>/Gain1' incorporates:
   *  Inport: '<Root>/In3'
   */
  rtb_Gain1_idx_0 = 2.0 * rtU.In3[0];
  rtb_Gain1_idx_1 = 2.0 * rtU.In3[1];

  /* Math: '<Root>/Math Function2'
   *
   * About '<Root>/Math Function2':
   *  Operator: magnitude^2
   */
  rtb_Add1 = rtb_Gain1_idx_0 * rtb_Gain1_idx_0;

  /* Sum: '<Root>/Add1' incorporates:
   *  Math: '<Root>/Math Function3'
   *
   * About '<Root>/Math Function3':
   *  Operator: magnitude^2
   */
  rtb_Add1 += rtb_Gain1_idx_1 * rtb_Gain1_idx_1;

  /* Outport: '<Root>/Out3' */
  rtY.Out3 = rtb_Add1;
  UNUSED_PARAMETER(tid);
}

/* Update for root system: '<Root>' */
void MdlUpdate(int_T tid)
{
  UNUSED_PARAMETER(tid);
}

/* Termination for root system: '<Root>' */
void MdlTerminate(void)
{
}

/* Function to initialize sizes */
void MdlInitializeSizes(void)
{
  ssSetNumContStates(rtS, 0);          /* Number of continuous states */
  ssSetNumY(rtS, 3);                   /* Number of model outputs */
  ssSetNumU(rtS, 5);                   /* Number of model inputs */
  ssSetDirectFeedThrough(rtS, 1);      /* The model is direct feedthrough */
  ssSetNumSampleTimes(rtS, 1);         /* Number of sample times */
  ssSetNumBlocks(rtS, 12);             /* Number of blocks */
  ssSetNumBlockIO(rtS, 0);             /* Number of block outputs */
}

/* Function to initialize sample times. */
void MdlInitializeSampleTimes(void)
{
  /* task periods */
  ssSetSampleTime(rtS, 0, 0.0);

  /* task offsets */
  ssSetOffsetTime(rtS, 0, 0.0);
}

/* Function to register the model */
/* Turns off all optimizations on Windows because of issues with VC 2015 compiler.
   This function is not performance-critical, hence this is not a problem.
 */
#if defined(_MSC_VER)

#pragma optimize( "", off )

#endif

SimStruct * rtwdemo_rsim_i(void)
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
    static boolean_T mdlTNextWasAdjustedPtr[NSAMPLE_TIMES];
    static int_T mdlPerTaskSampleHits[NSAMPLE_TIMES * NSAMPLE_TIMES];
    static time_T mdlTimeOfNextSampleHit[NSAMPLE_TIMES];

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
    ssSetTNextWasAdjustedPtr(rtS, &mdlTNextWasAdjustedPtr[0]);
    ssSetPerTaskSampleHitsPtr(rtS, &mdlPerTaskSampleHits[0]);
    ssSetTimeOfNextSampleHitPtr(rtS, &mdlTimeOfNextSampleHit[0]);
  }

  ssSetSolverMode(rtS, SOLVER_MODE_SINGLETASKING);

  /*
   * initialize model vectors and cache them in SimStruct
   */

  /* external inputs */
  {
    ssSetU(rtS, ((void*) &rtU));
    (void)memset(&rtU, 0, sizeof(ExtU));
  }

  /* external outputs */
  {
    ssSetY(rtS, &rtY);
    (void) memset((void *)&rtY, 0,
                  sizeof(ExtY));
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
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;
  }

  /* Model specific registration */
  ssSetRootSS(rtS, rtS);
  ssSetVersion(rtS, SIMSTRUCT_VERSION_LEVEL2);
  ssSetModelName(rtS, "rtwdemo_rsim_i");
  ssSetPath(rtS, "rtwdemo_rsim_i");
  ssSetTStart(rtS, 0.0);
  ssSetTFinal(rtS, 6.0);

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
    rtliSetLogFormat(ssGetRTWLogInfo(rtS), 0);
    rtliSetLogMaxRows(ssGetRTWLogInfo(rtS), 1000);
    rtliSetLogDecimation(ssGetRTWLogInfo(rtS), 1);

    /*
     * Set pointers to the data and signal info for each output
     */
    {
      static void * rt_LoggedOutputSignalPtrs[] = {
        &rtY.Out1,
        &rtY.Out2,
        &rtY.Out3
      };

      rtliSetLogYSignalPtrs(ssGetRTWLogInfo(rtS), ((LogSignalPtrsType)
        rt_LoggedOutputSignalPtrs));
    }

    {
      static int_T rt_LoggedOutputWidths[] = {
        1,
        1,
        1
      };

      static int_T rt_LoggedOutputNumDimensions[] = {
        1,
        1,
        1
      };

      static int_T rt_LoggedOutputDimensions[] = {
        1,
        1,
        1
      };

      static boolean_T rt_LoggedOutputIsVarDims[] = {
        0,
        0,
        0
      };

      static void* rt_LoggedCurrentSignalDimensions[] = {
        (NULL),
        (NULL),
        (NULL)
      };

      static int_T rt_LoggedCurrentSignalDimensionsSize[] = {
        4,
        4,
        4
      };

      static BuiltInDTypeId rt_LoggedOutputDataTypeIds[] = {
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE
      };

      static int_T rt_LoggedOutputComplexSignals[] = {
        0,
        0,
        0
      };

      static RTWPreprocessingFcnPtr rt_LoggingPreprocessingFcnPtrs[] = {
        (NULL),
        (NULL),
        (NULL)
      };

      static const char_T *rt_LoggedOutputLabels[] = {
        "",
        "",
        "" };

      static const char_T *rt_LoggedOutputBlockNames[] = {
        "rtwdemo_rsim_i/Out1",
        "rtwdemo_rsim_i/Out2",
        "rtwdemo_rsim_i/Out3" };

      static RTWLogDataTypeConvert rt_RTWLogDataTypeConvert[] = {
        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 }
      };

      static RTWLogSignalInfo rt_LoggedOutputSignalInfo[] = {
        {
          3,
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

          { rt_LoggedOutputLabels },
          (NULL),
          (NULL),
          (NULL),

          { rt_LoggedOutputBlockNames },

          { (NULL) },
          (NULL),
          rt_RTWLogDataTypeConvert
        }
      };

      rtliSetLogYSignalInfo(ssGetRTWLogInfo(rtS), rt_LoggedOutputSignalInfo);

      /* set currSigDims field */
      rt_LoggedCurrentSignalDimensions[0] = &rt_LoggedOutputWidths[0];
      rt_LoggedCurrentSignalDimensions[1] = &rt_LoggedOutputWidths[1];
      rt_LoggedCurrentSignalDimensions[2] = &rt_LoggedOutputWidths[2];
    }

    rtliSetLogY(ssGetRTWLogInfo(rtS), "yout");
  }

  {
    static ssSolverInfo slvrInfo;
    ssSetStepSize(rtS, 0.2);
    ssSetMinStepSize(rtS, 0.0);
    ssSetMaxNumMinSteps(rtS, -1);
    ssSetMinStepViolatedError(rtS, 0);
    ssSetMaxStepSize(rtS, 0.2);
    ssSetSolverMaxOrder(rtS, -1);
    ssSetSolverRefineFactor(rtS, 1);
    ssSetOutputTimes(rtS, (NULL));
    ssSetNumOutputTimes(rtS, 0);
    ssSetOutputTimesOnly(rtS, 0);
    ssSetOutputTimesIndex(rtS, 0);
    ssSetZCCacheNeedsReset(rtS, 0);
    ssSetDerivCacheNeedsReset(rtS, 0);
    ssSetNumNonContDerivSigInfos(rtS, 0);
    ssSetNonContDerivSigInfos(rtS, (NULL));
    ssSetSolverInfo(rtS, &slvrInfo);
    ssSetSolverName(rtS, "VariableStepDiscrete");
    ssSetVariableStepSolver(rtS, 1);
    ssSetSolverConsistencyChecking(rtS, 0);
    ssSetSolverAdaptiveZcDetection(rtS, 0);
    ssSetSolverRobustResetMethod(rtS, 0);
    ssSetSolverStateProjection(rtS, 0);
    ssSetSolverMassMatrixType(rtS, (ssMatrixType)0);
    ssSetSolverMassMatrixNzMax(rtS, 0);
    ssSetModelOutputs(rtS, MdlOutputs);
    ssSetModelLogData(rtS, rt_UpdateTXYLogVars);
    ssSetModelLogDataIfInInterval(rtS, rt_UpdateTXXFYLogVars);
    ssSetModelUpdate(rtS, MdlUpdate);
    ssSetTNextTid(rtS, INT_MIN);
    ssSetTNext(rtS, rtMinusInf);
    ssSetSolverNeedsReset(rtS);
    ssSetNumNonsampledZCs(rtS, 0);
  }

  ssSetChecksumVal(rtS, 0, 2684572843U);
  ssSetChecksumVal(rtS, 1, 873763423U);
  ssSetChecksumVal(rtS, 2, 3084513406U);
  ssSetChecksumVal(rtS, 3, 1535605258U);
  return rtS;
}

/* When you use the on parameter, it resets the optimizations to those that you
   specified with the /O compiler option. */
#if defined(_MSC_VER)

#pragma optimize( "", on )

#endif
