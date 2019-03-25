#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#define INT_DIGIT_MAX 64

typedef enum ltoken_type {
    TOK_INT
} ltoken_type;

typedef struct ltoken {
    ltoken_type t_tokentype;
    char *s_token;
    unsigned int ui_start, ui_size;
} ltoken;

typedef struct lexmachine {
    char *source;
    unsigned int mui_pointer;
} lexmachine;

typedef struct lexfout {
    ltoken *token;
    int worked;
} lexfout;

lexmachine *new_lexmachine(char*);
ltoken *new_ltoken(ltoken_type, char*, unsigned int);

void L_next(lexmachine*);
char L_peek(lexmachine*);
lexfout *IN_int(lexmachine*);