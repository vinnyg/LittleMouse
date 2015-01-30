#pragma once

#include <SDL.h>
#include "LMPoint.h"

namespace LM
{
	class LMRect : public SDL_Rect
	{
	protected:
		int x;
		int y;
		int w;
		int h;
	public:
		LMRect();
		LMRect(const SDL_Rect &rect);
		LMRect(const LMRect &rect);
		LMRect(const LMPoint &position, LMPoint &dimension);
		void SetX(int _x) { x = _x; }
		void SetY(int _y) { y = _y; }
		void SetWidth(int _w) { w = _w; }
		void SetHeight(int _h) { h = _h; }
		void SetPosition(LMPoint &pos);
		void SetDimension(LMPoint &dimension);
		int GetX() { return x; }
		int GetY() { return y; }
		int GetWidth() { return w; }
		int GetHeight() { return h; }
	};
}
