#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

enum {
    max_size = 128, 
};

void 
printArray(int *array, int num) {
    int i;
    for (i = 0; i < max_size; i++) {
        if (array[i] != 0) {

            printf("%#04x: %f\n", i, (double) array[i] / num);
        }
    }
}

int 
main(int argc, char *argv[]) {
    argv++;
    argc--;
    int i;
    int ascci[max_size];
    int caracter;
    FILE *archivo;
    int caracteres = 0;

    // Inicializamos el arreglo ascci con ceros
    memset(ascci, 0, max_size * sizeof(int));

    for (i = 0; i < argc; i++) {
        archivo = fopen(argv[i], "r");

        if (archivo == NULL) {
            perror("Error al abrir el archivo");
            return 1;
        }

        while ((caracter = fgetc(archivo)) != EOF) {
            if (caracter >= 0 && caracter < max_size) {
                ascci[caracter]++;
                caracteres++;
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
