#include <iostream>
#include <fstream>
#include "TGraph2D.h"
#include "TH2F.h"
#include "TCanvas.h"
#include "TStyle.h"

using namespace std;

void plotPoisson_potencial() {
    // Se abre el archivo con la solución de Poisson
    ifstream file("potencial_sor_solution.txt");
    if (!file) {
        cout << "Error: No se pudo abrir el archivo "  << endl;
        return;
    }

    const int NX = 128; // Tamaño de la malla en X
    const int NY = 128; // Tamaño de la malla en Y
    double h = 2.0 / (NX - 1); // Espaciado en [-1,1]
    double x, y, phi;
    int index = 0;

    // Ajustar el rango del histograma a [-1,1] en X e Y
    TH2F *hist = new TH2F("phi", "Mapa de calor Potencial electrico;X;Y;Phi", NX, -1, 1, NY, -1, 1);
    TGraph2D *graph = new TGraph2D(); 

    // Lectura de los datos
    for (int i = 0; i < NX; ++i) {
        for (int j = 0; j < NY; ++j) {
            file >> phi;

            // Calculo de las coordenadas de la malla
            x = -1.0 + i * h;
            y = -1.0 + j * h;

            // Se llena el histograma TH2F
            hist->SetBinContent(i + 1, j + 1, phi);

            // Se añade un punto al gráfico 3D
            graph->SetPoint(index++, x, y, phi);
        }
    }

    file.close();

    // Crear un canvas con dos pads
    TCanvas *c1 = new TCanvas("c1", "Potencial Electrico: Método SOR", 1000, 1000);
    c1->Divide(1, 2);

    // ---- Superficie 3D ----
    c1->cd(1);
    graph->SetTitle("Potencial Electrico: Metodo SOR; X; Y; Phi");
    graph->Draw("surf");

    // ---- Mapa de calor ----
    c1->cd(2);
    hist->SetStats(0); 
    hist->Draw("COLZ");

    // Guardar la imagen
    c1->Update();
    c1->SaveAs("Poisson_sor_potencial.png");
}
