/* 
 * File:   newsimpletest.cpp
 * Author: b41624, b12244
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
    string standar = "0.00X(0)Y(0)"; 
    if (polinomio.aHil() != standar)  
    {
        std::cout << "%TEST_FAILED% time=0 testname=testPolinomio (newsimpletest) fallo monomio 0" << std::endl;
    }
}


void testPolinomio2() {
    Polinomio orig;
    Polinomio polinomio(orig);
    string standar = "0.00X(0)Y(0)"; 
    string h = polinomio.aHil();
    if (h != standar) {
        std::cout << "%TEST_FAILED% time=0 testname=testPolinomio2 (newsimpletest) message=Fallo reporte 0.00X(0)Y(0)" << std::endl;
    }
    Polinomio orig2;
    Polinomio polinomio2(orig2);
    string standar2 = "5.33X(4)Y(2)+7.43X(4)Y(1)";
    string h2 = polinomio2.aHil();
    if (h2 != standar2) {
        std::cout << "%TEST_FAILED% time=0 testname=testPolinomio2 (newsimpletest) message=Fallo reporte 5.33X(4)Y(2)+7.43X(4)Y(1)" << std::endl;
    } 
    
}

void testPolinomio3() {
    string expoli = "0.0";
    string expoli2 = "0X(0)Y(0)" ; 
    string expoli3 = "0.00X(0)Y(0)" ;  
    string expoli4 = "0.00X(3)Y(2)+0X(2)Y(1)+0X(0)Y(0)"; 
    string expoli5 = "0X(5)Y(4)+0.00X(3)Y(2)+2.55X(0)Y(0)";  
    string expoli6 =  "0X(5)Y(4)+2.5X(0)Y(0)" ;  
    string expoli7 =  "6X(5)Y(3)+3X(3)Y(2)+5X(1)Y(1)+3X(0)Y(1)+4X(0)Y(0)"; 
    string expoli8 = "7.5X(5)Y(3)+3.2X(3)Y(2)+5.0X(1)Y(0)+4.2X(0)Y(0)";  
    string expoli9 = "1.5X(0)Y(2)-3X(2)Y(1)"; 
    string expoli10 = "3.2X(3)Y(2)+7.5X(5)Y(3)+5.0X(1)Y(0)+4.2+7.5X(5)Y(3)";  
    string expoli11 = "7.5X(5)Y(3)-2.5X(5)Y(3)+5.0X(1)Y(0)-3.2X(3)Y(2)-4.2+7.5X(5)Y(3)";  
    string expoli12 =  "+4X(0)Y(0)-6X(5)Y(3)+5X(3)Y(2)-3X(0)Y(1)-3X(3)Y(2)";       
    Polinomio polinomio(expoli);
    Polinomio polinomio2(expoli2);
    Polinomio polinomio3(expoli3);
    Polinomio polinomio4(expoli4);
    Polinomio polinomio5(expoli5);
    Polinomio polinomio6(expoli6);
    Polinomio polinomio7(expoli7);
    Polinomio polinomio8(expoli8);
    Polinomio polinomio9(expoli9);
    Polinomio polinomio10(expoli10);
    Polinomio polinomio11(expoli11);
    Polinomio polinomio12(expoli12);
    //polinomio.aHil();    
    if (polinomio.aHil() != "0.00X(0)Y(0)") 
        std::cout << "%TEST_FAILED% time=0 testname=testPolinomio3 (newsimpletest) message=Fallo reporte 0.00X(0)Y(0)" << std::endl;   
    if (polinomio2.aHil() != "0.00X(0)Y(0)") 
        std::cout << "%TEST_FAILED% time=0 testname=testPolinomio3 (newsimpletest) message=Fallo reporte 0.00X(0)Y(0)" << std::endl;    
     if (polinomio3.aHil() != "0.00X(0)Y(0)") 
        std::cout << "%TEST_FAILED% time=0 testname=testPolinomio3 (newsimpletest) message=Fallo reporte 0.00X(0)Y(0)" << std::endl;   
    if (polinomio4.aHil() != "0.00X(0)Y(0)") 
        std::cout << "%TEST_FAILED% time=0 testname=testPolinomio3 (newsimpletest) message=Fallo reporte 0.00X(0)Y(0)" << std::endl;    
     if (polinomio5.aHil() !=  "2.50X(0)Y(0)") 
        std::cout << "%TEST_FAILED% time=0 testname=testPolinomio3 (newsimpletest) message=Fallo reporte 2.50X(0)Y(0)" << std::endl;   
    if (polinomio6.aHil() != "2.50X(0)Y(0)") 
        std::cout << "%TEST_FAILED% time=0 testname=testPolinomio3 (newsimpletest) message=Fallo reporte 2.50X(0)Y(0)" << std::endl;    
     if (polinomio7.aHil() != "6.00X(5)Y(3)+3.00X(3)Y(2)+5.00X(1)Y(1)+3.00X(0)Y(1)+4.00X(0)Y(0)") 
        std::cout << "%TEST_FAILED% time=0 testname=testPolinomio3 (newsimpletest) message=Fallo reporte 6.00X(5)Y(3)+3.00X(3)Y(2)+5.00X(1)Y(1)+3.00X(0)Y(1)+4.00X(0)Y(0)" << std::endl;   
    if (polinomio8.aHil() != "7.50X(5)Y(3)+3.20X(3)Y(2)+5.00X(1)Y(0)+4.20X(0)Y(0)") 
        std::cout << "%TEST_FAILED% time=0 testname=testPolinomio3 (newsimpletest) message=Fallo reporte 7.50X(5)Y(3)+3.20X(3)Y(2)+5.00X(1)Y(0)+4.20X(0)Y(0)" << std::endl;    
     if (polinomio9.aHil() != "-3.00X(2)Y(1)+1.50X(0)Y(2)") 
        std::cout << "%TEST_FAILED% time=0 testname=testPolinomio3 (newsimpletest) message=Fallo reporte -3.00X(2)Y(1)+1.50X(0)Y(2)" << std::endl;   
    if (polinomio10.aHil() != "7.50X(5)Y(3)+7.50X(5)Y(3)+3.20X(3)Y(2)+5.00X(1)Y(0)+4.20") 
        std::cout << "%TEST_FAILED% time=0 testname=testPolinomio3 (newsimpletest) message=Fallo reporte 7.50X(5)Y(3)+7.50X(5)Y(3)+3.20X(3)Y(2)+5.00X(1)Y(0)+4.20" << std::endl;    
     if (polinomio11.aHil() != "7.50X(5)Y(3)-2.50X(5)Y(3)+5.00X(1)Y(0)-3.2X(3)Y(2)-4.20+7.50X(5)Y(3)") 
        std::cout << "%TEST_FAILED% time=0 testname=testPolinomio3 (newsimpletest) message=Fallo reporte 7.50X(5)Y(3)-2.50X(5)Y(3)+5.00X(1)Y(0)-3.2X(3)Y(2)-4.20+7.50X(5)Y(3)" << std::endl;   
    if (polinomio12.aHil() != "-6.00X(5)Y(3)+5.00X(3)Y(2)-3.00X(3)Y(2)-3.00X(0)Y(1)+4.00X(0)Y(0)") 
        std::cout << "%TEST_FAILED% time=0 testname=testPolinomio3 (newsimpletest) message=Fallo reporte -6.00X(5)Y(3)+5.00X(3)Y(2)-3.00X(3)Y(2)-3.00X(0)Y(1)+4.00X(0)Y(0)" << std::endl;    
}


void testEval() {
    double x;
    double y;
    Polinomio polinomio;
    double result = polinomio.eval(x, y);
    if (true ) {
        std::cout << "%TEST_FAILED% time=0 testname=testEval (newsimpletest) message=error message sample" << std::endl;
    }
}

void testVerGrado() {
    Polinomio polinomio;
    int result = polinomio.verGrado();
    if (true ) {
        std::cout << "%TEST_FAILED% time=0 testname=testVerGrado (newsimpletest) message=error message sample" << std::endl;
    }
}

void testVerInv() {
    Polinomio polinomio;
    bool result = polinomio.verInv();
    if (true ) {
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

