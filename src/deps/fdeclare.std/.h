#ifndef horizon_std/_fdeclare
#define horizon_std/_fdeclare
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
