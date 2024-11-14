#include "SurfacePoint.h"
using namespace Geometry;

SurfacePoint::SurfacePoint(double _x, double _y, double _z)
	:x(_x),
	y(_y),
	z(_z)
{
}

SurfacePoint::~SurfacePoint()
{
}
double SurfacePoint::X()
{
	return x;
}

double SurfacePoint::Y()
{
	return y;
}

double SurfacePoint::Z()
{
	return z;
}


bool SurfacePoint::operator<(const SurfacePoint& other) const
{
	if (x != other.x) {
		return x < other.x;
	}
	if (y != other.y) {
		return y < other.y;
	}
	return z < other.z;
}

bool SurfacePoint::operator==(const SurfacePoint& other) const 
{
	return x == other.x && y == other.y && z == other.z;
}
