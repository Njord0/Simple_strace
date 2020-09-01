#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "utils/args.h"
#include "utils/check.h"
#include "core/trace64.h"

int main(int argc, char **argv)
{

    char *filename = get_arg(argc, argv);

    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
        return -1;

    if (is_elf_file(fp))
    {
        if (is_elf32(fp))
        {
            fprintf(stderr, "[!] Not supported yet...\n");
            return -1;
        }

        else if (is_elf64(fp))
           tracex64(filename, argv);
        
    

        else 
        {
            fprintf(stderr, "Unsupported arch...\n");
            return -1;
        }
    }

    return 0;
}