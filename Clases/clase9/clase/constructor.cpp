#include <iostream>
#include <cmath>
#include "headfile.h"

using namespace std;

Operaciones::Operaciones(float t1, float t2, float t3, float t4){
    T1=t1;
    T2=t2;
    T3=t3;
    T4=t4;
}

void Operaciones::Suma(float, float, float, float){
    float real, imag;
    real = T1 + T3;
    imag = T2 + T4;
    cout <<"El resultado es: "<<real<<" + i"<<imag<< endl;
}


void Operaciones::Suma(float, float){
    float N;
    N=T1+T2;
    cout <<"El resultado es: "<<N<< endl;
}