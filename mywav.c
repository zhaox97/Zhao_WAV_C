//
// Created by Zhao Xianghe on 1/31/20.
//
#include "wav.h"
#include "file.h"
#include <string.h>\wav_file *p;

wav_file* parse(char* contents){
    wav_file *p = malloc(44 * sizeof(char));
    return memcpy(p,contents, 44);
}

