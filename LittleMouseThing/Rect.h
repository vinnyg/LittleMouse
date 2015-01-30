#pragma once

#include <SDL.h>
#include "LMPoint2.h"

namespace LM
{
	class Rect : public SDL_Rect
	{
	protected:
		int x;
		int y;
		int w;
		int h;
	public:
		Rect();
		Rect(const SDL_Rect &rect);
		Rect(const Rect &rect);
		Rect(const Point2 &position, Point2 &dimension);
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
	};
}
