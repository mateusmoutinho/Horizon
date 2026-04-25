#ifndef horizon_httpsclient/_fdeclare
#define horizon_httpsclient/_fdeclare
#if !defined(horizondeps_request_typedef)
#define horizondeps_request_typedef
typedef struct horizondeps_request horizondeps_request;
#endif

#if !defined(horizondeps_response_typedef)
#define horizondeps_response_typedef
typedef struct horizondeps_response horizondeps_response;
#endif

#if !defined(horizondeps_httpclient_new_ctxt_prototype)
#define horizondeps_httpclient_new_ctxt_prototype
horizondeps_request *horizondeps_httpclient_new_ctxt(void *ctxt, const char *url);
#endif

#if !defined(horizondeps_httpclient_set_method_ctxt_prototype)
#define horizondeps_httpclient_set_method_ctxt_prototype
void horizondeps_httpclient_set_method_ctxt(void *ctxt, horizondeps_request *client, const char *method);
#endif

#if !defined(horizondeps_httpclient_set_max_redirections_ctxt_prototype)
#define horizondeps_httpclient_set_max_redirections_ctxt_prototype
void horizondeps_httpclient_set_max_redirections_ctxt(void *ctxt, horizondeps_request *client, int max_redirections);
#endif

#if !defined(horizondeps_httpclient_fetch_ctxt_prototype)
#define horizondeps_httpclient_fetch_ctxt_prototype
horizondeps_response *horizondeps_httpclient_fetch_ctxt(void *ctxt, horizondeps_request *client);
#endif

#if !defined(horizondeps_httpclient_response_get_status_code_ctxt_prototype)
#define horizondeps_httpclient_response_get_status_code_ctxt_prototype
int horizondeps_httpclient_response_get_status_code_ctxt(void *ctxt, horizondeps_response *response);
#endif

#if !defined(horizondeps_httpclient_response_read_body_ctxt_prototype)
#define horizondeps_httpclient_response_read_body_ctxt_prototype
const unsigned char *horizondeps_httpclient_response_read_body_ctxt(void *ctxt, horizondeps_response *response, long *size);
#endif

#if !defined(horizondeps_httpclient_response_get_body_size_ctxt_prototype)
#define horizondeps_httpclient_response_get_body_size_ctxt_prototype
long horizondeps_httpclient_response_get_body_size_ctxt(void *ctxt, horizondeps_response *response);
#endif

#if !defined(horizondeps_httpclient_response_get_header_size_ctxt_prototype)
#define horizondeps_httpclient_response_get_header_size_ctxt_prototype
int horizondeps_httpclient_response_get_header_size_ctxt(void *ctxt, horizondeps_response *response);
#endif

#if !defined(horizondeps_httpclient_response_get_header_count_ctxt_prototype)
#define horizondeps_httpclient_response_get_header_count_ctxt_prototype
int horizondeps_httpclient_response_get_header_count_ctxt(void *ctxt, horizondeps_response *response);
#endif

#if !defined(horizondeps_httpclient_set_header_ctxt_prototype)
#define horizondeps_httpclient_set_header_ctxt_prototype
void horizondeps_httpclient_set_header_ctxt(void *ctxt, horizondeps_request *client, const char *key, const char *value);
#endif

#if !defined(horizondeps_httpclient_set_body_ctxt_prototype)
#define horizondeps_httpclient_set_body_ctxt_prototype
void horizondeps_httpclient_set_body_ctxt(void *ctxt, horizondeps_request *client, unsigned char *content, long size);
#endif

#if !defined(horizondeps_httpclient_free_ctxt_prototype)
#define horizondeps_httpclient_free_ctxt_prototype
void horizondeps_httpclient_free_ctxt(void *ctxt, horizondeps_request *client);
#endif

#if !defined(horizondeps_httpclient_response_get_header_value_by_key_ctxt_prototype)
#define horizondeps_httpclient_response_get_header_value_by_key_ctxt_prototype
const char *horizondeps_httpclient_response_get_header_value_by_key_ctxt(void *ctxt, horizondeps_response *response, const char *key);
#endif

#if !defined(horizondeps_httpclient_response_get_header_key_by_index_ctxt_prototype)
#define horizondeps_httpclient_response_get_header_key_by_index_ctxt_prototype
const char *horizondeps_httpclient_response_get_header_key_by_index_ctxt(void *ctxt, horizondeps_response *response, int index);
#endif

#if !defined(horizondeps_httpclient_response_get_header_value_by_index_ctxt_prototype)
#define horizondeps_httpclient_response_get_header_value_by_index_ctxt_prototype
const char *horizondeps_httpclient_response_get_header_value_by_index_ctxt(void *ctxt, horizondeps_response *response, int index);
#endif

#if !defined(horizondeps_httpclient_response_free_ctxt_prototype)
#define horizondeps_httpclient_response_free_ctxt_prototype
void horizondeps_httpclient_response_free_ctxt(void *ctxt, horizondeps_response *response);
#endif

#endif
