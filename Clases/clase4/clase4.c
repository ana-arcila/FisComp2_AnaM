//Clase 17 de Septiembre

#include <iostream>
#include <cmath>
using namespace std;

//Funciones
//Son subprogramas fuera del main

/*
int funcion1(int);

int main(){
    int vol, fac;
    cout <<"Ingrese el numero:"<< endl;
    cin >> fac;
    
    vol=funcion1(fac);

    cout <<"\n"<<"El factorial es: "<<vol<< endl;

    return 0;
}

int funcion1(int a){
    int i, x;

    x=1;
    for (i=1; i<=a; i++){
        x*=i;
    }

    return x;
}
*/

//Triangulos

/*
float per_rect(float x, float y);
float area_rect(float x, float y);
float per_equi(float x);
float area_equi(float x);
float area_iso(float x, float y);
float per_iso(float x, float y);

int main(){
    float x, per, area;
    string tri;

    cout <<"Ingrese el tipo de triangulo entre isoceles, equilatero y rectangulo:"<< endl;
    cin >> tri;

    if (tri == "rectangulo"){
        float y;

        cout <<"Ingrese el cateto opuesto:"<< endl;
        cin >> x;

        cout <<"Ingrese el cateto adyacente:"<< endl;
        cin >> y;

        per = per_rect(x, y);
        area = area_rect(x, y);

        cout <<"Perimetro= "<<per<<"\nArea= "<<area<< endl;
        
    }

    else if (tri == "equilatero"){

        cout <<"Ingrese el valor de los lados:"<< endl;
        cin >> x;

        per = per_equi(x);
        area = area_equi(x);

        cout <<"Perimetro= "<<per<<"\nArea= "<<area<< endl;
    }
    else if (tri == "isoceles"){

        float y, h;

        cout <<"Ingrese el valor de los lados que son iguales"<< endl;
        cin >> x;

        cout <<"Ingrese el valor del lado diferente"<< endl;
        cin >> y;

        area = area_iso(x, y);
        per = per_iso(x, y);

        cout <<"Perimetro= "<<per<<"\nArea= "<<area<< endl;
    }
    else{
        cout <<"El valor ingresado no es valido"<< endl;
    }

    return 0;
}

float per_rect(float x, float y){

    float z, per;

    z = sqrt(pow(x,2) + pow(y,2));

    per = x + y + z;
    
    return per;
}

float area_rect(float x, float y){

    float area;

    area = x*y/2;

    return area;
}

float per_equi(float x){
    float per;

    per = x * 3;

    return per;
}

float area_equi(float x){
    float h, area;

    h = sqrt(3) * x/2;
    area = x * h / 2;

    return area;
}

float per_iso(float x, float y){
    float per;

    per = 2*x + y;

    return per;
}

float area_iso(float x, float y){
    float area, h;

    h = sqrt(pow(x, 2) + pow(y/2, 2));
    area = y * h / 2;

    return area;
}
*/

//Bool

bool primos(int i, int lim);

int main(){

    int i, lim;

    cout <<"Ingrese el numero limite:"<< endl;
    cin >> lim;

    for (i=1; i<=lim; i++){
        if (primos(i, lim)){
            cout <<i<< endl;
        }
    }

    return 0;
}

bool primos(int i, int lim){
    int n, m, j;

    n=0;

    for (j=1; j<= i; j++){
        m = i%j;
        n+=m;
    }
    

    if (n=!0){
        return true;
    }
    else{
        return false;
    }
}