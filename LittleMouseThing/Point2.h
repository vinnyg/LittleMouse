#pragma once

#include <SDL.h>

namespace LM
{
	/*class Point2 : public SDL_Point
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
	};*/

	template <class type>
	class Point2 : public SDL_Point
	{
	private:
		type x, y;
	public:
		Point2(type _x, type _y) : x(_x), y(_y) {}
		Point2(SDL_Point const &point) : x(point.x), y(point.y) {}
		Point2(Point2 const &point) : x(point.x), y(point.y) {}

		void SetX(type _x) { x = _x; }
		void SetY(type _y) { y = _y; }
		type GetX() const { return x; }
		type GetY() const { return y; }

		Point2<type> operator+(Point2<type> const rhs) { return Point2<type>(x + rhs.x, y + rhs.y); }
		Point2<type> operator-(Point2<type> const rhs) { return Point2<type>(x - rhs.x, y - rhs.y); }

		template <typename operandType>
		Point2<type> operator*(operandType const rhs) { return Point2<type>(x * rhs, y * rhs); }
		template <typename operandType>
		Point2<type> operator/(operandType const rhs) { return Point2<type>(x / rhs, y / rhs) }
		template <typename operandType>
		Point2<type> operator=(Point2<operandType> const rhs)
		{
			this->x = rhs.GetX();
			this->y = rhs.GetY();
			return *this;
		}
	};
}