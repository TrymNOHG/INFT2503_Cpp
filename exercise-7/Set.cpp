//
// Created by Trym Hamer Gudvangen on 10/14/23.
//

#include "Set.h"
#include <map>

Set::Set(std::vector<int> &vector) {
    this->set = vector;
    reduce();
}


Set Set::operator+(Set &other_set) {
    Set union_set = *this;
    bool unique = true;
    for(auto &other_elem : other_set.set) {
        unique = true;
        for(auto &elem : union_set.set){
            if (elem == other_elem) {
                unique = false;
                break;
            }
        }
        if (unique) {
            union_set.set.emplace_back(other_elem);
        }
    }
    return union_set;
}

Set Set::operator+(int other) {
    for (auto &elem : this->set) {
        if (elem == other) {
            return *this;
        }
    }
    this->set.emplace_back(other);
    return *this;
}

Set Set::operator=(const Set &other_set) {
    this->set = other_set.set;
    return *this;
}

std::ostream &operator<<(std::ostream &out, const Set set) {
    out << "{ ";
    for (auto &elem : set.set) {
        out << elem << " ";
    }
    out << '}';
    return out;
}


void Set::reduce() {
    std::vector<int> set_vec;
    std::map<int, int> unique_element;
    for(auto &element : this->set){
        if(unique_element[element] == 0) {
            set_vec.emplace_back(element);
            unique_element[element] = 1;
        }
    }
    this->set = set_vec;
}
