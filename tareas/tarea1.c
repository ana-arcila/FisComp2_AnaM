#include <iostream>
#include <cmath>
using namespace std;

int main (){

    int r1, r2, r3;
    r1=4, r2=5, r3=6;

    float A, B, C, a, b, c; //angulos y lados

    a=r2+r3, b=r1+r3, c=r1+r2;

    A = acos((pow(b,2) + pow(c,2) - pow(a,2))/(2*b*c));
    B = acos((pow(a,2) + pow(c,2) - pow(b,2))/(2*a*c));
    C = acos((pow(b,2) + pow(a,2) - pow(c,2))/(2*b*a));

    float AA, AB, AC; //areas de cada semicirculo

    AA = A/2 * pow(r1,2);
    AB = B/2 * pow(r2,2);
    AC = C/2 * pow(r3,2);

    float h; //para el area del triangulo

    h = sin(B)*a;

    float area_triangulo, area_final;

    area_triangulo = h*c/2;

    area_final = area_triangulo - AA - AB - AC;

    cout <<"El área de la figura es de "<<area_final<< endl;

    return 0;
}
