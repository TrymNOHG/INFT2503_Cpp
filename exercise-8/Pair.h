//
// Created by Trym Hamer Gudvangen on 10/21/23.
//

#ifndef EXERCISE_8_PAIR_H
#define EXERCISE_8_PAIR_H

#include <ostream>

template<typename Type1, typename Type2>
class Pair {
public:
    Type1 first;
    Type2 second;

    Pair(Type1 _first, Type2 _second) : first(_first), second(_second) {};

    int get_size() const;

    Pair operator+(const Pair &other);

    bool operator>(const Pair &other) const;

    friend std::ostream &operator<<(std::ostream &os, const Pair &pair) {
        return os << "(" << pair.first << ", " << pair.second << ")";
    }
};


#endif //EXERCISE_8_PAIR_H
