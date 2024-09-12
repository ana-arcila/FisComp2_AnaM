#include <iostream>
#include <cmath>
using namespace std;

//Conteo


/*
int main(){

    int i, j, k;
    
    i=0, j=1, k=-3;

    cout <<i<<"_"<<j<<"_"<<k<< endl;

    i++;
    j--;
    k++;

    cout <<i<<"_"<<j<<"_"<<k<< endl; 

    return 0;

}
*/

//Ciclo_for

/*
int main(){

    int i;

    for (i=10; i>=1; i--){

        cout <<i<< endl;

    }

    return 0;

}
*/

//Factorial

/*
int main(){

    int i, n, f;

    f=1;
    n=5;

    for (i=1; i<=n; i++){
        f*=i;
    }

    cout <<f<< endl;

    return 0;
}
*/

//Factorial2

int main(){

    float i, n, f, m;

    f=1.;
    n=5.;

    for (i=1.; i<=n; i++){
        f*=i;
    }

    m=1./f;

    cout <<m<< endl;

    return 0;
}