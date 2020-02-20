//
// Created by Zhao Xianghe on 1/31/20.
//
#include "file.h"
#include "wav.h"


size_t size;

size_t read_file( char* filename, char **buffer ){

    FILE *fp;
    long filelen;

    fp = fopen(filename, "rb");  // Open the file in binary mode
    fseek(fp, 0, SEEK_END);          // Jump to the end of the file
    filelen = ftell(fp);             // Get the current byte offset in the file
    rewind(fp);                      // Jump back to the beginning of the file

    *buffer =  (char *) malloc(filelen * sizeof(char)); // Enough memory for the file
    size = fread(*buffer, filelen, sizeof(char), fp); // Read in the entire file
    fclose(fp); // Close the file
    return filelen;
}
size_t write_file( char* filename, char *buffer, size_t s){
    FILE *fp;
    size_t fs;

    fp = fopen(filename,"w");
    fs = fwrite(buffer,1,s,fp);
    fclose(fp);
    return fs;
}
