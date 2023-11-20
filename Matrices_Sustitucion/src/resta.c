#include "../header.h"

int main (int argc, char *argv[]) {
    char sub_FILE[] = "Resta.txt";
    char folder[] = "./output";
    FILE *matrix1File = fopen("./tmp/matriz1.txt", "r");
    FILE *matrix2File = fopen("./tmp/matriz2.txt", "r");
    FILE *subFile = createFile(folder, sub_FILE);    

    int **matrix1 = readIntMatrix(matrix1File, 10);
    int **matrix2 = readIntMatrix(matrix2File, 10);
    
    subMatrix(matrix1, matrix2, subFile);

    // Liberar memoria
    freeIntMatrix(matrix1, 10);
    freeIntMatrix(matrix2, 10);

    // Cerrar archivo
    fclose(subFile);
    fclose(matrix1File);
    fclose(matrix2File);
    return 0;
}