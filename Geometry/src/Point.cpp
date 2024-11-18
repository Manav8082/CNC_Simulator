
#include "Point.h"
using namespace Geometry;
Geometry::Point::Point()
{
}
Point::Point(int x, int y, int z)
	: mX(x), mY(y), mZ(z)
{
}


Point::~Point()
{
}

int Point::X()
{
	return mX;
}

int Point::Y()
{
	return mY;
}

int Point::Z()
{
	return mZ;
}

bool Point::operator<(const Point& other) const
{
	if (mX != other.mX) {
		return mX < other.mX;
	}
	if (mY != other.mY) {
		return mY < other.mY;
	}
	return mZ < other.mZ;
}

bool Point::operator==(const Point& other) const {
	return mX == other.mX && mY == other.mY && mZ == other.mZ;
}


std::size_t Point::PointHash::operator()(const Point& p) const noexcept {
	std::size_t h1 = std::hash<int>{}(p.mX);
	std::size_t h2 = std::hash<int>{}(p.mY);
	std::size_t h3 = std::hash<int>{}(p.mZ);

	return h1 ^ (h2 << 1) ^ (h3 << 2);
}
