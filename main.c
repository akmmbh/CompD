#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
//different enums....
typedef enum{
    SEMI,
    OPEN_PAREN,
    CLOSE_PAREN,
}TypeSeparator;
typedef enum {
    EXIT,
}TypeKeyword;
typedef enum {
    INT,
}TypeLiteral;


// differnet structs....
typedef struct{
TypeKeyword type;

}TokenKeyword;
typedef struct{
TypeLiteral type;
char* value;
}TokenLiteral;

typedef struct{
TypeSeparator type;
}TokenSeparator;


//for gernerating whole number

TokenLiteral *generate_number(char current ,FILE *file){
    TokenLiteral *token= malloc(sizeof(TokenLiteral)) ;
    token->type =INT;
    char* value=malloc(sizeof(char)*8);
    int value_index = 0;
    while(isdigit(current) && current!=EOF){
        if(!isdigit(current))break;
        value[value_index]=current;
        value_index++;
        //printf("%c\n",current);
        current =fgetc(file);
    }
    token->value = value;
    //free(value);
    return (token);
}
//for keywords
TokenKeyword *generate_keyword(char current,FILE *file){
    TokenKeyword *token =malloc(sizeof(TokenKeyword));
    char* keyword= malloc
    int keyword_index=0;
    while(isalpha(current) && current !=EOF){
    keyword[keyword_index]=current;
    current=fgetc(file);
    }
}
//lexer

void lexer(FILE *file){
    char current=fgetc(file);

    while(current!=EOF){
if(current ==';'){
    printf("FOUND SEMICOLON\n");
}else if(current=='('){
    printf("FOUND OPEN PAREN\n");
}else if(current ==')'){
    printf("FOUND CLOSE PAREN\n");
}else if(isdigit(current)){
   // printf("FOUND DIGIT :%d\n",current-'0');
   TokenLiteral test_token = generate_number(current,file);
   printf("TEST TOKEN VALUE: %d\n",test_token.value);
}else if(isalpha(current)){
    printf("FOUND CHARACTER: %c\n",current);
}

current=fgetc(file);
    }
}
int main(){
    FILE *file;
    file=fopen("test.unn","r");
    lexer(file);
    
}