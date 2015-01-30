#pragma once

#include <math.h>
#include "LMPoint.h"

namespace LM
{
	class LMVector2
	{
	private:
		int lengthX;
		int lengthY;
	public:
		LMVector2();
		LMVector2(int x, int y) : lengthX(x), lengthY(y) {};
		LMVector2(LMPoint p1, LMPoint p2);
		~LMVector2();
		int GetX() const { return lengthX; }
		int GetY() const { return lengthY; }
		float GetMagnitude();
		LMVector2 GetNormal();
		float GetDotProduct(LMVector2 &operandVector);
		//LMVector2 &operator= (const LMVector2 &rhs) const;
		//LMVector2 &operator+ (const LMVector2 &rhs) const;
		//LMVector2 &operator- (const LMVector2 &rhs) const;
		//LMVector2 &operator* (const int &rhs) const;
		//LMVector2 &operator/ (const int &rhs) const;
	};
}

