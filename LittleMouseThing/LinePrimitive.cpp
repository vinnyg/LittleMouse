#include "LinePrimitive.h"

/*namespace LM
{
	LinePrimitive::LinePrimitive(SDLRenderer* renderer, Point2<int> srcPosition, Point2<int> dstPosition) : Primitive(renderer), m_srcPos(srcPosition), m_dstPos(dstPosition)
	{

	}

	LinePrimitive::LinePrimitive(SDLRenderer* renderer, Point2<int> srcPosition, Point2<int> dstPosition, ColorRGB color) : Primitive(renderer, color), m_srcPos(srcPosition), m_dstPos(dstPosition)
	{

	}

	LinePrimitive::LinePrimitive(SDLRenderer* renderer, Point2<int> srcPosition, Point2<int> dstPosition, ColorRGBA color) : Primitive(renderer, color), m_srcPos(srcPosition), m_dstPos(dstPosition)
	{

	}

	LinePrimitive::~LinePrimitive()
	{
	}

	void LinePrimitive::SetSrcPosition(Point2<int> pos)
	{
		m_srcPos = pos;
	}

	void LinePrimitive::SetSrcPosition(int x, int y)
	{
		m_srcPos.SetX(x);
		m_srcPos.SetY(y);
	}

	void LinePrimitive::SetDstPosition(Point2<int> pos)
	{
		m_dstPos = pos;
	}

	void LinePrimitive::SetDstPosition(int x, int y)
	{
		m_dstPos.SetX(x);
		m_dstPos.SetY(y);
	}

	Point2<int> LinePrimitive::GetSrcPosition() const
	{
		return m_srcPos;
	}

	Point2<int> LinePrimitive::GetDstPosition() const
	{
		return m_dstPos;
	}

	int LinePrimitive::Draw()
	{
		GetRenderer()->SetDrawColor(GetDrawRGBA());
		return SDL_RenderDrawLine(GetRenderer()->Get(), m_srcPos.GetX(), m_srcPos.GetY(), m_dstPos.GetX(), m_dstPos.GetY());
	}
}
*/