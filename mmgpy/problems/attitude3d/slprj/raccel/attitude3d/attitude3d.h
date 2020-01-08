#include "__cf_attitude3d.h"
#ifndef RTW_HEADER_attitude3d_h_
#define RTW_HEADER_attitude3d_h_
#include <stddef.h>
#include <string.h>
#include "rtw_modelmap.h"
#ifndef attitude3d_COMMON_INCLUDES_
#define attitude3d_COMMON_INCLUDES_
#include <stdlib.h>
#include "rtwtypes.h"
#include "sl_fileio_rtw.h"
#include "simtarget/slSimTgtSlFileioRTW.h"
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
#include "attitude3d_types.h"
#include "multiword_types.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include "rt_defines.h"
#define MODEL_NAME attitude3d
#define NSAMPLE_TIMES (3) 
#define NINPUTS (3)       
#define NOUTPUTS (0)     
#define NBLOCKIO (47) 
#define NUM_ZC_EVENTS (0) 
#ifndef NCSTATES
#define NCSTATES (8)   
#elif NCSTATES != 8
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
typedef struct { real_T olimizud5z ; } lhr0fwp232 ; typedef struct {
oiijeexccd bdmeifvj0g ; it1m1m5jgb kfvrm3e5fw ; it1m1m5jgb ege0j1fhnq ;
boolean_T phxfrbtrrv ; } pqlrpaqdev ; typedef struct { real_T ezrshmdyuk ; }
oolcbzau2s ; typedef struct { hkrvp5gzcl jsyeqj31fa ; j510l0uc1d aivxxmxdyh ;
j510l0uc1d oethoov3ae ; boolean_T d1vg1xnbad ; } abmczhmvhh ; typedef struct
{ ENVIRONMENT ggl2c42ej4 ; real_T j3dtcamj3h [ 4 ] ; real_T gwuhy1m1pb [ 3 ]
; real_T ksb54aeynf ; real_T lbvs2uyceq ; real_T bv1kuls22a ; real_T
i1cpfgl4ur [ 3 ] ; real_T b13j3pqall ; real_T p2owgzs2iz ; real_T adp4h11fxy
; real_T kla2ie4xqo ; real_T fvvukgofqm ; real_T ocjizknfbp ; real_T
hcfehsmczi ; real_T jcjpclbjp2 ; real_T aui5mhj44r ; real_T objaac1udz ;
real_T njrvjekzfm [ 3 ] ; real_T pctj4gwip4 ; real_T fpa0aiyozw ; real_T
bi23bgkdar ; real_T ozqsycmu2s ; real_T lm0mtopp3u ; real_T ndieoaonxd [ 3 ]
; real_T ewt1hyh1w1 [ 3 ] ; real_T hmkhnfnj2o [ 3 ] ; real_T lbe030o5eg [ 3 ]
; real_T pu5umgngnw [ 3 ] ; real_T nkfoxrkhb4 [ 3 ] ; real_T kg4dzhebco [ 3 ]
; real_T fx1eniibgn [ 3 ] ; real_T dbvg0t1pgh [ 3 ] ; real_T jwzvety1de [ 4 ]
; real_T mgffwko2vy ; real_T p4mnuhzffc ; real_T n5lv0if3fe ; real_T
fmpx14rdcd ; real_T haese0mx0t ; real_T jtzgz1uiwi ; real_T gdkatceig2 ;
real_T hcaghgg2d4 ; real_T id3syu3xda [ 4 ] ; boolean_T bqvggehzz5 ;
oolcbzau2s juzdrgfwywbn ; oolcbzau2s juzdrgfwywb ; lhr0fwp232 fbz1lrgadk1o ;
lhr0fwp232 fbz1lrgadk1 ; } B ; typedef struct { real_T nrt1u3ug04 [ 59 ] ;
real_T nn3mukf4ls [ 59 ] ; struct { void * LoggedData ; } ahlf4oinxv ; struct
{ void * PrevTimePtr ; } p5wpguxq2t ; struct { void * LoggedData [ 7 ] ; }
ddanh5gylu ; struct { void * LoggedData [ 12 ] ; } objy321rh1 ; struct { void
* LoggedData ; } g4kmj1bu2w ; struct { void * LoggedData [ 5 ] ; } fdwjlnvn2h
; struct { void * LoggedData ; } b2rvqw04iy ; struct { void * LoggedData ; }
hk1giknb0y ; struct { void * LoggedData ; } ljsijxpkth ; struct { void *
LoggedData ; } mkouu2vbc0 ; struct { void * LoggedData ; } mn51ahvl50 ;
struct { void * LoggedData ; } miwmuef3dm ; struct { void * LoggedData ; }
lvmw50sr0x ; struct { void * LoggedData ; } c1sznid5dz ; struct { void *
LoggedData ; } bs2m1afbbu ; struct { void * LoggedData ; } dikyhxirdn ;
struct { void * LoggedData ; } g545csv13p ; struct { void * LoggedData ; }
kaytbfj0hw ; struct { void * LoggedData ; } arutvhkvxm ; struct { void *
LoggedData ; } i2wgvpy5uh ; struct { void * LoggedData [ 2 ] ; } by5wrfdoin ;
int_T ag2rcaep41 ; abmczhmvhh juzdrgfwywbn ; abmczhmvhh juzdrgfwywb ;
pqlrpaqdev fbz1lrgadk1o ; pqlrpaqdev fbz1lrgadk1 ; } DW ; typedef struct {
real_T kvd5s5mhzq [ 4 ] ; real_T oznfot3xd2 ; real_T gi0dbsjbab ; real_T
ndr0ddj14l ; real_T f5kva1vvha ; } X ; typedef struct { real_T kvd5s5mhzq [ 4
] ; real_T oznfot3xd2 ; real_T gi0dbsjbab ; real_T ndr0ddj14l ; real_T
f5kva1vvha ; } XDot ; typedef struct { boolean_T kvd5s5mhzq [ 4 ] ; boolean_T
oznfot3xd2 ; boolean_T gi0dbsjbab ; boolean_T ndr0ddj14l ; boolean_T
f5kva1vvha ; } XDis ; typedef struct { real_T bhvfzp4veb [ 3 ] ; } ExtU ;
typedef struct { rtwCAPI_ModelMappingInfo mmi ; } DataMapInfo ; struct P_ {
struct_qj1aZXRxDpRc9BsHnZQAtC P_E ; struct_nois8vFfP57DutoSgf9HZD P_F ;
struct_rawc2dqRCLbbSQv98WCoDC P_X ; real_T NormalizeVector_maxzero ; real_T
NormalizeVector1_maxzero ; real_T NormalizeVector_maxzero_mt13upuc30 ; real_T
NormalizeVector1_maxzero_it3sz44pnw ; real_T
NormalizeVector_maxzero_oczsk3pynm ; real_T
NormalizeVector1_maxzero_curh4i254k ; real_T
NormalizeVector_maxzero_ektzry0otc ; real_T
NormalizeVector1_maxzero_esmeewv013 ; real_T
NormalizeVector_maxzero_frofudci2i ; real_T
NormalizeVector1_maxzero_c1jmgth0uc ; real_T
NormalizeVector_maxzero_p3wnqley4p ; real_T
NormalizeVector1_maxzero_d0tqs3zyle ; real_T
NormalizeVector_maxzero_jv521hznkv ; real_T
NormalizeVector1_maxzero_gagywgljsc ; real_T Constant_Value ; real_T
Constant_Value_c4d4ozwwzr ; real_T Constant_Value_bpciai0igk ; real_T
Constant_Value_kw5w4qkv5v ; real_T Gain1_Gain [ 4 ] ; real_T
Gain1_Gain_i0dny2tgg4 [ 4 ] ; real_T Gain1_Gain_f3zo2a45h3 [ 4 ] ; real_T
Saturation_UpperSat ; real_T Saturation_LowerSat ; real_T
Gain1_Gain_mglm2i5i2e [ 4 ] ; real_T Saturation_UpperSat_o0tu1knjb5 ; real_T
Saturation_LowerSat_pjt1p3frof ; real_T Gain1_Gain_jasbtnac0r ; real_T
DiscreteFIRFilter_InitialStates ; real_T DiscreteFIRFilter_Coefficients [ 60
] ; real_T Gain1_Gain_luip00ayzb ; real_T
DiscreteFIRFilter_InitialStates_igm30wm5ib ; real_T
DiscreteFIRFilter_Coefficients_n1yfwntl03 [ 60 ] ; real_T Integrator1_IC ;
real_T Integrator1_IC_khgln1fz0y ; real_T Integrator2_IC ; real_T
Integrator1_IC_bdymfb0f54 ; real_T Gain1_Gain_fe1rn1jbbk [ 4 ] ; real_T
Gain1_Gain_m4frltiumm [ 4 ] ; real_T Gain1_Gain_nu325gvdxx [ 4 ] ; real_T
Gain_Gain ; real_T Saturation_UpperSat_ex5fckh1e5 ; real_T
Saturation_LowerSat_nqfyaemvcp ; real_T Saturation_UpperSat_laawyukirp ;
real_T Saturation_LowerSat_pjistqqcmw ; real_T Constant_Value_bpuwj1x24m ;
real_T Constant_Value_p5yqgecpys ; real_T Constant_Value_pblczk22x1 ; real_T
Constant_Value_ojxmxt5mmf ; real_T Constant_Value_pwofnawzxn ; real_T
Constant10_Value ; real_T Constant11_Value ; real_T Constant_Value_kd4xr3zjvz
; real_T Constant_Value_gspoitvpf3 ; real_T Constant10_Value_pnntlgrkfl ;
real_T Constant11_Value_fak2wrhghj ; real_T Constant_Value_bu2n4z0wwl ;
real_T Constant_Value_ovccxkrnjy ; real_T Constant_Value_o2fro3xhzj ; real_T
Constant_Value_i2bviibqa1 ; real_T Constant_Value_mgesvrfwfg ; real_T
Constant_Value_gdyff4hfxx ; real_T Constant_Value_fcyoyjujtb ; real_T
Constant11_Value_howgtgmefa ; real_T Constant9_Value ; real_T
Constant_Value_i2ujud0fea ; real_T Constant_Value_bfz3r5ve34 ; real_T
Constant_Value_ok5wcdghto ; real_T Constant11_Value_hvpxwvfqmk ; real_T
Constant_Value_osq1m5ngw5 ; real_T Constant_Value_n5p1mlb1zj ; real_T
Constant_Value_b54p1uwprt ; real_T Constant_Value_kubckzbqj3 ; real_T
Constant_Value_lfkufjj3ic ; uint8_T ManualSwitch1_CurrentSetting ; uint8_T
ManualSwitch1_CurrentSetting_kps3rcsvpl ; } ; extern const char *
RT_MEMORY_ALLOCATION_ERROR ; extern B rtB ; extern X rtX ; extern DW rtDW ;
extern ExtU rtU ; extern P rtP ; extern const rtwCAPI_ModelMappingStaticInfo
* attitude3d_GetCAPIStaticMap ( void ) ; extern SimStruct * const rtS ;
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
