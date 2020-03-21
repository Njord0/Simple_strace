#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "libs/args.h"
#include "libs/check.h"

int main(int argc, char *argv[]){

    char *filename = getArg(argc, argv);

    if (isElfFile(filename)){
        if (is32BitsBinary(filename)){
            fprintf(stderr, "[!] Not supported yet...\n");
            return -1;
        }

        else if (is64BitsBinary(filename)){
            printf("This is good...\n");
        }

        else {
            fprintf(stderr, "Unsupported arch...\n");
            return -1;
        }
    }

    return 0;
}