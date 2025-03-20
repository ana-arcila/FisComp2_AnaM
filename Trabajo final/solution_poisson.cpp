#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>

using namespace std;

const int NX = 32;          // Número de puntos en la dirección x
const int NY = 32;          // Número de puntos en la dirección y
const double TOL = 1e-7;    // Tolerancia para la convergencia
const double OMEGA = 1.85;   // Parámetro de relajación para SOR

// Función para calcular el residuo de la ecuación de Poisson en cada punto de la malla 
// El residuo es la diferencia entre el lado izquierdo y el lado derecho de la ecuación discretizada
double computeResidual(const vector<vector<double>>& phi, const vector<vector<double>>& S, double h) {
    // S = termino fuente, h = Espaciamiento entre puntos de la malla h=1/(NX-1)
    double residual = 0.0;
    for (int i = 1; i < NX - 1; ++i) {
        for (int j = 1; j < NY - 1; ++j) {
            double dx2 = (phi[i+1][j] - 2 * phi[i][j] + phi[i-1][j]) ; //aproximación de la segunda derivada en x
            double dy2 = (phi[i][j+1] - 2 * phi[i][j] + phi[i][j-1]); // aproximación de la segunda derivada en y
            residual += abs(dx2 + dy2 - h*h*S[i][j]);
        }
    }
    return residual;
}

// Método de Jacobi
// Resuelve la ecuación de Poisson usando el metodo de Jacobi
// metodo iterativo que actualiza todos los puntos de la malla usando los valores de la iteración anterior
int jacobi(vector<vector<double>>& phi, const vector<vector<double>>& S, double h) {
    vector<vector<double>> phi_new = phi;  // Copia de phi llamada phi_new para la nueva iteración
    int iterations = 0;
    double residual;

    do {
        // En cada iteración, se actualiza phi_new usando los valores de phi de la iteración anterior
        // Se itera sobre los puntos interiores hasta que la solución converja
        for (int i = 1; i < NX - 1; ++i) {
            for (int j = 1; j < NY - 1; ++j) {
                phi_new[i][j] = 0.25 * (phi[i+1][j] + phi[i-1][j] + phi[i][j+1] + phi[i][j-1] - h * h * S[i][j]);
            }
        }

        // Calcular el residuo usando computeResidual
        residual = computeResidual(phi_new, S, h);

        // Actualizar phi con los valores de phi_new
        for (int i = 1; i < NX - 1; ++i) {
            for (int j = 1; j < NY - 1; ++j) {
                phi[i][j] = phi_new[i][j];
            }
        }

        iterations++;
    } while (residual > TOL); //el proceso se repite hasta que el residuo sea menor que la tolerancia

    return iterations; //se retorna el numero de iteraciones necesarias para converger
}

// Método de Gauss-Seidel
// Resuelve la ecuación de Poisson usando el metodo de Gauss-Seidel
// En el metodo Gauss-Seidel se usa los valores ya actualizados en la misma iteración, es decir, que en vez
// de usar una segunda matriz, sobreescribe directamente phi[i][j] con el nuevo valor
int gaussSeidel(vector<vector<double>>& phi, const vector<vector<double>>& S, double h) {
    int iterations = 0;
    double residual;

    do {
        // Actualizar phi usando Gauss-Seidel
        // Se itera sobre los puntos interiores hasta que la solución converja
        for (int i = 1; i < NX - 1; ++i) {
            for (int j = 1; j < NY - 1; ++j) {
                phi[i][j] = 0.25 * (phi[i+1][j] + phi[i-1][j] + phi[i][j+1] + phi[i][j-1] - h * h * S[i][j]);
            }
        }

        // Calcular el residuo usando computeResidual
        residual = computeResidual(phi, S, h);

        iterations++;
    } while (residual > TOL); //el proceso se repite hasta que el residuo sea menor que la tolerancia

    return iterations;
}

// Método SOR (Successive over Relaxation)
// Resuelve la ecuación de Poisson usando el metodo SOR
// En el metodo SOR se introduce un parametro de relajacion w (OMEGA) para celerar la convergencia
int sor(vector<vector<double>>& phi, const vector<vector<double>>& S, double h) {
    int iterations = 0;
    double residual;

    do {
        // Actualizar phi usando SOR
        // Se itera sobre los puntos interiores hasta que la solución converja
        for (int i = 1; i < NX - 1; ++i) {
            for (int j = 1; j < NY - 1; ++j) {
                double phi_old = phi[i][j];
                phi[i][j] = (1 - OMEGA) * phi[i][j] + OMEGA * 0.25 * (phi[i+1][j] + phi[i-1][j] + phi[i][j+1] + phi[i][j-1] - h * h * S[i][j]);
            }
        }

        // Calcular el residuo usando computeResidual
        residual = computeResidual(phi, S, h);

        iterations++;
    } while (residual > TOL);

    return iterations;
}

// Función para escribir la solución en un archivo (Guarda la solución en un archivo de texto)
// Cada fila del archivo corresponde a una fila de la malla
void writeSolutionToFile(const vector<vector<double>>& phi, const string& filename) {
    ofstream file(filename);
    for (int i = 0; i < NX; ++i) {
        for (int j = 0; j < NY; ++j) {
            file << phi[i][j] << " "; //los valores de phi se escriben separados por espacios
        }
        file << endl;
    }
    file.close();
}

int main() {
    double h = 1.0 / (NX - 1);  // Espaciado de la malla

    // Inicialización de las matrices:

    // Inicialización de la matriz phi (solucion de la ecuación de Poisson en cada punto de la malla)
    // Inicialmente todas las entradas de la matriz son 0, pero luego se actualizan durante las iteraciones de los metodos numericos
    vector<vector<double>> phi(NX, vector<double>(NY, 0.0)); 

    //Inicialización de la matriz S (Término fuente)
    vector<vector<double>> S(NX, vector<double>(NY, 0.0)); 

    // Matriz del término fuente S
    double S_value = 2.0; 
    for (int i = 0; i < NX; ++i) {
        for (int j = 0; j < NY; ++j) {
            S[i][j] = S_value;
        }
    }

    // Aplicar condiciones de frontera usando la solucion exacta solo en los bordes
    for (int i = 0; i < NX; ++i) {
        for (int j = 0; j < NY; ++j) {
            //verificar que los puntos esten en el borde
            if (i == 0 || i == NX - 1 || j == 0 || j == NY - 1) {
                // coordenadas x e y
                double x = i * h;
                double y = j * h;
                phi[i][j] = exp(-M_PI * x) * sin(-M_PI * y) + (S_value / 4.0) * (x * x + y * y);
            }
        }
    }

    // Resolver usando Jacobi
    vector<vector<double>> phi_jacobi = phi;
    int iter_jacobi = jacobi(phi_jacobi, S, h);
    cout << "Iteraciones Jacobi : " << iter_jacobi << endl;
    writeSolutionToFile(phi_jacobi, "jacobi_solution.txt");

    // Resolver usando Gauss-Seidel
    vector<vector<double>> phi_gs = phi;
    int iter_gs = gaussSeidel(phi_gs, S, h);
    cout << "Iteraciones Gauss-Seidel: " << iter_gs << endl;
    writeSolutionToFile(phi_gs, "gauss_seidel_solution.txt");

    // Resolver usando SOR
    vector<vector<double>> phi_sor = phi;
    int iter_sor = sor(phi_sor, S, h);
    cout << "Iteraciones SOR: " << iter_sor << endl;
    writeSolutionToFile(phi_sor, "sor_solution.txt");

    return 0;
}