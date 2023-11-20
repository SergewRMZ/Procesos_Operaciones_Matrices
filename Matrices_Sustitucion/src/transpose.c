#include "../header.h"

int main (int argc, char *argv[]) {
    char tranpose1_FILE[] = "Transpuesta1.txt";
    char transpose2_FILE[] = "Transpuesta2.txt";
    char folder[] = "./output";
    FILE *matrix1File = fopen("./tmp/matriz1.txt", "r");
    FILE *matrix2File = fopen("./tmp/matriz2.txt", "r");
    FILE *trFile1 = createFile(folder, tranpose1_FILE);
    FILE *trFile2 = createFile(folder, transpose2_FILE);    

    // Leer Matrices
    int **matrix1 = readIntMatrix(matrix1File, 10);
    int **matrix2 = readIntMatrix(matrix2File, 10);
    
    // Calcular Transpuestas
    int **tranpose1 = transposeMatrix(matrix1, 10);
    int **tranpose2 = transposeMatrix(matrix2, 10);

    // Escribir resultados en archivo
    writeMatrix(trFile1, (void **) tranpose1, 10, 'i');
    writeMatrix(trFile2, (void **) tranpose2, 10, 'i');

    // Liberar memoria
    freeIntMatrix(matrix1, 10);
    freeIntMatrix(matrix2, 10);
    freeIntMatrix(tranpose1, 10);
    freeIntMatrix(tranpose2, 10);

    // Cerrar archivo
    fclose(trFile1);
    fclose(trFile2);
    fclose(matrix1File);
    fclose(matrix2File);
    return 0;
}