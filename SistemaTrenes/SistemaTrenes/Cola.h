#include <iostream>
using namespace std;

class cola
{
private:
    int frente;
    int fondo;
    int Cola[5];


public:
    cola() {
        frente = 0;
        fondo = -1;
        for (int i = 0; i < 5; i++) {
            Cola[i] = 0;
        }
    }

    bool ColaVacia() { return fondo < frente; }
    void insertar(int v);
    void eliminar();
    void imprimir();
};

void cola::insertar(int v)
{
    if (fondo < 5 - 1) {
        fondo++;
        Cola[fondo] = v;

    }
    else {
        cout << "La cola esta llena";
    }
}

void cola::eliminar()
{
    if (!ColaVacia()) {
        frente++;
    }
    else {
        cout << "La cola esta vacia";
    }
}

void cola::imprimir() {
    for (int i = frente; i < fondo + 1; i++) {
        cout << Cola[i] << "->" << endl;
    }
}