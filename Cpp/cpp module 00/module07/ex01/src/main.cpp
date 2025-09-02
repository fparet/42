// ************************************************************************** //
//                                                                            //
//                                 main.cpp                                    //
//                         42 C++ Module 07 - ex01                            //
//                                                                            //
// ************************************************************************** //
#include "iter.hpp"
#include <iostream>
#include <string>

template <typename T>
void print_elem(T const & x) { std::cout << x << " "; }

template <typename T>
void plus_one(T & x) { ++x; }

void to_upper(std::string & s) {
    for (std::size_t i = 0; i < s.size(); ++i) {
        if (s[i] >= 'a' && s[i] <= 'z') s[i] = static_cast<char>(s[i] - 'a' + 'A');
    }
}

int main() {
    int ai[5] = {1,2,3,4,5};
    ::iter(ai, 5, plus_one<int>);
    ::iter(ai, 5, print_elem<int>);
    std::cout << std::endl;

    const int ci[4] = {10, 20, 30, 40};
    ::iter(ci, 4, print_elem<int>);
    std::cout << std::endl;

    std::string as[3] = {"hello", "world", "iter"};
    ::iter(as, 3, to_upper);
    ::iter(as, 3, print_elem<std::string>);
    std::cout << std::endl;

    char ac[4] = {'a','b','c','d'};
    ::iter(ac, 4, plus_one<char>);
    ::iter(ac, 4, print_elem<char>);
    std::cout << std::endl;

    return 0;
}
