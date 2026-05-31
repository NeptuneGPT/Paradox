#include "include/lexer.h"
#include "include/token.h"
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


int is_number(char str){
    char endptr;
    strtol(str, endptr,10);
    if (endptr == "\0"){
        return 1;
    }
    else{
        return 0;
    }
}



lexer_T* init_lexer(char* contents){
    lexer_T* lexer = calloc(1, sizeof(struct LEXER_STRUCT));
    lexer->contents = contents;
    lexer->i = 0;
    lexer->c = contents[lexer->i];

    return lexer;
}
void lexer_advance(lexer_T* lexer){
    if (lexer->c != '\0' && lexer->i <strlen(lexer->contents)){
        lexer->i +=1;
        lexer->c = lexer->contents[lexer->i];
    }
}

void lexer_skip_whitespace(lexer_T* lexer){
    while(lexer->c  == ' '|| lexer->c ==10){
        lexer_advance(lexer);
    }
}

token_T* lexer_get_next_token(lexer_T* lexer){
    while (lexer->c != '\0' && lexer->i < strlen(lexer->contents)){
        if(lexer->c  == ' '|| lexer->c ==10){
            lexer_skip_whitespace(lexer);
        }
        if (isalnum(lexer->c)){
            return lexer_collect_id(lexer);
        }
        if (lexer->c == '"'){
            return lexer_collect_string(lexer);
        }
        if (is_number(lexer->c) == 1){
            return lexer_collect_number(lexer);
        }
        switch (lexer->c){
            case '=': return lexer_advance_with_token(lexer, init_token(TOKEN_EQUALS,lexer_get_current_char_as_string(lexer))); break;
            case '(': return lexer_advance_with_token(lexer, init_token(TOKEN_LPAREN,lexer_get_current_char_as_string(lexer))); break;
            case ')': return lexer_advance_with_token(lexer, init_token(TOKEN_RPAREN,lexer_get_current_char_as_string(lexer))); break;
            case ';': return lexer_advance_with_token(lexer, init_token(TOKEN_SEMI,lexer_get_current_char_as_string(lexer))); break;
            case ',': return lexer_advance_with_token(lexer,init_token(TOKEN_COMMA,lexer_get_current_char_as_string(lexer)));break;
            case '+': return lexer_advance_with_token(lexer,init_token(TOKEN_PLUS,lexer_get_current_char_as_string(lexer))); break;
            case '-': return lexer_advance_with_token(lexer,init_token(TOKEN_MINUS,lexer_get_current_char_as_string(lexer))); break;
            case '*': return lexer_advance_with_token(lexer, init_token(TOKEN_MULT, lexer_get_current_char_as_string(lexer))); break;
            case '/':{} // IDK how to modify divide and minus (ideally should turn minus into adding a negtive number and divide as multiplying 1/number)
        }
    }
    return init_token(TOKEN_EOF,"\0");
}

token_T* lexer_collect_string(lexer_T* lexer){
    lexer_advance(lexer);
    char* value = calloc(1,sizeof(char));
    value[0] = '\0';
    while (lexer->c != '"') {
        char* s = lexer_get_current_char_as_string(lexer);
        value = realloc(value, (strlen(value) + strlen(s) + 1) *sizeof(char));
        strcat(value,s);

        lexer_advance(lexer);
    }
    lexer_advance(lexer);
   
    return init_token(TOKEN_STRING, value);
}

token_T* lexer_collect_id(lexer_T* lexer){
    char* value = calloc(1,sizeof(char));
    value[0] = '\0';
    while (isalnum(lexer->c)) {
        char* s = lexer_get_current_char_as_string(lexer);
        value = realloc(value, (strlen(value) + strlen(s) + 1) *sizeof(char));
        strcat(value,s);
        
        lexer_advance(lexer);
    }
    return init_token(TOKEN_ID, value);
}

token_T* lexer_advance_with_token(lexer_T* lexer, token_T* token){
    lexer_advance(lexer);
    return token;
}


char* lexer_get_current_char_as_string(lexer_T* lexer){
    char* str = calloc(2,sizeof(char));
    str[0] = lexer->c;
    str[1] = '\0';
    return str;
}

token_T* lexer_collect_number(lexer_T* lexer){
    char* value = calloc(1,sizeof(char));
    value[0] = '\0';
    while (is_number(lexer->c)){
        char* s = lexer_get_current_char_as_string(lexer);
        value = realloc(value, (strlen(value) + strlen(s) + 1) *sizeof(char));
        strcat(value,s);
        lexer_advance(lexer);

    }
    
    return init_token(TOKEN_NUMBER, value);
}
