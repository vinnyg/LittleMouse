#pragma once
#include "Primitive.h"

namespace LM
{
	template <class LineType>
	class LinePrimitive :
		public Primitive
	{
	private:
		Point2<LineType> m_srcPos;
		Point2<LineType> m_dstPos;
	public:
		LinePrimitive(SDLRenderer* renderer, Point2<LineType> srcPosition, Point2<LineType> dstPosition) : Primitive(renderer), m_srcPos(srcPosition), m_dstPos(dstPosition) {}

		LinePrimitive(SDLRenderer* renderer, Point2<LineType> srcPosition, Point2<LineType> dstPosition, ColorRGB color) : Primitive(renderer, color), m_srcPos(srcPosition), m_dstPos(dstPosition) {}

		LinePrimitive(SDLRenderer* renderer, Point2<LineType> srcPosition, Point2<LineType> dstPosition, ColorRGBA color) : Primitive(renderer, color), m_srcPos(srcPosition), m_dstPos(dstPosition) {}

		~LinePrimitive() {}

		void SetSrcPosition(Point2<LineType> pos) { m_srcPos = pos; }

		void SetSrcPosition(LineType x, LineType y)
		{
			m_srcPos.SetX(x);
			m_srcPos.SetY(y);
		}

		void SetDstPosition(Point2<LineType> pos) { m_dstPos = pos;  }

		void SetDstPosition(LineType x, LineType y)
		{
			m_dstPos.SetX(x);
			m_dstPos.SetY(y);
		}

		Point2<LineType> GetSrcPosition() const { return m_srcPos; }

		Point2<LineType> GetDstPosition() const { return m_dstPos; }

		virtual int Draw()
		{
			GetRenderer()->SetDrawColor(GetDrawRGBA());
			return SDL_RenderDrawLine(GetRenderer()->Get(), m_srcPos.GetX(), m_srcPos.GetY(), m_dstPos.GetX(), m_dstPos.GetY());
		}
	};
}

