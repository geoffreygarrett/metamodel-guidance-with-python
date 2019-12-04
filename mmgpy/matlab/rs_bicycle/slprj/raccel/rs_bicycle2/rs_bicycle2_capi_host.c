#include "rs_bicycle2_capi_host.h"
static rs_bicycle2_host_DataMapInfo_T root;
static int initialized = 0;
rtwCAPI_ModelMappingInfo *getRootMappingInfo()
{
    if (initialized == 0) {
        initialized = 1;
        rs_bicycle2_host_InitializeDataMapInfo(&(root), "rs_bicycle2");
    }
    return &root.mmi;
}

rtwCAPI_ModelMappingInfo *mexFunction() {return(getRootMappingInfo());}
