//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../../../wrappers/std/imports/imports.depdeclare.h"
//silver_chain_scope_end




#if !defined(horizondeps_printf_ctxt_implementation)
#define horizondeps_printf_ctxt_implementation
int horizondeps_printf_ctxt(void *ctxt, const char *fmt, ...){
    va_list args;
    va_start(args, fmt);
    int ret = vprintf(fmt, args);
    va_end(args);
    return ret;
}
#endif



#if !defined(horizondeps_printf_implementation)
#define horizondeps_printf_implementation
int horizondeps_printf(const char *fmt, ...){
    va_list args;
    va_start(args, fmt);
    int ret = vprintf(fmt, args);
    va_end(args);
    return ret;
}
#endif