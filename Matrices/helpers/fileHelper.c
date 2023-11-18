#include "../header.h"

FILE *createFile (const char *folder, const char *fileName) {
    char fullpath[256];
    snprintf(fullpath, sizeof(fullpath), "%s/%s", folder, fileName);

    FILE *apf;
    apf = fopen(fullpath, "w");
    
    if (apf == NULL) {
        fprintf(stderr, "Error al crear el archivo\n");
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