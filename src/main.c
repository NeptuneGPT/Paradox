#include "include/main.h"

#define MAX_LIMIT 20
void print_help(){

    printf("Usage:\n ./paradox.out <filename>\n");
    exit(1);
}

int main(int argc, char* argv[])
{
    if (argc >= 2){
        for(int i = 1; i < argc; i++){
            int len = strlen(argv[i]);
            char* last_four = &argv[i][len-8];
            if(strcmp(last_four,".paradox") == 0){
                lexer_T* lexer = init_lexer(
                    get_file_contents(argv[i]));
                
                parser_T* parser = init_parser(lexer);
                AST_T* root = parser_parse(parser, parser->scope);
                visitor_T* visitor = init_visitor();
                visitor_visit(visitor, root);
            }

            else {
                print_help();
            }
        }
    }
    else{
        char input[MAX_LIMIT];
        while(1){
                printf("Welcome to Paradox.\n");
                fgets(input, MAX_LIMIT, stdin);
                lexer_T* lexer = init_lexer(input);
                parser_T* parser = init_parser(lexer);
                AST_T* root = parser_parse(parser, parser->scope);
                visitor_T* visitor = init_visitor();
                visitor_visit(visitor, root);
        }
    }
    return 0;
}
