#include <iostream>
#include <cmath>
#include "headfile.h"
using namespace std;

Equilatero::Equilatero(float lado){
    
    Lado = lado;
}

void Equilatero::EquiPeri(){
    
    float per;

    per = Lado * 3;

    cout <<"El valor del perimetro es: "<<per<< endl;
}

void Equilatero::EquiArea(){
    
    float h, area;

    h = sqrt(3) * Lado/2;
    area = Lado * h / 2;

    cout <<"El valor del area es: "<<area<< endl;
}