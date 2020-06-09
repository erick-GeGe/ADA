#include <iostream>

void llenarLista(int* arreglo, int tam)     
{
    for (size_t i = 0; i < tam; i++)
        arreglo[i] = 1+rand()%(tam-1);
}


void copiarArreglo(int* original, int* copia, int size)
{
    for(int i = 0; i<size; i++)
        copia[i] = original[i];
}
