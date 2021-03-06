#include "Primitive.h"

namespace LM
{
	Primitive::Primitive(SDLRenderer &renderer) : m_Renderer(renderer), m_drawRGBA({ 0, 0, 0, 255 }) {}

	Primitive::Primitive(SDLRenderer &renderer, ColorRGB color) : m_Renderer(renderer), m_drawRGBA({ color.r, color.g, color.b, 255 }) {}

	Primitive::Primitive(SDLRenderer &renderer, ColorRGBA color) : m_Renderer(renderer), m_drawRGBA({ color.r, color.g, color.b, color.a }) {}

	Primitive::~Primitive()
	{
	}

	void Primitive::SetDrawColor(ColorRGB color)
	{
		m_drawRGBA.r = color.r;
		m_drawRGBA.g = color.g;
		m_drawRGBA.b = color.b;
		/*#ifndef INCLUDE_SDL_GFX
		ColorRGBA c = {color.r, color.g, color.b, 255};
		#endif*/
	}

	void Primitive::SetDrawAlpha(Uint8 alpha)
	{
		m_drawRGBA.a = alpha;
	}

	void Primitive::SetDrawRGBA(ColorRGBA color)
	{
		m_drawRGBA = color;
		#ifdef INCLUDE_SDL_GFX
		//ColorRGBA c = { color.r, color.g, color.b, 255 };
		//m_pRenderer->SetDrawColor(c);
		#endif
	}


	SDLRenderer* Primitive::GetRenderer() const
	{
		//return m_Renderer.get();
		return &m_Renderer;
	}

	ColorRGB Primitive::GetDrawColor() const
	{
		ColorRGB c;
		c.r = m_drawRGBA.r;
		c.g = m_drawRGBA.g;
		c.b = m_drawRGBA.b;
		return c;
	}

	Uint8 Primitive::GetDrawAlpha() const
	{
		return m_drawRGBA.a;
	}

	ColorRGBA Primitive::GetDrawRGBA() const
	{
		return m_drawRGBA;
	}
}
