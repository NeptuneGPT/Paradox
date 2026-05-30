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
        TOKEN_COMMENT

}token_type_T;

typedef struct TOKEN_STRUCT{
    token_type_T* type;
    char* value;
}token_T;

token_T* init_token(token_type_T* type,char* value);
#endif
