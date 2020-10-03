#include<fstream>
#include <iostream>
#include <stdlib.h>
#include<string>
using namespace std;

class nodo {
public:
    nodo(int v, string cpais)
    {
        valor = v;
        pais = cpais;
        siguiente = NULL;
        anterior = NULL;
        ciudad = NULL;
    }

    nodo(int v, string cpais, nodo* signodo, nodo* sigCiudad)
    {
        valor = v;
        pais = cpais;
        siguiente = signodo;
        ciudad = sigCiudad;
    }

private:
    int valor;
    string pais;
    nodo* ciudad;
    nodo* siguiente;
    nodo* anterior;


    friend class listaDC;
};
typedef nodo* pnodo;

class listaDC {
public:
    listaDC() { primero = NULL; }
    //~listaDC();

    void InsertarInicio(int v, string pais);
    void InsertarFinal(int v, string pais);
    void InsertarPos(int v, string pais, int pos);
    bool ListaVacia() { return primero == NULL; }
    void Imprimir();
    void Borrar(int v);
    void Mostrar();
    void BorrarFinal();
    void BorrarInicio();
    void BorrarPosicion(int pos);
    int largoLista(); \
    void llenarListaPais();
    void llenarListaCiudad();

private:
    pnodo primero;

};
/*
listaDC::~listaDC()
{
    pnodo aux;

    while (primero) {
        aux = primero;
        primero = primero->siguiente;
        primero->anterior = aux->anterior;
        aux->anterior->siguiente = primero;
        delete aux;
    }

}*/

int listaDC::largoLista()
{
    int cont = 0;

    pnodo aux = primero;
    if (ListaVacia())
    {
        return cont;
    }
    else
    {
        while (aux != primero)
        {
            aux = aux->siguiente;
            cont++;
        }
        return cont;
    }

}

void listaDC::InsertarInicio(int v, string pais)
{

    if (ListaVacia())
    {
        primero = new nodo(v, pais);
        primero->anterior = primero;
        primero->siguiente = primero;
    }
    else
    {
        pnodo nuevo = new nodo(v, pais);
        nuevo->siguiente = primero;
        nuevo->anterior = primero->anterior;
        primero->anterior->siguiente = nuevo;
        nuevo->siguiente->anterior = nuevo;
        primero = nuevo;
    }
}

void listaDC::InsertarFinal(int v, string pais)
{
    if (ListaVacia())
    {
        primero = new nodo(v, pais);
        primero->anterior = primero;
        primero->siguiente = primero;
    }
    else
    {
        pnodo nuevo = new nodo(v, pais);
        nuevo->anterior = primero->anterior;
        nuevo->siguiente = primero->anterior->siguiente;
        primero->anterior->siguiente = nuevo;
        primero->anterior = nuevo;
    }
}


void listaDC::InsertarPos(int v, string pais, int pos)
{
    if (ListaVacia())
    {
        primero = new nodo(v, pais);
        primero->anterior = primero;
        primero->siguiente = primero;
    }
    else
    {
        if (pos <= 1)
            InsertarInicio(v, pais);
        else
        {
            if (pos == largoLista())
                InsertarFinal(v, pais);
            else
            {
                pnodo aux = primero;
                int i = 2;
                while ((i != pos) && (aux->siguiente != primero))
                {
                    i++;
                    aux = aux->siguiente;
                }
                pnodo nuevo = new nodo(v, pais);
                nuevo->siguiente = aux->siguiente;
                aux->siguiente = nuevo;
                aux->siguiente->anterior = aux;
                nuevo->siguiente->anterior = nuevo;
            }
        }
    }
}

void listaDC::BorrarFinal()
{
    if (ListaVacia())
        cout << "No hay elementos en la lista:" << endl;
    else
    {
        if (primero->siguiente == primero)
        {
            pnodo temp = primero;
            primero = NULL;
            delete temp;
        }
        else
        {
            pnodo aux = primero;
            while (aux->siguiente->siguiente != primero)
                aux = aux->siguiente;
            pnodo temp = aux->siguiente;
            aux->siguiente = primero;
            primero->anterior = aux;
            delete temp;
        }
    }
}

void listaDC::BorrarInicio()
{
    if (ListaVacia())
        cout << "No hay elementos en la lista:" << endl;
    else
    {
        if (primero->siguiente == primero)
        {
            pnodo temp = primero;
            primero = NULL;
            delete temp;
        }
        else
        {
            pnodo aux = primero->anterior;
            pnodo temp = primero;
            aux->siguiente = primero->siguiente;
            primero = primero->siguiente;
            primero->anterior = aux;
            delete temp;
        }
    }
}

void listaDC::BorrarPosicion(int pos)
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
                pnodo aux = primero;
                while (cont < pos)
                {
                    aux = aux->siguiente;
                    cont++;
                }
                pnodo temp = aux->siguiente;
                aux->siguiente = aux->siguiente->siguiente;
                delete temp;
            }
        }
    }
}

void listaDC::Mostrar()
{
    pnodo aux = primero;
    while (aux->siguiente != primero)
    {

        cout << aux->valor << "-" << aux->pais << "->";
        aux = aux->siguiente;
    }
    cout << aux->valor << "-" << aux->pais << "->";
    cout << endl;
}

void listaDC::llenarListaPais() {
    ifstream archivo;
    string texto;
    archivo.open("Paises.txt", ios::in);
    if (archivo.fail()) {
        cout << "No se pudo abrir el archivo";
        exit(1);
    }
    while (!archivo.eof()) {
        getline(archivo,texto);
        int posPC = texto.find(";");
        int codPais = atoi(texto.substr(0, posPC).c_str());
        string nomPais = texto.substr(posPC + 1, texto.length());
        if (ListaVacia()) {
            InsertarFinal(codPais, nomPais);
        }
        else {
            pnodo puntero = primero; bool flag = true;
            while (puntero->siguiente != primero) {
                if (puntero->valor == codPais) {
                    flag = false;
                    break;
                }
                else {
                    puntero = puntero->siguiente;
                }
            }
            if (flag) {
                InsertarFinal(codPais, nomPais);
            }
            
        }
        
    }
    archivo.close();
}

void listaDC::llenarListaCiudad() {
    ifstream archivo;
    string texto;
    archivo.open("Ciudades.txt", ios::in);
    if (archivo.fail()) {
        cout << "No se pudo abrir el archivo";
        exit(1);
    }
    while (!archivo.eof()) {
        getline(archivo, texto);
        int posPC = texto.find(";");
        int codPais = atoi(texto.substr(0, posPC).c_str());
        pnodo puntero = primero; bool flag = false;
        while (puntero->siguiente != primero) {
            if (puntero->valor == codPais) {
                flag = true;
                break;
            }
            else {
                puntero = puntero->siguiente;
            }
        }
        
        if (flag) {
            string CiudadTotal = texto.substr(posPC + 1, texto.length());
            int auxPC = CiudadTotal.find(";");
            int codCiudad = atoi(CiudadTotal.substr(0, auxPC).c_str());
            string nomCiudad = CiudadTotal.substr(auxPC+1, CiudadTotal.length());
            pnodo auxiliar = primero;
            while (auxiliar->siguiente != primero) {
                if (auxiliar->valor == codPais) {
                    break;
                }
                else {
                    auxiliar = auxiliar->siguiente;
                }
            }
            if ((puntero->ciudad==NULL)) {
                cout << "Primera Ciudad: "<<nomCiudad<< endl;
                pnodo nuevo = new nodo(codCiudad, nomCiudad);
                nuevo->anterior = puntero;
                puntero->ciudad = nuevo;
            }
            else {
                cout << "No soy segunda ciudad: "<<nomCiudad<< endl;
                bool flag = true;
                pnodo punteroAux = puntero;
                while (punteroAux->siguiente != puntero) {
                    if (punteroAux->valor == codCiudad) {
                        flag = false;
                        break;
                    }
                    else {
                        punteroAux = punteroAux->siguiente;
                    }
                }
                if (flag) {
                    pnodo nuevo = new nodo(codCiudad, nomCiudad);
                    nuevo->anterior = puntero->anterior;
                    nuevo->siguiente = puntero->anterior->siguiente;
                    puntero->anterior->siguiente = nuevo;
                    puntero->anterior = nuevo;
                    cout << "Agregado nuevo nodo al pais: " << codPais << " Con la ciudad: " << nomCiudad << endl;

                }
            }
        }
        else {
            continue;
        }
    }
}
/*Error cada vez que se reinicia la Lista entonces las ciudades de un mismo 
pa�s se quedan fuera.*/