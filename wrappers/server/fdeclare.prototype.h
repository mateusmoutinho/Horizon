#if !defined(PROJECT_NAMEdeps_server_globals_prototype)
#define PROJECT_NAMEdeps_server_globals_prototype
extern void *(*PROJECT_NAMEdeps_server_global_handler)(void *, void *);
extern void *PROJECT_NAMEdeps_server_global_props;
extern int PROJECT_NAMEdeps_server_global_firmware_mode;
#endif

#if !defined(PROJECT_NAMEdeps_server_get_route_ctxt_prototype)
#define PROJECT_NAMEdeps_server_get_route_ctxt_prototype
const char *PROJECT_NAMEdeps_server_get_route_ctxt(void *ctxt, const void *request);
#endif

#if !defined(PROJECT_NAMEdeps_server_get_method_ctxt_prototype)
#define PROJECT_NAMEdeps_server_get_method_ctxt_prototype
const char *PROJECT_NAMEdeps_server_get_method_ctxt(void *ctxt, const void *request);
#endif

#if !defined(PROJECT_NAMEdeps_server_get_header_ctxt_prototype)
#define PROJECT_NAMEdeps_server_get_header_ctxt_prototype
const char *PROJECT_NAMEdeps_server_get_header_ctxt(void *ctxt, const void *request, const char *key);
#endif

#if !defined(PROJECT_NAMEdeps_server_get_header_key_ctxt_prototype)
#define PROJECT_NAMEdeps_server_get_header_key_ctxt_prototype
const char *PROJECT_NAMEdeps_server_get_header_key_ctxt(void *ctxt, const void *request, int index);
#endif

#if !defined(PROJECT_NAMEdeps_server_get_header_value_ctxt_prototype)
#define PROJECT_NAMEdeps_server_get_header_value_ctxt_prototype
const char *PROJECT_NAMEdeps_server_get_header_value_ctxt(void *ctxt, const void *request, int index);
#endif

#if !defined(PROJECT_NAMEdeps_server_get_query_param_ctxt_prototype)
#define PROJECT_NAMEdeps_server_get_query_param_ctxt_prototype
const char *PROJECT_NAMEdeps_server_get_query_param_ctxt(void *ctxt, const void *request, const char *key);
#endif

#if !defined(PROJECT_NAMEdeps_server_get_query_param_key_ctxt_prototype)
#define PROJECT_NAMEdeps_server_get_query_param_key_ctxt_prototype
const char *PROJECT_NAMEdeps_server_get_query_param_key_ctxt(void *ctxt, const void *request, int index);
#endif

#if !defined(PROJECT_NAMEdeps_server_get_query_param_value_ctxt_prototype)
#define PROJECT_NAMEdeps_server_get_query_param_value_ctxt_prototype
const char *PROJECT_NAMEdeps_server_get_query_param_value_ctxt(void *ctxt, const void *request, int index);
#endif

#if !defined(PROJECT_NAMEdeps_server_get_header_count_ctxt_prototype)
#define PROJECT_NAMEdeps_server_get_header_count_ctxt_prototype
int PROJECT_NAMEdeps_server_get_header_count_ctxt(void *ctxt, const void *request);
#endif

#if !defined(PROJECT_NAMEdeps_server_get_query_param_count_ctxt_prototype)
#define PROJECT_NAMEdeps_server_get_query_param_count_ctxt_prototype
int PROJECT_NAMEdeps_server_get_query_param_count_ctxt(void *ctxt, const void *request);
#endif

#if !defined(PROJECT_NAMEdeps_server_read_body_ctxt_prototype)
#define PROJECT_NAMEdeps_server_read_body_ctxt_prototype
const unsigned char *PROJECT_NAMEdeps_server_read_body_ctxt(void *ctxt, const void *request, long size, long *read_size);
#endif

#if !defined(PROJECT_NAMEdeps_server_read_json_ctxt_prototype)
#define PROJECT_NAMEdeps_server_read_json_ctxt_prototype
const void *PROJECT_NAMEdeps_server_read_json_ctxt(void *ctxt, const void *request, long size);
#endif

#if !defined(PROJECT_NAMEdeps_server_new_response_ctxt_prototype)
#define PROJECT_NAMEdeps_server_new_response_ctxt_prototype
void *PROJECT_NAMEdeps_server_new_response_ctxt(void *ctxt);
#endif

#if !defined(PROJECT_NAMEdeps_server_set_response_header_ctxt_prototype)
#define PROJECT_NAMEdeps_server_set_response_header_ctxt_prototype
void PROJECT_NAMEdeps_server_set_response_header_ctxt(void *ctxt, void *response, const char *key, const char *value);
#endif

#if !defined(PROJECT_NAMEdeps_server_set_response_content_ctxt_prototype)
#define PROJECT_NAMEdeps_server_set_response_content_ctxt_prototype
void PROJECT_NAMEdeps_server_set_response_content_ctxt(void *ctxt, void *response, const unsigned char *content, long content_size);
#endif

#if !defined(PROJECT_NAMEdeps_server_set_response_status_code_ctxt_prototype)
#define PROJECT_NAMEdeps_server_set_response_status_code_ctxt_prototype
void PROJECT_NAMEdeps_server_set_response_status_code_ctxt(void *ctxt, void *response, int status_code);
#endif

#if !defined(PROJECT_NAMEdeps_server_send_any_ctxt_prototype)
#define PROJECT_NAMEdeps_server_send_any_ctxt_prototype
const void *PROJECT_NAMEdeps_server_send_any_ctxt(void *ctxt, const unsigned char *content, long content_size, const char *content_type, int status_code);
#endif

#if !defined(PROJECT_NAMEdeps_server_send_text_ctxt_prototype)
#define PROJECT_NAMEdeps_server_send_text_ctxt_prototype
const void *PROJECT_NAMEdeps_server_send_text_ctxt(void *ctxt, const char *text, const char *content_type, int status_code);
#endif

#if !defined(PROJECT_NAMEdeps_server_send_file_ctxt_prototype)
#define PROJECT_NAMEdeps_server_send_file_ctxt_prototype
const void *PROJECT_NAMEdeps_server_send_file_ctxt(void *ctxt, const char *path, const char *content_type, int status_code);
#endif

#if !defined(PROJECT_NAMEdeps_server_send_json_ctxt_prototype)
#define PROJECT_NAMEdeps_server_send_json_ctxt_prototype
const void *PROJECT_NAMEdeps_server_send_json_ctxt(void *ctxt, const void *json, int status_code);
#endif

#if !defined(PROJECT_NAMEdeps_server_start_ctxt_prototype)
#define PROJECT_NAMEdeps_server_start_ctxt_prototype
int PROJECT_NAMEdeps_server_start_ctxt(void *ctxt, int port, void *(*handler)(void *, void *), void *props, int single_process);
#endif
