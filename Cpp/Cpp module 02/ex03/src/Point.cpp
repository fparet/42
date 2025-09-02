// ************************************************************************** //
//                                                                            //
//                                 Point.cpp                                  //
//                         42 C++ Module 02 - ex03                            //
//                                                                            //
// ************************************************************************** //
#include "Point.hpp"

Point::Point() : _x(0), _y(0) {}
Point::Point(const float x, const float y) : _x(x), _y(y) {}
Point::Point(const Point& other) : _x(other._x), _y(other._y) {}
Point& Point::operator=(const Point& /*other*/) {
    // Members are const; assignment does nothing but is provided per Coplien requirement.
    return *this;
}
Point::~Point() {}

Fixed const& Point::getX() const { return _x; }
Fixed const& Point::getY() const { return _y; }
