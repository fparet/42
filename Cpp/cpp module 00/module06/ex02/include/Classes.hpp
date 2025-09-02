// ************************************************************************** //
//                                                                            //
//                                Classes.hpp                                  //
//                         42 C++ Module 06 - ex02                            //
//                                                                            //
// ************************************************************************** //
#ifndef CLASSES_HPP
#define CLASSES_HPP

#include <iostream>

class Base {
public:
    virtual ~Base();
};

class A : public Base {
public:
    A();
    A(const A&);
    A& operator=(const A&);
    ~A();
};
class B : public Base {
public:
    B();
    B(const B&);
    B& operator=(const B&);
    ~B();
};
class C : public Base {
public:
    C();
    C(const C&);
    C& operator=(const C&);
    ~C();
};

Base* generate();
void identify(Base* p);
void identify(Base& p);

#endif // CLASSES_HPP
