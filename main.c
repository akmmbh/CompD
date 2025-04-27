#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
//different enums....
typedef enum{
    INT,
    KEYWORD,
    SEPARATOR,
}TokenType;

// differnet structs....

typedef struct {
    TokenType type;
    char *value;
}Token;
//printing tokens
void print_token(Token token){
    for(int i=0;token.value[i]!='\0';i++){
   printf("%c",token.value[i]);
    }
    printf("\n");
    if(token.type ==INT){
        printf("TOKEN TYPE:INT\n");
    }
    if(token.type ==KEYWORD){
        printf("TOKEN TYPE:KEYWORD\n");
    }
    if(token.type ==INT){
        printf("TOKEN TYPE:SEPERATOR\n");
    }

}
//for gernerating whole number

Token *generate_number(char *current, int *current_index){
    Token *token= malloc(sizeof(Token)) ;
    token->type =INT;
    char* value=malloc(sizeof(char)*8);
    int value_index = 0;
    while(isdigit(current[*current_index]) && current[*current_index]!='\0'){
        if(!isdigit(current[*current_index]))break;
        value[value_index]=current[*current_index];
        value_index++;
        //printf("%c\n",current);
    *current_index+=1;
    }
    token->value = value;
    //free(value);
    return (token);
}
//for keywords
Token *generate_keyword(char *current,int *current_index){
    Token *token =malloc(sizeof(Token));
    char* keyword= malloc(sizeof(char)*8);
    int keyword_index=0;
    while(isalpha(current[*current_index]) && current[*current_index] !='\0'){
    keyword[keyword_index]=current[*current_index];
    keyword_index++;
    *current_index+=1;
    }
    printf(" %d\n",current_index);
    // for(int i=0;i<keyword_index;i++){
    //     printf("token char %c\n",keyword[i]);
    // }
    if(strcmp(keyword,"exit")==0){
        printf("TYPE EXIT\n");
        token->type=KEYWORD;
        token->value="EXIT";
    }
    return token;
}
//lexer

void lexer(FILE *file){
    int length;
    char* buffer=0;

    fseek(file,0,SEEK_END);
    length= ftell(file);
    fseek(file,0,SEEK_SET);
    buffer= malloc(sizeof(char)*(length+1));
    fread(buffer,1,length,file);

    fclose(file);
    buffer[length+1]='\0';
    char *current =malloc(sizeof(char)*length+1);
    current=buffer;
    int current_index=0;

    while(current[current_index]!='\0'){
        printf("curr:%c\n",current[current_index]);
if(current[current_index] ==';'){
    printf("FOUND SEMICOLON\n");
    Token *semicolon_token=malloc(sizeof(Token));
    semicolon_token->value[0] =current[current_index];
    semicolon_token->type[1] = SEPARATOR;
    print_token(*semicolon_token);
}else if(current[current_index]=='('){
    printf("FOUND OPEN PAREN\n");
}else if(current[current_index] ==')'){
    printf("FOUND CLOSE PAREN\n");
}else if(isdigit(current[current_index])){
   // printf("FOUND DIGIT :%d\n",current-'0');
   Token *test_token = generate_number(current,&current_index);
   print_token(*test_token);
   current_index--;
  // printf("TEST TOKEN VALUE: %s\n",test_token->value);
}else if(isalpha(current[current_index])){
  //  printf("FOUND CHARACTER: %c\n",current);
  Token *test_keyword=generate_keyword(current,&current_index);
  current_index--;
  print_token(*test_keyword);
 //printf("FOUND char:%c\n",current[current_index]);
}

current_index++;
    }
}
int main(){
    FILE *file;
    
    file=fopen("test.unn","r");
   
    lexer(file);
    
}