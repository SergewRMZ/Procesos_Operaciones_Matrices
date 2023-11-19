# Procesos con operaciones de Matrices

Se lleva a cabo la ejecución de 5 procesos donde cada uno de ellos se encarga de determinar una operación específica  entre dos matrices creadas aleatoriamente. Las operaciones son: Suma, resta, multiplicación, transpuesta e inversa.

## Compilación del Código:

```
gcc main.c ./src/*.c ./helpers/*.c -o matriz -lm
```
Para ejecutar el código con la creación de procesos se utilizan como archivo main el 
archivo mainProcess.c

## Compilación del Código:
```
gcc mainProcess.c ./src/*.c ./helpers/*.c -o matriz -lm
```
## Ejecución del Código:
```
./matriz
```

## Compilar código con bandera de depuración
```
gcc -g main.c ./src/*.c ./helpers/*.c -o matriz -lm
```