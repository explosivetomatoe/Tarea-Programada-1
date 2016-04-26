/* 
 * File:   Evaluador.h
 * Author: Alan
 *
 * Created on 29 de agosto de 2014, 01:11 PM
 */

#ifndef EVALUADOR_H
#define	EVALUADOR_H

#include "Polinomio.h"

class Evaluador {
    
public:
    Evaluador();
    virtual ~Evaluador();
    
    // REQ: exp esté bien construida y que existan los nombres de polinomios en el Mapeo.
    // RET: un polinomio con el resultado de evaluar exp.
    // EFE: evaluar exp y genera un nuevo polinomio.
    Polinomio& evaluar(const string& exp);
    
private:
    
    // REQ: exp esté bien construida y que existan los nombre de polinomios en el Mapeo.
    // RET: una hilera.
    // EFE: construye correctamente una nueva hilera con la equivalente expresión posfija para expInfija.
    string& aPosfija(const string& expInfija);
    
    // REQ: expPosfija esté bien construida y que existan los nombre de polinomios en el Mapeo.
    // RET: un nuevo polinomio.
    // EFE: construye un nuevo polinomio que cumple la IVA y corresponde a la evaluación correcta de expPosfija.
    Polinomio& evaluarPosfija(const string& expPosfija);

};

#endif	/* EVALUADOR_H */

