// 
// File:   Polinomio.h
// Author: Alan CalderOn Castro
//
// Created on 29 de agosto de 2014, 13:06
//

#ifndef _Polinomio_H
#define	_Polinomio_H

#include <iostream>
using namespace std;

#include "Monomio.h"

class Polinomio {
    /**
     * Responsabilidades (para quE sirve esta clase?):
     * Esta clase representa el concepto de polinomio en 2 variables que llamaremos X, Y.
     *
     * INVARIANTE DE LA ABSTRACCION (IVA): Una instancia de Polinomio estA bien construida si:
     * EstA simplificada o lo que es lo mismo, no aparecen dos monomios con los mismos exponentes en X, Y.
     * Y estA ordenada por exponente de X, Y descendentemente.
     * Y, si es el polinomio cero, se representa con base en el monomio cero: 0 X(0) Y(0).
     * Y la invariante de la abstracciOn de monomio se cumple para todos sus miembros.
     */

public:

    //EFE: Construye una instancia de Polinomio que cumple la IVA.      
    Polinomio();

    //EFE: Construye una copia del polinomio orig que por tanto cumple la IVA.  
    Polinomio(const Polinomio& orig);

    //REQ: que expoli esté bien formada.
    //EFE: Construye una instancia que cumple la IVA.
    Polinomio(const string& expoli);

    //EFE: destruye *this.
    ~Polinomio();
    
    /**
     * Operadores de construcciOn.
     * En todos se requiere que tanto *this como p cumplan la IV.
     * Nunca modifican al polinomio *this ni a p.
     */

    /**
     * RET: Nuevo Polinomio igual a (*this) + p.
     * EFE: Construye una instancia que corresponde con la suma de *this y p.
     */
    Polinomio& operator+(const Polinomio& p) const;

    /**
     * RET: Nuevo Polinomio igual a (*this) - p.
     * EFE: Construye una instancia que corresponde con la resta de *this y p.
     */
    Polinomio& operator-(const Polinomio& p) const;

    /**
     * RET: Nuevo Polinomio igual a (*this) * p.        
     * EFE: Construye una instancia que corresponde con la multiplicaciOn de *this y p.
     */
    Polinomio& operator*(const Polinomio& p) const;

    /**
     * RET: Nuevo Polinomio igual a (*this) / p.        
     * EFE: Construye una instancia que corresponde con la divisiOn de *this y p.
     */
    Polinomio& operator/(const Polinomio& p) const;

    /**
     * Funciones miembro observadoras. Nunca modifican *this.
     * En todas se requiere que *this cumpla la IVA.
     */

    /**
     * RET: El valor del grado del polinomio.        
     */
    int verGrado();

    /**
     * RET: El valor del polinomio al ser evaluado con valores x,y.        
     */
    double eval(double x, double y);

    /**
     * RET: Una hilera con una representación adecuada del polinomio *this.        
     */
    string aHil();

    /**
     * REQ: N/A.
     * RET: true si se cumple la IVA para *this false si no se cumple la IVA para *this.
     * EFE: Verifica la IVA en *this.
     */
    bool verInv();

private:
    // su representación
};

#endif	/* _Polinomio_H */

