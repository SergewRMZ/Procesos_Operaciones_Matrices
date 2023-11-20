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

    // Generar Matrices
    int **matrix1 = generateMatrix();
    int **matrix2 = generateMatrix();

    // Archivos
    char matriz1_FILE[] = "matriz1.txt";
    char matriz2_FILE[] = "matriz2.txt";
    char folder[] = "./tmp";
    printf("Matrices Creadas\n");

    FILE *matriz1File = createFile(folder, matriz1_FILE);
    FILE *matriz2File = createFile(folder, matriz2_FILE);

    // Escribir las matrices en archivos
    writeMatrix(matriz1File, (void **) matrix1, 10, 'i');
    writeMatrix(matriz2File, (void **) matrix2, 10, 'i');

    pid_t idProcess[7];
    for (int i = 0; i < 7; i++) {
        idProcess[i] = fork();

        if (idProcess[i] == 0) {
            switch (i) {
            case 0:
                printf("Ejecutando Suma...");
                execl("/home/sergew/SO/Practica5/Matrices_Sustitucion/exec/suma", "suma", (char *) NULL);
                perror("Error al ejecutar suma");
                exit(1);
                break;

            case 1: 
                printf("Ejecutando Resta...");
                execl("/home/sergew/SO/Practica5/Matrices_Sustitucion/exec/resta", "resta", NULL);
                perror("Error al ejecutar resta");
                exit(1);
                break;

            case 2:
                printf("Ejecutando Multiplicación...");
                execl("/home/sergew/SO/Practica5/Matrices_Sustitucion/exec/mult", "mult", NULL);
                perror("Error al ejecutar mult");
                exit(1);
                break;

            case 3:
                printf("Ejecutando Transpuesta...");
                execl("/home/sergew/SO/Practica5/Matrices_Sustitucion/exec/transpose", "transpose", NULL);
                perror("Error al ejecutar transpuesta");
                exit(1);
                break;

            case 4:
                printf("Ejecutando Inversa...");
                execl("/home/sergew/SO/Practica5/Matrices_Sustitucion/exec/inverse", "inverse", matriz1_FILE, "Inversa1.txt", NULL);
                perror("Error al ejecutar inverse");
                exit(1);
                break;

            case 5:
                execl("/home/sergew/SO/Practica5/Matrices_Sustitucion/exec/inverse", "inverse", matriz2_FILE, "Inversa2.txt", NULL);
                perror("Error al ejecutar inverse");
                exit(1);
                break;
            
            default:
                break;
            }

            exit(0);
        }
    }

    for (int i = 0; i < 6; i++) {
        waitpid(idProcess[i], NULL, 0);
    }

    /**
     * Una vez terminados los procesos, mostramos los resultados, 
     * de lo contrario vamos a tener problemas al acceder a archivos 
     * con contenido vacío.
    */
    
    if (idProcess[6] == 0) {
        char *args[] = {"readData", NULL};
        execvp("/home/sergew/SO/Practica5/Matrices_Sustitucion/exec/readData", args);
        perror("Error al ejecutar readData");
        exit(1);
    }

    // Esperar que termine el proceso
    waitpid(idProcess[6], NULL, 0);

    
    //******************************************************************	
	//      Liberar Memoria
	//******************************************************************
    freeIntMatrix(matrix1, 10);
    freeIntMatrix(matrix2, 10);

    
    //******************************************************************	
	//      Cerrar Archivos 
	//******************************************************************
    fclose(matriz1File);
    fclose(matriz2File);
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