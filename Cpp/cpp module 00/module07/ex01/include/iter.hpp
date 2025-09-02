// ************************************************************************** //
//                                                                            //
//                                 iter.hpp                                    //
//                         42 C++ Module 07 - ex01                            //
//                                                                            //
// ************************************************************************** //
#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef> // size_t

template <typename T>
void iter(T* array, std::size_t length, void (*f)(T&)) {
    if (!array || !f) return;
    for (std::size_t i = 0; i < length; ++i) f(array[i]);
}

template <typename T>
void iter(T const* array, std::size_t length, void (*f)(T const&)) {
    if (!array || !f) return;
    for (std::size_t i = 0; i < length; ++i) f(array[i]);
}

#endif // ITER_HPP
