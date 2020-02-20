//
// Created by Zhao Xianghe on 1/31/20.
//
#include "file.h"
#include "wav.h"


size_t size;
/**
 * this method read the file and allocate memory for the file
 * @param filename
 * @param buffer
 * @return size_t of the file
 */
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
/**
 * this method write from specific buffer to a new file
 * @param filename
 * @param buffer
 * @param s
 * @return
 */
size_t write_file( char* filename, char *buffer, size_t s){
    FILE *fp;
    size_t fs;

    fp = fopen(filename,"w");//file for the streaming
    fs = fwrite(buffer,1,s,fp);//write the buffer to the file
    fclose(fp);
    return fs;
}
