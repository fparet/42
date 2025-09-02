// ************************************************************************** //
//                                                                            //
//                                 Span.hpp                                    //
//                         42 C++ Module 08 - ex01                            //
//                                                                            //
// ************************************************************************** //
#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>
#include <algorithm>
#include <limits>

class Span {
public:
    // Coplien form
    Span();
    Span(const Span& other);
    Span& operator=(const Span&);
    ~Span();

    // Custom
    explicit Span(unsigned int N);

    // Methods
    void addNumber(int n);

    template <typename InputIt>
    void addNumber(InputIt first, InputIt last) {
        for (; first != last; ++first) {
            if (_data.size() >= _capacity) throw std::runtime_error("Span is full");
            _data.push_back(*first);
        }
    }

    long shortestSpan() const;
    long longestSpan() const;

    unsigned int size() const { return static_cast<unsigned int>(_data.size()); }
    unsigned int capacity() const { return _capacity; }

private:
    unsigned int   _capacity;
    std::vector<int> _data;
};

#endif // SPAN_HPP
