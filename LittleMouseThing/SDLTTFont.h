#pragma once

#include <SDL.h>
#include <SDL_ttf.h>
#include <string>
#include "FontAttributeStructs.h"

namespace LM
{
	class SDLTTFont
	{
	private:
		TTF_Font* m_font;
		int m_fontStyle;
		int m_outlineWidth;
		int m_hinting;
		int m_kerning;
	public:
		SDLTTFont(const SDLTTFont &font);
		SDLTTFont(SDLTTFont* font);
		SDLTTFont(std::string file, int size);
		~SDLTTFont();
		TTF_Font* Get() const;
		void SetStyle(int style);
		void SetOutline(int width);
		void SetHinting(int hinting);
		void SetKerning(bool enable);
		int GetStyle() const;
		int GetOutline() const;
		int GetHinting() const;
		bool GetKerning() const;

		void GetFontMetrics(FontMetrics* metrics) const;
		void GetFaceAttributes(FaceAttributes* attributes) const;
		int GetGlyphMetrics(GlyphMetrics* metrics, char ch) const;
		int GlyphIsProvided(char ch) const;
	};
}



