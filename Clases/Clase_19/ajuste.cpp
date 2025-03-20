#include <iostream>
#include<TH1F.h>
#include<TCanvas.h>
using namespace std;

int ajuste(){
    //TCanvas *cv = new TCanvas("cv", "mycanvas",0,0,720,720);
  
    TH1F *h1 = new TH1F("h1", "Histograma",100,-10,10);
    h1->FillRandom("gaus",10000);
    h1->Fit("gaus");
    h1->Draw();

    return 0;
}
