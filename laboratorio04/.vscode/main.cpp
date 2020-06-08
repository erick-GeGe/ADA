#include <iostream>
#include <vector>

using namespace std;

void sumamaxima(vector<int>& arreglo, int n,vector<int>& respuesta){
    int e=0;
    int d=-1;
    int i=1;
    int f=-1;
    int suma=0;
    int sumamax=0;

    while(f<n){
        f++;
        suma=suma+arreglo[f];
        if(suma<0){
            suma=0;
            i=f+1;
        }else{
            if(suma>sumamax){
                    sumamax=suma;
                    e=1;
                    d=f;
            }
        }
    }

    respuesta[0]=e;
    respuesta[1]=f;
    respuesta[2]=sumamax;
}


int main(){
    int n=9;
    vector<int> arreglo(n);
    arreglo.reserve(n);

    vector<int> respuesta(3);
    arreglo.reserve(3);

    arreglo[0]=4;
    arreglo[1]=-5;
    arreglo[2]=4;
    arreglo[3]=-3;
    arreglo[4]=4;
    arreglo[5]=4;
    arreglo[6]=-4;
    arreglo[7]=4;
    arreglo[8]=-5;

    sumamaxima(arreglo,n,respuesta);

    cout<<respuesta[0]<<endl;
    cout<<respuesta[1]<<endl;
    cout<<respuesta[2]<<endl;
}