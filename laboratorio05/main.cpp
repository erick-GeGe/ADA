#include <time.h>
#include <algorithm>
#include <vector>
#include "mergeSort.h"
#include "funciones.h"

using namespace std;

int main()
{
    for (size_t j = 1; j <= 100; j++)
    {
        int n = j*1000; 
        
        srand(time(NULL));
        int arreglo[n], cArreglo[n];                 
        vector<int> arreglo_v (cArreglo, cArreglo + n);
        llenarLista(arreglo, n);
        copiarArreglo(arreglo, cArreglo, n);

        cout << n << " Merge Sort ";
        unsigned t0 = clock();
        mergeSort(cArreglo, 0, n - 1);
        unsigned t1 = clock();
        double time = (double(t1-t0)/CLOCKS_PER_SEC);
        cout << time << endl;

        cout << n << " Quick Sort ";
        t0 = clock();
        sort(arreglo_v.begin(), arreglo_v.end());            
        t1 = clock();
        time = (double(t1-t0)/CLOCKS_PER_SEC);
        cout << time  << endl;
    }
}