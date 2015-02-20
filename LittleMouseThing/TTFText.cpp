#include "TTFText.h"

namespace LM
{
	/*TTFText::TTFText(std::string text, SDLTTFont* font, CharEncoding encoding) : m_text(text), m_font(std::make_shared<SDLTTFont>(font)), m_unicode(0), m_encoding(encoding != CharEncoding::ENC_UNICODE ? encoding : CharEncoding::ENC_LATIN1)
	{

	}*/

	TTFText::TTFText(std::string text, SDLTTFont* font, CharEncoding encoding) : m_text(text), m_font(font), m_unicode(0), m_encoding(encoding != CharEncoding::ENC_UNICODE ? encoding : CharEncoding::ENC_LATIN1)
	{

	}

	/*TTFText::TTFText(Uint16 text, SDLTTFont* font) : m_unicode(text), m_font(std::make_shared<SDLTTFont>(font)), m_text(""), m_encoding(CharEncoding::ENC_UNICODE)
	{
	}*/

	TTFText::TTFText(Uint16 text, SDLTTFont* font) : m_unicode(text), m_font(font), m_text(""), m_encoding(CharEncoding::ENC_UNICODE)
	{
	}

	TTFText::~TTFText()
	{
	}

	SDLSurface TTFText::RenderToSurface(RenderMode mode, ColorRGBA fg, ColorRGBA bg = { 0, 0, 0, 0 })
	{
		SDL_Color c;
		c.r = fg.r;
		c.g = fg.g;
		c.b = fg.b;
		c.a = fg.a;

		SDL_Color bc;
		bc.r = bg.r;
		bc.g = bg.g;
		bc.b = bg.b;
		bc.a = bg.a;

		SDL_Surface* s = nullptr;

		switch (m_encoding)
		{
		case CharEncoding::ENC_LATIN1:
			switch (mode)
			{
			case RenderMode::RenderSolid:
				s = TTF_RenderText_Solid(m_font->Get(), m_text.c_str(), c);
				break;
			case RenderMode::RenderShaded:
				s = TTF_RenderText_Shaded(m_font->Get(), m_text.c_str(), c, bc);
				break;
			case RenderMode::RenderBlended:
				s = TTF_RenderText_Blended(m_font->Get(), m_text.c_str(), c);
				break;
			}
			break;
		case CharEncoding::ENC_UNICODE:
			switch (mode)
			{
			case RenderMode::RenderSolid:
				s = TTF_RenderUNICODE_Solid(m_font->Get(), &m_unicode, c);
				break;
			case RenderMode::RenderShaded:
				s = TTF_RenderUNICODE_Shaded(m_font->Get(), &m_unicode, c, bc);
				break;
			case RenderMode::RenderBlended:
				s = TTF_RenderUNICODE_Blended(m_font->Get(), &m_unicode, c);
				break;
			}
			break;
		case CharEncoding::ENC_UTF8:
			switch (mode)
			{
			case RenderMode::RenderSolid:
				s = TTF_RenderUTF8_Solid(m_font->Get(), m_text.c_str(), c);
				break;
			case RenderMode::RenderShaded:
				s = TTF_RenderUTF8_Shaded(m_font->Get(), m_text.c_str(), c, bc);
				break;
			case RenderMode::RenderBlended:
				s = TTF_RenderUTF8_Blended(m_font->Get(), m_text.c_str(), c);
				break;
			}
			break;
		}

		return SDLSurface(s);
	}

	void TTFText::SetText(std::string text)
	{
		if (m_encoding != CharEncoding::ENC_UNICODE)
		{
			m_text = text;
			m_unicode = 0;
		}
	}

	void TTFText::SetText(Uint16 text)
	{
		if (m_encoding == CharEncoding::ENC_UNICODE)
		{
			m_unicode = text;
			m_text.clear();
		}
	}

	void TTFText::SetFont(SDLTTFont* font)
	{
		m_font = font;
		//m_font = std::make_shared<SDLTTFont>(font);
	}

	int TTFText::GetTextSize(Rect* dimensions) const
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

	void TTFText::GetText(std::string* text) const
	{
		if (m_encoding != CharEncoding::ENC_UNICODE)
			*text = m_text;
	}

	void TTFText::GetText(Uint16* text) const
	{
		if (m_encoding == CharEncoding::ENC_UNICODE)
			*text = m_unicode;
	}

	SDLTTFont* TTFText::GetFont() const
	{
		return m_font;// m_font.get();
	}
}

