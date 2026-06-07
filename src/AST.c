#include "include/AST.h"

AST_T* init_ast(int type){

    AST_T* ast = calloc(1, sizeof(struct AST_STRUCT));
    ast->type = type;

    ast->scope = (void*) 0;
    
    //AST VAR DEF
    ast->variable_definition_variable_name = (void*) 0;
    ast->variable_definition_value  = (void*) 0;

    //AST FUNC DEF
    ast->function_definition_body = (void*) 0;
    ast->function_definition_name = (void*)0;
    ast->function_definition_args = (void*)0;
    ast->function_definition_args_size = 0;

    //AST VAR
    ast->variable_name = (void*) 0;

    //AST FUNC CALL
    ast->function_call_name = (void*) 0;
    ast->function_call_arguments = (void*) 0;
    ast->function_call_arguments_size = 0;

    //AST STRING
    ast->string_value = (void*) 0;

    //AST COMPOUND
    ast->compound_value = (void*) 0;
    ast->compound_size = 0;

    //AST FACTOR
    ast->factors = (void*) 0;
    ast->factors_size = 0;

    //AST TERM
    ast->terms= (void*) 0;
    ast->terms_size = 0;

    //AST NUMBER
    ast->number_value = 0;

    return ast;
}
