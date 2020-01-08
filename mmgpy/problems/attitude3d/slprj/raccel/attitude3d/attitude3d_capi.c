#include "__cf_attitude3d.h"
#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "attitude3d_capi_host.h"
#define sizeof(s) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)    
#else
#include "builtin_typeid_types.h"
#include "attitude3d.h"
#include "attitude3d_capi.h"
#include "attitude3d_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST                  
#define TARGET_STRING(s)               (NULL)                    
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static const rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 0 , TARGET_STRING (
"attitude3d/From File13" ) , TARGET_STRING ( "E" ) , 0 , 1 , 1 , 0 , 0 } , {
1 , 0 , TARGET_STRING (
"attitude3d/Orbital Period Termination Condition/Clock1" ) , TARGET_STRING (
"" ) , 0 , 0 , 1 , 0 , 0 } , { 2 , 0 , TARGET_STRING (
"attitude3d/Orbital Period Termination Condition/Constant" ) , TARGET_STRING
( "" ) , 0 , 0 , 1 , 0 , 1 } , { 3 , 1 , TARGET_STRING (
"attitude3d/Quaternion Propagator/Quaternion Normed" ) , TARGET_STRING ( "" )
, 0 , 0 , 2 , 0 , 0 } , { 4 , 0 , TARGET_STRING (
"attitude3d/Star Sensor 1 Minimum Solar Exclusion/Product" ) , TARGET_STRING
( "min_exclusion" ) , 0 , 0 , 1 , 0 , 0 } , { 5 , 0 , TARGET_STRING (
"attitude3d/Star Sensor 1 Minimum Solar Exclusion/Saturation" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 6 , 0 , TARGET_STRING (
"attitude3d/Star Sensor 1 Minimum Solar Exclusion/Acos" ) , TARGET_STRING (
"" ) , 0 , 0 , 1 , 0 , 0 } , { 7 , 2 , TARGET_STRING (
"attitude3d/Star Sensor 1 Minimum Solar Exclusion/Moving Minimum" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 8 , 0 , TARGET_STRING (
"attitude3d/Star Sensor 2 Minimum Solar Exclusion/Product" ) , TARGET_STRING
( "min_exclusion" ) , 0 , 0 , 1 , 0 , 0 } , { 9 , 0 , TARGET_STRING (
"attitude3d/Star Sensor 2 Minimum Solar Exclusion/Saturation" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 10 , 0 , TARGET_STRING (
"attitude3d/Star Sensor 2 Minimum Solar Exclusion/Acos" ) , TARGET_STRING (
"" ) , 0 , 0 , 1 , 0 , 0 } , { 11 , 5 , TARGET_STRING (
"attitude3d/Star Sensor 2 Minimum Solar Exclusion/Moving Minimum" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 12 , 0 , TARGET_STRING (
"attitude3d/Subsystem/Switch" ) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 }
, { 13 , 8 , TARGET_STRING ( "attitude3d/Subsystem/Moving Maximum" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 2 } , { 14 , 0 , TARGET_STRING (
"attitude3d/Subsystem1/Switch" ) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 }
, { 15 , 11 , TARGET_STRING ( "attitude3d/Subsystem1/Moving Maximum" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 2 } , { 16 , 0 , TARGET_STRING (
"attitude3d/Thrust Pointing Efficiency/Integrator1" ) , TARGET_STRING (
"integral_pointing" ) , 0 , 0 , 1 , 0 , 0 } , { 17 , 0 , TARGET_STRING (
"attitude3d/Thrust Pointing Efficiency/Divide" ) , TARGET_STRING ( "" ) , 0 ,
0 , 1 , 0 , 0 } , { 18 , 0 , TARGET_STRING (
"attitude3d/Thrust Pointing Efficiency/Product" ) , TARGET_STRING (
"current_solar_e" ) , 0 , 0 , 1 , 0 , 0 } , { 19 , 0 , TARGET_STRING (
"attitude3d/Thrust Pointing Efficiency/Switch" ) , TARGET_STRING ( "" ) , 0 ,
0 , 1 , 0 , 0 } , { 20 , 0 , TARGET_STRING (
"attitude3d/Thrust Pointing Efficiency/Manual Switch1" ) , TARGET_STRING ( ""
) , 0 , 0 , 1 , 0 , 0 } , { 21 , 0 , TARGET_STRING (
"attitude3d/Thrust Pointing Efficiency/Dot Product1" ) , TARGET_STRING ( "" )
, 0 , 0 , 1 , 0 , 0 } , { 22 , 0 , TARGET_STRING (
"attitude3d/Total Pointing Efficiency (Comms)/Divide" ) , TARGET_STRING ( ""
) , 0 , 0 , 1 , 0 , 0 } , { 23 , 0 , TARGET_STRING (
"attitude3d/Total Pointing Efficiency (Comms)/Product" ) , TARGET_STRING (
"current_solar_e" ) , 0 , 0 , 1 , 0 , 0 } , { 24 , 0 , TARGET_STRING (
"attitude3d/Total Pointing Efficiency (Comms)/Manual Switch1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 25 , 0 , TARGET_STRING (
"attitude3d/Total Pointing Efficiency (Solar)/Divide" ) , TARGET_STRING ( ""
) , 0 , 0 , 1 , 0 , 0 } , { 26 , 0 , TARGET_STRING (
"attitude3d/Total Pointing Efficiency (Solar)/Product" ) , TARGET_STRING (
"current_solar_e" ) , 0 , 0 , 1 , 0 , 0 } , { 27 , 0 , TARGET_STRING (
"attitude3d/transposeQuaternion2/Gain1" ) , TARGET_STRING ( "" ) , 0 , 0 , 2
, 0 , 2 } , { 28 , 0 , TARGET_STRING (
"attitude3d/Orbital Period Termination Condition/Compare To Zero/Compare" ) ,
TARGET_STRING ( "" ) , 0 , 2 , 1 , 0 , 0 } , { 29 , 0 , TARGET_STRING (
"attitude3d/Quaternion Propagator/qDot/Gain" ) , TARGET_STRING ( "q_dot" ) ,
0 , 0 , 2 , 0 , 0 } , { 30 , 0 , TARGET_STRING (
"attitude3d/Subsystem2/frame change5/Product" ) , TARGET_STRING ( "" ) , 0 ,
0 , 0 , 0 , 0 } , { 31 , 0 , TARGET_STRING (
"attitude3d/Subsystem2/frame change6/Product" ) , TARGET_STRING ( "" ) , 0 ,
0 , 0 , 0 , 0 } , { 32 , 0 , TARGET_STRING (
"attitude3d/Subsystem2/frame change7/Product" ) , TARGET_STRING ( "" ) , 0 ,
0 , 0 , 0 , 0 } , { 33 , 0 , TARGET_STRING (
"attitude3d/Subsystem2/frame change8/Product" ) , TARGET_STRING ( "" ) , 0 ,
0 , 0 , 0 , 0 } , { 34 , 0 , TARGET_STRING (
"attitude3d/Subsystem2/frame change9/Product" ) , TARGET_STRING ( "" ) , 0 ,
0 , 0 , 0 , 0 } , { 0 , 0 , ( NULL ) , ( NULL ) , 0 , 0 , 0 , 0 , 0 } } ;
static const rtwCAPI_BlockParameters rtBlockParameters [ ] = { { 35 ,
TARGET_STRING (
"attitude3d/Star Sensor 1 Minimum Solar Exclusion/Normalize Vector" ) ,
TARGET_STRING ( "maxzero" ) , 0 , 1 , 0 } , { 36 , TARGET_STRING (
"attitude3d/Star Sensor 1 Minimum Solar Exclusion/Normalize Vector1" ) ,
TARGET_STRING ( "maxzero" ) , 0 , 1 , 0 } , { 37 , TARGET_STRING (
"attitude3d/Star Sensor 1 Minimum Solar Exclusion/Saturation" ) ,
TARGET_STRING ( "UpperLimit" ) , 0 , 1 , 0 } , { 38 , TARGET_STRING (
"attitude3d/Star Sensor 1 Minimum Solar Exclusion/Saturation" ) ,
TARGET_STRING ( "LowerLimit" ) , 0 , 1 , 0 } , { 39 , TARGET_STRING (
"attitude3d/Star Sensor 2 Minimum Solar Exclusion/Normalize Vector" ) ,
TARGET_STRING ( "maxzero" ) , 0 , 1 , 0 } , { 40 , TARGET_STRING (
"attitude3d/Star Sensor 2 Minimum Solar Exclusion/Normalize Vector1" ) ,
TARGET_STRING ( "maxzero" ) , 0 , 1 , 0 } , { 41 , TARGET_STRING (
"attitude3d/Star Sensor 2 Minimum Solar Exclusion/Saturation" ) ,
TARGET_STRING ( "UpperLimit" ) , 0 , 1 , 0 } , { 42 , TARGET_STRING (
"attitude3d/Star Sensor 2 Minimum Solar Exclusion/Saturation" ) ,
TARGET_STRING ( "LowerLimit" ) , 0 , 1 , 0 } , { 43 , TARGET_STRING (
"attitude3d/Subsystem/Normalize Vector" ) , TARGET_STRING ( "maxzero" ) , 0 ,
1 , 0 } , { 44 , TARGET_STRING ( "attitude3d/Subsystem/Normalize Vector1" ) ,
TARGET_STRING ( "maxzero" ) , 0 , 1 , 0 } , { 45 , TARGET_STRING (
"attitude3d/Subsystem/Constant10" ) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 }
, { 46 , TARGET_STRING ( "attitude3d/Subsystem/Constant11" ) , TARGET_STRING
( "Value" ) , 0 , 1 , 0 } , { 47 , TARGET_STRING (
"attitude3d/Subsystem/Gain1" ) , TARGET_STRING ( "Gain" ) , 0 , 1 , 0 } , {
48 , TARGET_STRING ( "attitude3d/Subsystem1/Normalize Vector" ) ,
TARGET_STRING ( "maxzero" ) , 0 , 1 , 0 } , { 49 , TARGET_STRING (
"attitude3d/Subsystem1/Normalize Vector1" ) , TARGET_STRING ( "maxzero" ) , 0
, 1 , 0 } , { 50 , TARGET_STRING ( "attitude3d/Subsystem1/Constant10" ) ,
TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 51 , TARGET_STRING (
"attitude3d/Subsystem1/Constant11" ) , TARGET_STRING ( "Value" ) , 0 , 1 , 0
} , { 52 , TARGET_STRING ( "attitude3d/Subsystem1/Gain1" ) , TARGET_STRING (
"Gain" ) , 0 , 1 , 0 } , { 53 , TARGET_STRING (
"attitude3d/Thrust Pointing Efficiency/Normalize Vector" ) , TARGET_STRING (
"maxzero" ) , 0 , 1 , 0 } , { 54 , TARGET_STRING (
"attitude3d/Thrust Pointing Efficiency/Normalize Vector1" ) , TARGET_STRING (
"maxzero" ) , 0 , 1 , 0 } , { 55 , TARGET_STRING (
"attitude3d/Thrust Pointing Efficiency/Constant11" ) , TARGET_STRING (
"Value" ) , 0 , 1 , 0 } , { 56 , TARGET_STRING (
"attitude3d/Thrust Pointing Efficiency/Constant9" ) , TARGET_STRING ( "Value"
) , 0 , 1 , 0 } , { 57 , TARGET_STRING (
"attitude3d/Thrust Pointing Efficiency/Integrator1" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 1 , 0 } , { 58 , TARGET_STRING (
"attitude3d/Thrust Pointing Efficiency/Integrator2" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 1 , 0 } , { 59 , TARGET_STRING (
"attitude3d/Thrust Pointing Efficiency/Manual Switch1" ) , TARGET_STRING (
"CurrentSetting" ) , 3 , 1 , 0 } , { 60 , TARGET_STRING (
"attitude3d/Total Pointing Efficiency (Comms)/Normalize Vector" ) ,
TARGET_STRING ( "maxzero" ) , 0 , 1 , 0 } , { 61 , TARGET_STRING (
"attitude3d/Total Pointing Efficiency (Comms)/Normalize Vector1" ) ,
TARGET_STRING ( "maxzero" ) , 0 , 1 , 0 } , { 62 , TARGET_STRING (
"attitude3d/Total Pointing Efficiency (Comms)/Constant" ) , TARGET_STRING (
"Value" ) , 0 , 1 , 0 } , { 63 , TARGET_STRING (
"attitude3d/Total Pointing Efficiency (Comms)/Constant11" ) , TARGET_STRING (
"Value" ) , 0 , 1 , 0 } , { 64 , TARGET_STRING (
"attitude3d/Total Pointing Efficiency (Comms)/Integrator1" ) , TARGET_STRING
( "InitialCondition" ) , 0 , 1 , 0 } , { 65 , TARGET_STRING (
"attitude3d/Total Pointing Efficiency (Comms)/Saturation" ) , TARGET_STRING (
"UpperLimit" ) , 0 , 1 , 0 } , { 66 , TARGET_STRING (
"attitude3d/Total Pointing Efficiency (Comms)/Saturation" ) , TARGET_STRING (
"LowerLimit" ) , 0 , 1 , 0 } , { 67 , TARGET_STRING (
"attitude3d/Total Pointing Efficiency (Comms)/Manual Switch1" ) ,
TARGET_STRING ( "CurrentSetting" ) , 3 , 1 , 0 } , { 68 , TARGET_STRING (
"attitude3d/Total Pointing Efficiency (Solar)/Normalize Vector" ) ,
TARGET_STRING ( "maxzero" ) , 0 , 1 , 0 } , { 69 , TARGET_STRING (
"attitude3d/Total Pointing Efficiency (Solar)/Normalize Vector1" ) ,
TARGET_STRING ( "maxzero" ) , 0 , 1 , 0 } , { 70 , TARGET_STRING (
"attitude3d/Total Pointing Efficiency (Solar)/Constant" ) , TARGET_STRING (
"Value" ) , 0 , 1 , 0 } , { 71 , TARGET_STRING (
"attitude3d/Total Pointing Efficiency (Solar)/Integrator1" ) , TARGET_STRING
( "InitialCondition" ) , 0 , 1 , 0 } , { 72 , TARGET_STRING (
"attitude3d/Total Pointing Efficiency (Solar)/Saturation" ) , TARGET_STRING (
"UpperLimit" ) , 0 , 1 , 0 } , { 73 , TARGET_STRING (
"attitude3d/Total Pointing Efficiency (Solar)/Saturation" ) , TARGET_STRING (
"LowerLimit" ) , 0 , 1 , 0 } , { 74 , TARGET_STRING (
"attitude3d/transposeQuaternion1/Gain1" ) , TARGET_STRING ( "Gain" ) , 0 , 3
, 0 } , { 75 , TARGET_STRING ( "attitude3d/transposeQuaternion2/Gain1" ) ,
TARGET_STRING ( "Gain" ) , 0 , 3 , 0 } , { 76 , TARGET_STRING (
"attitude3d/Orbital Period Termination Condition/Compare To Zero/Constant" )
, TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 77 , TARGET_STRING (
"attitude3d/Quaternion Propagator/qDot/Constant" ) , TARGET_STRING ( "Value"
) , 0 , 1 , 0 } , { 78 , TARGET_STRING (
"attitude3d/Quaternion Propagator/qDot/Gain" ) , TARGET_STRING ( "Gain" ) , 0
, 1 , 0 } , { 79 , TARGET_STRING (
"attitude3d/Star Sensor 1 Minimum Solar Exclusion/Normalize Vector/Constant"
) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 80 , TARGET_STRING (
"attitude3d/Star Sensor 1 Minimum Solar Exclusion/Normalize Vector1/Constant"
) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 81 , TARGET_STRING (
"attitude3d/Star Sensor 2 Minimum Solar Exclusion/Normalize Vector/Constant"
) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 82 , TARGET_STRING (
"attitude3d/Star Sensor 2 Minimum Solar Exclusion/Normalize Vector1/Constant"
) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 83 , TARGET_STRING (
"attitude3d/Subsystem/Normalize Vector/Constant" ) , TARGET_STRING ( "Value"
) , 0 , 1 , 0 } , { 84 , TARGET_STRING (
"attitude3d/Subsystem/Normalize Vector1/Constant" ) , TARGET_STRING ( "Value"
) , 0 , 1 , 0 } , { 85 , TARGET_STRING (
"attitude3d/Subsystem/Windowed Integrator3/Discrete FIR Filter" ) ,
TARGET_STRING ( "InitialStates" ) , 0 , 1 , 0 } , { 86 , TARGET_STRING (
"attitude3d/Subsystem/Windowed Integrator3/Discrete FIR Filter" ) ,
TARGET_STRING ( "Coefficients" ) , 0 , 4 , 0 } , { 87 , TARGET_STRING (
"attitude3d/Subsystem1/Normalize Vector/Constant" ) , TARGET_STRING ( "Value"
) , 0 , 1 , 0 } , { 88 , TARGET_STRING (
"attitude3d/Subsystem1/Normalize Vector1/Constant" ) , TARGET_STRING (
"Value" ) , 0 , 1 , 0 } , { 89 , TARGET_STRING (
"attitude3d/Subsystem1/Windowed Integrator3/Discrete FIR Filter" ) ,
TARGET_STRING ( "InitialStates" ) , 0 , 1 , 0 } , { 90 , TARGET_STRING (
"attitude3d/Subsystem1/Windowed Integrator3/Discrete FIR Filter" ) ,
TARGET_STRING ( "Coefficients" ) , 0 , 4 , 0 } , { 91 , TARGET_STRING (
"attitude3d/Subsystem2/frame change5/Constant" ) , TARGET_STRING ( "Value" )
, 0 , 1 , 0 } , { 92 , TARGET_STRING (
"attitude3d/Subsystem2/frame change6/Constant" ) , TARGET_STRING ( "Value" )
, 0 , 1 , 0 } , { 93 , TARGET_STRING (
"attitude3d/Subsystem2/frame change7/Constant" ) , TARGET_STRING ( "Value" )
, 0 , 1 , 0 } , { 94 , TARGET_STRING (
"attitude3d/Subsystem2/frame change8/Constant" ) , TARGET_STRING ( "Value" )
, 0 , 1 , 0 } , { 95 , TARGET_STRING (
"attitude3d/Subsystem2/frame change9/Constant" ) , TARGET_STRING ( "Value" )
, 0 , 1 , 0 } , { 96 , TARGET_STRING (
"attitude3d/Thrust Pointing Efficiency/Compare To Zero/Constant" ) ,
TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 97 , TARGET_STRING (
"attitude3d/Thrust Pointing Efficiency/Normalize Vector/Constant" ) ,
TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 98 , TARGET_STRING (
"attitude3d/Thrust Pointing Efficiency/Normalize Vector1/Constant" ) ,
TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 99 , TARGET_STRING (
"attitude3d/Total Pointing Efficiency (Comms)/Compare To Zero/Constant" ) ,
TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 100 , TARGET_STRING (
"attitude3d/Total Pointing Efficiency (Comms)/Normalize Vector/Constant" ) ,
TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 101 , TARGET_STRING (
"attitude3d/Total Pointing Efficiency (Comms)/Normalize Vector1/Constant" ) ,
TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 102 , TARGET_STRING (
"attitude3d/Total Pointing Efficiency (Solar)/Compare To Zero/Constant" ) ,
TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 103 , TARGET_STRING (
"attitude3d/Total Pointing Efficiency (Solar)/Normalize Vector/Constant" ) ,
TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 104 , TARGET_STRING (
"attitude3d/Total Pointing Efficiency (Solar)/Normalize Vector1/Constant" ) ,
TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 105 , TARGET_STRING (
"attitude3d/Subsystem2/frame change5/transposeQuaternion/Gain1" ) ,
TARGET_STRING ( "Gain" ) , 0 , 3 , 0 } , { 106 , TARGET_STRING (
"attitude3d/Subsystem2/frame change6/transposeQuaternion/Gain1" ) ,
TARGET_STRING ( "Gain" ) , 0 , 3 , 0 } , { 107 , TARGET_STRING (
"attitude3d/Subsystem2/frame change7/transposeQuaternion/Gain1" ) ,
TARGET_STRING ( "Gain" ) , 0 , 3 , 0 } , { 108 , TARGET_STRING (
"attitude3d/Subsystem2/frame change8/transposeQuaternion/Gain1" ) ,
TARGET_STRING ( "Gain" ) , 0 , 3 , 0 } , { 109 , TARGET_STRING (
"attitude3d/Subsystem2/frame change9/transposeQuaternion/Gain1" ) ,
TARGET_STRING ( "Gain" ) , 0 , 3 , 0 } , { 0 , ( NULL ) , ( NULL ) , 0 , 0 ,
0 } } ; static const rtwCAPI_ModelParameters rtModelParameters [ ] = { { 110
, TARGET_STRING ( "P_E" ) , 4 , 1 , 0 } , { 111 , TARGET_STRING ( "P_F" ) , 6
, 1 , 0 } , { 112 , TARGET_STRING ( "P_X" ) , 7 , 1 , 0 } , { 0 , ( NULL ) ,
0 , 0 , 0 } } ;
#ifndef HOST_CAPI_BUILD
static void * rtDataAddrMap [ ] = { & rtB . ggl2c42ej4 , & rtB . gdkatceig2 ,
& rtB . hcaghgg2d4 , & rtB . id3syu3xda [ 0 ] , & rtB . lbvs2uyceq , & rtB .
ksb54aeynf , & rtB . bv1kuls22a , & rtB . fbz1lrgadk1 . olimizud5z , & rtB .
p2owgzs2iz , & rtB . b13j3pqall , & rtB . adp4h11fxy , & rtB . fbz1lrgadk1o .
olimizud5z , & rtB . kla2ie4xqo , & rtB . juzdrgfwywb . ezrshmdyuk , & rtB .
fvvukgofqm , & rtB . juzdrgfwywbn . ezrshmdyuk , & rtB . aui5mhj44r , & rtB .
objaac1udz , & rtB . n5lv0if3fe , & rtB . jcjpclbjp2 , & rtB . p4mnuhzffc , &
rtB . mgffwko2vy , & rtB . hcfehsmczi , & rtB . haese0mx0t , & rtB .
fmpx14rdcd , & rtB . ocjizknfbp , & rtB . jtzgz1uiwi , & rtB . j3dtcamj3h [ 0
] , & rtB . bqvggehzz5 , & rtB . jwzvety1de [ 0 ] , & rtB . gwuhy1m1pb [ 0 ]
, & rtB . i1cpfgl4ur [ 0 ] , & rtB . dbvg0t1pgh [ 0 ] , & rtB . fx1eniibgn [
0 ] , & rtB . kg4dzhebco [ 0 ] , & rtP . NormalizeVector_maxzero , & rtP .
NormalizeVector1_maxzero , & rtP . Saturation_UpperSat , & rtP .
Saturation_LowerSat , & rtP . NormalizeVector_maxzero_mt13upuc30 , & rtP .
NormalizeVector1_maxzero_it3sz44pnw , & rtP . Saturation_UpperSat_o0tu1knjb5
, & rtP . Saturation_LowerSat_pjt1p3frof , & rtP .
NormalizeVector_maxzero_oczsk3pynm , & rtP .
NormalizeVector1_maxzero_curh4i254k , & rtP . Constant10_Value , & rtP .
Constant11_Value , & rtP . Gain1_Gain_jasbtnac0r , & rtP .
NormalizeVector_maxzero_ektzry0otc , & rtP .
NormalizeVector1_maxzero_esmeewv013 , & rtP . Constant10_Value_pnntlgrkfl , &
rtP . Constant11_Value_fak2wrhghj , & rtP . Gain1_Gain_luip00ayzb , & rtP .
NormalizeVector_maxzero_frofudci2i , & rtP .
NormalizeVector1_maxzero_c1jmgth0uc , & rtP . Constant11_Value_howgtgmefa , &
rtP . Constant9_Value , & rtP . Integrator1_IC_bdymfb0f54 , & rtP .
Integrator2_IC , & rtP . ManualSwitch1_CurrentSetting , & rtP .
NormalizeVector_maxzero_p3wnqley4p , & rtP .
NormalizeVector1_maxzero_d0tqs3zyle , & rtP . Constant_Value_ok5wcdghto , &
rtP . Constant11_Value_hvpxwvfqmk , & rtP . Integrator1_IC_khgln1fz0y , & rtP
. Saturation_UpperSat_ex5fckh1e5 , & rtP . Saturation_LowerSat_nqfyaemvcp , &
rtP . ManualSwitch1_CurrentSetting_kps3rcsvpl , & rtP .
NormalizeVector_maxzero_jv521hznkv , & rtP .
NormalizeVector1_maxzero_gagywgljsc , & rtP . Constant_Value_b54p1uwprt , &
rtP . Integrator1_IC , & rtP . Saturation_UpperSat_laawyukirp , & rtP .
Saturation_LowerSat_pjistqqcmw , & rtP . Gain1_Gain_i0dny2tgg4 [ 0 ] , & rtP
. Gain1_Gain [ 0 ] , & rtP . Constant_Value_kw5w4qkv5v , & rtP .
Constant_Value_bpuwj1x24m , & rtP . Gain_Gain , & rtP .
Constant_Value_p5yqgecpys , & rtP . Constant_Value_pblczk22x1 , & rtP .
Constant_Value_ojxmxt5mmf , & rtP . Constant_Value_pwofnawzxn , & rtP .
Constant_Value_kd4xr3zjvz , & rtP . Constant_Value_gspoitvpf3 , & rtP .
DiscreteFIRFilter_InitialStates , & rtP . DiscreteFIRFilter_Coefficients [ 0
] , & rtP . Constant_Value_bu2n4z0wwl , & rtP . Constant_Value_ovccxkrnjy , &
rtP . DiscreteFIRFilter_InitialStates_igm30wm5ib , & rtP .
DiscreteFIRFilter_Coefficients_n1yfwntl03 [ 0 ] , & rtP .
Constant_Value_o2fro3xhzj , & rtP . Constant_Value_i2bviibqa1 , & rtP .
Constant_Value_mgesvrfwfg , & rtP . Constant_Value_gdyff4hfxx , & rtP .
Constant_Value_fcyoyjujtb , & rtP . Constant_Value , & rtP .
Constant_Value_i2ujud0fea , & rtP . Constant_Value_bfz3r5ve34 , & rtP .
Constant_Value_c4d4ozwwzr , & rtP . Constant_Value_osq1m5ngw5 , & rtP .
Constant_Value_n5p1mlb1zj , & rtP . Constant_Value_bpciai0igk , & rtP .
Constant_Value_kubckzbqj3 , & rtP . Constant_Value_lfkufjj3ic , & rtP .
Gain1_Gain_f3zo2a45h3 [ 0 ] , & rtP . Gain1_Gain_mglm2i5i2e [ 0 ] , & rtP .
Gain1_Gain_nu325gvdxx [ 0 ] , & rtP . Gain1_Gain_m4frltiumm [ 0 ] , & rtP .
Gain1_Gain_fe1rn1jbbk [ 0 ] , & rtP . P_E , & rtP . P_F , & rtP . P_X , } ;
static int32_T * rtVarDimsAddrMap [ ] = { ( NULL ) } ;
#endif
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "double" ,
"real_T" , 0 , 0 , sizeof ( real_T ) , SS_DOUBLE , 0 , 0 , 0 } , { "struct" ,
"ENVIRONMENT" , 14 , 1 , sizeof ( ENVIRONMENT ) , SS_STRUCT , 0 , 0 , 0 } , {
"unsigned char" , "boolean_T" , 0 , 0 , sizeof ( boolean_T ) , SS_BOOLEAN , 0
, 0 , 0 } , { "unsigned char" , "uint8_T" , 0 , 0 , sizeof ( uint8_T ) ,
SS_UINT8 , 0 , 0 , 0 } , { "struct" , "struct_qj1aZXRxDpRc9BsHnZQAtC" , 12 ,
15 , sizeof ( struct_qj1aZXRxDpRc9BsHnZQAtC ) , SS_STRUCT , 0 , 0 , 0 } , {
"short" , "int16_T" , 0 , 0 , sizeof ( int16_T ) , SS_INT16 , 0 , 0 , 0 } , {
"struct" , "struct_nois8vFfP57DutoSgf9HZD" , 9 , 27 , sizeof (
struct_nois8vFfP57DutoSgf9HZD ) , SS_STRUCT , 0 , 0 , 0 } , { "struct" ,
"struct_rawc2dqRCLbbSQv98WCoDC" , 6 , 36 , sizeof (
struct_rawc2dqRCLbbSQv98WCoDC ) , SS_STRUCT , 0 , 0 , 0 } } ;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , { "thrust_vector" , rt_offsetof ( ENVIRONMENT , thrust_vector )
, 0 , 0 , 0 } , { "thrust_weight" , rt_offsetof ( ENVIRONMENT , thrust_weight
) , 0 , 1 , 0 } , { "solar_occulted_integral" , rt_offsetof ( ENVIRONMENT ,
solar_occulted_integral ) , 0 , 1 , 0 } , { "solar_occulted_boolean" ,
rt_offsetof ( ENVIRONMENT , solar_occulted_boolean ) , 0 , 1 , 0 } , {
"solar_vector" , rt_offsetof ( ENVIRONMENT , solar_vector ) , 0 , 0 , 0 } , {
"comms_occulted_integral" , rt_offsetof ( ENVIRONMENT ,
comms_occulted_integral ) , 0 , 1 , 0 } , { "comms_occulted_boolean" ,
rt_offsetof ( ENVIRONMENT , comms_occulted_boolean ) , 0 , 1 , 0 } , {
"comms_vector" , rt_offsetof ( ENVIRONMENT , comms_vector ) , 0 , 0 , 0 } , {
"r_s" , rt_offsetof ( ENVIRONMENT , r_s ) , 0 , 0 , 0 } , { "v_s" ,
rt_offsetof ( ENVIRONMENT , v_s ) , 0 , 0 , 0 } , { "r_c" , rt_offsetof (
ENVIRONMENT , r_c ) , 0 , 0 , 0 } , { "v_c" , rt_offsetof ( ENVIRONMENT , v_c
) , 0 , 0 , 0 } , { "r_t" , rt_offsetof ( ENVIRONMENT , r_t ) , 0 , 0 , 0 } ,
{ "v_t" , rt_offsetof ( ENVIRONMENT , v_t ) , 0 , 0 , 0 } , {
"sun_grav_param" , rt_offsetof ( struct_qj1aZXRxDpRc9BsHnZQAtC ,
sun_grav_param ) , 0 , 5 , 0 } , { "target_grav_param" , rt_offsetof (
struct_qj1aZXRxDpRc9BsHnZQAtC , target_grav_param ) , 0 , 5 , 0 } , {
"target_mean_sma" , rt_offsetof ( struct_qj1aZXRxDpRc9BsHnZQAtC ,
target_mean_sma ) , 0 , 5 , 0 } , { "target_mean_radius" , rt_offsetof (
struct_qj1aZXRxDpRc9BsHnZQAtC , target_mean_radius ) , 0 , 5 , 0 } , {
"satellite_h" , rt_offsetof ( struct_qj1aZXRxDpRc9BsHnZQAtC , satellite_h ) ,
0 , 5 , 0 } , { "satellite_sma" , rt_offsetof ( struct_qj1aZXRxDpRc9BsHnZQAtC
, satellite_sma ) , 0 , 5 , 0 } , { "mean_motion" , rt_offsetof (
struct_qj1aZXRxDpRc9BsHnZQAtC , mean_motion ) , 0 , 5 , 0 } , { "P" ,
rt_offsetof ( struct_qj1aZXRxDpRc9BsHnZQAtC , P ) , 0 , 5 , 0 } , {
"comms_mean_sma" , rt_offsetof ( struct_qj1aZXRxDpRc9BsHnZQAtC ,
comms_mean_sma ) , 0 , 5 , 0 } , { "initial_classical_satellite" ,
rt_offsetof ( struct_qj1aZXRxDpRc9BsHnZQAtC , initial_classical_satellite ) ,
0 , 6 , 0 } , { "initial_classical_target" , rt_offsetof (
struct_qj1aZXRxDpRc9BsHnZQAtC , initial_classical_target ) , 0 , 6 , 0 } , {
"initial_classical_comms" , rt_offsetof ( struct_qj1aZXRxDpRc9BsHnZQAtC ,
initial_classical_comms ) , 0 , 6 , 0 } , { "star_sensor_1_vb" , rt_offsetof
( struct_nois8vFfP57DutoSgf9HZD , star_sensor_1_vb ) , 0 , 7 , 0 } , {
"star_sensor_2_vb" , rt_offsetof ( struct_nois8vFfP57DutoSgf9HZD ,
star_sensor_2_vb ) , 0 , 7 , 0 } , { "thruster_vb" , rt_offsetof (
struct_nois8vFfP57DutoSgf9HZD , thruster_vb ) , 0 , 7 , 0 } , { "antenna_vb"
, rt_offsetof ( struct_nois8vFfP57DutoSgf9HZD , antenna_vb ) , 0 , 7 , 0 } ,
{ "solar_array_vb" , rt_offsetof ( struct_nois8vFfP57DutoSgf9HZD ,
solar_array_vb ) , 0 , 7 , 0 } , { "thrust_shadow_weight" , rt_offsetof (
struct_nois8vFfP57DutoSgf9HZD , thrust_shadow_weight ) , 0 , 5 , 0 } , {
"thrust_no_shadow_weight" , rt_offsetof ( struct_nois8vFfP57DutoSgf9HZD ,
thrust_no_shadow_weight ) , 0 , 5 , 0 } , { "window_t" , rt_offsetof (
struct_nois8vFfP57DutoSgf9HZD , window_t ) , 0 , 5 , 0 } , { "window_n" ,
rt_offsetof ( struct_nois8vFfP57DutoSgf9HZD , window_n ) , 5 , 5 , 0 } , {
"max_omega" , rt_offsetof ( struct_rawc2dqRCLbbSQv98WCoDC , max_omega ) , 0 ,
7 , 0 } , { "init_vel_vec" , rt_offsetof ( struct_rawc2dqRCLbbSQv98WCoDC ,
init_vel_vec ) , 0 , 7 , 0 } , { "init_pos_vec" , rt_offsetof (
struct_rawc2dqRCLbbSQv98WCoDC , init_pos_vec ) , 0 , 7 , 0 } , { "init_xBI" ,
rt_offsetof ( struct_rawc2dqRCLbbSQv98WCoDC , init_xBI ) , 0 , 7 , 0 } , {
"init_yBI" , rt_offsetof ( struct_rawc2dqRCLbbSQv98WCoDC , init_yBI ) , 0 , 7
, 0 } , { "init_zBI" , rt_offsetof ( struct_rawc2dqRCLbbSQv98WCoDC , init_zBI
) , 0 , 7 , 0 } } ; static const rtwCAPI_DimensionMap rtDimensionMap [ ] = {
{ rtwCAPI_VECTOR , 0 , 2 , 0 } , { rtwCAPI_SCALAR , 2 , 2 , 0 } , {
rtwCAPI_VECTOR , 4 , 2 , 0 } , { rtwCAPI_VECTOR , 6 , 2 , 0 } , {
rtwCAPI_VECTOR , 8 , 2 , 0 } , { rtwCAPI_MATRIX_COL_MAJOR , 2 , 2 , 0 } , {
rtwCAPI_MATRIX_COL_MAJOR , 10 , 2 , 0 } , { rtwCAPI_MATRIX_COL_MAJOR , 12 , 2
, 0 } } ; static const uint_T rtDimensionArray [ ] = { 3 , 1 , 1 , 1 , 4 , 1
, 1 , 4 , 1 , 60 , 7 , 1 , 1 , 3 } ; static const real_T rtcapiStoredFloats [
] = { 0.0 , 10.0 } ; static const rtwCAPI_FixPtMap rtFixPtMap [ ] = { { (
NULL ) , ( NULL ) , rtwCAPI_FIX_RESERVED , 0 , 0 , 0 } , } ; static const
rtwCAPI_SampleTimeMap rtSampleTimeMap [ ] = { { ( const void * ) &
rtcapiStoredFloats [ 0 ] , ( const void * ) & rtcapiStoredFloats [ 0 ] , 0 ,
0 } , { ( NULL ) , ( NULL ) , 2 , 0 } , { ( const void * ) &
rtcapiStoredFloats [ 1 ] , ( const void * ) & rtcapiStoredFloats [ 0 ] , 1 ,
0 } } ; static rtwCAPI_ModelMappingStaticInfo mmiStatic = { { rtBlockSignals
, 35 , ( NULL ) , 0 , ( NULL ) , 0 } , { rtBlockParameters , 75 ,
rtModelParameters , 3 } , { ( NULL ) , 0 } , { rtDataTypeMap , rtDimensionMap
, rtFixPtMap , rtElementMap , rtSampleTimeMap , rtDimensionArray } , "float"
, { 3803236602U , 2346542714U , 3261620555U , 2040919633U } , ( NULL ) , 0 ,
0 } ; const rtwCAPI_ModelMappingStaticInfo * attitude3d_GetCAPIStaticMap (
void ) { return & mmiStatic ; }
#ifndef HOST_CAPI_BUILD
void attitude3d_InitializeDataMapInfo ( void ) { rtwCAPI_SetVersion ( ( *
rt_dataMapInfoPtr ) . mmi , 1 ) ; rtwCAPI_SetStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , & mmiStatic ) ; rtwCAPI_SetLoggingStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ; rtwCAPI_SetDataAddressMap ( ( *
rt_dataMapInfoPtr ) . mmi , rtDataAddrMap ) ; rtwCAPI_SetVarDimsAddressMap (
( * rt_dataMapInfoPtr ) . mmi , rtVarDimsAddrMap ) ;
rtwCAPI_SetInstanceLoggingInfo ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArray ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( ( * rt_dataMapInfoPtr ) . mmi , 0 ) ; }
#else
#ifdef __cplusplus
extern "C" {
#endif
void attitude3d_host_InitializeDataMapInfo ( attitude3d_host_DataMapInfo_T *
dataMap , const char * path ) { rtwCAPI_SetVersion ( dataMap -> mmi , 1 ) ;
rtwCAPI_SetStaticMap ( dataMap -> mmi , & mmiStatic ) ;
rtwCAPI_SetDataAddressMap ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetVarDimsAddressMap ( dataMap -> mmi , NULL ) ; rtwCAPI_SetPath (
dataMap -> mmi , path ) ; rtwCAPI_SetFullPath ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetChildMMIArray ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( dataMap -> mmi , 0 ) ; }
#ifdef __cplusplus
}
#endif
#endif
