#include "LMPoint.h"

namespace LM
{
	Point::Point()
	{
		x = 0;
		y = 0;
	}

	Point::Point(int _x, int _y)
	{
		x = _x;
		y = _y;
	}

	Point::Point(const Point &point)
	{
		x = point.x;
		y = point.y;
	}

	Point &Point::operator+(const Point rhs)
	{
		return Point(x + rhs.x, y + rhs.y);
	}

	Point &Point::operator-(const Point rhs)
	{
		return Point(x - rhs.x, y - rhs.y);
	}

	Point &Point::operator*(const int rhs)
	{
		return Point(x * rhs, y * rhs);
	}

	Point &Point::operator/(const int rhs)
	{
		return Point(x / rhs, y / rhs);
	}
}
