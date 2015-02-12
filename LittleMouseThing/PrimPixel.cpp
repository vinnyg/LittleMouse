#include "PrimPixel.h"

namespace LM
{
	PrimPixel::PrimPixel(SDLRenderer* renderer, Point2 position) : Primitive(renderer), m_pos(position)
	{
	}

	PrimPixel::PrimPixel(SDLRenderer* renderer, Point2 position, ColorRGB color) : Primitive(renderer, color), m_pos(position)
	{
	}

	PrimPixel::PrimPixel(SDLRenderer* renderer, Point2 position, ColorRGBA color) : Primitive(renderer, color), m_pos(position)
	{
	}

	PrimPixel::~PrimPixel()
	{
	}

	void PrimPixel::SetPosition(int x, int y)
	{
		m_pos.SetX(x);
		m_pos.SetY(y);
	}

	Point2 PrimPixel::GetPosition() const
	{
		return m_pos;
	}

	int PrimPixel::Draw()
	{
	#ifndef INCLUDE_SDL_GFX
		return 0;
	#else INCLUDE_SDL_GFX
		return pixelRGBA(GetRenderer()->Get(), m_pos.GetX(), m_pos.GetY(), GetDrawColor().r, GetDrawColor().b, GetDrawColor().g, GetDrawAlpha());
	#endif
	}
}