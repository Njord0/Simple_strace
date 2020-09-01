#ifndef _CHECK_H
#define _CHECK_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

bool is_elf_file(FILE *fp);
bool is_elf64(FILE *fp);
bool is_elf32(FILE *fp);

#endif