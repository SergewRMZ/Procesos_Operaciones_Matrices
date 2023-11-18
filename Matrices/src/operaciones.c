#include "../header.h"

/**
 * @brief Realiza la suma de dos matrices
 * @param matrix1 La primera matriz
 * @param matrix2 La segunda matriz
 * @param apf Apuntador al archivo
*/
void addMatrix (int **matrix1, int **matrix2, FILE *apf) {
    int i, j;

    for (i = 0; i < filas; i++) { 
        for (j = 0; j < cols; j++) {
            writeFile(apf, matrix1[i][j] + matrix2[i][j]);
        }

        fprintf(apf, "\n");
    }
}

/**
 * @brief Realiza la resta de dos matrices
 * @param matrix1 La primera matriz
 * @param matrix2 La segunda matriz
 * @param apf Apuntador al archivo
*/
void subMatrix(int **matrix1, int **matrix2, FILE *apf) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < cols; j++) {
            writeFile(apf, matrix1[i][j] - matrix2[i][j]);
        }

        fprintf(apf, "\n");
    }
}

/**
 * @brief Realiza la multiplicación de dos matrices
 * @param matrix1 La primera matriz
 * @param matrix2 La segunda matriz
 * @param apf Apuntador al archivo
*/
void multMatrix(int **matrix1, int **matrix2, FILE *apf) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < cols; j++) {
            int res = 0;

            for (int k = 0; k < filas; k++) {
                res += matrix1[i][k] * matrix2[k][j];
            }

            writeFile(apf, res);
        }

        fprintf(apf, "\n");
    }
}

/**
 * @brief Calcula la transpuesta de una matriz
 * @param matrix La matriz
 * @param orden Orden de la Matriz
*/
int **transposeMatrix(int **matrix, int orden) {
    int **transpose = createMatrixInt(orden);
    for (int i = 0; i < orden; i++) {
        for (int j =  0; j < orden; j++) {
           transpose[i][j] = matrix[j][i]; 
        }
    }

    return transpose;
}

int **adjointMatrix (int **matrix, int orden) {
    int **transpose = transposeMatrix(matrix, orden);
    int **adjMatrix = (int **) malloc(sizeof(int*) * orden);
    for (int i = 0; i < orden; i++) {
        adjMatrix[i] = (int *) malloc(sizeof(int) * orden);
    }

    for (int i = 0; i < orden; i++) {
        for (int j = 0; j < orden; j++) {
            adjMatrix[i][j] = getCofactor(transpose, orden, i, j);
        }
    }

    return adjMatrix;
}

/**
 * @brief Calcula el determinante de una matriz
 * utilizando el método de cofactores.
 * @param matrix La matriz
 * @param orden Orden de la matriz
 * @param row  Fila por expandir a cofactores
*/
int determinantMatrix(int **matrix, int orden, int row) {
    int det = 0;
    if (orden == 1) {
        det = matrix[0][0];
    }   else {
            for (int j = 0; j < orden; j++) {
                det = det + matrix[row][j] * getCofactor(matrix, orden, row, j);        
        }
    }

    return det;
} 

int getCofactor(int **matrix, int orden, int row, int col) {
    int n = orden - 1;
    int **subMatrix = (int **) malloc(sizeof(int *) * n);
    
    for (int i = 0; i < n; i++) {
        subMatrix[i] = (int *) malloc(sizeof(int) * n);
    }

    int x = 0, y = 0;

    for (int i = 0; i < orden; i++) {
        if (i != row) {
            for (int j = 0; j < orden; j++) {
                if (j != col) {
                    subMatrix[x][y] = matrix[i][j];
                    // printf("Valor:%d\n", subMatrix[x][y]);
                    y++;

                    if (y >= n) {
                        x++;
                        y = 0;
                    }
                }
            }
        }
    }

    /**
     * Si al disminuir el orden de la matriz, coincide con la fila en la que 
     * se están tomando los cofactores para hallar el determinante, significa
     * que se está tomando la última fila de la matriz original, entonces al reducir
     * el orden de la matriz, esta fila quedará fuera de los límites de esta nueva
     * sub matriz y ocasionará un error de memoria por un desequilibrio
     * en lo límites.
    */

    int cofactor = 0;
    if (n == row) {
        cofactor = pow(-1.0, row + col) * determinantMatrix(subMatrix, n, row - 1);
    }   else {
        cofactor = pow(-1.0, row + col) * determinantMatrix(subMatrix, n, row);
    }
    
    // Liberar la memoria de la Matriz
    freeIntMatrix(subMatrix, n);

    return cofactor;
}

/**
 * @brief Calcula la inversa de una matriz
 * por el método de la adjunta
 * @param matrix La matriz
 * @param orden Orden de la matriz
*/
float **inverseMatrix(int **matrix, int orden) {
    int det = determinantMatrix(matrix, orden, 0);
    matrix = adjointMatrix(matrix, orden);
    float **inverse = createMatrixFloat(orden);

    for (int i = 0; i < orden; i++) {
        for (int j = 0; j < orden; j++) {
            inverse[i][j] = (float) matrix[i][j] / det;
        }
    }
    
    return inverse;
}

/**
 * Función para crear una matriz de flotantes
*/
float **createMatrixFloat(int orden) {
    float **matrix = (float **) malloc(sizeof(float*) * orden);
    for (int i = 0; i < orden; i++) 
        matrix[i] = (float *) malloc(sizeof(float) * orden);

    return matrix;
}

/**
 * Función para crear una matriz de enteros
*/
int **createMatrixInt(int orden) {
    int **matrix = (int **) malloc(sizeof(int *) * orden);
    for (int i = 0; i < orden; i++) 
        matrix[i] = (int *) malloc(sizeof(int) * orden);

    return matrix;
}

void freeIntMatrix(int **matrix, int orden) {
    FREE_MATRIX(matrix, orden);
}

void freeFloatMatrix(float **matrix, int orden) {
    FREE_MATRIX(matrix, orden);
}

void showMatrix (int **matrix1, int orden) {
    for (int i = 0; i < orden; i++) {
        for (int j = 0; j < orden; j++) {
            printf("%4d", matrix1[i][j]);
        }

        printf("\n");
    }
}