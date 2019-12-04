#include "__cf_rs_bicycle2.h"
#include "rt_logging_mmi.h"
#include "rs_bicycle2_capi.h"
#include <math.h>
#include "rs_bicycle2.h"
#include "rs_bicycle2_private.h"
#include "rs_bicycle2_dt.h"
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
"slprj//raccel//rs_bicycle2//rs_bicycle2_Jpattern.mat" ; const int_T
gblNumRootInportBlks = 0 ; const int_T gblNumModelInputs = 0 ; extern
rtInportTUtable * gblInportTUtables ; extern const char * gblInportFileName ;
extern void * gblAperiodicPartitionHitTimes ; const int_T
gblInportDataTypeIdx [ ] = { - 1 } ; const int_T gblInportDims [ ] = { - 1 }
; const int_T gblInportComplex [ ] = { - 1 } ; const int_T
gblInportInterpoFlag [ ] = { - 1 } ; const int_T gblInportContinuous [ ] = {
- 1 } ; int_T enableFcnCallFlag [ ] = { 1 , 1 , 1 } ; const char *
raccelLoadInputsAndAperiodicHitTimes ( const char * inportFileName , int *
matFileFormat ) { return rt_RapidReadInportsMatFile ( inportFileName ,
matFileFormat , 1 ) ; }
#include "simstruc.h"
#include "fixedpoint.h"
B rtB ; X rtX ; DW rtDW ; ExtY rtY ; static SimStruct model_S ; SimStruct *
const rtS = & model_S ; static void jujpi1rajl ( hq0hb5wdla * obj ,
a14pojzgfk * iobj_0 ) ; static void mqbwh1nkpv ( hq0hb5wdla * obj ) ; static
void o4quze3mjf ( hq0hb5wdla * obj ) ; static void evqdthrrjp ( hq0hb5wdla *
obj ) ; static void cwqfrbtfhu2 ( izdonajra3 * obj , nznsmjv5o1 * iobj_0 ) ;
static void cwqfrbtfhu ( bea3vlgt1r * obj , eae4ors1vz * iobj_0 ) ; static
real_T i425xztlhw ( eae4ors1vz * obj , real_T x ) ; static void nao4kbgvx5s (
izdonajra3 * obj ) ; static void j4x44qh4llo ( izdonajra3 * obj ) ; static
void pdch3c2fouu ( izdonajra3 * obj ) ; static void nao4kbgvx5 ( bea3vlgt1r *
obj ) ; static void j4x44qh4ll ( bea3vlgt1r * obj ) ; static void pdch3c2fou
( bea3vlgt1r * obj ) ; static void jujpi1rajl ( hq0hb5wdla * obj , a14pojzgfk
* iobj_0 ) { hq0hb5wdla * obj_p ; grfhvm5tpf varSizes ; a14pojzgfk * iobj_0_p
; int32_T i ; obj -> isSetupComplete = false ; obj -> isInitialized = 1 ;
obj_p = obj ; varSizes . f1 [ 0 ] = 1U ; varSizes . f1 [ 1 ] = 1U ; for ( i =
0 ; i < 6 ; i ++ ) { varSizes . f1 [ i + 2 ] = 1U ; } obj_p -> inputVarSize =
varSizes ; obj_p = obj ; iobj_0_p = iobj_0 ; obj_p -> NumChannels = 1 ;
iobj_0_p -> isInitialized = 0 ; obj_p -> pStat = iobj_0_p ; iobj_0_p = obj_p
-> pStat ; iobj_0_p -> isSetupComplete = false ; iobj_0_p -> isInitialized =
1 ; iobj_0_p -> isSetupComplete = true ; obj -> isSetupComplete = true ; }
static void mqbwh1nkpv ( hq0hb5wdla * obj ) { hq0hb5wdla * obj_p ; a14pojzgfk
* obj_e ; if ( obj -> isInitialized == 1 ) { obj_p = obj ; if ( obj_p ->
isSetupComplete ) { obj_p -> NumChannels = - 1 ; obj_e = obj_p -> pStat ; if
( obj_e -> isInitialized == 1 ) { obj_e -> isInitialized = 2 ; } } } } static
void o4quze3mjf ( hq0hb5wdla * obj ) { mqbwh1nkpv ( obj ) ; } static void
evqdthrrjp ( hq0hb5wdla * obj ) { if ( ! obj -> matlabCodegenIsDeleted ) {
obj -> matlabCodegenIsDeleted = true ; o4quze3mjf ( obj ) ; } } void
hulq2q2v4t ( oehzpt04yr * localDW ) { hq0hb5wdla * obj ; a14pojzgfk * obj_p ;
int32_T i ; obj = & localDW -> bgtbyci3g4 ; obj_p = obj -> pStat ; if ( obj_p
-> isInitialized == 1 ) { for ( i = 0 ; i < 200 ; i ++ ) { obj_p -> pBuffer [
i ] = 0.0 ; } for ( i = 0 ; i < 200 ; i ++ ) { obj_p -> pBufferIdx [ i ] = 0
; } obj_p -> pNumElements = 0 ; obj_p -> pCount = 1 ; obj_p -> pTop = 1 ; } }
void asxel4khfi ( oehzpt04yr * localDW ) { a14pojzgfk * iobj_0 ; hq0hb5wdla *
b_obj ; localDW -> bgtbyci3g4 . matlabCodegenIsDeleted = true ; iobj_0 = &
localDW -> ohlmpp21yt ; b_obj = & localDW -> bgtbyci3g4 ; b_obj ->
isInitialized = 0 ; b_obj -> NumChannels = - 1 ; b_obj ->
matlabCodegenIsDeleted = false ; localDW -> oo5zsud5tm = true ; jujpi1rajl (
& localDW -> bgtbyci3g4 , iobj_0 ) ; } void nrszotctkr ( real_T jdv1xek1e2 ,
l3csy1qexn * localB , oehzpt04yr * localDW ) { hq0hb5wdla * obj ; hq0hb5wdla
* obj_p ; real_T k ; a14pojzgfk * obj_e ; a14pojzgfk * obj_i ; real_T buf [
200 ] ; int32_T bufIdx [ 200 ] ; int32_T numElements ; int32_T cnt ; int32_T
top ; int32_T winLen ; int32_T placement ; int32_T ind_vect [ 200 ] ; int32_T
N ; int32_T count ; int32_T indVal ; boolean_T cond ; int32_T b_ind ;
a14pojzgfk * obj_m ; int32_T i ; boolean_T exitg1 ; obj = & localDW ->
bgtbyci3g4 ; obj_p = obj ; numElements = 0 ; exitg1 = false ; while ( ( !
exitg1 ) && ( numElements < 8 ) ) { k = ( real_T ) numElements + 1.0 ; if (
obj_p -> inputVarSize . f1 [ ( int32_T ) k - 1 ] != 1U ) { for ( placement =
0 ; placement < 8 ; placement ++ ) { obj_p -> inputVarSize . f1 [ placement ]
= 1U ; } exitg1 = true ; } else { numElements ++ ; } } obj_e = obj -> pStat ;
if ( obj_e -> isInitialized != 1 ) { obj_i = obj_e ; obj_m = obj_i ; obj_m ->
isSetupComplete = false ; obj_m -> isInitialized = 1 ; obj_m ->
isSetupComplete = true ; for ( i = 0 ; i < 200 ; i ++ ) { obj_i -> pBuffer [
i ] = 0.0 ; } for ( i = 0 ; i < 200 ; i ++ ) { obj_i -> pBufferIdx [ i ] = 0
; } obj_i -> pNumElements = 0 ; obj_i -> pCount = 1 ; obj_i -> pTop = 1 ; }
for ( i = 0 ; i < 200 ; i ++ ) { buf [ i ] = obj_e -> pBuffer [ i ] ; } for (
i = 0 ; i < 200 ; i ++ ) { bufIdx [ i ] = obj_e -> pBufferIdx [ i ] ; }
numElements = obj_e -> pNumElements ; cnt = obj_e -> pCount ; top = obj_e ->
pTop ; if ( numElements > 0 ) { i = bufIdx [ top - 1 ] ; if ( ( cnt >= 0 ) &&
( i < cnt - MAX_int32_T ) ) { i = MAX_int32_T ; } else if ( ( cnt < 0 ) && (
i > cnt - MIN_int32_T ) ) { i = MIN_int32_T ; } else { i = cnt - i ; } if ( i
== 200 ) { if ( top > 2147483646 ) { top = MAX_int32_T ; } else { top ++ ; }
if ( top > 200 ) { top = 1 ; } numElements -- ; } } if ( ( numElements < 0 )
&& ( top < MIN_int32_T - numElements ) ) { i = MIN_int32_T ; } else if ( (
numElements > 0 ) && ( top > MAX_int32_T - numElements ) ) { i = MAX_int32_T
; } else { i = numElements + top ; } if ( i < - 2147483647 ) { placement =
MIN_int32_T ; } else { placement = i - 1 ; } if ( placement >= 200 ) {
placement -= 200 ; } i = placement + 1 ; placement = i - 1 ; memset ( &
ind_vect [ 0 ] , 0 , 200U * sizeof ( int32_T ) ) ; N = numElements ; if (
numElements > 0 ) { count = 1 ; i = numElements - 1 ; if ( i >= 0 ) { if (
top < - 2147483647 ) { winLen = MIN_int32_T ; } else { winLen = top - 1 ; } }
for ( b_ind = i ; b_ind >= 0 ; b_ind -- ) { if ( ( winLen < 0 ) && ( b_ind <
MIN_int32_T - winLen ) ) { indVal = MIN_int32_T ; } else if ( ( winLen > 0 )
&& ( b_ind > MAX_int32_T - winLen ) ) { indVal = MAX_int32_T ; } else {
indVal = winLen + b_ind ; } if ( indVal >= 200 ) { indVal -= 200 ; } indVal
++ ; ind_vect [ count - 1 ] = indVal ; if ( count > 2147483646 ) { count =
MAX_int32_T ; } else { count ++ ; } } winLen = 1 ; exitg1 = false ; while ( (
! exitg1 ) && ( winLen - 1 <= numElements - 1 ) ) { count = winLen - 1 ;
count = ind_vect [ count ] ; k = buf [ count - 1 ] ; cond = ( jdv1xek1e2 < k
) ; if ( cond ) { exitg1 = true ; } else { placement = count - 1 ; if ( N < -
2147483647 ) { N = MIN_int32_T ; } else { N -- ; } winLen ++ ; } } } buf [
placement ] = jdv1xek1e2 ; bufIdx [ placement ] = cnt ; if ( N > 2147483646 )
{ numElements = MAX_int32_T ; } else { numElements = N + 1 ; } k = buf [ top
- 1 ] ; if ( cnt > 2147483646 ) { cnt = MAX_int32_T ; } else { cnt ++ ; } if
( cnt > 1000000 ) { cnt -= 1000000 ; for ( placement = 0 ; placement < 200 ;
placement ++ ) { i = bufIdx [ placement ] ; if ( i < - 2146483648 ) { i =
MIN_int32_T ; } else { i -= 1000000 ; } bufIdx [ placement ] = i ; } } for (
i = 0 ; i < 200 ; i ++ ) { obj_e -> pBuffer [ i ] = buf [ i ] ; } for ( i = 0
; i < 200 ; i ++ ) { obj_e -> pBufferIdx [ i ] = bufIdx [ i ] ; } obj_e ->
pNumElements = numElements ; obj_e -> pCount = cnt ; obj_e -> pTop = top ;
localB -> gm53zhdnh5 = k ; } void nkktcwoggm ( oehzpt04yr * localDW ) {
evqdthrrjp ( & localDW -> bgtbyci3g4 ) ; } static void cwqfrbtfhu2 (
izdonajra3 * obj , nznsmjv5o1 * iobj_0 ) { izdonajra3 * obj_p ; grfhvm5tpf
varSizes ; nznsmjv5o1 * iobj_0_p ; int32_T i ; obj -> isSetupComplete = false
; obj -> isInitialized = 1 ; obj_p = obj ; varSizes . f1 [ 0 ] = 1U ;
varSizes . f1 [ 1 ] = 1U ; for ( i = 0 ; i < 6 ; i ++ ) { varSizes . f1 [ i +
2 ] = 1U ; } obj_p -> inputVarSize = varSizes ; obj_p = obj ; iobj_0_p =
iobj_0 ; obj_p -> NumChannels = 1 ; iobj_0_p -> isInitialized = 0 ; obj_p ->
pStat = iobj_0_p ; iobj_0_p = obj_p -> pStat ; iobj_0_p -> isSetupComplete =
false ; iobj_0_p -> isInitialized = 1 ; iobj_0_p -> isSetupComplete = true ;
obj -> isSetupComplete = true ; } static void cwqfrbtfhu ( bea3vlgt1r * obj ,
eae4ors1vz * iobj_0 ) { bea3vlgt1r * obj_p ; grfhvm5tpf varSizes ; eae4ors1vz
* iobj_0_p ; int32_T i ; obj -> isSetupComplete = false ; obj ->
isInitialized = 1 ; obj_p = obj ; varSizes . f1 [ 0 ] = 1U ; varSizes . f1 [
1 ] = 1U ; for ( i = 0 ; i < 6 ; i ++ ) { varSizes . f1 [ i + 2 ] = 1U ; }
obj_p -> inputVarSize = varSizes ; obj_p = obj ; iobj_0_p = iobj_0 ; obj_p ->
NumChannels = 1 ; iobj_0_p -> isInitialized = 0 ; obj_p -> pStat = iobj_0_p ;
iobj_0_p = obj_p -> pStat ; iobj_0_p -> isSetupComplete = false ; iobj_0_p ->
isInitialized = 1 ; iobj_0_p -> isSetupComplete = true ; obj ->
isSetupComplete = true ; } static real_T i425xztlhw ( eae4ors1vz * obj ,
real_T x ) { real_T m ; real_T buf [ 500 ] ; int32_T bufIdx [ 500 ] ; int32_T
numElements ; int32_T cnt ; int32_T top ; int32_T winLen ; int32_T placement
; int32_T ind_vect [ 500 ] ; int32_T N ; int32_T count ; int32_T indVal ;
boolean_T cond ; int32_T b_ind ; real_T y ; int32_T qY ; boolean_T exitg1 ;
memcpy ( & buf [ 0 ] , & obj -> pBuffer [ 0 ] , 500U * sizeof ( real_T ) ) ;
memcpy ( & bufIdx [ 0 ] , & obj -> pBufferIdx [ 0 ] , 500U * sizeof ( int32_T
) ) ; numElements = obj -> pNumElements ; cnt = obj -> pCount ; top = obj ->
pTop ; if ( numElements > 0 ) { winLen = bufIdx [ top - 1 ] ; if ( ( cnt >= 0
) && ( winLen < cnt - MAX_int32_T ) ) { winLen = MAX_int32_T ; } else if ( (
cnt < 0 ) && ( winLen > cnt - MIN_int32_T ) ) { winLen = MIN_int32_T ; } else
{ winLen = cnt - winLen ; } if ( winLen == 500 ) { if ( top > 2147483646 ) {
top = MAX_int32_T ; } else { top ++ ; } if ( top > 500 ) { top = 1 ; }
numElements -- ; } } if ( ( numElements < 0 ) && ( top < MIN_int32_T -
numElements ) ) { winLen = MIN_int32_T ; } else if ( ( numElements > 0 ) && (
top > MAX_int32_T - numElements ) ) { winLen = MAX_int32_T ; } else { winLen
= numElements + top ; } if ( winLen < - 2147483647 ) { placement =
MIN_int32_T ; } else { placement = winLen - 1 ; } if ( placement >= 500 ) {
placement -= 500 ; } winLen = placement + 1 ; placement = winLen - 1 ; memset
( & ind_vect [ 0 ] , 0 , 500U * sizeof ( int32_T ) ) ; N = numElements ; if (
numElements > 0 ) { count = 1 ; winLen = numElements - 1 ; if ( winLen >= 0 )
{ if ( top < - 2147483647 ) { qY = MIN_int32_T ; } else { qY = top - 1 ; } }
for ( b_ind = winLen ; b_ind >= 0 ; b_ind -- ) { if ( ( qY < 0 ) && ( b_ind <
MIN_int32_T - qY ) ) { indVal = MIN_int32_T ; } else if ( ( qY > 0 ) && (
b_ind > MAX_int32_T - qY ) ) { indVal = MAX_int32_T ; } else { indVal = qY +
b_ind ; } if ( indVal >= 500 ) { indVal -= 500 ; } indVal ++ ; ind_vect [
count - 1 ] = indVal ; if ( count > 2147483646 ) { count = MAX_int32_T ; }
else { count ++ ; } } winLen = 1 ; exitg1 = false ; while ( ( ! exitg1 ) && (
winLen - 1 <= numElements - 1 ) ) { count = winLen - 1 ; count = ind_vect [
count ] ; y = buf [ count - 1 ] ; cond = ( x > y ) ; if ( cond ) { exitg1 =
true ; } else { placement = count - 1 ; if ( N < - 2147483647 ) { N =
MIN_int32_T ; } else { N -- ; } winLen ++ ; } } } buf [ placement ] = x ;
bufIdx [ placement ] = cnt ; if ( N > 2147483646 ) { numElements =
MAX_int32_T ; } else { numElements = N + 1 ; } m = buf [ top - 1 ] ; if ( cnt
> 2147483646 ) { cnt = MAX_int32_T ; } else { cnt ++ ; } if ( cnt > 1000000 )
{ cnt -= 1000000 ; for ( placement = 0 ; placement < 500 ; placement ++ ) {
winLen = bufIdx [ placement ] ; if ( winLen < - 2146483648 ) { winLen =
MIN_int32_T ; } else { winLen -= 1000000 ; } bufIdx [ placement ] = winLen ;
} } memcpy ( & obj -> pBuffer [ 0 ] , & buf [ 0 ] , 500U * sizeof ( real_T )
) ; memcpy ( & obj -> pBufferIdx [ 0 ] , & bufIdx [ 0 ] , 500U * sizeof (
int32_T ) ) ; obj -> pNumElements = numElements ; obj -> pCount = cnt ; obj
-> pTop = top ; return m ; } static void nao4kbgvx5s ( izdonajra3 * obj ) {
izdonajra3 * obj_p ; nznsmjv5o1 * obj_e ; if ( obj -> isInitialized == 1 ) {
obj_p = obj ; if ( obj_p -> isSetupComplete ) { obj_p -> NumChannels = - 1 ;
obj_e = obj_p -> pStat ; if ( obj_e -> isInitialized == 1 ) { obj_e ->
isInitialized = 2 ; } } } } static void j4x44qh4llo ( izdonajra3 * obj ) {
nao4kbgvx5s ( obj ) ; } static void pdch3c2fouu ( izdonajra3 * obj ) { if ( !
obj -> matlabCodegenIsDeleted ) { obj -> matlabCodegenIsDeleted = true ;
j4x44qh4llo ( obj ) ; } } static void nao4kbgvx5 ( bea3vlgt1r * obj ) {
bea3vlgt1r * obj_p ; eae4ors1vz * obj_e ; if ( obj -> isInitialized == 1 ) {
obj_p = obj ; if ( obj_p -> isSetupComplete ) { obj_p -> NumChannels = - 1 ;
obj_e = obj_p -> pStat ; if ( obj_e -> isInitialized == 1 ) { obj_e ->
isInitialized = 2 ; } } } } static void j4x44qh4ll ( bea3vlgt1r * obj ) {
nao4kbgvx5 ( obj ) ; } static void pdch3c2fou ( bea3vlgt1r * obj ) { if ( !
obj -> matlabCodegenIsDeleted ) { obj -> matlabCodegenIsDeleted = true ;
j4x44qh4ll ( obj ) ; } } void MdlInitialize ( void ) { izdonajra3 * obj ;
nznsmjv5o1 * obj_p ; bea3vlgt1r * obj_e ; eae4ors1vz * obj_i ; int32_T i ; if
( ssIsFirstInitCond ( rtS ) ) { rtX . kkiibctlhi = 0.0 ; } rtDW . bptbpmlejv
= 1 ; rtX . lfbgx15nj4 = rtP . Integrator_IC ; rtDW . o0ozn4wrlb = rtP .
Difference_ICPrevInput ; rtX . alyxv0p4jq = rtP . Integrator1_IC ; rtX .
k3tsvpgpqo = rtP . Integrator2_IC ; obj = & rtDW . dhfsjbleur ; obj_p = obj
-> pStat ; if ( obj_p -> isInitialized == 1 ) { obj_p -> pBuffer [ 0 ] = 0.0
; obj_p -> pBuffer [ 1 ] = 0.0 ; obj_p -> pBuffer [ 2 ] = 0.0 ; obj_p ->
pBuffer [ 3 ] = 0.0 ; obj_p -> pBufferIdx [ 0 ] = 0 ; obj_p -> pBufferIdx [ 1
] = 0 ; obj_p -> pBufferIdx [ 2 ] = 0 ; obj_p -> pBufferIdx [ 3 ] = 0 ; obj_p
-> pNumElements = 0 ; obj_p -> pCount = 1 ; obj_p -> pTop = 1 ; } obj_e = &
rtDW . pjhwxlxh5o ; obj_i = obj_e -> pStat ; if ( obj_i -> isInitialized == 1
) { for ( i = 0 ; i < 500 ; i ++ ) { obj_i -> pBuffer [ i ] = 0.0 ; } for ( i
= 0 ; i < 500 ; i ++ ) { obj_i -> pBufferIdx [ i ] = 0 ; } obj_i ->
pNumElements = 0 ; obj_i -> pCount = 1 ; obj_i -> pTop = 1 ; } hulq2q2v4t ( &
rtDW . pzjd3kuy5m ) ; hulq2q2v4t ( & rtDW . jdbr35ed4p ) ; hulq2q2v4t ( &
rtDW . fpf3fqle5c ) ; hulq2q2v4t ( & rtDW . nrszotctkrz ) ; } void MdlStart (
void ) { nznsmjv5o1 * iobj_0 ; izdonajra3 * b_obj ; eae4ors1vz * iobj_0_p ;
bea3vlgt1r * b_obj_p ; { void * * slioCatalogueAddr = rt_slioCatalogueAddr (
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
externalInputIsInDatasetFormat ) { } } rtB . jtpferclbe = rtP . init_position
; rtDW . dhfsjbleur . matlabCodegenIsDeleted = true ; iobj_0 = & rtDW .
l4wnyi14fe ; b_obj = & rtDW . dhfsjbleur ; b_obj -> isInitialized = 0 ; b_obj
-> NumChannels = - 1 ; b_obj -> matlabCodegenIsDeleted = false ; rtDW .
gvs4eonwop = true ; cwqfrbtfhu2 ( & rtDW . dhfsjbleur , iobj_0 ) ; rtDW .
pjhwxlxh5o . matlabCodegenIsDeleted = true ; iobj_0_p = & rtDW . anxd5wnwwf ;
b_obj_p = & rtDW . pjhwxlxh5o ; b_obj_p -> isInitialized = 0 ; b_obj_p ->
NumChannels = - 1 ; b_obj_p -> matlabCodegenIsDeleted = false ; rtDW .
h53kbocvrf = true ; cwqfrbtfhu ( & rtDW . pjhwxlxh5o , iobj_0_p ) ;
asxel4khfi ( & rtDW . pzjd3kuy5m ) ; asxel4khfi ( & rtDW . jdbr35ed4p ) ;
asxel4khfi ( & rtDW . fpf3fqle5c ) ; asxel4khfi ( & rtDW . nrszotctkrz ) ;
MdlInitialize ( ) ; } void MdlOutputs ( int_T tid ) { real_T x [ 4 ] ; real_T
xtmp ; real_T r ; izdonajra3 * obj ; izdonajra3 * obj_p ; nznsmjv5o1 * obj_e
; nznsmjv5o1 * obj_i ; real_T buf [ 4 ] ; int32_T bufIdx [ 4 ] ; int32_T
numElements ; int32_T cnt ; int32_T top ; int32_T winLen ; int32_T placement
; int32_T ind_vect [ 4 ] ; int32_T N ; int32_T count ; int32_T indVal ;
boolean_T cond ; int32_T b_ind ; nznsmjv5o1 * obj_m ; bea3vlgt1r * obj_g ;
bea3vlgt1r * obj_j ; eae4ors1vz * obj_f ; eae4ors1vz * obj_c ; eae4ors1vz *
obj_k ; int32_T qY ; boolean_T exitg1 ; int32_T exitg2 ; if ( rtDW .
bptbpmlejv != 0 ) { rtX . kkiibctlhi = rtB . jtpferclbe ; } rtB . kcyp21kc2a
= rtX . kkiibctlhi ; xtmp = rtB . kcyp21kc2a ; obj = & rtDW . dhfsjbleur ;
obj_p = obj ; numElements = 0 ; exitg1 = false ; while ( ( ! exitg1 ) && (
numElements < 8 ) ) { r = ( real_T ) numElements + 1.0 ; if ( obj_p ->
inputVarSize . f1 [ ( int32_T ) r - 1 ] != 1U ) { for ( numElements = 0 ;
numElements < 8 ; numElements ++ ) { obj_p -> inputVarSize . f1 [ numElements
] = 1U ; } exitg1 = true ; } else { numElements ++ ; } } obj_e = obj -> pStat
; if ( obj_e -> isInitialized != 1 ) { obj_i = obj_e ; obj_m = obj_i ; obj_m
-> isSetupComplete = false ; obj_m -> isInitialized = 1 ; obj_m ->
isSetupComplete = true ; obj_i -> pBuffer [ 0 ] = 0.0 ; obj_i -> pBuffer [ 1
] = 0.0 ; obj_i -> pBuffer [ 2 ] = 0.0 ; obj_i -> pBuffer [ 3 ] = 0.0 ; obj_i
-> pBufferIdx [ 0 ] = 0 ; obj_i -> pBufferIdx [ 1 ] = 0 ; obj_i -> pBufferIdx
[ 2 ] = 0 ; obj_i -> pBufferIdx [ 3 ] = 0 ; obj_i -> pNumElements = 0 ; obj_i
-> pCount = 1 ; obj_i -> pTop = 1 ; } buf [ 0 ] = obj_e -> pBuffer [ 0 ] ;
buf [ 1 ] = obj_e -> pBuffer [ 1 ] ; buf [ 2 ] = obj_e -> pBuffer [ 2 ] ; buf
[ 3 ] = obj_e -> pBuffer [ 3 ] ; bufIdx [ 0 ] = obj_e -> pBufferIdx [ 0 ] ;
bufIdx [ 1 ] = obj_e -> pBufferIdx [ 1 ] ; bufIdx [ 2 ] = obj_e -> pBufferIdx
[ 2 ] ; bufIdx [ 3 ] = obj_e -> pBufferIdx [ 3 ] ; numElements = obj_e ->
pNumElements ; cnt = obj_e -> pCount ; top = obj_e -> pTop ; if ( numElements
> 0 ) { placement = bufIdx [ top - 1 ] ; if ( ( cnt >= 0 ) && ( placement <
cnt - MAX_int32_T ) ) { qY = MAX_int32_T ; } else if ( ( cnt < 0 ) && (
placement > cnt - MIN_int32_T ) ) { qY = MIN_int32_T ; } else { qY = cnt -
placement ; } if ( qY == 4 ) { if ( top > 2147483646 ) { top = MAX_int32_T ;
} else { top ++ ; } if ( top > 4 ) { top = 1 ; } numElements -- ; } } if ( (
numElements < 0 ) && ( top < MIN_int32_T - numElements ) ) { qY = MIN_int32_T
; } else if ( ( numElements > 0 ) && ( top > MAX_int32_T - numElements ) ) {
qY = MAX_int32_T ; } else { qY = numElements + top ; } if ( qY < - 2147483647
) { placement = MIN_int32_T ; } else { placement = qY - 1 ; } if ( placement
>= 4 ) { placement -= 4 ; } qY = placement + 1 ; placement = qY - 1 ;
ind_vect [ 0 ] = 0 ; ind_vect [ 1 ] = 0 ; ind_vect [ 2 ] = 0 ; ind_vect [ 3 ]
= 0 ; N = numElements ; if ( numElements > 0 ) { count = 1 ; qY = numElements
- 1 ; if ( qY >= 0 ) { if ( top < - 2147483647 ) { winLen = MIN_int32_T ; }
else { winLen = top - 1 ; } } for ( b_ind = qY ; b_ind >= 0 ; b_ind -- ) { if
( ( winLen < 0 ) && ( b_ind < MIN_int32_T - winLen ) ) { indVal = MIN_int32_T
; } else if ( ( winLen > 0 ) && ( b_ind > MAX_int32_T - winLen ) ) { indVal =
MAX_int32_T ; } else { indVal = winLen + b_ind ; } if ( indVal >= 4 ) {
indVal -= 4 ; } indVal ++ ; ind_vect [ count - 1 ] = indVal ; if ( count >
2147483646 ) { count = MAX_int32_T ; } else { count ++ ; } } winLen = 1 ;
exitg1 = false ; while ( ( ! exitg1 ) && ( winLen - 1 <= numElements - 1 ) )
{ count = winLen - 1 ; count = ind_vect [ count ] ; r = buf [ count - 1 ] ;
cond = ( xtmp < r ) ; if ( cond ) { exitg1 = true ; } else { placement =
count - 1 ; if ( N < - 2147483647 ) { N = MIN_int32_T ; } else { N -- ; }
winLen ++ ; } } } buf [ placement ] = xtmp ; bufIdx [ placement ] = cnt ; if
( N > 2147483646 ) { numElements = MAX_int32_T ; } else { numElements = N + 1
; } r = buf [ top - 1 ] ; if ( cnt > 2147483646 ) { cnt = MAX_int32_T ; }
else { cnt ++ ; } if ( cnt > 1000000 ) { cnt -= 1000000 ; qY = bufIdx [ 0 ] ;
if ( qY < - 2146483648 ) { qY = MIN_int32_T ; } else { qY -= 1000000 ; }
bufIdx [ 0 ] = qY ; qY = bufIdx [ 1 ] ; if ( qY < - 2146483648 ) { qY =
MIN_int32_T ; } else { qY -= 1000000 ; } bufIdx [ 1 ] = qY ; qY = bufIdx [ 2
] ; if ( qY < - 2146483648 ) { qY = MIN_int32_T ; } else { qY -= 1000000 ; }
bufIdx [ 2 ] = qY ; qY = bufIdx [ 3 ] ; if ( qY < - 2146483648 ) { qY =
MIN_int32_T ; } else { qY -= 1000000 ; } bufIdx [ 3 ] = qY ; } obj_e ->
pBuffer [ 0 ] = buf [ 0 ] ; obj_e -> pBuffer [ 1 ] = buf [ 1 ] ; obj_e ->
pBuffer [ 2 ] = buf [ 2 ] ; obj_e -> pBuffer [ 3 ] = buf [ 3 ] ; obj_e ->
pBufferIdx [ 0 ] = bufIdx [ 0 ] ; obj_e -> pBufferIdx [ 1 ] = bufIdx [ 1 ] ;
obj_e -> pBufferIdx [ 2 ] = bufIdx [ 2 ] ; obj_e -> pBufferIdx [ 3 ] = bufIdx
[ 3 ] ; obj_e -> pNumElements = numElements ; obj_e -> pCount = cnt ; obj_e
-> pTop = top ; rtB . iazliuf4fr = r ; rtB . dj31gbg42s = rtB . iazliuf4fr /
rtB . f4spskjtp4 ; rtB . pr5iwe4db4 = rtX . lfbgx15nj4 ; rtB . jgw3cnihqn =
ssGetT ( rtS ) ; if ( rtB . jgw3cnihqn > rtP . Switch_Threshold ) { rtB .
jpfgqre33f = rtB . pr5iwe4db4 / rtB . jgw3cnihqn ; rtB . bvtrmm42qq = rtB .
jpfgqre33f ; } else { rtB . bvtrmm42qq = rtP . Constant_Value_ehkhiuseje ; }
rtB . ft1lwiplkf = ssGetT ( rtS ) ; xtmp = 0.25 * rtP . env_route_length ;
rtB . a0vhvlfvrp [ 0 ] = rtB . kcyp21kc2a - rtB . dm0n54sbqj [ 0 ] ; rtB .
klvou0jp43 [ 0 ] = muDoubleScalarAbs ( rtB . a0vhvlfvrp [ 0 ] ) ; rtB .
dhdvnfqewh [ 0 ] = ( rtB . jmn33aahhq [ 0 ] <= rtB . ft1lwiplkf ) ; rtB .
erbdt202km [ 0 ] = ( rtB . ft1lwiplkf <= rtB . l3gkhpvljt [ 0 ] ) ; rtB .
ntvdgb201d [ 0 ] = ( rtB . dhdvnfqewh [ 0 ] && rtB . erbdt202km [ 0 ] ) ; if
( rtB . ntvdgb201d [ 0 ] ) { rtB . nuq4ebgzji [ 0 ] = rtP . Constant_Value ;
} else { rtB . nuq4ebgzji [ 0 ] = rtP . no1_Value ; } if ( rtB . nuq4ebgzji [
0 ] > rtP . Switch2_Threshold ) { rtB . foohqlhzxj [ 0 ] = rtB . klvou0jp43 [
0 ] ; } else { rtB . foohqlhzxj [ 0 ] = xtmp ; } rtB . a0vhvlfvrp [ 1 ] = rtB
. kcyp21kc2a - rtB . dm0n54sbqj [ 1 ] ; rtB . klvou0jp43 [ 1 ] =
muDoubleScalarAbs ( rtB . a0vhvlfvrp [ 1 ] ) ; rtB . dhdvnfqewh [ 1 ] = ( rtB
. jmn33aahhq [ 1 ] <= rtB . ft1lwiplkf ) ; rtB . erbdt202km [ 1 ] = ( rtB .
ft1lwiplkf <= rtB . l3gkhpvljt [ 1 ] ) ; rtB . ntvdgb201d [ 1 ] = ( rtB .
dhdvnfqewh [ 1 ] && rtB . erbdt202km [ 1 ] ) ; if ( rtB . ntvdgb201d [ 1 ] )
{ rtB . nuq4ebgzji [ 1 ] = rtP . Constant_Value ; } else { rtB . nuq4ebgzji [
1 ] = rtP . no1_Value ; } if ( rtB . nuq4ebgzji [ 1 ] > rtP .
Switch2_Threshold ) { rtB . foohqlhzxj [ 1 ] = rtB . klvou0jp43 [ 1 ] ; }
else { rtB . foohqlhzxj [ 1 ] = xtmp ; } if ( ( rtB . foohqlhzxj [ 0 ] > rtB
. foohqlhzxj [ 1 ] ) || ( muDoubleScalarIsNaN ( rtB . foohqlhzxj [ 0 ] ) && (
! muDoubleScalarIsNaN ( rtB . foohqlhzxj [ 1 ] ) ) ) ) { rtB . brmok2vfn0 =
rtB . foohqlhzxj [ 1 ] ; } else { rtB . brmok2vfn0 = rtB . foohqlhzxj [ 0 ] ;
} xtmp = rtB . brmok2vfn0 ; obj_g = & rtDW . pjhwxlxh5o ; obj_j = obj_g ;
numElements = 0 ; exitg1 = false ; while ( ( ! exitg1 ) && ( numElements < 8
) ) { r = ( real_T ) numElements + 1.0 ; if ( obj_j -> inputVarSize . f1 [ (
int32_T ) r - 1 ] != 1U ) { for ( numElements = 0 ; numElements < 8 ;
numElements ++ ) { obj_j -> inputVarSize . f1 [ numElements ] = 1U ; } exitg1
= true ; } else { numElements ++ ; } } obj_f = obj_g -> pStat ; if ( obj_f ->
isInitialized != 1 ) { obj_c = obj_f ; obj_k = obj_c ; obj_k ->
isSetupComplete = false ; obj_k -> isInitialized = 1 ; obj_k ->
isSetupComplete = true ; for ( numElements = 0 ; numElements < 500 ;
numElements ++ ) { obj_c -> pBuffer [ numElements ] = 0.0 ; } for (
numElements = 0 ; numElements < 500 ; numElements ++ ) { obj_c -> pBufferIdx
[ numElements ] = 0 ; } obj_c -> pNumElements = 0 ; obj_c -> pCount = 1 ;
obj_c -> pTop = 1 ; } r = i425xztlhw ( obj_f , xtmp ) ; rtB . edohkr2wul = r
; rtB . jyapjnygey = ssGetT ( rtS ) ; buf [ 0 ] = rtP . vel [ 4 ] ; x [ 0 ] =
rtP . vel [ 0 ] ; buf [ 1 ] = rtP . vel [ 5 ] ; x [ 1 ] = rtP . vel [ 1 ] ;
buf [ 2 ] = rtP . vel [ 6 ] ; x [ 2 ] = rtP . vel [ 2 ] ; buf [ 3 ] = rtP .
vel [ 7 ] ; x [ 3 ] = rtP . vel [ 3 ] ; r = ( rtNaN ) ; numElements = 0 ; do
{ exitg2 = 0 ; if ( numElements < 4 ) { if ( muDoubleScalarIsNaN ( rtP . vel
[ numElements ] ) ) { exitg2 = 1 ; } else { numElements ++ ; } } else { if (
rtP . vel [ 1 ] < rtP . vel [ 0 ] ) { xtmp = x [ 0 ] ; x [ 0 ] = x [ 3 ] ; x
[ 3 ] = xtmp ; xtmp = x [ 1 ] ; x [ 1 ] = x [ 2 ] ; x [ 2 ] = xtmp ; xtmp =
buf [ 0 ] ; buf [ 0 ] = buf [ 3 ] ; buf [ 3 ] = xtmp ; xtmp = buf [ 1 ] ; buf
[ 1 ] = buf [ 2 ] ; buf [ 2 ] = xtmp ; } if ( ( ! muDoubleScalarIsNaN ( rtB .
jyapjnygey ) ) && ( ! ( rtB . jyapjnygey > x [ 3 ] ) ) && ( ! ( rtB .
jyapjnygey < x [ 0 ] ) ) ) { numElements = 1 ; cnt = 2 ; top = 4 ; while (
top > cnt ) { placement = ( numElements + top ) >> 1 ; if ( rtB . jyapjnygey
>= x [ placement - 1 ] ) { numElements = placement ; cnt = placement + 1 ; }
else { top = placement ; } } r = ( rtB . jyapjnygey - x [ numElements - 1 ] )
/ ( x [ numElements ] - x [ numElements - 1 ] ) ; if ( r == 0.0 ) { r = buf [
numElements - 1 ] ; } else if ( r == 1.0 ) { r = buf [ numElements ] ; } else
if ( buf [ numElements - 1 ] == buf [ numElements ] ) { r = buf [ numElements
- 1 ] ; } else { r = ( 1.0 - r ) * buf [ numElements - 1 ] + r * buf [
numElements ] ; } } exitg2 = 1 ; } } while ( exitg2 == 0 ) ; rtB . m2q0pua4hf
= r ; rtB . hbw1yihztg = rtB . m2q0pua4hf * rtP . reaction_time_Value ; rtB .
cwg0hry4ws = rtB . m2q0pua4hf * rtB . m2q0pua4hf ; rtB . prpccjcehp = ssGetT
( rtS ) ; rtB . oj4ir132kn = rtB . o2zt0cwv3s - rtB . prpccjcehp ; if ( rtB .
oj4ir132kn > rtP . Switch_Threshold_hglhrydy3y ) { rtB . dhkufhyeyq = rtB .
craf4qjftk ; } else { rtB . dhkufhyeyq = rtB . odv2qhzlqg ; } rtB .
eodzgtkr5j = rtB . dhkufhyeyq * rtP . g ; rtB . dvlei2dmhh = rtP . Gain_Gain
* rtB . eodzgtkr5j ; rtB . e5a31ttfny = rtB . cwg0hry4ws / rtB . dvlei2dmhh ;
rtB . olssxob2yv = rtB . hbw1yihztg + rtB . e5a31ttfny ; nrszotctkr ( rtB .
olssxob2yv , & rtB . pzjd3kuy5m , & rtDW . pzjd3kuy5m ) ; if ( ssIsSampleHit
( rtS , 1 , 0 ) ) { rtB . bk43fv2n4y = rtDW . o0ozn4wrlb ; rtB . nge5jnvtgx =
rtB . m2q0pua4hf - rtB . bk43fv2n4y ; rtB . o2croyjuf1 = ( rtB . nge5jnvtgx
>= rtP . Constant1_Value ) ; rtB . hxqshrzbjb = ( rtB . nge5jnvtgx < rtP .
Constant3_Value ) ; } rtB . ntwseknv4g = ( rtB . m2q0pua4hf >= rtP .
Constant_Value_kyz3xktxbl ) ; rtB . jwq1epnjmp = ( rtB . o2croyjuf1 && rtB .
ntwseknv4g ) ; rtB . erl53vzxd3 = ( rtB . m2q0pua4hf < rtP . Constant2_Value
) ; rtB . fisvgzk5zv = ( rtB . hxqshrzbjb && rtB . erl53vzxd3 ) ; rtB .
nlloggg0bk = ( rtB . jwq1epnjmp || rtB . fisvgzk5zv ) ; if ( rtB . nlloggg0bk
) { rtB . ixl2ngyssb = rtB . nge5jnvtgx * rtB . m2q0pua4hf ; rtB . irfhmm4oof
= rtB . ixl2ngyssb ; } else { rtB . irfhmm4oof = rtP . Constant4_Value ; }
nrszotctkr ( rtB . irfhmm4oof , & rtB . jdbr35ed4p , & rtDW . jdbr35ed4p ) ;
rtB . f5lt2gautr = rtX . alyxv0p4jq ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) {
rtB . ixalepcbyn = rtB . nge5jnvtgx / rtP . g ; rtB . lz2vzowa3c =
muDoubleScalarAbs ( rtB . ixalepcbyn ) ; } rtB . h3xadqth0r = rtB .
lz2vzowa3c - rtB . dhkufhyeyq ; nrszotctkr ( rtB . h3xadqth0r , & rtB .
fpf3fqle5c , & rtDW . fpf3fqle5c ) ; rtB . a5ewqn2mxx = muDoubleScalarPower (
rtB . m2q0pua4hf , rtP . Constant_Value_jqzxbewhqx ) ; rtB . lvxqtzvles =
muDoubleScalarAbs ( rtB . a5ewqn2mxx ) ; nrszotctkr ( rtB . lvxqtzvles , &
rtB . nrszotctkrz , & rtDW . nrszotctkrz ) ; rtB . hlq1tatw2c = rtX .
k3tsvpgpqo ; rtY . c5nklccwze [ 0 ] = rtB . dj31gbg42s ; rtY . c5nklccwze [ 1
] = rtB . bvtrmm42qq ; rtY . c5nklccwze [ 2 ] = rtB . edohkr2wul ; rtY .
c5nklccwze [ 3 ] = rtB . pzjd3kuy5m . gm53zhdnh5 ; rtY . c5nklccwze [ 4 ] =
rtB . jdbr35ed4p . gm53zhdnh5 ; rtY . c5nklccwze [ 5 ] = rtB . f5lt2gautr ;
rtY . c5nklccwze [ 6 ] = rtB . fpf3fqle5c . gm53zhdnh5 ; rtY . c5nklccwze [ 7
] = rtB . m2q0pua4hf ; rtY . c5nklccwze [ 8 ] = rtB . nrszotctkrz .
gm53zhdnh5 ; rtY . c5nklccwze [ 9 ] = rtB . hlq1tatw2c ; rtY . jdublxckra [ 0
] = rtB . nge5jnvtgx ; rtY . jdublxckra [ 1 ] = rtB . m2q0pua4hf ; rtY .
jdublxckra [ 2 ] = rtB . kcyp21kc2a ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) {
} rtB . ojsxt052dx = ssGetT ( rtS ) ; rtB . hydn0gjndu [ 0 ] = rtB .
jmn33aahhq [ 0 ] - rtB . ojsxt052dx ; rtB . comw5ylrlx [ 0 ] = ( rtB .
ojsxt052dx <= rtB . jmn33aahhq [ 0 ] ) ; rtB . j5mv5pspvc [ 0 ] = ( 0.0 - rtB
. hydn0gjndu [ 0 ] ) - rtB . biki50erxe [ 0 ] ; if ( rtB . comw5ylrlx [ 0 ] )
{ rtB . egn3zic0pm [ 0 ] = rtB . hydn0gjndu [ 0 ] ; } else { rtB . egn3zic0pm
[ 0 ] = rtB . j5mv5pspvc [ 0 ] ; } rtB . hydn0gjndu [ 1 ] = rtB . jmn33aahhq
[ 1 ] - rtB . ojsxt052dx ; rtB . comw5ylrlx [ 1 ] = ( rtB . ojsxt052dx <= rtB
. jmn33aahhq [ 1 ] ) ; rtB . j5mv5pspvc [ 1 ] = ( 0.0 - rtB . hydn0gjndu [ 1
] ) - rtB . biki50erxe [ 1 ] ; if ( rtB . comw5ylrlx [ 1 ] ) { rtB .
egn3zic0pm [ 1 ] = rtB . hydn0gjndu [ 1 ] ; } else { rtB . egn3zic0pm [ 1 ] =
rtB . j5mv5pspvc [ 1 ] ; } rtB . jbd0xdvrsq = ssGetT ( rtS ) ; rtB .
j4s3bqbxd4 = rtB . o2zt0cwv3s - rtB . jbd0xdvrsq ; rtB . dage4kxeup = ssGetT
( rtS ) ; rtB . na4hrtuuyw = rtB . dage4kxeup - rtB . o2zt0cwv3s ; if ( rtB .
na4hrtuuyw > rtP . Switch1_Threshold ) { rtB . d1jelb2eui = rtP . yes_Value ;
} else { rtB . d1jelb2eui = rtP . no_Value ; } if ( ssIsSampleHit ( rtS , 1 ,
0 ) ) { } rtB . ece5hhfx4x = ( rtB . hqjcuxu5y0 [ 0 ] <= rtB . kcyp21kc2a ) ;
rtB . dpka2uzame = ( rtB . kcyp21kc2a <= rtB . hqjcuxu5y0 [ 1 ] ) ; rtB .
jhgjsl1qel = ( rtB . ece5hhfx4x && rtB . dpka2uzame ) ; if ( rtB . jhgjsl1qel
) { rtB . ovxbrcsfmz = rtP . Constant_Value_oxokqz1erg ; } else { rtB .
ovxbrcsfmz = rtP . no_Value_eq3lkpaxhu ; } UNUSED_PARAMETER ( tid ) ; } void
MdlOutputsTID2 ( int_T tid ) { rtB . odv2qhzlqg = rtP . env_mu_s_wet ; rtB .
f4spskjtp4 = rtP . env_route_length ; rtB . o2zt0cwv3s = rtP .
env_t_rain_start ; rtB . craf4qjftk = rtP . env_mu_s_dry ; rtB . ifpg5v2co4 =
rtP . duration ; rtB . jtpferclbe = rtP . init_position ; rtB . biki50erxe [
0 ] = rtP . env_traffic_durations [ 0 ] ; rtB . c5fwmfh314 [ 0 ] = rtP .
env_traffic_pos [ 0 ] ; rtB . jmn33aahhq [ 0 ] = rtP . env_traffic_times [ 0
] ; rtB . czhyu2bg0k [ 0 ] = rtP . env_forest [ 0 ] ; rtB . hqjcuxu5y0 [ 0 ]
= rtB . czhyu2bg0k [ 0 ] * rtB . f4spskjtp4 ; rtB . dm0n54sbqj [ 0 ] = rtB .
c5fwmfh314 [ 0 ] * rtB . f4spskjtp4 ; rtB . l3gkhpvljt [ 0 ] = rtB .
jmn33aahhq [ 0 ] + rtB . biki50erxe [ 0 ] ; rtB . biki50erxe [ 1 ] = rtP .
env_traffic_durations [ 1 ] ; rtB . c5fwmfh314 [ 1 ] = rtP . env_traffic_pos
[ 1 ] ; rtB . jmn33aahhq [ 1 ] = rtP . env_traffic_times [ 1 ] ; rtB .
czhyu2bg0k [ 1 ] = rtP . env_forest [ 1 ] ; rtB . hqjcuxu5y0 [ 1 ] = rtB .
czhyu2bg0k [ 1 ] * rtB . f4spskjtp4 ; rtB . dm0n54sbqj [ 1 ] = rtB .
c5fwmfh314 [ 1 ] * rtB . f4spskjtp4 ; rtB . l3gkhpvljt [ 1 ] = rtB .
jmn33aahhq [ 1 ] + rtB . biki50erxe [ 1 ] ; UNUSED_PARAMETER ( tid ) ; } void
MdlUpdate ( int_T tid ) { rtDW . bptbpmlejv = 0 ; if ( ssIsSampleHit ( rtS ,
1 , 0 ) ) { rtDW . o0ozn4wrlb = rtB . m2q0pua4hf ; } UNUSED_PARAMETER ( tid )
; } void MdlUpdateTID2 ( int_T tid ) { UNUSED_PARAMETER ( tid ) ; } void
MdlDerivatives ( void ) { XDot * _rtXdot ; _rtXdot = ( ( XDot * ) ssGetdX (
rtS ) ) ; _rtXdot -> kkiibctlhi = rtB . m2q0pua4hf ; _rtXdot -> lfbgx15nj4 =
rtB . ovxbrcsfmz ; _rtXdot -> alyxv0p4jq = rtB . irfhmm4oof ; _rtXdot ->
k3tsvpgpqo = rtB . lvxqtzvles ; } void MdlProjection ( void ) { } void
MdlTerminate ( void ) { pdch3c2fouu ( & rtDW . dhfsjbleur ) ; pdch3c2fou ( &
rtDW . pjhwxlxh5o ) ; nkktcwoggm ( & rtDW . pzjd3kuy5m ) ; nkktcwoggm ( &
rtDW . jdbr35ed4p ) ; nkktcwoggm ( & rtDW . fpf3fqle5c ) ; nkktcwoggm ( &
rtDW . nrszotctkrz ) ; if ( rt_slioCatalogue ( ) != ( NULL ) ) { void * *
slioCatalogueAddr = rt_slioCatalogueAddr ( ) ; rtwSaveDatasetsToMatFile (
rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) ,
rt_GetMatSigstreamLoggingFileName ( ) ) ; rtwTerminateSlioCatalogue (
slioCatalogueAddr ) ; * slioCatalogueAddr = NULL ; } } void
MdlInitializeSizes ( void ) { ssSetNumContStates ( rtS , 4 ) ;
ssSetNumPeriodicContStates ( rtS , 0 ) ; ssSetNumY ( rtS , 13 ) ; ssSetNumU (
rtS , 0 ) ; ssSetDirectFeedThrough ( rtS , 0 ) ; ssSetNumSampleTimes ( rtS ,
2 ) ; ssSetNumBlocks ( rtS , 108 ) ; ssSetNumBlockIO ( rtS , 77 ) ;
ssSetNumBlockParams ( rtS , 46 ) ; } void MdlInitializeSampleTimes ( void ) {
ssSetSampleTime ( rtS , 0 , 0.0 ) ; ssSetSampleTime ( rtS , 1 , 4.0 ) ;
ssSetOffsetTime ( rtS , 0 , 0.0 ) ; ssSetOffsetTime ( rtS , 1 , 0.0 ) ; }
void raccel_set_checksum ( ) { ssSetChecksumVal ( rtS , 0 , 2815083295U ) ;
ssSetChecksumVal ( rtS , 1 , 69055812U ) ; ssSetChecksumVal ( rtS , 2 ,
3976536213U ) ; ssSetChecksumVal ( rtS , 3 , 588105720U ) ; }
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
( B ) ) ; } { ssSetY ( rtS , & rtY ) ; ( void ) memset ( ( void * ) & rtY , 0
, sizeof ( ExtY ) ) ; } { real_T * x = ( real_T * ) & rtX ; ssSetContStates (
rtS , x ) ; ( void ) memset ( ( void * ) x , 0 , sizeof ( X ) ) ; } { void *
dwork = ( void * ) & rtDW ; ssSetRootDWork ( rtS , dwork ) ; ( void ) memset
( dwork , 0 , sizeof ( DW ) ) ; } { static DataTypeTransInfo dtInfo ; ( void
) memset ( ( char_T * ) & dtInfo , 0 , sizeof ( dtInfo ) ) ;
ssSetModelMappingInfo ( rtS , & dtInfo ) ; dtInfo . numDataTypes = 20 ;
dtInfo . dataTypeSizes = & rtDataTypeSizes [ 0 ] ; dtInfo . dataTypeNames = &
rtDataTypeNames [ 0 ] ; dtInfo . BTransTable = & rtBTransTable ; dtInfo .
PTransTable = & rtPTransTable ; dtInfo . dataTypeInfoTable =
rtDataTypeInfoTable ; } rs_bicycle2_InitializeDataMapInfo ( ) ;
ssSetIsRapidAcceleratorActive ( rtS , true ) ; ssSetRootSS ( rtS , rtS ) ;
ssSetVersion ( rtS , SIMSTRUCT_VERSION_LEVEL2 ) ; ssSetModelName ( rtS ,
"rs_bicycle2" ) ; ssSetPath ( rtS , "rs_bicycle2" ) ; ssSetTStart ( rtS , 0.0
) ; ssSetTFinal ( rtS , 200.0 ) ; ssSetStepSize ( rtS , 4.0 ) ;
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
"rs_bicycle2/Integrator" ,
"rs_bicycle2/aux2: Fraction Spent In Forest/Integrator" ,
"rs_bicycle2/Integrator1" , "rs_bicycle2/Integrator2" ,
"rs_bicycle2/Difference/UD" } ; static const char_T * rt_LoggedStateNames [ ]
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
) ; rt_LoggedStateSignalPtrs [ 0 ] = ( void * ) & rtX . kkiibctlhi ;
rt_LoggedStateSignalPtrs [ 1 ] = ( void * ) & rtX . lfbgx15nj4 ;
rt_LoggedStateSignalPtrs [ 2 ] = ( void * ) & rtX . alyxv0p4jq ;
rt_LoggedStateSignalPtrs [ 3 ] = ( void * ) & rtX . k3tsvpgpqo ;
rt_LoggedStateSignalPtrs [ 4 ] = ( void * ) & rtDW . o0ozn4wrlb ; }
rtliSetLogT ( ssGetRTWLogInfo ( rtS ) , "tout" ) ; rtliSetLogX (
ssGetRTWLogInfo ( rtS ) , "tmp_raccel_xout" ) ; rtliSetLogXFinal (
ssGetRTWLogInfo ( rtS ) , "xFinal" ) ; rtliSetLogVarNameModifier (
ssGetRTWLogInfo ( rtS ) , "none" ) ; rtliSetLogFormat ( ssGetRTWLogInfo ( rtS
) , 2 ) ; rtliSetLogMaxRows ( ssGetRTWLogInfo ( rtS ) , 0 ) ;
rtliSetLogDecimation ( ssGetRTWLogInfo ( rtS ) , 1 ) ; { static void *
rt_LoggedOutputSignalPtrs [ ] = { & rtY . c5nklccwze [ 0 ] , & rtY .
jdublxckra [ 0 ] } ; rtliSetLogYSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( (
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
rt_LoggedOutputBlockNames_0 [ ] = { "rs_bicycle2/F" } ; static const char_T *
rt_LoggedOutputLabels_1 [ ] = { "S" } ; static const char_T *
rt_LoggedOutputBlockNames_1 [ ] = { "rs_bicycle2/S" } ; static
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
contStatesDisabled ) ; } ssSetChecksumVal ( rtS , 0 , 2815083295U ) ;
ssSetChecksumVal ( rtS , 1 , 69055812U ) ; ssSetChecksumVal ( rtS , 2 ,
3976536213U ) ; ssSetChecksumVal ( rtS , 3 , 588105720U ) ; { static const
sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE ; static RTWExtModeInfo
rt_ExtModeInfo ; static const sysRanDType * systemRan [ 11 ] ;
gblRTWExtModeInfo = & rt_ExtModeInfo ; ssSetRTWExtModeInfo ( rtS , &
rt_ExtModeInfo ) ; rteiSetSubSystemActiveVectorAddresses ( & rt_ExtModeInfo ,
systemRan ) ; systemRan [ 0 ] = & rtAlwaysEnabled ; systemRan [ 1 ] = &
rtAlwaysEnabled ; systemRan [ 2 ] = & rtAlwaysEnabled ; systemRan [ 3 ] = &
rtAlwaysEnabled ; systemRan [ 4 ] = & rtAlwaysEnabled ; systemRan [ 5 ] = &
rtAlwaysEnabled ; systemRan [ 6 ] = & rtAlwaysEnabled ; systemRan [ 7 ] = &
rtAlwaysEnabled ; systemRan [ 8 ] = & rtAlwaysEnabled ; systemRan [ 9 ] = &
rtAlwaysEnabled ; systemRan [ 10 ] = & rtAlwaysEnabled ;
rteiSetModelMappingInfoPtr ( ssGetRTWExtModeInfo ( rtS ) , &
ssGetModelMappingInfo ( rtS ) ) ; rteiSetChecksumsPtr ( ssGetRTWExtModeInfo (
rtS ) , ssGetChecksums ( rtS ) ) ; rteiSetTPtr ( ssGetRTWExtModeInfo ( rtS )
, ssGetTPtr ( rtS ) ) ; } return rtS ; }
#if defined(_MSC_VER)
#pragma optimize( "", on )
#endif
const int_T gblParameterTuningTid = 2 ; void MdlOutputsParameterSampleTime (
int_T tid ) { MdlOutputsTID2 ( tid ) ; }
