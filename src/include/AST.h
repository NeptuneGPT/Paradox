#ifndef AST_H
#define AST_H
#include <stdlib.h>
typedef struct AST_STRUCT
{
    enum{
        AST_VARIABLE_DEFINITION,
        AST_FUNCTION_CALL,
        AST_VARIABLE,
        AST_STRING,
        AST_COMPOUND,
        AST_COMMENT
    } type;

    /* AST_VAR_DEF */
    char* variable_definition_variable_name;
    struct AST_STRUCT* variable_definition_value;

    /*AST_VAR*/
    char* variable_name;
    
    /* AST_FUNC_CALL*/
    char* function_call_name;
    struct AST_STRUCT** function_call_arguments;
    size_t function_call_arguments_size;

    /*AST STRING*/
    char* string_value;
} AST_T;

AST_T* init_ast(int type);
#endif
