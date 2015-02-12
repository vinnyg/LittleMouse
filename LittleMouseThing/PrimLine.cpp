#include "PrimLine.h"

namespace LM
{
	PrimLine::PrimLine(SDLRenderer* renderer, Point2 srcPosition, Point2 dstPosition) : Primitive(renderer), m_srcPos(srcPosition), m_dstPos(dstPosition)
	{

	}

	PrimLine::PrimLine(SDLRenderer* renderer, Point2 srcPosition, Point2 dstPosition, ColorRGB color) : Primitive(renderer, color), m_srcPos(srcPosition), m_dstPos(dstPosition)
	{

	}

	PrimLine::PrimLine(SDLRenderer* renderer, Point2 srcPosition, Point2 dstPosition, ColorRGBA color) : Primitive(renderer, color), m_srcPos(srcPosition), m_dstPos(dstPosition)
	{

	}

	PrimLine::~PrimLine()
	{
	}

	void PrimLine::SetSrcPosition(Point2 pos)
	{
		m_srcPos = pos;
	}

	void PrimLine::SetSrcPosition(int x, int y)
	{
		m_srcPos.SetX(x);
		m_srcPos.SetY(y);
	}

	void PrimLine::SetDstPosition(Point2 pos)
	{
		m_dstPos = pos;
	}

	void PrimLine::SetDstPosition(int x, int y)
	{
		m_dstPos.SetX(x);
		m_dstPos.SetY(y);
	}

	Point2 PrimLine::GetSrcPosition() const
	{
		return m_srcPos;
	}

	Point2 PrimLine::GetDstPosition() const
	{
		return m_dstPos;
	}

	int PrimLine::Draw()
	{
		GetRenderer()->SetDrawColor(GetDrawRGBA());
		return SDL_RenderDrawLine(GetRenderer()->Get(), m_srcPos.GetX(), m_srcPos.GetY(), m_dstPos.GetX(), m_dstPos.GetY());
	}
}
