#include "__cf_rs_bicycle2.h"
#ifndef RTW_HEADER_rs_bicycle2_h_
#define RTW_HEADER_rs_bicycle2_h_
#include <stddef.h>
#include <string.h>
#include "rtw_modelmap.h"
#ifndef rs_bicycle2_COMMON_INCLUDES_
#define rs_bicycle2_COMMON_INCLUDES_
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
#include "rs_bicycle2_types.h"
#include "multiword_types.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include "rt_defines.h"
#include "rtGetInf.h"
#define MODEL_NAME rs_bicycle2
#define NSAMPLE_TIMES (3) 
#define NINPUTS (0)       
#define NOUTPUTS (13)     
#define NBLOCKIO (77) 
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
typedef struct { real_T gm53zhdnh5 ; } l3csy1qexn ; typedef struct {
a14pojzgfk ohlmpp21yt ; a14pojzgfk iq234qewu4 ; hq0hb5wdla bgtbyci3g4 ;
boolean_T oo5zsud5tm ; } oehzpt04yr ; typedef struct { real_T kcyp21kc2a ;
real_T dj31gbg42s ; real_T pr5iwe4db4 ; real_T jgw3cnihqn ; real_T bvtrmm42qq
; real_T a0vhvlfvrp [ 2 ] ; real_T klvou0jp43 [ 2 ] ; real_T ft1lwiplkf ;
real_T nuq4ebgzji [ 2 ] ; real_T foohqlhzxj [ 2 ] ; real_T jyapjnygey ;
real_T hbw1yihztg ; real_T cwg0hry4ws ; real_T prpccjcehp ; real_T oj4ir132kn
; real_T dhkufhyeyq ; real_T eodzgtkr5j ; real_T dvlei2dmhh ; real_T
e5a31ttfny ; real_T olssxob2yv ; real_T bk43fv2n4y ; real_T nge5jnvtgx ;
real_T irfhmm4oof ; real_T f5lt2gautr ; real_T ixalepcbyn ; real_T lz2vzowa3c
; real_T h3xadqth0r ; real_T a5ewqn2mxx ; real_T lvxqtzvles ; real_T
hlq1tatw2c ; real_T ojsxt052dx ; real_T hydn0gjndu [ 2 ] ; real_T j5mv5pspvc
[ 2 ] ; real_T egn3zic0pm [ 2 ] ; real_T jbd0xdvrsq ; real_T j4s3bqbxd4 ;
real_T dage4kxeup ; real_T na4hrtuuyw ; real_T d1jelb2eui ; real_T ovxbrcsfmz
; real_T biki50erxe [ 2 ] ; real_T odv2qhzlqg ; real_T f4spskjtp4 ; real_T
c5fwmfh314 [ 2 ] ; real_T jmn33aahhq [ 2 ] ; real_T czhyu2bg0k [ 2 ] ; real_T
o2zt0cwv3s ; real_T craf4qjftk ; real_T ifpg5v2co4 ; real_T hqjcuxu5y0 [ 2 ]
; real_T jtpferclbe ; real_T dm0n54sbqj [ 2 ] ; real_T l3gkhpvljt [ 2 ] ;
real_T ixl2ngyssb ; real_T brmok2vfn0 ; real_T jpfgqre33f ; real_T iazliuf4fr
; real_T m2q0pua4hf ; real_T edohkr2wul ; boolean_T dhdvnfqewh [ 2 ] ;
boolean_T erbdt202km [ 2 ] ; boolean_T ntvdgb201d [ 2 ] ; boolean_T
o2croyjuf1 ; boolean_T ntwseknv4g ; boolean_T jwq1epnjmp ; boolean_T
hxqshrzbjb ; boolean_T erl53vzxd3 ; boolean_T fisvgzk5zv ; boolean_T
nlloggg0bk ; boolean_T comw5ylrlx [ 2 ] ; boolean_T ece5hhfx4x ; boolean_T
dpka2uzame ; boolean_T jhgjsl1qel ; l3csy1qexn pzjd3kuy5m ; l3csy1qexn
jdbr35ed4p ; l3csy1qexn fpf3fqle5c ; l3csy1qexn nrszotctkrz ; } B ; typedef
struct { eae4ors1vz anxd5wnwwf ; eae4ors1vz jzedrgivtk ; nznsmjv5o1
l4wnyi14fe ; nznsmjv5o1 dukunxirwj ; bea3vlgt1r pjhwxlxh5o ; izdonajra3
dhfsjbleur ; real_T o0ozn4wrlb ; struct { void * LoggedData [ 6 ] ; }
axozqa2z0x ; struct { void * LoggedData [ 10 ] ; } p4ifn0i4ms ; struct { void
* LoggedData [ 7 ] ; } l3axxfz1gt ; struct { void * LoggedData [ 3 ] ; }
dwr4oeemew ; int_T bptbpmlejv ; boolean_T gvs4eonwop ; boolean_T h53kbocvrf ;
oehzpt04yr pzjd3kuy5m ; oehzpt04yr jdbr35ed4p ; oehzpt04yr fpf3fqle5c ;
oehzpt04yr nrszotctkrz ; } DW ; typedef struct { real_T kkiibctlhi ; real_T
lfbgx15nj4 ; real_T alyxv0p4jq ; real_T k3tsvpgpqo ; } X ; typedef struct {
real_T kkiibctlhi ; real_T lfbgx15nj4 ; real_T alyxv0p4jq ; real_T k3tsvpgpqo
; } XDot ; typedef struct { boolean_T kkiibctlhi ; boolean_T lfbgx15nj4 ;
boolean_T alyxv0p4jq ; boolean_T k3tsvpgpqo ; } XDis ; typedef struct {
real_T c5nklccwze [ 10 ] ; real_T jdublxckra [ 3 ] ; } ExtY ; typedef struct
{ rtwCAPI_ModelMappingInfo mmi ; } DataMapInfo ; struct P_ { real_T duration
; real_T env_forest [ 2 ] ; real_T env_mu_s_dry ; real_T env_mu_s_wet ;
real_T env_route_length ; real_T env_t_rain_start ; real_T
env_traffic_durations [ 2 ] ; real_T env_traffic_pos [ 2 ] ; real_T
env_traffic_times [ 2 ] ; real_T g ; real_T init_position ; real_T vel [ 8 ]
; real_T Difference_ICPrevInput ; real_T Integrator_IC ; real_T
Switch_Threshold ; real_T Switch2_Threshold ; real_T
Switch_Threshold_hglhrydy3y ; real_T Gain_Gain ; real_T Integrator1_IC ;
real_T Integrator2_IC ; real_T Switch1_Threshold ; real_T no_Value ; real_T
yes_Value ; real_T Constant_Value ; real_T no1_Value ; real_T
Constant_Value_ehkhiuseje ; real_T Constant_Value_oxokqz1erg ; real_T
no_Value_eq3lkpaxhu ; real_T reaction_time_Value ; real_T
Constant_Value_kyz3xktxbl ; real_T Constant1_Value ; real_T Constant2_Value ;
real_T Constant3_Value ; real_T Constant4_Value ; real_T
Constant_Value_jqzxbewhqx ; } ; extern const char *
RT_MEMORY_ALLOCATION_ERROR ; extern B rtB ; extern X rtX ; extern DW rtDW ;
extern ExtY rtY ; extern P rtP ; extern const rtwCAPI_ModelMappingStaticInfo
* rs_bicycle2_GetCAPIStaticMap ( void ) ; extern SimStruct * const rtS ;
extern const int_T gblNumToFiles ; extern const int_T gblNumFrFiles ; extern
const int_T gblNumFrWksBlocks ; extern rtInportTUtable * gblInportTUtables ;
extern const char * gblInportFileName ; extern const int_T
gblNumRootInportBlks ; extern const int_T gblNumModelInputs ; extern const
int_T gblInportDataTypeIdx [ ] ; extern const int_T gblInportDims [ ] ;
extern const int_T gblInportComplex [ ] ; extern const int_T
gblInportInterpoFlag [ ] ; extern const int_T gblInportContinuous [ ] ;
extern const int_T gblParameterTuningTid ; extern DataMapInfo *
rt_dataMapInfoPtr ; extern rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr ;
void MdlOutputs ( int_T tid ) ; void MdlOutputsParameterSampleTime ( int_T
tid ) ; void MdlUpdate ( int_T tid ) ; void MdlTerminate ( void ) ; void
MdlInitializeSizes ( void ) ; void MdlInitializeSampleTimes ( void ) ;
SimStruct * raccel_register_model ( void ) ;
#endif
