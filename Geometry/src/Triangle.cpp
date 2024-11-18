#include <vector>
#include "Triangle.h"
using namespace Geometry;
Triangle::Triangle(Point normal, Point p1, Point p2, Point p3)
    : p1(p1), p2(p2), p3(p3), normal(normal)
{
}

Triangle::~Triangle()
{
}

Point Triangle::P1()
{
    return p1;
}

Point Triangle::P2()
{
    return p2;
}

Point Triangle::P3()
{
    return p3;
}

std::vector<Point> Triangle::Points()
{
    std::vector<Point> points;
    points.push_back(p1);
    points.push_back(p2);
    points.push_back(p3);
    return points;
}


Geometry::Point Triangle::Normal()
{
    return normal;
}

bool Triangle::operator==(const Triangle& other) const {
    // Check if points match, allowing different orderings of the triangle's vertices
    return (p1 == other.p1 && p2 == other.p2 && p3 == other.p3) ||
        (p1 == other.p2 && p2 == other.p3 && p3 == other.p1) ||
        (p1 == other.p3 && p2 == other.p1 && p3 == other.p2);
}


//std::size_t Triangle:: TriangleHash::operator()(const Triangle& t) const noexcept {
//    // Combine the hashes of the three points (p1, p2, p3) in the triangle
//    std::size_t h1 = Point::PointHash{}(t.p1);
//    std::size_t h2 = Point::PointHash{}(t.p2);
//    std::size_t h3 = Point::PointHash{}(t.p3);
//
//    // Combine the individual hashes into one using XOR and shifting
//    return h1 ^ (h2 << 1) ^ (h3 << 2);
//}
//bool Geometry::Triangle::operator!=(Triangle& other) {
//    //if();
//}
