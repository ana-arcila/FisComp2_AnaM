#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

int main(){
    fstream archivo;

    string evento;
    float Identificacion,estacion,momento_x, momento_y, momento_z,masa,energia_depositada;

    float energia;

    archivo.open("fileclasexx.txt", ios::in);

    float min, max;

    max=0;
    min=100000;
    float range=5000;
    int frecuencias[24];
    int counter;

    while(!archivo.eof()){

        archivo>>evento>>Identificacion>>estacion>>momento_x>>momento_y>> momento_z>>masa>>energia_depositada;

        energia=sqrt(pow(momento_x,2)+pow(momento_y,2)+pow(momento_z,2)+pow(masa,2));

        if (max < energia){
            max=energia;
        }
        if (min > energia){
            min=energia;
        }

        counter = energia/range;


        frecuencias[floor(counter)] += 1;
    }

    
    for (int i=0; i<24; i++){
        cout<<frecuencias[i]<<endl;
    }
    

    return 0;
}