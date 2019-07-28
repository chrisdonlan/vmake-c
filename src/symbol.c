#include<stdlib.h>
#include<string.h>
#include"symbol.h"
#include"token.h"

void init_symbol(symbol_t * symbol,char * (*next_token)(const char * istream)){
  symbol->lexeme = NULL;
  symbol->token = digit;
  symbol->next_token = next_token;
}
void destroy_symbol(symbol_t * symbol){
  free(symbol->lexeme);
  symbol->lexeme = NULL;
}

char * next_token(const char * istream){

  int start = 0;
  int steps = 0;

  while(istream[start] == ' '){
    start++;
  }

  if(istream[start + steps] == NULL)
    return NULL;

  while(istream[start + steps] != NULL){
    if (istream[start + steps + 1] == ' ')
      break;
    steps++;
  }
  steps++;

  char * result = malloc(sizeof(char)*(steps+1));
  result[steps] = 0;

  memcpy(result,istream+start,steps);

  return result;
}
