//
// Created by Trym Hamer Gudvangen on 9/3/23.
//

#include <iostream>
#include <vector>
#include <algorithm>

bool num_exists(const std::vector<double> &vector, double val);
void print_element(const std::vector<double> &vector, double val);

int main() {

    std::vector<double> double_vector = {0.0, 1.1, 2.2, 4.0, 5.23};

    std::cout << "Front returns: " << double_vector.front() << "\n";
    std::cout << "End returns: " << double_vector.back() << "\n";

    double_vector.emplace(double_vector.begin(), -1.1);

    std::cout << "New front: " << double_vector.front() << "\n";

    print_element(double_vector, 5.0);
    print_element(double_vector, 5.23);


    return 0;
}

bool num_exists(const std::vector<double> &vector, double val) {
    return std::find(vector.begin(), vector.end(), val) != vector.end();
}

void print_element(const std::vector<double> &vector, double val) {
    if(num_exists(vector, val)) {
        std::cout << val << " was found!" << "\n";
    }
    else {
        std::cout << "Value " << val << " does not exist in the vector\n";
    }
}
