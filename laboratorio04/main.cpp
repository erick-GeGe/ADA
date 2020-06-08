

// Erick Gutierrez Enriquez

#include <iostream>
using namespace std;

int max(int a, int b)
{
    return (a>b)? a : b;
}

int max(int a, int b, int c)
{
    int c_aux = max(a, b);
    return max(c_aux, c);
}

struct Par
{
    int inicio;
    int fin;
};

int seg_sum_max(int A[], int n, int &inicio, int &fin)
{
    int sumaMax = 0;
    int suma = 0;
    int e = 0;
    inicio = 0;
    fin = -1;
    int i = 0;
    while(i < n)
    {
        suma = suma + A[i];
        if(suma < 0 )
        {
            suma = 0;
            e = i + 1;
        }
        else if (suma >= sumaMax)   
        {
            sumaMax = suma;
            inicio = e;
            fin = i;
        }
        i++;
    }
    return sumaMax;
}



int seg_sum_dv(int A[],  int p, int r)
{
    if(p == r)
        return max(0, A[p]);
    int suma;
    int q = (p + r)/2;
    int maxIzq = seg_sum_dv(A,p,q);
    int maxDer = seg_sum_dv(A,q+1,r);
    int max2Izq = suma = A[q];
    for (int i = q - 1; i >= p; i--)
    {
        suma += A[i];
        max2Izq = max(max2Izq, suma);
    }
    int max2Der = suma = A[q+1];
    for (int i = q + 2; i <= r; i++)
    {
        suma += A[i];
        max2Der = max(max2Der, suma);
    }
    int maxCruz = max2Izq + max2Der;
    int max_s =max (maxCruz, maxIzq, maxDer);
    return max_s;
}




int main()
{
    int inicio,fin;
    
    int Rutas,Calles;
    cin >> Rutas;
    Par sumas_maximas[Rutas];
    int sumas_maximas_dv[Rutas];
    
    for (int i = 0; i < Rutas; i++)
    {
        cin >> Calles;
        int A[Calles-1];
        
        for (int i = 0; i < Calles - 1; i++)
            cin >> A[i];

        seg_sum_max(A,Calles-1,inicio,fin);
        sumas_maximas[i].inicio = inicio;
        sumas_maximas[i].fin = fin;
        sumas_maximas_dv[i] = seg_sum_dv(A,0,Calles-2);
    }
    
    cout << "\n\n...::Suma maxima con Algoritmo lineal::...\n" << endl;
    for (int i = 0; i < Rutas; i++)
        if(sumas_maximas[i].fin == -1)
            cout << "La ruta " << i + 1 << " no tiene calles interesantes" << endl;
        else
            cout << "La mejor parte de la runa " << i + 1 << "es entre las calles " << 
                sumas_maximas[i].inicio + 1 << " y " << sumas_maximas[i].fin + 2 << endl;


    // el pseudicódigo de las diapositivas no tenia variables que indicaran en que 
    // parte del arreglo se encontra el segmento de mayor suma

    cout << "\n\n...::Suma maxima con Algoritmo divide y venceras::...\n" << endl;
    for (int i = 0; i < Rutas; i++)
        if(sumas_maximas_dv[i] == 0)
            cout << "La ruta " << i + 1 << " no tiene calles interesantes" << endl;
        else
            cout << "La ruta " << i + 1 << " tiene un beneficio de " << sumas_maximas_dv[i] << endl;
}