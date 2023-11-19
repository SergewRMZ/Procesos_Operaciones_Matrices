#ifndef HEADER_H
#define HEADER_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <time.h>
#include <math.h>
#define cols 10
#define filas 10

// MACRO PARA LIBERAR MEMORIA DE UNA MATRIZ
#define FREE_MATRIX(matrix, orden) \
    for (int i = 0; i < orden; i++) { \
        free(matrix[i]); \
    } \
    free(matrix);


// Operaciones de Matrices
void showMatrix(int **matrix1, int orden);
void freeIntMatrix(int **matrix, int orden);
void freeFloatMatrix(float **matrix, int orden);
float **createMatrixFloat(int orden);
int **createMatrixInt (int orden);

void addMatrix(int **matrix1, int **matrix2, FILE *apf);
void subMatrix(int **matrix1, int **matrix2, FILE *apf);
void multMatrix(int **matrix1, int **matrix2, FILE *apf);

int **transposeMatrix(int **matrix, int orden);
int determinantMatrix(int **matrix, int orden, int row);
int **adjointMatrix (int **matrix, int orden);
int getCofactor(int **matrix, int orden, int row, int col);
float **inverseMatrix(int **matrix, int orden);

int **generateMatrix();

// Operaciones con ficheros
FILE *createFile (const char *folder, const char *fileName);
void writeFile(FILE *apf, const int valor);
void writeMatrix (FILE *apf, void **matrix, int orden, char type);
void readIntMatrix (FILE *apf, int orden);
void readFloatMatrix(FILE *apf, int orden);

// Función para medir tiempos
void uswtime(double *usertime, double *systime, double *walltime);

#endif // HEADER_H