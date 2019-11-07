#include <iostream>
#include <cstdlib>
using namespace std;

struct nodo{
     int dato;
     nodo *der;
     nodo *izq;

};

//funciones

void menu();
 nodo *crearNodo(int);
 void insertarNodo(nodo *&, int);
 void mostrarArbol(nodo *, int);

 nodo *arbol= NULL;

 int main () {
    menu();
    return 0;
 }

void menu(){
    int dato, opcion, contador= 0;

    do{
    cout<< ".: MENU:. "<<endl;
    cout<< "1. Insertar un nuevo Nodo "<<endl;
    cout<< "2. Mostrar Arbol "<<endl;
    cout<< "3. Salir "<<endl;
    cout<< " opcion: ";
    cin>> opcion;

    switch (opcion){
        case 1: cout<< " \nDigite un numero: ";
            cin>> dato;
            insertarNodo(arbol, dato);
            cout<<"\n";
        case 2: cout<<"\n Mostrando Arbol:\n\n";
            mostrarArbol(arbol, contador);
            cout<<"\n";
            break;


    }

    }while(opcion!=3);

}

nodo *crearNodo(int n){
    nodo *nuevo_nodo= new nodo();
    nuevo_nodo->dato= n;
    nuevo_nodo->der =NULL;
    nuevo_nodo->izq =NULL;

    return nuevo_nodo;

}

void insertarNodo(nodo *&arbol, int n){
    if (arbol== NULL ) {
        nodo* nuevo_nodo= crearNodo(n);
        arbol= nuevo_nodo;
    }
    else {
        int valorRaiz = arbol->dato;
        if(n< valorRaiz){
            insertarNodo(arbol->izq,n);

        }
        else{
            insertarNodo(arbol->der, n);
        }
    }
}
void mostrarArbol(nodo *arbol, int cont ) {
    if (arbol== NULL){
        return;
    }
    else {
        mostrarArbol(arbol->der, cont+1);
        for (int i=0; i< cont; i++){
            cout<<"     ";
        }
        cout<< arbol->dato<<endl;
        mostrarArbol(arbol->izq, cont+1);

    }
}
