// ************************************************************************** //
//                                                                            //
//                                Classes.cpp                                  //
//                         42 C++ Module 06 - ex02                            //
//                                                                            //
// ************************************************************************** //
#include "Classes.hpp"
#include <cstdlib>
#include <ctime>
#include <typeinfo>

// Base
Base::~Base() {}

// A
A::A() {}
A::A(const A&) {}
A& A::operator=(const A&) { return *this; }
A::~A() {}

// B
B::B() {}
B::B(const B&) {}
B& B::operator=(const B&) { return *this; }
B::~B() {}

// C
C::C() {}
C::C(const C&) {}
C& C::operator=(const C&) { return *this; }
C::~C() {}

Base* generate() {
    std::srand(static_cast<unsigned int>(std::time(0)));
    int r = std::rand() % 3;
    if (r == 0) return new A();
    if (r == 1) return new B();
    return new C();
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p)) std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p)) std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p)) std::cout << "C" << std::endl;
    else std::cout << "Unknown" << std::endl;
}

void identify(Base& p) {
    try { (void)dynamic_cast<A&>(p); std::cout << "A" << std::endl; return; } catch (...) {}
    try { (void)dynamic_cast<B&>(p); std::cout << "B" << std::endl; return; } catch (...) {}
    try { (void)dynamic_cast<C&>(p); std::cout << "C" << std::endl; return; } catch (...) {}
    std::cout << "Unknown" << std::endl;
}
