#include <iostream>
#include <cmath>
#include "headfile.h"
using namespace std;

Isoceles::Isoceles(float lados, float diferente){

    Lados=lados;
    Diferente=diferente;
}

void Isoceles::IsoArea(){
    float area, h;

    h = sqrt(pow(Lados, 2) + pow(Diferente/2, 2));
    area = Diferente * h / 2;

    cout <<"El valor del area es: "<<area<<endl;
}

void Isoceles::IsoPeri(){

    float per;

    per = 2*Lados + Diferente;

    cout <<"El valor del perimetro es: "<<per<<endl;
}