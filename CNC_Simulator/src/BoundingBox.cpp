#include <vector>
#include <iostream>
#include <cfloat>
#include "BoundingBox.h"
#include "Point.h"
#include "Triangle.h"
#include <cmath>
#include <Intersector.h>
#include <qpainterpath.h>

using namespace Geometry;

BoundingBox::BoundingBox() : Xmin(DBL_MAX), Xmax(DBL_MIN),
Ymin(DBL_MAX), Ymax(DBL_MIN),
Zmin(DBL_MAX), Zmax(DBL_MIN)
{
}

void BoundingBox::FindMinMax(double xyz[3])
{
    Xmin = std::min(Xmin, xyz[0]);
    Xmax = std::max(Xmax, xyz[0]);
    Ymin = std::min(Ymin, xyz[1]);
    Ymax = std::max(Ymax, xyz[1]);
    Zmin = std::min(Zmin, xyz[2]);
    Zmax = std::max(Zmax, xyz[2]);
}

std::vector<std::vector<std::vector<double>>> BoundingBox::GenerateTriangles()
{
    std::vector<std::vector<std::vector<double>>> boundingBox;
    vector<double> v0;
    v0.push_back(Xmin);
    v0.push_back(Ymin);
    v0.push_back(Zmin);
    vector<double> v1;
    v1.push_back(Xmin);
    v1.push_back(Ymin);
    v1.push_back(Zmax);
    vector<double> v2;
    v2.push_back(Xmin);
    v2.push_back(Ymax);
    v2.push_back(Zmin);
    vector<double> v3;
    v3.push_back(Xmin);
    v3.push_back(Ymax);
    v3.push_back(Zmax);
    vector<double> v4;
    v4.push_back(Xmax);
    v4.push_back(Ymin);
    v4.push_back(Zmin);
    vector<double> v5;
    v5.push_back(Xmax);
    v5.push_back(Ymin);
    v5.push_back(Zmax);
    vector<double> v6;
    v6.push_back(Xmax);
    v6.push_back(Ymax);
    v6.push_back(Zmin);
    vector<double> v7;
    v7.push_back(Xmax);
    v7.push_back(Ymax);
    v7.push_back(Zmax);
    
    boundingBox.push_back({ v0, v2, v4 });
    boundingBox.push_back({ v2, v6, v4 });
    boundingBox.push_back({ v1, v3, v5 });
    boundingBox.push_back({ v3, v7, v5 });
    boundingBox.push_back({ v0, v2, v1 });
    boundingBox.push_back({ v2, v3, v1 });
    boundingBox.push_back({ v4, v6, v5 });
    boundingBox.push_back({ v6, v7, v5 });
    boundingBox.push_back({ v2, v6, v3 });
    boundingBox.push_back({ v6, v7, v3 });
    boundingBox.push_back({ v0, v4, v1 });
    boundingBox.push_back({ v4, v5, v1 });

    return boundingBox;
   /* triangles.push_back({ v0, v2, v4 });
    triangles.push_back({ v2, v6, v4 });
    triangles.push_back({ v1, v3, v5 });
    triangles.push_back({ v3, v7, v5 });
    triangles.push_back({ v0, v2, v1 });
    triangles.push_back({ v2, v3, v1 });
    triangles.push_back({ v4, v6, v5 });
    triangles.push_back({ v6, v7, v5 });
    triangles.push_back({ v2, v6, v3 });
    triangles.push_back({ v6, v7, v3 });
    triangles.push_back({ v0, v4, v1 });
    triangles.push_back({ v4, v5, v1 });

    return triangles;*/
}
