#pragma once
#include "Primitive.h"

namespace LM
{
	class PixelPrimitive :
		public Primitive
	{
	private:
		Point2 m_pos;
	public:
		PixelPrimitive(SDLRenderer* renderer, Point2 position);
		PixelPrimitive(SDLRenderer* renderer, Point2 position, ColorRGB color);
		PixelPrimitive(SDLRenderer* renderer, Point2 position, ColorRGBA color);
		~PixelPrimitive();
		void SetPosition(Point2 pos);
		void SetPosition(int x, int y);
		Point2 GetPosition() const;
		virtual int Draw();
	};
}

