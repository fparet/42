// ************************************************************************** //
//                                                                            //
//                                 Point.hpp                                  //
//                         42 C++ Module 02 - ex03                            //
//                                                                            //
// ************************************************************************** //
#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
public:
    // Coplien form
    Point();                         // (0,0)
    Point(const Point& other);       // Copy ctor
    Point& operator=(const Point&);  // Copy assignment (no-op due to const members)
    ~Point();                        // Dtor

    // Extra constructor
    Point(const float x, const float y);

    // Accessors
    Fixed const& getX() const;
    Fixed const& getY() const;

private:
    const Fixed _x;
    const Fixed _y;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif // POINT_HPP
