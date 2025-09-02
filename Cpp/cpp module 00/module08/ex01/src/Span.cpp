// ************************************************************************** //
//                                                                            //
//                                 Span.cpp                                    //
//                         42 C++ Module 08 - ex01                            //
//                                                                            //
// ************************************************************************** //
#include "Span.hpp"
#include <algorithm>
#include <iostream>

Span::Span() : _capacity(0), _data() {}
Span::Span(unsigned int N) : _capacity(N), _data() { _data.reserve(N); }
Span::Span(const Span& other) : _capacity(other._capacity), _data(other._data) {}
Span& Span::operator=(const Span& other) {
    if (this != &other) { _capacity = other._capacity; _data = other._data; }
    return *this;
}
Span::~Span() {}

void Span::addNumber(int n) {
    if (_data.size() >= _capacity) throw std::runtime_error("Span is full");
    _data.push_back(n);
}

long Span::shortestSpan() const {
    if (_data.size() < 2) throw std::runtime_error("Not enough numbers to compute span");
    std::vector<int> tmp = _data;
    std::sort(tmp.begin(), tmp.end());
    long best = std::numeric_limits<long>::max();
    for (std::size_t i = 1; i < tmp.size(); ++i) {
        long diff = static_cast<long>(tmp[i]) - static_cast<long>(tmp[i-1]);
        if (diff < best) best = diff;
    }
    return best;
}

long Span::longestSpan() const {
    if (_data.size() < 2) throw std::runtime_error("Not enough numbers to compute span");
    std::vector<int>::const_iterator minIt = std::min_element(_data.begin(), _data.end());
    std::vector<int>::const_iterator maxIt = std::max_element(_data.begin(), _data.end());
    return static_cast<long>(*maxIt) - static_cast<long>(*minIt);
}
