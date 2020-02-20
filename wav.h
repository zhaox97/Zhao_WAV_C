#ifndef HEADER_FILE_WAV
#define HEADER_FILE_WAV

#include <stdlib.h>

typedef struct {
    char riff[4];//always same value"RIFF"
    int chunk_size;//Chunk size(file- 8 bytes)
    char wave[4];//if doesn't say this, don't use
    char fmt[4];//may vary
    int format_len;
    short format_type;
    short num_channels;
    int sample_rate;
    int byte_rate;
    short block_alignment;
    short bits_perSample;
    char data[4];//beginning of data section
    int data_size;
} wav_file;
wav_file* parse(char* contents);
#endif//HEADER_FILE_WAV
