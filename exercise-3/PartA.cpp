//
// Created by Trym Hamer Gudvangen on 8/16/23.
//

#include <iostream>

/*
 * Part A. Remove the errors from the code.
 */

const double pi = 3.141592;

class Circle {
public:
    explicit Circle(double radius_);
    int get_area() const;
    double get_circumference() const;

private:
    double radius;
};

// ==> Implementation of the Circle class

Circle::Circle(double radius_) : radius(radius_) {}

int Circle::get_area() const{
    return (int) (pi * radius * radius);
}

double Circle::get_circumference() const {
    double circumference = 2.0 * pi * radius;
    return circumference;
}

int main() {

    //Part 2.
    auto circle = Circle(5); //Could also explicitly use Circle data structure.

    int area = circle.get_area();
    std::cout << "Area of circle: " << area << "\n";

    double circumference = circle.get_circumference();
    std::cout << "Circumference of circle: " << circumference << "\n";

    return 0;
}

