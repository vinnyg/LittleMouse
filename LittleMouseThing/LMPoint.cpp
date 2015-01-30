#include "LMPoint.h"

namespace LM
{
	LMPoint::LMPoint()
	{
		x = 0;
		y = 0;
	}

	LMPoint::LMPoint(int _x, int _y)
	{
		x = _x;
		y = _y;
	}

	LMPoint::LMPoint(const LMPoint &point)
	{
		x = point.x;
		y = point.y;
	}

	LMPoint::LMPoint(const SDL_Point &point)
	{
		x = point.x;
		y = point.y;
	}

	LMPoint &LMPoint::operator+(const LMPoint rhs)
	{
		return LMPoint(x + rhs.x, y + rhs.y);
	}

	LMPoint &LMPoint::operator-(const LMPoint rhs)
	{
		return LMPoint(x - rhs.x, y - rhs.y);
	}

	LMPoint &LMPoint::operator*(const int rhs)
	{
		return LMPoint(x * rhs, y * rhs);
	}

	LMPoint &LMPoint::operator/(const int rhs)
	{
		return LMPoint(x / rhs, y / rhs);
	}
}
