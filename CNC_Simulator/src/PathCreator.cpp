#include "PathCreator.h"
#include "Intersector.h"
#include <map>
PathCreator::PathCreator()
{
}

PathCreator::~PathCreator()
{
}

std::vector<std::vector<SurfacePoint>> PathCreator::CreatePath(Triangulation& tri, double y_max, double y_min)
{
	std::vector<std::vector<SurfacePoint>> path;
	double y = y_max;
	Intersector in;

	for (; y >= y_min; y = y - 0.1)
	{
		map<SurfacePoint,int> uniquePoints;
		vector<SurfacePoint> eachplane;
		for (auto t : tri.Triangles)
		{
			vector<SurfacePoint> triangleIntersectingPoints;
			triangleIntersectingPoints = in.intersect(t, y, tri);
			for (auto a : triangleIntersectingPoints)
			{
				auto pair = uniquePoints.find(a);
				if (pair == uniquePoints.end())
				{
					eachplane.push_back(a);
					uniquePoints[a] = eachplane.size() - 1;
				}
			}
			/*if (triangleIntersectingPoints.size() == 2)
			{
				auto pair1 = uniquePoints.find(triangleIntersectingPoints[0]);
				auto pair2 = uniquePoints.find(triangleIntersectingPoints[1]);
				if (pair1 != uniquePoints.end() && pair2 != uniquePoints.end())
				{
					if (triangleIntersectingPoints[0].next == nullptr)
						triangleIntersectingPoints[0].next = &triangleIntersectingPoints[1];
					else if (triangleIntersectingPoints[1].next == nullptr)
						triangleIntersectingPoints[1].next = &triangleIntersectingPoints[0];
				}
				else if(pair1 != uniquePoints.end())
				{
					triangleIntersectingPoints[0].next = &triangleIntersectingPoints[1];
					eachplane.push_back(triangleIntersectingPoints[1]);
					uniquePoints[pair2->first] = eachplane.size() - 1;
				}
				else if (pair2 != uniquePoints.end())
				{
					triangleIntersectingPoints[1].next = &triangleIntersectingPoints[0];
					eachplane.push_back(triangleIntersectingPoints[0]);
					uniquePoints[pair1->first] = eachplane.size() - 1;
				}
				else
				{
					eachplane.push_back(triangleIntersectingPoints[0]);
					eachplane.push_back(triangleIntersectingPoints[1]);
					triangleIntersectingPoints[0].next = &triangleIntersectingPoints[1];
					uniquePoints[pair1->first]=
					

				}
			}*/
			/*if (triangleIntersectingPoints.size() == 1)
			{
				auto pair = uniquePoints.find(triangleIntersectingPoints[0]);
				if (pair == uniquePoints.end())
				{

				}
			}*/
			
		}
		path.push_back(eachplane);
	}
	return path;
}
