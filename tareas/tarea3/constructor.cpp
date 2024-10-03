#include <iostream>
#include <cmath>
#include "headfile.h"
using namespace std;

Cuadrados::Cuadrados(float lado){
    Lado=lado;
}

float Cuadrados::Perimetro(){
    return 4*Lado;
}

float Cuadrados::Area(){
    return Lado * Lado;
}