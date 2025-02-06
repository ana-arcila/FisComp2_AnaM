#include <iostream>
#include <cmath>
//#include <TH1F.h>
#include <TCanvas.h>
#include <TGraphErrors.h>


// Gausiano
/*
int fit(){
    TCanvas *cv = new TCanvas("cv", "myCanvas", 0, 0, 720, 1080);
    cv -> Divide(1, 2);

    TH1F *hist1 = new TH1F("hist1", "Gausiano", 100, -5, 5);
    hist1 -> FillRandom("gaus", 1000);
    hist1 -> Fit("gaus");

    cv -> cd(1);
    hist1 -> Draw();

    return 0;
}
*/

int fit(){

    auto c1 = new TCanvas("c1", "Movimiento rectilineo", 200, 10, 700, 500);

    const Int_t n = 10;
    Double_t x[n] = {20, 30, 40, 55, 25, 65, 70, 80, 100, 90};
    Double_t y[n] = {1.28, 1.48, 2.15, 2.6, 0.9, 2.81, 3.45, 4.1, 5.3, 6.1};
    Double_t ex[n] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    Double_t ey[n] = {.06, .02, .04, .02, .05, .03, .03, .04, .01, .03};

    auto gr = new TGraphErrors(n, x, y, ex, ey);
    gr -> Fit("pol1");
    gr -> SetTitle("Movimiento Rectilineo");
    gr -> Draw("AP");

    return 0;
}