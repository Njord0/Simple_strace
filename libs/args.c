#include <stdlib.h>
#include <stdio.h>

#include "args.h"

char *getArg(int argc, char *argv[]){
    for (int i = 1; i < argc; i++){
        if (strcmp(argv[i], "--binary") == 0){
            return argv[i+1];
        }

        else if (strcmp(argv[i], "--help") == 0){
            displayUsage();
        }
    }

    displayUsage();
}

void displayUsage(char *arg){
    printf("Usage:\n");
    printf("\t %s --binary 'filename' \n", arg);
    printf("\t %s --help\n\n", arg);
    exit(0);
}
