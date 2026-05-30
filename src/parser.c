#include "include/parser.h"
#include "include/AST.h"
#include <stdio.h>

parser_T* init_parser(lexer_T* lexer){
    parser_T* parser = calloc(1,sizeof(struct PARSER_STRUCT));
    parser->lexer = lexer;
    parser->current_token = lexer_get_next_token(lexer);

    return parser;
}

void parser_eat(parser_T* parser, token_type_T token_type){
    if (parser->current_token->type == token_type){
        parser->current_token = lexer_get_next_token(parser->lexer);
    }
    else{
        printf("Unexpected token %s, with type %d",
                parser->current_token->value,
                parser->current_token->type);
        exit(1);
    }

}

AST_T* parser_parse(parser_T* parser){
    return parser_parse_statements(parser);
}

AST_T* parser_parse_statement(parser_T* parser){}

AST_T* parser_parse_statements(parser_T* parser){

    AST_T* compound  = init_ast(AST_COMPOUND);
    compound->compound_value = calloc(1, sizeof(struct AST_STRUCT*)); 
    AST_T* statement = parser_parse_statement(parser);
    compound->compound_value[0] = statement;
    compound->compound_size+=1;
    while(parser->current_token->type == TOKEN_SEMI){
        parser_eat(parser,TOKEN_SEMI);  
        AST_T* statement = parser_parse_statement(parser);
        compound->compound_size+=1;
        compound->compound_value = realloc(compound->compound_value,compound->compound_size * sizeof(struct AST_STRUCT*));
        compound->compound_value[compound->compound_size] = statement;
        
    }
    return compound;
}

AST_T* parser_parse_expr(parser_T* parser){}

AST_T* parser_parse_factor(parser_T* parser){}

AST_T* parser_parse_term(parser_T* parser){}

AST_T* parser_parse_variable(parser_T* parser){}

AST_T* parser_parse_string(parser_T* parser){}
