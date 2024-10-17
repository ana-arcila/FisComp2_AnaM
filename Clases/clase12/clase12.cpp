#include <iostream>
#include <cmath>
using namespace std;

//Punteros

/*
 int main(){
    int a;
    int *aPtr;
    a = 7;
    aPtr =& a;

    cout << "La direccion de a es: "<< &a <<"\nEl valor de aPtr es: "<< aPtr<< endl;

    cout <<"\nEl valor de a es: "<< a <<"\nEl valor de *aPtr es: "<< *aPtr<< endl;

    cout <<"\nDemostracion de que * y & son inversos uno del otro: \n&*aPtr = "<<&*aPtr
    <<"\n*&aPtr = "<< *&aPtr<< endl;

    return 0;
 }
 */

 //Punteros 2

/*
 int main(){
    int x, y;
    const int *ptr; //= &x;
    ptr = &x;
    cout <<*ptr<< endl;
    //*ptr = 6; No se puede hacer porque *ptr es read-only
    ptr = &y; //*ptr = &y; no se puede hacer porque *ptr es el valor de ese punto
    cout <<*ptr<< endl;

    int z=3, w;
    const int *const ptr2=&z;
    cout <<*ptr2<< endl;
    *ptr2=6; //error
    *ptr2 = &w // error
    cout <<*ptr2<< endl;
    
    return 0;
 }
 */

//Ejemplo

 int cuboPorValor(int);
 void cuboPorReferencia(int*);

 int main(){
    int numero = 5;
    cout <<"El valor original de numero es: "<< numero<< endl;
    numero = cuboPorValor(numero);
    cout <<"El nuevo valor de numero es: "<<numero<<endl;

    int numero2 = 5;
    cout <<"El valor original de numero2 es: "<<numero2<< endl;
    cuboPorReferencia(&numero2);
    cout <<"El nuevo valor de numero2 es: "<<numero2<< endl;

    return 0;
 }

 int cuboPorValor(int n){
    return n*n*n;
 }

 void cuboPorReferencia(int *nPtr){
    *nPtr = (*nPtr) * (*nPtr) * (*nPtr);
 }