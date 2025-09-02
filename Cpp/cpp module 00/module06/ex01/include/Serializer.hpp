// ************************************************************************** //
//                                                                            //
//                               Serializer.hpp                                //
//                         42 C++ Module 06 - ex01                            //
//                                                                            //
// ************************************************************************** //
#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <string>
#include <stdint.h>

struct Data {
    // plain data struct
    std::string name;
    int         value;
    double      score;

    Data();
    Data(const Data&);
    Data& operator=(const Data&);
    ~Data();
};

class Serializer {
public:
    static uintptr_t serialize(Data* ptr);
    static Data*     deserialize(uintptr_t raw);
private:
    Serializer();
    Serializer(const Serializer&);
    Serializer& operator=(const Serializer&);
    ~Serializer();
};

#endif // SERIALIZER_HPP
