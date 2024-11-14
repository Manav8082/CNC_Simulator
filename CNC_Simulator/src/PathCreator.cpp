#include "PathCreator.h"
#include "Intersector.h"
#include <map>
PathCreator::PathCreator()
{
}

PathCreator::~PathCreator()
{
}

std::vector<std::vector<SurfacePoint>> PathCreator::createPath(Triangulation& tri,double y_max,double y_min)
{
	std::vector<std::vector<SurfacePoint>> path;
	double y = y_max;
	Intersector in;
	
	for (; y >= y_min; y = y - 0.433000)
	{
		double xSum = 0;
		double zSum = 0;
		double noPts = 0;

		map<SurfacePoint, int> checkPoint;
		vector<SurfacePoint> eachplane;
		vector<Triangle> copyTrs;
		for (auto t : tri.Triangles)
		{
			copyTrs.push_back(t);
		}
		for (auto t : copyTrs)
		{
			vector<SurfacePoint> triangleIntersectingPoints;
			triangleIntersectingPoints = in.intersect(t, y, tri);
			for (auto a : triangleIntersectingPoints)
			{
				noPts++;
				xSum += a.X();
				zSum += a.Z();
				auto pair = checkPoint.find(a);
				if (pair == checkPoint.end())
				{
					eachplane.push_back(a);
					checkPoint[a] = eachplane.size() - 1;
				}
			}
		}
		path.push_back(eachplane);
		centroids.push_back(SurfacePoint(xSum / noPts, y, zSum / noPts));
	}
	return path;
}
