#include <stdio.h>
#include <stdlib.h>

#include "logging.h"

void log_(unsigned int type, const char* message)
{
    if (type == L_ERROR)
    {
        fprintf(stderr, "%s\n", message);
        exit(L_ERROR);
    }

    if (type == L_WARNING)
        fprintf(stderr, "%s\n", message);

    else if (type == L_LOG)
        fprintf(stdout, "%s\n", message);

    return;
}
