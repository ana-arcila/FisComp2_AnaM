#include <iostream>
#include <cmath>
using namespace std;

long double factorial(float);

int main(){
    int i, n;
    float m, ang;
    long double sin;

    cout <<"Ingrese el angulo en radianes:"<< endl;
    cin >> ang;

    cout <<"Ingrese el numero de pasos (Warning: no escoja mayor a 16):"<< endl;
    cin >> i;

    n=0;
    sin=0;

    while(n<=i){
        m = pow(-1, n)/factorial(2*n+1) * pow(ang, 2*n+1);
        sin += m;
        n++;
    }

    cout <<"El seno es:\n"<<sin<< endl;

    return 0;
}

long double factorial(float n){

    int i, f;

    f=1;

    for (i=1; i<=n; i++){
        f*=i;
    }

    return f;
}