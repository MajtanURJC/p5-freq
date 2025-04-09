#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


enum{
    max_size = 128,
}

void 
printArray(int *array)
{
    i = 0;
    for (i=0; i<max_size ;i++){
        if (array[i] != 0) {
            printf("%x: %f",i,)
        }
    }
}


int 
main(int argc, char *argv[])
{

    argv++;
    argc--;
    size_t nitems;
    int i;
    int ascii[max_size];

    memset(&ascii,0,max_size);

    for (i=0;i<argc;i++) {

    }

    
}

//%x para hexadecimal