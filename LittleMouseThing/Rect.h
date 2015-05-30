#pragma once

#include <SDL.h>
#include "Point2.h"

namespace LM
{
	template<class rectType>
	class Rect// : public SDL_Rect
	{
	private:
		rectType x, y;
		rectType w, h;
	public:
		Rect() = delete;

		Rect(SDL_Rect const &rect)// : SDL_Rect()
		{
			this->x = rect.x;
			this->y = rect.y;
			this->w = rect.w;
			this->h = rect.h;
		}

		Rect(Rect<rectType> const &rect)// : SDL_Rect()
		{
			this->x = rect.x;
			this->y = rect.y;
			this->w = rect.w;
			this->h = rect.h;
		}

		Rect(Point2<rectType> const &position, Point2<rectType> const &dimension)
		{
			this->x = position.GetX();
			this->y = position.GetY();
			this->w = dimension.GetX();
			this->h = dimension.GetY();
		}

		Rect(rectType const _x, rectType const _y, rectType const _w, rectType const _h)// : SDL_Rect()
		{
			this->x = _x;
			this->y = _y;
			this->w = _w;
			this->h = _h;
		}

		void SetX(rectType _x) { x = _x; }
		void SetY(rectType _y) { y = _y; }
		void SetWidth(rectType _w) { w = _w; }
		void SetHeight(rectType _h) { h = _h; }

		void SetPosition(Point2<rectType> &pos)
		{
			x = pos.GetX();
			y = pos.GetY();
		}

		void SetDimension(Point2<rectType> &dimension)
		{
			w = dimension.GetX();
			h = dimension.GetY();
		}

		rectType GetX() const { return x; }
		rectType GetY() const { return y; }
		rectType GetWidth() const { return w; }
		rectType GetHeight() const { return h; }

		Point2<rectType> GetPosition() const
		{
			return Point2<rectType>(x, y);
		}

		Point2<rectType> GetDimensions() const
		{
			return Point2<rectType>(w, h);
		}

		SDL_Rect ToSDLRect()
		{
			return SDL_Rect { int(x), int(y), int(w), int(h) };
		}

		Rect<rectType> &operator=(Rect<rectType> const &rhs)
		{
			this->x = rhs.GetX();
			this->y = rhs.GetY();
			this->w = rhs.GetWidth();
			this->h = rhs.GetHeight();
			return *this;
		}
	};
}
