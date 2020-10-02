
#include <iostream>
using namespace std;

class nodoCir {
public:
    nodoCir(int v)
    {
        valor = v;
        siguiente = NULL;
    }

    nodo(int v, nodoCir* signodo)
    {
        valor = v;
        siguiente = signodo;
    }

private:
    int valor;
    nodoCir* siguiente;


    friend class listaC;
};

typedef nodoCir* pnodoCir;

class listaC {
public:
    listaC() { primero = NULL; }
    ~listaC();

    void InsertarInicio(int v);
    void InsertarFinal(int v);
    void InsertarPos(int v, int pos);
    void EliminarInicio();
    void EliminarFinal();
    void EliminarPos(int pos);
    bool ListaVacia() { return primero == NULL; }
    void Imprimir();
    void Borrar(int v);
    void Mostrar();
    void BorrarFinal();
    void BorrarInicio();
    void borrarPosicion(int pos);
    int largoLista();

private:
    pnodoCir primero;

};

listaC::~listaC()
{
    pnodoCir aux;

    while (primero) {
        aux = primero;
        primero = primero->siguiente;
        delete aux;
    }

}

int listaC::largoLista() {
    int cont = 0;

    pnodoCir aux = primero;
    if (ListaVacia())
        return cont;
    else
    {
        while (aux->siguiente != primero)
        {
            cont++;
            aux = aux->siguiente;
        }
        cont = cont + 1;
        return cont;
    }
}

void listaC::InsertarInicio(int v)
{
    if (ListaVacia())
    {
        pnodoCir nuevo = new nodoCir(v);
        primero = nuevo;
        nuevo->siguiente = primero;
    }
    else
    {
        pnodoCir nuevo = new nodoCir(v);
        pnodoCir aux = primero;
        while (aux->siguiente != primero)
            aux = aux->siguiente;
        nuevo->siguiente = primero;
        aux->siguiente = nuevo;
        primero = nuevo;
    }
}

void listaC::InsertarFinal(int v)
{
    if (ListaVacia())
    {
        pnodoCir nuevo = new nodoCir(v);
        primero = nuevo;
        nuevo->siguiente = primero;
    }
    else
    {
        pnodoCir nuevo = new nodoCir(v);
        pnodoCir aux = primero;
        while (aux->siguiente != primero)
            aux = aux->siguiente;
        nuevo->siguiente = primero;
        aux->siguiente = nuevo;

    }
}


void listaC::InsertarPos(int v, int pos)
{
    if (ListaVacia())
    {
        pnodoCir nuevo = new nodoCir(v);
        primero = nuevo;
        nuevo->siguiente = primero;
    }
    else
    {
        if (pos <= 1)
        {
            InsertarInicio(v);
        }
        else
        {
            pnodoCir aux = primero;
            int i = 2;
            while ((i != pos) && (aux->siguiente != primero))
            {
                i++;
                aux = aux->siguiente;
            }
            pnodoCir nuevo = new nodoCir(v);
            nuevo->siguiente = aux->siguiente;
            aux->siguiente = nuevo;
        }
    }
}

void listaC::BorrarFinal()
{
    if (ListaVacia())
        cout << "No hay elementos en la lista:" << endl;
    else
    {
        if (primero->siguiente == primero)
        {
            pnodoCir temp = primero;
            primero = NULL;
            delete temp;
        }
        else
        {
            pnodoCir aux = primero;
            while (aux->siguiente->siguiente != primero)
                aux = aux->siguiente;
            pnodoCir temp = aux->siguiente;
            aux->siguiente = primero;
            delete temp;
        }
    }
}

void listaC::BorrarInicio()
{
    if (ListaVacia())
        cout << "No hay elementos en la lista:" << endl;
    else
    {
        if (primero->siguiente == primero)
        {
            pnodoCir temp = primero;
            primero = NULL;
            delete temp;
        }
        else
        {
            pnodoCir aux = primero;
            pnodoCir temp = primero;
            while (aux->siguiente != primero)
                aux = aux->siguiente;
            primero = primero->siguiente;
            aux->siguiente = primero;
            delete temp;
        }
    }
}

void listaC::borrarPosicion(int pos)
{
    if (ListaVacia())
        cout << "Lista vacia" << endl;
    else
    {
        if ((pos > largoLista()) || (pos < 0))
            cout << "Error en posicion" << endl;
        else
        {
            if (pos == 1)
                BorrarInicio();
            else
            {
                int cont = 2;
                pnodoCir aux = primero;
                while (cont < pos)
                {
                    aux = aux->siguiente;
                    cont++;
                }
                pnodoCir temp = aux->siguiente;
                aux->siguiente = aux->siguiente->siguiente;
                delete temp;
            }
        }
    }
}

void listaC::Mostrar()
{
    pnodoCir aux = primero;
    while (aux->siguiente != primero)
    {

        cout << aux->valor << "-> ";
        aux = aux->siguiente;
    }
    cout << aux->valor << "->";
    cout << endl;
}
