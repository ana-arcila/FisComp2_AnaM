#include <iostream>

using namespace std;

void copia1(char *, const char *); //Copia una cadena de una fuente (s2) a un destino (s1) usando notación de arreglos.
void copia2(char *, const char *); //  Copia una cadena de una fuente (s2) a un destino (s1) usando notación de punteros.

int main(){
    char cadena1[10]; //arreglo de 10 caracteres vacio
    const char *cadena2= "Hola"; // declara un puntero a una cadena constante hola
    char cadena3[10];
    char cadena4[]="Hasta luego"; //declara un array que contiene la cedena hasta luego

    copia1(cadena1, cadena2);
    cout<<"cadena1 = "<<cadena1<<endl;

    copia2(cadena3, cadena4);
    cout<<"cadena3 = "<<cadena3<<endl;

    return 0;
}

//copia la cadena s2 (origen) a s1(destino) usando notacion de arreglos
void copia1(char *s1, const char *s2){
    for (int i=0; (s1[i]=s2[i])!='\0';i++) // '\0' marca el final de un caracter
    ; //no hace nada en el cuerpo
}

//copia s2 a s1 usando notacion de apuntador
void copia2(char *s1, const char *s2){
    //copia el contenido apuntado por s2 al lugar apuntado por s1
    //copia el carácter al que apunta s2 en s1 y continúa hasta que alcanza el carácter nulo ('\0')
    for (; (*s1=*s2)!='\0';s1++,s2++)
    ; 
}

//El primer argumento para copia1 y copia2 debe ser un arreglo lo bastante rande como para contener la copia