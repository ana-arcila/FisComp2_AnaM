#include <iostream>
#include <fstream>
#include "TGraph2D.h"
#include "TH2F.h"
#include "TCanvas.h"
#include "TStyle.h"

using namespace std;

void plotPoisson() {
    // Se abre el archivo con la solución de Poisson
    ifstream file("sor_solution.txt"); // Cambiar por el método deseado
    if (!file) {
        cout << "Error: No se pudo abrir el archivo." << endl;
        return;
    }

    const int NX = 32; //Tamaño de la malla, número de puntos en la dirección x
    const int NY = 32; //Tamaño de la malla, número de puntos en la dirección y
    double h = 1.0 / (NX - 1); // espacio entre los puntos de la malla
    double x, y, phi;
    int index = 0;

    TH2F *hist = new TH2F("phi", "Mapa de calor Poisson;X;Y;Phi", NX, 0, 1, NY, 0, 1); //Histograma 2D = Mapa de calor
    TGraph2D *graph = new TGraph2D(); //superficie 3D de la funcion phi

    //lectura de los datos
    for (int i = 0; i < NX; ++i) {
        for (int j = 0; j < NY; ++j) {
            //lectura de phi desde el archivo
            file >> phi;

            // Calculo de las coordenadas de la malla
            x = i * h;
            y = j * h;

            // Se llena el histograma TH2F con el valor de la funcion phi
            hist->SetBinContent(i + 1, j + 1, phi);

            // Se añade un punto al grafico graph (index:indice del punto)
            graph->SetPoint(index++, x, y, phi);
        }
    }

    file.close();

// Crear un canvas con dos pads
TCanvas *c1 = new TCanvas("c1", "Solución de Poisson: Método SOR", 800, 1000);
c1->Divide(1, 2); // Divide el canvas en 1 columna y 2 filas

// ---- Superficie 3D ----
c1->cd(1);  // Selecciona la parte superior
graph->SetTitle("Solucion de Poisson: Metodo SOR; X; Y; Phi");
graph->Draw("surf");

// ---- Mapa de calor ----
c1->cd(2);  // Selecciona la parte inferior
hist->Draw("COLZ");

// Actualizar y guardar la imagen
c1->Update();
c1->SaveAs("Poisson_SOR.png");

}