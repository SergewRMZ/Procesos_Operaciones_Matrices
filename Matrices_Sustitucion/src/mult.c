#include "../header.h"

int main (int argc, char *argv[]) {
    char sub_FILE[] = "Mult.txt";
    char folder[] = "./output";
    FILE *matrix1File = fopen("./tmp/matriz1.txt", "r");
    FILE *matrix2File = fopen("./tmp/matriz2.txt", "r");
    FILE *multFile = createFile(folder, sub_FILE);    

    int **matrix1 = readIntMatrix(matrix1File, 10);
    int **matrix2 = readIntMatrix(matrix2File, 10);
    
    multMatrix(matrix1, matrix2, multFile);

    // Liberar memoria
    freeIntMatrix(matrix1, 10);
    freeIntMatrix(matrix2, 10);

    // Cerrar archivo
    fclose(multFile);
    fclose(matrix1File);
    fclose(matrix2File);
    return 0;
}