//Clase Septiembre 10, 2024

#include <iostream>
#include <cmath> //Funciones matematicas
using namespace std;
#define M_PI 3.14159265358979323846

/*

//Para el if, podemos tener dos condiciones separadas por or de la manera: if(cond1||cond2)

//Operaciones números

int main(){

    float a, b, c;

    cout <<"Igrese el primer numero:"<< endl;
    cin >> a;

    cout <<"Ingrese el segundo numero:"<< endl;
    cin >> b;

    c = a/b;

    cout <<"El resultado es: \n"<<c<< endl;

    return 0;
}
*/


/*
//Condicionales

int main(){

    //Para comparar strings es con == 

    int n;

    cout <<"Ingrese un numero entero:"<< endl;
    cin >> n;

    if (n<0){
        cout <<"El numero es negativo."<< endl;
    }
    else if (n==0){
        cout <<"El numero es 0."<< endl;
    }
    else{
        cout <<"El numero es positivo."<< endl;
    };

    return 0;

}

*/

//Funciones

//abs(x), pow(x, y) = x**y. sqrt(x), sin(x), cos(x), tan(x)
//log(x)=log10(x), logn(x),  exp(x)
/*
int main(){

    float x, y, h;

    cout <<"Ingrese x:"<< endl;
    cin >> x;

    cout <<"Ingrese y:"<< endl;
    cin >> y;

    if (x>0 && y>0){
        h = sqrt(pow(x,2) + pow(y,2));
        cout <<"La hipotenusa es "<<h<<endl;
    }
    else{
        cout <<"Ingrese catetos validos."<<endl;
    }

    return 0;

}
*/

/*
//Seleccion triangulos

int main(){
    float x, per, area;
    string tri;

    cout <<"Ingrese el tipo de triangulo entre isoceles, equilatero y rectangulo" <<endl;
    cin >> tri;

    if (tri == "rectangulo"){

        float y, z;

        cout <<"Ingrese el cateto opuesto:"<< endl;
        cin >> x;

        cout <<"Ingrese el cateto adyacente:"<< endl;
        cin >> y;

        if (x>0 && y>0){
            z = sqrt(pow(x,2) + pow(y,2));

            per = x + y + z;

            area = x*y/2;

            cout <<"El area es "<<area<<" y el perimetro es "<<per<< endl;
        }
        else {
            cout<<"Ingrese lados validos"<< endl;
        }
        

    }
    else if (tri == "equilatero"){

        float h;

        cout <<"Ingrese el valor de los lados:"<< endl;
        cin >> x;

        h = sqrt(3) * x/2;

        per = x * 3;

        area = x * h / 2;

        cout <<"El area es "<<area<<" y el perimetro es "<<per<< endl;
    }
    else if (tri == "isoceles"){

        float y, h;

        cout <<"Ingrese el valor de los lados que son iguales"<< endl;
        cin >> x;

        cout <<"Ingrese el valor del lado diferente"<< endl;
        cin >> y;

        h = sqrt(pow(x, 2) + pow(y/2, 2));

        per = 2*x + y;

        area = y * h / 2;

        cout <<"El area es "<<area<<" y el perimetro es "<<per<< endl;
    }
    else{
        cout <<"El valor ingresado no es valido"<< endl;
    }

    return 0;
}
*/

//escaleno

int main(){

    int a, b, c;
    float area, theta, y, x;

    a=4;
    b=11;
    c=10;

    
    theta = acos((pow(b,2) + pow(c,2) - pow(a,2))/(2*b*c));

    y = c * sin(theta);

    x = c * cos(theta);

    area = x * y / 2;

    cout <<area<< endl;

}
