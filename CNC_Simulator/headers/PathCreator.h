#pragma once
#include<vector>
#include"SurfacePoint.h"
#include "Triangulation.h"
using namespace Geometry;
class PathCreator
{
public:
	std::vector<SurfacePoint> centroids;

	PathCreator();
	~PathCreator();
	std::vector<std::vector<SurfacePoint>> createPath(Triangulation&,double ymax,double ymin);
};

