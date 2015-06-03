#pragma once

#include <SDL.h>

namespace LM
{
	template <class type>
	class Point2 : public SDL_Point
	{
	private:
		type x, y;
	public:
		Point2() = delete;
		Point2(type _x, type _y) : x(_x), y(_y) {}
		//Point2(SDL_Point const &point) : x(point.x), y(point.y) {}
		Point2(Point2<type> const &point) : x(point.x), y(point.y) {}
		~Point2() {}

		type GetX() const { return x; }
		type GetY() const { return y; }
		void SetX(type _x) { x = _x; }
		void SetY(type _y) { y = _y; }

		SDL_Point ToSDLPoint() const
		{
			return SDL_Point{ int(x), int(y) };
		}

		template <typename operandType>
		Point2<type> operator+(Point2<operandType> const rhs)
		{
			return Point2<type>(x + rhs.GetX(), y + rhs.GetY());
		}

		template <typename operandType>
		Point2<type> operator-(Point2<operandType> const rhs)
		{
			return Point2<type>(x - rhs.GetX(), y - rhs.GetY());
		}

		template <typename operandType>
		Point2<type> operator*(operandType const rhs)
		{
			return Point2<type>((type)(x * rhs), (type)(y * rhs));
		}

		template <typename operandType>
		Point2<type> operator/(operandType const rhs)
		{ 
			return Point2<type>(x / rhs, y / rhs);
		}

		template <typename operandType>
		Point2<type> &operator=(Point2<operandType> const rhs)
		{
			this->x = rhs.GetX();
			this->y = rhs.GetY();
			return this;
		}

		//TODO: ToSDL_Point Method()
	};
}