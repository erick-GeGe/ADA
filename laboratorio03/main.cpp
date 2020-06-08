#include <time.h>
#include "insertSort.h"
#include "mergeSortGG.h"        // GG por GeeksforGeeks
#include "mergeSort.h"
#include "funciones.h"

using namespace std;

int main()
{
    int n = 1000;               // tamanio del arreglo
    int pruebas = 50;           // cantidad de pruebas
    int arreglo[pruebas][n], cArreglo[pruebas][n];                 
    srand(time(NULL));
    for (size_t i = 0; i < pruebas; i++)
    {
        llenarLista(arreglo[i], n);
        copiarArreglo(arreglo[i], cArreglo[i], n);
    }
    

    cout << "..::Arreglo de " << n << " Merge Sort::.." << endl;
    unsigned t0 = clock();

    for (size_t i = 0; i < pruebas; i++)
        mergeSort(cArreglo[i], 0, n - 1);

    unsigned t1 = clock();
    double time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "time: " << time << '\n' << endl;



    // cout << "..::Arreglo de " << n << " Insert Sort::.." << endl;
    // t0 = clock();

    // for (size_t i = 0; i < pruebas; i++)
    //     insertionSort(arreglo[i], n);
    
    // t1 = clock();
    // time = (double(t1-t0)/CLOCKS_PER_SEC);
    // cout << "time: " << time << endl;


    // ejercicio 2
    cout << "..::Arreglo de " << n << " Merge Sort GG::.." << endl;
    t0 = clock();

    for (size_t i = 0; i < pruebas; i++)
        mergeSortGG(arreglo[i], 0, n);
    
    t1 = clock();
    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "time: " << time << endl;

}