#include "__cf_rs_bicycle2.h"
#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "rs_bicycle2_capi_host.h"
#define sizeof(s) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)    
#else
#include "builtin_typeid_types.h"
#include "rs_bicycle2.h"
#include "rs_bicycle2_capi.h"
#include "rs_bicycle2_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST                  
#define TARGET_STRING(s)               (NULL)                    
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static const rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 6 , TARGET_STRING (
"rs_bicycle2/MATLAB Function" ) , TARGET_STRING ( "vel" ) , 0 , 0 , 0 , 0 , 0
} , { 1 , 0 , TARGET_STRING ( "rs_bicycle2/Clock" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 0 } , { 2 , 0 , TARGET_STRING ( "rs_bicycle2/Clock1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 3 , 0 , TARGET_STRING (
"rs_bicycle2/Clock2" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 4 , 0
, TARGET_STRING ( "rs_bicycle2/Clock3" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 ,
0 , 0 } , { 5 , 0 , TARGET_STRING ( "rs_bicycle2/Clock4" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 0 } , { 6 , 0 , TARGET_STRING ( "rs_bicycle2/Clock5" )
, TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 7 , 0 , TARGET_STRING (
"rs_bicycle2/Constant1" ) , TARGET_STRING ( "env_traffic_durations" ) , 0 , 0
, 1 , 0 , 1 } , { 8 , 0 , TARGET_STRING ( "rs_bicycle2/Constant10" ) ,
TARGET_STRING ( "env_mu_s_wet" ) , 0 , 0 , 0 , 0 , 1 } , { 9 , 0 ,
TARGET_STRING ( "rs_bicycle2/Constant4" ) , TARGET_STRING (
"env_route_length" ) , 0 , 0 , 0 , 0 , 1 } , { 10 , 0 , TARGET_STRING (
"rs_bicycle2/Constant5" ) , TARGET_STRING ( "env_traffic_pos" ) , 0 , 0 , 1 ,
0 , 1 } , { 11 , 0 , TARGET_STRING ( "rs_bicycle2/Constant6" ) ,
TARGET_STRING ( "env_traffic_times" ) , 0 , 0 , 1 , 0 , 1 } , { 12 , 0 ,
TARGET_STRING ( "rs_bicycle2/Constant7" ) , TARGET_STRING ( "env_forest" ) ,
0 , 0 , 1 , 0 , 1 } , { 13 , 0 , TARGET_STRING ( "rs_bicycle2/Constant8" ) ,
TARGET_STRING ( "env_t_rain_start" ) , 0 , 0 , 0 , 0 , 1 } , { 14 , 0 ,
TARGET_STRING ( "rs_bicycle2/Constant9" ) , TARGET_STRING ( "env_mu_s_dry" )
, 0 , 0 , 0 , 0 , 1 } , { 15 , 0 , TARGET_STRING ( "rs_bicycle2/Duration" ) ,
TARGET_STRING ( "duration" ) , 0 , 0 , 0 , 0 , 1 } , { 16 , 0 , TARGET_STRING
( "rs_bicycle2/Initial Position" ) , TARGET_STRING ( "init_position" ) , 0 ,
0 , 0 , 0 , 1 } , { 17 , 0 , TARGET_STRING ( "rs_bicycle2/Integrator" ) ,
TARGET_STRING ( "pos" ) , 0 , 0 , 0 , 0 , 0 } , { 18 , 0 , TARGET_STRING (
"rs_bicycle2/Integrator1" ) , TARGET_STRING ( "f6_av_int" ) , 0 , 0 , 0 , 0 ,
0 } , { 19 , 0 , TARGET_STRING ( "rs_bicycle2/Integrator2" ) , TARGET_STRING
( "f10_v3_int" ) , 0 , 0 , 0 , 0 , 0 } , { 20 , 4 , TARGET_STRING (
"rs_bicycle2/Moving Maximum" ) , TARGET_STRING ( "f4_stop_dist" ) , 0 , 0 , 0
, 0 , 0 } , { 21 , 2 , TARGET_STRING ( "rs_bicycle2/Moving Maximum1" ) ,
TARGET_STRING ( "f7_slip_max" ) , 0 , 0 , 0 , 0 , 0 } , { 22 , 3 ,
TARGET_STRING ( "rs_bicycle2/Moving Maximum2" ) , TARGET_STRING ( "f5_av_max"
) , 0 , 0 , 0 , 0 , 0 } , { 23 , 1 , TARGET_STRING (
"rs_bicycle2/Moving Maximum3" ) , TARGET_STRING ( "f9_v3_max" ) , 0 , 0 , 0 ,
0 , 0 } , { 24 , 5 , TARGET_STRING ( "rs_bicycle2/Moving Minimum1" ) ,
TARGET_STRING ( "f3_traffic_dist" ) , 0 , 0 , 0 , 0 , 0 } , { 25 , 0 ,
TARGET_STRING ( "rs_bicycle2/Current Static Friction/Sum" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 0 } , { 26 , 0 , TARGET_STRING (
"rs_bicycle2/Current Static Friction/Switch" ) , TARGET_STRING (
"static_friction" ) , 0 , 0 , 0 , 0 , 0 } , { 27 , 0 , TARGET_STRING (
"rs_bicycle2/Difference/Diff" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 }
, { 28 , 0 , TARGET_STRING ( "rs_bicycle2/Difference/UD" ) , TARGET_STRING (
"U(k-1)" ) , 0 , 0 , 0 , 0 , 2 } , { 29 , 0 , TARGET_STRING (
"rs_bicycle2/Forest Boundaries/Product" ) , TARGET_STRING ( "" ) , 0 , 0 , 1
, 0 , 1 } , { 30 , 0 , TARGET_STRING ( "rs_bicycle2/Raining Boolean/Sum1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 31 , 0 , TARGET_STRING (
"rs_bicycle2/Raining Boolean/Switch1" ) , TARGET_STRING ( "raining" ) , 0 , 0
, 0 , 0 , 0 } , { 32 , 0 , TARGET_STRING (
"rs_bicycle2/Time From Traffic Encounter/Relational Operator" ) ,
TARGET_STRING ( "" ) , 0 , 1 , 1 , 0 , 0 } , { 33 , 0 , TARGET_STRING (
"rs_bicycle2/Time From Traffic Encounter/Sum1" ) , TARGET_STRING ( "" ) , 0 ,
0 , 1 , 0 , 0 } , { 34 , 0 , TARGET_STRING (
"rs_bicycle2/Time From Traffic Encounter/Sum2" ) , TARGET_STRING ( "" ) , 0 ,
0 , 1 , 0 , 0 } , { 35 , 0 , TARGET_STRING (
"rs_bicycle2/Time From Traffic Encounter/Switch1" ) , TARGET_STRING ( "" ) ,
0 , 0 , 1 , 0 , 0 } , { 36 , 0 , TARGET_STRING (
"rs_bicycle2/Time Until Raining/Sum1" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 ,
0 , 0 } , { 37 , 0 , TARGET_STRING (
"rs_bicycle2/Traffic Location(s)/Product" ) , TARGET_STRING ( "" ) , 0 , 0 ,
1 , 0 , 1 } , { 38 , 0 , TARGET_STRING (
"rs_bicycle2/Traffic Passing/Logical Operator" ) , TARGET_STRING ( "" ) , 0 ,
1 , 1 , 0 , 0 } , { 39 , 0 , TARGET_STRING (
"rs_bicycle2/Traffic Passing/Relational Operator" ) , TARGET_STRING ( "" ) ,
0 , 1 , 1 , 0 , 0 } , { 40 , 0 , TARGET_STRING (
"rs_bicycle2/Traffic Passing/Relational Operator1" ) , TARGET_STRING ( "" ) ,
0 , 1 , 1 , 0 , 0 } , { 41 , 0 , TARGET_STRING (
"rs_bicycle2/Traffic Passing/Sum1" ) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 ,
1 } , { 42 , 0 , TARGET_STRING ( "rs_bicycle2/Traffic Passing/Switch1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 43 , 0 , TARGET_STRING (
"rs_bicycle2/aux1: Fraction of Route Distance/Divide" ) , TARGET_STRING (
"frac_dist" ) , 0 , 0 , 0 , 0 , 0 } , { 44 , 7 , TARGET_STRING (
"rs_bicycle2/aux1: Fraction of Route Distance/Moving Maximum" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 45 , 0 , TARGET_STRING (
"rs_bicycle2/aux2: Fraction Spent In Forest/Clock7" ) , TARGET_STRING ( "" )
, 0 , 0 , 0 , 0 , 0 } , { 46 , 0 , TARGET_STRING (
"rs_bicycle2/aux2: Fraction Spent In Forest/Integrator" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 0 } , { 47 , 8 , TARGET_STRING (
"rs_bicycle2/aux2: Fraction Spent In Forest/Divide" ) , TARGET_STRING (
"frac_forest" ) , 0 , 0 , 0 , 0 , 0 } , { 48 , 0 , TARGET_STRING (
"rs_bicycle2/aux2: Fraction Spent In Forest/Switch" ) , TARGET_STRING ( "" )
, 0 , 0 , 0 , 0 , 0 } , { 49 , 9 , TARGET_STRING (
"rs_bicycle2/aux3: Closest Instantaenous Traffic/Minimum Between Signals " )
, TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 50 , 0 , TARGET_STRING (
"rs_bicycle2/aux3: Closest Instantaenous Traffic/Abs" ) , TARGET_STRING ( ""
) , 0 , 0 , 1 , 0 , 0 } , { 51 , 0 , TARGET_STRING (
"rs_bicycle2/aux3: Closest Instantaenous Traffic/Sum" ) , TARGET_STRING ( ""
) , 0 , 0 , 1 , 0 , 0 } , { 52 , 0 , TARGET_STRING (
"rs_bicycle2/aux3: Closest Instantaenous Traffic/Switch2" ) , TARGET_STRING (
"" ) , 0 , 0 , 1 , 0 , 0 } , { 53 , 0 , TARGET_STRING (
"rs_bicycle2/aux4: Instantaneous Stopping Distance/Gain" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 0 } , { 54 , 0 , TARGET_STRING (
"rs_bicycle2/aux4: Instantaneous Stopping Distance/Square" ) , TARGET_STRING
( "" ) , 0 , 0 , 0 , 0 , 0 } , { 55 , 0 , TARGET_STRING (
"rs_bicycle2/aux4: Instantaneous Stopping Distance/Divide" ) , TARGET_STRING
( "" ) , 0 , 0 , 0 , 0 , 0 } , { 56 , 0 , TARGET_STRING (
"rs_bicycle2/aux4: Instantaneous Stopping Distance/Product" ) , TARGET_STRING
( "" ) , 0 , 0 , 0 , 0 , 0 } , { 57 , 0 , TARGET_STRING (
"rs_bicycle2/aux4: Instantaneous Stopping Distance/Product1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 58 , 0 , TARGET_STRING (
"rs_bicycle2/aux4: Instantaneous Stopping Distance/Sum" ) , TARGET_STRING (
"stopping_dist" ) , 0 , 0 , 0 , 0 , 0 } , { 59 , 0 , TARGET_STRING (
"rs_bicycle2/aux5: Cyclist Power Density Transfer/Logical Operator" ) ,
TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 0 } , { 60 , 0 , TARGET_STRING (
"rs_bicycle2/aux5: Cyclist Power Density Transfer/Logical Operator1" ) ,
TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 0 } , { 61 , 0 , TARGET_STRING (
"rs_bicycle2/aux5: Cyclist Power Density Transfer/Logical Operator2" ) ,
TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 0 } , { 62 , 10 , TARGET_STRING (
"rs_bicycle2/aux5: Cyclist Power Density Transfer/Product1" ) , TARGET_STRING
( "cyclist_power_density" ) , 0 , 0 , 0 , 0 , 0 } , { 63 , 0 , TARGET_STRING
( "rs_bicycle2/aux5: Cyclist Power Density Transfer/Relational Operator" ) ,
TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 2 } , { 64 , 0 , TARGET_STRING (
"rs_bicycle2/aux5: Cyclist Power Density Transfer/Relational Operator1" ) ,
TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 0 } , { 65 , 0 , TARGET_STRING (
"rs_bicycle2/aux5: Cyclist Power Density Transfer/Relational Operator2" ) ,
TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 2 } , { 66 , 0 , TARGET_STRING (
"rs_bicycle2/aux5: Cyclist Power Density Transfer/Relational Operator3" ) ,
TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 0 } , { 67 , 0 , TARGET_STRING (
"rs_bicycle2/aux5: Cyclist Power Density Transfer/Switch" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 0 } , { 68 , 0 , TARGET_STRING (
"rs_bicycle2/aux6: Exceedance of Static Friction (slipping)/Abs" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 69 , 0 , TARGET_STRING (
"rs_bicycle2/aux6: Exceedance of Static Friction (slipping)/Divide" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 70 , 0 , TARGET_STRING (
"rs_bicycle2/aux6: Exceedance of Static Friction (slipping)/Sum" ) ,
TARGET_STRING ( "slipping" ) , 0 , 0 , 0 , 0 , 0 } , { 71 , 0 , TARGET_STRING
( "rs_bicycle2/aux8: Drag Power Compensation (V^3)/Abs" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 0 } , { 72 , 0 , TARGET_STRING (
"rs_bicycle2/aux8: Drag Power Compensation (V^3)/Exp" ) , TARGET_STRING ( ""
) , 0 , 0 , 0 , 0 , 0 } , { 73 , 0 , TARGET_STRING (
"rs_bicycle2/aux2: Fraction Spent In Forest/In Forest Boolearn/Logical Operator"
) , TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 0 } , { 74 , 0 , TARGET_STRING (
 "rs_bicycle2/aux2: Fraction Spent In Forest/In Forest Boolearn/Relational Operator"
) , TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 0 } , { 75 , 0 , TARGET_STRING (
 "rs_bicycle2/aux2: Fraction Spent In Forest/In Forest Boolearn/Relational Operator1"
) , TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 0 } , { 76 , 0 , TARGET_STRING (
"rs_bicycle2/aux2: Fraction Spent In Forest/In Forest Boolearn/Switch" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 0 , 0 , ( NULL ) , ( NULL ) ,
0 , 0 , 0 , 0 , 0 } } ; static const rtwCAPI_BlockParameters
rtBlockParameters [ ] = { { 77 , TARGET_STRING ( "rs_bicycle2/Difference" ) ,
TARGET_STRING ( "ICPrevInput" ) , 0 , 0 , 0 } , { 78 , TARGET_STRING (
"rs_bicycle2/Integrator1" ) , TARGET_STRING ( "InitialCondition" ) , 0 , 0 ,
0 } , { 79 , TARGET_STRING ( "rs_bicycle2/Integrator2" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 0 , 0 } , { 80 , TARGET_STRING (
"rs_bicycle2/Current Static Friction/Switch" ) , TARGET_STRING ( "Threshold"
) , 0 , 0 , 0 } , { 81 , TARGET_STRING ( "rs_bicycle2/Raining Boolean/no" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 82 , TARGET_STRING (
"rs_bicycle2/Raining Boolean/yes" ) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 }
, { 83 , TARGET_STRING ( "rs_bicycle2/Raining Boolean/Switch1" ) ,
TARGET_STRING ( "Threshold" ) , 0 , 0 , 0 } , { 84 , TARGET_STRING (
"rs_bicycle2/Traffic Passing/Constant" ) , TARGET_STRING ( "Value" ) , 0 , 0
, 0 } , { 85 , TARGET_STRING ( "rs_bicycle2/Traffic Passing/no1" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 86 , TARGET_STRING (
"rs_bicycle2/aux2: Fraction Spent In Forest/Constant" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 87 , TARGET_STRING (
"rs_bicycle2/aux2: Fraction Spent In Forest/Integrator" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 0 , 0 } , { 88 , TARGET_STRING (
"rs_bicycle2/aux2: Fraction Spent In Forest/Switch" ) , TARGET_STRING (
"Threshold" ) , 0 , 0 , 0 } , { 89 , TARGET_STRING (
"rs_bicycle2/aux3: Closest Instantaenous Traffic/Switch2" ) , TARGET_STRING (
"Threshold" ) , 0 , 0 , 0 } , { 90 , TARGET_STRING (
"rs_bicycle2/aux4: Instantaneous Stopping Distance/reaction_time" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 91 , TARGET_STRING (
"rs_bicycle2/aux4: Instantaneous Stopping Distance/Gain" ) , TARGET_STRING (
"Gain" ) , 0 , 0 , 0 } , { 92 , TARGET_STRING (
"rs_bicycle2/aux5: Cyclist Power Density Transfer/Constant" ) , TARGET_STRING
( "Value" ) , 0 , 0 , 0 } , { 93 , TARGET_STRING (
"rs_bicycle2/aux5: Cyclist Power Density Transfer/Constant1" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 94 , TARGET_STRING (
"rs_bicycle2/aux5: Cyclist Power Density Transfer/Constant2" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 95 , TARGET_STRING (
"rs_bicycle2/aux5: Cyclist Power Density Transfer/Constant3" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 96 , TARGET_STRING (
"rs_bicycle2/aux5: Cyclist Power Density Transfer/Constant4" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 97 , TARGET_STRING (
"rs_bicycle2/aux8: Drag Power Compensation (V^3)/Constant" ) , TARGET_STRING
( "Value" ) , 0 , 0 , 0 } , { 98 , TARGET_STRING (
"rs_bicycle2/aux2: Fraction Spent In Forest/In Forest Boolearn/Constant" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 99 , TARGET_STRING (
"rs_bicycle2/aux2: Fraction Spent In Forest/In Forest Boolearn/no" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 0 , ( NULL ) , ( NULL ) , 0 , 0 ,
0 } } ; static const rtwCAPI_ModelParameters rtModelParameters [ ] = { { 100
, TARGET_STRING ( "duration" ) , 0 , 0 , 0 } , { 101 , TARGET_STRING (
"env_forest" ) , 0 , 2 , 0 } , { 102 , TARGET_STRING ( "env_mu_s_dry" ) , 0 ,
0 , 0 } , { 103 , TARGET_STRING ( "env_mu_s_wet" ) , 0 , 0 , 0 } , { 104 ,
TARGET_STRING ( "env_route_length" ) , 0 , 0 , 0 } , { 105 , TARGET_STRING (
"env_t_rain_start" ) , 0 , 0 , 0 } , { 106 , TARGET_STRING (
"env_traffic_durations" ) , 0 , 1 , 0 } , { 107 , TARGET_STRING (
"env_traffic_pos" ) , 0 , 1 , 0 } , { 108 , TARGET_STRING (
"env_traffic_times" ) , 0 , 1 , 0 } , { 109 , TARGET_STRING ( "g" ) , 0 , 0 ,
0 } , { 110 , TARGET_STRING ( "init_position" ) , 0 , 0 , 0 } , { 111 ,
TARGET_STRING ( "vel" ) , 0 , 3 , 0 } , { 0 , ( NULL ) , 0 , 0 , 0 } } ;
#ifndef HOST_CAPI_BUILD
static void * rtDataAddrMap [ ] = { & rtB . m2q0pua4hf , & rtB . jyapjnygey ,
& rtB . ft1lwiplkf , & rtB . ojsxt052dx , & rtB . jbd0xdvrsq , & rtB .
dage4kxeup , & rtB . prpccjcehp , & rtB . biki50erxe [ 0 ] , & rtB .
odv2qhzlqg , & rtB . f4spskjtp4 , & rtB . c5fwmfh314 [ 0 ] , & rtB .
jmn33aahhq [ 0 ] , & rtB . czhyu2bg0k [ 0 ] , & rtB . o2zt0cwv3s , & rtB .
craf4qjftk , & rtB . ifpg5v2co4 , & rtB . jtpferclbe , & rtB . kcyp21kc2a , &
rtB . f5lt2gautr , & rtB . hlq1tatw2c , & rtB . pzjd3kuy5m . gm53zhdnh5 , &
rtB . fpf3fqle5c . gm53zhdnh5 , & rtB . jdbr35ed4p . gm53zhdnh5 , & rtB .
nrszotctkrz . gm53zhdnh5 , & rtB . edohkr2wul , & rtB . oj4ir132kn , & rtB .
dhkufhyeyq , & rtB . nge5jnvtgx , & rtB . bk43fv2n4y , & rtB . hqjcuxu5y0 [ 0
] , & rtB . na4hrtuuyw , & rtB . d1jelb2eui , & rtB . comw5ylrlx [ 0 ] , &
rtB . j5mv5pspvc [ 0 ] , & rtB . hydn0gjndu [ 0 ] , & rtB . egn3zic0pm [ 0 ]
, & rtB . j4s3bqbxd4 , & rtB . dm0n54sbqj [ 0 ] , & rtB . ntvdgb201d [ 0 ] ,
& rtB . dhdvnfqewh [ 0 ] , & rtB . erbdt202km [ 0 ] , & rtB . l3gkhpvljt [ 0
] , & rtB . nuq4ebgzji [ 0 ] , & rtB . dj31gbg42s , & rtB . iazliuf4fr , &
rtB . jgw3cnihqn , & rtB . pr5iwe4db4 , & rtB . jpfgqre33f , & rtB .
bvtrmm42qq , & rtB . brmok2vfn0 , & rtB . klvou0jp43 [ 0 ] , & rtB .
a0vhvlfvrp [ 0 ] , & rtB . foohqlhzxj [ 0 ] , & rtB . dvlei2dmhh , & rtB .
cwg0hry4ws , & rtB . e5a31ttfny , & rtB . hbw1yihztg , & rtB . eodzgtkr5j , &
rtB . olssxob2yv , & rtB . jwq1epnjmp , & rtB . fisvgzk5zv , & rtB .
nlloggg0bk , & rtB . ixl2ngyssb , & rtB . o2croyjuf1 , & rtB . ntwseknv4g , &
rtB . hxqshrzbjb , & rtB . erl53vzxd3 , & rtB . irfhmm4oof , & rtB .
lz2vzowa3c , & rtB . ixalepcbyn , & rtB . h3xadqth0r , & rtB . lvxqtzvles , &
rtB . a5ewqn2mxx , & rtB . jhgjsl1qel , & rtB . ece5hhfx4x , & rtB .
dpka2uzame , & rtB . ovxbrcsfmz , & rtP . Difference_ICPrevInput , & rtP .
Integrator1_IC , & rtP . Integrator2_IC , & rtP . Switch_Threshold_hglhrydy3y
, & rtP . no_Value , & rtP . yes_Value , & rtP . Switch1_Threshold , & rtP .
Constant_Value , & rtP . no1_Value , & rtP . Constant_Value_ehkhiuseje , &
rtP . Integrator_IC , & rtP . Switch_Threshold , & rtP . Switch2_Threshold ,
& rtP . reaction_time_Value , & rtP . Gain_Gain , & rtP .
Constant_Value_kyz3xktxbl , & rtP . Constant1_Value , & rtP . Constant2_Value
, & rtP . Constant3_Value , & rtP . Constant4_Value , & rtP .
Constant_Value_jqzxbewhqx , & rtP . Constant_Value_oxokqz1erg , & rtP .
no_Value_eq3lkpaxhu , & rtP . duration , & rtP . env_forest [ 0 ] , & rtP .
env_mu_s_dry , & rtP . env_mu_s_wet , & rtP . env_route_length , & rtP .
env_t_rain_start , & rtP . env_traffic_durations [ 0 ] , & rtP .
env_traffic_pos [ 0 ] , & rtP . env_traffic_times [ 0 ] , & rtP . g , & rtP .
init_position , & rtP . vel [ 0 ] , } ; static int32_T * rtVarDimsAddrMap [ ]
= { ( NULL ) } ;
#endif
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "double" ,
"real_T" , 0 , 0 , sizeof ( real_T ) , SS_DOUBLE , 0 , 0 , 0 } , {
"unsigned char" , "boolean_T" , 0 , 0 , sizeof ( boolean_T ) , SS_BOOLEAN , 0
, 0 , 0 } } ;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , } ; static const rtwCAPI_DimensionMap rtDimensionMap [ ] = { {
rtwCAPI_SCALAR , 0 , 2 , 0 } , { rtwCAPI_VECTOR , 2 , 2 , 0 } , {
rtwCAPI_VECTOR , 4 , 2 , 0 } , { rtwCAPI_MATRIX_COL_MAJOR , 6 , 2 , 0 } } ;
static const uint_T rtDimensionArray [ ] = { 1 , 1 , 2 , 1 , 1 , 2 , 4 , 2 }
; static const real_T rtcapiStoredFloats [ ] = { 0.0 , 4.0 } ; static const
rtwCAPI_FixPtMap rtFixPtMap [ ] = { { ( NULL ) , ( NULL ) ,
rtwCAPI_FIX_RESERVED , 0 , 0 , 0 } , } ; static const rtwCAPI_SampleTimeMap
rtSampleTimeMap [ ] = { { ( const void * ) & rtcapiStoredFloats [ 0 ] , (
const void * ) & rtcapiStoredFloats [ 0 ] , 0 , 0 } , { ( NULL ) , ( NULL ) ,
2 , 0 } , { ( const void * ) & rtcapiStoredFloats [ 1 ] , ( const void * ) &
rtcapiStoredFloats [ 0 ] , 1 , 0 } } ; static rtwCAPI_ModelMappingStaticInfo
mmiStatic = { { rtBlockSignals , 77 , ( NULL ) , 0 , ( NULL ) , 0 } , {
rtBlockParameters , 23 , rtModelParameters , 12 } , { ( NULL ) , 0 } , {
rtDataTypeMap , rtDimensionMap , rtFixPtMap , rtElementMap , rtSampleTimeMap
, rtDimensionArray } , "float" , { 2815083295U , 69055812U , 3976536213U ,
588105720U } , ( NULL ) , 0 , 0 } ; const rtwCAPI_ModelMappingStaticInfo *
rs_bicycle2_GetCAPIStaticMap ( void ) { return & mmiStatic ; }
#ifndef HOST_CAPI_BUILD
void rs_bicycle2_InitializeDataMapInfo ( void ) { rtwCAPI_SetVersion ( ( *
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
void rs_bicycle2_host_InitializeDataMapInfo ( rs_bicycle2_host_DataMapInfo_T
* dataMap , const char * path ) { rtwCAPI_SetVersion ( dataMap -> mmi , 1 ) ;
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
