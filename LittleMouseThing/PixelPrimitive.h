#pragma once
#include "Primitive.h"

namespace LM
{
	template <class ptType>
	class PixelPrimitive : public Primitive
	{
	private:
		Point2<ptType> m_pos;
	public:

		PixelPrimitive(SDLRenderer* renderer, Point2<ptType> position) : Primitive(renderer), m_pos(position) {}

		PixelPrimitive(SDLRenderer* renderer, Point2<ptType> position, ColorRGB color) : Primitive(renderer, color), m_pos(position) {}

		PixelPrimitive(SDLRenderer* renderer, Point2<ptType> position, ColorRGBA color) : Primitive(renderer, color), m_pos(position) {}

		~PixelPrimitive() {}

		void SetPosition(ptType x, ptType y)
		{
			m_pos.SetX(x);
			m_pos.SetY(y);
		}

		void SetPosition(Point2<ptType> pos) { m_pos = pos; }

		Point2<ptType> GetPosition() const { return m_pos; }

		virtual int Draw()
		{
		#ifndef INCLUDE_SDL_GFX
			GetRenderer()->SetDrawColor(GetDrawRGBA());
			return SDL_RenderDrawPoint(GetRenderer()->Get(), m_pos.GetX(), m_pos.GetY());
		#else
			return pixelRGBA(GetRenderer()->Get(), m_pos.GetX(), m_pos.GetY(), GetDrawColor().r, GetDrawColor().b, GetDrawColor().g, GetDrawAlpha());
		#endif
		}
	};
}

