//
// Created by Trym Hamer Gudvangen on 8/20/23.
//
#include <iostream>

int find_sum(const int *table, int length);

int main() {

    double number;
    double &numberRef = number;

    // 1. Directly change number
    number = 6;

    //2. Change the reference
    numberRef = 5;

    //3. Make number variable point to different address.
    double *ptr = &numberRef;
    *ptr = 3;


    // Part 6.
    int table[20];

    for(int i = 0; i < 20; i++) {
        table[i] = i + 1;
    }

    std::cout << "The sum of the first ten values: " << find_sum(&table[0], 10) << "\n";
    std::cout << "The sum of the next five values: " << find_sum(&table[10], 5) << "\n";
    std::cout << "The sum of the last five values: " << find_sum(&table[15], 5) << std::endl;



    return 0;
}

int find_sum(const int *table, int length) {
    int sum = 0;
    for(int i = 0; i < length; i++) {
        sum += *table;
        table++;
    }
    return sum;
}
