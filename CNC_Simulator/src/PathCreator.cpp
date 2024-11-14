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
			if (triangleIntersectingPoints.size() == 2)	// if there are two intersection points
			{
				auto pair1 = uniquePoints.find(triangleIntersectingPoints[0]);
				auto pair2 = uniquePoints.find(triangleIntersectingPoints[1]);
				if (pair1 == uniquePoints.end() && pair2 == uniquePoints.end()) // if both points are new to vector
				{
					eachplane.push_back(pair1->first);
					eachplane.push_back(pair2->first);
					uniquePoints[pair2->first] = eachplane.size() - 1;
				}
				else if (pair2 == uniquePoints.end())	// if first intersecting point is in the vector
				{
					if (eachplane[eachplane.size() - 1] == triangleIntersectingPoints[0])	// if first intersecting point is at last position in vector
					{
						eachplane.push_back(pair2->first);	// then put the second intersecting point after that.
						uniquePoints[pair2->first] = eachplane.size() - 1;
					}
					else	// if first intersecting point is not at the last then find its position and 
					{
						auto it = find(eachplane.begin(), eachplane.end(), triangleIntersectingPoints[0]);
						eachplane.insert(it, triangleIntersectingPoints[1]);
					}

					if (eachplane[0] != triangleIntersectingPoints[0])
					{
						eachplane.push_back(pair2->first);
						uniquePoints[pair2->first] = eachplane.size() - 1;
					}
					else if (eachplane[0] == triangleIntersectingPoints[0])
					{
						vector<SurfacePoint>::iterator it = eachplane.begin();
						eachplane.insert(it, triangleIntersectingPoints[1]);
					}
					else
				}
			}
			/*vector<SurfacePoint> triangleIntersectingPoints;
			triangleIntersectingPoints = in.intersect(t, y, tri);
			if (triangleIntersectingPoints.size() == 2)
			{
				for (int i=0;i<2;i++)
				{
					auto pair1 = uniquePoints.find(triangleIntersectingPoints[0]);
					auto pair2 = uniquePoints.find(triangleIntersectingPoints[1]);
					if (pair1 == uniquePoints.end() && pair2 == uniquePoints.end())
					{
						eachplane.push_back(pair1->first);
						eachplane.push_back(pair2->first);
						uniquePoints[pair2->first] = eachplane.size() - 1;
					}
					
				}
			}*/
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
