#include "__cf_attitude3d.h"
#ifndef RTW_HEADER_attitude3d_cap_host_h_
#define RTW_HEADER_attitude3d_cap_host_h_
#ifdef HOST_CAPI_BUILD
#include "rtw_capi.h"
#include "rtw_modelmap.h"
typedef struct { rtwCAPI_ModelMappingInfo mmi ; }
attitude3d_host_DataMapInfo_T ;
#ifdef __cplusplus
extern "C" {
#endif
void attitude3d_host_InitializeDataMapInfo ( attitude3d_host_DataMapInfo_T *
dataMap , const char * path ) ;
#ifdef __cplusplus
}
#endif
#endif
#endif
