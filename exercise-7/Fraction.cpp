//
// Created by Trym Hamer Gudvangen on 10/8/23.
//

#include "Fraction.h"

#include <cmath>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

Fraction::Fraction() : numerator(0), denominator(1) {}

Fraction::Fraction(int numerator, int denominator) {
    set(numerator, denominator);
}

void Fraction::set(int numberator_, int denominator_) {
    if (denominator_ != 0) {
        numerator = numberator_;
        denominator = denominator_;
        reduce();
    } else {
        throw "Denominator is zero";
    }
}

Fraction Fraction::operator+(const Fraction &other) const {
    Fraction fraction = *this;
    fraction += other;
    return fraction;
}

Fraction &Fraction::operator+=(const Fraction &other) {
    set(numerator * other.denominator + denominator * other.numerator,
        denominator * other.denominator);
    return *this;
}

Fraction &Fraction::operator++() {
    numerator += denominator;
    return *this;
}

Fraction Fraction::operator++(int) { // postfix
    Fraction fraction;
    fraction = *this;
    ++(*this);
    return fraction;
}

Fraction Fraction::operator-(const Fraction &other) const {
    Fraction fraction = *this;
    fraction -= other;
    return fraction;
}

Fraction &Fraction::operator-=(const Fraction &other) {
    set(numerator * other.denominator - denominator * other.numerator,
        denominator * other.denominator);
    return *this;
}

Fraction &Fraction::operator--() {
    numerator -= denominator;
    return *this;
}

Fraction Fraction::operator--(int) {
    Fraction fraction;
    fraction = *this;
    --(*this);
    return fraction;
}

Fraction Fraction::operator-() const {
    Fraction fraction;
    fraction.numerator = -numerator;
    fraction.denominator = denominator;
    return fraction;
}

Fraction Fraction::operator*(const Fraction &other) const {
    Fraction fraction = *this;
    fraction *= other;
    return fraction;
}

Fraction &Fraction::operator*=(const Fraction &other) {
    set(numerator * other.numerator, denominator * other.denominator);
    return *this;
}

Fraction Fraction::operator/(const Fraction &other) const {
    Fraction fraction = *this;
    fraction /= other;
    return fraction;
}

Fraction &Fraction::operator/=(const Fraction &other) {
    set(numerator * other.denominator, denominator * other.numerator);
    return *this;
}

Fraction &Fraction::operator=(const Fraction &other) {
    numerator = other.numerator;
    denominator = other.denominator;
    return *this;
}

Fraction Fraction::operator-(int other) const {
    Fraction fraction(this->numerator - (other * this->denominator), this->denominator);
    return fraction;
}

Fraction operator-(int other, const Fraction &fraction) {
    Fraction final_fraction;
    final_fraction.numerator = (other * fraction.denominator) - fraction.numerator;
    final_fraction.denominator = fraction.denominator;
    return final_fraction;
}

//Fraction operator-(const Fraction &fraction, int other) {
//    Fraction final_fraction;
//    final_fraction.numerator = other * fraction.denominator - fraction.numerator;
//    final_fraction.denominator = fraction.denominator;
//    return final_fraction;
//}

bool Fraction::operator==(const Fraction &other) const {
    return (compare(other) == 0);
}

bool Fraction::operator!=(const Fraction &other) const {
    return (compare(other) != 0);
}

bool Fraction::operator<=(const Fraction &other) const {
    return (compare(other) <= 0);
}

bool Fraction::operator>=(const Fraction &other) const {
    return (compare(other) >= 0);
}

bool Fraction::operator<(const Fraction &other) const {
    return (compare(other) < 0);
}

bool Fraction::operator>(const Fraction &other) const {
    return (compare(other) > 0);
}

//-------------------------------------------------------------------
//
// Sørg for at nevneren alltid er positiv.
// Bruker Euclids algoritme for å finne fellesnevneren.
//
void Fraction::reduce() {
    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
    int a = numerator;
    int b = denominator;
    int c;
    if (a < 0)
        a = -a;

    while (b > 0) {
        c = a % b;
        a = b;
        b = c;
    }
    numerator /= a;
    denominator /= a;
}

//-------------------------------------------------------------------
//
// Returnerer +1 hvis *this > other, 0 hvis de er like, -1 ellers
//
int Fraction::compare(const Fraction &other) const {
    Fraction fraction = *this - other;
    if (fraction.numerator > 0)
        return 1;
    else if (fraction.numerator == 0)
        return 0;
    else
        return -1;
}

std::ostream &operator<<(ostream &out, const Fraction &fraction) {
    out << fraction.numerator << "/" << fraction.denominator;
    return out;
}
