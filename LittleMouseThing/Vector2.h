#pragma once

#include <math.h>
#include "Point2.h"

namespace LM
{
	template<class type>
	class Vector2
	{
	private:
		type lengthX;
		type lengthY;
	public:
		template<typename operandType>
		Vector2(Vector2<operandType> j) : lengthX(j.GetX()), lengthY(j.GetY()) {}
		Vector2(type x, type y) : lengthX(x), lengthY(y) {}
		Vector2(Point2<type> p1, Point2<type> p2) : lengthX(p2.GetX() - p1.GetX()), lengthY(p2.GetY() - p1.GetY()) {}
		~Vector2();
		type GetX() const { return lengthX; }
		type GetY() const { return lengthY; }
		float GetMagnitude() { return sqrt(float((lengthX * lengthX) + (lengthY * lengthY))); }
		Vector2<type> Normalise() { return Vector2(-lengthY, lengthX); }
		type GetDotProduct(Vector2<type> &operandVector) { return lengthX * operandVector.GetX() + lengthY * operandVector.GetY(); }
		
		template<typename operandType>
		Vector2<type> &operator+ (Vector2<operandType> const &rhs) const
		{
			return Vector2<type>(lengthX + rhs.GetX(), lengthY + rhs.GetY());
		}

		template<typename operandType>
		Vector2<type> &operator- (Vector2<operandType> const &rhs) const
		{
			return Vector2<type>(lengthX - rhs.GetX(), lengthY - rhs.GetY());
		}

		template<typename operandType>
		Vector2<type> &operator* (operandType const &rhs) const
		{
			return Vector2<type>(lengthX * rhs, lengthY * rhs);
		}
		
		template<typename operandType>
		Vector2<type> &operator/ (operandType const &rhs) const
		{
			return Vector2<type>(lengthX / rhs, lengthY / rhs);
		}

		template<typename operandType>
		Vector2<type> &operator= (Vector2 const &rhs) const
		{
			this->lengthX = rhs.GetX();
			this->lengthY = rhs.GetY();
			return *this;
		}
	};
}

