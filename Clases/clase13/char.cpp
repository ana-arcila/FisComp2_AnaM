#include <iostream>
#include <cctype> //

using namespace std;

void convertirAMayusculas (char *); //función que toma como argumento un puntero
void imprimirCaracteres(const char *); //Esta función recibe un puntero constante a una cadena
// (significa que no puede modificar los datos a los que apunta) y los imprime carácter por carácter.

int main(){

    cout<<"Apuntador no constante a datos no constantes"<<endl;
    char frase[]="caracTeres y $32.98"; //declara un array de caracteres
    cout<<"La frase antes de la conversion es: "<<frase<<endl;
    convertirAMayusculas(frase);
    cout<<"La frase despues de la conversion es: "<<frase<<endl;
    cout<<endl;

    cout<<"Apuntador no constante a datos constantes"<<endl;
    const char frase2[]="Imprimir caracteres de una cadena";
    cout<<"La cadenas es: ";
    imprimirCaracteres(frase2);
    cout<<endl;
    return 0;
}


//convertir la cadenas a letras mayusculas
void convertirAMayusculas(char *sPtr){

    //recorre la cadenas carcater por caracter hasta llegar al caracter nulo '\0'
    while (*sPtr != '\0'){
        if (islower(*sPtr)){ //si el caracter es minuscula
        *sPtr=toupper(*sPtr);} //lo convierte a mayuscula
        sPtr++; //Mueve sPtr al siguiente carcater en la cadena 
    }
}


//sPtr se puede modificar, pero no se puede modificar el caracter al cual apunta, es decir;
// sPtr es un apuntador de solo lectura, por lo tanto se pueden leer los caracteres pero no modificarlos
void imprimirCaracteres(const char *sPtr){
    //recorremos la cadena hasta llegar al caracter nulo, imprimiedno cada caracter
    for (; *sPtr != '\0'; sPtr++){
    cout<<*sPtr;}
}
