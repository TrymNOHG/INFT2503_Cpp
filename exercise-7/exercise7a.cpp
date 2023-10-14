//
// Created by Trym Hamer Gudvangen on 10/8/23.
//

#include "Fraction.cpp"
#include <iostream>

/**
 * Exercise 1.
 * b).
 * Explain how 5 - 3 - fraction - 7 - fraction works.
 *
 * In the expression above, the different variables are chained together using the operator- with pre-defiend
 * association rules and return type. Since all of the operators are subtraction, the expression is evaluated from
 * right to left. First int operator-(int) is used to evalute 5 - 3. 5.operator-(3) becomes the int value 2. From there,
 * 2 - fraction is evaluated using the Fraction operator-(int other, const Fraction &fraction): operator-(2, fraction).
 * This equation returns a Fraction object which is then used in the next evaluation. The resultant_fraction - 7
 * is evaluated using Fraction operator-(int): resultant_fraction.operator-(7). Finally a similar evaluation as before
 * Fraction operator-(int other, const Fraction &fraction) is performed.
 *
 * @return
 */
int main() {
    Fraction fraction(5, 6);


    Fraction newFraction = fraction - 5;
    std::cout << newFraction << std::endl;

    newFraction = 5 - fraction;
    std::cout << newFraction << std::endl;

    newFraction = 5 - 3 - fraction - 7 - fraction;
    std::cout << newFraction << std::endl;

}