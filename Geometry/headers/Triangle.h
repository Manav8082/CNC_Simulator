#pragma once
#include <vector>
#include "Edge.h"
#include "Point.h"

namespace Geometry
{
    class Triangle
    {
        // Three points representing the vertices of the triangle
    private:
        Point p1;
        Point p2;
        Point p3;
        Point normal;

    public:
        Triangle(Point normal, Point p1, Point p2, Point p3);
        ~Triangle();

        // Getter functions to access the private members 
        Point P1();
        Point P2();
        Point P3();
        Point Normal();
        bool operator==(const Triangle& other) const;
        std::vector<Geometry::Point> Points();


       /* struct TriangleHash {
            std::size_t operator()(const Triangle& t) const noexcept;
        };*/
        //struct temp
        //{
        //    bool operator<(Triangle& other) const {
        //        // For simplicity, compare lexicographically by vertices (p1, p2, p3)
        //        if (p1 != other.p1) return p1 < other.p1;
        //        if (p2 != other.p2) return p2 < other.p2;
        //        return p3 < other.p3;
        //    }
        //};

      /*  bool operator!=(Triangle&);*/
        //struct Hash {
        //    bool operator()(Triangle& t) const noexcept{
        //        size_t h1 = Point::Hash{}(t.p1);
        //        size_t h2 = Point::Hash{}(t.p2);
        //        size_t h3 = Point::Hash{}(t.p3);
        //        return h1 ^ (h2 << 1) ^ (h3 << 2);  // Combine the hashes of the three points
        //    }
        //};
        
        //struct Hash {
        //    size_t operator()(const Triangle& t) const {
        //        size_t h1 = SurfacePoint::Hash{}(t.P1);
        //        size_t h2 = SurfacePoint::Hash{}(t.P2);
        //        size_t h3 = SurfacePoint::Hash{}(t.P3);
        //        return h1 ^ (h2 << 1) ^ (h3 << 2);  // Combine the hashes of the three vertices
        //    }
        //};
    };

}
