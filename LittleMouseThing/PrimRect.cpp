#include "PrimRect.h"

namespace LM
{
	/*PrimRect::PrimRect(SDLRenderer* renderer, const Rect* rect, bool fill) : Primitive(renderer), m_Rect(std::make_shared<Rect>(rect)), m_filled(fill)
	{

	}

	PrimRect::PrimRect(SDLRenderer* renderer, const Rect* rect, bool fill, ColorRGB color) : Primitive(renderer, color), m_Rect(std::make_shared<Rect>(rect)), m_filled(fill)
	{

	}

	PrimRect::PrimRect(SDLRenderer* renderer, const Rect* rect, bool fill, ColorRGBA color) : Primitive(renderer, color), m_Rect(std::make_shared<Rect>(rect)), m_filled(fill)
	{

	}*/

	PrimRect::PrimRect(SDLRenderer* renderer, const Rect rect, bool fill) : Primitive(renderer), m_Rect(rect), m_filled(fill)
	{

	}

	PrimRect::PrimRect(SDLRenderer* renderer, const Rect rect, bool fill, ColorRGB color) : Primitive(renderer, color), m_Rect(rect), m_filled(fill)
	{

	}

	PrimRect::PrimRect(SDLRenderer* renderer, const Rect rect, bool fill, ColorRGBA color) : Primitive(renderer, color), m_Rect(rect), m_filled(fill)
	{

	}

	PrimRect::~PrimRect()
	{
	}

	int PrimRect::Draw()
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
