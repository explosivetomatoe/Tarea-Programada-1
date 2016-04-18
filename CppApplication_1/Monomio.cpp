#include "Monomio.h"

shared_ptr<Monomio> Monomio::rs_ptr = 0;

Monomio::Monomio ():coef(0.0), expX(0), expY(0){  
}

Monomio::Monomio(const Monomio& orig): coef(orig.coef), expX(orig.expX), expY(orig.expY){
    if (coef == 0.0){
        expX = 0;
        expY = 0;
    }
}

Monomio::~Monomio(){
}

Monomio::Monomio(const string& expmono){
    string h = expmono;
    int p1 = expmono.find_first_of("(");
    string sCoef = expmono.substr(0,p1-1); // se extrae el coeficiente
    
    int p2 = expmono.find_first_of(")");
    string sExpX = expmono.substr(p1+1,p2-p1-1); // se extrae el exponente X
    
    h = expmono.substr(p2+1);
    int p3 = h.find_first_of("(");
    int p4 = h.find_first_of(")");
    string sExpY = h.substr(p3+1,p4-p3-1); // se extrae el exponente Y
    coef = atof(sCoef.c_str());
    expX = atoi(sExpX.c_str());
    expY = atoi(sExpY.c_str());
    
    if (coef == 0.0){
        expX = 0;
        expY = 0;
    }
}

Monomio& Monomio::operator+(const Monomio& m) const{
    if (rs_ptr != 0)
        rs_ptr.reset();
    rs_ptr = shared_ptr<Monomio>(new Monomio());
    Monomio& rs = *rs_ptr;
    if (!(this->esCero())&&!(m.esCero())){
        rs.coef = this->coef + m.coef;
        rs.expX = this->expX;
        rs.expY = this->expY;
    } else {
        if (this->esCero())
            rs = m;
        else rs = *this;
    }
    if (rs.coef == 0.0){
        rs.expX = 0;
        rs.expY = 0;
    }    
    return rs; // se usa atributo static
}

Monomio& Monomio::operator-(const Monomio& m) const{
    if (rs_ptr != 0)
        rs_ptr.reset();
    rs_ptr = shared_ptr<Monomio>(new Monomio());
    Monomio& rs = *rs_ptr;
    if (!(this->esCero())&&!(m.esCero())){
        rs.coef = this->coef - m.coef;
        rs.expX = this->expX;
        rs.expY = this->expY;
    } else {
        if (this->esCero()){
            rs = m;
            rs.coef = -rs.coef;
        }
        else rs = *this;
    }   
    if (rs.coef == 0.0){
        rs.expX = 0;
        rs.expY = 0;
    }    
    return rs; // se usa atributo static
}

Monomio& Monomio::operator*(const Monomio& m) const{
    if (rs_ptr != 0)
        rs_ptr.reset();
    rs_ptr = shared_ptr<Monomio>(new Monomio());
    Monomio& rs = *rs_ptr;    
    rs.coef = this->coef * m.coef;
    rs.expX = this->expX + m.expX;
    rs.expY = this->expY + m.expY;
    if (rs.coef == 0.0){
        rs.expX = 0;
        rs.expY = 0;
    }  
    return rs; // se usa atributo static
}

Monomio& Monomio::operator/(const Monomio& m) const{
    if (rs_ptr != 0)
        rs_ptr.reset();
    rs_ptr = shared_ptr<Monomio>(new Monomio());
    Monomio& rs = *rs_ptr;    
    rs.coef = this->coef / m.coef;
    rs.expX = this->expX - m.expX;
    rs.expY = this->expY - m.expY;  
    if (rs.coef == 0.0){
        rs.expX = 0;
        rs.expY = 0;
    }     
    return rs; // se usa atributo static
}

void Monomio::asgCoef(double c){
    coef = c;
}

void Monomio::asgExpX(int ne){
    expX = ne;
}

void Monomio::asgExpY(int ne){
    expY = ne;
}

double Monomio::obtCoef() const{
    return coef;
}

int Monomio::obtExpX() const{
    return expX;
}

int Monomio::obtExpY() const{
    return expY;
}

bool Monomio::semejante(const Monomio & m) const{
    return (expX == m.expX) && (expY == m.expY);
}

bool Monomio::verInv(){
    
}

string Monomio::aHil(){
    stringstream rs;
    rs << coef << "x(" << expX << ")y(" << expY << ")";
    return rs.str();
}

bool Monomio::esCero() const{
    return (coef == 0);
}