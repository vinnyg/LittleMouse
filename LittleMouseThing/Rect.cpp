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

	Rect::Rect(const int _x, const int _y, const int _w, const int _h) : x(_x), y(_y), w(_w), h(_h)
	{
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

	Point2 Rect::GetPosition()
	{
		return Point2(x, y);
	}

	Point2 Rect::GetDimensions()
	{
		return Point2(x, y);
	}
}