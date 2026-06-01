#ifndef TOKEN_H
#define TOKEN_H
typedef enum{
        TOKEN_ID,
        TOKEN_EQUALS,
        TOKEN_STRING,
        TOKEN_NEWLINE,
        TOKEN_LPAREN,
        TOKEN_RPAREN,
        TOKEN_SEMI,
        TOKEN_COMMENT,
        TOKEN_RBRACE,
        TOKEN_LBRACE,
        TOKEN_NUMBER,
        TOKEN_PLUS,
        TOKEN_MINUS,
        TOKEN_MULT,
        TOKEN_COMMA,
        TOKEN_EOF

}token_type_T;

typedef struct TOKEN_STRUCT{
    token_type_T type;
    char* value;
}token_T;

token_T* init_token(token_type_T type,char* value);
#endif
