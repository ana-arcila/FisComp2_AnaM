#include <iostream>
#include <fstream>
#include <cmath>
#include <TCanvas.h>
#include <TH1F.h>
#include <TFile.h>
#include <TKey.h>


using namespace std;

int leer_3(){

TCanvas *cv = new TCanvas("cv", "Tarea",0,0,720,1080); //Creamos el canvas
TFile *f = new TFile("first_file.root", "READ");

//TH1F *hist;
//TH1F *hist;f->GetObject("Energia_total",hist);

//f->ls();

Energia_total->Draw();

int bines = Energia_total->GetNbinsX();
cout<<"Los bines son"<<bines<<endl;

return 0;
}