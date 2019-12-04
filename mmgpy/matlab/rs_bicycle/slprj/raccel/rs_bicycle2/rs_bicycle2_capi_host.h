#include "__cf_rs_bicycle2.h"
#ifndef RTW_HEADER_rs_bicycle2_cap_host_h_
#define RTW_HEADER_rs_bicycle2_cap_host_h_
#ifdef HOST_CAPI_BUILD
#include "rtw_capi.h"
#include "rtw_modelmap.h"
typedef struct { rtwCAPI_ModelMappingInfo mmi ; }
rs_bicycle2_host_DataMapInfo_T ;
#ifdef __cplusplus
extern "C" {
#endif
void rs_bicycle2_host_InitializeDataMapInfo ( rs_bicycle2_host_DataMapInfo_T
* dataMap , const char * path ) ;
#ifdef __cplusplus
}
#endif
#endif
#endif
