#include <iostream>
#include <cmath>
using namespace std;

float v(float);

int main(){
    float i, integ, dt, m, altura;

    integ = 0;
    dt = 0.1;
    m=0;

    for (i=0; i<=10; i+=dt){
        altura = v(m);
        integ += dt*altura;
        m+=dt;
    }

    cout <<"El desplazamiento del cuerpo en 10 segundos es: "<<integ<< endl;

    return 0;
}

float v(float t){
    return pow(t-5, 2);
}