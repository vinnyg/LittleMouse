#include "Rect.h"

namespace LM
{
	Rect::Rect() : SDL_Rect()
	{
	}

	Rect::Rect(int const _x, int const _y, int const _w, int const _h) : SDL_Rect()
	{
		this->x = _x;
		this->y = _y;
		this->w = _w;
		this->h = _h;

	}


	Rect::Rect(SDL_Rect const &rect) : SDL_Rect()
	{
		this->x = rect.x;
		this->y = rect.y;
		this->w = rect.w;
		this->h = rect.h;
	}

	Rect::Rect(Rect const &rect) : SDL_Rect()
	{
		this->x = rect.x;
		this->y = rect.y;
		this->w = rect.w;
		this->h = rect.h;
	}

	Rect::Rect(Point2 const &position, Point2 const &dimension)
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