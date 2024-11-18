#include "PathCreator.h"
#include "Intersector.h"
#include <unordered_set>
#include <unordered_map>
using namespace std;
PathCreator::PathCreator()
{
}

PathCreator::~PathCreator()
{
}

std::vector<std::vector<std::vector<double>>> PathCreator::CreatePath(Triangulation& tri, double y_max, double y_min)
{
	vector<vector<vector<double>>> path;
	double y = y_max;
	Intersector in;

	for (; y >= y_min; y = y - 0.1)
	{
		vector<vector<double>> sortedPoints;
		unordered_map<vector<double>,int, Point> uniquePoints;
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

			while (visited.size() < yIntersecingTrs.size())
			{
				bool progressMade = false;
				for (auto& next : yIntersecingTrs )
				{
					if (visited.find(next) != visited.end()) {
						continue;
					}
					bool foundAdjacentEdge = false;
					for (const auto& edge1 : getEdge(current))
					{
						for (const auto& edge2 : getEdge(next))
						{
							if (edge1.isAdjacent(edge2))
							{
								sortedTriangles.push_back(next);
								visited.insert(next);
								current = next;
								foundAdjacentEdge = true;
								progressMade = true;
								break;
							}
							
						}
						if (foundAdjacentEdge)
						{
							break;
						}
					}
					/*if (progressMade)
					{
						break;
					}*/
				}
				if (!progressMade) {
					break;
				}
			}
			vector<vector<double>> triangleIntersectingPoints;
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

vector<Edge> PathCreator::getEdge(Triangle& t)
{
	Point p1 = Point(t.P1().X(), t.P1().Y(), t.P1().Z());
	Point p2 = Point(t.P2().X(), t.P2().Y(), t.P2().Z());
	Point p3 = Point(t.P3().X(), t.P3().Y(), t.P3().Z());
	/*SurfacePoint s2 = SurfacePoint(tri.uniqueNumbers[t.P2().X()], tri.uniqueNumbers[t.P2().Y()], tri.uniqueNumbers[t.P2().Z()]);
	SurfacePoint s3 = SurfacePoint(tri.uniqueNumbers[t.P3().X()], tri.uniqueNumbers[t.P3().Y()], tri.uniqueNumbers[t.P3().Z()]);
	*/
	std::vector<Edge> edges;
	edges.push_back(Edge(p1, p2));
	edges.push_back(Edge(p2, p3));
	edges.push_back(Edge(p3, p1));
	return edges;
}
