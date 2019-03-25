#include <stdio.h>
#include "lex.h"

int main(int argc, char const *argv[])
{
    lexmachine *L = new_lexmachine("t100");
    printf("%d", IN_int(L));
    free(L);
    return 0;
}