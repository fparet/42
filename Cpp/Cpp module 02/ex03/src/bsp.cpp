// ************************************************************************** //
//                                                                            //
//                                  bsp.cpp                                   //
//                         42 C++ Module 02 - ex03                            //
//                                                                            //
// ************************************************************************** //
#include "Point.hpp"

// Cross product (2D) of vectors p1p2 x p1p3
static float cross(const Point& p1, const Point& p2, const Point& p3) {
    float x1 = p2.getX().toFloat() - p1.getX().toFloat();
    float y1 = p2.getY().toFloat() - p1.getY().toFloat();
    float x2 = p3.getX().toFloat() - p1.getX().toFloat();
    float y2 = p3.getY().toFloat() - p1.getY().toFloat();
    return x1 * y2 - y1 * x2;
}

// Return true if 'point' is strictly inside triangle abc (edges excluded)
bool bsp(Point const a, Point const b, Point const c, Point const point) {
    float c1 = cross(a, b, point);
    float c2 = cross(b, c, point);
    float c3 = cross(c, a, point);

    // Reject points on edges (== 0) to satisfy "strictly inside"
    if (c1 == 0.0f || c2 == 0.0f || c3 == 0.0f)
        return false;

    bool hasNeg = (c1 < 0) || (c2 < 0) || (c3 < 0);
    bool hasPos = (c1 > 0) || (c2 > 0) || (c3 > 0);
    return !(hasNeg && hasPos); // all same sign -> inside
}
