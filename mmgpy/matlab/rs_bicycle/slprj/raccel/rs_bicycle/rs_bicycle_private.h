#include "__cf_rs_bicycle.h"
#ifndef RTW_HEADER_rs_bicycle_private_h_
#define RTW_HEADER_rs_bicycle_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "rs_bicycle.h"
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
extern void gwug4loynm ( dzvjycueyh * localDW ) ; extern void ka0rucvtv0 (
dzvjycueyh * localDW ) ; extern void c351hegycs ( real_T avahefhab4 ,
me0inc24h2 * localB , dzvjycueyh * localDW ) ; extern void dzd01mhcmk (
dzvjycueyh * localDW ) ;
#if defined(MULTITASKING)
#error Model (rs_bicycle) was built in \SingleTasking solver mode, however the MULTITASKING define is \present. If you have multitasking (e.g. -DMT or -DMULTITASKING) \defined on the Code Generation page of Simulation parameter dialog, please \remove it and on the Solver page, select solver mode \MultiTasking. If the Simulation parameter dialog is configured \correctly, please verify that your template makefile is \configured correctly.
#endif
#endif
