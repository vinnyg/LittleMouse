#include "RectPrimitive.h"

namespace LM
{
	RectPrimitive::RectPrimitive(SDLRenderer* renderer, Rect const rect, bool fill) : Primitive(renderer), m_Rect(rect), m_filled(fill)
	{

	}

	RectPrimitive::RectPrimitive(SDLRenderer* renderer, Rect const rect, bool fill, ColorRGB color) : Primitive(renderer, color), m_Rect(rect), m_filled(fill)
	{

	}

	RectPrimitive::RectPrimitive(SDLRenderer* renderer, Rect const rect, bool fill, ColorRGBA color) : Primitive(renderer, color), m_Rect(rect), m_filled(fill)
	{

	}

	RectPrimitive::~RectPrimitive()
	{
	}

	int RectPrimitive::Draw()
	{
		GetRenderer()->SetDrawColor(GetDrawRGBA());

		if (m_filled)
		{
			//SDL_RenderFillRect(GetRenderer()->Get(), m_Rect.get());
			return SDL_RenderFillRect(GetRenderer()->Get(), &m_Rect);
		}
		else
		{
			//SDL_RenderDrawRect(GetRenderer()->Get(), m_Rect.get());
			return SDL_RenderDrawRect(GetRenderer()->Get(), &m_Rect);
		}
	}
}
