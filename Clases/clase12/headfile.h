#include <iostream>
#include <cmath>

using namespace std;

class Triangulo{
    private:
        float base;
        float altura;

    public:
        Triangulo(float, float);
        void Area(float, float);
        void Perimetro(float, float);
        void Area(float);
        void Perimetro(float);
};