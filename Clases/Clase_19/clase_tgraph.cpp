#include <iostream>
#include <cmath>
#include <TGraph.h>

using namespace std;

int clase_tgraph(){
    double x[100], y[100];
    int n=20;
    for (int i=0; i<n;i++){
        x[i]=i*0.1;
        y[i]=10*sin(x[i]+0.2);

    }

    auto g = new TGraph(n,x,y);
    g->SetTitle("Graph title; X title; Y title");
    g->Draw("AC*");
    return 0;
}

