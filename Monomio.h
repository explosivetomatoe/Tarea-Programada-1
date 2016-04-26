// 
// File:   Polinomio.h
// Author: Alan CalderOn Castro
//
// Created on 29 de agosto de 2014, 13:06
//


#ifndef _Monomio_H
#define _Monomio_H

#include <sstream>
#include <cstdlib>
#include <memory>
#include <iomanip> // std::setprecision
#include <regex>
using namespace std;

class Monomio {

	/** 
	* Responsabilidades (para quE sirve esta clase?):
	* Esta clase representa el concepto de monomio en 2 variables que llamaremos X, Y.
	* En correspondencia con la definiciOn usual de monomio, los exponentes son enteros.
	* 
	* INVARIANTE DE LA ABSTRACCION (IVA): Una instancia de Monomio estA bien construida si:
        *      Los dos exponentes para X, Y son enteros. 
	*      El coeficiente es cero, esto implica que todos los exponentes son cero.
	*      Todos los exponentes son mayores o iguales a cero.
	*/
	

public:
	/**
	* EFE: Construye el monomio 0 que cumple la IVA.
	*/
	Monomio ();

	/**
	* EFE: Construye una copia de orig que por tanto cumple la IVA.
	*/
	Monomio(const Monomio& orig);
	
        //REQ: que expmono esté bien formada.
        //EFE: Construye una instancia que cumple la IVA.
        Monomio(const string& expmono);
        
        //EFE: destruye a *this.
        ~Monomio();
        
	/**
	* Operadores de construcciOn. Nunca modifican ni a *this ni a m.
      	* Se requiere que ambos operandos (*this y m) cumplan la IVA.
        */
	
	/**
        * REQ: *this y m sean semejantes. 
	* EFE: Construye una instancia que corresponde con la suma de m y *this.
	*/        
	Monomio& operator+(const Monomio& m) const;

	/**
        * REQ: *this y m sean semejantes.
	* EFE: Construye una instancia que corresponde con la resta de m y *this.
	*/        
	Monomio& operator-(const Monomio& m) const;

	/**
	* EFE: Construye una instancia que corresponde con la multiplicaciOn de m y *this.
	*/
	Monomio& operator*(const Monomio& m) const;

	/**
        * REQ: todos los exponentes de *this sean mayores que los de m,
	* REQ: que m sea diferente del monomio cero.	
	* EFE: Construye una instancia que corresponde con la divisiOn de *this por m.
	*/
	Monomio& operator/(const Monomio& m) const;        
	/**
	* Funciones miembro mutadoras.
	* Se requiere que *this estE bien construido en todas las funciones.
	*/

	/**
	* MOD: *this.
	* EFE: Asigna "c" como nuevo coeficiente de *this.
	*/        
	void asgCoef(double c);

	/**
	* REQ: ne >= 0.
	* MOD: *this.
	* EFE: Asigna exponente de X de *this el valor "ne".
		*/
	void asgExpX(int ne);

	/**
	* REQ: ne >= 0.
	* MOD: *this.
	* EFE: Asigna exponente de Y de *this el valor "ne".
		*/
	void asgExpY(int ne);
        
	/**
	* Funciones miembro observadoras. Nunca modifican a *this.
	* Se requiere que *this estE bien construido en todas las funciones.
	*/
	
	/**
	* EFE: Devuelve el valor del coeficiente de *this.
        */       
	double obtCoef() const;

	/**
	* EFE: Devuelve el valor del exponente de X.
        */
	int obtExpX() const;

	/**
	* EFE: Devuelve el valor del exponente de Y.
        */
	int obtExpY() const;
 
	/**
	* RET: true si *this es semejante a m, false en caso contrario.
        * EFE: compara los exponentes de la X y Y para *this y m.
        */
	bool semejante(const Monomio & m) const;
        
	/**
	* RET: true si se cumple la IVA en *this.
	* EFE: Verifica la IVA en *this.
	*/          
	bool verInv();

	/**
	* RET: una hilera que representa a *this en la forma: Cx(ex)y(ey) donde C es el coeficiente,
	*      ex es el exponente de la X y ey es el exponente de la Y.
	*/	
	string aHil();
private:
    string extraerExp(char min, char may, string b); // método privado para extraer algún exponente de una hilera.
    string extraerCoef(string b); // método privado para extraer el coeficiente de una hilera.
    bool esCero() const;
    double coef;
    int expX;
    int expY;
    
    static shared_ptr<Monomio> rs_ptr;
};

#endif /* _Monomio_H */

