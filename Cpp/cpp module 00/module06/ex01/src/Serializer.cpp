// ************************************************************************** //
//                                                                            //
//                               Serializer.cpp                                //
//                         42 C++ Module 06 - ex01                            //
//                                                                            //
// ************************************************************************** //
#include "Serializer.hpp"

Data::Data() : name(""), value(0), score(0.0) {}
Data::Data(const Data& other) : name(other.name), value(other.value), score(other.score) {}
Data& Data::operator=(const Data& other) { if (this != &other) { name = other.name; value = other.value; score = other.score; } return *this; }
Data::~Data() {}

Serializer::Serializer() {}
Serializer::Serializer(const Serializer&) {}
Serializer& Serializer::operator=(const Serializer&) { return *this; }
Serializer::~Serializer() {}

uintptr_t Serializer::serialize(Data* ptr) { return reinterpret_cast<uintptr_t>(ptr); }
Data*     Serializer::deserialize(uintptr_t raw) { return reinterpret_cast<Data*>(raw); }
