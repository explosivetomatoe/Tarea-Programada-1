/* 
 * File:   newsimpletest.cpp
 * Author: b41624
 *
 * Created on 07/04/2016, 05:46:42 PM
 */

#include <stdlib.h>
#include <iostream>
#include "Polinomio.h"
#include "ConstructorPolinomio.h"

/*
 * Simple C++ Test Suite
 */

void testPolinomio() {
    Polinomio polinomio();
    string standar = "0.0X(0)Y(0)";
    string m= ""
    string h1 = "0.0"; //polinomio.aHil();  
    string    
    int i = 0;
    bool limit = false;
    int ctr = 0;
    for(ctr=1;ctr<=5; ctr++)
    {
        if (ctr == 1)
                m =h1;
        else if (ctr == 1)
                m =h2;
        else if (ctr == 1)
                m =h3;
        else if (ctr == 1)
                m =h4;
        else if (ctr == 1)
                m =h5;                
        while ((m[i] != 'X') && (m[i] == '0' || (m[i] == '.'))) 
        {
            i++;
        }
    }
    if (i == m.length()) 
    {
        limit = true;
    }
    if (limit) 
    {
        std::cout << standar << std::endl;
    } 
    else 
    {
        std::cout << "%TEST_FAILED% time=0 testname=testPolinomio (newsimpletest) fallo monomio 0" << std::endl;
    }
}


void testPolinomio2() {
    const Polinomio& orig;
    Polinomio polinomio(orig);
    string h = polinomio.aHil();
    if (h != "{}") {
        std::cout << "%TEST_FAILED% time=0 testname=testPolinomio2 (newsimpletest) message=error message sample" << std::endl;
    }
}
/*
void testPolinomio3() {
    const string& expoli;
    Polinomio polinomio(expoli);
    string str = polinomio.aHil();    
    if (str[1] == 0) {
        std::cout << "%TEST_FAILED% time=0 testname=testPolinomio3 (newsimpletest) message=error message sample" << std::endl;
    }
}*/

void testAHil() {
    Polinomio polinomio;
    string result = polinomio.aHil();
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testAHil (newsimpletest) message=error message sample" << std::endl;
    }
}

void testEval() {
    double x;
    double y;
    Polinomio polinomio;
    double result = polinomio.eval(x, y);
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testEval (newsimpletest) message=error message sample" << std::endl;
    }
}

void testVerGrado() {
    Polinomio polinomio;
    int result = polinomio.verGrado();
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testVerGrado (newsimpletest) message=error message sample" << std::endl;
    }
}

void testVerInv() {
    Polinomio polinomio;
    bool result = polinomio.verInv();
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testVerInv (newsimpletest) message=error message sample" << std::endl;
    }
}

int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% newsimpletest" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% testPolinomio (newsimpletest)" << std::endl;
    testPolinomio();
    std::cout << "%TEST_FINISHED% time=0 testPolinomio (newsimpletest)" << std::endl;
    /* 
     std::cout << "%TEST_STARTED% testPolinomio3 (newsimpletest)" << std::endl;
     testPolinomio3();
     std::cout << "%TEST_FINISHED% time=0 testPolinomio3 (newsimpletest)" << std::endl;
*/
     std::cout << "%TEST_STARTED% testPolinomio2 (newsimpletest)" << std::endl;
     testPolinomio2();
     std::cout << "%TEST_FINISHED% time=0 testPolinomio2 (newsimpletest)" << std::endl;
     /*
    
    std::cout << "%TEST_STARTED% testAHil (newsimpletest)" << std::endl;
    testAHil();
    std::cout << "%TEST_FINISHED% time=0 testAHil (newsimpletest)" << std::endl;

    std::cout << "%TEST_STARTED% testEval (newsimpletest)" << std::endl;
    testEval();
    std::cout << "%TEST_FINISHED% time=0 testEval (newsimpletest)" << std::endl;

    std::cout << "%TEST_STARTED% testVerGrado (newsimpletest)" << std::endl;
    testVerGrado();
    std::cout << "%TEST_FINISHED% time=0 testVerGrado (newsimpletest)" << std::endl;

    std::cout << "%TEST_STARTED% testVerInv (newsimpletest)" << std::endl;
    testVerInv();
    std::cout << "%TEST_FINISHED% time=0 testVerInv (newsimpletest)" << std::endl;

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;
 */
    return (EXIT_SUCCESS);
}

