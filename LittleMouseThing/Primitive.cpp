#include "Primitive.h"

namespace LM
{
	Primitive::Primitive(SDLRenderer* renderer) : m_pRenderer(std::make_shared<SDLRenderer>(renderer)), m_drawColor({ 0, 0, 0 }), m_drawAlpha(255)
	{
	}

	Primitive::Primitive(SDLRenderer* renderer, ColorRGB color) : m_pRenderer(std::make_shared<SDLRenderer>(renderer)), m_drawColor(color), m_drawAlpha(255)
	{
	}

	Primitive::Primitive(SDLRenderer* renderer, ColorRGBA color) : m_pRenderer(std::make_shared<SDLRenderer>(renderer)), m_drawColor({ color.r, color.g, color.b }), m_drawAlpha(color.a)
	{
	}

	/*Primitive::Primitive(SDLRenderer* renderer) : m_pRenderer(renderer), m_drawColor({ 0, 0, 0 }), m_drawAlpha(255)
	{
	}

	Primitive::Primitive(SDLRenderer* renderer, ColorRGB color) : m_pRenderer(renderer), m_drawColor(color), m_drawAlpha(255)
	{
	}

	Primitive::Primitive(SDLRenderer* renderer, ColorRGBA color) : m_pRenderer(renderer), m_drawColor({ color.r, color.g, color.b }), m_drawAlpha(color.a)
	{
	}*/

	Primitive::~Primitive()
	{
	}

	void Primitive::SetDrawColor(ColorRGB color)
	{
		m_drawColor = color;
		#ifndef INCLUDE_SDL_GFX
		ColorRGBA c = {color.r, color.g, color.b, 255};
		m_pRenderer->SetDrawColor(c);
		#endif
	}

	void Primitive::SetDrawAlpha(Uint8 alpha)
	{
		m_drawAlpha = alpha;
	}

	void Primitive::SetDrawRGBA(ColorRGBA color)
	{
		//m_drawColor = color;
		#ifdef INCLUDE_SDL_GFX
		ColorRGBA c = { color.r, color.g, color.b, 255 };
		m_pRenderer->SetDrawColor(c);
		#endif
	}


	SDLRenderer* Primitive::GetRenderer() const
	{
		return m_pRenderer.get();
	}

	ColorRGB Primitive::GetDrawColor() const
	{
		return m_drawColor;
	}

	Uint8 Primitive::GetDrawAlpha() const
	{
		return m_drawAlpha;
	}
}
