// ************************************************************************** //
//                                                                            //
//                                 main.cpp                                   //
//                         42 C++ Module 02 - ex03                            //
//                                                                            //
// ************************************************************************** //
#include "Point.hpp"
#include <iostream>

static void test(const Point& a, const Point& b, const Point& c, const Point& p) {
    std::cout << "Triangle A(" << a.getX() << "," << a.getY() << ") "
              << "B(" << b.getX() << "," << b.getY() << ") "
              << "C(" << c.getX() << "," << c.getY() << ") | P("
              << p.getX() << "," << p.getY() << ") -> ";
    bool inside = bsp(a,b,c,p);
    std::cout << (inside ? "INSIDE" : "OUTSIDE/EDGE") << std::endl;
}

int main() {
    Point a(0.f, 0.f);
    Point b(10.f, 0.f);
    Point c(0.f, 10.f);

    test(a,b,c, Point(2.f, 2.f));      // inside
    test(a,b,c, Point(5.f, 5.f));      // edge (hypotenuse) -> false
    test(a,b,c, Point(10.f, 10.f));    // outside
    test(a,b,c, Point(0.f, 0.f));      // vertex -> false
    test(a,b,c, Point(3.f, 1.f));      // inside
    test(a,b,c, Point(7.f, 2.f));      // outside
    return 0;
}
