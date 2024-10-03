#include <iostream>
#include <cmath>
#include "headfile.h"
using namespace std;

int main(){
    int i, N;
    float lado, area_T, peri_T;

   cout <<"Ingrese el numero de cuadrados: "<< endl;
   cin >>  N;

   cout <<"Ingrese la longitud del lado del primer cuadrado:"<< endl;
   cin >> lado;

    area_T=0;
    peri_T=0;

    for (i=1; i<=N; i++){
        Cuadrados cuad(lado);
        area_T += cuad.Area();
        peri_T += cuad.Perimetro();
        lado =lado/sqrt(2);
    }

    cout <<"El area total es: "<<area_T<< endl;
    cout <<"El perimetro total es: "<<peri_T<< endl;

    return 0;
}