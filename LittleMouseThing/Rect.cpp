#include "Rect.h"

namespace LM
{
	Rect::Rect() : SDL_Rect()
	{
	}

	Rect::Rect(const int _x, const int _y, const int _w, const int _h) : SDL_Rect()
	{
		this->x = _x;
		this->y = _y;
		this->w = _w;
		this->h = _h;

	}


	Rect::Rect(const SDL_Rect &rect) : SDL_Rect()
	{
	}

	Rect::Rect(const Rect &rect) : SDL_Rect()
	{
	}

	Rect::Rect(const Point2 &position, Point2 &dimension) 
	{
		this->x = position.GetX();
		this->y = position.GetY();
		this->w = dimension.GetX();
		this->h = dimension.GetY();
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