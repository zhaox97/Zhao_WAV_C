//
// Created by Zhao Xianghe on 1/31/20.
//

#ifndef WAV_C_FILE_H
#define WAV_C_FILE_H
#include <stdio.h>

//header file(signature)
size_t read_file( char* filename, char **buffer );
size_t write_file( char* filename, char *buffer, size_t size);


#endif //WAV_C_FILE_H
