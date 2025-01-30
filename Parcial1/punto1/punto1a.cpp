#include <iostream>
#include <cmath>
using namespace std;

float v(float);
int main(){

    float i, der;
    float dt = 0.001;

    for (i=0; i<=10; i++){
        der = (v(i+dt)-v(i))/dt;
        cout<<"Velocidad segundo "<<i<<": "<<der<<" m/s²"<<endl;
    }

    return 0;
}


float v(float t){
    return pow(t-5, 2);
}