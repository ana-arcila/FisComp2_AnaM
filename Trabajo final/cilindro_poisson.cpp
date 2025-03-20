// Solución de la ecuación de Poisson para el potencial eléctrico en presencia de un cilindro cargado
#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>

using namespace std;

const int NX = 128;          // Número de puntos en la dirección x
const int NY = 128;          // Número de puntos en la dirección y
const double TOL = 1e-7;     // Tolerancia para la convergencia
const double OMEGA = 1.85;   // Parámetro de relajación para SOR
const double a = 0.1;        // Radio del cilindro
const double rho_0= 1.0;     // Densidad de carga dentro del cilindro

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

// Función para calcular la solución exacta
double exactSolution(double x, double y) {
    double r = sqrt(x * x + y * y);
    if (r >= 0 and r <= a) {
        return -0.25*rho_0* r * r ;
    } else {
        return -0.5*rho_0* a * a  * (log(r / a) + 0.5);
    }
}

int main() {
    double h = 2.0 / (NX - 1);  // Espaciado de la malla (dominio de -1 a 1) // Nuevo: Espaciado ajustado para el dominio [-1, 1]

    // Inicialización de las matrices:

    // Inicialización de la matriz phi (solucion de la ecuación de Poisson en cada punto de la malla)
    // Inicialmente todas las entradas de la matriz son 0, pero luego se actualizan durante las iteraciones de los metodos numericos
    vector<vector<double>> phi(NX, vector<double>(NY, 0.0));

    //Inicialización de la matriz S (Término fuente)
    vector<vector<double>> S(NX, vector<double>(NY, 0.0));

    // Inicialización del término fuente S según la distribución de carga
    for (int i = 0; i < NX; ++i) {
        for (int j = 0; j < NY; ++j) {
            double x = -1.0 + i * h; // Coordenada x en el dominio [-1, 1]
            double y = -1.0 + j * h; // Coordenada y en el dominio [-1, 1]
            double r = sqrt(x * x + y * y); // Distancia radial desde el origen
            if (0 <= r && r <= a) {
                S[i][j] = -rho_0; // Término fuente dentro del cilindro
            }  else {
                S[i][j] = 0.0; // Término fuente fuera del cilindro
            }
    }
}

    // Aplicar condiciones de frontera usando la solucion exacta
    for (int i = 0; i < NX; ++i) {
        for (int j = 0; j < NY; ++j) {
            //verificar que los puntos esten en el borde
            if (i == 0 || i == NX - 1 || j == 0 || j == NY - 1) {
                // coordenadas x e y
                double x = -1.0 + i * h; //  Coordenada x en el dominio [-1, 1]
                double y = -1.0 + j * h; //  Coordenada y en el dominio [-1, 1]
                phi[i][j] = exactSolution(x, y); // Nuevo: Usar la solución exacta en los bordes
            }
        }
    }

    // Resolver usando Jacobi
    vector<vector<double>> phi_jacobi = phi;
    int iter_jacobi = jacobi(phi_jacobi, S, h);
    cout << "Iteraciones Jacobi : " << iter_jacobi << endl;
    writeSolutionToFile(phi_jacobi, "potencial_jacobi_solution.txt");

    // Resolver usando Gauss-Seidel
    vector<vector<double>> phi_gs = phi;
    int iter_gs = gaussSeidel(phi_gs, S, h);
    cout << "Iteraciones Gauss-Seidel: " << iter_gs << endl;
    writeSolutionToFile(phi_gs, "potencial_gauss_seidel_solution.txt");

    // Resolver usando SOR
    vector<vector<double>> phi_sor = phi;
    int iter_sor = sor(phi_sor, S, h);
    cout << "Iteraciones SOR: " << iter_sor << endl;
    writeSolutionToFile(phi_sor, "potencial_sor_solution.txt");

    return 0;
}