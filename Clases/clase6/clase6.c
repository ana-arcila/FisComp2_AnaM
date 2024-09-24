//Clase 24 de Septiembre

#include <iostream>
#include <cmath>
using namespace std;

//do-while
//El proceso siempre se va a hacer. Si se cumple la condicion se repite.
//A diferencia del while normal que verifica la condición primero.

/*
int main(){

    string clave;
    int n;

    do{
        cout <<"Ingrese la clave:"<< endl;
        cin >> clave;

        if (clave == "123" || clave == "x"){
            break;
        }

    }while(clave != "123" || clave != "x");

    if (clave == "123"){
        cout <<"Aceptado"<< endl;
    }
    else if( clave == "x"){
        cout <<"Cerrando"<< endl;
    }

    return 0;
}
*/

//Conversion

/*
int main(){

    int n=1;

    do{

        cout <<n<<" gal -----> "<<3.785 * n<<" litros"<< endl;
        n++;

    }while(n<=20);

    return 0;
}
*/

//Switch

int main(){

    int n;
    float T;

    do{
        cout <<"Ingrese la conversion que quiera: \n"<<
        "1 = °F a °C \n2 = °K a °C \n3 = °C a °F \n4 = °K a °F \n5 = °C a °K \n6 = °F a °K"<< endl;
        cin >> n;

        if (n>0 && n <= 6){

            cout <<"Ingrese la temperatura a convertir:"<< endl;
            cin >> T;

            switch(n){

                case 1:
                cout <<T<<"°F ----> "<< (T - 32)/1.8<<"°C"<< endl;
                break;
                
                case 2:
                cout <<T<<"°K ----> "<<T - 273.15<<"°C"<< endl;
                break;

                case 3:
                cout <<T<<"°C ----> "<<(9/5 * T) + 32<<"°F"<< endl;
                break;

                case 4:
                cout <<T<<"°K ----> "<<1.8 * (T -273.15) + 32<<"°F"<< endl;
                break;

                case 5:
                cout <<T<<"°C ----> "<<T + 273.15<<"°K"<< endl;
                break;

                case 6:
                cout <<T<<"°F ----> "<< (T - 32)/1.8 + 273.15<<"°K"<< endl;
                break;
            }
        }
    }while(n>0 && n <= 6);

    cout <<"Caso no valido, cerrando programa."<< endl;


    return 0;
}