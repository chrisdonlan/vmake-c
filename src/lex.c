#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#include "chtbl.h"
#include "lex.h"
#include "symbol.h"

token_e lex(const char * istream,chtbl_t * symtbl){
  token_e token;
  symbol_t * symbol;
  int len,retval,i;

  if((symbol = (symbol_t *)malloc(sizeof(symbol_t))) == NULL)
    return error;

  init_symbol(symbol,next_token);

  if ((symbol->lexeme = next_token(istream)) == NULL) {
    destroy(symbol);
    free(symbol);
    return lexit;
  }
  else {
    symbol->token = digit;
    length = strlen(symbol->lexeme);

    for(i = 0; i < length; i++) {
      if (!isdigit(symbol->lexeme[i]))
        symbol->token = other;
    }

    memcpy(&token, &symbol->token, sizeof(token_e));

    if ((retval = chtbl_insert(symtbl,symbol)) < 0) {
      destroy(symbol);
      free(symbol);
      return error;

    }

    else if (retval == 1){
      destroy(symbol);
      free(symbol);
    }
  }
  return token;

}
