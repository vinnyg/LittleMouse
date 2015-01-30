#include "LMRect.h"

namespace LM
{
	LMRect::LMRect()
	{
		x = 0;
		y = 0;
		w = 0;
		h = 0;
	}

	LMRect::LMRect(const SDL_Rect &rect)
	{
		x = rect.x;
		y = rect.y;
		w = rect.w;
		h = rect.h;
	}

	LMRect::LMRect(const LMRect &rect)
	{
		x = rect.x;
		y = rect.y;
		w = rect.w;
		h = rect.h;
	}

	LMRect::LMRect(const LMPoint &position, LMPoint &dimension)
	{
		x = position.GetX();
		y = position.GetY();
		w = dimension.GetX();
		h = dimension.GetY();
	}

	void LMRect::SetPosition(LMPoint &pos)
	{
		x = pos.GetX();
		y = pos.GetY();
	}

	void LMRect::SetDimension(LMPoint &dimension)
	{
		w = dimension.GetX();
		h = dimension.GetY();
	}
}