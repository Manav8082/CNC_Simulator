#include "PathCreator.h"
#include "Intersector.h"
#include <map>
PathCreator::PathCreator()
{
}

PathCreator::~PathCreator()
{
}

std::vector<std::vector<SurfacePoint>> PathCreator::CreatePath(Triangulation& tri,double y_max,double y_min)
{
	std::vector<std::vector<SurfacePoint>> path;
	double y = y_max;
	Intersector in;
	
	for (; y >= y_min; y = y - 0.1)
	{
		map<SurfacePoint, int> checkPoint;
		vector<SurfacePoint> eachplane;
		for (auto t : tri.Triangles)
		{
			vector<SurfacePoint> triangleIntersectingPoints;
			triangleIntersectingPoints = in.intersect(t, y, tri);
			for (auto a : triangleIntersectingPoints)
			{
				auto pair = checkPoint.find(a);
				if (pair == checkPoint.end())
				{
					eachplane.push_back(a);
					checkPoint[a] = eachplane.size() - 1;
				}
			}
		}
		path.push_back(eachplane);
	}
	return path;
}
