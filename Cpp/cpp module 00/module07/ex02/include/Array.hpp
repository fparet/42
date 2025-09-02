// ************************************************************************** //
//                                                                            //
//                                 Array.hpp                                   //
//                         42 C++ Module 07 - ex02                            //
//                                                                            //
// ************************************************************************** //
#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <stdexcept>

template <typename T>
class Array {
public:
    // Coplien form
    Array() : _size(0), _data(0) {}
    Array(unsigned int n) : _size(n), _data(0) {
        if (_size) _data = new T[_size]();
    }
    Array(const Array& other) : _size(0), _data(0) {
        *this = other;
    }
    Array& operator=(const Array& other) {
        if (this != &other) {
            delete [] _data;
            _size = other._size;
            if (_size) {
                _data = new T[_size];
                for (unsigned int i = 0; i < _size; ++i) _data[i] = other._data[i];
            } else {
                _data = 0;
            }
        }
        return *this;
    }
    ~Array() { delete [] _data; }

    // Access
    T& operator[](unsigned int i) {
        if (i >= _size) throw std::out_of_range("Array index out of range");
        return _data[i];
    }
    const T& operator[](unsigned int i) const {
        if (i >= _size) throw std::out_of_range("Array index out of range");
        return _data[i];
    }

    unsigned int size() const { return _size; }

private:
    unsigned int _size;
    T*           _data;
};

#endif // ARRAY_HPP
