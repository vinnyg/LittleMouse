#ifndef LMPOINT_H
#define LMPOINT_H

#include <SDL.h>

namespace LM
{
	class LMPoint : public SDL_Point
	{
	private:
		int x;
		int y;
	public:
		LMPoint();
		LMPoint(int _x, int _y);
		LMPoint(const SDL_Point &point);
		LMPoint(const LMPoint &point);

		void SetX(int _x) { x = _x; }
		void SetY(int _y) { y = _y; }
		int GetX() const { return x; }
		int GetY() const { return y; }

		LMPoint &operator+(const LMPoint rhs);
		LMPoint &operator-(const LMPoint rhs);
		LMPoint &operator*(const int rhs);
		LMPoint &operator/(const int rhs);
		LMPoint &operator=(const LMPoint rhs);
	};

}

#endif