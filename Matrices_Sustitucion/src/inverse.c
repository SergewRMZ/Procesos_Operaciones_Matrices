#include "../header.h"

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Uso: %s <nombre_archivo_matriz> <nombre_archivo_inversa>\n", argv[0]);
        exit(1);
    }

    char *matriz_FILE = argv[1];
    char *inverse_FILE = argv[2];
    char folder[] = "./output";
    char folderInput[] = "./tmp";
    FILE *matrizFile = openFile(folderInput, matriz_FILE);
    FILE *InverseFile = createFile(folder, inverse_FILE);

    // Leer Matrices
    int **matrix = readIntMatrix(matrizFile, 10);

    showMatrix(matrix, 10);
    // Calcular Inversa
    float **inverse = inverseMatrix(matrix, 10);
    
    // Escribir resultados en archivo
    writeMatrix(InverseFile, (void **)inverse, 10, 'f');

    // Liberar memoria
    freeIntMatrix(matrix, 10);
    freeFloatMatrix(inverse, 10);

    // Cerrar archivos
    fclose(InverseFile);
    fclose(matrizFile);
    return 0;
}
