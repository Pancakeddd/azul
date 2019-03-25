#include "lex.h"

typedef struct parsemachine
{
    ltoken **tokenstream;
    unsigned int mui_pointer;
} parsemachine;