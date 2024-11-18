#include "Triangulation.h"
using namespace Geometry;
Triangulation::Triangulation()
{

}

Triangulation::~Triangulation()
{

}

std::vector<double> Geometry::Triangulation::getcoordinates(Point& P1)
{
	std::vector<double> xyz;

	double x = uniqueNumbers[P1.X()];
	xyz.push_back(x);
	double y = uniqueNumbers[P1.Y()];
	xyz.push_back(y);
	double z = uniqueNumbers[P1.Z()];
	xyz.push_back(z);
	return xyz;
}

