//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../../../wrappers/std/imports/imports.depdeclare.h"
//silver_chain_scope_end




#if !defined(PROJECT_NAMEdeps_printf_ctxt_implementation)
#define PROJECT_NAMEdeps_printf_ctxt_implementation
int PROJECT_NAMEdeps_printf_ctxt(void *ctxt, const char *fmt, ...){
    va_list args;
    va_start(args, fmt);
    int ret = vprintf(fmt, args);
    va_end(args);
    return ret;
}
#endif
