#include <iostream>
#include <fstream>
#include <cmath>
#include <TCanvas.h>
#include <TH1F.h>
#include <TFile.h>

using namespace std;

int Tarea_1(){

fstream archivo;

string evento;
float Identificacion,estacion,momento_x, momento_y, momento_z,masa,energia_depositada;

float energia;
float energia_acumulada;
float numero_particulas;
float norm;



TCanvas *cv = new TCanvas("cv", "Tarea",0,0,720,1080); //Creamos el canvas
TH1F *hist1 = new TH1F("hist1", "Energia Total; Energia Total (MeV); Fecuencia de eventos",100,275,120000);
TH1F *hist2 = new TH1F("hist2", "Energia depositada; Energia Depositada (MeV);Frecuencia de eventos",100,0,30);
TH1F *hist3 = new TH1F("hist3", "Histograma de peso; Energia Total (MeV); Energia Depositada (MeV)",100,275,120000);
TH1F *hist4 = new TH1F("hist4", "Histograma Normalizado; Energia Total (MeV); Energia depositada por particula (MeV)",100,275,120000);
cv->Divide(1,3);

TFile *f = new TFile("first_file.root", "RECREATE");

archivo.open("fileclasexx.txt",ios::in);
//cout<<"evento"<<" "<<"Identificacion"<<" "<<"estacion"<<" "<<"momento_x"<<" "<<"momento_y"<<" "<<"momento_z"<<" "<<"masa"<<" "<<"energia_depositada"<<endl;

while(!archivo.eof()){

    archivo>>evento>>Identificacion>>estacion>>momento_x>>momento_y>> momento_z>>masa>>energia_depositada;
    //cout<<evento<<" "<<Identificacion<<" "<<estacion<<" "<<momento_x<<" "<<momento_y<<" "<<momento_z<<" "<<masa<<" "<<energia_depositada<<endl;

    energia=sqrt(pow(momento_x,2)+pow(momento_y,2)+pow(momento_z,2)+pow(masa,2));
    //cout<<"energia_ total = "<<energia<<endl;

    hist1->Fill(energia); //Histograma de la energia total
    hist2->Fill(energia_depositada); //Histograma de la energia depositada
    hist3->Fill(energia,energia_depositada); //Histograma de peso
}

//Normalización de hist3
for(int i=0; i<hist3->GetNbinsX(); i++){

    energia_acumulada=hist3->GetBinContent(i);
    numero_particulas=hist1->GetBinContent(i);
    if(numero_particulas>0){
        norm=(energia_acumulada/numero_particulas); 
        //hist4->Fill(hist1->GetBinCenter(i),norm);
        hist4->SetBinContent(i,norm);
    }
}

cv->cd(1);
hist1->SetLineColor(kRed);
hist1->Draw();
cv->cd(2);
hist2->SetLineColor(kBlue);
hist2->Draw();
//cv->cd(3);
//hist3->SetLineColor(kGreen+2);
//hist3->Draw();
cv->cd(3);
hist4->Draw();

hist1->Write("Energia_total");

    return 0;
}