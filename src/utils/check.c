#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "check.h"

bool is_elf_file(FILE *fp)
{

    char buffer[4];

    fread(buffer, sizeof(buffer), 1, fp);

    if (strcmp(buffer+1, "ELF") != 0)
        return false;

    return true;
}

bool is_elf32(FILE *fp)
{
    char buffer[5];
    
    fseek(fp, 0, SEEK_SET);
    fread(buffer, sizeof(buffer), 1, fp);

    if (buffer[4] == 1)
        return true;

    return false;
}

bool is_elf64(FILE *fp)
{
    char buffer[5];
    fseek(fp, 0, SEEK_SET);
    fread(buffer, sizeof(buffer), 1, fp);
    if (buffer[4] == 2)
        return true;

    return false;

}
