#ifndef AST_H
#define AST_H
#include <stdlib.h>
typedef struct AST_STRUCT
{
    enum{
        AST_VARIABLE_DEFINITION,
        AST_FUNCTION_CALL,
        AST_FUNCTION_DEFINITION,
        AST_VARIABLE,
        AST_STRING,
        AST_COMPOUND,
        AST_COMMENT,
        AST_NOOP //no operation
    } type;

    /* AST_VAR_DEF */
    char* variable_definition_variable_name;
    struct AST_STRUCT* variable_definition_value;

    // AST FUNC DEF
    struct AST_STRUCT* function_definition_body;

    /*AST_VAR*/
    char* variable_name;
    
    /* AST_FUNC_CALL*/
    char* function_call_name;
    struct AST_STRUCT** function_call_arguments;
    size_t function_call_arguments_size;

    /*AST STRING*/
    char* string_value;

    /*AST COMPOUND*/
    struct AST_STRUCT** compound_value;
    size_t compound_size;
} AST_T;

AST_T* init_ast(int type);
#endif
