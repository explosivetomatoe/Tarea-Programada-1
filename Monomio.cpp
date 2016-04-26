#include "Monomio.h"

shared_ptr<Monomio> Monomio::rs_ptr = 0;

Monomio::Monomio() : coef(0.0), expX(0), expY(0) {
}

Monomio::Monomio(const Monomio& orig) : coef(orig.coef), expX(orig.expX), expY(orig.expY) {

}

Monomio::~Monomio() {
}

Monomio::Monomio(const string& expmono) {
    string sCoef = "";
    string sExpX = "";
    string sExpY = "";
    int cntExpRgl = 7;
    string hExpRgl[] = {"\\-?[xX]|\\-?[yY]|\\-?[xX][yY]", // 0 -> no coef no exps
        "\\-?[xX]\\(\\d+\\)|\\-?[yY]\\(\\d+\\)|\\-?[xX]\\(\\d+\\)[yY]|\\-?[xX][yY]\\(\\d+\\)", // 1 -> no coef un exp 
        "\\-?[xX]\\(\\d+\\)[yY]\\(\\d+\\)", // 2 -> no coef dos exps
        "\\-?\\d+|\\-?\\d+\\.\\d+", // 3 -> coef no x, no y, no exps
        "\\-?\\d+[xX]|\\-?\\d+[yY]|\\-?\\d+\\.\\d+[xX]|\\-?\\d+\\.\\d+[yY]|\\-?\\d+[xX][yY]|\\-?\\d+[xX][yY]|\\-?\\d+\\.\\d+[xX][yY]|\\-?\\d+\\.\\d+[xX][yY]", // 4 -> coef no exps
        "\\-?\\d+[xX]\\(\\d+\\)|\\-?\\d+\\.\\d+[xX]\\(\\d+\\)|\\-?\\d+[yY]\\(\\d+\\)|\\-?\\d+\\.\\d+[yY]\\(\\d+\\)|\\-?\\d+[xX]\\(\\d+\\)[yY]|\\-?\\d+\\.\\d+[xX]\\(\\d+\\)[yY]|\\-?\\d+[xX][yY]\\(\\d+\\)|\\-?\\d+\\.\\d+[xX][yY]\\(\\d+\\)", // 5 -> coef un exp
        "\\-?\\d+[xX]\\(\\d+\\)[yY]\\(\\d+\\)|\\-?\\d+\\.\\d+[xX]\\(\\d+\\)[yY]\\(\\d+\\)"}; // 6 -> coef dos exps
    regex expRgl[cntExpRgl];

    for (int i = 0; i < cntExpRgl; i++) // se inicializa arreglo de expresiones regulares
        expRgl[i].assign(hExpRgl[i]);

    for (int i = 0; i < cntExpRgl; i++) { // se identifica la expresión regular que aplica para procesar la hilera
        if (regex_match(expmono, expRgl[i]))
            switch (i) {
                case 0: // 0 -> no coef no exps
                {
                    if (expmono[0] == '-')
                        sCoef = "-1.0";
                    else sCoef = "1.0";
                    regex expRegDosLetras("\\-?[xX][yY]");
                    if (regex_match(expmono, expRegDosLetras)) {
                        sExpX = "1";
                        sExpY = "1";
                    } else if (expmono.find('x') != string::npos || expmono.find('X') != string::npos) {
                        sExpX = "1";
                        sExpY = "0";
                    } else if (expmono.find('y') != string::npos || expmono.find('Y') != string::npos) {
                        sExpX = "0";
                        sExpY = "1";
                    }
                    break;
                }
                case 1: // 1 -> no coef un exp
                {
                    if (expmono[0] == '-')
                        sCoef = "-1.0";
                    else sCoef = "1.0";
                    regex expRegDosLetras("\\-?[xX]\\(\\d+\\)[yY]|\\-?[xX][yY]\\(\\d+\\)");
                    if (regex_match(expmono, expRegDosLetras))
                        if (expmono.find("x(") != string::npos || expmono.find("X(") != string::npos) {
                            sExpX = extraerExp('x', 'X', expmono);
                            sExpY = "1";
                        } else {
                            sExpX = "1";
                            sExpY = extraerExp('y', 'Y', expmono);
                        } else if (expmono.find("x(") != string::npos || expmono.find("X(") != string::npos) {
                        sExpX = extraerExp('x', 'X', expmono);
                        sExpY = "0";
                    } else {
                        sExpX = "0";
                        sExpY = extraerExp('y', 'Y', expmono) + ")";
                    }
                    break;
                }
                case 2: // 2 -> no coef dos exps
                    if (expmono[0] == '-')
                        sCoef = "-1.0";
                    else sCoef = "1.0";
                    sExpX = extraerExp('x', 'X', expmono);
                    sExpY = extraerExp('y', 'Y', expmono);
                    break;
                case 3: // 3 -> coef no x, no y, no exps
                    sCoef = extraerCoef(expmono);
                    sExpX = "0";
                    sExpY = "0";
                    break;
                case 4: // 4 -> coef no exps
                {
                    sCoef = extraerCoef(expmono);
                    regex expRegDosLetras("\\-?\\d+[xX][yY]|\\-?\\d+[xX][yY]|\\-?\\d+\\.\\d+[xX][yY]|\\-?\\d+\\.\\d+[xX][yY]");
                    if (regex_match(expmono, expRegDosLetras)) {
                        sExpX = "1";
                        sExpY = "1";
                    } else if (expmono.find('x') != string::npos || expmono.find('X') != string::npos) {
                        sExpX = "1";
                        sExpY = "0";
                    } else if (expmono.find('y') != string::npos || expmono.find('Y') != string::npos) {
                        sExpX = "0";
                        sExpY = "1";
                    }
                    break;
                }
                case 5: // 5 -> coef un exp
                {
                    sCoef = extraerCoef(expmono);
                    regex expRegDosLetras("\\-?\\d+[xX]\\(\\d+\\)[yY]|\\-?\\d+\\.\\d+[xX]\\(\\d+\\)[yY]|\\-?\\d+[xX][yY]\\(\\d+\\)|\\-?\\d+\\.\\d+[xX][yY]\\(\\d+\\)");
                    if (regex_match(expmono, expRegDosLetras))
                        if (expmono.find("x(") != string::npos || expmono.find("X(") != string::npos) {
                            sExpX = extraerExp('x', 'X', expmono);
                            sExpY = "1";
                        } else {
                            sExpX = "1";
                            sExpY = extraerExp('y', 'Y', expmono);
                        } else if (expmono.find("x(") != string::npos || expmono.find("X(") != string::npos) {
                        sExpX = extraerExp('x', 'X', expmono);
                        sExpY = "0";
                    } else {
                        sExpX = "0";
                        sExpY = extraerExp('y', 'Y', expmono) + ")";
                    }
                    break;
                }
                case 6: // 6 -> coef dos exps
                    sCoef = extraerCoef(expmono);
                    sExpX = extraerExp('x', 'X', expmono);
                    sExpY = extraerExp('y', 'Y', expmono);
                    break;
                default:
                    /* cout << "EXPRESIÓN DE MONOMIO ERRÓNEA" << endl */;
            }
    };

    coef = atof(sCoef.c_str());
    expX = atoi(sExpX.c_str());
    expY = atoi(sExpY.c_str());

    if (coef == 0.0) {
        expX = 0;
        expY = 0;
    }
}

Monomio& Monomio::operator+(const Monomio& m) const {
    if (rs_ptr != 0)
        rs_ptr.reset();
    rs_ptr = shared_ptr<Monomio>(new Monomio());
    Monomio& rs = *rs_ptr;
    if (!(this->esCero())&&!(m.esCero())) {
        rs.coef = this->coef + m.coef;
        rs.expX = this->expX;
        rs.expY = this->expY;
    } else {
        if (this->esCero())
            rs = m;
        else rs = *this;
    }
    if (rs.coef == 0.0) {
        rs.expX = 0;
        rs.expY = 0;
    }
    return rs; // se usa atributo static
}

Monomio& Monomio::operator-(const Monomio& m) const {
    if (rs_ptr != 0)
        rs_ptr.reset();
    rs_ptr = shared_ptr<Monomio>(new Monomio());
    Monomio& rs = *rs_ptr;
    if (!(this->esCero())&&!(m.esCero())) {
        rs.coef = this->coef - m.coef;
        rs.expX = this->expX;
        rs.expY = this->expY;
    } else {
        if (this->esCero()) {
            rs = m;
            rs.coef = -rs.coef;
        } else rs = *this;
    }
    if (rs.coef == 0.0) {
        rs.expX = 0;
        rs.expY = 0;
    }
    return rs; // se usa atributo static
}

Monomio& Monomio::operator*(const Monomio& m) const {
    if (rs_ptr != 0)
        rs_ptr.reset();
    rs_ptr = shared_ptr<Monomio>(new Monomio());
    Monomio& rs = *rs_ptr;
    rs.coef = this->coef * m.coef;
    rs.expX = this->expX + m.expX;
    rs.expY = this->expY + m.expY;
    if (rs.coef == 0.0) {
        rs.expX = 0;
        rs.expY = 0;
    }
    return rs; // se usa atributo static
}

Monomio& Monomio::operator/(const Monomio& m) const {
    if (rs_ptr != 0)
        rs_ptr.reset();
    rs_ptr = shared_ptr<Monomio>(new Monomio());
    Monomio& rs = *rs_ptr;
    rs.coef = this->coef / m.coef;
    rs.expX = this->expX - m.expX;
    rs.expY = this->expY - m.expY;
    if (rs.coef == 0.0) {
        rs.expX = 0;
        rs.expY = 0;
    }
    return rs; // se usa atributo static
}

void Monomio::asgCoef(double c) {
    coef = c;
}

void Monomio::asgExpX(int ne) {
    expX = ne;
}

void Monomio::asgExpY(int ne) {
    expY = ne;
}

double Monomio::obtCoef() const {
    return coef;
}

int Monomio::obtExpX() const {
    return expX;
}

int Monomio::obtExpY() const {
    return expY;
}

bool Monomio::semejante(const Monomio & m) const {
    return (expX == m.expX) && (expY == m.expY);
}

bool Monomio::verInv() {
    bool rs = true;
    if (coef == 0)
        rs = (expX == 0) && (expY == 0);
    return rs;
}

string Monomio::aHil() {
    stringstream rs;
    rs << std::setprecision(2) << std::fixed << coef << "X(" << expX << ")Y(" << expY << ")";
    return rs.str();
}

bool Monomio::esCero() const {
    return (coef == 0);
}

string Monomio::extraerExp(char min, char may, string b) {
    string rs;
    int pLetra = b.find(min);
    int pExpIni = 0;
    int pExpFnl = 0;
    if (pLetra == string::npos) {
        pLetra = b.find(may);
    };
    pExpIni = pLetra + 2; // +1 es el (, +2 es el primer dígito del exponente
    pExpFnl = pLetra + 2; // posición del primer caracter del exponente
    while (b[pExpFnl] != ')') pExpFnl++;
    rs = b.substr(pExpIni, pExpFnl - pExpIni); // se extraen los dígitos del expo
    return rs;
}

string Monomio::extraerCoef(string b) {
    string rs;
    int pCoefIni = 0;
    int pCoefFnl = 0;
    while (b[pCoefFnl] != 'x' && b[pCoefFnl] != 'X' && b[pCoefFnl] != 'y' && b[pCoefFnl] != 'Y') pCoefFnl++;
    rs = b.substr(pCoefIni, pCoefFnl - pCoefIni);
    return rs;
}