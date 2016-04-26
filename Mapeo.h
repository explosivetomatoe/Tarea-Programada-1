/* 
 * File:   Mapeo.h
 * Author: Alan
 *
 * Created on 29 de agosto de 2014, 01:22 PM
 */

#ifndef MAPEO_H
#define	MAPEO_H

#include <iostream>
using namespace std;

#include "Polinomio.h"

class Mapeo {
public:
    Mapeo();
    virtual ~Mapeo();
    
    // REQ: que nombre sea del tipo "p1", "p2", etc; y que poli cumpla la IVA correspondiente.
    // EFE: guarda en *this a poli asociado al nombre.
    void asgPolinomio(const string& nombre, const Polinomio& poli);
    
    // REQ: que nombre haya sido previamente guardado con asgPolinomio a un polinomio.
    // RET: el polinomio previamente guardado con el nombre dado.
    // EFE: busca el polinomio previamente guardado bajo el nombre dado.
    Polinomio& obtPolinomio(const string& nombre);
    
    // RET: true si el nombre ha sido previamente asignado a algún polinomio, false en caso contrario.
    bool verPolinomio(const string& nombre);
    
private:

};

#endif	/* MAPEO_H */

