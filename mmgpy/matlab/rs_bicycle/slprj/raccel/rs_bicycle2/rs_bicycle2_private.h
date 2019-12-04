#include "__cf_rs_bicycle2.h"
#ifndef RTW_HEADER_rs_bicycle2_private_h_
#define RTW_HEADER_rs_bicycle2_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "rs_bicycle2.h"
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
extern void hulq2q2v4t ( oehzpt04yr * localDW ) ; extern void asxel4khfi (
oehzpt04yr * localDW ) ; extern void nrszotctkr ( real_T jdv1xek1e2 ,
l3csy1qexn * localB , oehzpt04yr * localDW ) ; extern void nkktcwoggm (
oehzpt04yr * localDW ) ;
#if defined(MULTITASKING)
#error Model (rs_bicycle2) was built in \SingleTasking solver mode, however the MULTITASKING define is \present. If you have multitasking (e.g. -DMT or -DMULTITASKING) \defined on the Code Generation page of Simulation parameter dialog, please \remove it and on the Solver page, select solver mode \MultiTasking. If the Simulation parameter dialog is configured \correctly, please verify that your template makefile is \configured correctly.
#endif
#endif
