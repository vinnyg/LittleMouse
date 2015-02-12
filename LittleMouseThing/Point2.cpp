#include "Point2.h"

namespace LM
{
	Point2::Point2() : x(0), y(0)
	{
	}

	Point2::Point2(int _x, int _y) : x(_x), y(_y)
	{
	}

	Point2::Point2(const Point2 &point) : x(point.x), y(point.y)
	{
	}

	Point2::Point2(const SDL_Point &point) : x(point.x), y(point.y)
	{
	}

	Point2 Point2::operator=(const Point2 rhs)
	{
		this->x = rhs.x;
		this->y = rhs.y;
		return *this;
	}

	Point2 Point2::operator+(const Point2 rhs)
	{
		return Point2(x + rhs.x, y + rhs.y);
	}

	Point2 Point2::operator-(const Point2 rhs)
	{
		return Point2(x - rhs.x, y - rhs.y);
	}

	Point2 Point2::operator*(const int rhs)
	{
		return Point2(x * rhs, y * rhs);
	}

	Point2 Point2::operator/(const int rhs)
	{
		return Point2(x / rhs, y / rhs);
	}
}
