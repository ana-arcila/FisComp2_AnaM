#include <iostream>
#include <cmath>
using namespace std;


//Ejemplo 
/*
void Ejemplo();

const float gravedad = 9.8;

int main(){

    cout <<"Primer llamado de la funcion ejemplo"<< endl;
    Ejemplo();
    cout <<"Segundo llamado de la funcion ejemplo"<< endl;
    Ejemplo();
    cout <<"Tercer llamado de la funcion ejemplo"<< endl;
    Ejemplo();

    return 0;
}

void Ejemplo(){

    static int var1 = 10; //Se corre una vez y no se vuelve a correr
    int var2=10; //Se va a correr cada vez que se llame la funcion
    float aceleracion = gravedad; //No se va a poder cambiar ya que gravedad es una variable global. 
                                  //Ninguna declaración dentro de la funcion lo va a sobreescribit

    ++var1;
    ++var2;

    cout <<"El valor static es: "<<var1<< endl;
    cout <<"El valor int es: "<<var2<< endl;
    cout <<"El valor constant es: "<<aceleracion<< endl;

}
*/

//Misma funcion

void suma(float, float);
void suma(float, float, float, float);

int main(){
    float x, y;
    string str;
    cout <<"Ingrese si desea hacer una suma real o imaginaria: "<< endl;
    cin >> str;
    
    if (str == "real"){
        cout <<"Ingrese el primer valor:"<< endl;
        cin >> x;
        cout <<"Ingrese el segundo valor:"<< endl;
        cin >> y;

        suma(x, y);
    }
    else if(str == "imaginaria"){
        float z, m;
        cout <<"Ingrese la parte real del primer valor:"<< endl;
        cin >> x;
        cout <<"Ingrese la parte imaginaria del primer valor:"<< endl;
        cin >> y;
        cout <<"Ingrese la parte real del segundo valor:"<< endl;
        cin >> z;
        cout <<"Ingrese la parte imeginaria del segundo valor:"<< endl;
        cin >> m;

        suma(x, y, z, m);

    }
    else{
        cout <<"Argumento no válido."<< endl;
    }

    return 0;
}

void suma(float a, float b){
    float resultado;
    resultado = a+b;
    cout <<"La suma de los numeros reales es: "<<resultado<< endl;
}

void suma(float a, float b, float c, float d){
    float real, imag;
    real = a + c;
    imag = b + d;
    cout <<"La suma de los numeros imaginarios es: "<<real<<" + i"<<imag<< endl;
}