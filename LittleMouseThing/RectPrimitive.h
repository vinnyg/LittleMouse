#pragma once
#include "Primitive.h"

namespace LM
{
	class RectPrimitive : public Primitive
	{
	private:
		Rect m_Rect;
		bool m_filled;
	public:
		RectPrimitive(SDLRenderer* renderer, Rect const rect, bool fill);
		RectPrimitive(SDLRenderer* renderer, Rect const rect, bool fill, ColorRGB color);
		RectPrimitive(SDLRenderer* renderer, Rect const rect, bool fill, ColorRGBA color);
		~RectPrimitive();
		virtual int Draw();
	};
}

