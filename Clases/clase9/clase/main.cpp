#include <iostream>
#include <cmath>
#include "headfile.h"
using namespace std;

int main(){
    float x, y, z, m;
    string str;
    cout <<"Ingrese si desea hacer una suma real o imaginaria: "<< endl;
    cin >> str;
    
    Operaciones opp(x, y, z, m);
    if (str == "real"){
        cout <<"Ingrese el primer valor:"<< endl;
        cin >> x;
        cout <<"Ingrese el segundo valor:"<< endl;
        cin >> y;

        
        opp.Suma(x, y);
    }
    else if(str == "imaginaria"){
        cout <<"Ingrese la parte real del primer valor:"<< endl;
        cin >> x;
        cout <<"Ingrese la parte imaginaria del primer valor:"<< endl;
        cin >> y;
        cout <<"Ingrese la parte real del segundo valor:"<< endl;
        cin >> z;
        cout <<"Ingrese la parte imeginaria del segundo valor:"<< endl;
        cin >> m;

        opp.Suma(x, y, z, m);

    }
    else{
        cout <<"Argumento no válido."<< endl;
    }

    return 0;
}