#include <stdio.h>
#include "parse.h"

int main(int argc, char const *argv[])
{
    lexmachine *L = new_lexmachine("100+ 200");
    ltoken *t = L_nexttoken(L);

    while(t != NULL)
    {
        printf(t->s_token);
        t = L_nexttoken(L);
    }

    free(t);
    free(L);
    return 0;
}