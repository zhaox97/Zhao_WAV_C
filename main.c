#include <stdio.h>
#include "wav.h"
#include "file.h"

int main(int argc, char **argv ) {

    char* buffer;
    wav_file *wav = NULL;
    size_t size;

    size = read_file(argv[1],&buffer);
    wav =  parse(buffer);
    /**
     * - File size is 2646044.  Read 2646036 bytes.
- Format is "fmt " with format data length 16.
- Format type is WAVEfmt
- 1 channels with a sample rate of 22050.
- 44100 byte rate, 2 alignment, 16 bits per sample.
- Data is "data" and data size is 2646000
    **/
    printf("File: %s\n",argv[1]);
    puts("-------------------------------------------");
    printf("- File size is: %zu. Read:%d bytes\n",size,wav->chunk_size);
    printf("- Format is %s with format data length %d. \n",wav->fmt,wav->format_len);
    printf("- Format type is %hd\n",wav->format_type);
    printf("- 1 channels with a sample rate of %d.\n",wav->sample_rate);
    printf("- %d byte rate, %hd alignment, %hd bits per sample.\n",wav->byte_rate,wav->block_alignment,wav->bits_perSample);
    printf("- Data is %s and data size is %d\n",wav->data,wav->data_size);

    char newbuf[size];

    //copy the first 0-43 bytes from the buffer to the new buffer
    for(int i = 0; i <= 43; i++){
        newbuf[i] = buffer[i];
    }

    //reverse the rest and put them to the newbuf
    int begin = 44;
    int end = size;
    for(int l = begin; l <= size; l+=2 ){
        newbuf[l] = buffer[end-1];
        newbuf[l+1] = buffer[end];
        end-=2;
    }

    write_file(argv[2], newbuf, size);
    return 0;
}