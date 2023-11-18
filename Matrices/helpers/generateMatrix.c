#include "../header.h"

int **generateMatrix() { 

    int **matriz = (int **) malloc(filas * sizeof(int*));
    for (int i = 0; i < filas; i++) {
        matriz[i] = (int*) malloc(cols * sizeof(int));
    }

    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < cols; j++) {
            matriz[i][j] = rand() % 13;
        }
    }

    return matriz;
}