#include "__cf_attitude3d.h"
#include "rt_logging_mmi.h"
#include "attitude3d_capi.h"
#include <math.h>
#include "attitude3d.h"
#include "attitude3d_private.h"
#include "attitude3d_dt.h"
extern void * CreateDiagnosticAsVoidPtr_wrapper ( const char * id , int nargs
, ... ) ; RTWExtModeInfo * gblRTWExtModeInfo = NULL ; extern boolean_T
gblExtModeStartPktReceived ; void raccelForceExtModeShutdown ( ) { if ( !
gblExtModeStartPktReceived ) { boolean_T stopRequested = false ;
rtExtModeWaitForStartPkt ( gblRTWExtModeInfo , 2 , & stopRequested ) ; }
rtExtModeShutdown ( 2 ) ; }
#include "slsv_diagnostic_codegen_c_api.h"
const int_T gblNumToFiles = 0 ; const int_T gblNumFrFiles = 1 ; const int_T
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
"slprj//raccel//attitude3d//attitude3d_Jpattern.mat" ; const int_T
gblNumRootInportBlks = 1 ; const int_T gblNumModelInputs = 3 ; extern
rtInportTUtable * gblInportTUtables ; extern const char * gblInportFileName ;
extern void * gblAperiodicPartitionHitTimes ; const int_T
gblInportDataTypeIdx [ ] = { 0 } ; const int_T gblInportDims [ ] = { 3 , 1 }
; const int_T gblInportComplex [ ] = { 0 } ; const int_T gblInportInterpoFlag
[ ] = { 1 } ; const int_T gblInportContinuous [ ] = { 1 } ; int_T
enableFcnCallFlag [ ] = { 1 , 1 , 1 } ; const char *
raccelLoadInputsAndAperiodicHitTimes ( const char * inportFileName , int *
matFileFormat ) { return rt_RapidReadInportsMatFile ( inportFileName ,
matFileFormat , 1 ) ; } FrFInfo attitude3d_gblFrFInfo [ 1 ] ;
#include "simstruc.h"
#include "fixedpoint.h"
B rtB ; X rtX ; DW rtDW ; ExtU rtU ; static SimStruct model_S ; SimStruct *
const rtS = & model_S ; static void mbauvq4dny ( oiijeexccd * obj ,
it1m1m5jgb * iobj_0 ) ; static void fvnxjlohfw ( oiijeexccd * obj ) ; static
void kmijkao54m ( oiijeexccd * obj ) ; static void cidvp450rp ( oiijeexccd *
obj ) ; static void mbauvq4dnyb ( hkrvp5gzcl * obj , j510l0uc1d * iobj_0 ) ;
static void fvnxjlohfwh ( hkrvp5gzcl * obj ) ; static void kmijkao54mn (
hkrvp5gzcl * obj ) ; static void cidvp450rpy ( hkrvp5gzcl * obj ) ; static
void mbauvq4dny ( oiijeexccd * obj , it1m1m5jgb * iobj_0 ) { epls3zpd4h
varSizes ; it1m1m5jgb * obj_p ; int32_T i ; obj -> isSetupComplete = false ;
obj -> isInitialized = 1 ; varSizes . f1 [ 0 ] = 1U ; varSizes . f1 [ 1 ] =
1U ; for ( i = 0 ; i < 6 ; i ++ ) { varSizes . f1 [ i + 2 ] = 1U ; } obj ->
inputVarSize = varSizes ; obj -> NumChannels = 1 ; iobj_0 -> isInitialized =
0 ; obj -> pStat = iobj_0 ; obj_p = obj -> pStat ; obj_p -> isSetupComplete =
false ; obj_p -> isInitialized = 1 ; obj_p -> pCumMin = ( rtInf ) ; obj_p ->
isSetupComplete = true ; obj -> isSetupComplete = true ; } static void
fvnxjlohfw ( oiijeexccd * obj ) { it1m1m5jgb * obj_p ; if ( ( obj ->
isInitialized == 1 ) && obj -> isSetupComplete ) { obj -> NumChannels = - 1 ;
obj_p = obj -> pStat ; if ( obj_p -> isInitialized == 1 ) { obj_p ->
isInitialized = 2 ; } } } static void kmijkao54m ( oiijeexccd * obj ) {
fvnxjlohfw ( obj ) ; } static void cidvp450rp ( oiijeexccd * obj ) { if ( !
obj -> matlabCodegenIsDeleted ) { obj -> matlabCodegenIsDeleted = true ;
kmijkao54m ( obj ) ; } } void esdot54nug ( pqlrpaqdev * localDW ) {
it1m1m5jgb * obj ; obj = localDW -> bdmeifvj0g . pStat ; if ( obj ->
isInitialized == 1 ) { obj -> pCumMin = ( rtInf ) ; } } void ekt4d0juw0 (
pqlrpaqdev * localDW ) { localDW -> bdmeifvj0g . matlabCodegenIsDeleted =
true ; localDW -> bdmeifvj0g . isInitialized = 0 ; localDW -> bdmeifvj0g .
NumChannels = - 1 ; localDW -> bdmeifvj0g . matlabCodegenIsDeleted = false ;
localDW -> phxfrbtrrv = true ; mbauvq4dny ( & localDW -> bdmeifvj0g , &
localDW -> kfvrm3e5fw ) ; } void fbz1lrgadk ( real_T okfdlrvjbv , lhr0fwp232
* localB , pqlrpaqdev * localDW ) { int32_T b_k ; it1m1m5jgb * obj ; real_T
y_idx_1 ; boolean_T exitg1 ; b_k = 0 ; exitg1 = false ; while ( ( ! exitg1 )
&& ( b_k < 8 ) ) { if ( localDW -> bdmeifvj0g . inputVarSize . f1 [ b_k ] !=
1U ) { for ( b_k = 0 ; b_k < 8 ; b_k ++ ) { localDW -> bdmeifvj0g .
inputVarSize . f1 [ b_k ] = 1U ; } exitg1 = true ; } else { b_k ++ ; } } obj
= localDW -> bdmeifvj0g . pStat ; if ( obj -> isInitialized != 1 ) { obj ->
isSetupComplete = false ; obj -> isInitialized = 1 ; obj -> pCumMin = ( rtInf
) ; obj -> isSetupComplete = true ; obj -> pCumMin = ( rtInf ) ; } y_idx_1 =
obj -> pCumMin ; y_idx_1 = muDoubleScalarMin ( y_idx_1 , okfdlrvjbv ) ; obj
-> pCumMin = y_idx_1 ; localB -> olimizud5z = y_idx_1 ; } void ftsgw51zjp (
pqlrpaqdev * localDW ) { cidvp450rp ( & localDW -> bdmeifvj0g ) ; } static
void mbauvq4dnyb ( hkrvp5gzcl * obj , j510l0uc1d * iobj_0 ) { epls3zpd4h
varSizes ; j510l0uc1d * obj_p ; int32_T i ; obj -> isSetupComplete = false ;
obj -> isInitialized = 1 ; varSizes . f1 [ 0 ] = 1U ; varSizes . f1 [ 1 ] =
1U ; for ( i = 0 ; i < 6 ; i ++ ) { varSizes . f1 [ i + 2 ] = 1U ; } obj ->
inputVarSize = varSizes ; obj -> NumChannels = 1 ; iobj_0 -> isInitialized =
0 ; obj -> pStat = iobj_0 ; obj_p = obj -> pStat ; obj_p -> isSetupComplete =
false ; obj_p -> isInitialized = 1 ; obj_p -> pCumMax = ( rtMinusInf ) ;
obj_p -> isSetupComplete = true ; obj -> isSetupComplete = true ; } static
void fvnxjlohfwh ( hkrvp5gzcl * obj ) { j510l0uc1d * obj_p ; if ( ( obj ->
isInitialized == 1 ) && obj -> isSetupComplete ) { obj -> NumChannels = - 1 ;
obj_p = obj -> pStat ; if ( obj_p -> isInitialized == 1 ) { obj_p ->
isInitialized = 2 ; } } } static void kmijkao54mn ( hkrvp5gzcl * obj ) {
fvnxjlohfwh ( obj ) ; } static void cidvp450rpy ( hkrvp5gzcl * obj ) { if ( !
obj -> matlabCodegenIsDeleted ) { obj -> matlabCodegenIsDeleted = true ;
kmijkao54mn ( obj ) ; } } void a2gsmdpwl3 ( abmczhmvhh * localDW ) {
j510l0uc1d * obj ; obj = localDW -> jsyeqj31fa . pStat ; if ( obj ->
isInitialized == 1 ) { obj -> pCumMax = ( rtMinusInf ) ; } } void bqfcltg4dy
( abmczhmvhh * localDW ) { localDW -> jsyeqj31fa . matlabCodegenIsDeleted =
true ; localDW -> jsyeqj31fa . isInitialized = 0 ; localDW -> jsyeqj31fa .
NumChannels = - 1 ; localDW -> jsyeqj31fa . matlabCodegenIsDeleted = false ;
localDW -> d1vg1xnbad = true ; mbauvq4dnyb ( & localDW -> jsyeqj31fa , &
localDW -> aivxxmxdyh ) ; } void juzdrgfwyw ( real_T okfdlrvjbv , oolcbzau2s
* localB , abmczhmvhh * localDW ) { int32_T b_k ; j510l0uc1d * obj ; real_T
y_idx_1 ; boolean_T exitg1 ; b_k = 0 ; exitg1 = false ; while ( ( ! exitg1 )
&& ( b_k < 8 ) ) { if ( localDW -> jsyeqj31fa . inputVarSize . f1 [ b_k ] !=
1U ) { for ( b_k = 0 ; b_k < 8 ; b_k ++ ) { localDW -> jsyeqj31fa .
inputVarSize . f1 [ b_k ] = 1U ; } exitg1 = true ; } else { b_k ++ ; } } obj
= localDW -> jsyeqj31fa . pStat ; if ( obj -> isInitialized != 1 ) { obj ->
isSetupComplete = false ; obj -> isInitialized = 1 ; obj -> pCumMax = (
rtMinusInf ) ; obj -> isSetupComplete = true ; obj -> pCumMax = ( rtMinusInf
) ; } y_idx_1 = obj -> pCumMax ; y_idx_1 = muDoubleScalarMax ( y_idx_1 ,
okfdlrvjbv ) ; obj -> pCumMax = y_idx_1 ; localB -> ezrshmdyuk = y_idx_1 ; }
void onxlpkziey ( abmczhmvhh * localDW ) { cidvp450rpy ( & localDW ->
jsyeqj31fa ) ; } void MdlInitialize ( void ) { int32_T i ; if (
ssIsFirstInitCond ( rtS ) ) { rtX . kvd5s5mhzq [ 0 ] = 0.0 ; rtX . kvd5s5mhzq
[ 1 ] = 0.0 ; rtX . kvd5s5mhzq [ 2 ] = 0.0 ; rtX . kvd5s5mhzq [ 3 ] = 0.0 ; }
rtDW . ag2rcaep41 = 1 ; for ( i = 0 ; i < 59 ; i ++ ) { rtDW . nrt1u3ug04 [ i
] = rtP . DiscreteFIRFilter_InitialStates ; rtDW . nn3mukf4ls [ i ] = rtP .
DiscreteFIRFilter_InitialStates_igm30wm5ib ; } rtX . oznfot3xd2 = rtP .
Integrator1_IC ; rtX . gi0dbsjbab = rtP . Integrator1_IC_khgln1fz0y ; rtX .
ndr0ddj14l = rtP . Integrator2_IC ; rtX . f5kva1vvha = rtP .
Integrator1_IC_bdymfb0f54 ; esdot54nug ( & rtDW . fbz1lrgadk1 ) ; esdot54nug
( & rtDW . fbz1lrgadk1o ) ; a2gsmdpwl3 ( & rtDW . juzdrgfwywb ) ; a2gsmdpwl3
( & rtDW . juzdrgfwywbn ) ; } void MdlStart ( void ) { { void * *
slioCatalogueAddr = rt_slioCatalogueAddr ( ) ; void * r2 = ( NULL ) ; void *
* pOSigstreamManagerAddr = ( NULL ) ; const int maxErrorBufferSize = 16384 ;
char errMsgCreatingOSigstreamManager [ 16384 ] ; bool
errorCreatingOSigstreamManager = false ; const char *
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
pISigstreamManager , 0 , & rtU . bhvfzp4veb [ 0 ] ) ; } } { char fileName [
509 ] = "ENVIRONMENT.mat" ; const char * blockpath = "attitude3d/From File13"
; if ( slIsRapidAcceleratorSimulating ( ) ) { rt_RAccelReplaceFromFilename (
blockpath , fileName ) ; } { void * fp = ( NULL ) ; const char * errMsg = (
NULL ) ; errMsg = rtwMatFileLoaderCollectionCreateInstance ( 1 , & fp ) ; if
( errMsg != ( NULL ) ) { ssSetErrorStatus ( rtS , errMsg ) ; return ; } rtDW
. p5wpguxq2t . PrevTimePtr = fp ; { unsigned char groundValue [ ] = { 0U , 0U
, 0U , 0U , 0U , 0U , 0U , 0U } ; const int enumNStrings = 0 ; const char * *
enumStrings = ( NULL ) ; const int32_T * enumValues = ( NULL ) ; int_T
dimensions [ 1 ] = { 3 } ; errMsg = rtwMatFileLoaderCollectionAddElement ( 1
, fp , fileName , ".thrust_vector" , 0 , 0 , 0 , 0 , groundValue , "double" ,
0 , 1 , dimensions , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , enumNStrings ,
enumStrings , enumValues , 1 , 1 , "attitude3d/From File13" ) ; if ( errMsg
!= ( NULL ) ) { ssSetErrorStatus ( rtS , errMsg ) ; return ; } } { unsigned
char groundValue [ ] = { 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U } ; const int
enumNStrings = 0 ; const char * * enumStrings = ( NULL ) ; const int32_T *
enumValues = ( NULL ) ; int_T dimensions [ 1 ] = { 1 } ; errMsg =
rtwMatFileLoaderCollectionAddElement ( 1 , fp , fileName , ".thrust_weight" ,
0 , 0 , 0 , 0 , groundValue , "double" , 0 , 1 , dimensions , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 , enumNStrings , enumStrings , enumValues , 1 , 1 ,
"attitude3d/From File13" ) ; if ( errMsg != ( NULL ) ) { ssSetErrorStatus (
rtS , errMsg ) ; return ; } } { unsigned char groundValue [ ] = { 0U , 0U ,
0U , 0U , 0U , 0U , 0U , 0U } ; const int enumNStrings = 0 ; const char * *
enumStrings = ( NULL ) ; const int32_T * enumValues = ( NULL ) ; int_T
dimensions [ 1 ] = { 1 } ; errMsg = rtwMatFileLoaderCollectionAddElement ( 1
, fp , fileName , ".solar_occulted_integral" , 0 , 0 , 0 , 0 , groundValue ,
"double" , 0 , 1 , dimensions , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , enumNStrings
, enumStrings , enumValues , 1 , 1 , "attitude3d/From File13" ) ; if ( errMsg
!= ( NULL ) ) { ssSetErrorStatus ( rtS , errMsg ) ; return ; } } { unsigned
char groundValue [ ] = { 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U } ; const int
enumNStrings = 0 ; const char * * enumStrings = ( NULL ) ; const int32_T *
enumValues = ( NULL ) ; int_T dimensions [ 1 ] = { 1 } ; errMsg =
rtwMatFileLoaderCollectionAddElement ( 1 , fp , fileName ,
".solar_occulted_boolean" , 0 , 0 , 0 , 0 , groundValue , "double" , 0 , 1 ,
dimensions , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , enumNStrings , enumStrings ,
enumValues , 1 , 1 , "attitude3d/From File13" ) ; if ( errMsg != ( NULL ) ) {
ssSetErrorStatus ( rtS , errMsg ) ; return ; } } { unsigned char groundValue
[ ] = { 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U } ; const int enumNStrings = 0
; const char * * enumStrings = ( NULL ) ; const int32_T * enumValues = ( NULL
) ; int_T dimensions [ 1 ] = { 3 } ; errMsg =
rtwMatFileLoaderCollectionAddElement ( 1 , fp , fileName , ".solar_vector" ,
0 , 0 , 0 , 0 , groundValue , "double" , 0 , 1 , dimensions , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 , enumNStrings , enumStrings , enumValues , 1 , 1 ,
"attitude3d/From File13" ) ; if ( errMsg != ( NULL ) ) { ssSetErrorStatus (
rtS , errMsg ) ; return ; } } { unsigned char groundValue [ ] = { 0U , 0U ,
0U , 0U , 0U , 0U , 0U , 0U } ; const int enumNStrings = 0 ; const char * *
enumStrings = ( NULL ) ; const int32_T * enumValues = ( NULL ) ; int_T
dimensions [ 1 ] = { 1 } ; errMsg = rtwMatFileLoaderCollectionAddElement ( 1
, fp , fileName , ".comms_occulted_integral" , 0 , 0 , 0 , 0 , groundValue ,
"double" , 0 , 1 , dimensions , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , enumNStrings
, enumStrings , enumValues , 1 , 1 , "attitude3d/From File13" ) ; if ( errMsg
!= ( NULL ) ) { ssSetErrorStatus ( rtS , errMsg ) ; return ; } } { unsigned
char groundValue [ ] = { 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U } ; const int
enumNStrings = 0 ; const char * * enumStrings = ( NULL ) ; const int32_T *
enumValues = ( NULL ) ; int_T dimensions [ 1 ] = { 1 } ; errMsg =
rtwMatFileLoaderCollectionAddElement ( 1 , fp , fileName ,
".comms_occulted_boolean" , 0 , 0 , 0 , 0 , groundValue , "double" , 0 , 1 ,
dimensions , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , enumNStrings , enumStrings ,
enumValues , 1 , 1 , "attitude3d/From File13" ) ; if ( errMsg != ( NULL ) ) {
ssSetErrorStatus ( rtS , errMsg ) ; return ; } } { unsigned char groundValue
[ ] = { 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U } ; const int enumNStrings = 0
; const char * * enumStrings = ( NULL ) ; const int32_T * enumValues = ( NULL
) ; int_T dimensions [ 1 ] = { 3 } ; errMsg =
rtwMatFileLoaderCollectionAddElement ( 1 , fp , fileName , ".comms_vector" ,
0 , 0 , 0 , 0 , groundValue , "double" , 0 , 1 , dimensions , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 , enumNStrings , enumStrings , enumValues , 1 , 1 ,
"attitude3d/From File13" ) ; if ( errMsg != ( NULL ) ) { ssSetErrorStatus (
rtS , errMsg ) ; return ; } } { unsigned char groundValue [ ] = { 0U , 0U ,
0U , 0U , 0U , 0U , 0U , 0U } ; const int enumNStrings = 0 ; const char * *
enumStrings = ( NULL ) ; const int32_T * enumValues = ( NULL ) ; int_T
dimensions [ 1 ] = { 3 } ; errMsg = rtwMatFileLoaderCollectionAddElement ( 1
, fp , fileName , ".r_s" , 0 , 0 , 0 , 0 , groundValue , "double" , 0 , 1 ,
dimensions , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , enumNStrings , enumStrings ,
enumValues , 1 , 1 , "attitude3d/From File13" ) ; if ( errMsg != ( NULL ) ) {
ssSetErrorStatus ( rtS , errMsg ) ; return ; } } { unsigned char groundValue
[ ] = { 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U } ; const int enumNStrings = 0
; const char * * enumStrings = ( NULL ) ; const int32_T * enumValues = ( NULL
) ; int_T dimensions [ 1 ] = { 3 } ; errMsg =
rtwMatFileLoaderCollectionAddElement ( 1 , fp , fileName , ".v_s" , 0 , 0 , 0
, 0 , groundValue , "double" , 0 , 1 , dimensions , 0 , 0 , 0 , 0 , 0 , 0 , 0
, 0 , enumNStrings , enumStrings , enumValues , 1 , 1 ,
"attitude3d/From File13" ) ; if ( errMsg != ( NULL ) ) { ssSetErrorStatus (
rtS , errMsg ) ; return ; } } { unsigned char groundValue [ ] = { 0U , 0U ,
0U , 0U , 0U , 0U , 0U , 0U } ; const int enumNStrings = 0 ; const char * *
enumStrings = ( NULL ) ; const int32_T * enumValues = ( NULL ) ; int_T
dimensions [ 1 ] = { 3 } ; errMsg = rtwMatFileLoaderCollectionAddElement ( 1
, fp , fileName , ".r_c" , 0 , 0 , 0 , 0 , groundValue , "double" , 0 , 1 ,
dimensions , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , enumNStrings , enumStrings ,
enumValues , 1 , 1 , "attitude3d/From File13" ) ; if ( errMsg != ( NULL ) ) {
ssSetErrorStatus ( rtS , errMsg ) ; return ; } } { unsigned char groundValue
[ ] = { 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U } ; const int enumNStrings = 0
; const char * * enumStrings = ( NULL ) ; const int32_T * enumValues = ( NULL
) ; int_T dimensions [ 1 ] = { 3 } ; errMsg =
rtwMatFileLoaderCollectionAddElement ( 1 , fp , fileName , ".v_c" , 0 , 0 , 0
, 0 , groundValue , "double" , 0 , 1 , dimensions , 0 , 0 , 0 , 0 , 0 , 0 , 0
, 0 , enumNStrings , enumStrings , enumValues , 1 , 1 ,
"attitude3d/From File13" ) ; if ( errMsg != ( NULL ) ) { ssSetErrorStatus (
rtS , errMsg ) ; return ; } } { unsigned char groundValue [ ] = { 0U , 0U ,
0U , 0U , 0U , 0U , 0U , 0U } ; const int enumNStrings = 0 ; const char * *
enumStrings = ( NULL ) ; const int32_T * enumValues = ( NULL ) ; int_T
dimensions [ 1 ] = { 3 } ; errMsg = rtwMatFileLoaderCollectionAddElement ( 1
, fp , fileName , ".r_t" , 0 , 0 , 0 , 0 , groundValue , "double" , 0 , 1 ,
dimensions , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , enumNStrings , enumStrings ,
enumValues , 1 , 1 , "attitude3d/From File13" ) ; if ( errMsg != ( NULL ) ) {
ssSetErrorStatus ( rtS , errMsg ) ; return ; } } { unsigned char groundValue
[ ] = { 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U } ; const int enumNStrings = 0
; const char * * enumStrings = ( NULL ) ; const int32_T * enumValues = ( NULL
) ; int_T dimensions [ 1 ] = { 3 } ; errMsg =
rtwMatFileLoaderCollectionAddElement ( 1 , fp , fileName , ".v_t" , 0 , 0 , 0
, 0 , groundValue , "double" , 0 , 1 , dimensions , 0 , 0 , 0 , 0 , 0 , 0 , 0
, 0 , enumNStrings , enumStrings , enumValues , 1 , 1 ,
"attitude3d/From File13" ) ; if ( errMsg != ( NULL ) ) { ssSetErrorStatus (
rtS , errMsg ) ; return ; } } } } ekt4d0juw0 ( & rtDW . fbz1lrgadk1 ) ;
ekt4d0juw0 ( & rtDW . fbz1lrgadk1o ) ; bqfcltg4dy ( & rtDW . juzdrgfwywb ) ;
bqfcltg4dy ( & rtDW . juzdrgfwywbn ) ; MdlInitialize ( ) ; } void MdlOutputs
( int_T tid ) { real_T po5evibzby ; real_T f4vnhc3tuh ; real_T A [ 4 ] ;
int32_T idx ; int32_T k ; real_T scale ; real_T hu15wb2s0u ; real_T
o2311hs4bm ; real_T moeghwuxxr ; real_T oufzjameo0_idx_2 ; real_T
aujhvgokqy_idx_0 ; real_T aujhvgokqy_idx_2 ; real_T cizfy4cb2f_idx_0 ; real_T
cizfy4cb2f_idx_2 ; real_T cizfy4cb2f_idx_1 ; real_T jt3hs0aizl_idx_0 ; real_T
jt3hs0aizl_idx_1 ; real_T jt3hs0aizl_idx_2 ; boolean_T exitg1 ; if (
gblInportFileName != ( NULL ) ) { bool externalInputIsInDatasetFormat = false
; void * pISigstreamManager = rt_GetISigstreamManager ( ) ;
rtwISigstreamManagerGetInputIsInDatasetFormat ( pISigstreamManager , &
externalInputIsInDatasetFormat ) ; if ( slIsRapidAcceleratorSimulating ( ) &&
externalInputIsInDatasetFormat ) { const int maxErrorBufferSize = 16384 ;
char errMsg [ 16384 ] ; bool bSetErrorStatus = false ; if ( 1 ) { { real_T
time = ssGetTaskTime ( rtS , 0 ) ; if ( !
rtwISigstreamManagerIsPeriodicFcnCall ( pISigstreamManager , 0 ) ) { int_T
sampleHit = 0U ; bSetErrorStatus = rtwISigstreamManagerInjectDataMultiRate (
pISigstreamManager , 0 , time , 1 , "<Root>/x" , "x" , & sampleHit , errMsg ,
maxErrorBufferSize ) ; } } } if ( bSetErrorStatus ) { ssSetErrorStatus ( rtS
, errMsg ) ; return ; } } else { int_T currTimeIdx ; int_T i ; if (
gblInportTUtables [ 0 ] . nTimePoints > 0 ) { if ( 1 ) { { real_T time =
ssGetTaskTime ( rtS , 0 ) ; int k = 1 ; if ( gblInportTUtables [ 0 ] .
nTimePoints == 1 ) { k = 0 ; } currTimeIdx = rt_getTimeIdx (
gblInportTUtables [ 0 ] . time , time , gblInportTUtables [ 0 ] . nTimePoints
, gblInportTUtables [ 0 ] . currTimeIdx , 1 , 0 ) ; gblInportTUtables [ 0 ] .
currTimeIdx = currTimeIdx ; for ( i = 0 ; i < 3 ; i ++ ) { real_T * realPtr1
= ( real_T * ) gblInportTUtables [ 0 ] . ur + i * gblInportTUtables [ 0 ] .
nTimePoints + currTimeIdx ; real_T * realPtr2 = realPtr1 + 1 * k ; ( void )
rt_Interpolate_Datatype ( realPtr1 , realPtr2 , & rtU . bhvfzp4veb [ i ] ,
time , gblInportTUtables [ 0 ] . time [ currTimeIdx ] , gblInportTUtables [ 0
] . time [ currTimeIdx + k ] , gblInportTUtables [ 0 ] . uDataType ) ; } } }
} } } if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { } { void * fp = ( void * ) rtDW
. p5wpguxq2t . PrevTimePtr ; const char * errMsg = ( NULL ) ; if ( fp != (
NULL ) && ( ssIsMajorTimeStep ( rtS ) || ! 0 ) ) { real_T t = ssGetTaskTime (
rtS , 0 ) ; { void * y = & rtB . ggl2c42ej4 . thrust_vector ; errMsg =
rtwMatFileLoaderCollectionGetOutput ( 1 , fp , 0 , t , ssIsMajorTimeStep (
rtS ) , & y ) ; if ( errMsg != ( NULL ) ) { ssSetErrorStatus ( rtS , errMsg )
; return ; } } { void * y = & rtB . ggl2c42ej4 . thrust_weight ; errMsg =
rtwMatFileLoaderCollectionGetOutput ( 1 , fp , 1 , t , ssIsMajorTimeStep (
rtS ) , & y ) ; if ( errMsg != ( NULL ) ) { ssSetErrorStatus ( rtS , errMsg )
; return ; } } { void * y = & rtB . ggl2c42ej4 . solar_occulted_integral ;
errMsg = rtwMatFileLoaderCollectionGetOutput ( 1 , fp , 2 , t ,
ssIsMajorTimeStep ( rtS ) , & y ) ; if ( errMsg != ( NULL ) ) {
ssSetErrorStatus ( rtS , errMsg ) ; return ; } } { void * y = & rtB .
ggl2c42ej4 . solar_occulted_boolean ; errMsg =
rtwMatFileLoaderCollectionGetOutput ( 1 , fp , 3 , t , ssIsMajorTimeStep (
rtS ) , & y ) ; if ( errMsg != ( NULL ) ) { ssSetErrorStatus ( rtS , errMsg )
; return ; } } { void * y = & rtB . ggl2c42ej4 . solar_vector ; errMsg =
rtwMatFileLoaderCollectionGetOutput ( 1 , fp , 4 , t , ssIsMajorTimeStep (
rtS ) , & y ) ; if ( errMsg != ( NULL ) ) { ssSetErrorStatus ( rtS , errMsg )
; return ; } } { void * y = & rtB . ggl2c42ej4 . comms_occulted_integral ;
errMsg = rtwMatFileLoaderCollectionGetOutput ( 1 , fp , 5 , t ,
ssIsMajorTimeStep ( rtS ) , & y ) ; if ( errMsg != ( NULL ) ) {
ssSetErrorStatus ( rtS , errMsg ) ; return ; } } { void * y = & rtB .
ggl2c42ej4 . comms_occulted_boolean ; errMsg =
rtwMatFileLoaderCollectionGetOutput ( 1 , fp , 6 , t , ssIsMajorTimeStep (
rtS ) , & y ) ; if ( errMsg != ( NULL ) ) { ssSetErrorStatus ( rtS , errMsg )
; return ; } } { void * y = & rtB . ggl2c42ej4 . comms_vector ; errMsg =
rtwMatFileLoaderCollectionGetOutput ( 1 , fp , 7 , t , ssIsMajorTimeStep (
rtS ) , & y ) ; if ( errMsg != ( NULL ) ) { ssSetErrorStatus ( rtS , errMsg )
; return ; } } { void * y = & rtB . ggl2c42ej4 . r_s ; errMsg =
rtwMatFileLoaderCollectionGetOutput ( 1 , fp , 8 , t , ssIsMajorTimeStep (
rtS ) , & y ) ; if ( errMsg != ( NULL ) ) { ssSetErrorStatus ( rtS , errMsg )
; return ; } } { void * y = & rtB . ggl2c42ej4 . v_s ; errMsg =
rtwMatFileLoaderCollectionGetOutput ( 1 , fp , 9 , t , ssIsMajorTimeStep (
rtS ) , & y ) ; if ( errMsg != ( NULL ) ) { ssSetErrorStatus ( rtS , errMsg )
; return ; } } { void * y = & rtB . ggl2c42ej4 . r_c ; errMsg =
rtwMatFileLoaderCollectionGetOutput ( 1 , fp , 10 , t , ssIsMajorTimeStep (
rtS ) , & y ) ; if ( errMsg != ( NULL ) ) { ssSetErrorStatus ( rtS , errMsg )
; return ; } } { void * y = & rtB . ggl2c42ej4 . v_c ; errMsg =
rtwMatFileLoaderCollectionGetOutput ( 1 , fp , 11 , t , ssIsMajorTimeStep (
rtS ) , & y ) ; if ( errMsg != ( NULL ) ) { ssSetErrorStatus ( rtS , errMsg )
; return ; } } { void * y = & rtB . ggl2c42ej4 . r_t ; errMsg =
rtwMatFileLoaderCollectionGetOutput ( 1 , fp , 12 , t , ssIsMajorTimeStep (
rtS ) , & y ) ; if ( errMsg != ( NULL ) ) { ssSetErrorStatus ( rtS , errMsg )
; return ; } } { void * y = & rtB . ggl2c42ej4 . v_t ; errMsg =
rtwMatFileLoaderCollectionGetOutput ( 1 , fp , 13 , t , ssIsMajorTimeStep (
rtS ) , & y ) ; if ( errMsg != ( NULL ) ) { ssSetErrorStatus ( rtS , errMsg )
; return ; } } } } idx = 0 ; moeghwuxxr = ( rtB . ggl2c42ej4 . solar_vector [
0 ] * rtB . ggl2c42ej4 . solar_vector [ 0 ] + rtB . ggl2c42ej4 . solar_vector
[ 1 ] * rtB . ggl2c42ej4 . solar_vector [ 1 ] ) + rtB . ggl2c42ej4 .
solar_vector [ 2 ] * rtB . ggl2c42ej4 . solar_vector [ 2 ] ; if ( moeghwuxxr
< 0.0 ) { moeghwuxxr = - muDoubleScalarSqrt ( muDoubleScalarAbs ( moeghwuxxr
) ) ; } else { moeghwuxxr = muDoubleScalarSqrt ( moeghwuxxr ) ; } if (
moeghwuxxr > rtP . NormalizeVector_maxzero ) { cizfy4cb2f_idx_0 = rtB .
ggl2c42ej4 . solar_vector [ 0 ] ; cizfy4cb2f_idx_1 = rtB . ggl2c42ej4 .
solar_vector [ 1 ] ; cizfy4cb2f_idx_2 = rtB . ggl2c42ej4 . solar_vector [ 2 ]
; } else { cizfy4cb2f_idx_0 = rtB . ggl2c42ej4 . solar_vector [ 0 ] * 0.0 ;
cizfy4cb2f_idx_1 = rtB . ggl2c42ej4 . solar_vector [ 1 ] * 0.0 ;
cizfy4cb2f_idx_2 = rtB . ggl2c42ej4 . solar_vector [ 2 ] * 0.0 ; moeghwuxxr =
rtP . Constant_Value_p5yqgecpys ; } jt3hs0aizl_idx_0 = cizfy4cb2f_idx_0 /
moeghwuxxr ; jt3hs0aizl_idx_1 = cizfy4cb2f_idx_1 / moeghwuxxr ;
jt3hs0aizl_idx_2 = cizfy4cb2f_idx_2 / moeghwuxxr ; if ( ssIsSampleHit ( rtS ,
1 , 0 ) ) { A [ 0 ] = ( rtP . P_X . init_xBI [ 0 ] + rtP . P_X . init_yBI [ 1
] ) + rtP . P_X . init_zBI [ 2 ] ; A [ 1 ] = ( rtP . P_X . init_xBI [ 0 ] -
rtP . P_X . init_yBI [ 1 ] ) - rtP . P_X . init_zBI [ 2 ] ; A [ 2 ] = ( - rtP
. P_X . init_xBI [ 0 ] + rtP . P_X . init_yBI [ 1 ] ) - rtP . P_X . init_zBI
[ 2 ] ; A [ 3 ] = ( - rtP . P_X . init_xBI [ 0 ] - rtP . P_X . init_yBI [ 1 ]
) + rtP . P_X . init_zBI [ 2 ] ; if ( ! muDoubleScalarIsNaN ( A [ 0 ] ) ) {
idx = 1 ; } else { k = 2 ; exitg1 = false ; while ( ( ! exitg1 ) && ( k < 5 )
) { if ( ! muDoubleScalarIsNaN ( A [ k - 1 ] ) ) { idx = k ; exitg1 = true ;
} else { k ++ ; } } } if ( idx == 0 ) { idx = 1 ; } else { moeghwuxxr = A [
idx - 1 ] ; for ( k = idx ; k < 4 ; k ++ ) { if ( moeghwuxxr < A [ k ] ) {
moeghwuxxr = A [ k ] ; idx = k + 1 ; } } } switch ( idx ) { case 1 :
cizfy4cb2f_idx_1 = muDoubleScalarSqrt ( A [ 0 ] + 1.0 ) * 0.5 ; moeghwuxxr =
1.0 / ( 4.0 * cizfy4cb2f_idx_1 ) ; cizfy4cb2f_idx_2 = ( rtP . P_X . init_yBI
[ 2 ] - rtP . P_X . init_zBI [ 1 ] ) * moeghwuxxr ; oufzjameo0_idx_2 = ( rtP
. P_X . init_zBI [ 0 ] - rtP . P_X . init_xBI [ 2 ] ) * moeghwuxxr ;
cizfy4cb2f_idx_0 = ( rtP . P_X . init_xBI [ 1 ] - rtP . P_X . init_yBI [ 0 ]
) * moeghwuxxr ; break ; case 2 : cizfy4cb2f_idx_2 = muDoubleScalarSqrt ( A [
1 ] + 1.0 ) * 0.5 ; moeghwuxxr = 1.0 / ( 4.0 * cizfy4cb2f_idx_2 ) ;
oufzjameo0_idx_2 = ( rtP . P_X . init_xBI [ 1 ] + rtP . P_X . init_yBI [ 0 ]
) * moeghwuxxr ; cizfy4cb2f_idx_0 = ( rtP . P_X . init_zBI [ 0 ] + rtP . P_X
. init_xBI [ 2 ] ) * moeghwuxxr ; cizfy4cb2f_idx_1 = ( rtP . P_X . init_yBI [
2 ] - rtP . P_X . init_zBI [ 1 ] ) * moeghwuxxr ; break ; case 3 :
oufzjameo0_idx_2 = muDoubleScalarSqrt ( A [ 2 ] + 1.0 ) * 0.5 ; moeghwuxxr =
1.0 / ( 4.0 * oufzjameo0_idx_2 ) ; cizfy4cb2f_idx_0 = ( rtP . P_X . init_yBI
[ 2 ] + rtP . P_X . init_zBI [ 1 ] ) * moeghwuxxr ; cizfy4cb2f_idx_1 = ( rtP
. P_X . init_zBI [ 0 ] - rtP . P_X . init_xBI [ 2 ] ) * moeghwuxxr ;
cizfy4cb2f_idx_2 = ( rtP . P_X . init_xBI [ 1 ] + rtP . P_X . init_yBI [ 0 ]
) * moeghwuxxr ; break ; default : cizfy4cb2f_idx_0 = muDoubleScalarSqrt ( A
[ 3 ] + 1.0 ) * 0.5 ; moeghwuxxr = 1.0 / ( 4.0 * cizfy4cb2f_idx_0 ) ;
cizfy4cb2f_idx_1 = ( rtP . P_X . init_xBI [ 1 ] - rtP . P_X . init_yBI [ 0 ]
) * moeghwuxxr ; cizfy4cb2f_idx_2 = ( rtP . P_X . init_zBI [ 0 ] + rtP . P_X
. init_xBI [ 2 ] ) * moeghwuxxr ; oufzjameo0_idx_2 = ( rtP . P_X . init_yBI [
2 ] + rtP . P_X . init_zBI [ 1 ] ) * moeghwuxxr ; break ; } rtB . j3dtcamj3h
[ 0 ] = rtP . Gain1_Gain [ 0 ] * cizfy4cb2f_idx_1 ; rtB . j3dtcamj3h [ 1 ] =
rtP . Gain1_Gain [ 1 ] * cizfy4cb2f_idx_2 ; rtB . j3dtcamj3h [ 2 ] = rtP .
Gain1_Gain [ 2 ] * oufzjameo0_idx_2 ; rtB . j3dtcamj3h [ 3 ] = rtP .
Gain1_Gain [ 3 ] * cizfy4cb2f_idx_0 ; } if ( rtDW . ag2rcaep41 != 0 ) { rtX .
kvd5s5mhzq [ 0 ] = rtB . j3dtcamj3h [ 0 ] ; rtX . kvd5s5mhzq [ 1 ] = rtB .
j3dtcamj3h [ 1 ] ; rtX . kvd5s5mhzq [ 2 ] = rtB . j3dtcamj3h [ 2 ] ; rtX .
kvd5s5mhzq [ 3 ] = rtB . j3dtcamj3h [ 3 ] ; } scale = 3.3121686421112381E-170
; cizfy4cb2f_idx_0 = muDoubleScalarAbs ( rtX . kvd5s5mhzq [ 0 ] ) ; if (
cizfy4cb2f_idx_0 > 3.3121686421112381E-170 ) { moeghwuxxr = 1.0 ; scale =
cizfy4cb2f_idx_0 ; } else { cizfy4cb2f_idx_1 = cizfy4cb2f_idx_0 /
3.3121686421112381E-170 ; moeghwuxxr = cizfy4cb2f_idx_1 * cizfy4cb2f_idx_1 ;
} cizfy4cb2f_idx_0 = muDoubleScalarAbs ( rtX . kvd5s5mhzq [ 1 ] ) ; if (
cizfy4cb2f_idx_0 > scale ) { cizfy4cb2f_idx_1 = scale / cizfy4cb2f_idx_0 ;
moeghwuxxr = moeghwuxxr * cizfy4cb2f_idx_1 * cizfy4cb2f_idx_1 + 1.0 ; scale =
cizfy4cb2f_idx_0 ; } else { cizfy4cb2f_idx_1 = cizfy4cb2f_idx_0 / scale ;
moeghwuxxr += cizfy4cb2f_idx_1 * cizfy4cb2f_idx_1 ; } cizfy4cb2f_idx_0 =
muDoubleScalarAbs ( rtX . kvd5s5mhzq [ 2 ] ) ; if ( cizfy4cb2f_idx_0 > scale
) { cizfy4cb2f_idx_1 = scale / cizfy4cb2f_idx_0 ; moeghwuxxr = moeghwuxxr *
cizfy4cb2f_idx_1 * cizfy4cb2f_idx_1 + 1.0 ; scale = cizfy4cb2f_idx_0 ; } else
{ cizfy4cb2f_idx_1 = cizfy4cb2f_idx_0 / scale ; moeghwuxxr +=
cizfy4cb2f_idx_1 * cizfy4cb2f_idx_1 ; } cizfy4cb2f_idx_0 = muDoubleScalarAbs
( rtX . kvd5s5mhzq [ 3 ] ) ; if ( cizfy4cb2f_idx_0 > scale ) {
cizfy4cb2f_idx_1 = scale / cizfy4cb2f_idx_0 ; moeghwuxxr = moeghwuxxr *
cizfy4cb2f_idx_1 * cizfy4cb2f_idx_1 + 1.0 ; scale = cizfy4cb2f_idx_0 ; } else
{ cizfy4cb2f_idx_1 = cizfy4cb2f_idx_0 / scale ; moeghwuxxr +=
cizfy4cb2f_idx_1 * cizfy4cb2f_idx_1 ; } moeghwuxxr = scale *
muDoubleScalarSqrt ( moeghwuxxr ) ; rtB . id3syu3xda [ 0 ] = rtX . kvd5s5mhzq
[ 0 ] / moeghwuxxr ; oufzjameo0_idx_2 = rtP . Gain1_Gain_i0dny2tgg4 [ 0 ] *
rtB . id3syu3xda [ 0 ] ; A [ 0 ] = rtP . Gain1_Gain_f3zo2a45h3 [ 0 ] *
oufzjameo0_idx_2 ; cizfy4cb2f_idx_0 = oufzjameo0_idx_2 ; rtB . id3syu3xda [ 1
] = rtX . kvd5s5mhzq [ 1 ] / moeghwuxxr ; oufzjameo0_idx_2 = rtP .
Gain1_Gain_i0dny2tgg4 [ 1 ] * rtB . id3syu3xda [ 1 ] ; A [ 1 ] = rtP .
Gain1_Gain_f3zo2a45h3 [ 1 ] * oufzjameo0_idx_2 ; cizfy4cb2f_idx_1 =
oufzjameo0_idx_2 ; rtB . id3syu3xda [ 2 ] = rtX . kvd5s5mhzq [ 2 ] /
moeghwuxxr ; oufzjameo0_idx_2 = rtP . Gain1_Gain_i0dny2tgg4 [ 2 ] * rtB .
id3syu3xda [ 2 ] ; A [ 2 ] = rtP . Gain1_Gain_f3zo2a45h3 [ 2 ] *
oufzjameo0_idx_2 ; cizfy4cb2f_idx_2 = oufzjameo0_idx_2 ; rtB . id3syu3xda [ 3
] = rtX . kvd5s5mhzq [ 3 ] / moeghwuxxr ; oufzjameo0_idx_2 = rtP .
Gain1_Gain_i0dny2tgg4 [ 3 ] * rtB . id3syu3xda [ 3 ] ; A [ 3 ] = rtP .
Gain1_Gain_f3zo2a45h3 [ 3 ] * oufzjameo0_idx_2 ; moeghwuxxr = A [ 0 ] * rtP .
Constant_Value_o2fro3xhzj - ( ( rtP . P_F . star_sensor_1_vb [ 0 ] * A [ 1 ]
+ rtP . P_F . star_sensor_1_vb [ 1 ] * A [ 2 ] ) + rtP . P_F .
star_sensor_1_vb [ 2 ] * A [ 3 ] ) ; aujhvgokqy_idx_0 = ( ( A [ 2 ] * rtP .
P_F . star_sensor_1_vb [ 2 ] - A [ 3 ] * rtP . P_F . star_sensor_1_vb [ 1 ] )
+ A [ 0 ] * rtP . P_F . star_sensor_1_vb [ 0 ] ) + rtP .
Constant_Value_o2fro3xhzj * A [ 1 ] ; hu15wb2s0u = ( ( A [ 3 ] * rtP . P_F .
star_sensor_1_vb [ 0 ] - A [ 1 ] * rtP . P_F . star_sensor_1_vb [ 2 ] ) + A [
0 ] * rtP . P_F . star_sensor_1_vb [ 1 ] ) + rtP . Constant_Value_o2fro3xhzj
* A [ 2 ] ; aujhvgokqy_idx_2 = ( ( A [ 1 ] * rtP . P_F . star_sensor_1_vb [ 1
] - A [ 2 ] * rtP . P_F . star_sensor_1_vb [ 0 ] ) + A [ 0 ] * rtP . P_F .
star_sensor_1_vb [ 2 ] ) + rtP . Constant_Value_o2fro3xhzj * A [ 3 ] ; scale
= moeghwuxxr * cizfy4cb2f_idx_0 - ( ( cizfy4cb2f_idx_1 * aujhvgokqy_idx_0 +
cizfy4cb2f_idx_2 * hu15wb2s0u ) + oufzjameo0_idx_2 * aujhvgokqy_idx_2 ) ; rtB
. gwuhy1m1pb [ 0 ] = ( ( ( hu15wb2s0u * oufzjameo0_idx_2 - aujhvgokqy_idx_2 *
cizfy4cb2f_idx_2 ) + moeghwuxxr * cizfy4cb2f_idx_1 ) + cizfy4cb2f_idx_0 *
aujhvgokqy_idx_0 ) * ( 1.0 / scale ) ; rtB . gwuhy1m1pb [ 1 ] = ( ( (
aujhvgokqy_idx_2 * cizfy4cb2f_idx_1 - aujhvgokqy_idx_0 * oufzjameo0_idx_2 ) +
moeghwuxxr * cizfy4cb2f_idx_2 ) + cizfy4cb2f_idx_0 * hu15wb2s0u ) * ( 1.0 /
scale ) ; rtB . gwuhy1m1pb [ 2 ] = ( ( ( aujhvgokqy_idx_0 * cizfy4cb2f_idx_2
- hu15wb2s0u * cizfy4cb2f_idx_1 ) + moeghwuxxr * oufzjameo0_idx_2 ) +
cizfy4cb2f_idx_0 * aujhvgokqy_idx_2 ) * ( 1.0 / scale ) ; o2311hs4bm = ( rtB
. gwuhy1m1pb [ 0 ] * rtB . gwuhy1m1pb [ 0 ] + rtB . gwuhy1m1pb [ 1 ] * rtB .
gwuhy1m1pb [ 1 ] ) + rtB . gwuhy1m1pb [ 2 ] * rtB . gwuhy1m1pb [ 2 ] ; if (
o2311hs4bm < 0.0 ) { o2311hs4bm = - muDoubleScalarSqrt ( muDoubleScalarAbs (
o2311hs4bm ) ) ; } else { o2311hs4bm = muDoubleScalarSqrt ( o2311hs4bm ) ; }
if ( o2311hs4bm > rtP . NormalizeVector1_maxzero ) { A [ 0 ] = rtB .
gwuhy1m1pb [ 0 ] ; A [ 1 ] = rtB . gwuhy1m1pb [ 1 ] ; A [ 2 ] = rtB .
gwuhy1m1pb [ 2 ] ; A [ 3 ] = o2311hs4bm ; } else { A [ 0 ] = rtB . gwuhy1m1pb
[ 0 ] * 0.0 ; A [ 1 ] = rtB . gwuhy1m1pb [ 1 ] * 0.0 ; A [ 2 ] = rtB .
gwuhy1m1pb [ 2 ] * 0.0 ; A [ 3 ] = rtP . Constant_Value_pblczk22x1 ; }
aujhvgokqy_idx_0 = ( A [ 0 ] / A [ 3 ] * jt3hs0aizl_idx_0 + A [ 1 ] / A [ 3 ]
* jt3hs0aizl_idx_1 ) + A [ 2 ] / A [ 3 ] * jt3hs0aizl_idx_2 ; if (
aujhvgokqy_idx_0 > rtP . Saturation_UpperSat ) { rtB . ksb54aeynf = rtP .
Saturation_UpperSat ; } else if ( aujhvgokqy_idx_0 < rtP .
Saturation_LowerSat ) { rtB . ksb54aeynf = rtP . Saturation_LowerSat ; } else
{ rtB . ksb54aeynf = aujhvgokqy_idx_0 ; } rtB . lbvs2uyceq = rtB . ggl2c42ej4
. solar_occulted_boolean * rtB . ksb54aeynf ; if ( rtB . lbvs2uyceq > 1.0 ) {
jt3hs0aizl_idx_0 = 1.0 ; } else if ( rtB . lbvs2uyceq < - 1.0 ) {
jt3hs0aizl_idx_0 = - 1.0 ; } else { jt3hs0aizl_idx_0 = rtB . lbvs2uyceq ; }
rtB . bv1kuls22a = muDoubleScalarAcos ( jt3hs0aizl_idx_0 ) ; fbz1lrgadk ( rtB
. bv1kuls22a , & rtB . fbz1lrgadk1 , & rtDW . fbz1lrgadk1 ) ;
jt3hs0aizl_idx_0 = ( rtB . ggl2c42ej4 . solar_vector [ 0 ] * rtB . ggl2c42ej4
. solar_vector [ 0 ] + rtB . ggl2c42ej4 . solar_vector [ 1 ] * rtB .
ggl2c42ej4 . solar_vector [ 1 ] ) + rtB . ggl2c42ej4 . solar_vector [ 2 ] *
rtB . ggl2c42ej4 . solar_vector [ 2 ] ; if ( jt3hs0aizl_idx_0 < 0.0 ) {
jt3hs0aizl_idx_0 = - muDoubleScalarSqrt ( muDoubleScalarAbs (
jt3hs0aizl_idx_0 ) ) ; } else { jt3hs0aizl_idx_0 = muDoubleScalarSqrt (
jt3hs0aizl_idx_0 ) ; } if ( jt3hs0aizl_idx_0 > rtP .
NormalizeVector_maxzero_mt13upuc30 ) { A [ 0 ] = rtB . ggl2c42ej4 .
solar_vector [ 0 ] ; A [ 1 ] = rtB . ggl2c42ej4 . solar_vector [ 1 ] ; A [ 2
] = rtB . ggl2c42ej4 . solar_vector [ 2 ] ; A [ 3 ] = jt3hs0aizl_idx_0 ; }
else { A [ 0 ] = rtB . ggl2c42ej4 . solar_vector [ 0 ] * 0.0 ; A [ 1 ] = rtB
. ggl2c42ej4 . solar_vector [ 1 ] * 0.0 ; A [ 2 ] = rtB . ggl2c42ej4 .
solar_vector [ 2 ] * 0.0 ; A [ 3 ] = rtP . Constant_Value_ojxmxt5mmf ; }
jt3hs0aizl_idx_2 = A [ 0 ] / A [ 3 ] ; moeghwuxxr = A [ 1 ] / A [ 3 ] ; scale
= A [ 2 ] / A [ 3 ] ; A [ 0 ] = rtP . Gain1_Gain_mglm2i5i2e [ 0 ] *
cizfy4cb2f_idx_0 ; A [ 1 ] = rtP . Gain1_Gain_mglm2i5i2e [ 1 ] *
cizfy4cb2f_idx_1 ; A [ 2 ] = rtP . Gain1_Gain_mglm2i5i2e [ 2 ] *
cizfy4cb2f_idx_2 ; A [ 3 ] = rtP . Gain1_Gain_mglm2i5i2e [ 3 ] *
oufzjameo0_idx_2 ; jt3hs0aizl_idx_0 = A [ 0 ] * rtP .
Constant_Value_i2bviibqa1 - ( ( rtP . P_F . star_sensor_2_vb [ 0 ] * A [ 1 ]
+ rtP . P_F . star_sensor_2_vb [ 1 ] * A [ 2 ] ) + rtP . P_F .
star_sensor_2_vb [ 2 ] * A [ 3 ] ) ; aujhvgokqy_idx_0 = ( ( A [ 2 ] * rtP .
P_F . star_sensor_2_vb [ 2 ] - A [ 3 ] * rtP . P_F . star_sensor_2_vb [ 1 ] )
+ A [ 0 ] * rtP . P_F . star_sensor_2_vb [ 0 ] ) + rtP .
Constant_Value_i2bviibqa1 * A [ 1 ] ; hu15wb2s0u = ( ( A [ 3 ] * rtP . P_F .
star_sensor_2_vb [ 0 ] - A [ 1 ] * rtP . P_F . star_sensor_2_vb [ 2 ] ) + A [
0 ] * rtP . P_F . star_sensor_2_vb [ 1 ] ) + rtP . Constant_Value_i2bviibqa1
* A [ 2 ] ; aujhvgokqy_idx_2 = ( ( A [ 1 ] * rtP . P_F . star_sensor_2_vb [ 1
] - A [ 2 ] * rtP . P_F . star_sensor_2_vb [ 0 ] ) + A [ 0 ] * rtP . P_F .
star_sensor_2_vb [ 2 ] ) + rtP . Constant_Value_i2bviibqa1 * A [ 3 ] ;
o2311hs4bm = jt3hs0aizl_idx_0 * cizfy4cb2f_idx_0 - ( ( cizfy4cb2f_idx_1 *
aujhvgokqy_idx_0 + cizfy4cb2f_idx_2 * hu15wb2s0u ) + oufzjameo0_idx_2 *
aujhvgokqy_idx_2 ) ; rtB . i1cpfgl4ur [ 0 ] = ( ( ( hu15wb2s0u *
oufzjameo0_idx_2 - aujhvgokqy_idx_2 * cizfy4cb2f_idx_2 ) + jt3hs0aizl_idx_0 *
cizfy4cb2f_idx_1 ) + cizfy4cb2f_idx_0 * aujhvgokqy_idx_0 ) * ( 1.0 /
o2311hs4bm ) ; rtB . i1cpfgl4ur [ 1 ] = ( ( ( aujhvgokqy_idx_2 *
cizfy4cb2f_idx_1 - aujhvgokqy_idx_0 * oufzjameo0_idx_2 ) + jt3hs0aizl_idx_0 *
cizfy4cb2f_idx_2 ) + cizfy4cb2f_idx_0 * hu15wb2s0u ) * ( 1.0 / o2311hs4bm ) ;
rtB . i1cpfgl4ur [ 2 ] = ( ( ( aujhvgokqy_idx_0 * cizfy4cb2f_idx_2 -
hu15wb2s0u * cizfy4cb2f_idx_1 ) + jt3hs0aizl_idx_0 * oufzjameo0_idx_2 ) +
cizfy4cb2f_idx_0 * aujhvgokqy_idx_2 ) * ( 1.0 / o2311hs4bm ) ;
jt3hs0aizl_idx_0 = ( rtB . i1cpfgl4ur [ 0 ] * rtB . i1cpfgl4ur [ 0 ] + rtB .
i1cpfgl4ur [ 1 ] * rtB . i1cpfgl4ur [ 1 ] ) + rtB . i1cpfgl4ur [ 2 ] * rtB .
i1cpfgl4ur [ 2 ] ; if ( jt3hs0aizl_idx_0 < 0.0 ) { jt3hs0aizl_idx_0 = -
muDoubleScalarSqrt ( muDoubleScalarAbs ( jt3hs0aizl_idx_0 ) ) ; } else {
jt3hs0aizl_idx_0 = muDoubleScalarSqrt ( jt3hs0aizl_idx_0 ) ; } if (
jt3hs0aizl_idx_0 > rtP . NormalizeVector1_maxzero_it3sz44pnw ) { A [ 0 ] =
rtB . i1cpfgl4ur [ 0 ] ; A [ 1 ] = rtB . i1cpfgl4ur [ 1 ] ; A [ 2 ] = rtB .
i1cpfgl4ur [ 2 ] ; A [ 3 ] = jt3hs0aizl_idx_0 ; } else { A [ 0 ] = rtB .
i1cpfgl4ur [ 0 ] * 0.0 ; A [ 1 ] = rtB . i1cpfgl4ur [ 1 ] * 0.0 ; A [ 2 ] =
rtB . i1cpfgl4ur [ 2 ] * 0.0 ; A [ 3 ] = rtP . Constant_Value_pwofnawzxn ; }
jt3hs0aizl_idx_2 = ( A [ 0 ] / A [ 3 ] * jt3hs0aizl_idx_2 + A [ 1 ] / A [ 3 ]
* moeghwuxxr ) + A [ 2 ] / A [ 3 ] * scale ; if ( jt3hs0aizl_idx_2 > rtP .
Saturation_UpperSat_o0tu1knjb5 ) { rtB . b13j3pqall = rtP .
Saturation_UpperSat_o0tu1knjb5 ; } else if ( jt3hs0aizl_idx_2 < rtP .
Saturation_LowerSat_pjt1p3frof ) { rtB . b13j3pqall = rtP .
Saturation_LowerSat_pjt1p3frof ; } else { rtB . b13j3pqall = jt3hs0aizl_idx_2
; } rtB . p2owgzs2iz = rtB . ggl2c42ej4 . solar_occulted_boolean * rtB .
b13j3pqall ; if ( rtB . p2owgzs2iz > 1.0 ) { jt3hs0aizl_idx_0 = 1.0 ; } else
if ( rtB . p2owgzs2iz < - 1.0 ) { jt3hs0aizl_idx_0 = - 1.0 ; } else {
jt3hs0aizl_idx_0 = rtB . p2owgzs2iz ; } rtB . adp4h11fxy = muDoubleScalarAcos
( jt3hs0aizl_idx_0 ) ; fbz1lrgadk ( rtB . adp4h11fxy , & rtB . fbz1lrgadk1o ,
& rtDW . fbz1lrgadk1o ) ; aujhvgokqy_idx_0 = rtP . Gain1_Gain_jasbtnac0r *
rtB . ggl2c42ej4 . r_s [ 0 ] ; jt3hs0aizl_idx_2 = aujhvgokqy_idx_0 *
aujhvgokqy_idx_0 ; jt3hs0aizl_idx_0 = aujhvgokqy_idx_0 ; aujhvgokqy_idx_0 =
rtP . Gain1_Gain_jasbtnac0r * rtB . ggl2c42ej4 . r_s [ 1 ] ; moeghwuxxr =
aujhvgokqy_idx_0 * aujhvgokqy_idx_0 ; jt3hs0aizl_idx_1 = aujhvgokqy_idx_0 ;
aujhvgokqy_idx_0 = rtP . Gain1_Gain_jasbtnac0r * rtB . ggl2c42ej4 . r_s [ 2 ]
; jt3hs0aizl_idx_2 = ( jt3hs0aizl_idx_2 + moeghwuxxr ) + aujhvgokqy_idx_0 *
aujhvgokqy_idx_0 ; if ( jt3hs0aizl_idx_2 < 0.0 ) { jt3hs0aizl_idx_2 = -
muDoubleScalarSqrt ( muDoubleScalarAbs ( jt3hs0aizl_idx_2 ) ) ; } else {
jt3hs0aizl_idx_2 = muDoubleScalarSqrt ( jt3hs0aizl_idx_2 ) ; } if (
jt3hs0aizl_idx_2 > rtP . NormalizeVector_maxzero_oczsk3pynm ) { A [ 0 ] =
jt3hs0aizl_idx_0 ; A [ 1 ] = jt3hs0aizl_idx_1 ; A [ 2 ] = aujhvgokqy_idx_0 ;
A [ 3 ] = jt3hs0aizl_idx_2 ; } else { A [ 0 ] = jt3hs0aizl_idx_0 * 0.0 ; A [
1 ] = jt3hs0aizl_idx_1 * 0.0 ; A [ 2 ] = aujhvgokqy_idx_0 * 0.0 ; A [ 3 ] =
rtP . Constant_Value_kd4xr3zjvz ; } jt3hs0aizl_idx_2 = A [ 0 ] / A [ 3 ] ;
moeghwuxxr = A [ 1 ] / A [ 3 ] ; scale = A [ 2 ] / A [ 3 ] ; hu15wb2s0u = (
rtB . gwuhy1m1pb [ 0 ] * rtB . gwuhy1m1pb [ 0 ] + rtB . gwuhy1m1pb [ 1 ] *
rtB . gwuhy1m1pb [ 1 ] ) + rtB . gwuhy1m1pb [ 2 ] * rtB . gwuhy1m1pb [ 2 ] ;
if ( hu15wb2s0u < 0.0 ) { hu15wb2s0u = - muDoubleScalarSqrt (
muDoubleScalarAbs ( hu15wb2s0u ) ) ; } else { hu15wb2s0u = muDoubleScalarSqrt
( hu15wb2s0u ) ; } if ( hu15wb2s0u > rtP .
NormalizeVector1_maxzero_curh4i254k ) { A [ 0 ] = rtB . gwuhy1m1pb [ 0 ] ; A
[ 1 ] = rtB . gwuhy1m1pb [ 1 ] ; A [ 2 ] = rtB . gwuhy1m1pb [ 2 ] ; A [ 3 ] =
hu15wb2s0u ; } else { A [ 0 ] = rtB . gwuhy1m1pb [ 0 ] * 0.0 ; A [ 1 ] = rtB
. gwuhy1m1pb [ 1 ] * 0.0 ; A [ 2 ] = rtB . gwuhy1m1pb [ 2 ] * 0.0 ; A [ 3 ] =
rtP . Constant_Value_gspoitvpf3 ; } jt3hs0aizl_idx_2 = ( A [ 0 ] / A [ 3 ] *
jt3hs0aizl_idx_2 + A [ 1 ] / A [ 3 ] * moeghwuxxr ) + A [ 2 ] / A [ 3 ] *
scale ; if ( jt3hs0aizl_idx_2 > 1.0 ) { jt3hs0aizl_idx_2 = 1.0 ; } else { if
( jt3hs0aizl_idx_2 < - 1.0 ) { jt3hs0aizl_idx_2 = - 1.0 ; } } if (
muDoubleScalarAtan ( rtP . P_E . target_mean_radius / ( muDoubleScalarSqrt (
( jt3hs0aizl_idx_0 * jt3hs0aizl_idx_0 + jt3hs0aizl_idx_1 * jt3hs0aizl_idx_1 )
+ aujhvgokqy_idx_0 * aujhvgokqy_idx_0 ) + rtP . P_E . target_mean_radius ) )
> muDoubleScalarAcos ( jt3hs0aizl_idx_2 ) ) { rtB . kla2ie4xqo = rtP .
Constant10_Value ; } else { rtB . kla2ie4xqo = rtP . Constant11_Value ; } if
( ssIsSampleHit ( rtS , 1 , 0 ) ) { jt3hs0aizl_idx_2 = rtB . kla2ie4xqo * rtP
. DiscreteFIRFilter_Coefficients [ 0 ] ; for ( idx = 0 ; idx < 59 ; idx ++ )
{ jt3hs0aizl_idx_2 += rtP . DiscreteFIRFilter_Coefficients [ idx + 1 ] * rtDW
. nrt1u3ug04 [ idx ] ; } for ( idx = 57 ; idx >= 0 ; idx -- ) { rtDW .
nrt1u3ug04 [ idx + 1 ] = rtDW . nrt1u3ug04 [ idx ] ; } rtDW . nrt1u3ug04 [ 0
] = rtB . kla2ie4xqo ; po5evibzby = jt3hs0aizl_idx_2 / ( real_T ) rtP . P_F .
window_n ; juzdrgfwyw ( po5evibzby , & rtB . juzdrgfwywb , & rtDW .
juzdrgfwywb ) ; } aujhvgokqy_idx_0 = rtP . Gain1_Gain_luip00ayzb * rtB .
ggl2c42ej4 . r_s [ 0 ] ; jt3hs0aizl_idx_2 = aujhvgokqy_idx_0 *
aujhvgokqy_idx_0 ; jt3hs0aizl_idx_0 = aujhvgokqy_idx_0 ; aujhvgokqy_idx_0 =
rtP . Gain1_Gain_luip00ayzb * rtB . ggl2c42ej4 . r_s [ 1 ] ; moeghwuxxr =
aujhvgokqy_idx_0 * aujhvgokqy_idx_0 ; jt3hs0aizl_idx_1 = aujhvgokqy_idx_0 ;
aujhvgokqy_idx_0 = rtP . Gain1_Gain_luip00ayzb * rtB . ggl2c42ej4 . r_s [ 2 ]
; jt3hs0aizl_idx_2 = ( jt3hs0aizl_idx_2 + moeghwuxxr ) + aujhvgokqy_idx_0 *
aujhvgokqy_idx_0 ; if ( jt3hs0aizl_idx_2 < 0.0 ) { jt3hs0aizl_idx_2 = -
muDoubleScalarSqrt ( muDoubleScalarAbs ( jt3hs0aizl_idx_2 ) ) ; } else {
jt3hs0aizl_idx_2 = muDoubleScalarSqrt ( jt3hs0aizl_idx_2 ) ; } if (
jt3hs0aizl_idx_2 > rtP . NormalizeVector_maxzero_ektzry0otc ) { A [ 0 ] =
jt3hs0aizl_idx_0 ; A [ 1 ] = jt3hs0aizl_idx_1 ; A [ 2 ] = aujhvgokqy_idx_0 ;
A [ 3 ] = jt3hs0aizl_idx_2 ; } else { A [ 0 ] = jt3hs0aizl_idx_0 * 0.0 ; A [
1 ] = jt3hs0aizl_idx_1 * 0.0 ; A [ 2 ] = aujhvgokqy_idx_0 * 0.0 ; A [ 3 ] =
rtP . Constant_Value_bu2n4z0wwl ; } jt3hs0aizl_idx_2 = A [ 0 ] / A [ 3 ] ;
moeghwuxxr = A [ 1 ] / A [ 3 ] ; scale = A [ 2 ] / A [ 3 ] ; hu15wb2s0u = (
rtB . i1cpfgl4ur [ 0 ] * rtB . i1cpfgl4ur [ 0 ] + rtB . i1cpfgl4ur [ 1 ] *
rtB . i1cpfgl4ur [ 1 ] ) + rtB . i1cpfgl4ur [ 2 ] * rtB . i1cpfgl4ur [ 2 ] ;
if ( hu15wb2s0u < 0.0 ) { hu15wb2s0u = - muDoubleScalarSqrt (
muDoubleScalarAbs ( hu15wb2s0u ) ) ; } else { hu15wb2s0u = muDoubleScalarSqrt
( hu15wb2s0u ) ; } if ( hu15wb2s0u > rtP .
NormalizeVector1_maxzero_esmeewv013 ) { A [ 0 ] = rtB . i1cpfgl4ur [ 0 ] ; A
[ 1 ] = rtB . i1cpfgl4ur [ 1 ] ; A [ 2 ] = rtB . i1cpfgl4ur [ 2 ] ; A [ 3 ] =
hu15wb2s0u ; } else { A [ 0 ] = rtB . i1cpfgl4ur [ 0 ] * 0.0 ; A [ 1 ] = rtB
. i1cpfgl4ur [ 1 ] * 0.0 ; A [ 2 ] = rtB . i1cpfgl4ur [ 2 ] * 0.0 ; A [ 3 ] =
rtP . Constant_Value_ovccxkrnjy ; } jt3hs0aizl_idx_2 = ( A [ 0 ] / A [ 3 ] *
jt3hs0aizl_idx_2 + A [ 1 ] / A [ 3 ] * moeghwuxxr ) + A [ 2 ] / A [ 3 ] *
scale ; if ( jt3hs0aizl_idx_2 > 1.0 ) { jt3hs0aizl_idx_2 = 1.0 ; } else { if
( jt3hs0aizl_idx_2 < - 1.0 ) { jt3hs0aizl_idx_2 = - 1.0 ; } } if (
muDoubleScalarAtan ( rtP . P_E . target_mean_radius / ( muDoubleScalarSqrt (
( jt3hs0aizl_idx_0 * jt3hs0aizl_idx_0 + jt3hs0aizl_idx_1 * jt3hs0aizl_idx_1 )
+ aujhvgokqy_idx_0 * aujhvgokqy_idx_0 ) + rtP . P_E . target_mean_radius ) )
> muDoubleScalarAcos ( jt3hs0aizl_idx_2 ) ) { rtB . fvvukgofqm = rtP .
Constant10_Value_pnntlgrkfl ; } else { rtB . fvvukgofqm = rtP .
Constant11_Value_fak2wrhghj ; } if ( ssIsSampleHit ( rtS , 1 , 0 ) ) {
jt3hs0aizl_idx_0 = rtB . fvvukgofqm * rtP .
DiscreteFIRFilter_Coefficients_n1yfwntl03 [ 0 ] ; for ( idx = 0 ; idx < 59 ;
idx ++ ) { jt3hs0aizl_idx_0 += rtP .
DiscreteFIRFilter_Coefficients_n1yfwntl03 [ idx + 1 ] * rtDW . nn3mukf4ls [
idx ] ; } for ( idx = 57 ; idx >= 0 ; idx -- ) { rtDW . nn3mukf4ls [ idx + 1
] = rtDW . nn3mukf4ls [ idx ] ; } rtDW . nn3mukf4ls [ 0 ] = rtB . fvvukgofqm
; f4vnhc3tuh = jt3hs0aizl_idx_0 / ( real_T ) rtP . P_F . window_n ;
juzdrgfwyw ( f4vnhc3tuh , & rtB . juzdrgfwywbn , & rtDW . juzdrgfwywbn ) ; }
if ( rtB . ggl2c42ej4 . solar_occulted_integral == rtP .
Constant_Value_bpciai0igk ) { jt3hs0aizl_idx_0 = rtP .
Constant_Value_b54p1uwprt ; } else { jt3hs0aizl_idx_0 = rtB . ggl2c42ej4 .
solar_occulted_integral ; } rtB . ocjizknfbp = 1.0 / jt3hs0aizl_idx_0 * rtX .
oznfot3xd2 ; if ( rtB . ggl2c42ej4 . comms_occulted_integral == rtP .
Constant_Value_c4d4ozwwzr ) { jt3hs0aizl_idx_0 = rtP .
Constant_Value_ok5wcdghto ; } else { jt3hs0aizl_idx_0 = rtB . ggl2c42ej4 .
comms_occulted_integral ; } rtB . hcfehsmczi = 1.0 / jt3hs0aizl_idx_0 * rtX .
gi0dbsjbab ; if ( rtX . ndr0ddj14l == rtP . Constant_Value ) { rtB .
jcjpclbjp2 = rtP . Constant9_Value ; } else { rtB . jcjpclbjp2 = rtX .
ndr0ddj14l ; } rtB . aui5mhj44r = rtX . f5kva1vvha ; rtB . objaac1udz = 1.0 /
rtB . jcjpclbjp2 * rtB . aui5mhj44r ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) {
} rtB . pctj4gwip4 = rtB . ggl2c42ej4 . thrust_weight ; rtB . fpa0aiyozw =
rtB . ggl2c42ej4 . solar_occulted_integral ; rtB . bi23bgkdar = rtB .
ggl2c42ej4 . solar_occulted_boolean ; rtB . ozqsycmu2s = rtB . ggl2c42ej4 .
comms_occulted_integral ; rtB . lm0mtopp3u = rtB . ggl2c42ej4 .
comms_occulted_boolean ; rtB . njrvjekzfm [ 0 ] = rtB . ggl2c42ej4 .
thrust_vector [ 0 ] ; rtB . ndieoaonxd [ 0 ] = rtB . ggl2c42ej4 . r_s [ 0 ] ;
rtB . ewt1hyh1w1 [ 0 ] = rtB . ggl2c42ej4 . v_s [ 0 ] ; rtB . hmkhnfnj2o [ 0
] = rtB . ggl2c42ej4 . r_c [ 0 ] ; rtB . lbe030o5eg [ 0 ] = rtB . ggl2c42ej4
. v_c [ 0 ] ; rtB . pu5umgngnw [ 0 ] = rtB . ggl2c42ej4 . r_t [ 0 ] ; rtB .
nkfoxrkhb4 [ 0 ] = rtB . ggl2c42ej4 . v_t [ 0 ] ; rtB . njrvjekzfm [ 1 ] =
rtB . ggl2c42ej4 . thrust_vector [ 1 ] ; rtB . ndieoaonxd [ 1 ] = rtB .
ggl2c42ej4 . r_s [ 1 ] ; rtB . ewt1hyh1w1 [ 1 ] = rtB . ggl2c42ej4 . v_s [ 1
] ; rtB . hmkhnfnj2o [ 1 ] = rtB . ggl2c42ej4 . r_c [ 1 ] ; rtB . lbe030o5eg
[ 1 ] = rtB . ggl2c42ej4 . v_c [ 1 ] ; rtB . pu5umgngnw [ 1 ] = rtB .
ggl2c42ej4 . r_t [ 1 ] ; rtB . nkfoxrkhb4 [ 1 ] = rtB . ggl2c42ej4 . v_t [ 1
] ; rtB . njrvjekzfm [ 2 ] = rtB . ggl2c42ej4 . thrust_vector [ 2 ] ; rtB .
ndieoaonxd [ 2 ] = rtB . ggl2c42ej4 . r_s [ 2 ] ; rtB . ewt1hyh1w1 [ 2 ] =
rtB . ggl2c42ej4 . v_s [ 2 ] ; rtB . hmkhnfnj2o [ 2 ] = rtB . ggl2c42ej4 .
r_c [ 2 ] ; rtB . lbe030o5eg [ 2 ] = rtB . ggl2c42ej4 . v_c [ 2 ] ; rtB .
pu5umgngnw [ 2 ] = rtB . ggl2c42ej4 . r_t [ 2 ] ; rtB . nkfoxrkhb4 [ 2 ] =
rtB . ggl2c42ej4 . v_t [ 2 ] ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { } A [ 0
] = rtP . Gain1_Gain_fe1rn1jbbk [ 0 ] * cizfy4cb2f_idx_0 ; A [ 1 ] = rtP .
Gain1_Gain_fe1rn1jbbk [ 1 ] * cizfy4cb2f_idx_1 ; A [ 2 ] = rtP .
Gain1_Gain_fe1rn1jbbk [ 2 ] * cizfy4cb2f_idx_2 ; A [ 3 ] = rtP .
Gain1_Gain_fe1rn1jbbk [ 3 ] * oufzjameo0_idx_2 ; jt3hs0aizl_idx_0 = A [ 0 ] *
rtP . Constant_Value_fcyoyjujtb - ( ( rtP . P_F . solar_array_vb [ 0 ] * A [
1 ] + rtP . P_F . solar_array_vb [ 1 ] * A [ 2 ] ) + rtP . P_F .
solar_array_vb [ 2 ] * A [ 3 ] ) ; jt3hs0aizl_idx_2 = ( ( A [ 2 ] * rtP . P_F
. solar_array_vb [ 2 ] - A [ 3 ] * rtP . P_F . solar_array_vb [ 1 ] ) + A [ 0
] * rtP . P_F . solar_array_vb [ 0 ] ) + rtP . Constant_Value_fcyoyjujtb * A
[ 1 ] ; moeghwuxxr = ( ( A [ 3 ] * rtP . P_F . solar_array_vb [ 0 ] - A [ 1 ]
* rtP . P_F . solar_array_vb [ 2 ] ) + A [ 0 ] * rtP . P_F . solar_array_vb [
1 ] ) + rtP . Constant_Value_fcyoyjujtb * A [ 2 ] ; scale = ( ( A [ 1 ] * rtP
. P_F . solar_array_vb [ 1 ] - A [ 2 ] * rtP . P_F . solar_array_vb [ 0 ] ) +
A [ 0 ] * rtP . P_F . solar_array_vb [ 2 ] ) + rtP .
Constant_Value_fcyoyjujtb * A [ 3 ] ; hu15wb2s0u = jt3hs0aizl_idx_0 *
cizfy4cb2f_idx_0 - ( ( cizfy4cb2f_idx_1 * jt3hs0aizl_idx_2 + cizfy4cb2f_idx_2
* moeghwuxxr ) + oufzjameo0_idx_2 * scale ) ; rtB . kg4dzhebco [ 0 ] = ( ( (
moeghwuxxr * oufzjameo0_idx_2 - scale * cizfy4cb2f_idx_2 ) + jt3hs0aizl_idx_0
* cizfy4cb2f_idx_1 ) + cizfy4cb2f_idx_0 * jt3hs0aizl_idx_2 ) * ( 1.0 /
hu15wb2s0u ) ; rtB . kg4dzhebco [ 1 ] = ( ( ( scale * cizfy4cb2f_idx_1 -
jt3hs0aizl_idx_2 * oufzjameo0_idx_2 ) + jt3hs0aizl_idx_0 * cizfy4cb2f_idx_2 )
+ cizfy4cb2f_idx_0 * moeghwuxxr ) * ( 1.0 / hu15wb2s0u ) ; rtB . kg4dzhebco [
2 ] = ( ( ( jt3hs0aizl_idx_2 * cizfy4cb2f_idx_2 - moeghwuxxr *
cizfy4cb2f_idx_1 ) + jt3hs0aizl_idx_0 * oufzjameo0_idx_2 ) + cizfy4cb2f_idx_0
* scale ) * ( 1.0 / hu15wb2s0u ) ; A [ 0 ] = rtP . Gain1_Gain_m4frltiumm [ 0
] * cizfy4cb2f_idx_0 ; A [ 1 ] = rtP . Gain1_Gain_m4frltiumm [ 1 ] *
cizfy4cb2f_idx_1 ; A [ 2 ] = rtP . Gain1_Gain_m4frltiumm [ 2 ] *
cizfy4cb2f_idx_2 ; A [ 3 ] = rtP . Gain1_Gain_m4frltiumm [ 3 ] *
oufzjameo0_idx_2 ; jt3hs0aizl_idx_0 = A [ 0 ] * rtP .
Constant_Value_gdyff4hfxx - ( ( rtP . P_F . antenna_vb [ 0 ] * A [ 1 ] + rtP
. P_F . antenna_vb [ 1 ] * A [ 2 ] ) + rtP . P_F . antenna_vb [ 2 ] * A [ 3 ]
) ; jt3hs0aizl_idx_2 = ( ( A [ 2 ] * rtP . P_F . antenna_vb [ 2 ] - A [ 3 ] *
rtP . P_F . antenna_vb [ 1 ] ) + A [ 0 ] * rtP . P_F . antenna_vb [ 0 ] ) +
rtP . Constant_Value_gdyff4hfxx * A [ 1 ] ; moeghwuxxr = ( ( A [ 3 ] * rtP .
P_F . antenna_vb [ 0 ] - A [ 1 ] * rtP . P_F . antenna_vb [ 2 ] ) + A [ 0 ] *
rtP . P_F . antenna_vb [ 1 ] ) + rtP . Constant_Value_gdyff4hfxx * A [ 2 ] ;
scale = ( ( A [ 1 ] * rtP . P_F . antenna_vb [ 1 ] - A [ 2 ] * rtP . P_F .
antenna_vb [ 0 ] ) + A [ 0 ] * rtP . P_F . antenna_vb [ 2 ] ) + rtP .
Constant_Value_gdyff4hfxx * A [ 3 ] ; hu15wb2s0u = jt3hs0aizl_idx_0 *
cizfy4cb2f_idx_0 - ( ( cizfy4cb2f_idx_1 * jt3hs0aizl_idx_2 + cizfy4cb2f_idx_2
* moeghwuxxr ) + oufzjameo0_idx_2 * scale ) ; rtB . fx1eniibgn [ 0 ] = ( ( (
moeghwuxxr * oufzjameo0_idx_2 - scale * cizfy4cb2f_idx_2 ) + jt3hs0aizl_idx_0
* cizfy4cb2f_idx_1 ) + cizfy4cb2f_idx_0 * jt3hs0aizl_idx_2 ) * ( 1.0 /
hu15wb2s0u ) ; rtB . fx1eniibgn [ 1 ] = ( ( ( scale * cizfy4cb2f_idx_1 -
jt3hs0aizl_idx_2 * oufzjameo0_idx_2 ) + jt3hs0aizl_idx_0 * cizfy4cb2f_idx_2 )
+ cizfy4cb2f_idx_0 * moeghwuxxr ) * ( 1.0 / hu15wb2s0u ) ; rtB . fx1eniibgn [
2 ] = ( ( ( jt3hs0aizl_idx_2 * cizfy4cb2f_idx_2 - moeghwuxxr *
cizfy4cb2f_idx_1 ) + jt3hs0aizl_idx_0 * oufzjameo0_idx_2 ) + cizfy4cb2f_idx_0
* scale ) * ( 1.0 / hu15wb2s0u ) ; A [ 0 ] = rtP . Gain1_Gain_nu325gvdxx [ 0
] * cizfy4cb2f_idx_0 ; A [ 1 ] = rtP . Gain1_Gain_nu325gvdxx [ 1 ] *
cizfy4cb2f_idx_1 ; A [ 2 ] = rtP . Gain1_Gain_nu325gvdxx [ 2 ] *
cizfy4cb2f_idx_2 ; A [ 3 ] = rtP . Gain1_Gain_nu325gvdxx [ 3 ] *
oufzjameo0_idx_2 ; jt3hs0aizl_idx_0 = A [ 0 ] * rtP .
Constant_Value_mgesvrfwfg - ( ( rtP . P_F . thruster_vb [ 0 ] * A [ 1 ] + rtP
. P_F . thruster_vb [ 1 ] * A [ 2 ] ) + rtP . P_F . thruster_vb [ 2 ] * A [ 3
] ) ; jt3hs0aizl_idx_2 = ( ( A [ 2 ] * rtP . P_F . thruster_vb [ 2 ] - A [ 3
] * rtP . P_F . thruster_vb [ 1 ] ) + A [ 0 ] * rtP . P_F . thruster_vb [ 0 ]
) + rtP . Constant_Value_mgesvrfwfg * A [ 1 ] ; moeghwuxxr = ( ( A [ 3 ] *
rtP . P_F . thruster_vb [ 0 ] - A [ 1 ] * rtP . P_F . thruster_vb [ 2 ] ) + A
[ 0 ] * rtP . P_F . thruster_vb [ 1 ] ) + rtP . Constant_Value_mgesvrfwfg * A
[ 2 ] ; scale = ( ( A [ 1 ] * rtP . P_F . thruster_vb [ 1 ] - A [ 2 ] * rtP .
P_F . thruster_vb [ 0 ] ) + A [ 0 ] * rtP . P_F . thruster_vb [ 2 ] ) + rtP .
Constant_Value_mgesvrfwfg * A [ 3 ] ; hu15wb2s0u = jt3hs0aizl_idx_0 *
cizfy4cb2f_idx_0 - ( ( cizfy4cb2f_idx_1 * jt3hs0aizl_idx_2 + cizfy4cb2f_idx_2
* moeghwuxxr ) + oufzjameo0_idx_2 * scale ) ; rtB . dbvg0t1pgh [ 0 ] = ( ( (
moeghwuxxr * oufzjameo0_idx_2 - scale * cizfy4cb2f_idx_2 ) + jt3hs0aizl_idx_0
* cizfy4cb2f_idx_1 ) + cizfy4cb2f_idx_0 * jt3hs0aizl_idx_2 ) * ( 1.0 /
hu15wb2s0u ) ; rtB . dbvg0t1pgh [ 1 ] = ( ( ( scale * cizfy4cb2f_idx_1 -
jt3hs0aizl_idx_2 * oufzjameo0_idx_2 ) + jt3hs0aizl_idx_0 * cizfy4cb2f_idx_2 )
+ cizfy4cb2f_idx_0 * moeghwuxxr ) * ( 1.0 / hu15wb2s0u ) ; rtB . dbvg0t1pgh [
2 ] = ( ( ( jt3hs0aizl_idx_2 * cizfy4cb2f_idx_2 - moeghwuxxr *
cizfy4cb2f_idx_1 ) + jt3hs0aizl_idx_0 * oufzjameo0_idx_2 ) + cizfy4cb2f_idx_0
* scale ) * ( 1.0 / hu15wb2s0u ) ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { }
rtB . jwzvety1de [ 0 ] = ( rtB . id3syu3xda [ 0 ] * rtP .
Constant_Value_bpuwj1x24m - ( ( rtU . bhvfzp4veb [ 0 ] * rtB . id3syu3xda [ 1
] + rtU . bhvfzp4veb [ 1 ] * rtB . id3syu3xda [ 2 ] ) + rtU . bhvfzp4veb [ 2
] * rtB . id3syu3xda [ 3 ] ) ) * rtP . Gain_Gain ; rtB . jwzvety1de [ 1 ] = (
( ( rtB . id3syu3xda [ 2 ] * rtU . bhvfzp4veb [ 2 ] - rtB . id3syu3xda [ 3 ]
* rtU . bhvfzp4veb [ 1 ] ) + rtB . id3syu3xda [ 0 ] * rtU . bhvfzp4veb [ 0 ]
) + rtP . Constant_Value_bpuwj1x24m * rtB . id3syu3xda [ 1 ] ) * rtP .
Gain_Gain ; rtB . jwzvety1de [ 2 ] = ( ( ( rtB . id3syu3xda [ 3 ] * rtU .
bhvfzp4veb [ 0 ] - rtB . id3syu3xda [ 1 ] * rtU . bhvfzp4veb [ 2 ] ) + rtB .
id3syu3xda [ 0 ] * rtU . bhvfzp4veb [ 1 ] ) + rtP . Constant_Value_bpuwj1x24m
* rtB . id3syu3xda [ 2 ] ) * rtP . Gain_Gain ; rtB . jwzvety1de [ 3 ] = ( ( (
rtB . id3syu3xda [ 1 ] * rtU . bhvfzp4veb [ 1 ] - rtB . id3syu3xda [ 2 ] *
rtU . bhvfzp4veb [ 0 ] ) + rtB . id3syu3xda [ 0 ] * rtU . bhvfzp4veb [ 2 ] )
+ rtP . Constant_Value_bpuwj1x24m * rtB . id3syu3xda [ 3 ] ) * rtP .
Gain_Gain ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { } jt3hs0aizl_idx_0 = ( rtB
. dbvg0t1pgh [ 0 ] * rtB . dbvg0t1pgh [ 0 ] + rtB . dbvg0t1pgh [ 1 ] * rtB .
dbvg0t1pgh [ 1 ] ) + rtB . dbvg0t1pgh [ 2 ] * rtB . dbvg0t1pgh [ 2 ] ; if (
jt3hs0aizl_idx_0 < 0.0 ) { jt3hs0aizl_idx_0 = - muDoubleScalarSqrt (
muDoubleScalarAbs ( jt3hs0aizl_idx_0 ) ) ; } else { jt3hs0aizl_idx_0 =
muDoubleScalarSqrt ( jt3hs0aizl_idx_0 ) ; } if ( jt3hs0aizl_idx_0 > rtP .
NormalizeVector_maxzero_frofudci2i ) { A [ 0 ] = rtB . dbvg0t1pgh [ 0 ] ; A [
1 ] = rtB . dbvg0t1pgh [ 1 ] ; A [ 2 ] = rtB . dbvg0t1pgh [ 2 ] ; A [ 3 ] =
jt3hs0aizl_idx_0 ; } else { A [ 0 ] = rtB . dbvg0t1pgh [ 0 ] * 0.0 ; A [ 1 ]
= rtB . dbvg0t1pgh [ 1 ] * 0.0 ; A [ 2 ] = rtB . dbvg0t1pgh [ 2 ] * 0.0 ; A [
3 ] = rtP . Constant_Value_i2ujud0fea ; } jt3hs0aizl_idx_2 = A [ 0 ] / A [ 3
] ; moeghwuxxr = A [ 1 ] / A [ 3 ] ; scale = A [ 2 ] / A [ 3 ] ;
jt3hs0aizl_idx_0 = ( rtB . ggl2c42ej4 . thrust_vector [ 0 ] * rtB .
ggl2c42ej4 . thrust_vector [ 0 ] + rtB . ggl2c42ej4 . thrust_vector [ 1 ] *
rtB . ggl2c42ej4 . thrust_vector [ 1 ] ) + rtB . ggl2c42ej4 . thrust_vector [
2 ] * rtB . ggl2c42ej4 . thrust_vector [ 2 ] ; if ( jt3hs0aizl_idx_0 < 0.0 )
{ jt3hs0aizl_idx_0 = - muDoubleScalarSqrt ( muDoubleScalarAbs (
jt3hs0aizl_idx_0 ) ) ; } else { jt3hs0aizl_idx_0 = muDoubleScalarSqrt (
jt3hs0aizl_idx_0 ) ; } if ( jt3hs0aizl_idx_0 > rtP .
NormalizeVector1_maxzero_c1jmgth0uc ) { A [ 0 ] = rtB . ggl2c42ej4 .
thrust_vector [ 0 ] ; A [ 1 ] = rtB . ggl2c42ej4 . thrust_vector [ 1 ] ; A [
2 ] = rtB . ggl2c42ej4 . thrust_vector [ 2 ] ; A [ 3 ] = jt3hs0aizl_idx_0 ; }
else { A [ 0 ] = rtB . ggl2c42ej4 . thrust_vector [ 0 ] * 0.0 ; A [ 1 ] = rtB
. ggl2c42ej4 . thrust_vector [ 1 ] * 0.0 ; A [ 2 ] = rtB . ggl2c42ej4 .
thrust_vector [ 2 ] * 0.0 ; A [ 3 ] = rtP . Constant_Value_bfz3r5ve34 ; } rtB
. mgffwko2vy = ( A [ 0 ] / A [ 3 ] * jt3hs0aizl_idx_2 + A [ 1 ] / A [ 3 ] *
moeghwuxxr ) + A [ 2 ] / A [ 3 ] * scale ; if ( rtP .
ManualSwitch1_CurrentSetting == 1 ) { rtB . p4mnuhzffc = rtB . mgffwko2vy ; }
else { rtB . p4mnuhzffc = rtP . Constant11_Value_howgtgmefa - rtB .
mgffwko2vy ; } if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { } rtB . n5lv0if3fe =
rtB . ggl2c42ej4 . thrust_weight * rtB . p4mnuhzffc ; jt3hs0aizl_idx_0 = (
rtB . ggl2c42ej4 . comms_vector [ 0 ] * rtB . ggl2c42ej4 . comms_vector [ 0 ]
+ rtB . ggl2c42ej4 . comms_vector [ 1 ] * rtB . ggl2c42ej4 . comms_vector [ 1
] ) + rtB . ggl2c42ej4 . comms_vector [ 2 ] * rtB . ggl2c42ej4 . comms_vector
[ 2 ] ; if ( jt3hs0aizl_idx_0 < 0.0 ) { jt3hs0aizl_idx_0 = -
muDoubleScalarSqrt ( muDoubleScalarAbs ( jt3hs0aizl_idx_0 ) ) ; } else {
jt3hs0aizl_idx_0 = muDoubleScalarSqrt ( jt3hs0aizl_idx_0 ) ; } if (
jt3hs0aizl_idx_0 > rtP . NormalizeVector_maxzero_p3wnqley4p ) { A [ 0 ] = rtB
. ggl2c42ej4 . comms_vector [ 0 ] ; A [ 1 ] = rtB . ggl2c42ej4 . comms_vector
[ 1 ] ; A [ 2 ] = rtB . ggl2c42ej4 . comms_vector [ 2 ] ; A [ 3 ] =
jt3hs0aizl_idx_0 ; } else { A [ 0 ] = rtB . ggl2c42ej4 . comms_vector [ 0 ] *
0.0 ; A [ 1 ] = rtB . ggl2c42ej4 . comms_vector [ 1 ] * 0.0 ; A [ 2 ] = rtB .
ggl2c42ej4 . comms_vector [ 2 ] * 0.0 ; A [ 3 ] = rtP .
Constant_Value_osq1m5ngw5 ; } jt3hs0aizl_idx_2 = A [ 0 ] / A [ 3 ] ;
moeghwuxxr = A [ 1 ] / A [ 3 ] ; scale = A [ 2 ] / A [ 3 ] ; jt3hs0aizl_idx_0
= ( rtB . fx1eniibgn [ 0 ] * rtB . fx1eniibgn [ 0 ] + rtB . fx1eniibgn [ 1 ]
* rtB . fx1eniibgn [ 1 ] ) + rtB . fx1eniibgn [ 2 ] * rtB . fx1eniibgn [ 2 ]
; if ( jt3hs0aizl_idx_0 < 0.0 ) { jt3hs0aizl_idx_0 = - muDoubleScalarSqrt (
muDoubleScalarAbs ( jt3hs0aizl_idx_0 ) ) ; } else { jt3hs0aizl_idx_0 =
muDoubleScalarSqrt ( jt3hs0aizl_idx_0 ) ; } if ( jt3hs0aizl_idx_0 > rtP .
NormalizeVector1_maxzero_d0tqs3zyle ) { A [ 0 ] = rtB . fx1eniibgn [ 0 ] ; A
[ 1 ] = rtB . fx1eniibgn [ 1 ] ; A [ 2 ] = rtB . fx1eniibgn [ 2 ] ; A [ 3 ] =
jt3hs0aizl_idx_0 ; } else { A [ 0 ] = rtB . fx1eniibgn [ 0 ] * 0.0 ; A [ 1 ]
= rtB . fx1eniibgn [ 1 ] * 0.0 ; A [ 2 ] = rtB . fx1eniibgn [ 2 ] * 0.0 ; A [
3 ] = rtP . Constant_Value_n5p1mlb1zj ; } if ( rtP .
ManualSwitch1_CurrentSetting_kps3rcsvpl == 1 ) { jt3hs0aizl_idx_2 = ( A [ 0 ]
/ A [ 3 ] * jt3hs0aizl_idx_2 + A [ 1 ] / A [ 3 ] * moeghwuxxr ) + A [ 2 ] / A
[ 3 ] * scale ; if ( jt3hs0aizl_idx_2 > rtP . Saturation_UpperSat_ex5fckh1e5
) { rtB . fmpx14rdcd = rtP . Saturation_UpperSat_ex5fckh1e5 ; } else if (
jt3hs0aizl_idx_2 < rtP . Saturation_LowerSat_nqfyaemvcp ) { rtB . fmpx14rdcd
= rtP . Saturation_LowerSat_nqfyaemvcp ; } else { rtB . fmpx14rdcd =
jt3hs0aizl_idx_2 ; } } else { jt3hs0aizl_idx_2 = ( A [ 0 ] / A [ 3 ] *
jt3hs0aizl_idx_2 + A [ 1 ] / A [ 3 ] * moeghwuxxr ) + A [ 2 ] / A [ 3 ] *
scale ; if ( jt3hs0aizl_idx_2 > rtP . Saturation_UpperSat_ex5fckh1e5 ) {
jt3hs0aizl_idx_2 = rtP . Saturation_UpperSat_ex5fckh1e5 ; } else { if (
jt3hs0aizl_idx_2 < rtP . Saturation_LowerSat_nqfyaemvcp ) { jt3hs0aizl_idx_2
= rtP . Saturation_LowerSat_nqfyaemvcp ; } } rtB . fmpx14rdcd = rtP .
Constant11_Value_hvpxwvfqmk - jt3hs0aizl_idx_2 ; } if ( ssIsSampleHit ( rtS ,
1 , 0 ) ) { } rtB . haese0mx0t = rtB . ggl2c42ej4 . comms_occulted_boolean *
rtB . fmpx14rdcd ; jt3hs0aizl_idx_0 = ( rtB . ggl2c42ej4 . solar_vector [ 0 ]
* rtB . ggl2c42ej4 . solar_vector [ 0 ] + rtB . ggl2c42ej4 . solar_vector [ 1
] * rtB . ggl2c42ej4 . solar_vector [ 1 ] ) + rtB . ggl2c42ej4 . solar_vector
[ 2 ] * rtB . ggl2c42ej4 . solar_vector [ 2 ] ; if ( jt3hs0aizl_idx_0 < 0.0 )
{ jt3hs0aizl_idx_0 = - muDoubleScalarSqrt ( muDoubleScalarAbs (
jt3hs0aizl_idx_0 ) ) ; } else { jt3hs0aizl_idx_0 = muDoubleScalarSqrt (
jt3hs0aizl_idx_0 ) ; } if ( jt3hs0aizl_idx_0 > rtP .
NormalizeVector_maxzero_jv521hznkv ) { A [ 0 ] = rtB . ggl2c42ej4 .
solar_vector [ 0 ] ; A [ 1 ] = rtB . ggl2c42ej4 . solar_vector [ 1 ] ; A [ 2
] = rtB . ggl2c42ej4 . solar_vector [ 2 ] ; A [ 3 ] = jt3hs0aizl_idx_0 ; }
else { A [ 0 ] = rtB . ggl2c42ej4 . solar_vector [ 0 ] * 0.0 ; A [ 1 ] = rtB
. ggl2c42ej4 . solar_vector [ 1 ] * 0.0 ; A [ 2 ] = rtB . ggl2c42ej4 .
solar_vector [ 2 ] * 0.0 ; A [ 3 ] = rtP . Constant_Value_kubckzbqj3 ; }
jt3hs0aizl_idx_2 = A [ 0 ] / A [ 3 ] ; moeghwuxxr = A [ 1 ] / A [ 3 ] ; scale
= A [ 2 ] / A [ 3 ] ; jt3hs0aizl_idx_0 = ( rtB . kg4dzhebco [ 0 ] * rtB .
kg4dzhebco [ 0 ] + rtB . kg4dzhebco [ 1 ] * rtB . kg4dzhebco [ 1 ] ) + rtB .
kg4dzhebco [ 2 ] * rtB . kg4dzhebco [ 2 ] ; if ( jt3hs0aizl_idx_0 < 0.0 ) {
jt3hs0aizl_idx_0 = - muDoubleScalarSqrt ( muDoubleScalarAbs (
jt3hs0aizl_idx_0 ) ) ; } else { jt3hs0aizl_idx_0 = muDoubleScalarSqrt (
jt3hs0aizl_idx_0 ) ; } if ( jt3hs0aizl_idx_0 > rtP .
NormalizeVector1_maxzero_gagywgljsc ) { A [ 0 ] = rtB . kg4dzhebco [ 0 ] ; A
[ 1 ] = rtB . kg4dzhebco [ 1 ] ; A [ 2 ] = rtB . kg4dzhebco [ 2 ] ; A [ 3 ] =
jt3hs0aizl_idx_0 ; } else { A [ 0 ] = rtB . kg4dzhebco [ 0 ] * 0.0 ; A [ 1 ]
= rtB . kg4dzhebco [ 1 ] * 0.0 ; A [ 2 ] = rtB . kg4dzhebco [ 2 ] * 0.0 ; A [
3 ] = rtP . Constant_Value_lfkufjj3ic ; } jt3hs0aizl_idx_2 = ( A [ 0 ] / A [
3 ] * jt3hs0aizl_idx_2 + A [ 1 ] / A [ 3 ] * moeghwuxxr ) + A [ 2 ] / A [ 3 ]
* scale ; if ( jt3hs0aizl_idx_2 > rtP . Saturation_UpperSat_laawyukirp ) {
jt3hs0aizl_idx_2 = rtP . Saturation_UpperSat_laawyukirp ; } else { if (
jt3hs0aizl_idx_2 < rtP . Saturation_LowerSat_pjistqqcmw ) { jt3hs0aizl_idx_2
= rtP . Saturation_LowerSat_pjistqqcmw ; } } rtB . jtzgz1uiwi = rtB .
ggl2c42ej4 . solar_occulted_boolean * muDoubleScalarAbs ( jt3hs0aizl_idx_2 )
; rtB . gdkatceig2 = ssGetT ( rtS ) ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) {
} rtB . bqvggehzz5 = ( rtB . hcaghgg2d4 - rtB . gdkatceig2 <= rtP .
Constant_Value_kw5w4qkv5v ) ; if ( ssIsSampleHit ( rtS , 1 , 0 ) && rtB .
bqvggehzz5 ) { ssSetStopRequested ( rtS , 1 ) ; } UNUSED_PARAMETER ( tid ) ;
} void MdlOutputsTID2 ( int_T tid ) { rtB . hcaghgg2d4 = 0.999 * rtP . P_E .
P ; UNUSED_PARAMETER ( tid ) ; } void MdlUpdate ( int_T tid ) { rtDW .
ag2rcaep41 = 0 ; UNUSED_PARAMETER ( tid ) ; } void MdlUpdateTID2 ( int_T tid
) { UNUSED_PARAMETER ( tid ) ; } void MdlDerivatives ( void ) { XDot *
_rtXdot ; _rtXdot = ( ( XDot * ) ssGetdX ( rtS ) ) ; _rtXdot -> kvd5s5mhzq [
0 ] = rtB . jwzvety1de [ 0 ] ; _rtXdot -> kvd5s5mhzq [ 1 ] = rtB . jwzvety1de
[ 1 ] ; _rtXdot -> kvd5s5mhzq [ 2 ] = rtB . jwzvety1de [ 2 ] ; _rtXdot ->
kvd5s5mhzq [ 3 ] = rtB . jwzvety1de [ 3 ] ; _rtXdot -> oznfot3xd2 = rtB .
jtzgz1uiwi ; _rtXdot -> gi0dbsjbab = rtB . haese0mx0t ; _rtXdot -> ndr0ddj14l
= rtB . ggl2c42ej4 . thrust_weight ; _rtXdot -> f5kva1vvha = rtB . n5lv0if3fe
; } void MdlProjection ( void ) { } void MdlTerminate ( void ) { { const char
* errMsg = ( NULL ) ; void * fp = ( void * ) rtDW . p5wpguxq2t . PrevTimePtr
; if ( fp != ( NULL ) ) { errMsg = rtwMatFileLoaderCollectionDestroyInstance
( 1 , fp ) ; if ( errMsg != ( NULL ) ) { ssSetErrorStatus ( rtS , errMsg ) ;
return ; } } } ftsgw51zjp ( & rtDW . fbz1lrgadk1 ) ; ftsgw51zjp ( & rtDW .
fbz1lrgadk1o ) ; onxlpkziey ( & rtDW . juzdrgfwywb ) ; onxlpkziey ( & rtDW .
juzdrgfwywbn ) ; if ( rt_slioCatalogue ( ) != ( NULL ) ) { void * *
slioCatalogueAddr = rt_slioCatalogueAddr ( ) ; rtwSaveDatasetsToMatFile (
rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) ,
rt_GetMatSigstreamLoggingFileName ( ) ) ; rtwTerminateSlioCatalogue (
slioCatalogueAddr ) ; * slioCatalogueAddr = NULL ; } } void
MdlInitializeSizes ( void ) { ssSetNumContStates ( rtS , 8 ) ;
ssSetNumPeriodicContStates ( rtS , 0 ) ; ssSetNumY ( rtS , 0 ) ; ssSetNumU (
rtS , 3 ) ; ssSetDirectFeedThrough ( rtS , 1 ) ; ssSetNumSampleTimes ( rtS ,
2 ) ; ssSetNumBlocks ( rtS , 430 ) ; ssSetNumBlockIO ( rtS , 47 ) ;
ssSetNumBlockParams ( rtS , 217 ) ; } void MdlInitializeSampleTimes ( void )
{ ssSetSampleTime ( rtS , 0 , 0.0 ) ; ssSetSampleTime ( rtS , 1 , 10.0 ) ;
ssSetOffsetTime ( rtS , 0 , 0.0 ) ; ssSetOffsetTime ( rtS , 1 , 0.0 ) ; }
void raccel_set_checksum ( ) { ssSetChecksumVal ( rtS , 0 , 3803236602U ) ;
ssSetChecksumVal ( rtS , 1 , 2346542714U ) ; ssSetChecksumVal ( rtS , 2 ,
3261620555U ) ; ssSetChecksumVal ( rtS , 3 , 2040919633U ) ; }
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
( B ) ) ; } { ssSetU ( rtS , ( ( void * ) & rtU ) ) ; ( void ) memset ( & rtU
, 0 , sizeof ( ExtU ) ) ; } { real_T * x = ( real_T * ) & rtX ;
ssSetContStates ( rtS , x ) ; ( void ) memset ( ( void * ) x , 0 , sizeof ( X
) ) ; } { void * dwork = ( void * ) & rtDW ; ssSetRootDWork ( rtS , dwork ) ;
( void ) memset ( dwork , 0 , sizeof ( DW ) ) ; } { static DataTypeTransInfo
dtInfo ; ( void ) memset ( ( char_T * ) & dtInfo , 0 , sizeof ( dtInfo ) ) ;
ssSetModelMappingInfo ( rtS , & dtInfo ) ; dtInfo . numDataTypes = 22 ;
dtInfo . dataTypeSizes = & rtDataTypeSizes [ 0 ] ; dtInfo . dataTypeNames = &
rtDataTypeNames [ 0 ] ; dtInfo . BTransTable = & rtBTransTable ; dtInfo .
PTransTable = & rtPTransTable ; dtInfo . dataTypeInfoTable =
rtDataTypeInfoTable ; } attitude3d_InitializeDataMapInfo ( ) ;
ssSetIsRapidAcceleratorActive ( rtS , true ) ; ssSetRootSS ( rtS , rtS ) ;
ssSetVersion ( rtS , SIMSTRUCT_VERSION_LEVEL2 ) ; ssSetModelName ( rtS ,
"attitude3d" ) ; ssSetPath ( rtS , "attitude3d" ) ; ssSetTStart ( rtS , 0.0 )
; ssSetTFinal ( rtS , 6530.0 ) ; ssSetStepSize ( rtS , 10.0 ) ;
ssSetFixedStepSize ( rtS , 10.0 ) ; { static RTWLogInfo rt_DataLoggingInfo ;
rt_DataLoggingInfo . loggingInterval = NULL ; ssSetRTWLogInfo ( rtS , &
rt_DataLoggingInfo ) ; } { rtliSetLogXSignalInfo ( ssGetRTWLogInfo ( rtS ) ,
( NULL ) ) ; rtliSetLogXSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ;
rtliSetLogT ( ssGetRTWLogInfo ( rtS ) , "tout" ) ; rtliSetLogX (
ssGetRTWLogInfo ( rtS ) , "" ) ; rtliSetLogXFinal ( ssGetRTWLogInfo ( rtS ) ,
"" ) ; rtliSetLogVarNameModifier ( ssGetRTWLogInfo ( rtS ) , "none" ) ;
rtliSetLogFormat ( ssGetRTWLogInfo ( rtS ) , 4 ) ; rtliSetLogMaxRows (
ssGetRTWLogInfo ( rtS ) , 0 ) ; rtliSetLogDecimation ( ssGetRTWLogInfo ( rtS
) , 1 ) ; rtliSetLogY ( ssGetRTWLogInfo ( rtS ) , "" ) ;
rtliSetLogYSignalInfo ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ;
rtliSetLogYSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ; } { static
struct _ssStatesInfo2 statesInfo2 ; ssSetStatesInfo2 ( rtS , & statesInfo2 )
; } { static ssPeriodicStatesInfo periodicStatesInfo ;
ssSetPeriodicStatesInfo ( rtS , & periodicStatesInfo ) ; } { static
ssSolverInfo slvrInfo ; static boolean_T contStatesDisabled [ 8 ] ;
ssSetSolverInfo ( rtS , & slvrInfo ) ; ssSetSolverName ( rtS , "ode4" ) ;
ssSetVariableStepSolver ( rtS , 0 ) ; ssSetSolverConsistencyChecking ( rtS ,
0 ) ; ssSetSolverAdaptiveZcDetection ( rtS , 0 ) ;
ssSetSolverRobustResetMethod ( rtS , 0 ) ; ssSetSolverStateProjection ( rtS ,
0 ) ; ssSetSolverMassMatrixType ( rtS , ( ssMatrixType ) 0 ) ;
ssSetSolverMassMatrixNzMax ( rtS , 0 ) ; ssSetModelOutputs ( rtS , MdlOutputs
) ; ssSetModelLogData ( rtS , rt_UpdateTXYLogVars ) ;
ssSetModelLogDataIfInInterval ( rtS , rt_UpdateTXXFYLogVars ) ;
ssSetModelUpdate ( rtS , MdlUpdate ) ; ssSetModelDerivatives ( rtS ,
MdlDerivatives ) ; ssSetTNextTid ( rtS , INT_MIN ) ; ssSetTNext ( rtS ,
rtMinusInf ) ; ssSetSolverNeedsReset ( rtS ) ; ssSetNumNonsampledZCs ( rtS ,
0 ) ; ssSetContStateDisabled ( rtS , contStatesDisabled ) ; }
ssSetChecksumVal ( rtS , 0 , 3803236602U ) ; ssSetChecksumVal ( rtS , 1 ,
2346542714U ) ; ssSetChecksumVal ( rtS , 2 , 3261620555U ) ; ssSetChecksumVal
( rtS , 3 , 2040919633U ) ; { static const sysRanDType rtAlwaysEnabled =
SUBSYS_RAN_BC_ENABLE ; static RTWExtModeInfo rt_ExtModeInfo ; static const
sysRanDType * systemRan [ 23 ] ; gblRTWExtModeInfo = & rt_ExtModeInfo ;
ssSetRTWExtModeInfo ( rtS , & rt_ExtModeInfo ) ;
rteiSetSubSystemActiveVectorAddresses ( & rt_ExtModeInfo , systemRan ) ;
systemRan [ 0 ] = & rtAlwaysEnabled ; systemRan [ 1 ] = & rtAlwaysEnabled ;
systemRan [ 2 ] = & rtAlwaysEnabled ; systemRan [ 3 ] = & rtAlwaysEnabled ;
systemRan [ 4 ] = & rtAlwaysEnabled ; systemRan [ 5 ] = & rtAlwaysEnabled ;
systemRan [ 6 ] = & rtAlwaysEnabled ; systemRan [ 7 ] = & rtAlwaysEnabled ;
systemRan [ 8 ] = & rtAlwaysEnabled ; systemRan [ 9 ] = & rtAlwaysEnabled ;
systemRan [ 10 ] = & rtAlwaysEnabled ; systemRan [ 11 ] = & rtAlwaysEnabled ;
systemRan [ 12 ] = & rtAlwaysEnabled ; systemRan [ 13 ] = & rtAlwaysEnabled ;
systemRan [ 14 ] = & rtAlwaysEnabled ; systemRan [ 15 ] = & rtAlwaysEnabled ;
systemRan [ 16 ] = & rtAlwaysEnabled ; systemRan [ 17 ] = & rtAlwaysEnabled ;
systemRan [ 18 ] = & rtAlwaysEnabled ; systemRan [ 19 ] = & rtAlwaysEnabled ;
systemRan [ 20 ] = & rtAlwaysEnabled ; systemRan [ 21 ] = & rtAlwaysEnabled ;
systemRan [ 22 ] = & rtAlwaysEnabled ; rteiSetModelMappingInfoPtr (
ssGetRTWExtModeInfo ( rtS ) , & ssGetModelMappingInfo ( rtS ) ) ;
rteiSetChecksumsPtr ( ssGetRTWExtModeInfo ( rtS ) , ssGetChecksums ( rtS ) )
; rteiSetTPtr ( ssGetRTWExtModeInfo ( rtS ) , ssGetTPtr ( rtS ) ) ; } return
rtS ; }
#if defined(_MSC_VER)
#pragma optimize( "", on )
#endif
const int_T gblParameterTuningTid = 2 ; void MdlOutputsParameterSampleTime (
int_T tid ) { MdlOutputsTID2 ( tid ) ; }
