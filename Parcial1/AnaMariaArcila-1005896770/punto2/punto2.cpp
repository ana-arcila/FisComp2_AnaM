#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

fstream output, archivo;
string evento;
float Identificacion,estacion,momento_x, momento_y, momento_z,masa,energia_depositada, angulo;

float energia;

int main(){

    output.open("output.txt", ios::out);

    archivo.open("fileclasexx.txt",ios::in);
    cout<<"evento"<<" "<<"Identificacion"<<" "<<"estacion"<<" "<<"momento_x"<<" "<<"momento_y"<<" "<<"momento_z"<<" "<<"masa"<<" "<<"energia_depositada"<<endl;

    while(!archivo.eof()){

        archivo>>evento>>Identificacion>>estacion>>momento_x>>momento_y>> momento_z>>masa>>energia_depositada;
        cout<<evento<<" "<<Identificacion<<" "<<estacion<<" "<<momento_x<<" "<<momento_y<<" "<<momento_z<<" "<<masa<<" "<<energia<<endl;

        energia=sqrt(pow(momento_x,2)+pow(momento_y,2)+pow(momento_z,2)+pow(masa,2));
        angulo=acos(momento_z/sqrt(pow(momento_x,2)+pow(momento_y,2)+pow(momento_z,2)+pow(masa,2)));
        output << energia <<"\t"<<angulo<<"\t"<<energia_depositada<< endl;
    }

    return 0;
}