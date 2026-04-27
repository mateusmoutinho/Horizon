#if !defined(PROJECT_NAMEdeps_json_typedef)
#define PROJECT_NAMEdeps_json_typedef
typedef struct PROJECT_NAMEdeps_json PROJECT_NAMEdeps_json;
#endif

#if !defined(PROJECT_NAMEdeps_json_parse_ctxt_prototype)
#define PROJECT_NAMEdeps_json_parse_ctxt_prototype
PROJECT_NAMEdeps_json *PROJECT_NAMEdeps_json_parse_ctxt(void *ctxt, const char *value);
#endif

#if !defined(PROJECT_NAMEdeps_json_parse_file_ctxt_prototype)
#define PROJECT_NAMEdeps_json_parse_file_ctxt_prototype
PROJECT_NAMEdeps_json *PROJECT_NAMEdeps_json_parse_file_ctxt(void *ctxt, const char *filepath);
#endif

#if !defined(PROJECT_NAMEdeps_json_delete_ctxt_prototype)
#define PROJECT_NAMEdeps_json_delete_ctxt_prototype
void PROJECT_NAMEdeps_json_delete_ctxt(void *ctxt, PROJECT_NAMEdeps_json *json);
#endif

#if !defined(PROJECT_NAMEdeps_json_print_ctxt_prototype)
#define PROJECT_NAMEdeps_json_print_ctxt_prototype
char *PROJECT_NAMEdeps_json_print_ctxt(void *ctxt, const PROJECT_NAMEdeps_json *json);
#endif

#if !defined(PROJECT_NAMEdeps_json_print_unformatted_ctxt_prototype)
#define PROJECT_NAMEdeps_json_print_unformatted_ctxt_prototype
char *PROJECT_NAMEdeps_json_print_unformatted_ctxt(void *ctxt, const PROJECT_NAMEdeps_json *json);
#endif

#if !defined(PROJECT_NAMEdeps_json_save_file_ctxt_prototype)
#define PROJECT_NAMEdeps_json_save_file_ctxt_prototype
int PROJECT_NAMEdeps_json_save_file_ctxt(void *ctxt, const PROJECT_NAMEdeps_json *json, const char *filepath);
#endif

#if !defined(PROJECT_NAMEdeps_json_free_string_ctxt_prototype)
#define PROJECT_NAMEdeps_json_free_string_ctxt_prototype
void PROJECT_NAMEdeps_json_free_string_ctxt(void *ctxt, char *str);
#endif

#if !defined(PROJECT_NAMEdeps_json_create_object_ctxt_prototype)
#define PROJECT_NAMEdeps_json_create_object_ctxt_prototype
PROJECT_NAMEdeps_json *PROJECT_NAMEdeps_json_create_object_ctxt(void *ctxt);
#endif

#if !defined(PROJECT_NAMEdeps_json_create_array_ctxt_prototype)
#define PROJECT_NAMEdeps_json_create_array_ctxt_prototype
PROJECT_NAMEdeps_json *PROJECT_NAMEdeps_json_create_array_ctxt(void *ctxt);
#endif

#if !defined(PROJECT_NAMEdeps_json_create_string_ctxt_prototype)
#define PROJECT_NAMEdeps_json_create_string_ctxt_prototype
PROJECT_NAMEdeps_json *PROJECT_NAMEdeps_json_create_string_ctxt(void *ctxt, const char *string);
#endif

#if !defined(PROJECT_NAMEdeps_json_create_number_ctxt_prototype)
#define PROJECT_NAMEdeps_json_create_number_ctxt_prototype
PROJECT_NAMEdeps_json *PROJECT_NAMEdeps_json_create_number_ctxt(void *ctxt, double num);
#endif

#if !defined(PROJECT_NAMEdeps_json_create_bool_ctxt_prototype)
#define PROJECT_NAMEdeps_json_create_bool_ctxt_prototype
PROJECT_NAMEdeps_json *PROJECT_NAMEdeps_json_create_bool_ctxt(void *ctxt, int boolean);
#endif

#if !defined(PROJECT_NAMEdeps_json_create_null_ctxt_prototype)
#define PROJECT_NAMEdeps_json_create_null_ctxt_prototype
PROJECT_NAMEdeps_json *PROJECT_NAMEdeps_json_create_null_ctxt(void *ctxt);
#endif

#if !defined(PROJECT_NAMEdeps_json_duplicate_ctxt_prototype)
#define PROJECT_NAMEdeps_json_duplicate_ctxt_prototype
PROJECT_NAMEdeps_json *PROJECT_NAMEdeps_json_duplicate_ctxt(void *ctxt, const PROJECT_NAMEdeps_json *item, int recurse);
#endif

#if !defined(PROJECT_NAMEdeps_json_get_object_item_ctxt_prototype)
#define PROJECT_NAMEdeps_json_get_object_item_ctxt_prototype
PROJECT_NAMEdeps_json *PROJECT_NAMEdeps_json_get_object_item_ctxt(void *ctxt, const PROJECT_NAMEdeps_json *object, const char *key);
#endif

#if !defined(PROJECT_NAMEdeps_json_has_object_item_ctxt_prototype)
#define PROJECT_NAMEdeps_json_has_object_item_ctxt_prototype
int PROJECT_NAMEdeps_json_has_object_item_ctxt(void *ctxt, const PROJECT_NAMEdeps_json *object, const char *key);
#endif

#if !defined(PROJECT_NAMEdeps_json_add_item_to_object_ctxt_prototype)
#define PROJECT_NAMEdeps_json_add_item_to_object_ctxt_prototype
int PROJECT_NAMEdeps_json_add_item_to_object_ctxt(void *ctxt, PROJECT_NAMEdeps_json *object, const char *key, PROJECT_NAMEdeps_json *item);
#endif

#if !defined(PROJECT_NAMEdeps_json_delete_item_from_object_ctxt_prototype)
#define PROJECT_NAMEdeps_json_delete_item_from_object_ctxt_prototype
int PROJECT_NAMEdeps_json_delete_item_from_object_ctxt(void *ctxt, PROJECT_NAMEdeps_json *object, const char *key);
#endif

#if !defined(PROJECT_NAMEdeps_json_replace_item_in_object_ctxt_prototype)
#define PROJECT_NAMEdeps_json_replace_item_in_object_ctxt_prototype
int PROJECT_NAMEdeps_json_replace_item_in_object_ctxt(void *ctxt, PROJECT_NAMEdeps_json *object, const char *key, PROJECT_NAMEdeps_json *newitem);
#endif

#if !defined(PROJECT_NAMEdeps_json_add_string_to_object_ctxt_prototype)
#define PROJECT_NAMEdeps_json_add_string_to_object_ctxt_prototype
PROJECT_NAMEdeps_json *PROJECT_NAMEdeps_json_add_string_to_object_ctxt(void *ctxt, PROJECT_NAMEdeps_json *object, const char *key, const char *string);
#endif

#if !defined(PROJECT_NAMEdeps_json_add_number_to_object_ctxt_prototype)
#define PROJECT_NAMEdeps_json_add_number_to_object_ctxt_prototype
PROJECT_NAMEdeps_json *PROJECT_NAMEdeps_json_add_number_to_object_ctxt(void *ctxt, PROJECT_NAMEdeps_json *object, const char *key, double number);
#endif

#if !defined(PROJECT_NAMEdeps_json_add_bool_to_object_ctxt_prototype)
#define PROJECT_NAMEdeps_json_add_bool_to_object_ctxt_prototype
PROJECT_NAMEdeps_json *PROJECT_NAMEdeps_json_add_bool_to_object_ctxt(void *ctxt, PROJECT_NAMEdeps_json *object, const char *key, int boolean);
#endif

#if !defined(PROJECT_NAMEdeps_json_add_null_to_object_ctxt_prototype)
#define PROJECT_NAMEdeps_json_add_null_to_object_ctxt_prototype
PROJECT_NAMEdeps_json *PROJECT_NAMEdeps_json_add_null_to_object_ctxt(void *ctxt, PROJECT_NAMEdeps_json *object, const char *key);
#endif

#if !defined(PROJECT_NAMEdeps_json_add_object_to_object_ctxt_prototype)
#define PROJECT_NAMEdeps_json_add_object_to_object_ctxt_prototype
PROJECT_NAMEdeps_json *PROJECT_NAMEdeps_json_add_object_to_object_ctxt(void *ctxt, PROJECT_NAMEdeps_json *object, const char *key);
#endif

#if !defined(PROJECT_NAMEdeps_json_add_array_to_object_ctxt_prototype)
#define PROJECT_NAMEdeps_json_add_array_to_object_ctxt_prototype
PROJECT_NAMEdeps_json *PROJECT_NAMEdeps_json_add_array_to_object_ctxt(void *ctxt, PROJECT_NAMEdeps_json *object, const char *key);
#endif

#if !defined(PROJECT_NAMEdeps_json_get_array_size_ctxt_prototype)
#define PROJECT_NAMEdeps_json_get_array_size_ctxt_prototype
int PROJECT_NAMEdeps_json_get_array_size_ctxt(void *ctxt, const PROJECT_NAMEdeps_json *array);
#endif

#if !defined(PROJECT_NAMEdeps_json_get_array_item_ctxt_prototype)
#define PROJECT_NAMEdeps_json_get_array_item_ctxt_prototype
PROJECT_NAMEdeps_json *PROJECT_NAMEdeps_json_get_array_item_ctxt(void *ctxt, const PROJECT_NAMEdeps_json *array, int index);
#endif

#if !defined(PROJECT_NAMEdeps_json_add_item_to_array_ctxt_prototype)
#define PROJECT_NAMEdeps_json_add_item_to_array_ctxt_prototype
int PROJECT_NAMEdeps_json_add_item_to_array_ctxt(void *ctxt, PROJECT_NAMEdeps_json *array, PROJECT_NAMEdeps_json *item);
#endif

#if !defined(PROJECT_NAMEdeps_json_insert_item_in_array_ctxt_prototype)
#define PROJECT_NAMEdeps_json_insert_item_in_array_ctxt_prototype
int PROJECT_NAMEdeps_json_insert_item_in_array_ctxt(void *ctxt, PROJECT_NAMEdeps_json *array, int index, PROJECT_NAMEdeps_json *item);
#endif

#if !defined(PROJECT_NAMEdeps_json_replace_item_in_array_ctxt_prototype)
#define PROJECT_NAMEdeps_json_replace_item_in_array_ctxt_prototype
int PROJECT_NAMEdeps_json_replace_item_in_array_ctxt(void *ctxt, PROJECT_NAMEdeps_json *array, int index, PROJECT_NAMEdeps_json *newitem);
#endif

#if !defined(PROJECT_NAMEdeps_json_delete_item_from_array_ctxt_prototype)
#define PROJECT_NAMEdeps_json_delete_item_from_array_ctxt_prototype
void PROJECT_NAMEdeps_json_delete_item_from_array_ctxt(void *ctxt, PROJECT_NAMEdeps_json *array, int index);
#endif

#if !defined(PROJECT_NAMEdeps_json_is_object_ctxt_prototype)
#define PROJECT_NAMEdeps_json_is_object_ctxt_prototype
int PROJECT_NAMEdeps_json_is_object_ctxt(void *ctxt, const PROJECT_NAMEdeps_json *item);
#endif

#if !defined(PROJECT_NAMEdeps_json_is_array_ctxt_prototype)
#define PROJECT_NAMEdeps_json_is_array_ctxt_prototype
int PROJECT_NAMEdeps_json_is_array_ctxt(void *ctxt, const PROJECT_NAMEdeps_json *item);
#endif

#if !defined(PROJECT_NAMEdeps_json_is_string_ctxt_prototype)
#define PROJECT_NAMEdeps_json_is_string_ctxt_prototype
int PROJECT_NAMEdeps_json_is_string_ctxt(void *ctxt, const PROJECT_NAMEdeps_json *item);
#endif

#if !defined(PROJECT_NAMEdeps_json_is_number_ctxt_prototype)
#define PROJECT_NAMEdeps_json_is_number_ctxt_prototype
int PROJECT_NAMEdeps_json_is_number_ctxt(void *ctxt, const PROJECT_NAMEdeps_json *item);
#endif

#if !defined(PROJECT_NAMEdeps_json_is_bool_ctxt_prototype)
#define PROJECT_NAMEdeps_json_is_bool_ctxt_prototype
int PROJECT_NAMEdeps_json_is_bool_ctxt(void *ctxt, const PROJECT_NAMEdeps_json *item);
#endif

#if !defined(PROJECT_NAMEdeps_json_is_null_ctxt_prototype)
#define PROJECT_NAMEdeps_json_is_null_ctxt_prototype
int PROJECT_NAMEdeps_json_is_null_ctxt(void *ctxt, const PROJECT_NAMEdeps_json *item);
#endif

#if !defined(PROJECT_NAMEdeps_json_is_true_ctxt_prototype)
#define PROJECT_NAMEdeps_json_is_true_ctxt_prototype
int PROJECT_NAMEdeps_json_is_true_ctxt(void *ctxt, const PROJECT_NAMEdeps_json *item);
#endif

#if !defined(PROJECT_NAMEdeps_json_is_false_ctxt_prototype)
#define PROJECT_NAMEdeps_json_is_false_ctxt_prototype
int PROJECT_NAMEdeps_json_is_false_ctxt(void *ctxt, const PROJECT_NAMEdeps_json *item);
#endif

#if !defined(PROJECT_NAMEdeps_json_get_string_value_ctxt_prototype)
#define PROJECT_NAMEdeps_json_get_string_value_ctxt_prototype
char *PROJECT_NAMEdeps_json_get_string_value_ctxt(void *ctxt, const PROJECT_NAMEdeps_json *item);
#endif

#if !defined(PROJECT_NAMEdeps_json_get_number_value_ctxt_prototype)
#define PROJECT_NAMEdeps_json_get_number_value_ctxt_prototype
double PROJECT_NAMEdeps_json_get_number_value_ctxt(void *ctxt, const PROJECT_NAMEdeps_json *item);
#endif

#if !defined(PROJECT_NAMEdeps_json_compare_ctxt_prototype)
#define PROJECT_NAMEdeps_json_compare_ctxt_prototype
int PROJECT_NAMEdeps_json_compare_ctxt(void *ctxt, const PROJECT_NAMEdeps_json *a, const PROJECT_NAMEdeps_json *b, int case_sensitive);
#endif

#if !defined(PROJECT_NAMEdeps_json_get_child_ctxt_prototype)
#define PROJECT_NAMEdeps_json_get_child_ctxt_prototype
PROJECT_NAMEdeps_json *PROJECT_NAMEdeps_json_get_child_ctxt(void *ctxt, const PROJECT_NAMEdeps_json *item);
#endif

#if !defined(PROJECT_NAMEdeps_json_get_next_ctxt_prototype)
#define PROJECT_NAMEdeps_json_get_next_ctxt_prototype
PROJECT_NAMEdeps_json *PROJECT_NAMEdeps_json_get_next_ctxt(void *ctxt, const PROJECT_NAMEdeps_json *item);
#endif

#if !defined(PROJECT_NAMEdeps_json_get_key_ctxt_prototype)
#define PROJECT_NAMEdeps_json_get_key_ctxt_prototype
const char *PROJECT_NAMEdeps_json_get_key_ctxt(void *ctxt, const PROJECT_NAMEdeps_json *item);
#endif

#if !defined(PROJECT_NAMEdeps_json_get_object_size_ctxt_prototype)
#define PROJECT_NAMEdeps_json_get_object_size_ctxt_prototype
int PROJECT_NAMEdeps_json_get_object_size_ctxt(void *ctxt, const PROJECT_NAMEdeps_json *object);
#endif
