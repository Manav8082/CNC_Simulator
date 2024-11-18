#pragma once
#include<vector>
#include "Triangulation.h"
#include "Edge.h"
using namespace Geometry;
class PathCreator
{
public:
	PathCreator();
	~PathCreator();
	std::vector<std::vector<std::vector<double>>> CreatePath(Triangulation& tri, double, double);
	std::vector<Edge> getEdge(Triangle& t);
	
};
