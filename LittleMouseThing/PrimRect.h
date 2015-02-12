#pragma once
#include "Primitive.h"

namespace LM
{
	class PrimRect : public Primitive
	{
	private:
		//std::shared_ptr<Rect> m_Rect;
		Rect m_Rect;
		bool m_filled;
	public:
		/*PrimRect(SDLRenderer* renderer, const Rect* rect, bool fill);
		PrimRect(SDLRenderer* renderer, const Rect* rect, bool fill, ColorRGB color);
		PrimRect(SDLRenderer* renderer, const Rect* rect, bool fill, ColorRGBA color);*/

		PrimRect(SDLRenderer* renderer, const Rect rect, bool fill);
		PrimRect(SDLRenderer* renderer, const Rect rect, bool fill, ColorRGB color);
		PrimRect(SDLRenderer* renderer, const Rect rect, bool fill, ColorRGBA color);
		~PrimRect();
		virtual int Draw();
	};
}

