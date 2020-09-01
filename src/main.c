#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "utils/args.h"
#include "utils/check.h"

#include "core/logging.h"
#include "core/x86_64/trace64.h"

int main(int argc, char **argv)
{

    char *filename = get_arg(argc, argv);

    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
        return -1;

    if (is_elf_file(fp))
    {
        if (is_elf32(fp))
            log_(L_ERROR, "Not supported yet");


        else if (is_elf64(fp))
           tracex64(filename, argv);



        else
            log_(L_ERROR, "Unknow arch...");


    }

    return 0;
}
