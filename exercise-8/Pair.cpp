//
// Created by Trym Hamer Gudvangen on 10/21/23.
//

#include "Pair.h"

template<typename Type1, typename Type2>
int Pair<Type1, Type2>::get_size() const{
    return this->first + this->second;
}

template<typename Type1, typename Type2>
Pair<Type1, Type2> Pair<Type1, Type2>::operator+(const Pair<Type1, Type2> &other) {
    Pair pair = *this;
    pair.first += other.first;
    pair.second += other.second;
    return pair;
}

template<typename Type1, typename Type2>
bool Pair<Type1, Type2>::operator>(const Pair &other) const{
    return this->get_size() > other.get_size();
}