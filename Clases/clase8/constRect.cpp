#include <iostream>
#include <cmath>
#include "headfile.h"
using namespace std;

Rectangulo::Rectangulo(float c_op, float c_ady){
    C_op = c_op;
    C_ady = c_ady;
}

void Rectangulo::RectPeri(){

    float z, per;

    z = sqrt(pow(C_op,2) + pow(C_ady,2));

    per = C_op + C_ady + z;

    cout <<"El valor del perimetro es: "<<per<<endl;
}

void Rectangulo::RectArea(){

    float area;

    area = C_op*C_ady/2;

    cout <<"El valor del area es: "<<area<<endl;
}