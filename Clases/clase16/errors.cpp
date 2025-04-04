#include <iostream>
#include <cmath>
#include <TGraphErrors.h>
#include <TCanvas.h>

using namespace std;

int errors(){
    auto c1 = new TCanvas("c1", "A Simple Graph with error bars", 200, 10, 700, 500);
    c1 -> SetFillColor(42);
    c1 -> SetGrid();
    c1 -> GetFrame() -> SetFillColor(21);
    c1 -> GetFrame() -> SetBorderSize(12);

    const Int_t n = 10;
    Double_t x[n] = {-0.22, 0.05, 0.25, 0.35, 0.5, 0.61, 0.7, 0.85, 0.89, 0.95};
    Double_t y[n] = {1, 2.9, 5.6, 7.4, 9, 9.6, 8.7, 6.3, 4.5, 1};
    Double_t ex[n] = {.05, .1, .07, .07, .04, .05, .06, .07, .08, .05};
    Double_t ey[n] = {.8, .7, .6, .5, .4, .4, .5, .6, .7, .8};

    auto gr = new TGraphErrors(n, x, y, ex, ey);
    gr -> SetTitle("TGraphErrors Example");
    gr -> SetMarkerColor(4);
    gr -> SetMarkerStyle(21);
    gr -> Draw("ALP");

    return 0;
}