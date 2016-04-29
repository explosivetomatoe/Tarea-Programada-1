#include <string>
#include "Polinomio.h"
#include "Evaluador.h"
shared_ptr<Polinomio> Polinomio::cnj_nvo_mon(nullptr);
//shared_ptr<Polinomio> Polinomio::poli_new_ptr(nullptr);

Polinomio::Polinomio() : inicio() {
    inicio = shared_ptr<NdoPoli>(new NdoPoli("0.00X(0)Y(0)"));
}

Polinomio::Polinomio(const Polinomio& orig) {
    shared_ptr<NdoPoli> p = orig.inicio;

    inicio = shared_ptr<NdoPoli>(new NdoPoli(orig.inicio->expoli));
    p = p->sgt;
    shared_ptr<NdoPoli> ultimo = inicio;
    while (p != nullptr) { // Mientras no se acabe orig.
        ultimo->sgt = shared_ptr<NdoPoli>(new NdoPoli(p->expoli));
        p = p->sgt;
        ultimo = ultimo->sgt;
    }
}

Polinomio::Polinomio(const string & expoli) {

     //ejemplo de commo separar en un char especifico y hacer un array
    /*
    string str = "102:330:3133:76531:451:000:12:44412";
    for (int i=0; i<str.length(); i++)
    {
        if (str[i] == ':')
        str[i] = ' ';
    }

    vector<int> array;
    stringstream ss(str);
    int temp;
    while (ss >> temp)
    array.push_back(temp); // done! now array={102,330,3133,76531,451,000,12,44412}
     *
   */
}

Polinomio::~Polinomio() {
}

Polinomio & Polinomio::operator+(const Polinomio & p) const {

}

Polinomio & Polinomio::operator-(const Polinomio & p) const {

}

Polinomio & Polinomio::operator*(const Polinomio & p) const {

}

Polinomio & Polinomio::operator/(const Polinomio & p) const {

}

int Polinomio::verGrado() {

}

double Polinomio::eval(double x, double y) {

}

string Polinomio::aHil() {
    stringstream fs;
    shared_ptr<NdoPoli> p = inicio;
    
    while (p != nullptr) {
        fs << p ->expoli;
        p = p->sgt;   
        if (p->sgt != nullptr)
            fs << '+';
    }
    return fs.str();
}

bool Polinomio::verInv() {
    bool cumple = true;
    shared_ptr<NdoPoli> p = inicio;
    while (p != nullptr)//exprecion nula solo al final
    {
        if(p->expoli.semejante((p->sgt->expoli.obtExpX)))     
            cumple = false;       
        if(p->expoli.obtExpX()<(p->sgt->expoli.obtExpX))       
            cumple = false;        
        else if(p->expoli.obtExpY()<(p->sgt->expoli.obtExpY))
            cumple = false;    
        
        p = p-> sgt;
    }
    return cumple;
}
