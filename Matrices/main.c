#include "header.h"

int main (int argc, char *argv[]) {

    //*********************************************************
    //      VARIABLES PARA MEDIR TIEMPO
    //*********************************************************
    double utime0, stime0, wtime0,utime1, stime1, wtime1; //Variables para medición de tiempos
	int n; 	//n determina el tamaño del algorito dado por argumento al ejecutar
	int i; //Variables para loops

    //**************************************************************************
	//      Iniciar el conteo del tiempo para las evaluaciones de rendimiento
	//**************************************************************************	
	uswtime(&utime0, &stime0, &wtime0);

    srand(time(NULL));
    int **matrix1 = generateMatrix();
    int **matrix2 = generateMatrix();

    printf("Matriz 1:\n"); showMatrix(matrix1, 10);
    printf("\nMatriz 2:\n"); showMatrix(matrix2, 10);
    char folder[] = "./output";
    char sub_FILE[] = "Resta.txt";
    char add_FILE[] = "Suma.txt"; 
    char mult_FILE[] = "Mult.txt";
    char inverse_FILE[] = "Inversa.txt";
    char transpose_FILE[] = "Transpuesta.txt";
    char transpose2_FILE[] = "Transpuesta2.txt";
    char inverse2_FILE[] = "Inversa2.txt";

    FILE *addFile = createFile(folder, add_FILE);
    FILE *subFile = createFile(folder, sub_FILE);
    FILE *multFile = createFile(folder, mult_FILE);
    FILE *transposeFile = createFile(folder, transpose_FILE);
    FILE *transpose2File = createFile(folder, transpose2_FILE);
    FILE *inverseFile = createFile(folder, inverse_FILE);
    FILE *inverse2File = createFile(folder, inverse2_FILE);

    addMatrix(matrix1, matrix2, addFile);
    subMatrix(matrix1, matrix2, subFile);
    multMatrix(matrix1, matrix2, multFile);
    int **transpose = transposeMatrix(matrix1, 10);
    int **transpose2 = transposeMatrix(matrix2, 10);
    writeMatrix(transposeFile, (void **) transpose, 10, 'i');
    writeMatrix(transpose2File, (void **) transpose2, 10, 'i');

    //  Inversa de la matriz
    float **inverse = inverseMatrix(matrix1, 10);
    float **inverse2 = inverseMatrix(matrix2, 10);
    writeMatrix(inverseFile, (void **) inverse, 10, 'f');
    writeMatrix(inverse2File, (void **) inverse2, 10, 'f');


    //******************************************************************	
	//      Liberar Memoria
	//******************************************************************
    freeIntMatrix(transpose, 10);
    freeIntMatrix(matrix1, 10);
    freeIntMatrix(matrix2, 10);
    freeFloatMatrix(inverse, 10);
    freeFloatMatrix(inverse2, 10);

    //******************************************************************	
	//      Cerrar los Archivos 
	//******************************************************************
    fclose(transposeFile);
    fclose(multFile);
    fclose(addFile);
    fclose(subFile);
    fclose(inverseFile);

    //******************************************************************	
	//      Evaluar los tiempos de ejecución 
	//******************************************************************
	uswtime(&utime1, &stime1, &wtime1);
	
	printf("\nTiempo de Ejecucion\n");
	printf("real (Tiempo total)  %.10f s\n",  wtime1 - wtime0);
	printf("user (Tiempo de procesamiento en CPU) %.10f s\n",  utime1 - utime0);
	printf("sys (Tiempo en acciónes de E/S)  %.10f s\n",  stime1 - stime0);
	printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
	printf("\n");
	
	//  Mostrar los tiempos en formato exponecial
	printf("\n");
	printf("real (Tiempo total)  %.10e s\n",  wtime1 - wtime0);
	printf("user (Tiempo de procesamiento en CPU) %.10e s\n",  utime1 - utime0);
	printf("sys (Tiempo en acciónes de E/S)  %.10e s\n",  stime1 - stime0);
	printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
	printf("\n");
	//******************************************************************

    return 0;
}