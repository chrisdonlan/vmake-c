#ifndef __SYMBOL_H__
#define __SYMBOL_H__
#include"token.h"

typedef struct symbol {
  char * lexeme;
  token_e token;
  char * (*next_token)(const char * istream);
} symbol_t;

void init_symbol(symbol_t * symbol,char * (*next_token)(const char * istream));

void destroy_symbol(symbol_t * symbol);

char * next_token(const char * istream);


#endif
