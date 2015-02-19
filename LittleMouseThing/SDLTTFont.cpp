#include "SDLTTFont.h"

namespace LM
{
	SDLTTFont::SDLTTFont(std::string file, int size)
	{
		m_font = TTF_OpenFont(file.c_str(), size);
	}


	SDLTTFont::~SDLTTFont()
	{
		if (m_font)
		{
			TTF_CloseFont(m_font);
		}
	}

	TTF_Font* SDLTTFont::Get() const
	{
		return m_font;
	}

	void SDLTTFont::SetStyle(int style)
	{
		TTF_SetFontStyle(m_font, style);
	}

	void SDLTTFont::SetOutline(int width)
	{
		TTF_SetFontOutline(m_font, width);
	}

	void SDLTTFont::SetHinting(int hinting)
	{
		TTF_SetFontHinting(m_font, hinting);
	}

	void SDLTTFont::SetKerning(bool enable)
	{
		m_kerning = enable;
		TTF_SetFontKerning(m_font, m_kerning ? 1 : 0);
	}

	int SDLTTFont::GetStyle() const
	{
		return TTF_GetFontStyle(m_font);
	}

	int SDLTTFont::GetOutline() const
	{
		return TTF_GetFontOutline(m_font);
	}

	int SDLTTFont::GetHinting() const
	{
		return TTF_GetFontHinting(m_font);
	}

	bool SDLTTFont::GetKerning() const
	{
		int r = TTF_GetFontKerning(m_font);
		return (r ? true : false);
	}

	void SDLTTFont::GetFontMetrics(FontMetrics* metrics) const
	{
		metrics->maxHeight = TTF_FontHeight(m_font);
		metrics->maxAscent = TTF_FontAscent(m_font);
		metrics->maxDescent = TTF_FontDescent(m_font);
		metrics->lineSkip = TTF_FontLineSkip(m_font);
	}

	void SDLTTFont::GetFaceAttributes(FaceAttributes* attributes) const
	{
		attributes->numFaces = TTF_FontFaces(m_font);
		attributes->faceIsFixedWidth = (TTF_FontFaceIsFixedWidth(m_font) ? true : false);
		attributes->faceFamilyName = TTF_FontFaceFamilyName(m_font);
		attributes->faceStyleName = TTF_FontFaceStyleName(m_font);
	}

	int SDLTTFont::GetGlyphMetrics(GlyphMetrics* metrics, char ch) const
	{
		return TTF_GlyphMetrics(m_font, ch, &(metrics->minXOffset), &(metrics->minYOffset), &(metrics->maxXOffset), &(metrics->maxXOffset), &(metrics->advanceOffset));
	}

	int SDLTTFont::GlyphIsProvided(char ch) const
	{
		return TTF_GlyphIsProvided(m_font, ch);
	}
}
