#include "Triangulation.h"
//#include "SurfacePoint.h"
using namespace Geometry;
using namespace std;

class Intersector
{
public:
	Intersector();
	~Intersector();
	vector<double> isIntersecting(Point& p1, Point& p2, double y, Triangulation& tri);
	vector<vector<double>> intersect( Triangle& t, double y, Triangulation&);

};