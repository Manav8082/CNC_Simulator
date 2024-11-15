#include "SurfacePoint.h"
namespace Geometry
{
	class Edge
	{
	public:
		SurfacePoint start;
		SurfacePoint end;

		Edge(SurfacePoint&, SurfacePoint&);
		~Edge();

		bool operator==(const Edge& other) const;
		bool isAdjacent(const Edge& other) const;
	};
}