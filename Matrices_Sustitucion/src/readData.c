#include "../header.h"

int main (int argc, char *argv[]) {
    char folder[] = "./output";
    char sub_FILE[] = "Resta.txt";
    char add_FILE[] = "Suma.txt"; 
    char mult_FILE[] = "Mult.txt";
    char inverse_FILE[] = "Inversa1.txt";
    char inverse2_FILE[] = "Inversa2.txt";
    char transpose_FILE[] = "Transpuesta1.txt";
    char transpose2_FILE[] = "Transpuesta2.txt";

    FILE *addFile = openFile(folder, add_FILE);
    FILE *subFile = openFile(folder, sub_FILE);
    FILE *multFile = openFile(folder, mult_FILE);
    FILE *transpose1File = openFile(folder, transpose_FILE);
    FILE *transpose2File = openFile(folder, transpose2_FILE);
    FILE *inverse1File = openFile(folder, inverse_FILE);
    FILE *inverse2File = openFile(folder, inverse2_FILE);

    printf("Suma:\n\n");
    showIntMatrix(addFile, 10);
    printf("\nResta: \n\n");
    showIntMatrix(subFile, 10);
    printf("\nMultiplicación: \n\n");
    showIntMatrix(multFile, 10);
    printf("\nTranpuesta de la matriz 1: \n\n");
    showIntMatrix(transpose1File, 10);
    printf("\nTrasnpuesta de la matriz 2: \n\n");
    showIntMatrix(transpose2File, 10);
    printf("\nInversa de la matriz 1: \n\n");
    readFloatMatrix(inverse1File, 10);
    printf("\nInversa de la matriz 2: \n\n");
    readFloatMatrix(inverse2File, 10);

    // Cerrar los archivos
    fclose(addFile);
    fclose(subFile);
    fclose(multFile);
    fclose(transpose1File);
    fclose(transpose2File);
    fclose(inverse1File);
    fclose(inverse2File);
}