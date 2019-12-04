#include "__cf_rs_bicycle.h"
#ifndef RTW_HEADER_rs_bicycle_h_
#define RTW_HEADER_rs_bicycle_h_
#include <stddef.h>
#include <string.h>
#include "rtw_modelmap.h"
#ifndef rs_bicycle_COMMON_INCLUDES_
#define rs_bicycle_COMMON_INCLUDES_
#include <stdlib.h>
#include "rtwtypes.h"
#include "simtarget/slSimTgtSigstreamRTW.h"
#include "simtarget/slSimTgtSlioCoreRTW.h"
#include "simtarget/slSimTgtSlioClientsRTW.h"
#include "simtarget/slSimTgtSlioSdiRTW.h"
#include "sigstream_rtw.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "raccel.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "rt_logging.h"
#include "dt_info.h"
#include "ext_work.h"
#endif
#include "rs_bicycle_types.h"
#include "multiword_types.h"
#include "mwmathutil.h"
#include "rt_defines.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#define MODEL_NAME rs_bicycle
#define NSAMPLE_TIMES (3) 
#define NINPUTS (1)       
#define NOUTPUTS (13)     
#define NBLOCKIO (75) 
#define NUM_ZC_EVENTS (0) 
#ifndef NCSTATES
#define NCSTATES (4)   
#elif NCSTATES != 4
#error Invalid specification of NCSTATES defined in compiler command
#endif
#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm) (*rt_dataMapInfoPtr)
#endif
#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val) (rt_dataMapInfoPtr = &val)
#endif
#ifndef IN_RACCEL_MAIN
#endif
typedef struct { real_T ipdergl1q3 ; } me0inc24h2 ; typedef struct {
fkh3de5uws aviewp3bz1 ; fkh3de5uws ita2zzwqtk ; bckkwnlnai bu2jbgsv15 ;
boolean_T pumqcfxdvo ; } dzvjycueyh ; typedef struct { real_T kkii1l5vii ;
real_T pwf3pin41a ; real_T nmalw2wdvv ; real_T phpmeo4o31 ; real_T arnwhbdsjr
; real_T letet25bjg [ 2 ] ; real_T cuq4s4xyta [ 2 ] ; real_T fkudo4yvzg ;
real_T lfuqpkbv4w [ 2 ] ; real_T gjgjxuamsb [ 2 ] ; real_T owlwvra5lv ;
real_T koludsbdn4 ; real_T nd3novo4e2 ; real_T crugzyhjzg ; real_T pnpnetosep
; real_T kky4swrkln ; real_T pwzgbqhmlu ; real_T nfix4prp31 ; real_T
mjipwiwsab ; real_T mg4tkrdzya ; real_T dny1ckhqrw ; real_T gwzzjj2332 ;
real_T agcm0t1jl3 ; real_T bmrbqdn4ib ; real_T mgtwfogikl ; real_T na1xsgoign
; real_T kliqr4bqad ; real_T lqzb33ramg ; real_T j2ranx3eff ; real_T
eb5o55xhxk ; real_T lmtgic4fhp [ 2 ] ; real_T mg4fdmac5p [ 2 ] ; real_T
lhn2pokn3p [ 2 ] ; real_T bba5tmuhaa ; real_T nvdetxb5tx ; real_T ddyto5b4zd
; real_T gddvi424wr ; real_T k3z3m3ldej ; real_T ipe2ymqves ; real_T
pusu00yrcw [ 2 ] ; real_T e5n35j2niw ; real_T lb31uoepla ; real_T dxa2fe4h5d
[ 2 ] ; real_T cfti4gkgoy [ 2 ] ; real_T nmxegffgia [ 2 ] ; real_T eph0u45qky
; real_T nngc4xyghd ; real_T fvmipg4lrj ; real_T ouatgm5wlm [ 2 ] ; real_T
itak35c1xz ; real_T omdnrdnywn [ 2 ] ; real_T erbk25hexb [ 2 ] ; real_T
gjhcrpjjk2 ; real_T g14mvqcdge ; real_T pviusfxiyr ; real_T e3mvbvmzx4 ;
real_T ic2bkjstr3 ; boolean_T di5jcafytx [ 2 ] ; boolean_T odelljfi5g [ 2 ] ;
boolean_T lmdphncnhd [ 2 ] ; boolean_T lavjegxa0s ; boolean_T k5yjkklppp ;
boolean_T gqyvdicpar ; boolean_T n30pv2m1ci ; boolean_T mssb2m5uof ;
boolean_T ei3l4cdp3l ; boolean_T jkqihkxsof ; boolean_T pn4bqsppqd [ 2 ] ;
boolean_T lwwvvar4jx ; boolean_T nivlobgrcv ; boolean_T gllg0oiz3l ;
me0inc24h2 cq1wd4pu5m ; me0inc24h2 it0b4crh0a ; me0inc24h2 jfaynsbq1z ;
me0inc24h2 c351hegycsd ; } B ; typedef struct { kuzoipzra0 gqwdiipwrj ;
kuzoipzra0 bcimcwmolr ; kztkp1snwz azlvoaxn1v ; kztkp1snwz gdlg4sgpor ;
kes444tmjv ifjz2d2ffr ; ht3benkjob o5o3u4ixzs ; real_T odnmi54ao0 ; struct {
void * LoggedData [ 6 ] ; } g3n5clq5yl ; struct { void * LoggedData [ 10 ] ;
} nennjmvryo ; struct { void * LoggedData [ 7 ] ; } a1vj5lhw2w ; struct {
void * LoggedData [ 3 ] ; } gsgtf5x3u2 ; int_T eufiybe1pc ; boolean_T
pchqaf4hz2 ; boolean_T l4xuf0ayh1 ; dzvjycueyh cq1wd4pu5m ; dzvjycueyh
it0b4crh0a ; dzvjycueyh jfaynsbq1z ; dzvjycueyh c351hegycsd ; } DW ; typedef
struct { real_T fdwigv02gz ; real_T jr2pi52g5m ; real_T mbyulbirys ; real_T
damgdgtbrg ; } X ; typedef struct { real_T fdwigv02gz ; real_T jr2pi52g5m ;
real_T mbyulbirys ; real_T damgdgtbrg ; } XDot ; typedef struct { boolean_T
fdwigv02gz ; boolean_T jr2pi52g5m ; boolean_T mbyulbirys ; boolean_T
damgdgtbrg ; } XDis ; typedef struct { real_T bpe1ezavi1 ; } ExtU ; typedef
struct { real_T i2gyzd3b1a [ 10 ] ; real_T efcbr5m0pz [ 3 ] ; } ExtY ;
typedef struct { rtwCAPI_ModelMappingInfo mmi ; } DataMapInfo ; struct P_ {
real_T duration ; real_T env_forest [ 2 ] ; real_T env_mu_s_dry ; real_T
env_mu_s_wet ; real_T env_route_length ; real_T env_t_rain_start ; real_T
env_traffic_durations [ 2 ] ; real_T env_traffic_pos [ 2 ] ; real_T
env_traffic_times [ 2 ] ; real_T g ; real_T init_position ; real_T
Difference_ICPrevInput ; real_T Integrator_IC ; real_T Switch_Threshold ;
real_T Switch2_Threshold ; real_T Switch_Threshold_hglhrydy3y ; real_T
Gain_Gain ; real_T Integrator1_IC ; real_T Integrator2_IC ; real_T
Switch1_Threshold ; real_T no_Value ; real_T yes_Value ; real_T
Constant_Value ; real_T no1_Value ; real_T Constant_Value_ehkhiuseje ; real_T
Constant_Value_oxokqz1erg ; real_T no_Value_eq3lkpaxhu ; real_T
reaction_time_Value ; real_T Constant_Value_kyz3xktxbl ; real_T
Constant1_Value ; real_T Constant2_Value ; real_T Constant3_Value ; real_T
Constant4_Value ; real_T Constant_Value_jqzxbewhqx ; } ; extern const char *
RT_MEMORY_ALLOCATION_ERROR ; extern B rtB ; extern X rtX ; extern DW rtDW ;
extern ExtU rtU ; extern ExtY rtY ; extern P rtP ; extern const
rtwCAPI_ModelMappingStaticInfo * rs_bicycle_GetCAPIStaticMap ( void ) ;
extern SimStruct * const rtS ; extern const int_T gblNumToFiles ; extern
const int_T gblNumFrFiles ; extern const int_T gblNumFrWksBlocks ; extern
rtInportTUtable * gblInportTUtables ; extern const char * gblInportFileName ;
extern const int_T gblNumRootInportBlks ; extern const int_T
gblNumModelInputs ; extern const int_T gblInportDataTypeIdx [ ] ; extern
const int_T gblInportDims [ ] ; extern const int_T gblInportComplex [ ] ;
extern const int_T gblInportInterpoFlag [ ] ; extern const int_T
gblInportContinuous [ ] ; extern const int_T gblParameterTuningTid ; extern
DataMapInfo * rt_dataMapInfoPtr ; extern rtwCAPI_ModelMappingInfo *
rt_modelMapInfoPtr ; void MdlOutputs ( int_T tid ) ; void
MdlOutputsParameterSampleTime ( int_T tid ) ; void MdlUpdate ( int_T tid ) ;
void MdlTerminate ( void ) ; void MdlInitializeSizes ( void ) ; void
MdlInitializeSampleTimes ( void ) ; SimStruct * raccel_register_model ( void
) ;
#endif
