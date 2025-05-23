#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

enum {
    max_size = 128,
    buffer_size = 4028,
};

void
printArray(int *array, int num) 
{

    for (int i = 0; i < max_size; i++) {
        if (array[i] != 0) {
            printf("%#04x: %f\n", i, (double) array[i] / num);
        }
    }
}

int
main(int argc, char *argv[]) 
{
    argv++;
    argc--;
    int ascci[max_size];
    int leidos;
    int j;
    int posicion;
    FILE *archivo;
    int caracteres = 0;
    unsigned char buffer[buffer_size];

    // Inicializamos el arreglo ascci con ceros
    memset(ascci, 0, max_size * sizeof(int));

    for (int i = 0; i < argc; i++) {
        archivo = fopen(argv[i], "r"); 

        if (archivo == NULL) {
            perror("Error al abrir el archivo");
            return 1;
        }
        while ((leidos = fread(buffer, sizeof(unsigned char), buffer_size, archivo)) > 0) {
            for (j = 0; j < leidos; j++) {
                if (buffer[j] < max_size) {
                    posicion = (int) buffer[j];
                    ascci[posicion]++;
                    caracteres++;
                }
            }
        }

        fclose(archivo);
    }

    if (caracteres > 0) {
        printArray(ascci, caracteres);
    } else {
        printf("No se leyeron caracteres.\n");
    }

    return 0;
}
