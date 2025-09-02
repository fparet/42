// ************************************************************************** //
//                                                                            //
//                               easyfind.hpp                                  //
//                         42 C++ Module 08 - ex00                            //
//                                                                            //
// ************************************************************************** //
#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm> // std::find
#include <stdexcept>

// Non-const version: returns iterator to first occurrence of 'needle', or throws.
template <typename Container>
typename Container::iterator easyfind(Container& c, int needle) {
    typename Container::iterator it = std::find(c.begin(), c.end(), needle);
    if (it == c.end())
        throw std::runtime_error("easyfind: value not found");
    return it;
}

// Const version
template <typename Container>
typename Container::const_iterator easyfind(Container const& c, int needle) {
    typename Container::const_iterator it = std::find(c.begin(), c.end(), needle);
    if (it == c.end())
        throw std::runtime_error("easyfind: value not found");
    return it;
}

#endif // EASYFIND_HPP
