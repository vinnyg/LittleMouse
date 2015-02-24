#pragma once

#include <SDL.h>
#include "Point2.h"

namespace LM
{
	class Rect : public SDL_Rect
	{
	public:
		Rect();
		Rect(SDL_Rect const &rect);
		Rect(Rect const &rect);
		Rect(Point2 const &position, Point2 const &dimension);

		Rect(int const _x, int const _y, int const _w, int const _h);

		void SetX(int _x) { x = _x; }
		void SetY(int _y) { y = _y; }
		void SetWidth(int _w) { w = _w; }
		void SetHeight(int _h) { h = _h; }
		void SetPosition(Point2 &pos);
		void SetDimension(Point2 &dimension);
		int GetX() { return x; }
		int GetY() { return y; }
		int GetWidth() { return w; }
		int GetHeight() { return h; }
		Point2 GetPosition();
		Point2 GetDimensions();
	};
}
