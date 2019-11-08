#include <iostream>
#include <cstdlib>
using namespace std;

struct nodo{
     int nro;
     struct nodo *izq, *der;
};

typedef struct nodo *ABB;


ABB crearNodo(int x)
{
     ABB nuevoNodo = new(struct nodo);
     nuevoNodo->nro = x;
     nuevoNodo->izq = NULL;
     nuevoNodo->der = NULL;

     return nuevoNodo;
}
void insertar(ABB &arbol, int x)
{
     if(arbol==NULL)
     {
           arbol = crearNodo(x);
     }
     else if(x < arbol->nro)
          insertar(arbol->izq, x);
     else if(x > arbol->nro)
          insertar(arbol->der, x);
}

void preOrden(ABB arbol)
{
     if(arbol!=NULL)
     {
          cout << arbol->nro <<" ";
          preOrden(arbol->izq);
          preOrden(arbol->der);
     }
}



int main()
{
    ABB arbol = NULL;

    int n;
    int x;

    cout << "\n\t\t C,: ARBOL BINARIO DE BUSQUEDA :,C  \n\n";

    cout << " Numero de nodos:  ";
    cin >> n;
    cout << endl;

    for(int i=0; i<n; i++)
    {
        cout << " Inserte numero" << i+1 << ": ";
        cin >> x;
        insertar( arbol, x);
    }



    cout << "\n\n Pre Orden  :  ";   preOrden(arbol);


    cout << endl << endl;

    system("pause");
    return 0;
}
