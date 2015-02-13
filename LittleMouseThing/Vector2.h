#pragma once

#include <math.h>
#include "Point2.h"

namespace LM
{
	class Vector2
	{
	private:
		int lengthX;
		int lengthY;
	public:
		Vector2();
		Vector2(int x, int y) : lengthX(x), lengthY(y) {};
		Vector2(Point2 p1, Point2 p2);
		~Vector2();
		int GetX() const { return lengthX; }
		int GetY() const { return lengthY; }
		float GetMagnitude();
		Vector2 Normalise();
		float GetDotProduct(Vector2 &operandVector);
		//LMVector2 &operator= (const LMVector2 &rhs) const;
		//LMVector2 &operator+ (const LMVector2 &rhs) const;
		//LMVector2 &operator- (const LMVector2 &rhs) const;
		//LMVector2 &operator* (const int &rhs) const;
		//LMVector2 &operator/ (const int &rhs) const;
	};
}

