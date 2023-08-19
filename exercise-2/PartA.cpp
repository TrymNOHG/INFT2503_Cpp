//
// Created by Trym Hamer Gudvangen on 8/16/23.
//

#include <iostream>

int main() {

    int i = 3;
    int j = 5;
    int *p = &i;
    int *q = &j;

    std::cout << "Value of i: " << i << "\n";
    std::cout << "Address of i: " << &i << "\n";

    std::cout << "Value of p: " << p << "\n";
    std::cout << "Address of p: " << &p << "\n";
    std::cout << "Value p is pointing to: " << *p << "\n" << std::endl;

    std::cout << "Value of j: " << j << "\n";
    std::cout << "Address of j: " << &j << "\n";

    std::cout << "Value of q: " << q << "\n";
    std::cout << "Address of q: " << &q << "\n";
    std::cout << "Value q is pointing to: " << *q << "\n";

    return 0;
}