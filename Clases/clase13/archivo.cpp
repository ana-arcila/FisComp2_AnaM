#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main(){
fstream archivo;

string evento;
float Identificacion,estacion,momento_x, momento_y, momento_z,masa,energia_depositada;

float energia;


archivo.open("fileclasexx.txt",ios::in);
cout<<"evento"<<" "<<"Identificacion"<<" "<<"estacion"<<" "<<"momento_x"<<" "<<"momento_y"<<" "<<"momento_z"<<" "<<"masa"<<" "<<"energia_depositada"<<endl;

while(!archivo.eof()){

    archivo>>evento>>Identificacion>>estacion>>momento_x>>momento_y>> momento_z>>masa>>energia_depositada;
    cout<<evento<<" "<<Identificacion<<" "<<estacion<<" "<<momento_x<<" "<<momento_y<<" "<<momento_z<<" "<<masa<<" "<<energia<<endl;

    energia=sqrt(pow(momento_x,2)+pow(momento_y,2)+pow(momento_z,2)+pow(masa,2));
    cout<<"energia = "<<energia<<endl;
}

return 0;
}