//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../imports/imports.global.h"
//silver_chain_scope_end
#ifndef Horizon_std_fdeclare
#define Horizon_std_fdeclare
#if !defined(horizondeps_free_ctxt_prototype)
#define horizondeps_free_ctxt_prototype
void horizondeps_free_ctxt(void *ctxt, void *ptr);
#endif

#if !defined(horizondeps_malloc_ctxt_prototype)
#define horizondeps_malloc_ctxt_prototype
void * horizondeps_malloc_ctxt(void *ctxt, long size);
#endif

#if !defined(horizondeps_printf_ctxt_prototype)
#define horizondeps_printf_ctxt_prototype
int horizondeps_printf_ctxt(void *ctxt, const char *fmt, ...);
#endif

#endif
