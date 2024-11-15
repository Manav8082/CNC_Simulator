#include "PathCreator.h"
#include "Intersector.h"
#include <unordered_set>
#include <map>
using namespace std;
PathCreator::PathCreator()
{
}

PathCreator::~PathCreator()
{
}

std::vector<std::vector<SurfacePoint>> PathCreator::CreatePath(Triangulation& tri, double y_max, double y_min)
{
	vector<vector<SurfacePoint>> path;
	double y = y_max;
	Intersector in;

	for (; y >= y_min; y = y - 0.1)
	{
		vector<SurfacePoint> sortedPoints;
		map<SurfacePoint,int> uniquePoints;
		vector<Triangle> sortedTriangles;
		vector<Triangle> yIntersecingTrs;
		for (auto t:tri.Triangles)
		{
			bool intersect = false;

			if ((tri.uniqueNumbers[t.P1().Y()] <= y && tri.uniqueNumbers[t.P2().Y()] > y) ||
				(tri.uniqueNumbers[t.P1().Y()] > y && tri.uniqueNumbers[t.P2().Y()] <= y) ||
				(tri.uniqueNumbers[t.P1().Y()] <= y && tri.uniqueNumbers[t.P3().Y()] > y) ||
				(tri.uniqueNumbers[t.P1().Y()] > y && tri.uniqueNumbers[t.P3().Y()] <= y) ||
				(tri.uniqueNumbers[t.P2().Y()] <= y && tri.uniqueNumbers[t.P3().Y()] > y) ||
				(tri.uniqueNumbers[t.P2().Y()] > y && tri.uniqueNumbers[t.P3().Y()] <= y))
			{ 
				intersect = true; 
			}
			if (intersect)
			{
				yIntersecingTrs.push_back(t);
			}
		}
		for (int i = 0; i < yIntersecingTrs.size(); i++)
		{
			unordered_set<Triangle> visited;

			Triangle start = yIntersecingTrs[0];
			sortedTriangles.push_back(start);
			visited.insert(start);

			Triangle current = start;

			while (visited.size() < yIntersecingTrs.size()) {
				for (auto& next : yIntersecingTrs) {
					if (visited.find(next) == visited.end())
					{
						for (const auto& edge1 : current.getEdge(tri))
						{
							for (const auto& edge2 : next.getEdge(tri))
							{
								if (edge1.isAdjacent(edge2))
								{
									sortedTriangles.push_back(next);
									visited.insert(next);
									current = next;
									break;
								}
							}
						}
					}
				}
			}
			vector<SurfacePoint> triangleIntersectingPoints;
			for (auto t : sortedTriangles)
			{
				triangleIntersectingPoints = in.intersect(t, y, tri);
				for (auto pt : triangleIntersectingPoints)
				{
					auto pair = uniquePoints.find(pt);
					if (pair == uniquePoints.end())
					{
						sortedPoints.push_back(pair->first);
						uniquePoints[pair->first] = uniquePoints.size() - 1;
					}
				}
			}
		}
		path.push_back(sortedPoints);
	}
	return path;
}
