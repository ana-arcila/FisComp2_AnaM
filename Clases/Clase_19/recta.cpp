#include <iostream>
#include <cmath>
#include <TCanvas.h>
#include <TGraphErrors.h>

using namespace std;

int recta(){
    auto c1 = new TCanvas("c1", "A Simple Graph with error bars",200,10,700,500);
    c1->SetGrid();

    
    const Int_t n=10;
    Double_t y[n] = {20,30,40,55,25,65,70,80,100,90};
    Double_t x[n] = {1.28,1.48,2.15,2.60,0.9,2.81,3.45,4.1,5.3,6.1};
    Double_t ey[n] = {1,1,1,1,1,1,1,1,1,1};
    Double_t ex[n] = {0.06,0.02,0.04,0.02,0.05,0.03,0.03,0.04,0.01,0.03};

    auto gr = new TGraphErrors(n,x,y,ex,ey);
    gr->Fit("pol1");
    gr->SetTitle("MRU");
    gr->SetMarkerColor(4);
    gr->SetMarkerStyle(21);
    gr->Draw();

    return 0;
}