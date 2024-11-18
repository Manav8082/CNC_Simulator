#pragma once
//#include "SurfacePoint.h"
#include "Point.h"
//#include "Triangulation.h"
namespace Geometry
{
	class Edge
	{
	public:
		Point start;
		Point end;

		Edge(Point&, Point&);
		//Edge(Point&, Point&);
		~Edge();

		bool operator==(const Edge& other) const;
		bool isAdjacent(const Edge& other) const;
	};
}