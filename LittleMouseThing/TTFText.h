#pragma once
#include <memory>
#include <string>
#include "CharEncodingEnum.h"
#include "SDLSurface.h"
#include "Geometry.h"
#include "SDLTTFont.h"
#include "TextRenderModeEnum.h"

namespace LM
{
	class TTFText
	{
	private:
		std::string m_text;
		std::shared_ptr<SDLTTFont> m_font;
		Uint16 m_unicode;
		CharEncoding m_encoding;
	public:
		TTFText(std::string text, SDLTTFont* font, CharEncoding encoding);
		TTFText(Uint16 text, SDLTTFont* font);
		~TTFText();
		SDLSurface RenderToSurface(RenderMode mode, ColorRGBA fg, ColorRGBA bg);
		void SetText(std::string text);
		void SetText(Uint16 text);
		void SetFont(SDLTTFont* font);
		int GetTextSize(Rect* dimensions) const;
		void GetText(std::string* text) const;
		void GetText(Uint16* text) const;
		SDLTTFont* GetFont() const;
	};
}