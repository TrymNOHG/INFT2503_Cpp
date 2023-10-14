//
// Created by Trym Hamer Gudvangen on 10/14/23.
//

#include "Set.cpp"
#include <vector>
#include <cstdio>
#include <iostream>

/**
 * Exercise 2.
 * @return
 */
int main() {

    std::vector<int> vec = {1, 4, 3};
    std::vector<int> vec2 = {4, 7};
    Set set(vec);
    Set set2(vec2);

    std::cout << set << std::endl;
    std::cout << set2 << std::endl;

    std::cout << (set + set2) << std::endl;

    set = set2;
    std::cout << set << std::endl;

    return 0;
}