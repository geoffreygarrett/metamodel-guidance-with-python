#include "__cf_attitude3d.h"
#ifndef RTW_HEADER_attitude3d_types_h_
#define RTW_HEADER_attitude3d_types_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#ifndef DEFINED_TYPEDEF_FOR_ENVIRONMENT_
#define DEFINED_TYPEDEF_FOR_ENVIRONMENT_
typedef struct { real_T thrust_vector [ 3 ] ; real_T thrust_weight ; real_T
solar_occulted_integral ; real_T solar_occulted_boolean ; real_T solar_vector
[ 3 ] ; real_T comms_occulted_integral ; real_T comms_occulted_boolean ;
real_T comms_vector [ 3 ] ; real_T r_s [ 3 ] ; real_T v_s [ 3 ] ; real_T r_c
[ 3 ] ; real_T v_c [ 3 ] ; real_T r_t [ 3 ] ; real_T v_t [ 3 ] ; }
ENVIRONMENT ;
#endif
#ifndef DEFINED_TYPEDEF_FOR_struct_nois8vFfP57DutoSgf9HZD_
#define DEFINED_TYPEDEF_FOR_struct_nois8vFfP57DutoSgf9HZD_
typedef struct { real_T star_sensor_1_vb [ 3 ] ; real_T star_sensor_2_vb [ 3
] ; real_T thruster_vb [ 3 ] ; real_T antenna_vb [ 3 ] ; real_T
solar_array_vb [ 3 ] ; real_T thrust_shadow_weight ; real_T
thrust_no_shadow_weight ; real_T window_t ; int16_T window_n ; uint8_T
sl_padding0 [ 6 ] ; } struct_nois8vFfP57DutoSgf9HZD ;
#endif
#ifndef DEFINED_TYPEDEF_FOR_struct_rawc2dqRCLbbSQv98WCoDC_
#define DEFINED_TYPEDEF_FOR_struct_rawc2dqRCLbbSQv98WCoDC_
typedef struct { real_T max_omega [ 3 ] ; real_T init_vel_vec [ 3 ] ; real_T
init_pos_vec [ 3 ] ; real_T init_xBI [ 3 ] ; real_T init_yBI [ 3 ] ; real_T
init_zBI [ 3 ] ; } struct_rawc2dqRCLbbSQv98WCoDC ;
#endif
#ifndef DEFINED_TYPEDEF_FOR_struct_qj1aZXRxDpRc9BsHnZQAtC_
#define DEFINED_TYPEDEF_FOR_struct_qj1aZXRxDpRc9BsHnZQAtC_
typedef struct { real_T sun_grav_param ; real_T target_grav_param ; real_T
target_mean_sma ; real_T target_mean_radius ; real_T satellite_h ; real_T
satellite_sma ; real_T mean_motion ; real_T P ; real_T comms_mean_sma ;
real_T initial_classical_satellite [ 7 ] ; real_T initial_classical_target [
7 ] ; real_T initial_classical_comms [ 7 ] ; } struct_qj1aZXRxDpRc9BsHnZQAtC
;
#endif
#ifndef typedef_it1m1m5jgb
#define typedef_it1m1m5jgb
typedef struct { int32_T isInitialized ; boolean_T isSetupComplete ; real_T
pCumMin ; } it1m1m5jgb ;
#endif
#ifndef typedef_epls3zpd4h
#define typedef_epls3zpd4h
typedef struct { uint32_T f1 [ 8 ] ; } epls3zpd4h ;
#endif
#ifndef typedef_oiijeexccd
#define typedef_oiijeexccd
typedef struct { boolean_T matlabCodegenIsDeleted ; int32_T isInitialized ;
boolean_T isSetupComplete ; epls3zpd4h inputVarSize ; int32_T NumChannels ;
it1m1m5jgb * pStat ; } oiijeexccd ;
#endif
#ifndef typedef_j510l0uc1d
#define typedef_j510l0uc1d
typedef struct { int32_T isInitialized ; boolean_T isSetupComplete ; real_T
pCumMax ; } j510l0uc1d ;
#endif
#ifndef typedef_hkrvp5gzcl
#define typedef_hkrvp5gzcl
typedef struct { boolean_T matlabCodegenIsDeleted ; int32_T isInitialized ;
boolean_T isSetupComplete ; epls3zpd4h inputVarSize ; int32_T NumChannels ;
j510l0uc1d * pStat ; } hkrvp5gzcl ;
#endif
typedef struct P_ P ;
#endif
