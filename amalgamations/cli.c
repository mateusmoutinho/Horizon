
#include "../src/imports/imports.fdeclare.h"

int main(int argc,char **argv){
    return PROJECT_NAME_main(argc,argv);
}

#define PROJECT_NAME_main_implementation
int PROJECT_NAME_main(int argc, char** argv){

    PROJECT_NAMEdeps_request *req = PROJECT_NAMEdeps_httpclient_new_ctxt(PROJECT_NAME_null, "https://www.google.com");
    PROJECT_NAMEdeps_response *resp = PROJECT_NAMEdeps_httpclient_fetch_ctxt(PROJECT_NAME_null, req);
    
    long size;
    const unsigned char *response = PROJECT_NAMEdeps_httpclient_response_read_body_ctxt(PROJECT_NAME_null, resp, &size);
    PROJECT_NAMEdeps_printf_ctxt(PROJECT_NAME_null, "%s\n", response);

    
    PROJECT_NAMEdeps_httpclient_response_free_ctxt(PROJECT_NAME_null, resp);
    PROJECT_NAMEdeps_httpclient_free_ctxt(PROJECT_NAME_null, req);
    return 0;
}



#include "../src/imports/imports.fdefine.h"
#include "wrapper_imports.h"


