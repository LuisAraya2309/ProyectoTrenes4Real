
#include <iostream>
using namespace std;

class nodoDoble {
public:
    nodoDoble(string v)
    {
        valor = v;
        siguiente = NULL;
        anterior = NULL;
    }

    nodoDoble(string v, nodoDoble* signodoDoble)
    {
        valor = v;
        siguiente = signodoDoble;
    }
    string valor;
    nodoDoble* siguiente;
    nodoDoble* anterior;


    friend class listaD;
};

typedef nodoDoble* pnodoDoble;

class listaD {
public:
    listaD() { primero = NULL; }
    ~listaD();

    void InsertarInicio(string v);
    void InsertarFinal(string v);
    bool ListaVacia() { return primero == NULL; }
    void Imprimir();
    void Mostrar();
    int largoLista();
    pnodoDoble primero;

};

listaD::~listaD()
{
    pnodoDoble aux;

    while (primero) {
        aux = primero;
        primero = primero->siguiente;
        delete aux;
    }

}

int listaD::largoLista() {
    int cont = 0;

    pnodoDoble aux;
    aux = primero;
    if (ListaVacia()) {
        return cont;
    }
    else {
        while (aux != NULL) {
            aux = aux->siguiente;
            cont++;
        }
        return cont;
    }

}

void listaD::InsertarInicio(string v)
{
    if (ListaVacia()) {
        primero = new nodoDoble(v);
    }
    else
    {
        pnodoDoble aux = primero;
        primero = new nodoDoble(v, primero);
        aux->anterior = primero;
    }

}

void listaD::InsertarFinal(string v)
{
    if (ListaVacia()) {
        primero = new nodoDoble(v);
    }
    else
    {
        pnodoDoble aux = primero;
        while (aux->siguiente != NULL) {
            aux = aux->siguiente;
        }
        pnodoDoble nuevo = new nodoDoble(v);
        aux->siguiente = nuevo;
        nuevo->anterior = aux;

    }
}
void listaD::Mostrar()
{
    nodoDoble* aux;

    aux = primero;
    while (aux) {
        cout << aux->valor << "-> ";
        aux = aux->siguiente;
    }
    cout << endl;
}
