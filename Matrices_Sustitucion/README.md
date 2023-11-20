# Compilación del proyecto
```
gcc main.c ./src/operaciones.c ./helpers/*.c -o matriz -lm
```

## Programa de Matriz Inversa
El programa o ejecutable para hallar la matriz inversa recibe como parámetros
el nombre del archivo donde se aloja la matriz y el nombre del archivo
para almacenar el resultado.

```
./inverse nombreMatriz.txt inversaMatriz.txt
```