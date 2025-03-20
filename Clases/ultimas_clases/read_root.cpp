#include <iostream>
#include <TCanvas.h>
#include <TH1F.h>
#include <TF1.h>
#include <TH2F.h>
#include <cctype>
#include <fstream>
#include <TFile.h>
#include <cmath>

using namespace std;

//Segunda derivada de f en x con diferencias finitas a paso h
//Detectamos puntos de inflexión, cuando cambia de signo
double finiteDifferenceSecondDerivative(TF1 *f, double x, double h) {
    return (f->Eval(x + h) - 2 * f->Eval(x) + f->Eval(x - h)) / (h * h);
    }

//Combinamos dos sigmoides. Se usa para ajustar datos en el histograma
double doble_sigmoide(double *x, double *par) {
    return par[0] / (1 + exp(-par[1] * (x[0] - par[2]))) + par[3] - par[4] / (1 + exp(-par[5] * (x[0] - par[6])))+ par[7] ;
}

int read_root(){

    TCanvas *cv = new TCanvas("cv", "Mi Canvas", 0, 0, 720, 1080);
    TFile *f = new TFile("EffHY.root", "READ");

    // File con los resultados de la variable diferencia
    ofstream outFile("diferencias_gauss.txt");
    fstream archivo;

    // Iterar sobre las keys del ROOT file
    TIter next(f->GetListOfKeys());
    TKey *key;

    //Verificamos si el objeto es un hist TH1F. Si no, se salta
    while ((key = (TKey*)next())) {
    TObject *obj = key->ReadObj();
    TH1F *EffHY = dynamic_cast<TH1F*>(obj);

    if (!EffHY) {
    continue; // Skip if not a histogram
    }

    //Extraemos la informacion del archivo
    int bines = EffHY->GetNbinsX();
    double h0= EffHY->GetBinContent(1); //1er bin
    double h1= EffHY->GetBinContent(bines); //ultimo bin
    double primer = EffHY->GetBinCenter(0);
    double ultimo = EffHY->GetBinCenter(bines);
    
    //Arreglo para almacenar puntos de infleccion
    double puntos_inflexion[2] = {0};

    cout << " Histogarama " << key->GetName() << endl;

    //Ajuste Gauss y extraemos val. medio (mean)
    EffHY->Fit("gaus");
    TF1 *gausFit = EffHY->GetFunction("gaus");
    double mean = gausFit->GetParameter(1);

    //Ajuste sigmoide con parámetros iniciales
    TF1 *f2 = new TF1("f2", doble_sigmoide,primer,ultimo,8);
    f2->SetParameters(1,1,primer,h0,1,1,mean,h1);

    EffHY->Draw();
    EffHY->Fit(f2, "R");

    // Metoto de diferencias finitas para encontrar los puntos de inflexion
    double h = 0.1; // paso
    double previousSecondDerivative = finiteDifferenceSecondDerivative(f2, primer, h);

    // Escanear todo el rango de la función para detectar puntos de inflexión
    for (double x = primer + h; x < ultimo - h; x += h) {
    double secondDerivative = finiteDifferenceSecondDerivative(f2, x, h);

    // Detecta cuando la derivada cambia de signo
    if (previousSecondDerivative * secondDerivative < 0) {
    if (puntos_inflexion[0] == 0) {
    puntos_inflexion[0] = x; //primer punto de inflexion
    } else if (puntos_inflexion[0] != 0 && puntos_inflexion[1] == 0) {
    puntos_inflexion[1] = x; // segundo punto de inflexion
    }
    cout << "Punto de inflexion detectatdo en x = " << x << endl;
    }
    previousSecondDerivative = secondDerivative; // Actualizar la segunda derivada anterior
    }

    //Si se encontraron dos puntos de inflexión, calculamos el punto medio
    double mitad = 0;
    if (puntos_inflexion[0] != 0 && puntos_inflexion[1] != 0) {
    mitad = (puntos_inflexion[0] + puntos_inflexion[1]) / 2;
    cout << "Punto medio del detector: " << mitad << endl;
    } else {
    cout << "No hay suficientes puntos de inflexion" << endl;
    }

    //Diferencia con la media gaussiana
    double diferencia = mitad - mean;
    outFile<<diferencia<<endl;
}

  // cerrar el output file
  outFile.close();

  //crear el histograma con los datos diferencia obtenidos para cada histograma del archvio .root
  double diferencia;

  TH1F *hist1 = new TH1F("hist1", "Histograma",100,-10,10);
  archivo.open("diferencias_gauss.txt",ios::in);
    //Diferenciass que teníamos en el archivo
    while(!archivo.eof()){

        archivo>>diferencia;

        hist1->Fill(diferencia);
    }

    TCanvas *canvas = new TCanvas("canvas", "Histograma", 800, 600);
    hist1->Draw();

    return 0;
}