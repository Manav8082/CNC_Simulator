#include "Intersector.h"
using namespace Geometry;

Intersector::Intersector()
{
}

Intersector::~Intersector()
{
}

vector<double> Intersector::isIntersecting(Point& p1, Point& p2, double y,Triangulation& tri)
{
    vector<double> intersectionPoints;
    vector<double> y1 = tri.getcoordinates(p1);
    vector<double> y2 = tri.getcoordinates(p2);

    if((y1[1]-y)*(y2[1]-y)<=0)
    {
        double ty = (y - y1[1]) / (y2[1] - y1[1]);
        double x = (y1[0]+ty*(y2[0]-y1[0]));
        double z = (y1[2] +ty*(y2[2] - y1[2]));
        intersectionPoints.push_back(x);
        intersectionPoints.push_back(ty);
        intersectionPoints.push_back(z);
        
    }
    //else
    //{
    //    /*intersectionPoints.push_back(0);
    //    intersectionPoints.push_back(0);
    //    intersectionPoints.push_back(0);*/
    //}
    return intersectionPoints;
    
   /* if ((uniqueValues[p1.Y()] - y) * (uniqueValues[p2.Y()] - y) <= 0) {
        double ty = (y - uniqueValues[p1.Y()]) / (uniqueValues[p2.Y()] - uniqueValues[p1.Y()]);
        double x_ = uniqueValues[p1.X()] + ty * (uniqueValues[p2.X()] - uniqueValues[p2.X()]);
        double z_ = uniqueValues[p1.Z()] + ty * (uniqueValues[p2.Z()] - uniqueValues[p2.Z()]);
        return new SurfacePoint(x_, y, z_);
    }
    return nullptr;*/
}

vector<vector<double>> Intersector::intersect( Triangle& t, double y, Triangulation& tri)
{
    vector<vector<double>> intersectingPts;

    Point p1 = t.P1();
    Point p2 = t.P2();
    Point p3 = t.P3();

    vector<double> sp1=isIntersecting(p1, p2, y, tri);
    vector<double> sp2=isIntersecting(p3, p2, y, tri);
    vector<double> sp3=isIntersecting(p1, p3, y, tri);

    if (sp1.size()>0)
        intersectingPts.push_back(sp1);
    if (sp2.size() > 0)
        intersectingPts.push_back(sp2);
    if (sp3.size() > 0)
        intersectingPts.push_back(sp3);

    return intersectingPts;
}