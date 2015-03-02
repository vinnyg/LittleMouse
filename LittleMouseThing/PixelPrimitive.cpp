#include "PixelPrimitive.h"

namespace LM
{
	/*PixelPrimitive::PixelPrimitive(SDLRenderer* renderer, Point2<int> position) : Primitive(renderer), m_pos(position)
	{
	}

	PixelPrimitive::PixelPrimitive(SDLRenderer* renderer, Point2<int> position, ColorRGB color) : Primitive(renderer, color), m_pos(position)
	{
	}

	PixelPrimitive::PixelPrimitive(SDLRenderer* renderer, Point2<int> position, ColorRGBA color) : Primitive(renderer, color), m_pos(position)
	{
	}

	PixelPrimitive::~PixelPrimitive()
	{
	}

	void PixelPrimitive::SetPosition(Point2<int> pos)
	{
		m_pos = pos;
	}

	void PixelPrimitive::SetPosition(int x, int y)
	{
		m_pos.SetX(x);
		m_pos.SetY(y);
	}

	Point2<int> PixelPrimitive::GetPosition() const
	{
		return m_pos;
	}

	int PixelPrimitive::Draw()
	{
	#ifndef INCLUDE_SDL_GFX
		GetRenderer()->SetDrawColor(GetDrawRGBA());
		return SDL_RenderDrawPoint(GetRenderer()->Get(), m_pos.GetX(), m_pos.GetY());
	#else
		return pixelRGBA(GetRenderer()->Get(), m_pos.GetX(), m_pos.GetY(), GetDrawColor().r, GetDrawColor().b, GetDrawColor().g, GetDrawAlpha());
	#endif
	}*/
}