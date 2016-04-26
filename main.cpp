/* 
 * File:   main.cpp
 * Author: Alan
 *
 * Created on 29 de agosto de 2014, 12:06 PM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

#include "Evaluador.h"
#include "Mapeo.h"
#include "Monomio.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    //    Polinomio p;
    //    Monomio m;
    //    Evaluador eval;
    //    Mapeo map;
    //    string nom;
    //    Polinomio ps(nom);
    //    Monomio ms(nom);

    // Prueba exhaustiva del constructor de monomios basado en una hilera
    string nomArch = "expmonos.txt";
    string expmono = "";
    ifstream archivoLineasEntrada(nomArch.c_str(), ios::in);
    if (!archivoLineasEntrada) { // operador ! sobrecargado
        cerr << "No se pudo abrir el archivo de entrada" << endl;
        exit(1);
    }
    getline(archivoLineasEntrada, expmono); // se lee la primera línea
    while (!archivoLineasEntrada.eof()) {
        Monomio m(expmono); // Se invoca el constructor basado en una hilera.
        cout << expmono << " --> " << m.aHil() << endl;
        getline(archivoLineasEntrada, expmono); // se lee la siguiente línea
    }
    return 0;
}

