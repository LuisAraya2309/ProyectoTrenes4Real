//Clase Main

//Incluimos todos los headers

#include <iostream>
#include "CodigosRuta.h"
#include "Rutas.h"
#include "Pais-Ciudad.h"
#include "listaDoble.h"
#include "Pila.h"
#include "Cola.h"
#include "Admin.h"
#include "Usuario.h"
#include"Tipo-Tren.h"
#include "Trenes.h"
#include<stdlib.h>
#include<string.h>
#include<fstream>
using namespace std;
//Definicion de clases






//Definicion de Funciones






//Funcion main

int main() {
	listaDC paises;
	listaC rutas;
	listaC2 admin;
	listaDCUsuario usuario;
	paises.llenarListaPais();
	//paises.Mostrar();
	//cout << "Lista de Paises: " << endl;
	//paises.ConsultarPaises();
	cout << endl;
	cout << "Ciudades" << endl;
	paises.llenarListaCiudad();
	paises.Mostrar();
	paises.ConsultarCiudades();
	/*cout << "Conexiones: " << endl;
	paises.llenarListaConexiones();
	cout << "Rutas: " << endl;
	rutas.llenarListaRutas();
	cout << "Administradores: " << endl;
	admin.llenarListaAdmin();
	admin.Mostrar();
	cout << "Usuarios: " << endl;
	usuario.llenarListaUsuario();*/
	return 0;
}











