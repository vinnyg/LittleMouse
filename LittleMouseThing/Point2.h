#pragma once

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
		Point2(SDL_Point const &point);
		Point2(Point2 const &point);

		void SetX(int _x) { x = _x; }
		void SetY(int _y) { y = _y; }
		int GetX() const { return x; }
		int GetY() const { return y; }

		Point2 operator+(Point2 const rhs);
		Point2 operator-( Point2 const rhs);
		Point2 operator*(int const rhs);
		Point2 operator/(int const rhs);
		Point2 operator=(Point2 const rhs);
	};

}