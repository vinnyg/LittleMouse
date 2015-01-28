#pragma once

#include <math.h>

class LMVector2
{
private:
	float vx;
	float vy;

public:
	LMVector2(float x, float y) : vx(x), vy(y) {};
	~LMVector2();
	LMVector2 &operator= (const LMVector2 &rhs) const;
	LMVector2 &operator+ (const LMVector2 &rhs) const;
	LMVector2 &operator- (const LMVector2 &rhs) const;
	LMVector2 &operator* (const LMVector2 &rhs) const;
	LMVector2 &operator/ (const LMVector2 &rhs) const;
};

