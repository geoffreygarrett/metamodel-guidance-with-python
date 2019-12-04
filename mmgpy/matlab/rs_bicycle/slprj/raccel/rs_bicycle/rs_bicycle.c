#include "__cf_rs_bicycle.h"
#include "rt_logging_mmi.h"
#include "rs_bicycle_capi.h"
#include <math.h>
#include "rs_bicycle.h"
#include "rs_bicycle_private.h"
#include "rs_bicycle_dt.h"
extern void * CreateDiagnosticAsVoidPtr_wrapper ( const char * id , int nargs
, ... ) ; RTWExtModeInfo * gblRTWExtModeInfo = NULL ; extern boolean_T
gblExtModeStartPktReceived ; void raccelForceExtModeShutdown ( ) { if ( !
gblExtModeStartPktReceived ) { boolean_T stopRequested = false ;
rtExtModeWaitForStartPkt ( gblRTWExtModeInfo , 2 , & stopRequested ) ; }
rtExtModeShutdown ( 2 ) ; }
#include "slsv_diagnostic_codegen_c_api.h"
const int_T gblNumToFiles = 0 ; const int_T gblNumFrFiles = 0 ; const int_T
gblNumFrWksBlocks = 0 ;
#ifdef RSIM_WITH_SOLVER_MULTITASKING
boolean_T gbl_raccel_isMultitasking = 1 ;
#else
boolean_T gbl_raccel_isMultitasking = 0 ;
#endif
boolean_T gbl_raccel_tid01eq = 1 ; int_T gbl_raccel_NumST = 3 ; const char_T
* gbl_raccel_Version = "9.2 (R2019b) 18-Jul-2019" ; void
raccel_setup_MMIStateLog ( SimStruct * S ) {
#ifdef UseMMIDataLogging
rt_FillStateSigInfoFromMMI ( ssGetRTWLogInfo ( S ) , & ssGetErrorStatus ( S )
) ;
#else
UNUSED_PARAMETER ( S ) ;
#endif
} static DataMapInfo rt_dataMapInfo ; DataMapInfo * rt_dataMapInfoPtr = &
rt_dataMapInfo ; rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr = & (
rt_dataMapInfo . mmi ) ; const char * gblSlvrJacPatternFileName =
"slprj//raccel//rs_bicycle//rs_bicycle_Jpattern.mat" ; const int_T
gblNumRootInportBlks = 1 ; const int_T gblNumModelInputs = 1 ; extern
rtInportTUtable * gblInportTUtables ; extern const char * gblInportFileName ;
extern void * gblAperiodicPartitionHitTimes ; const int_T
gblInportDataTypeIdx [ ] = { 0 } ; const int_T gblInportDims [ ] = { 1 , 1 }
; const int_T gblInportComplex [ ] = { 0 } ; const int_T gblInportInterpoFlag
[ ] = { 1 } ; const int_T gblInportContinuous [ ] = { 1 } ; int_T
enableFcnCallFlag [ ] = { 1 , 1 , 1 } ; const char *
raccelLoadInputsAndAperiodicHitTimes ( const char * inportFileName , int *
matFileFormat ) { return rt_RapidReadInportsMatFile ( inportFileName ,
matFileFormat , 1 ) ; }
#include "simstruc.h"
#include "fixedpoint.h"
B rtB ; X rtX ; DW rtDW ; ExtU rtU ; ExtY rtY ; static SimStruct model_S ;
SimStruct * const rtS = & model_S ; static void cwxa05ec2v ( bckkwnlnai * obj
, fkh3de5uws * iobj_0 ) ; static void o5vwfobue0 ( bckkwnlnai * obj ) ;
static void fh5egdhe0x ( bckkwnlnai * obj ) ; static void bgdpkbiamx (
bckkwnlnai * obj ) ; static void bnz0w0vzzdd ( ht3benkjob * obj , kztkp1snwz
* iobj_0 ) ; static void bnz0w0vzzd ( kes444tmjv * obj , kuzoipzra0 * iobj_0
) ; static real_T jyxyppocco ( kuzoipzra0 * obj , real_T x ) ; static void
b3j0rsupo2u ( ht3benkjob * obj ) ; static void eu4rsuc3mkt ( ht3benkjob * obj
) ; static void gpmhpxabouq ( ht3benkjob * obj ) ; static void b3j0rsupo2 (
kes444tmjv * obj ) ; static void eu4rsuc3mk ( kes444tmjv * obj ) ; static
void gpmhpxabou ( kes444tmjv * obj ) ; static void cwxa05ec2v ( bckkwnlnai *
obj , fkh3de5uws * iobj_0 ) { bckkwnlnai * obj_p ; fs2tenmqcv varSizes ;
fkh3de5uws * iobj_0_p ; int32_T i ; obj -> isSetupComplete = false ; obj ->
isInitialized = 1 ; obj_p = obj ; varSizes . f1 [ 0 ] = 1U ; varSizes . f1 [
1 ] = 1U ; for ( i = 0 ; i < 6 ; i ++ ) { varSizes . f1 [ i + 2 ] = 1U ; }
obj_p -> inputVarSize = varSizes ; obj_p = obj ; iobj_0_p = iobj_0 ; obj_p ->
NumChannels = 1 ; iobj_0_p -> isInitialized = 0 ; obj_p -> pStat = iobj_0_p ;
iobj_0_p = obj_p -> pStat ; iobj_0_p -> isSetupComplete = false ; iobj_0_p ->
isInitialized = 1 ; iobj_0_p -> isSetupComplete = true ; obj ->
isSetupComplete = true ; } static void o5vwfobue0 ( bckkwnlnai * obj ) {
bckkwnlnai * obj_p ; fkh3de5uws * obj_e ; if ( obj -> isInitialized == 1 ) {
obj_p = obj ; if ( obj_p -> isSetupComplete ) { obj_p -> NumChannels = - 1 ;
obj_e = obj_p -> pStat ; if ( obj_e -> isInitialized == 1 ) { obj_e ->
isInitialized = 2 ; } } } } static void fh5egdhe0x ( bckkwnlnai * obj ) {
o5vwfobue0 ( obj ) ; } static void bgdpkbiamx ( bckkwnlnai * obj ) { if ( !
obj -> matlabCodegenIsDeleted ) { obj -> matlabCodegenIsDeleted = true ;
fh5egdhe0x ( obj ) ; } } void gwug4loynm ( dzvjycueyh * localDW ) {
bckkwnlnai * obj ; fkh3de5uws * obj_p ; int32_T i ; obj = & localDW ->
bu2jbgsv15 ; obj_p = obj -> pStat ; if ( obj_p -> isInitialized == 1 ) { for
( i = 0 ; i < 200 ; i ++ ) { obj_p -> pBuffer [ i ] = 0.0 ; } for ( i = 0 ; i
< 200 ; i ++ ) { obj_p -> pBufferIdx [ i ] = 0 ; } obj_p -> pNumElements = 0
; obj_p -> pCount = 1 ; obj_p -> pTop = 1 ; } } void ka0rucvtv0 ( dzvjycueyh
* localDW ) { fkh3de5uws * iobj_0 ; bckkwnlnai * b_obj ; localDW ->
bu2jbgsv15 . matlabCodegenIsDeleted = true ; iobj_0 = & localDW -> aviewp3bz1
; b_obj = & localDW -> bu2jbgsv15 ; b_obj -> isInitialized = 0 ; b_obj ->
NumChannels = - 1 ; b_obj -> matlabCodegenIsDeleted = false ; localDW ->
pumqcfxdvo = true ; cwxa05ec2v ( & localDW -> bu2jbgsv15 , iobj_0 ) ; } void
c351hegycs ( real_T avahefhab4 , me0inc24h2 * localB , dzvjycueyh * localDW )
{ bckkwnlnai * obj ; bckkwnlnai * obj_p ; real_T k ; fkh3de5uws * obj_e ;
fkh3de5uws * obj_i ; real_T buf [ 200 ] ; int32_T bufIdx [ 200 ] ; int32_T
numElements ; int32_T cnt ; int32_T top ; int32_T winLen ; int32_T placement
; int32_T ind_vect [ 200 ] ; int32_T N ; int32_T count ; int32_T indVal ;
boolean_T cond ; int32_T b_ind ; fkh3de5uws * obj_m ; int32_T i ; boolean_T
exitg1 ; obj = & localDW -> bu2jbgsv15 ; obj_p = obj ; numElements = 0 ;
exitg1 = false ; while ( ( ! exitg1 ) && ( numElements < 8 ) ) { k = ( real_T
) numElements + 1.0 ; if ( obj_p -> inputVarSize . f1 [ ( int32_T ) k - 1 ]
!= 1U ) { for ( placement = 0 ; placement < 8 ; placement ++ ) { obj_p ->
inputVarSize . f1 [ placement ] = 1U ; } exitg1 = true ; } else { numElements
++ ; } } obj_e = obj -> pStat ; if ( obj_e -> isInitialized != 1 ) { obj_i =
obj_e ; obj_m = obj_i ; obj_m -> isSetupComplete = false ; obj_m ->
isInitialized = 1 ; obj_m -> isSetupComplete = true ; for ( i = 0 ; i < 200 ;
i ++ ) { obj_i -> pBuffer [ i ] = 0.0 ; } for ( i = 0 ; i < 200 ; i ++ ) {
obj_i -> pBufferIdx [ i ] = 0 ; } obj_i -> pNumElements = 0 ; obj_i -> pCount
= 1 ; obj_i -> pTop = 1 ; } for ( i = 0 ; i < 200 ; i ++ ) { buf [ i ] =
obj_e -> pBuffer [ i ] ; } for ( i = 0 ; i < 200 ; i ++ ) { bufIdx [ i ] =
obj_e -> pBufferIdx [ i ] ; } numElements = obj_e -> pNumElements ; cnt =
obj_e -> pCount ; top = obj_e -> pTop ; if ( numElements > 0 ) { i = bufIdx [
top - 1 ] ; if ( ( cnt >= 0 ) && ( i < cnt - MAX_int32_T ) ) { i =
MAX_int32_T ; } else if ( ( cnt < 0 ) && ( i > cnt - MIN_int32_T ) ) { i =
MIN_int32_T ; } else { i = cnt - i ; } if ( i == 200 ) { if ( top >
2147483646 ) { top = MAX_int32_T ; } else { top ++ ; } if ( top > 200 ) { top
= 1 ; } numElements -- ; } } if ( ( numElements < 0 ) && ( top < MIN_int32_T
- numElements ) ) { i = MIN_int32_T ; } else if ( ( numElements > 0 ) && (
top > MAX_int32_T - numElements ) ) { i = MAX_int32_T ; } else { i =
numElements + top ; } if ( i < - 2147483647 ) { placement = MIN_int32_T ; }
else { placement = i - 1 ; } if ( placement >= 200 ) { placement -= 200 ; } i
= placement + 1 ; placement = i - 1 ; memset ( & ind_vect [ 0 ] , 0 , 200U *
sizeof ( int32_T ) ) ; N = numElements ; if ( numElements > 0 ) { count = 1 ;
i = numElements - 1 ; if ( i >= 0 ) { if ( top < - 2147483647 ) { winLen =
MIN_int32_T ; } else { winLen = top - 1 ; } } for ( b_ind = i ; b_ind >= 0 ;
b_ind -- ) { if ( ( winLen < 0 ) && ( b_ind < MIN_int32_T - winLen ) ) {
indVal = MIN_int32_T ; } else if ( ( winLen > 0 ) && ( b_ind > MAX_int32_T -
winLen ) ) { indVal = MAX_int32_T ; } else { indVal = winLen + b_ind ; } if (
indVal >= 200 ) { indVal -= 200 ; } indVal ++ ; ind_vect [ count - 1 ] =
indVal ; if ( count > 2147483646 ) { count = MAX_int32_T ; } else { count ++
; } } winLen = 1 ; exitg1 = false ; while ( ( ! exitg1 ) && ( winLen - 1 <=
numElements - 1 ) ) { count = winLen - 1 ; count = ind_vect [ count ] ; k =
buf [ count - 1 ] ; cond = ( avahefhab4 < k ) ; if ( cond ) { exitg1 = true ;
} else { placement = count - 1 ; if ( N < - 2147483647 ) { N = MIN_int32_T ;
} else { N -- ; } winLen ++ ; } } } buf [ placement ] = avahefhab4 ; bufIdx [
placement ] = cnt ; if ( N > 2147483646 ) { numElements = MAX_int32_T ; }
else { numElements = N + 1 ; } k = buf [ top - 1 ] ; if ( cnt > 2147483646 )
{ cnt = MAX_int32_T ; } else { cnt ++ ; } if ( cnt > 1000000 ) { cnt -=
1000000 ; for ( placement = 0 ; placement < 200 ; placement ++ ) { i = bufIdx
[ placement ] ; if ( i < - 2146483648 ) { i = MIN_int32_T ; } else { i -=
1000000 ; } bufIdx [ placement ] = i ; } } for ( i = 0 ; i < 200 ; i ++ ) {
obj_e -> pBuffer [ i ] = buf [ i ] ; } for ( i = 0 ; i < 200 ; i ++ ) { obj_e
-> pBufferIdx [ i ] = bufIdx [ i ] ; } obj_e -> pNumElements = numElements ;
obj_e -> pCount = cnt ; obj_e -> pTop = top ; localB -> ipdergl1q3 = k ; }
void dzd01mhcmk ( dzvjycueyh * localDW ) { bgdpkbiamx ( & localDW ->
bu2jbgsv15 ) ; } static void bnz0w0vzzdd ( ht3benkjob * obj , kztkp1snwz *
iobj_0 ) { ht3benkjob * obj_p ; fs2tenmqcv varSizes ; kztkp1snwz * iobj_0_p ;
int32_T i ; obj -> isSetupComplete = false ; obj -> isInitialized = 1 ; obj_p
= obj ; varSizes . f1 [ 0 ] = 1U ; varSizes . f1 [ 1 ] = 1U ; for ( i = 0 ; i
< 6 ; i ++ ) { varSizes . f1 [ i + 2 ] = 1U ; } obj_p -> inputVarSize =
varSizes ; obj_p = obj ; iobj_0_p = iobj_0 ; obj_p -> NumChannels = 1 ;
iobj_0_p -> isInitialized = 0 ; obj_p -> pStat = iobj_0_p ; iobj_0_p = obj_p
-> pStat ; iobj_0_p -> isSetupComplete = false ; iobj_0_p -> isInitialized =
1 ; iobj_0_p -> isSetupComplete = true ; obj -> isSetupComplete = true ; }
static void bnz0w0vzzd ( kes444tmjv * obj , kuzoipzra0 * iobj_0 ) {
kes444tmjv * obj_p ; fs2tenmqcv varSizes ; kuzoipzra0 * iobj_0_p ; int32_T i
; obj -> isSetupComplete = false ; obj -> isInitialized = 1 ; obj_p = obj ;
varSizes . f1 [ 0 ] = 1U ; varSizes . f1 [ 1 ] = 1U ; for ( i = 0 ; i < 6 ; i
++ ) { varSizes . f1 [ i + 2 ] = 1U ; } obj_p -> inputVarSize = varSizes ;
obj_p = obj ; iobj_0_p = iobj_0 ; obj_p -> NumChannels = 1 ; iobj_0_p ->
isInitialized = 0 ; obj_p -> pStat = iobj_0_p ; iobj_0_p = obj_p -> pStat ;
iobj_0_p -> isSetupComplete = false ; iobj_0_p -> isInitialized = 1 ;
iobj_0_p -> isSetupComplete = true ; obj -> isSetupComplete = true ; } static
real_T jyxyppocco ( kuzoipzra0 * obj , real_T x ) { real_T m ; real_T buf [
500 ] ; int32_T bufIdx [ 500 ] ; int32_T numElements ; int32_T cnt ; int32_T
top ; int32_T winLen ; int32_T placement ; int32_T ind_vect [ 500 ] ; int32_T
N ; int32_T count ; int32_T indVal ; boolean_T cond ; int32_T b_ind ; real_T
y ; int32_T qY ; boolean_T exitg1 ; memcpy ( & buf [ 0 ] , & obj -> pBuffer [
0 ] , 500U * sizeof ( real_T ) ) ; memcpy ( & bufIdx [ 0 ] , & obj ->
pBufferIdx [ 0 ] , 500U * sizeof ( int32_T ) ) ; numElements = obj ->
pNumElements ; cnt = obj -> pCount ; top = obj -> pTop ; if ( numElements > 0
) { winLen = bufIdx [ top - 1 ] ; if ( ( cnt >= 0 ) && ( winLen < cnt -
MAX_int32_T ) ) { winLen = MAX_int32_T ; } else if ( ( cnt < 0 ) && ( winLen
> cnt - MIN_int32_T ) ) { winLen = MIN_int32_T ; } else { winLen = cnt -
winLen ; } if ( winLen == 500 ) { if ( top > 2147483646 ) { top = MAX_int32_T
; } else { top ++ ; } if ( top > 500 ) { top = 1 ; } numElements -- ; } } if
( ( numElements < 0 ) && ( top < MIN_int32_T - numElements ) ) { winLen =
MIN_int32_T ; } else if ( ( numElements > 0 ) && ( top > MAX_int32_T -
numElements ) ) { winLen = MAX_int32_T ; } else { winLen = numElements + top
; } if ( winLen < - 2147483647 ) { placement = MIN_int32_T ; } else {
placement = winLen - 1 ; } if ( placement >= 500 ) { placement -= 500 ; }
winLen = placement + 1 ; placement = winLen - 1 ; memset ( & ind_vect [ 0 ] ,
0 , 500U * sizeof ( int32_T ) ) ; N = numElements ; if ( numElements > 0 ) {
count = 1 ; winLen = numElements - 1 ; if ( winLen >= 0 ) { if ( top < -
2147483647 ) { qY = MIN_int32_T ; } else { qY = top - 1 ; } } for ( b_ind =
winLen ; b_ind >= 0 ; b_ind -- ) { if ( ( qY < 0 ) && ( b_ind < MIN_int32_T -
qY ) ) { indVal = MIN_int32_T ; } else if ( ( qY > 0 ) && ( b_ind >
MAX_int32_T - qY ) ) { indVal = MAX_int32_T ; } else { indVal = qY + b_ind ;
} if ( indVal >= 500 ) { indVal -= 500 ; } indVal ++ ; ind_vect [ count - 1 ]
= indVal ; if ( count > 2147483646 ) { count = MAX_int32_T ; } else { count
++ ; } } winLen = 1 ; exitg1 = false ; while ( ( ! exitg1 ) && ( winLen - 1
<= numElements - 1 ) ) { count = winLen - 1 ; count = ind_vect [ count ] ; y
= buf [ count - 1 ] ; cond = ( x > y ) ; if ( cond ) { exitg1 = true ; } else
{ placement = count - 1 ; if ( N < - 2147483647 ) { N = MIN_int32_T ; } else
{ N -- ; } winLen ++ ; } } } buf [ placement ] = x ; bufIdx [ placement ] =
cnt ; if ( N > 2147483646 ) { numElements = MAX_int32_T ; } else {
numElements = N + 1 ; } m = buf [ top - 1 ] ; if ( cnt > 2147483646 ) { cnt =
MAX_int32_T ; } else { cnt ++ ; } if ( cnt > 1000000 ) { cnt -= 1000000 ; for
( placement = 0 ; placement < 500 ; placement ++ ) { winLen = bufIdx [
placement ] ; if ( winLen < - 2146483648 ) { winLen = MIN_int32_T ; } else {
winLen -= 1000000 ; } bufIdx [ placement ] = winLen ; } } memcpy ( & obj ->
pBuffer [ 0 ] , & buf [ 0 ] , 500U * sizeof ( real_T ) ) ; memcpy ( & obj ->
pBufferIdx [ 0 ] , & bufIdx [ 0 ] , 500U * sizeof ( int32_T ) ) ; obj ->
pNumElements = numElements ; obj -> pCount = cnt ; obj -> pTop = top ; return
m ; } static void b3j0rsupo2u ( ht3benkjob * obj ) { ht3benkjob * obj_p ;
kztkp1snwz * obj_e ; if ( obj -> isInitialized == 1 ) { obj_p = obj ; if (
obj_p -> isSetupComplete ) { obj_p -> NumChannels = - 1 ; obj_e = obj_p ->
pStat ; if ( obj_e -> isInitialized == 1 ) { obj_e -> isInitialized = 2 ; } }
} } static void eu4rsuc3mkt ( ht3benkjob * obj ) { b3j0rsupo2u ( obj ) ; }
static void gpmhpxabouq ( ht3benkjob * obj ) { if ( ! obj ->
matlabCodegenIsDeleted ) { obj -> matlabCodegenIsDeleted = true ; eu4rsuc3mkt
( obj ) ; } } static void b3j0rsupo2 ( kes444tmjv * obj ) { kes444tmjv *
obj_p ; kuzoipzra0 * obj_e ; if ( obj -> isInitialized == 1 ) { obj_p = obj ;
if ( obj_p -> isSetupComplete ) { obj_p -> NumChannels = - 1 ; obj_e = obj_p
-> pStat ; if ( obj_e -> isInitialized == 1 ) { obj_e -> isInitialized = 2 ;
} } } } static void eu4rsuc3mk ( kes444tmjv * obj ) { b3j0rsupo2 ( obj ) ; }
static void gpmhpxabou ( kes444tmjv * obj ) { if ( ! obj ->
matlabCodegenIsDeleted ) { obj -> matlabCodegenIsDeleted = true ; eu4rsuc3mk
( obj ) ; } } void MdlInitialize ( void ) { ht3benkjob * obj ; kztkp1snwz *
obj_p ; kes444tmjv * obj_e ; kuzoipzra0 * obj_i ; int32_T i ; if (
ssIsFirstInitCond ( rtS ) ) { rtX . fdwigv02gz = 0.0 ; } rtDW . eufiybe1pc =
1 ; rtX . jr2pi52g5m = rtP . Integrator_IC ; rtDW . odnmi54ao0 = rtP .
Difference_ICPrevInput ; rtX . mbyulbirys = rtP . Integrator1_IC ; rtX .
damgdgtbrg = rtP . Integrator2_IC ; obj = & rtDW . o5o3u4ixzs ; obj_p = obj
-> pStat ; if ( obj_p -> isInitialized == 1 ) { obj_p -> pBuffer [ 0 ] = 0.0
; obj_p -> pBuffer [ 1 ] = 0.0 ; obj_p -> pBuffer [ 2 ] = 0.0 ; obj_p ->
pBuffer [ 3 ] = 0.0 ; obj_p -> pBufferIdx [ 0 ] = 0 ; obj_p -> pBufferIdx [ 1
] = 0 ; obj_p -> pBufferIdx [ 2 ] = 0 ; obj_p -> pBufferIdx [ 3 ] = 0 ; obj_p
-> pNumElements = 0 ; obj_p -> pCount = 1 ; obj_p -> pTop = 1 ; } obj_e = &
rtDW . ifjz2d2ffr ; obj_i = obj_e -> pStat ; if ( obj_i -> isInitialized == 1
) { for ( i = 0 ; i < 500 ; i ++ ) { obj_i -> pBuffer [ i ] = 0.0 ; } for ( i
= 0 ; i < 500 ; i ++ ) { obj_i -> pBufferIdx [ i ] = 0 ; } obj_i ->
pNumElements = 0 ; obj_i -> pCount = 1 ; obj_i -> pTop = 1 ; } gwug4loynm ( &
rtDW . cq1wd4pu5m ) ; gwug4loynm ( & rtDW . it0b4crh0a ) ; gwug4loynm ( &
rtDW . jfaynsbq1z ) ; gwug4loynm ( & rtDW . c351hegycsd ) ; } void MdlStart (
void ) { kztkp1snwz * iobj_0 ; ht3benkjob * b_obj ; kuzoipzra0 * iobj_0_p ;
kes444tmjv * b_obj_p ; { void * * slioCatalogueAddr = rt_slioCatalogueAddr (
) ; void * r2 = ( NULL ) ; void * * pOSigstreamManagerAddr = ( NULL ) ; const
int maxErrorBufferSize = 16384 ; char errMsgCreatingOSigstreamManager [ 16384
] ; bool errorCreatingOSigstreamManager = false ; const char *
errorAddingR2SharedResource = ( NULL ) ; * slioCatalogueAddr =
rtwGetNewSlioCatalogue ( rt_GetMatSigLogSelectorFileName ( ) ) ;
errorAddingR2SharedResource = rtwAddR2SharedResource (
rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) , 1 ) ; if (
errorAddingR2SharedResource != ( NULL ) ) { rtwTerminateSlioCatalogue (
slioCatalogueAddr ) ; * slioCatalogueAddr = ( NULL ) ; ssSetErrorStatus ( rtS
, errorAddingR2SharedResource ) ; return ; } r2 = rtwGetR2SharedResource (
rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) ) ;
pOSigstreamManagerAddr = rt_GetOSigstreamManagerAddr ( ) ;
errorCreatingOSigstreamManager = rtwOSigstreamManagerCreateInstance (
rt_GetMatSigLogSelectorFileName ( ) , r2 , pOSigstreamManagerAddr ,
errMsgCreatingOSigstreamManager , maxErrorBufferSize ) ; if (
errorCreatingOSigstreamManager ) { * pOSigstreamManagerAddr = ( NULL ) ;
ssSetErrorStatus ( rtS , errMsgCreatingOSigstreamManager ) ; return ; } } {
bool externalInputIsInDatasetFormat = false ; void * pISigstreamManager =
rt_GetISigstreamManager ( ) ; rtwISigstreamManagerGetInputIsInDatasetFormat (
pISigstreamManager , & externalInputIsInDatasetFormat ) ; if (
externalInputIsInDatasetFormat ) { rtwISigstreamManagerSetDestinationBase (
pISigstreamManager , 0 , & rtU . bpe1ezavi1 ) ; } } rtB . itak35c1xz = rtP .
init_position ; rtDW . o5o3u4ixzs . matlabCodegenIsDeleted = true ; iobj_0 =
& rtDW . azlvoaxn1v ; b_obj = & rtDW . o5o3u4ixzs ; b_obj -> isInitialized =
0 ; b_obj -> NumChannels = - 1 ; b_obj -> matlabCodegenIsDeleted = false ;
rtDW . pchqaf4hz2 = true ; bnz0w0vzzdd ( & rtDW . o5o3u4ixzs , iobj_0 ) ;
rtDW . ifjz2d2ffr . matlabCodegenIsDeleted = true ; iobj_0_p = & rtDW .
gqwdiipwrj ; b_obj_p = & rtDW . ifjz2d2ffr ; b_obj_p -> isInitialized = 0 ;
b_obj_p -> NumChannels = - 1 ; b_obj_p -> matlabCodegenIsDeleted = false ;
rtDW . l4xuf0ayh1 = true ; bnz0w0vzzd ( & rtDW . ifjz2d2ffr , iobj_0_p ) ;
ka0rucvtv0 ( & rtDW . cq1wd4pu5m ) ; ka0rucvtv0 ( & rtDW . it0b4crh0a ) ;
ka0rucvtv0 ( & rtDW . jfaynsbq1z ) ; ka0rucvtv0 ( & rtDW . c351hegycsd ) ;
MdlInitialize ( ) ; } void MdlOutputs ( int_T tid ) { ht3benkjob * obj ;
ht3benkjob * obj_p ; real_T k ; kztkp1snwz * obj_e ; kztkp1snwz * obj_i ;
real_T buf [ 4 ] ; int32_T bufIdx [ 4 ] ; int32_T numElements ; int32_T cnt ;
int32_T top ; int32_T winLen ; int32_T placement ; int32_T ind_vect [ 4 ] ;
int32_T N ; int32_T count ; int32_T indVal ; boolean_T cond ; int32_T b_ind ;
kztkp1snwz * obj_m ; kes444tmjv * obj_g ; kes444tmjv * obj_j ; kuzoipzra0 *
obj_f ; kuzoipzra0 * obj_c ; kuzoipzra0 * obj_k ; real_T Bias ; int32_T qY ;
boolean_T exitg1 ; if ( gblInportFileName != ( NULL ) ) { bool
externalInputIsInDatasetFormat = false ; void * pISigstreamManager =
rt_GetISigstreamManager ( ) ; rtwISigstreamManagerGetInputIsInDatasetFormat (
pISigstreamManager , & externalInputIsInDatasetFormat ) ; if (
slIsRapidAcceleratorSimulating ( ) && externalInputIsInDatasetFormat ) {
const int maxErrorBufferSize = 16384 ; char errMsg [ 16384 ] ; bool
bSetErrorStatus = false ; if ( 1 ) { { real_T time = ssGetTaskTime ( rtS , 0
) ; if ( ! rtwISigstreamManagerIsPeriodicFcnCall ( pISigstreamManager , 0 ) )
{ int_T sampleHit = 0U ; bSetErrorStatus =
rtwISigstreamManagerInjectDataMultiRate ( pISigstreamManager , 0 , time , 1 ,
"<Root>/Time Velocity Vectors" , "[x]" , & sampleHit , errMsg ,
maxErrorBufferSize ) ; } } } if ( bSetErrorStatus ) { ssSetErrorStatus ( rtS
, errMsg ) ; return ; } } else { int_T currTimeIdx ; int_T i ; if (
gblInportTUtables [ 0 ] . nTimePoints > 0 ) { if ( 1 ) { { real_T time =
ssGetTaskTime ( rtS , 0 ) ; int k = 1 ; if ( gblInportTUtables [ 0 ] .
nTimePoints == 1 ) { k = 0 ; } currTimeIdx = rt_getTimeIdx (
gblInportTUtables [ 0 ] . time , time , gblInportTUtables [ 0 ] . nTimePoints
, gblInportTUtables [ 0 ] . currTimeIdx , 1 , 0 ) ; gblInportTUtables [ 0 ] .
currTimeIdx = currTimeIdx ; for ( i = 0 ; i < 1 ; i ++ ) { real_T * realPtr1
= ( real_T * ) gblInportTUtables [ 0 ] . ur + i * gblInportTUtables [ 0 ] .
nTimePoints + currTimeIdx ; real_T * realPtr2 = realPtr1 + 1 * k ; ( void )
rt_Interpolate_Datatype ( realPtr1 , realPtr2 , & rtU . bpe1ezavi1 , time ,
gblInportTUtables [ 0 ] . time [ currTimeIdx ] , gblInportTUtables [ 0 ] .
time [ currTimeIdx + k ] , gblInportTUtables [ 0 ] . uDataType ) ; } } } } }
} if ( rtDW . eufiybe1pc != 0 ) { rtX . fdwigv02gz = rtB . itak35c1xz ; } rtB
. kkii1l5vii = rtX . fdwigv02gz ; Bias = rtB . kkii1l5vii ; obj = & rtDW .
o5o3u4ixzs ; obj_p = obj ; numElements = 0 ; exitg1 = false ; while ( ( !
exitg1 ) && ( numElements < 8 ) ) { k = ( real_T ) numElements + 1.0 ; if (
obj_p -> inputVarSize . f1 [ ( int32_T ) k - 1 ] != 1U ) { for ( numElements
= 0 ; numElements < 8 ; numElements ++ ) { obj_p -> inputVarSize . f1 [
numElements ] = 1U ; } exitg1 = true ; } else { numElements ++ ; } } obj_e =
obj -> pStat ; if ( obj_e -> isInitialized != 1 ) { obj_i = obj_e ; obj_m =
obj_i ; obj_m -> isSetupComplete = false ; obj_m -> isInitialized = 1 ; obj_m
-> isSetupComplete = true ; obj_i -> pBuffer [ 0 ] = 0.0 ; obj_i -> pBuffer [
1 ] = 0.0 ; obj_i -> pBuffer [ 2 ] = 0.0 ; obj_i -> pBuffer [ 3 ] = 0.0 ;
obj_i -> pBufferIdx [ 0 ] = 0 ; obj_i -> pBufferIdx [ 1 ] = 0 ; obj_i ->
pBufferIdx [ 2 ] = 0 ; obj_i -> pBufferIdx [ 3 ] = 0 ; obj_i -> pNumElements
= 0 ; obj_i -> pCount = 1 ; obj_i -> pTop = 1 ; } buf [ 0 ] = obj_e ->
pBuffer [ 0 ] ; buf [ 1 ] = obj_e -> pBuffer [ 1 ] ; buf [ 2 ] = obj_e ->
pBuffer [ 2 ] ; buf [ 3 ] = obj_e -> pBuffer [ 3 ] ; bufIdx [ 0 ] = obj_e ->
pBufferIdx [ 0 ] ; bufIdx [ 1 ] = obj_e -> pBufferIdx [ 1 ] ; bufIdx [ 2 ] =
obj_e -> pBufferIdx [ 2 ] ; bufIdx [ 3 ] = obj_e -> pBufferIdx [ 3 ] ;
numElements = obj_e -> pNumElements ; cnt = obj_e -> pCount ; top = obj_e ->
pTop ; if ( numElements > 0 ) { placement = bufIdx [ top - 1 ] ; if ( ( cnt
>= 0 ) && ( placement < cnt - MAX_int32_T ) ) { qY = MAX_int32_T ; } else if
( ( cnt < 0 ) && ( placement > cnt - MIN_int32_T ) ) { qY = MIN_int32_T ; }
else { qY = cnt - placement ; } if ( qY == 4 ) { if ( top > 2147483646 ) {
top = MAX_int32_T ; } else { top ++ ; } if ( top > 4 ) { top = 1 ; }
numElements -- ; } } if ( ( numElements < 0 ) && ( top < MIN_int32_T -
numElements ) ) { qY = MIN_int32_T ; } else if ( ( numElements > 0 ) && ( top
> MAX_int32_T - numElements ) ) { qY = MAX_int32_T ; } else { qY =
numElements + top ; } if ( qY < - 2147483647 ) { placement = MIN_int32_T ; }
else { placement = qY - 1 ; } if ( placement >= 4 ) { placement -= 4 ; } qY =
placement + 1 ; placement = qY - 1 ; ind_vect [ 0 ] = 0 ; ind_vect [ 1 ] = 0
; ind_vect [ 2 ] = 0 ; ind_vect [ 3 ] = 0 ; N = numElements ; if (
numElements > 0 ) { count = 1 ; qY = numElements - 1 ; if ( qY >= 0 ) { if (
top < - 2147483647 ) { winLen = MIN_int32_T ; } else { winLen = top - 1 ; } }
for ( b_ind = qY ; b_ind >= 0 ; b_ind -- ) { if ( ( winLen < 0 ) && ( b_ind <
MIN_int32_T - winLen ) ) { indVal = MIN_int32_T ; } else if ( ( winLen > 0 )
&& ( b_ind > MAX_int32_T - winLen ) ) { indVal = MAX_int32_T ; } else {
indVal = winLen + b_ind ; } if ( indVal >= 4 ) { indVal -= 4 ; } indVal ++ ;
ind_vect [ count - 1 ] = indVal ; if ( count > 2147483646 ) { count =
MAX_int32_T ; } else { count ++ ; } } winLen = 1 ; exitg1 = false ; while ( (
! exitg1 ) && ( winLen - 1 <= numElements - 1 ) ) { count = winLen - 1 ;
count = ind_vect [ count ] ; k = buf [ count - 1 ] ; cond = ( Bias < k ) ; if
( cond ) { exitg1 = true ; } else { placement = count - 1 ; if ( N < -
2147483647 ) { N = MIN_int32_T ; } else { N -- ; } winLen ++ ; } } } buf [
placement ] = Bias ; bufIdx [ placement ] = cnt ; if ( N > 2147483646 ) {
numElements = MAX_int32_T ; } else { numElements = N + 1 ; } Bias = buf [ top
- 1 ] ; if ( cnt > 2147483646 ) { cnt = MAX_int32_T ; } else { cnt ++ ; } if
( cnt > 1000000 ) { cnt -= 1000000 ; qY = bufIdx [ 0 ] ; if ( qY < -
2146483648 ) { qY = MIN_int32_T ; } else { qY -= 1000000 ; } bufIdx [ 0 ] =
qY ; qY = bufIdx [ 1 ] ; if ( qY < - 2146483648 ) { qY = MIN_int32_T ; } else
{ qY -= 1000000 ; } bufIdx [ 1 ] = qY ; qY = bufIdx [ 2 ] ; if ( qY < -
2146483648 ) { qY = MIN_int32_T ; } else { qY -= 1000000 ; } bufIdx [ 2 ] =
qY ; qY = bufIdx [ 3 ] ; if ( qY < - 2146483648 ) { qY = MIN_int32_T ; } else
{ qY -= 1000000 ; } bufIdx [ 3 ] = qY ; } obj_e -> pBuffer [ 0 ] = buf [ 0 ]
; obj_e -> pBuffer [ 1 ] = buf [ 1 ] ; obj_e -> pBuffer [ 2 ] = buf [ 2 ] ;
obj_e -> pBuffer [ 3 ] = buf [ 3 ] ; obj_e -> pBufferIdx [ 0 ] = bufIdx [ 0 ]
; obj_e -> pBufferIdx [ 1 ] = bufIdx [ 1 ] ; obj_e -> pBufferIdx [ 2 ] =
bufIdx [ 2 ] ; obj_e -> pBufferIdx [ 3 ] = bufIdx [ 3 ] ; obj_e ->
pNumElements = numElements ; obj_e -> pCount = cnt ; obj_e -> pTop = top ;
rtB . e3mvbvmzx4 = Bias ; rtB . pwf3pin41a = rtB . e3mvbvmzx4 / rtB .
lb31uoepla ; rtB . nmalw2wdvv = rtX . jr2pi52g5m ; rtB . phpmeo4o31 = ssGetT
( rtS ) ; if ( rtB . phpmeo4o31 > rtP . Switch_Threshold ) { rtB . pviusfxiyr
= rtB . nmalw2wdvv / rtB . phpmeo4o31 ; rtB . arnwhbdsjr = rtB . pviusfxiyr ;
} else { rtB . arnwhbdsjr = rtP . Constant_Value_ehkhiuseje ; } rtB .
fkudo4yvzg = ssGetT ( rtS ) ; Bias = 0.25 * rtP . env_route_length ; rtB .
letet25bjg [ 0 ] = rtB . kkii1l5vii - rtB . omdnrdnywn [ 0 ] ; rtB .
cuq4s4xyta [ 0 ] = muDoubleScalarAbs ( rtB . letet25bjg [ 0 ] ) ; rtB .
di5jcafytx [ 0 ] = ( rtB . cfti4gkgoy [ 0 ] <= rtB . fkudo4yvzg ) ; rtB .
odelljfi5g [ 0 ] = ( rtB . fkudo4yvzg <= rtB . erbk25hexb [ 0 ] ) ; rtB .
lmdphncnhd [ 0 ] = ( rtB . di5jcafytx [ 0 ] && rtB . odelljfi5g [ 0 ] ) ; if
( rtB . lmdphncnhd [ 0 ] ) { rtB . lfuqpkbv4w [ 0 ] = rtP . Constant_Value ;
} else { rtB . lfuqpkbv4w [ 0 ] = rtP . no1_Value ; } if ( rtB . lfuqpkbv4w [
0 ] > rtP . Switch2_Threshold ) { rtB . gjgjxuamsb [ 0 ] = rtB . cuq4s4xyta [
0 ] ; } else { rtB . gjgjxuamsb [ 0 ] = Bias ; } rtB . letet25bjg [ 1 ] = rtB
. kkii1l5vii - rtB . omdnrdnywn [ 1 ] ; rtB . cuq4s4xyta [ 1 ] =
muDoubleScalarAbs ( rtB . letet25bjg [ 1 ] ) ; rtB . di5jcafytx [ 1 ] = ( rtB
. cfti4gkgoy [ 1 ] <= rtB . fkudo4yvzg ) ; rtB . odelljfi5g [ 1 ] = ( rtB .
fkudo4yvzg <= rtB . erbk25hexb [ 1 ] ) ; rtB . lmdphncnhd [ 1 ] = ( rtB .
di5jcafytx [ 1 ] && rtB . odelljfi5g [ 1 ] ) ; if ( rtB . lmdphncnhd [ 1 ] )
{ rtB . lfuqpkbv4w [ 1 ] = rtP . Constant_Value ; } else { rtB . lfuqpkbv4w [
1 ] = rtP . no1_Value ; } if ( rtB . lfuqpkbv4w [ 1 ] > rtP .
Switch2_Threshold ) { rtB . gjgjxuamsb [ 1 ] = rtB . cuq4s4xyta [ 1 ] ; }
else { rtB . gjgjxuamsb [ 1 ] = Bias ; } if ( ( rtB . gjgjxuamsb [ 0 ] > rtB
. gjgjxuamsb [ 1 ] ) || ( muDoubleScalarIsNaN ( rtB . gjgjxuamsb [ 0 ] ) && (
! muDoubleScalarIsNaN ( rtB . gjgjxuamsb [ 1 ] ) ) ) ) { rtB . g14mvqcdge =
rtB . gjgjxuamsb [ 1 ] ; } else { rtB . g14mvqcdge = rtB . gjgjxuamsb [ 0 ] ;
} Bias = rtB . g14mvqcdge ; obj_g = & rtDW . ifjz2d2ffr ; obj_j = obj_g ;
numElements = 0 ; exitg1 = false ; while ( ( ! exitg1 ) && ( numElements < 8
) ) { k = ( real_T ) numElements + 1.0 ; if ( obj_j -> inputVarSize . f1 [ (
int32_T ) k - 1 ] != 1U ) { for ( numElements = 0 ; numElements < 8 ;
numElements ++ ) { obj_j -> inputVarSize . f1 [ numElements ] = 1U ; } exitg1
= true ; } else { numElements ++ ; } } obj_f = obj_g -> pStat ; if ( obj_f ->
isInitialized != 1 ) { obj_c = obj_f ; obj_k = obj_c ; obj_k ->
isSetupComplete = false ; obj_k -> isInitialized = 1 ; obj_k ->
isSetupComplete = true ; for ( numElements = 0 ; numElements < 500 ;
numElements ++ ) { obj_c -> pBuffer [ numElements ] = 0.0 ; } for (
numElements = 0 ; numElements < 500 ; numElements ++ ) { obj_c -> pBufferIdx
[ numElements ] = 0 ; } obj_c -> pNumElements = 0 ; obj_c -> pCount = 1 ;
obj_c -> pTop = 1 ; } Bias = jyxyppocco ( obj_f , Bias ) ; rtB . ic2bkjstr3 =
Bias ; rtB . owlwvra5lv = rtU . bpe1ezavi1 * rtP . reaction_time_Value ; rtB
. koludsbdn4 = rtU . bpe1ezavi1 * rtU . bpe1ezavi1 ; rtB . nd3novo4e2 =
ssGetT ( rtS ) ; rtB . crugzyhjzg = rtB . eph0u45qky - rtB . nd3novo4e2 ; if
( rtB . crugzyhjzg > rtP . Switch_Threshold_hglhrydy3y ) { rtB . pnpnetosep =
rtB . nngc4xyghd ; } else { rtB . pnpnetosep = rtB . e5n35j2niw ; } rtB .
kky4swrkln = rtB . pnpnetosep * rtP . g ; rtB . pwzgbqhmlu = rtP . Gain_Gain
* rtB . kky4swrkln ; rtB . nfix4prp31 = rtB . koludsbdn4 / rtB . pwzgbqhmlu ;
rtB . mjipwiwsab = rtB . owlwvra5lv + rtB . nfix4prp31 ; c351hegycs ( rtB .
mjipwiwsab , & rtB . cq1wd4pu5m , & rtDW . cq1wd4pu5m ) ; if ( ssIsSampleHit
( rtS , 1 , 0 ) ) { rtB . mg4tkrdzya = rtDW . odnmi54ao0 ; rtB . dny1ckhqrw =
rtU . bpe1ezavi1 - rtB . mg4tkrdzya ; rtB . lavjegxa0s = ( rtB . dny1ckhqrw
>= rtP . Constant1_Value ) ; rtB . n30pv2m1ci = ( rtB . dny1ckhqrw < rtP .
Constant3_Value ) ; } rtB . k5yjkklppp = ( rtU . bpe1ezavi1 >= rtP .
Constant_Value_kyz3xktxbl ) ; rtB . gqyvdicpar = ( rtB . lavjegxa0s && rtB .
k5yjkklppp ) ; rtB . mssb2m5uof = ( rtU . bpe1ezavi1 < rtP . Constant2_Value
) ; rtB . ei3l4cdp3l = ( rtB . n30pv2m1ci && rtB . mssb2m5uof ) ; rtB .
jkqihkxsof = ( rtB . gqyvdicpar || rtB . ei3l4cdp3l ) ; if ( rtB . jkqihkxsof
) { rtB . gjhcrpjjk2 = rtB . dny1ckhqrw * rtU . bpe1ezavi1 ; rtB . gwzzjj2332
= rtB . gjhcrpjjk2 ; } else { rtB . gwzzjj2332 = rtP . Constant4_Value ; }
c351hegycs ( rtB . gwzzjj2332 , & rtB . it0b4crh0a , & rtDW . it0b4crh0a ) ;
rtB . agcm0t1jl3 = rtX . mbyulbirys ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) {
rtB . bmrbqdn4ib = rtB . dny1ckhqrw / rtP . g ; rtB . mgtwfogikl =
muDoubleScalarAbs ( rtB . bmrbqdn4ib ) ; } rtB . na1xsgoign = rtB .
mgtwfogikl - rtB . pnpnetosep ; c351hegycs ( rtB . na1xsgoign , & rtB .
jfaynsbq1z , & rtDW . jfaynsbq1z ) ; rtB . kliqr4bqad = muDoubleScalarPower (
rtU . bpe1ezavi1 , rtP . Constant_Value_jqzxbewhqx ) ; rtB . lqzb33ramg =
muDoubleScalarAbs ( rtB . kliqr4bqad ) ; c351hegycs ( rtB . lqzb33ramg , &
rtB . c351hegycsd , & rtDW . c351hegycsd ) ; rtB . j2ranx3eff = rtX .
damgdgtbrg ; rtY . i2gyzd3b1a [ 0 ] = rtB . pwf3pin41a ; rtY . i2gyzd3b1a [ 1
] = rtB . arnwhbdsjr ; rtY . i2gyzd3b1a [ 2 ] = rtB . ic2bkjstr3 ; rtY .
i2gyzd3b1a [ 3 ] = rtB . cq1wd4pu5m . ipdergl1q3 ; rtY . i2gyzd3b1a [ 4 ] =
rtB . it0b4crh0a . ipdergl1q3 ; rtY . i2gyzd3b1a [ 5 ] = rtB . agcm0t1jl3 ;
rtY . i2gyzd3b1a [ 6 ] = rtB . jfaynsbq1z . ipdergl1q3 ; rtY . i2gyzd3b1a [ 7
] = rtU . bpe1ezavi1 ; rtY . i2gyzd3b1a [ 8 ] = rtB . c351hegycsd .
ipdergl1q3 ; rtY . i2gyzd3b1a [ 9 ] = rtB . j2ranx3eff ; rtY . efcbr5m0pz [ 0
] = rtB . dny1ckhqrw ; rtY . efcbr5m0pz [ 1 ] = rtU . bpe1ezavi1 ; rtY .
efcbr5m0pz [ 2 ] = rtB . kkii1l5vii ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) {
} rtB . eb5o55xhxk = ssGetT ( rtS ) ; rtB . lmtgic4fhp [ 0 ] = rtB .
cfti4gkgoy [ 0 ] - rtB . eb5o55xhxk ; rtB . pn4bqsppqd [ 0 ] = ( rtB .
eb5o55xhxk <= rtB . cfti4gkgoy [ 0 ] ) ; rtB . mg4fdmac5p [ 0 ] = ( 0.0 - rtB
. lmtgic4fhp [ 0 ] ) - rtB . pusu00yrcw [ 0 ] ; if ( rtB . pn4bqsppqd [ 0 ] )
{ rtB . lhn2pokn3p [ 0 ] = rtB . lmtgic4fhp [ 0 ] ; } else { rtB . lhn2pokn3p
[ 0 ] = rtB . mg4fdmac5p [ 0 ] ; } rtB . lmtgic4fhp [ 1 ] = rtB . cfti4gkgoy
[ 1 ] - rtB . eb5o55xhxk ; rtB . pn4bqsppqd [ 1 ] = ( rtB . eb5o55xhxk <= rtB
. cfti4gkgoy [ 1 ] ) ; rtB . mg4fdmac5p [ 1 ] = ( 0.0 - rtB . lmtgic4fhp [ 1
] ) - rtB . pusu00yrcw [ 1 ] ; if ( rtB . pn4bqsppqd [ 1 ] ) { rtB .
lhn2pokn3p [ 1 ] = rtB . lmtgic4fhp [ 1 ] ; } else { rtB . lhn2pokn3p [ 1 ] =
rtB . mg4fdmac5p [ 1 ] ; } rtB . bba5tmuhaa = ssGetT ( rtS ) ; rtB .
nvdetxb5tx = rtB . eph0u45qky - rtB . bba5tmuhaa ; rtB . ddyto5b4zd = ssGetT
( rtS ) ; rtB . gddvi424wr = rtB . ddyto5b4zd - rtB . eph0u45qky ; if ( rtB .
gddvi424wr > rtP . Switch1_Threshold ) { rtB . k3z3m3ldej = rtP . yes_Value ;
} else { rtB . k3z3m3ldej = rtP . no_Value ; } if ( ssIsSampleHit ( rtS , 1 ,
0 ) ) { } rtB . lwwvvar4jx = ( rtB . ouatgm5wlm [ 0 ] <= rtB . kkii1l5vii ) ;
rtB . nivlobgrcv = ( rtB . kkii1l5vii <= rtB . ouatgm5wlm [ 1 ] ) ; rtB .
gllg0oiz3l = ( rtB . lwwvvar4jx && rtB . nivlobgrcv ) ; if ( rtB . gllg0oiz3l
) { rtB . ipe2ymqves = rtP . Constant_Value_oxokqz1erg ; } else { rtB .
ipe2ymqves = rtP . no_Value_eq3lkpaxhu ; } UNUSED_PARAMETER ( tid ) ; } void
MdlOutputsTID2 ( int_T tid ) { rtB . e5n35j2niw = rtP . env_mu_s_wet ; rtB .
lb31uoepla = rtP . env_route_length ; rtB . eph0u45qky = rtP .
env_t_rain_start ; rtB . nngc4xyghd = rtP . env_mu_s_dry ; rtB . fvmipg4lrj =
rtP . duration ; rtB . itak35c1xz = rtP . init_position ; rtB . pusu00yrcw [
0 ] = rtP . env_traffic_durations [ 0 ] ; rtB . dxa2fe4h5d [ 0 ] = rtP .
env_traffic_pos [ 0 ] ; rtB . cfti4gkgoy [ 0 ] = rtP . env_traffic_times [ 0
] ; rtB . nmxegffgia [ 0 ] = rtP . env_forest [ 0 ] ; rtB . ouatgm5wlm [ 0 ]
= rtB . nmxegffgia [ 0 ] * rtB . lb31uoepla ; rtB . omdnrdnywn [ 0 ] = rtB .
dxa2fe4h5d [ 0 ] * rtB . lb31uoepla ; rtB . erbk25hexb [ 0 ] = rtB .
cfti4gkgoy [ 0 ] + rtB . pusu00yrcw [ 0 ] ; rtB . pusu00yrcw [ 1 ] = rtP .
env_traffic_durations [ 1 ] ; rtB . dxa2fe4h5d [ 1 ] = rtP . env_traffic_pos
[ 1 ] ; rtB . cfti4gkgoy [ 1 ] = rtP . env_traffic_times [ 1 ] ; rtB .
nmxegffgia [ 1 ] = rtP . env_forest [ 1 ] ; rtB . ouatgm5wlm [ 1 ] = rtB .
nmxegffgia [ 1 ] * rtB . lb31uoepla ; rtB . omdnrdnywn [ 1 ] = rtB .
dxa2fe4h5d [ 1 ] * rtB . lb31uoepla ; rtB . erbk25hexb [ 1 ] = rtB .
cfti4gkgoy [ 1 ] + rtB . pusu00yrcw [ 1 ] ; UNUSED_PARAMETER ( tid ) ; } void
MdlUpdate ( int_T tid ) { rtDW . eufiybe1pc = 0 ; if ( ssIsSampleHit ( rtS ,
1 , 0 ) ) { rtDW . odnmi54ao0 = rtU . bpe1ezavi1 ; } UNUSED_PARAMETER ( tid )
; } void MdlUpdateTID2 ( int_T tid ) { UNUSED_PARAMETER ( tid ) ; } void
MdlDerivatives ( void ) { XDot * _rtXdot ; _rtXdot = ( ( XDot * ) ssGetdX (
rtS ) ) ; _rtXdot -> fdwigv02gz = rtU . bpe1ezavi1 ; _rtXdot -> jr2pi52g5m =
rtB . ipe2ymqves ; _rtXdot -> mbyulbirys = rtB . gwzzjj2332 ; _rtXdot ->
damgdgtbrg = rtB . lqzb33ramg ; } void MdlProjection ( void ) { } void
MdlTerminate ( void ) { gpmhpxabouq ( & rtDW . o5o3u4ixzs ) ; gpmhpxabou ( &
rtDW . ifjz2d2ffr ) ; dzd01mhcmk ( & rtDW . cq1wd4pu5m ) ; dzd01mhcmk ( &
rtDW . it0b4crh0a ) ; dzd01mhcmk ( & rtDW . jfaynsbq1z ) ; dzd01mhcmk ( &
rtDW . c351hegycsd ) ; if ( rt_slioCatalogue ( ) != ( NULL ) ) { void * *
slioCatalogueAddr = rt_slioCatalogueAddr ( ) ; rtwSaveDatasetsToMatFile (
rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) ,
rt_GetMatSigstreamLoggingFileName ( ) ) ; rtwTerminateSlioCatalogue (
slioCatalogueAddr ) ; * slioCatalogueAddr = NULL ; } } void
MdlInitializeSizes ( void ) { ssSetNumContStates ( rtS , 4 ) ;
ssSetNumPeriodicContStates ( rtS , 0 ) ; ssSetNumY ( rtS , 13 ) ; ssSetNumU (
rtS , 1 ) ; ssSetDirectFeedThrough ( rtS , 1 ) ; ssSetNumSampleTimes ( rtS ,
2 ) ; ssSetNumBlocks ( rtS , 104 ) ; ssSetNumBlockIO ( rtS , 75 ) ;
ssSetNumBlockParams ( rtS , 38 ) ; } void MdlInitializeSampleTimes ( void ) {
ssSetSampleTime ( rtS , 0 , 0.0 ) ; ssSetSampleTime ( rtS , 1 , 4.0 ) ;
ssSetOffsetTime ( rtS , 0 , 0.0 ) ; ssSetOffsetTime ( rtS , 1 , 0.0 ) ; }
void raccel_set_checksum ( ) { ssSetChecksumVal ( rtS , 0 , 551039131U ) ;
ssSetChecksumVal ( rtS , 1 , 168430918U ) ; ssSetChecksumVal ( rtS , 2 ,
238321069U ) ; ssSetChecksumVal ( rtS , 3 , 1733840132U ) ; }
#if defined(_MSC_VER)
#pragma optimize( "", off )
#endif
SimStruct * raccel_register_model ( void ) { static struct _ssMdlInfo mdlInfo
; ( void ) memset ( ( char * ) rtS , 0 , sizeof ( SimStruct ) ) ; ( void )
memset ( ( char * ) & mdlInfo , 0 , sizeof ( struct _ssMdlInfo ) ) ;
ssSetMdlInfoPtr ( rtS , & mdlInfo ) ; { static time_T mdlPeriod [
NSAMPLE_TIMES ] ; static time_T mdlOffset [ NSAMPLE_TIMES ] ; static time_T
mdlTaskTimes [ NSAMPLE_TIMES ] ; static int_T mdlTsMap [ NSAMPLE_TIMES ] ;
static int_T mdlSampleHits [ NSAMPLE_TIMES ] ; static boolean_T
mdlTNextWasAdjustedPtr [ NSAMPLE_TIMES ] ; static int_T mdlPerTaskSampleHits
[ NSAMPLE_TIMES * NSAMPLE_TIMES ] ; static time_T mdlTimeOfNextSampleHit [
NSAMPLE_TIMES ] ; { int_T i ; for ( i = 0 ; i < NSAMPLE_TIMES ; i ++ ) {
mdlPeriod [ i ] = 0.0 ; mdlOffset [ i ] = 0.0 ; mdlTaskTimes [ i ] = 0.0 ;
mdlTsMap [ i ] = i ; mdlSampleHits [ i ] = 1 ; } } ssSetSampleTimePtr ( rtS ,
& mdlPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rtS , & mdlOffset [ 0 ] ) ;
ssSetSampleTimeTaskIDPtr ( rtS , & mdlTsMap [ 0 ] ) ; ssSetTPtr ( rtS , &
mdlTaskTimes [ 0 ] ) ; ssSetSampleHitPtr ( rtS , & mdlSampleHits [ 0 ] ) ;
ssSetTNextWasAdjustedPtr ( rtS , & mdlTNextWasAdjustedPtr [ 0 ] ) ;
ssSetPerTaskSampleHitsPtr ( rtS , & mdlPerTaskSampleHits [ 0 ] ) ;
ssSetTimeOfNextSampleHitPtr ( rtS , & mdlTimeOfNextSampleHit [ 0 ] ) ; }
ssSetSolverMode ( rtS , SOLVER_MODE_SINGLETASKING ) ; { ssSetBlockIO ( rtS ,
( ( void * ) & rtB ) ) ; ( void ) memset ( ( ( void * ) & rtB ) , 0 , sizeof
( B ) ) ; } { ssSetU ( rtS , ( ( void * ) & rtU ) ) ; rtU . bpe1ezavi1 = 0.0
; } { ssSetY ( rtS , & rtY ) ; ( void ) memset ( ( void * ) & rtY , 0 ,
sizeof ( ExtY ) ) ; } { real_T * x = ( real_T * ) & rtX ; ssSetContStates (
rtS , x ) ; ( void ) memset ( ( void * ) x , 0 , sizeof ( X ) ) ; } { void *
dwork = ( void * ) & rtDW ; ssSetRootDWork ( rtS , dwork ) ; ( void ) memset
( dwork , 0 , sizeof ( DW ) ) ; } { static DataTypeTransInfo dtInfo ; ( void
) memset ( ( char_T * ) & dtInfo , 0 , sizeof ( dtInfo ) ) ;
ssSetModelMappingInfo ( rtS , & dtInfo ) ; dtInfo . numDataTypes = 20 ;
dtInfo . dataTypeSizes = & rtDataTypeSizes [ 0 ] ; dtInfo . dataTypeNames = &
rtDataTypeNames [ 0 ] ; dtInfo . BTransTable = & rtBTransTable ; dtInfo .
PTransTable = & rtPTransTable ; dtInfo . dataTypeInfoTable =
rtDataTypeInfoTable ; } rs_bicycle_InitializeDataMapInfo ( ) ;
ssSetIsRapidAcceleratorActive ( rtS , true ) ; ssSetRootSS ( rtS , rtS ) ;
ssSetVersion ( rtS , SIMSTRUCT_VERSION_LEVEL2 ) ; ssSetModelName ( rtS ,
"rs_bicycle" ) ; ssSetPath ( rtS , "rs_bicycle" ) ; ssSetTStart ( rtS , 0.0 )
; ssSetTFinal ( rtS , 200.0 ) ; ssSetStepSize ( rtS , 4.0 ) ;
ssSetFixedStepSize ( rtS , 4.0 ) ; { static RTWLogInfo rt_DataLoggingInfo ;
rt_DataLoggingInfo . loggingInterval = NULL ; ssSetRTWLogInfo ( rtS , &
rt_DataLoggingInfo ) ; } { { static int_T rt_LoggedStateWidths [ ] = { 1 , 1
, 1 , 1 , 1 } ; static int_T rt_LoggedStateNumDimensions [ ] = { 1 , 1 , 1 ,
1 , 1 } ; static int_T rt_LoggedStateDimensions [ ] = { 1 , 1 , 1 , 1 , 1 } ;
static boolean_T rt_LoggedStateIsVarDims [ ] = { 0 , 0 , 0 , 0 , 0 } ; static
BuiltInDTypeId rt_LoggedStateDataTypeIds [ ] = { SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE } ; static int_T
rt_LoggedStateComplexSignals [ ] = { 0 , 0 , 0 , 0 , 0 } ; static
RTWPreprocessingFcnPtr rt_LoggingStatePreprocessingFcnPtrs [ ] = { ( NULL ) ,
( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) } ; static const char_T *
rt_LoggedStateLabels [ ] = { "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" ,
"DSTATE" } ; static const char_T * rt_LoggedStateBlockNames [ ] = {
"rs_bicycle/Integrator" ,
"rs_bicycle/aux2: Fraction Spent In Forest/Integrator" ,
"rs_bicycle/Integrator1" , "rs_bicycle/Integrator2" ,
"rs_bicycle/Difference/UD" } ; static const char_T * rt_LoggedStateNames [ ]
= { "" , "" , "" , "" , "" } ; static boolean_T rt_LoggedStateCrossMdlRef [ ]
= { 0 , 0 , 0 , 0 , 0 } ; static RTWLogDataTypeConvert
rt_RTWLogDataTypeConvert [ ] = { { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 ,
1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } ,
{ 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } } ; static RTWLogSignalInfo rt_LoggedStateSignalInfo =
{ 5 , rt_LoggedStateWidths , rt_LoggedStateNumDimensions ,
rt_LoggedStateDimensions , rt_LoggedStateIsVarDims , ( NULL ) , ( NULL ) ,
rt_LoggedStateDataTypeIds , rt_LoggedStateComplexSignals , ( NULL ) ,
rt_LoggingStatePreprocessingFcnPtrs , { rt_LoggedStateLabels } , ( NULL ) , (
NULL ) , ( NULL ) , { rt_LoggedStateBlockNames } , { rt_LoggedStateNames } ,
rt_LoggedStateCrossMdlRef , rt_RTWLogDataTypeConvert } ; static void *
rt_LoggedStateSignalPtrs [ 5 ] ; rtliSetLogXSignalPtrs ( ssGetRTWLogInfo (
rtS ) , ( LogSignalPtrsType ) rt_LoggedStateSignalPtrs ) ;
rtliSetLogXSignalInfo ( ssGetRTWLogInfo ( rtS ) , & rt_LoggedStateSignalInfo
) ; rt_LoggedStateSignalPtrs [ 0 ] = ( void * ) & rtX . fdwigv02gz ;
rt_LoggedStateSignalPtrs [ 1 ] = ( void * ) & rtX . jr2pi52g5m ;
rt_LoggedStateSignalPtrs [ 2 ] = ( void * ) & rtX . mbyulbirys ;
rt_LoggedStateSignalPtrs [ 3 ] = ( void * ) & rtX . damgdgtbrg ;
rt_LoggedStateSignalPtrs [ 4 ] = ( void * ) & rtDW . odnmi54ao0 ; }
rtliSetLogT ( ssGetRTWLogInfo ( rtS ) , "tout" ) ; rtliSetLogX (
ssGetRTWLogInfo ( rtS ) , "tmp_raccel_xout" ) ; rtliSetLogXFinal (
ssGetRTWLogInfo ( rtS ) , "xFinal" ) ; rtliSetLogVarNameModifier (
ssGetRTWLogInfo ( rtS ) , "none" ) ; rtliSetLogFormat ( ssGetRTWLogInfo ( rtS
) , 2 ) ; rtliSetLogMaxRows ( ssGetRTWLogInfo ( rtS ) , 0 ) ;
rtliSetLogDecimation ( ssGetRTWLogInfo ( rtS ) , 1 ) ; { static void *
rt_LoggedOutputSignalPtrs [ ] = { & rtY . i2gyzd3b1a [ 0 ] , & rtY .
efcbr5m0pz [ 0 ] } ; rtliSetLogYSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( (
LogSignalPtrsType ) rt_LoggedOutputSignalPtrs ) ) ; } { static int_T
rt_LoggedOutputWidths [ ] = { 10 , 3 } ; static int_T
rt_LoggedOutputNumDimensions [ ] = { 1 , 1 } ; static int_T
rt_LoggedOutputDimensions [ ] = { 10 , 3 } ; static boolean_T
rt_LoggedOutputIsVarDims [ ] = { 0 , 0 } ; static void *
rt_LoggedCurrentSignalDimensions [ ] = { ( NULL ) , ( NULL ) } ; static int_T
rt_LoggedCurrentSignalDimensionsSize [ ] = { 4 , 4 } ; static BuiltInDTypeId
rt_LoggedOutputDataTypeIds [ ] = { SS_DOUBLE , SS_DOUBLE } ; static int_T
rt_LoggedOutputComplexSignals [ ] = { 0 , 0 } ; static RTWPreprocessingFcnPtr
rt_LoggingPreprocessingFcnPtrs [ ] = { ( NULL ) , ( NULL ) } ; static const
char_T * rt_LoggedOutputLabels_0 [ ] = { "" } ; static const char_T *
rt_LoggedOutputBlockNames_0 [ ] = { "rs_bicycle/F" } ; static const char_T *
rt_LoggedOutputLabels_1 [ ] = { "S" } ; static const char_T *
rt_LoggedOutputBlockNames_1 [ ] = { "rs_bicycle/S" } ; static
RTWLogDataTypeConvert rt_RTWLogDataTypeConvert [ ] = { { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } } ; static RTWLogSignalInfo rt_LoggedOutputSignalInfo [
] = { { 1 , rt_LoggedOutputWidths , rt_LoggedOutputNumDimensions ,
rt_LoggedOutputDimensions , rt_LoggedOutputIsVarDims ,
rt_LoggedCurrentSignalDimensions , rt_LoggedCurrentSignalDimensionsSize ,
rt_LoggedOutputDataTypeIds , rt_LoggedOutputComplexSignals , ( NULL ) ,
rt_LoggingPreprocessingFcnPtrs , { rt_LoggedOutputLabels_0 } , ( NULL ) , (
NULL ) , ( NULL ) , { rt_LoggedOutputBlockNames_0 } , { ( NULL ) } , ( NULL )
, rt_RTWLogDataTypeConvert } , { 1 , rt_LoggedOutputWidths + 1 ,
rt_LoggedOutputNumDimensions + 1 , rt_LoggedOutputDimensions + 1 ,
rt_LoggedOutputIsVarDims + 1 , rt_LoggedCurrentSignalDimensions + 1 ,
rt_LoggedCurrentSignalDimensionsSize + 1 , rt_LoggedOutputDataTypeIds + 1 ,
rt_LoggedOutputComplexSignals + 1 , ( NULL ) , rt_LoggingPreprocessingFcnPtrs
+ 1 , { rt_LoggedOutputLabels_1 } , ( NULL ) , ( NULL ) , ( NULL ) , {
rt_LoggedOutputBlockNames_1 } , { ( NULL ) } , ( NULL ) ,
rt_RTWLogDataTypeConvert + 1 } } ; rtliSetLogYSignalInfo ( ssGetRTWLogInfo (
rtS ) , rt_LoggedOutputSignalInfo ) ; rt_LoggedCurrentSignalDimensions [ 0 ]
= & rt_LoggedOutputWidths [ 0 ] ; rt_LoggedCurrentSignalDimensions [ 1 ] = &
rt_LoggedOutputWidths [ 1 ] ; } rtliSetLogY ( ssGetRTWLogInfo ( rtS ) ,
"tmp_raccel_yout1,tmp_raccel_yout2" ) ; } { static struct _ssStatesInfo2
statesInfo2 ; ssSetStatesInfo2 ( rtS , & statesInfo2 ) ; } { static
ssPeriodicStatesInfo periodicStatesInfo ; ssSetPeriodicStatesInfo ( rtS , &
periodicStatesInfo ) ; } { static ssSolverInfo slvrInfo ; static boolean_T
contStatesDisabled [ 4 ] ; ssSetSolverInfo ( rtS , & slvrInfo ) ;
ssSetSolverName ( rtS , "ode3" ) ; ssSetVariableStepSolver ( rtS , 0 ) ;
ssSetSolverConsistencyChecking ( rtS , 0 ) ; ssSetSolverAdaptiveZcDetection (
rtS , 0 ) ; ssSetSolverRobustResetMethod ( rtS , 0 ) ;
ssSetSolverStateProjection ( rtS , 0 ) ; ssSetSolverMassMatrixType ( rtS , (
ssMatrixType ) 0 ) ; ssSetSolverMassMatrixNzMax ( rtS , 0 ) ;
ssSetModelOutputs ( rtS , MdlOutputs ) ; ssSetModelLogData ( rtS ,
rt_UpdateTXYLogVars ) ; ssSetModelLogDataIfInInterval ( rtS ,
rt_UpdateTXXFYLogVars ) ; ssSetModelUpdate ( rtS , MdlUpdate ) ;
ssSetModelDerivatives ( rtS , MdlDerivatives ) ; ssSetTNextTid ( rtS ,
INT_MIN ) ; ssSetTNext ( rtS , rtMinusInf ) ; ssSetSolverNeedsReset ( rtS ) ;
ssSetNumNonsampledZCs ( rtS , 0 ) ; ssSetContStateDisabled ( rtS ,
contStatesDisabled ) ; } ssSetChecksumVal ( rtS , 0 , 551039131U ) ;
ssSetChecksumVal ( rtS , 1 , 168430918U ) ; ssSetChecksumVal ( rtS , 2 ,
238321069U ) ; ssSetChecksumVal ( rtS , 3 , 1733840132U ) ; { static const
sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE ; static RTWExtModeInfo
rt_ExtModeInfo ; static const sysRanDType * systemRan [ 10 ] ;
gblRTWExtModeInfo = & rt_ExtModeInfo ; ssSetRTWExtModeInfo ( rtS , &
rt_ExtModeInfo ) ; rteiSetSubSystemActiveVectorAddresses ( & rt_ExtModeInfo ,
systemRan ) ; systemRan [ 0 ] = & rtAlwaysEnabled ; systemRan [ 1 ] = &
rtAlwaysEnabled ; systemRan [ 2 ] = & rtAlwaysEnabled ; systemRan [ 3 ] = &
rtAlwaysEnabled ; systemRan [ 4 ] = & rtAlwaysEnabled ; systemRan [ 5 ] = &
rtAlwaysEnabled ; systemRan [ 6 ] = & rtAlwaysEnabled ; systemRan [ 7 ] = &
rtAlwaysEnabled ; systemRan [ 8 ] = & rtAlwaysEnabled ; systemRan [ 9 ] = &
rtAlwaysEnabled ; rteiSetModelMappingInfoPtr ( ssGetRTWExtModeInfo ( rtS ) ,
& ssGetModelMappingInfo ( rtS ) ) ; rteiSetChecksumsPtr ( ssGetRTWExtModeInfo
( rtS ) , ssGetChecksums ( rtS ) ) ; rteiSetTPtr ( ssGetRTWExtModeInfo ( rtS
) , ssGetTPtr ( rtS ) ) ; } return rtS ; }
#if defined(_MSC_VER)
#pragma optimize( "", on )
#endif
const int_T gblParameterTuningTid = 2 ; void MdlOutputsParameterSampleTime (
int_T tid ) { MdlOutputsTID2 ( tid ) ; }
