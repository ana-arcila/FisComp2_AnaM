#include <iostream>
#include <cmath>
#include "tri.h"
using namespace std;

int main(){
    int x, y;
    
    cout <<"Ingrese el cateto opuesto:"<< endl;
    cin >> x;
    cout <<"Ingrese el cateto adyacente:"<< endl;
    cin >> y;

    Triangulos rect(x, y);
    rect.Per();
    rect.Area();
    return 0;
}