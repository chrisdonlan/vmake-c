#ifndef __LEX_H__
#define __LEX_H__
#include "chtbl.h"

typedef enum token {lexit,error,digit,other} token_e;

token_e lex(const char * istream, chtbl_t * symtbl);

#endif
