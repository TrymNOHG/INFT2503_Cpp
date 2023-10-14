//
// Created by Trym Hamer Gudvangen on 10/14/23.
//

#ifndef EXERCISE_7_SET_H
#define EXERCISE_7_SET_H

#include <cstdio>
#include <vector>
#include <sstream>

class Set {
public:
    std::vector<int> set;

    Set() {};
    Set(std::vector<int> &vector);
    Set operator+(Set &other_set);
    Set operator+(int other);
    Set operator=(const Set &other_set);
    friend std::ostream &operator<<(std::ostream &out, const Set set);

private:

    void reduce();

};


#endif //EXERCISE_7_SET_H
