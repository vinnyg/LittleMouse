#pragma once
#include "Primitive.h"

namespace LM
{
	class PrimPixel :
		public Primitive
	{
	private:
		Point2 m_pos;
	public:
		PrimPixel(SDLRenderer* renderer, Point2 position);
		PrimPixel(SDLRenderer* renderer, Point2 position, ColorRGB color);
		PrimPixel(SDLRenderer* renderer, Point2 position, ColorRGBA color);
		~PrimPixel();
		void SetPosition(int x, int y);
		Point2 GetPosition() const;
		virtual int Draw();
	};
}

