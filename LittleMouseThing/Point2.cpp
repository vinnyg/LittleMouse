#include "Point2.h"

namespace LM
{
	Point2::Point2() : x(0), y(0)
	{
	}

	Point2::Point2(int _x, int _y) : x(_x), y(_y)
	{
	}

	Point2::Point2(Point2 const &point) : x(point.x), y(point.y)
	{
	}

	Point2::Point2(SDL_Point const &point) : x(point.x), y(point.y)
	{
	}

	Point2 Point2::operator=(Point2 const rhs)
	{
		this->x = rhs.x;
		this->y = rhs.y;
		return *this;
	}

	Point2 Point2::operator+(Point2 const rhs)
	{
		return Point2(x + rhs.x, y + rhs.y);
	}

	Point2 Point2::operator-(Point2 const rhs)
	{
		return Point2(x - rhs.x, y - rhs.y);
	}

	Point2 Point2::operator*(int const rhs)
	{
		return Point2(x * rhs, y * rhs);
	}

	Point2 Point2::operator/(int const rhs)
	{
		return Point2(x / rhs, y / rhs);
	}
}
