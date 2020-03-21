#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isElfFile(char *filename){

    char buffer[4]; 
    FILE *binary = fopen(filename, "rb");
    
    if (binary == NULL){
        fprintf(stderr, "[!] Can't open %s\n\n", filename);
        exit(-1);
    }
    
    fread(buffer, sizeof(buffer), 1, binary);

    if (strcmp(buffer+1, "ELF") != 0){
        return false;
    }
    return true;
}

bool is32BitsBinary(char *filename){
    char buffer[5];
    FILE *file_ptr = fopen(filename, "rb");
    
    if (file_ptr == NULL){
        fprintf(stderr, "[!] Can't open %s\n", filename);
        exit(-1);
    }

    fread(buffer, sizeof(buffer), 1, file_ptr);

    if (buffer[4] == 1){
        return true;
    }

    return false;
}

bool is64BitsBinary(char *filename){
    char buffer[5];
    FILE *file_ptr = fopen(filename, "rb");
    
    if (file_ptr == NULL){
        fprintf(stderr, "[!] Can't open %s\n", filename);
        exit(-1);
    }

    fread(buffer, sizeof(buffer), 1, file_ptr);

    if (buffer[4] == 2){
        return true;
    }

    return false;

}