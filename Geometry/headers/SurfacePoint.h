#pragma once

namespace Geometry 
{
	class SurfacePoint
	{
	public:
		double x;
		double y;
		double z;

		SurfacePoint(double, double, double);
		~SurfacePoint();
	};
}