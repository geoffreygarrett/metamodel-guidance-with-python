#include "rs_bicycle_capi_host.h"
static rs_bicycle_host_DataMapInfo_T root;
static int initialized = 0;
rtwCAPI_ModelMappingInfo *getRootMappingInfo()
{
    if (initialized == 0) {
        initialized = 1;
        rs_bicycle_host_InitializeDataMapInfo(&(root), "rs_bicycle");
    }
    return &root.mmi;
}

rtwCAPI_ModelMappingInfo *mexFunction() {return(getRootMappingInfo());}
