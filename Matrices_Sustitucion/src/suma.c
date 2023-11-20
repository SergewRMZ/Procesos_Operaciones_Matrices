#include "../header.h"

int main (int argc, char *argv[]) {
    char add_FILE[] = "Suma.txt";
    char folder[] = "./output";
    FILE *matrix1File = fopen("./tmp/matriz1.txt", "r");
    FILE *matrix2File = fopen("./tmp/matriz2.txt", "r");
    FILE *addFile = createFile(folder, add_FILE);    

    int **matrix1 = readIntMatrix(matrix1File, 10);
    int **matrix2 = readIntMatrix(matrix2File, 10);
    
    addMatrix(matrix1, matrix2, addFile);

    // Liberar memoria
    freeIntMatrix(matrix1, 10);
    freeIntMatrix(matrix2, 10);

    // Cerrar archivo
    fclose(addFile);
    fclose(matrix1File);
    fclose(matrix2File);
    return 0;
}