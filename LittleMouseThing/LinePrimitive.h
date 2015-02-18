#pragma once
#include "Primitive.h"

namespace LM
{
	class LinePrimitive :
		public Primitive
	{
	private:
		Point2 m_srcPos;
		Point2 m_dstPos;
	public:
		LinePrimitive(SDLRenderer* renderer, Point2 srcPosition, Point2 dstPosition);
		LinePrimitive(SDLRenderer* renderer, Point2 srcPosition, Point2 dstPosition, ColorRGB color);
		LinePrimitive(SDLRenderer* renderer, Point2 srcPosition, Point2 dstPosition, ColorRGBA color);
		~LinePrimitive();
		void SetSrcPosition(Point2 pos);
		void SetSrcPosition(int x, int y);
		void SetDstPosition(Point2 pos);
		void SetDstPosition(int x, int y);
		Point2 GetSrcPosition() const;
		Point2 GetDstPosition() const;
		virtual int Draw();
	};
}

