//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../imports/imports.global.h"
//silver_chain_scope_end
#ifndef PROJECT_NAME_std_fdeclare
#define PROJECT_NAME_std_fdeclare
#if !defined(PROJECT_NAMEdeps_free_ctxt_prototype)
#define PROJECT_NAMEdeps_free_ctxt_prototype
void PROJECT_NAMEdeps_free_ctxt(void *ctxt, void *ptr);
#endif

#if !defined(PROJECT_NAMEdeps_malloc_ctxt_prototype)
#define PROJECT_NAMEdeps_malloc_ctxt_prototype
void * PROJECT_NAMEdeps_malloc_ctxt(void *ctxt, long size);
#endif

#if !defined(PROJECT_NAMEdeps_printf_ctxt_prototype)
#define PROJECT_NAMEdeps_printf_ctxt_prototype
int PROJECT_NAMEdeps_printf_ctxt(void *ctxt, const char *fmt, ...);
#endif

#endif
