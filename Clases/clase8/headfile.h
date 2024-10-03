#include <iostream>
#include <cmath>
using namespace std;

class Rectangulo{
    private:
        float C_op;
        float C_ady;

    public:
        Rectangulo(float, float);
        void RectArea();
        void RectPeri();
};

class Equilatero{
    private:
        float Lado;

    public:
        Equilatero(float);
        void EquiArea();
        void EquiPeri();
};

class Isoceles{
    private:
        float Lados;
        float Diferente;

    public:
        Isoceles(float, float);
        void IsoArea();
        void IsoPeri();
};