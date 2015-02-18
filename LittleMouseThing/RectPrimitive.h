#pragma once
#include "Primitive.h"

namespace LM
{
	class RectPrimitive : public Primitive
	{
	private:
		//std::shared_ptr<Rect> m_Rect;
		Rect m_Rect;
		bool m_filled;
	public:
		/*PrimRect(SDLRenderer* renderer, const Rect* rect, bool fill);
		PrimRect(SDLRenderer* renderer, const Rect* rect, bool fill, ColorRGB color);
		PrimRect(SDLRenderer* renderer, const Rect* rect, bool fill, ColorRGBA color);*/

		RectPrimitive(SDLRenderer* renderer, const Rect rect, bool fill);
		RectPrimitive(SDLRenderer* renderer, const Rect rect, bool fill, ColorRGB color);
		RectPrimitive(SDLRenderer* renderer, const Rect rect, bool fill, ColorRGBA color);
		~RectPrimitive();
		virtual int Draw();
	};
}

