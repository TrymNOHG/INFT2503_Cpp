//
// Created by Trym Hamer Gudvangen on 10/21/23.
//
#include <iomanip>
#include <string>
#include <iostream>

template<typename Type>
bool equal(Type a, Type b);

bool equal(double a, double b);

int main(){

    std::cout << "Int test\n";
    int a = 1;
    int b = 1;

    if (equal(a, b)) {
        std::cout << "a is equal to b!\n";
    } else {
        std::cout << "a is not equal to b\n";
    }

    std::cout << "\nString test\n";

    std::string c = "123";
    std::string d = "123";
    if (equal(c, d)) {
        std::cout << "c is equal to d!\n";
    } else {
        std::cout << "c is not equal to d\n";
    }


    std::cout << "\nDouble test\n";

    double e = 1.00001;
    double f = 1.00001;

    if (equal(e, f)) {
        std::cout << "e is equal to f!\n";
    } else {
        std::cout << "e is not equal to f\n";
    }

    return 0;
}

template<typename Type>
bool equal(Type a, Type b) {
    std::cout << "Function template is being used." << std::endl;
    return a == b;
}

bool equal(double a, double b){
    std::cout << "Special double function is being used." << std::endl;
    std::cout << std::setprecision(6);
    std::cout << a << " == " << b << "?\n";
    double tol = 0.00001;
    return abs(a - b) < tol;
}