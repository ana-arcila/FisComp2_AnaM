#include <iostream>
#include <cmath>
using namespace std;

class Triangulos{
    private:
        float C_op;
        float C_ady;

    public:
        Triangulos(float, float);
        void Area();
        void Per();
};

Triangulos::Triangulos(float c_op, float c_ady){
    C_op = c_op;
    C_ady = c_ady;
}

void Triangulos::Per(){

    float z, per;

    z = sqrt(pow(C_op,2) + pow(C_ady,2));

    per = C_op + C_ady + z;

    cout <<"El valor del perimetro es: "<<per<<endl;
}

void Triangulos::Area(){

    float area;

    area = C_op*C_ady/2;

    cout <<"El valor del area es: "<<area<<endl;
}

int main(){
    int x, y;
    
    cout <<"Ingrese el cateto opuesto:"<< endl;
    cin >> x;
    cout <<"Ingrese el cateto adyacente:"<< endl;
    cin >> y;

    Triangulos rect(x, y);
    rect.Per();
    rect.Area();
    return 0;
}