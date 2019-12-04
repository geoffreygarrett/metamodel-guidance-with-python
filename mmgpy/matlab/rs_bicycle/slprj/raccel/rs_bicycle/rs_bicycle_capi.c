#include "__cf_rs_bicycle.h"
#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "rs_bicycle_capi_host.h"
#define sizeof(s) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)    
#else
#include "builtin_typeid_types.h"
#include "rs_bicycle.h"
#include "rs_bicycle_capi.h"
#include "rs_bicycle_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST                  
#define TARGET_STRING(s)               (NULL)                    
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static const rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 0 , TARGET_STRING (
"rs_bicycle/Clock1" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 1 , 0
, TARGET_STRING ( "rs_bicycle/Clock2" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 ,
0 , 0 } , { 2 , 0 , TARGET_STRING ( "rs_bicycle/Clock3" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 0 } , { 3 , 0 , TARGET_STRING ( "rs_bicycle/Clock4" )
, TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 4 , 0 , TARGET_STRING (
"rs_bicycle/Clock5" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 5 , 0
, TARGET_STRING ( "rs_bicycle/Constant1" ) , TARGET_STRING (
"env_traffic_durations" ) , 0 , 0 , 1 , 0 , 1 } , { 6 , 0 , TARGET_STRING (
"rs_bicycle/Constant10" ) , TARGET_STRING ( "env_mu_s_wet" ) , 0 , 0 , 0 , 0
, 1 } , { 7 , 0 , TARGET_STRING ( "rs_bicycle/Constant4" ) , TARGET_STRING (
"env_route_length" ) , 0 , 0 , 0 , 0 , 1 } , { 8 , 0 , TARGET_STRING (
"rs_bicycle/Constant5" ) , TARGET_STRING ( "env_traffic_pos" ) , 0 , 0 , 1 ,
0 , 1 } , { 9 , 0 , TARGET_STRING ( "rs_bicycle/Constant6" ) , TARGET_STRING
( "env_traffic_times" ) , 0 , 0 , 1 , 0 , 1 } , { 10 , 0 , TARGET_STRING (
"rs_bicycle/Constant7" ) , TARGET_STRING ( "env_forest" ) , 0 , 0 , 1 , 0 , 1
} , { 11 , 0 , TARGET_STRING ( "rs_bicycle/Constant8" ) , TARGET_STRING (
"env_t_rain_start" ) , 0 , 0 , 0 , 0 , 1 } , { 12 , 0 , TARGET_STRING (
"rs_bicycle/Constant9" ) , TARGET_STRING ( "env_mu_s_dry" ) , 0 , 0 , 0 , 0 ,
1 } , { 13 , 0 , TARGET_STRING ( "rs_bicycle/Duration" ) , TARGET_STRING (
"duration" ) , 0 , 0 , 0 , 0 , 1 } , { 14 , 0 , TARGET_STRING (
"rs_bicycle/Initial Position" ) , TARGET_STRING ( "init_position" ) , 0 , 0 ,
0 , 0 , 1 } , { 15 , 0 , TARGET_STRING ( "rs_bicycle/Integrator" ) ,
TARGET_STRING ( "pos" ) , 0 , 0 , 0 , 0 , 0 } , { 16 , 0 , TARGET_STRING (
"rs_bicycle/Integrator1" ) , TARGET_STRING ( "f6_av_int" ) , 0 , 0 , 0 , 0 ,
0 } , { 17 , 0 , TARGET_STRING ( "rs_bicycle/Integrator2" ) , TARGET_STRING (
"f10_v3_int" ) , 0 , 0 , 0 , 0 , 0 } , { 18 , 4 , TARGET_STRING (
"rs_bicycle/Moving Maximum" ) , TARGET_STRING ( "f4_stop_dist" ) , 0 , 0 , 0
, 0 , 0 } , { 19 , 2 , TARGET_STRING ( "rs_bicycle/Moving Maximum1" ) ,
TARGET_STRING ( "f7_slip_max" ) , 0 , 0 , 0 , 0 , 0 } , { 20 , 3 ,
TARGET_STRING ( "rs_bicycle/Moving Maximum2" ) , TARGET_STRING ( "f5_av_max"
) , 0 , 0 , 0 , 0 , 0 } , { 21 , 1 , TARGET_STRING (
"rs_bicycle/Moving Maximum3" ) , TARGET_STRING ( "f9_v3_max" ) , 0 , 0 , 0 ,
0 , 0 } , { 22 , 5 , TARGET_STRING ( "rs_bicycle/Moving Minimum1" ) ,
TARGET_STRING ( "f3_traffic_dist" ) , 0 , 0 , 0 , 0 , 0 } , { 23 , 0 ,
TARGET_STRING ( "rs_bicycle/Current Static Friction/Sum" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 0 } , { 24 , 0 , TARGET_STRING (
"rs_bicycle/Current Static Friction/Switch" ) , TARGET_STRING (
"static_friction" ) , 0 , 0 , 0 , 0 , 0 } , { 25 , 0 , TARGET_STRING (
"rs_bicycle/Difference/Diff" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } ,
{ 26 , 0 , TARGET_STRING ( "rs_bicycle/Difference/UD" ) , TARGET_STRING (
"U(k-1)" ) , 0 , 0 , 0 , 0 , 2 } , { 27 , 0 , TARGET_STRING (
"rs_bicycle/Forest Boundaries/Product" ) , TARGET_STRING ( "" ) , 0 , 0 , 1 ,
0 , 1 } , { 28 , 0 , TARGET_STRING ( "rs_bicycle/Raining Boolean/Sum1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 29 , 0 , TARGET_STRING (
"rs_bicycle/Raining Boolean/Switch1" ) , TARGET_STRING ( "raining" ) , 0 , 0
, 0 , 0 , 0 } , { 30 , 0 , TARGET_STRING (
"rs_bicycle/Time From Traffic Encounter/Relational Operator" ) ,
TARGET_STRING ( "" ) , 0 , 1 , 1 , 0 , 0 } , { 31 , 0 , TARGET_STRING (
"rs_bicycle/Time From Traffic Encounter/Sum1" ) , TARGET_STRING ( "" ) , 0 ,
0 , 1 , 0 , 0 } , { 32 , 0 , TARGET_STRING (
"rs_bicycle/Time From Traffic Encounter/Sum2" ) , TARGET_STRING ( "" ) , 0 ,
0 , 1 , 0 , 0 } , { 33 , 0 , TARGET_STRING (
"rs_bicycle/Time From Traffic Encounter/Switch1" ) , TARGET_STRING ( "" ) , 0
, 0 , 1 , 0 , 0 } , { 34 , 0 , TARGET_STRING (
"rs_bicycle/Time Until Raining/Sum1" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0
, 0 } , { 35 , 0 , TARGET_STRING ( "rs_bicycle/Traffic Location(s)/Product" )
, TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 1 } , { 36 , 0 , TARGET_STRING (
"rs_bicycle/Traffic Passing/Logical Operator" ) , TARGET_STRING ( "" ) , 0 ,
1 , 1 , 0 , 0 } , { 37 , 0 , TARGET_STRING (
"rs_bicycle/Traffic Passing/Relational Operator" ) , TARGET_STRING ( "" ) , 0
, 1 , 1 , 0 , 0 } , { 38 , 0 , TARGET_STRING (
"rs_bicycle/Traffic Passing/Relational Operator1" ) , TARGET_STRING ( "" ) ,
0 , 1 , 1 , 0 , 0 } , { 39 , 0 , TARGET_STRING (
"rs_bicycle/Traffic Passing/Sum1" ) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 ,
1 } , { 40 , 0 , TARGET_STRING ( "rs_bicycle/Traffic Passing/Switch1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 41 , 0 , TARGET_STRING (
"rs_bicycle/aux1: Fraction of Route Distance/Divide" ) , TARGET_STRING (
"frac_dist" ) , 0 , 0 , 0 , 0 , 0 } , { 42 , 6 , TARGET_STRING (
"rs_bicycle/aux1: Fraction of Route Distance/Moving Maximum" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 43 , 0 , TARGET_STRING (
"rs_bicycle/aux2: Fraction Spent In Forest/Clock7" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 0 } , { 44 , 0 , TARGET_STRING (
"rs_bicycle/aux2: Fraction Spent In Forest/Integrator" ) , TARGET_STRING ( ""
) , 0 , 0 , 0 , 0 , 0 } , { 45 , 7 , TARGET_STRING (
"rs_bicycle/aux2: Fraction Spent In Forest/Divide" ) , TARGET_STRING (
"frac_forest" ) , 0 , 0 , 0 , 0 , 0 } , { 46 , 0 , TARGET_STRING (
"rs_bicycle/aux2: Fraction Spent In Forest/Switch" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 0 } , { 47 , 8 , TARGET_STRING (
"rs_bicycle/aux3: Closest Instantaenous Traffic/Minimum Between Signals " ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 48 , 0 , TARGET_STRING (
"rs_bicycle/aux3: Closest Instantaenous Traffic/Abs" ) , TARGET_STRING ( "" )
, 0 , 0 , 1 , 0 , 0 } , { 49 , 0 , TARGET_STRING (
"rs_bicycle/aux3: Closest Instantaenous Traffic/Sum" ) , TARGET_STRING ( "" )
, 0 , 0 , 1 , 0 , 0 } , { 50 , 0 , TARGET_STRING (
"rs_bicycle/aux3: Closest Instantaenous Traffic/Switch2" ) , TARGET_STRING (
"" ) , 0 , 0 , 1 , 0 , 0 } , { 51 , 0 , TARGET_STRING (
"rs_bicycle/aux4: Instantaneous Stopping Distance/Gain" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 0 } , { 52 , 0 , TARGET_STRING (
"rs_bicycle/aux4: Instantaneous Stopping Distance/Square" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 0 } , { 53 , 0 , TARGET_STRING (
"rs_bicycle/aux4: Instantaneous Stopping Distance/Divide" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 0 } , { 54 , 0 , TARGET_STRING (
"rs_bicycle/aux4: Instantaneous Stopping Distance/Product" ) , TARGET_STRING
( "" ) , 0 , 0 , 0 , 0 , 0 } , { 55 , 0 , TARGET_STRING (
"rs_bicycle/aux4: Instantaneous Stopping Distance/Product1" ) , TARGET_STRING
( "" ) , 0 , 0 , 0 , 0 , 0 } , { 56 , 0 , TARGET_STRING (
"rs_bicycle/aux4: Instantaneous Stopping Distance/Sum" ) , TARGET_STRING (
"stopping_dist" ) , 0 , 0 , 0 , 0 , 0 } , { 57 , 0 , TARGET_STRING (
"rs_bicycle/aux5: Cyclist Power Density Transfer/Logical Operator" ) ,
TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 0 } , { 58 , 0 , TARGET_STRING (
"rs_bicycle/aux5: Cyclist Power Density Transfer/Logical Operator1" ) ,
TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 0 } , { 59 , 0 , TARGET_STRING (
"rs_bicycle/aux5: Cyclist Power Density Transfer/Logical Operator2" ) ,
TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 0 } , { 60 , 9 , TARGET_STRING (
"rs_bicycle/aux5: Cyclist Power Density Transfer/Product1" ) , TARGET_STRING
( "cyclist_power_density" ) , 0 , 0 , 0 , 0 , 0 } , { 61 , 0 , TARGET_STRING
( "rs_bicycle/aux5: Cyclist Power Density Transfer/Relational Operator" ) ,
TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 2 } , { 62 , 0 , TARGET_STRING (
"rs_bicycle/aux5: Cyclist Power Density Transfer/Relational Operator1" ) ,
TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 0 } , { 63 , 0 , TARGET_STRING (
"rs_bicycle/aux5: Cyclist Power Density Transfer/Relational Operator2" ) ,
TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 2 } , { 64 , 0 , TARGET_STRING (
"rs_bicycle/aux5: Cyclist Power Density Transfer/Relational Operator3" ) ,
TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 0 } , { 65 , 0 , TARGET_STRING (
"rs_bicycle/aux5: Cyclist Power Density Transfer/Switch" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 0 } , { 66 , 0 , TARGET_STRING (
"rs_bicycle/aux6: Exceedance of Static Friction (slipping)/Abs" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 67 , 0 , TARGET_STRING (
"rs_bicycle/aux6: Exceedance of Static Friction (slipping)/Divide" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 68 , 0 , TARGET_STRING (
"rs_bicycle/aux6: Exceedance of Static Friction (slipping)/Sum" ) ,
TARGET_STRING ( "slipping" ) , 0 , 0 , 0 , 0 , 0 } , { 69 , 0 , TARGET_STRING
( "rs_bicycle/aux8: Drag Power Compensation (V^3)/Abs" ) , TARGET_STRING ( ""
) , 0 , 0 , 0 , 0 , 0 } , { 70 , 0 , TARGET_STRING (
"rs_bicycle/aux8: Drag Power Compensation (V^3)/Exp" ) , TARGET_STRING ( "" )
, 0 , 0 , 0 , 0 , 0 } , { 71 , 0 , TARGET_STRING (
"rs_bicycle/aux2: Fraction Spent In Forest/In Forest Boolearn/Logical Operator"
) , TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 0 } , { 72 , 0 , TARGET_STRING (
 "rs_bicycle/aux2: Fraction Spent In Forest/In Forest Boolearn/Relational Operator"
) , TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 0 } , { 73 , 0 , TARGET_STRING (
 "rs_bicycle/aux2: Fraction Spent In Forest/In Forest Boolearn/Relational Operator1"
) , TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 0 } , { 74 , 0 , TARGET_STRING (
"rs_bicycle/aux2: Fraction Spent In Forest/In Forest Boolearn/Switch" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 0 , 0 , ( NULL ) , ( NULL ) ,
0 , 0 , 0 , 0 , 0 } } ; static const rtwCAPI_BlockParameters
rtBlockParameters [ ] = { { 75 , TARGET_STRING ( "rs_bicycle/Difference" ) ,
TARGET_STRING ( "ICPrevInput" ) , 0 , 0 , 0 } , { 76 , TARGET_STRING (
"rs_bicycle/Integrator1" ) , TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0
} , { 77 , TARGET_STRING ( "rs_bicycle/Integrator2" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 0 , 0 } , { 78 , TARGET_STRING (
"rs_bicycle/Current Static Friction/Switch" ) , TARGET_STRING ( "Threshold" )
, 0 , 0 , 0 } , { 79 , TARGET_STRING ( "rs_bicycle/Raining Boolean/no" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 80 , TARGET_STRING (
"rs_bicycle/Raining Boolean/yes" ) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 }
, { 81 , TARGET_STRING ( "rs_bicycle/Raining Boolean/Switch1" ) ,
TARGET_STRING ( "Threshold" ) , 0 , 0 , 0 } , { 82 , TARGET_STRING (
"rs_bicycle/Traffic Passing/Constant" ) , TARGET_STRING ( "Value" ) , 0 , 0 ,
0 } , { 83 , TARGET_STRING ( "rs_bicycle/Traffic Passing/no1" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 84 , TARGET_STRING (
"rs_bicycle/aux2: Fraction Spent In Forest/Constant" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 85 , TARGET_STRING (
"rs_bicycle/aux2: Fraction Spent In Forest/Integrator" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 0 , 0 } , { 86 , TARGET_STRING (
"rs_bicycle/aux2: Fraction Spent In Forest/Switch" ) , TARGET_STRING (
"Threshold" ) , 0 , 0 , 0 } , { 87 , TARGET_STRING (
"rs_bicycle/aux3: Closest Instantaenous Traffic/Switch2" ) , TARGET_STRING (
"Threshold" ) , 0 , 0 , 0 } , { 88 , TARGET_STRING (
"rs_bicycle/aux4: Instantaneous Stopping Distance/reaction_time" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 89 , TARGET_STRING (
"rs_bicycle/aux4: Instantaneous Stopping Distance/Gain" ) , TARGET_STRING (
"Gain" ) , 0 , 0 , 0 } , { 90 , TARGET_STRING (
"rs_bicycle/aux5: Cyclist Power Density Transfer/Constant" ) , TARGET_STRING
( "Value" ) , 0 , 0 , 0 } , { 91 , TARGET_STRING (
"rs_bicycle/aux5: Cyclist Power Density Transfer/Constant1" ) , TARGET_STRING
( "Value" ) , 0 , 0 , 0 } , { 92 , TARGET_STRING (
"rs_bicycle/aux5: Cyclist Power Density Transfer/Constant2" ) , TARGET_STRING
( "Value" ) , 0 , 0 , 0 } , { 93 , TARGET_STRING (
"rs_bicycle/aux5: Cyclist Power Density Transfer/Constant3" ) , TARGET_STRING
( "Value" ) , 0 , 0 , 0 } , { 94 , TARGET_STRING (
"rs_bicycle/aux5: Cyclist Power Density Transfer/Constant4" ) , TARGET_STRING
( "Value" ) , 0 , 0 , 0 } , { 95 , TARGET_STRING (
"rs_bicycle/aux8: Drag Power Compensation (V^3)/Constant" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 96 , TARGET_STRING (
"rs_bicycle/aux2: Fraction Spent In Forest/In Forest Boolearn/Constant" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 97 , TARGET_STRING (
"rs_bicycle/aux2: Fraction Spent In Forest/In Forest Boolearn/no" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 0 , ( NULL ) , ( NULL ) , 0 , 0 ,
0 } } ; static const rtwCAPI_ModelParameters rtModelParameters [ ] = { { 98 ,
TARGET_STRING ( "duration" ) , 0 , 0 , 0 } , { 99 , TARGET_STRING (
"env_forest" ) , 0 , 2 , 0 } , { 100 , TARGET_STRING ( "env_mu_s_dry" ) , 0 ,
0 , 0 } , { 101 , TARGET_STRING ( "env_mu_s_wet" ) , 0 , 0 , 0 } , { 102 ,
TARGET_STRING ( "env_route_length" ) , 0 , 0 , 0 } , { 103 , TARGET_STRING (
"env_t_rain_start" ) , 0 , 0 , 0 } , { 104 , TARGET_STRING (
"env_traffic_durations" ) , 0 , 1 , 0 } , { 105 , TARGET_STRING (
"env_traffic_pos" ) , 0 , 1 , 0 } , { 106 , TARGET_STRING (
"env_traffic_times" ) , 0 , 1 , 0 } , { 107 , TARGET_STRING ( "g" ) , 0 , 0 ,
0 } , { 108 , TARGET_STRING ( "init_position" ) , 0 , 0 , 0 } , { 0 , ( NULL
) , 0 , 0 , 0 } } ;
#ifndef HOST_CAPI_BUILD
static void * rtDataAddrMap [ ] = { & rtB . fkudo4yvzg , & rtB . eb5o55xhxk ,
& rtB . bba5tmuhaa , & rtB . ddyto5b4zd , & rtB . nd3novo4e2 , & rtB .
pusu00yrcw [ 0 ] , & rtB . e5n35j2niw , & rtB . lb31uoepla , & rtB .
dxa2fe4h5d [ 0 ] , & rtB . cfti4gkgoy [ 0 ] , & rtB . nmxegffgia [ 0 ] , &
rtB . eph0u45qky , & rtB . nngc4xyghd , & rtB . fvmipg4lrj , & rtB .
itak35c1xz , & rtB . kkii1l5vii , & rtB . agcm0t1jl3 , & rtB . j2ranx3eff , &
rtB . cq1wd4pu5m . ipdergl1q3 , & rtB . jfaynsbq1z . ipdergl1q3 , & rtB .
it0b4crh0a . ipdergl1q3 , & rtB . c351hegycsd . ipdergl1q3 , & rtB .
ic2bkjstr3 , & rtB . crugzyhjzg , & rtB . pnpnetosep , & rtB . dny1ckhqrw , &
rtB . mg4tkrdzya , & rtB . ouatgm5wlm [ 0 ] , & rtB . gddvi424wr , & rtB .
k3z3m3ldej , & rtB . pn4bqsppqd [ 0 ] , & rtB . mg4fdmac5p [ 0 ] , & rtB .
lmtgic4fhp [ 0 ] , & rtB . lhn2pokn3p [ 0 ] , & rtB . nvdetxb5tx , & rtB .
omdnrdnywn [ 0 ] , & rtB . lmdphncnhd [ 0 ] , & rtB . di5jcafytx [ 0 ] , &
rtB . odelljfi5g [ 0 ] , & rtB . erbk25hexb [ 0 ] , & rtB . lfuqpkbv4w [ 0 ]
, & rtB . pwf3pin41a , & rtB . e3mvbvmzx4 , & rtB . phpmeo4o31 , & rtB .
nmalw2wdvv , & rtB . pviusfxiyr , & rtB . arnwhbdsjr , & rtB . g14mvqcdge , &
rtB . cuq4s4xyta [ 0 ] , & rtB . letet25bjg [ 0 ] , & rtB . gjgjxuamsb [ 0 ]
, & rtB . pwzgbqhmlu , & rtB . koludsbdn4 , & rtB . nfix4prp31 , & rtB .
owlwvra5lv , & rtB . kky4swrkln , & rtB . mjipwiwsab , & rtB . gqyvdicpar , &
rtB . ei3l4cdp3l , & rtB . jkqihkxsof , & rtB . gjhcrpjjk2 , & rtB .
lavjegxa0s , & rtB . k5yjkklppp , & rtB . n30pv2m1ci , & rtB . mssb2m5uof , &
rtB . gwzzjj2332 , & rtB . mgtwfogikl , & rtB . bmrbqdn4ib , & rtB .
na1xsgoign , & rtB . lqzb33ramg , & rtB . kliqr4bqad , & rtB . gllg0oiz3l , &
rtB . lwwvvar4jx , & rtB . nivlobgrcv , & rtB . ipe2ymqves , & rtP .
Difference_ICPrevInput , & rtP . Integrator1_IC , & rtP . Integrator2_IC , &
rtP . Switch_Threshold_hglhrydy3y , & rtP . no_Value , & rtP . yes_Value , &
rtP . Switch1_Threshold , & rtP . Constant_Value , & rtP . no1_Value , & rtP
. Constant_Value_ehkhiuseje , & rtP . Integrator_IC , & rtP .
Switch_Threshold , & rtP . Switch2_Threshold , & rtP . reaction_time_Value ,
& rtP . Gain_Gain , & rtP . Constant_Value_kyz3xktxbl , & rtP .
Constant1_Value , & rtP . Constant2_Value , & rtP . Constant3_Value , & rtP .
Constant4_Value , & rtP . Constant_Value_jqzxbewhqx , & rtP .
Constant_Value_oxokqz1erg , & rtP . no_Value_eq3lkpaxhu , & rtP . duration ,
& rtP . env_forest [ 0 ] , & rtP . env_mu_s_dry , & rtP . env_mu_s_wet , &
rtP . env_route_length , & rtP . env_t_rain_start , & rtP .
env_traffic_durations [ 0 ] , & rtP . env_traffic_pos [ 0 ] , & rtP .
env_traffic_times [ 0 ] , & rtP . g , & rtP . init_position , } ; static
int32_T * rtVarDimsAddrMap [ ] = { ( NULL ) } ;
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
rtwCAPI_VECTOR , 4 , 2 , 0 } } ; static const uint_T rtDimensionArray [ ] = {
1 , 1 , 2 , 1 , 1 , 2 } ; static const real_T rtcapiStoredFloats [ ] = { 0.0
, 4.0 } ; static const rtwCAPI_FixPtMap rtFixPtMap [ ] = { { ( NULL ) , (
NULL ) , rtwCAPI_FIX_RESERVED , 0 , 0 , 0 } , } ; static const
rtwCAPI_SampleTimeMap rtSampleTimeMap [ ] = { { ( const void * ) &
rtcapiStoredFloats [ 0 ] , ( const void * ) & rtcapiStoredFloats [ 0 ] , 0 ,
0 } , { ( NULL ) , ( NULL ) , 2 , 0 } , { ( const void * ) &
rtcapiStoredFloats [ 1 ] , ( const void * ) & rtcapiStoredFloats [ 0 ] , 1 ,
0 } } ; static rtwCAPI_ModelMappingStaticInfo mmiStatic = { { rtBlockSignals
, 75 , ( NULL ) , 0 , ( NULL ) , 0 } , { rtBlockParameters , 23 ,
rtModelParameters , 11 } , { ( NULL ) , 0 } , { rtDataTypeMap ,
rtDimensionMap , rtFixPtMap , rtElementMap , rtSampleTimeMap ,
rtDimensionArray } , "float" , { 551039131U , 168430918U , 238321069U ,
1733840132U } , ( NULL ) , 0 , 0 } ; const rtwCAPI_ModelMappingStaticInfo *
rs_bicycle_GetCAPIStaticMap ( void ) { return & mmiStatic ; }
#ifndef HOST_CAPI_BUILD
void rs_bicycle_InitializeDataMapInfo ( void ) { rtwCAPI_SetVersion ( ( *
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
void rs_bicycle_host_InitializeDataMapInfo ( rs_bicycle_host_DataMapInfo_T *
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
