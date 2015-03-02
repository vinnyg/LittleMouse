#pragma once
#include "Primitive.h"

namespace LM
{
	template <class rectType>
	class RectPrimitive : public Primitive
	{
	private:
		Rect<rectType> m_Rect;

		bool m_filled;
	public:
		RectPrimitive(SDLRenderer* renderer, Rect<rectType> const rect, bool fill) : Primitive(renderer), m_Rect(rect), m_filled(fill) {}

		RectPrimitive(SDLRenderer* renderer, Rect<rectType> const rect, bool fill, ColorRGB color) : Primitive(renderer, color), m_Rect(rect), m_filled(fill) {}

		RectPrimitive(SDLRenderer* renderer, Rect<rectType> const rect, bool fill, ColorRGBA color) : Primitive(renderer, color), m_Rect(rect), m_filled(fill){}

		~RectPrimitive() {}

		virtual int Draw()
		{
			GetRenderer()->SetDrawColor(GetDrawRGBA());

			if (m_filled)
				return SDL_RenderFillRect(GetRenderer()->Get(), &m_Rect);
			else
				return SDL_RenderDrawRect(GetRenderer()->Get(), &m_Rect);
		}
	};
}

