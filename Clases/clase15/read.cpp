#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>

using namespace std;


int read() {

    int freq[24] = {0};  // Inicializar el array freq a 0
    int bin;

    ifstream archivoEntrada;
    ifstream archivoEntrada1;
    ifstream archivoEntrada2;
    ofstream archivoFrecuencias;
    float key, Identificación, estación, momentox, momentoy, momentoz, masa, energíaDepositada, totalEnergy;

    // Abre el archivo de entrada en modo de lectura
    archivoEntrada1.open("fileclasexx.txt", ios::in);

    float maxEnergy, minEnergy;
    maxEnergy=0;

    while (archivoEntrada1 >> key >> Identificación >> estación >> momentox >> momentoy >> momentoz >> masa >> energíaDepositada) {
        
        totalEnergy = sqrt(pow(momentox, 2) + pow(momentoy, 2) + pow(momentoz, 2) + pow(masa, 2));

        if (maxEnergy < totalEnergy){
            maxEnergy = totalEnergy;
        }

    }

    archivoEntrada2.open("fileclasexx.txt", ios::in);
    minEnergy = 200000;

    while (archivoEntrada2 >> key >> Identificación >> estación >> momentox >> momentoy >> momentoz >> masa >> energíaDepositada) {
        
        totalEnergy = sqrt(pow(momentox, 2) + pow(momentoy, 2) + pow(momentoz, 2) + pow(masa, 2));

        if (minEnergy > totalEnergy){
            minEnergy = totalEnergy;
        }

    }
    
    archivoEntrada.open("fileclasexx.txt", ios::in);
    // Lee cada línea del archivo de entrada y procesa los datos
    while (archivoEntrada >> key >> Identificación >> estación >> momentox >> momentoy >> momentoz >> masa >> energíaDepositada) {
        // Calcula la energía total
        totalEnergy = sqrt(pow(momentox, 2) + pow(momentoy, 2) + pow(momentoz, 2) + pow(masa, 2));

        // Calcula el bin correspondiente
        bin = floor(totalEnergy / (maxEnergy-minEnergy));
        if (bin >= 0 && bin < 24) {
            freq[bin] += 1;  // Incrementa la frecuencia en el bin correspondiente
        }

    }

    
    // Cierra los archivos
    archivoEntrada.close();
    archivoEntrada1.close();
    archivoEntrada2.close();
    cout <<minEnergy<< endl;
    TCanvas *cv = new TCanvas("cv", "myCanvas", 0, 0, 720, 1080);
    cv -> Divide(1, 2);
    
    TH1F *hist1 = new TH1F("hist1", "firstHist", 24, minEnergy, maxEnergy); //nombre1, nombre2, bins, inicio rango, final rango

    for (int i=0; i<24; i++){
        hist1 -> Fill(hist1->GetBinCenter(i),freq[i]);
        cout << freq[i] << endl;
    }

    cv -> cd(1);
    hist1 -> Draw();

    return 0;
}

