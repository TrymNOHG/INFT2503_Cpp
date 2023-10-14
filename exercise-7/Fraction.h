//
// Created by Trym Hamer Gudvangen on 10/8/23.
//

#ifndef EXERCISE_7_FRACTION_H
#define EXERCISE_7_FRACTION_H

#include <cstdio>
#include <sstream>

class Fraction {
public:
    int numerator{};
    int denominator{};

    Fraction();
    Fraction(int numerator, int denominator);
    void set(int numerator_, int denominator_ = 1);
    Fraction operator+(const Fraction &other) const;
    Fraction operator-(const Fraction &other) const;
    Fraction operator*(const Fraction &other) const;
    Fraction operator/(const Fraction &other) const;
    Fraction operator-() const;
    Fraction &operator++(); // Prefix
    Fraction operator++(int); // Postfix
    Fraction &operator--(); // Prefix
    Fraction operator--(int); // Postfix
    Fraction &operator+=(const Fraction &other);
    Fraction &operator-=(const Fraction &other);
    Fraction &operator*=(const Fraction &other);
    Fraction &operator/=(const Fraction &other);
    Fraction &operator=(const Fraction &other);
    Fraction operator-(int other) const;
    friend Fraction operator-(int other, const Fraction &fraction);
//    friend Fraction operator-(const Fraction &fraction, int other);
    bool operator==(const Fraction &other) const;
    bool operator!=(const Fraction &other) const;
    bool operator<=(const Fraction &other) const;
    bool operator>=(const Fraction &other) const;
    bool operator<(const Fraction &other) const;
    bool operator>(const Fraction &other) const;

    friend std::ostream &operator<<(std::ostream &out, const Fraction &fraction);


private:
    void reduce();
    int compare(const Fraction &other) const;
};


#endif //EXERCISE_7_FRACTION_H
