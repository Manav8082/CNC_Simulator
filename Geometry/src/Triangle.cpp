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

std::vector<Edge> Geometry::Triangle::getEdge(Triangulation& tri)
{
    SurfacePoint s1 = SurfacePoint(tri.uniqueNumbers[P1().X()], tri.uniqueNumbers[P1().Y()], tri.uniqueNumbers[P1().Z()]);
    SurfacePoint s2 = SurfacePoint(tri.uniqueNumbers[P2().X()], tri.uniqueNumbers[P2().Y()], tri.uniqueNumbers[P2().Z()]);
    SurfacePoint s3 = SurfacePoint(tri.uniqueNumbers[P3().X()], tri.uniqueNumbers[P3().Y()], tri.uniqueNumbers[P3().Z()]);

    std::vector<Edge> edges;
    edges.push_back(Edge(s1, s2));
    edges.push_back(Edge(s2, s3));
    edges.push_back(Edge(s3, s1));
    return edges;
}

Point Triangle::Normal()
{
    return normal;
}


