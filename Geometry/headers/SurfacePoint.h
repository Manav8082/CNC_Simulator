#pragma once

namespace Geometry 
{
	class SurfacePoint
	{
	private:
		double x;
		double y;
		double z;
	public:
		SurfacePoint(double, double, double);
		~SurfacePoint();
		double X();
		double Y();
		double Z();
		bool operator==(const SurfacePoint& other) const;
		bool operator<(const SurfacePoint& other) const;
		
	};
}