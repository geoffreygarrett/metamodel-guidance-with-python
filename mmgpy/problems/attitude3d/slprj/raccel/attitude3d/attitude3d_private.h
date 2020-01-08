#include "__cf_attitude3d.h"
#ifndef RTW_HEADER_attitude3d_private_h_
#define RTW_HEADER_attitude3d_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "attitude3d.h"
#if !defined(rt_VALIDATE_MEMORY)
#define rt_VALIDATE_MEMORY(S, ptr)   if(!(ptr)) {\
  ssSetErrorStatus(rtS, RT_MEMORY_ALLOCATION_ERROR);\
  }
#endif
#if !defined(rt_FREE)
#if !defined(_WIN32)
#define rt_FREE(ptr)   if((ptr) != (NULL)) {\
  free((ptr));\
  (ptr) = (NULL);\
  }
#else
#define rt_FREE(ptr)   if((ptr) != (NULL)) {\
  free((void *)(ptr));\
  (ptr) = (NULL);\
  }
#endif
#endif
extern void esdot54nug ( pqlrpaqdev * localDW ) ; extern void ekt4d0juw0 (
pqlrpaqdev * localDW ) ; extern void fbz1lrgadk ( real_T okfdlrvjbv ,
lhr0fwp232 * localB , pqlrpaqdev * localDW ) ; extern void a2gsmdpwl3 (
abmczhmvhh * localDW ) ; extern void bqfcltg4dy ( abmczhmvhh * localDW ) ;
extern void juzdrgfwyw ( real_T okfdlrvjbv , oolcbzau2s * localB , abmczhmvhh
* localDW ) ; extern void ftsgw51zjp ( pqlrpaqdev * localDW ) ; extern void
onxlpkziey ( abmczhmvhh * localDW ) ;
#if defined(MULTITASKING)
#error Model (attitude3d) was built in \SingleTasking solver mode, however the MULTITASKING define is \present. If you have multitasking (e.g. -DMT or -DMULTITASKING) \defined on the Code Generation page of Simulation parameter dialog, please \remove it and on the Solver page, select solver mode \MultiTasking. If the Simulation parameter dialog is configured \correctly, please verify that your template makefile is \configured correctly.
#endif
#endif
