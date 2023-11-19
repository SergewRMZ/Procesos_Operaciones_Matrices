#include "header.h"

int main (int argc, char *argv[]) {
    srand(time(NULL));
    int **matrix1 = generateMatrix();
    int **matrix2 = generateMatrix();

    clock_t start, end;

    char folder[] = "./output";
    char sub_FILE[] = "Resta.txt";
    char add_FILE[] = "Suma.txt"; 
    char mult_FILE[] = "Mult.txt";
    char inverse_FILE[] = "Inversa.txt";
    char inverse2_FILE[] = "Inversa2.txt";
    char transpose_FILE[] = "Transpuesta.txt";
    char transpose2_FILE[] = "Transpuesta2.txt";

    FILE *addFile = createFile(folder, add_FILE);
    FILE *subFile = createFile(folder, sub_FILE);
    FILE *multFile = createFile(folder, mult_FILE);
    FILE *transposeFile = createFile(folder, transpose_FILE);
    FILE *transpose2File = createFile(folder, transpose2_FILE);
    FILE *inverseFile = createFile(folder, inverse_FILE);
    FILE *inverse2File = createFile(folder, inverse2_FILE);

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

    pid_t id_process[7];
    for (int i = 0; i < 7; i++) {
        id_process[i] = fork();

        if (id_process[i] == 0) {
            switch (i) {
                case 0:
                    printf("Proceso hijo %i (SUMA) mi padre es: %i\n", getpid(), getppid());
                    addMatrix(matrix1, matrix2, addFile);
                    printf("Suma calculada\n");
                    break;

                case 1:
                    printf("Proceso hijo %i (RESTA) mi padre es: %i\n", getpid(), getppid());
                    subMatrix(matrix1, matrix2, subFile);
                    printf("Resta calculada\n");
                    break;

                case 2:
                    printf("Proceso hijo %i (MULTIPLICACIÓN) mi padre es: %i\n", getpid(), getppid());
                    multMatrix(matrix1, matrix2, multFile);
                    printf("Multiplicación calculada\n");
                    break;
                
                case 3:
                    printf("Proceso hijo %i (TRANSPUESTA) mi padre es: %i\n", getpid(), getppid());
                    int **transpose = transposeMatrix(matrix1, 10);
                    int **transpose_2 = transposeMatrix(matrix2, 10);

                    writeMatrix(transposeFile, (void **) transpose, 10, 'i');
                    writeMatrix(transpose2File, (void **) transpose_2, 10, 'i');

                    freeIntMatrix(transpose, 10);
                    freeIntMatrix(transpose_2, 10);
                    printf("Tranpuestas calculadas\n");
                    break;

                case 4:
                    printf("Proceso hijo %i (INVERSA) mi padre es: %i\n", getpid(), getppid());
                    float **inverse = inverseMatrix(matrix1, 10); 
                    writeMatrix(inverseFile, (void **) inverse, 10, 'f');   
                    freeFloatMatrix(inverse, 10);
                    printf("Inversa de la Matriz 1 calculada\n");   
                    break;

                case 5:
                    printf("Proceso hijo %i (INVERSA) mi padre es: %i\n", getpid(), getppid());
                    float **inverse_2 = inverseMatrix(matrix2, 10);
                    writeMatrix(inverse2File, (void **) inverse_2, 10, 'f');
                    freeFloatMatrix(inverse_2, 10); 
                    printf("Inversa de la Matriz 2 calculada\n");
                    break;

                default:
                    break;
            }
            
            exit(0);
        }

    } 

    for (int i = 0; i < 6; i++) {
        waitpid(id_process[i], NULL, 0);
    }

    /**
     * Una vez terminados los procesos, mostramos los resultados, 
     * de lo contrario vamos a tener problemas al acceder a archivos 
     * con contenido vacío.
    */
    
    if (id_process[6] != 0) {
        printf("Proceso hijo %i (MOSTRAR ARCHIVOS) mi padre es: %i\n", getpid(), getppid());
        printf("Suma:\n\n");
        readIntMatrix(addFile, 10);
        printf("\nResta:\n\n");
        readIntMatrix(subFile, 10);
        printf("\nMultiplicación:\n\n");
        readIntMatrix(multFile, 10);
        printf("\nTranspuesta de la Matriz 1:\n\n");
        readIntMatrix(transposeFile, 10);
        printf("\nTranpuesta de la Matriz 2: \n\n");
        readIntMatrix(transpose2File, 10);
        printf("\nInversa de la Matriz 1: \n\n");
        readFloatMatrix(inverseFile, 10);
        printf("\nInversa de la Matriz 2:\n\n");
        readFloatMatrix(inverse2File, 10);
    }
    
    //******************************************************************	
	//      Liberar Memoria
	//******************************************************************
    freeIntMatrix(matrix1, 10);
    freeIntMatrix(matrix2, 10);

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
	//******************************************************************

    return 0;
}