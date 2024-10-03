#include <iostream>
#include <cmath>
#include "headfile.h"
using namespace std;

int main(){

    float x, per, area;
    string tri;

    cout <<"Ingrese el tipo de triangulo entre isoceles, equilatero y rectangulo:"<< endl;
    cin >> tri;

    if (tri=="rectangulo"){
        float y;

        cout <<"Ingrese el cateto opuesto:"<< endl;
        cin >> x;

        cout <<"Ingrese el cateto adyacente:"<< endl;
        cin >> y;

        Rectangulo rect(x, y);
        rect.RectArea();
        rect.RectPeri();
    }
    else if (tri == "equilatero"){

        cout <<"Ingrese el valor de los lados:"<< endl;
        cin >> x;

        Equilatero equi(x);
        equi.EquiArea();
        equi.EquiPeri();
    }
    else if (tri == "isoceles"){

        float y;

        cout <<"Ingrese el valor de los lados que son iguales"<< endl;
        cin >> x;

        cout <<"Ingrese el valor del lado diferente"<< endl;
        cin >> y;
        
        Isoceles iso(x, y);
        iso.IsoArea();
        iso.IsoPeri();
    }
    return 0;
}