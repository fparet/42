// ************************************************************************** //
//                                                                            //
//                                   main.cpp                                  //
//                         42 C++ Module 06 - ex01                            //
//                                                                            //
// ************************************************************************** //
#include "Serializer.hpp"
#include <iostream>

int main() {
    Data d;
    d.name = "alice";
    d.value = 42;
    d.score = 3.14;

    uintptr_t raw = Serializer::serialize(&d);
    Data* back = Serializer::deserialize(raw);

    std::cout << "Original: " << &d << " -> {name=" << d.name << ", value=" << d.value << ", score=" << d.score << "}" << std::endl;
    std::cout << "Back ptr: " << back << " -> {name=" << back->name << ", value=" << back->value << ", score=" << back->score << "}" << std::endl;

    // check that it's the same address
    std::cout << "Same address? " << (back == &d ? "yes" : "no") << std::endl;
    return 0;
}
