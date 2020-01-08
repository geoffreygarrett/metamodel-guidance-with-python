#include "__cf_attitude3d.h"
#include "ext_types.h"
static DataTypeInfo rtDataTypeInfoTable [ ] = { { "real_T" , 0 , 8 } , {
"real32_T" , 1 , 4 } , { "int8_T" , 2 , 1 } , { "uint8_T" , 3 , 1 } , {
"int16_T" , 4 , 2 } , { "uint16_T" , 5 , 2 } , { "int32_T" , 6 , 4 } , {
"uint32_T" , 7 , 4 } , { "boolean_T" , 8 , 1 } , { "fcn_call_T" , 9 , 0 } , {
"int_T" , 10 , 4 } , { "pointer_T" , 11 , 8 } , { "action_T" , 12 , 8 } , {
"timer_uint32_pair_T" , 13 , 8 } , { "struct_nois8vFfP57DutoSgf9HZD" , 14 ,
152 } , { "struct_rawc2dqRCLbbSQv98WCoDC" , 15 , 144 } , {
"struct_qj1aZXRxDpRc9BsHnZQAtC" , 16 , 240 } , { "ENVIRONMENT" , 17 , 256 } ,
{ "oiijeexccd" , 18 , 56 } , { "it1m1m5jgb" , 19 , 16 } , { "hkrvp5gzcl" , 20
, 56 } , { "j510l0uc1d" , 21 , 16 } } ; static uint_T rtDataTypeSizes [ ] = {
sizeof ( real_T ) , sizeof ( real32_T ) , sizeof ( int8_T ) , sizeof (
uint8_T ) , sizeof ( int16_T ) , sizeof ( uint16_T ) , sizeof ( int32_T ) ,
sizeof ( uint32_T ) , sizeof ( boolean_T ) , sizeof ( fcn_call_T ) , sizeof (
int_T ) , sizeof ( pointer_T ) , sizeof ( action_T ) , 2 * sizeof ( uint32_T
) , sizeof ( struct_nois8vFfP57DutoSgf9HZD ) , sizeof (
struct_rawc2dqRCLbbSQv98WCoDC ) , sizeof ( struct_qj1aZXRxDpRc9BsHnZQAtC ) ,
sizeof ( ENVIRONMENT ) , sizeof ( oiijeexccd ) , sizeof ( it1m1m5jgb ) ,
sizeof ( hkrvp5gzcl ) , sizeof ( j510l0uc1d ) } ; static const char_T *
rtDataTypeNames [ ] = { "real_T" , "real32_T" , "int8_T" , "uint8_T" ,
"int16_T" , "uint16_T" , "int32_T" , "uint32_T" , "boolean_T" , "fcn_call_T"
, "int_T" , "pointer_T" , "action_T" , "timer_uint32_pair_T" ,
"struct_nois8vFfP57DutoSgf9HZD" , "struct_rawc2dqRCLbbSQv98WCoDC" ,
"struct_qj1aZXRxDpRc9BsHnZQAtC" , "ENVIRONMENT" , "oiijeexccd" , "it1m1m5jgb"
, "hkrvp5gzcl" , "j510l0uc1d" } ; static DataTypeTransition rtBTransitions [
] = { { ( char_T * ) ( & rtB . ggl2c42ej4 ) , 17 , 0 , 1 } , { ( char_T * ) (
& rtB . j3dtcamj3h [ 0 ] ) , 0 , 0 , 74 } , { ( char_T * ) ( & rtB .
bqvggehzz5 ) , 8 , 0 , 1 } , { ( char_T * ) ( & rtB . juzdrgfwywbn .
ezrshmdyuk ) , 0 , 0 , 1 } , { ( char_T * ) ( & rtB . juzdrgfwywb .
ezrshmdyuk ) , 0 , 0 , 1 } , { ( char_T * ) ( & rtB . fbz1lrgadk1o .
olimizud5z ) , 0 , 0 , 1 } , { ( char_T * ) ( & rtB . fbz1lrgadk1 .
olimizud5z ) , 0 , 0 , 1 } , { ( char_T * ) ( & rtDW . nrt1u3ug04 [ 0 ] ) , 0
, 0 , 118 } , { ( char_T * ) ( & rtDW . ahlf4oinxv . LoggedData ) , 11 , 0 ,
43 } , { ( char_T * ) ( & rtDW . ag2rcaep41 ) , 10 , 0 , 1 } , { ( char_T * )
( & rtDW . juzdrgfwywbn . jsyeqj31fa ) , 20 , 0 , 1 } , { ( char_T * ) ( &
rtDW . juzdrgfwywbn . aivxxmxdyh ) , 21 , 0 , 2 } , { ( char_T * ) ( & rtDW .
juzdrgfwywbn . d1vg1xnbad ) , 8 , 0 , 1 } , { ( char_T * ) ( & rtDW .
juzdrgfwywb . jsyeqj31fa ) , 20 , 0 , 1 } , { ( char_T * ) ( & rtDW .
juzdrgfwywb . aivxxmxdyh ) , 21 , 0 , 2 } , { ( char_T * ) ( & rtDW .
juzdrgfwywb . d1vg1xnbad ) , 8 , 0 , 1 } , { ( char_T * ) ( & rtDW .
fbz1lrgadk1o . bdmeifvj0g ) , 18 , 0 , 1 } , { ( char_T * ) ( & rtDW .
fbz1lrgadk1o . kfvrm3e5fw ) , 19 , 0 , 2 } , { ( char_T * ) ( & rtDW .
fbz1lrgadk1o . phxfrbtrrv ) , 8 , 0 , 1 } , { ( char_T * ) ( & rtDW .
fbz1lrgadk1 . bdmeifvj0g ) , 18 , 0 , 1 } , { ( char_T * ) ( & rtDW .
fbz1lrgadk1 . kfvrm3e5fw ) , 19 , 0 , 2 } , { ( char_T * ) ( & rtDW .
fbz1lrgadk1 . phxfrbtrrv ) , 8 , 0 , 1 } } ; static DataTypeTransitionTable
rtBTransTable = { 22U , rtBTransitions } ; static DataTypeTransition
rtPTransitions [ ] = { { ( char_T * ) ( & rtP . P_E ) , 16 , 0 , 1 } , { (
char_T * ) ( & rtP . P_F ) , 14 , 0 , 1 } , { ( char_T * ) ( & rtP . P_X ) ,
15 , 0 , 1 } , { ( char_T * ) ( & rtP . NormalizeVector_maxzero ) , 0 , 0 ,
212 } , { ( char_T * ) ( & rtP . ManualSwitch1_CurrentSetting ) , 3 , 0 , 2 }
} ; static DataTypeTransitionTable rtPTransTable = { 5U , rtPTransitions } ;
