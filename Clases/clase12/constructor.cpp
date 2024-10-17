#include <iostream>
#include <cmath>
#include "headfile.h"
using namespace std;

Triangulo::Triangulo(float Base, float Altura){
    Base = base;
    Altura = altura;
}

void Triangulo::Area(float){
    float h, area;

    h = sqrt(3) * Lado/2;
    area = Lado * h / 2;

    cout <<"El valor del area es: "<<area<< endl;
}

