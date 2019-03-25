#include <stdio.h>
#include "lex.h"

int main(int argc, char const *argv[])
{
    lexmachine *L = new_lexmachine("100");
    lexfout *lo = IN_int(L);
    printf("%d, %s", lo->worked, lo->token->s_token);
    free(lo->token);
    free(lo);
    free(L);
    return 0;
}