#include "Edge.h"

Geometry::Edge::Edge(SurfacePoint& start, SurfacePoint& end)
	: start(start), end(end)
{
}

Geometry::Edge::~Edge()
{

}

bool Geometry::Edge::operator==(const Edge& other) const
{
	return (start == other.start && end == other.end) || (start == other.end && end == other.start);
}

bool Geometry::Edge::isAdjacent(const Edge& other) const
{
	return (start == other.start || start == other.end || end == other.start || end == other.end);
}