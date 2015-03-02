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
		//std::shared_ptr<SDLTTFont> m_font;
		SDLTTFont* m_font;
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
		void GetText(std::string* text) const;
		void GetText(Uint16* text) const;
		SDLTTFont* GetFont() const;

		template <typename rectType>
		int GetTextSize(Rect<rectType>* dimensions) const
		{
			int w, h;
			int res;
			switch (m_encoding)
			{
			case CharEncoding::ENC_LATIN1:
				res = TTF_SizeText(m_font->Get(), m_text.c_str(), &w, &h);
				break;
			case CharEncoding::ENC_UNICODE:
				res = TTF_SizeUNICODE(m_font->Get(), &m_unicode, &w, &h);
				break;
			case CharEncoding::ENC_UTF8:
				res = TTF_SizeUTF8(m_font->Get(), m_text.c_str(), &w, &h);
				break;
			}

			dimensions->SetWidth(w);
			dimensions->SetHeight(h);
			return res;
		}

	};
}