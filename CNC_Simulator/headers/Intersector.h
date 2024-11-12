#include "Triangulation.h"
#include "SurfacePoint.h"
using namespace Geometry;
using namespace std;

class Intersector
{
public:
	double y;
	Triangle t;

	SurfacePoint* isIntersecting(Point& p1, Point& p2, double y, const vector<double>& uniqueValues);
	vector<SurfacePoint> intersect(const Triangle& t, double y, const Triangulation&);

};