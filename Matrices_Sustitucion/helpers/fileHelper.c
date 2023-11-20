#include "../header.h"

FILE *createFile (const char *folder, const char *fileName) {
    char fullpath[256];
    snprintf(fullpath, sizeof(fullpath), "%s/%s", folder, fileName);

    FILE *apf;
    apf = fopen(fullpath, "w+");
    
    if (apf == NULL) {
        fprintf(stderr, "Error al crear el archivo\n");
        exit(EXIT_FAILURE);
    }

    return apf;
}

FILE *openFile (const char *folder, const char *fileName) {
    char fullpath[256];
    snprintf(fullpath, sizeof(fullpath), "%s/%s", folder, fileName);

    FILE *apf;
    apf = fopen(fullpath, "r");
    
    if (apf == NULL) {
        fprintf(stderr, "Error al abrir el archivo\n");
        exit(EXIT_FAILURE);
    }

    return apf;
}


void writeFile (FILE *apf, const int valor) {
    fprintf(apf, "%6d", valor);
}

void writeMatrix (FILE *apf, void **matrix, int orden, char type) {
    if (type == 'i') {
        for (int i = 0; i < orden; i++) {
            for (int j = 0; j < orden; j++) {
                fprintf(apf, "%6d", *((int *) matrix[i] + j));
            }

            fprintf(apf, "\n");
        }
    }   else if(type  == 'f') {
        for (int i = 0; i < orden; i++) {
            for (int j = 0; j < orden; j++) {
                fprintf(apf, "%8.4f\t", *((float *) matrix[i] + j));
            }

            fprintf(apf, "\n");
        }
    }
}

int **readIntMatrix (FILE *apf, int orden) {
    fseek(apf, 0, SEEK_SET); // Posicionar el puntero al inicio del archivo
    int **matriz = createMatrixInt(10);
    for (int i = 0; i < orden; i++) {
        for (int j = 0; j < orden; j++) {
            fscanf(apf, "%d", &matriz[i][j]);
        }
    }

    return matriz;
}

/**
 * Función para leer la matriz del archivo y mostrarla
 * en la consola
*/
void showIntMatrix (FILE *apf, int orden) {
    fseek(apf, 0, SEEK_SET); // Posicionar el puntero al inicio del archivo
    int valor;
    for (int i = 0; i < orden; i++) {
        for (int j = 0; j < orden; j++) {
            fscanf(apf, "%d", &valor);
            printf("%6d", valor);
        }

        printf("\n");
    }
}

void readFloatMatrix (FILE *apf, int orden) {
    fseek(apf, 0, SEEK_SET); // Posicionar el puntero al inicio del archivo
    float valor;
    for (int i = 0; i < orden; i++) {
        for (int j = 0; j < orden; j++) {
            fscanf(apf, "%f", &valor);
            printf("%8.4f", valor);
        }

        printf("\n");
    }
}