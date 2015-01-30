#include "Rect.h"

namespace LM
{
	Rect::Rect()
	{
		x = 0;
		y = 0;
		w = 0;
		h = 0;
	}

	Rect::Rect(const SDL_Rect &rect)
	{
		x = rect.x;
		y = rect.y;
		w = rect.w;
		h = rect.h;
	}

	Rect::Rect(const Rect &rect)
	{
		x = rect.x;
		y = rect.y;
		w = rect.w;
		h = rect.h;
	}

	Rect::Rect(const Point2 &position, Point2 &dimension)
	{
		x = position.GetX();
		y = position.GetY();
		w = dimension.GetX();
		h = dimension.GetY();
	}

	void Rect::SetPosition(Point2 &pos)
	{
		x = pos.GetX();
		y = pos.GetY();
	}

	void Rect::SetDimension(Point2 &dimension)
	{
		w = dimension.GetX();
		h = dimension.GetY();
	}
}