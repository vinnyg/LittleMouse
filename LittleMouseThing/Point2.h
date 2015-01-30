#ifndef POINT2_H
#define POINT2_H

#include <SDL.h>

namespace LM
{
	class Point2 : public SDL_Point
	{
	private:
		int x;
		int y;
	public:
		Point2();
		Point2(int _x, int _y);
		Point2(const SDL_Point &point);
		Point2(const Point2 &point);

		void SetX(int _x) { x = _x; }
		void SetY(int _y) { y = _y; }
		int GetX() const { return x; }
		int GetY() const { return y; }

		Point2 operator+(const Point2 rhs);
		Point2 operator-(const Point2 rhs);
		Point2 operator*(const int rhs);
		Point2 operator/(const int rhs);
		Point2 operator=(const Point2 rhs);
	};

}

#endif