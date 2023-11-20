#!/bin/bash

# Script para compilar cada operación de la matriz
source=(
    "suma"
    "resta"
    "mult"
    "transpose"
    "inverse"
    "readData"
)

# Compilar todos los programas
for source_file in "${source[@]}"; do
    gcc ./$source_file.c ./operaciones.c  ../helpers/*.c -o ../exec/$source_file -lm 
done

echo "Compilación Terminada"