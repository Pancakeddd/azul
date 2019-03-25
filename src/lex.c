#include "lex.h"

lexmachine *new_lexmachine(char* source)
{
    lexmachine *lex = (lexmachine*)malloc(sizeof(lexmachine*));

    lex->source = source;
    lex->mui_pointer = 0;

    return lex;
}

ltoken *new_ltoken(ltoken_type type, char* token, unsigned int start)
{
    ltoken *tok = (ltoken*)malloc(sizeof(ltoken));

    tok->t_tokentype = type;
    tok->s_token = token;
    tok->ui_start = start;
    tok->ui_size = strlen(token);

    return tok;
}

void L_next(lexmachine *L)
{
    L->mui_pointer++;
}

char L_peek(lexmachine *L)
{
    size_t size = strlen(L->source);
    if(L->mui_pointer > size)
    {
        return 0;
    }

    return L->source[L->mui_pointer];
}

lexfout *IN_int(lexmachine* L)
{
    char *buffer = calloc(INT_DIGIT_MAX, sizeof(char));
    char c = L_peek(L);
    if(c != 0)
    {
        unsigned i = 0;
        char peekc = L_peek(L);
        while(peekc != 0 && isdigit(peekc))
        {
            peekc = L_peek(L);
            buffer[i] = peekc;
            L_next(L);
            i++;
        }
        buffer[i] = '\0';
    }

    lexfout *out = malloc(sizeof(lexfout));
    out->worked = buffer[0] == '\0' ? 0 : 1;
    out->token = new_ltoken(TOK_INT, buffer, L->mui_pointer);
    return out;
}