
#include "../src/imports/imports.fdeclare.h"

int main(int argc,char **argv){
    return horizon_main(argc,argv);
}

#define horizon_main_implementation
int horizon_main(int argc, char** argv){

    horizondeps_request *req = horizondeps_httpclient_new_ctxt(horizon_null, "https://www.google.com");
    horizondeps_response *resp = horizondeps_httpclient_fetch_ctxt(horizon_null, req);
    
    long size;
    const unsigned char *response = horizondeps_httpclient_response_read_body_ctxt(horizon_null, resp, &size);
    horizondeps_printf_ctxt(horizon_null, "%s\n", response);

    
    horizondeps_httpclient_response_free_ctxt(horizon_null, resp);
    horizondeps_httpclient_free_ctxt(horizon_null, req);
    return 0;
}



#include "../src/imports/imports.fdefine.h"


