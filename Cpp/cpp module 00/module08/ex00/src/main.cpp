// ************************************************************************** //
//                                                                            //
//                                 main.cpp                                    //
//                         42 C++ Module 08 - ex00                            //
//                                                                            //
// ************************************************************************** //
#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

template <typename It>
static int indexOf(It begin, It it) {
    int idx = 0;
    for (It cur = begin; cur != it; ++cur) ++idx;
    return idx;
}

int main() {
    std::vector<int> v;
    for (int i = 0; i < 10; ++i) v.push_back(i * 2); // 0,2,4,...,18

    try {
        std::vector<int>::iterator it = easyfind(v, 6);
        std::cout << "Found 6 in vector at index " << indexOf(v.begin(), it) << std::endl;
    } catch (std::exception& e) {
        std::cout << "Vector: " << e.what() << std::endl;
    }

    try {
        easyfind(v, 7);
    } catch (std::exception& e) {
        std::cout << "Vector: " << e.what() << std::endl;
    }

    const std::list<int> lst = (std::list<int>()) ;
    std::list<int> l;
    l.push_back(42); l.push_back(10); l.push_back(42);
    try {
        std::list<int>::iterator it2 = easyfind(l, 42);
        std::cout << "Found 42 in list (first occurrence)." << std::endl;
        (void)it2;
    } catch (std::exception& e) {
        std::cout << "List: " << e.what() << std::endl;
    }

    return 0;
}
