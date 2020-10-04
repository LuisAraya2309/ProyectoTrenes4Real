//Clase Main

//Incluimos todos los headers

#include <iostream>
#include "listaSimple.h"
#include "listaSimpleCircular.h"
#include "listaDobleCircular.h"
#include "listaDoble.h"
#include "Pila.h"
#include "Cola.h"
#include<stdlib.h>
#include<string.h>
#include<fstream>
using namespace std;
//Definicion de clases






//Definicion de Funciones






//Funcion main

int main() {
	listaDC paises;
	paises.llenarListaPais();
	cout << "Lista de Paises: " << endl;
	paises.Mostrar();
	cout << endl;
	cout << "Ciudades" << endl;
	paises.llenarListaCiudad();
	cout << "Conexiones: " << endl;
	paises.llenarListaConexiones();
	return 0;
}











