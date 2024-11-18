#pragma once
#include <iostream>
#include <unordered_set>
#include <functional>

namespace Geometry
{
	class Point
	{
		int mX;
		int mY;
		int mZ;

	public:
		Point();
		Point(int x, int y, int z);
		~Point();

		int X();
		int Y();
		int Z();
		bool operator==(const Point& other) const;
		bool operator<(const Point& other) const;
		/*struct temp{
			bool operator!=(Point& other) const;
		};*/
		
		struct PointHash {
			std::size_t operator()(const Point& p) const noexcept;
		};
	};
}
