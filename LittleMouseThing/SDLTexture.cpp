#include "SDLTexture.h"

namespace LM
{
	/*SDLTexture::SDLTexture(SDL_Texture* texture) : m_pTexture(texture), m_frameCount(1)
	{
	if (SDL_QueryTexture(texture, &m_format, &m_access, &m_frameWidth, &m_frameHeight) != 0)
	throw LM::Exception("SDL_QueryTexture");
	}*/

	SDLTexture::SDLTexture(SDLTexture const &texture) : m_pTexture(texture.Get()), m_pRenderer(texture.GetRenderer()), m_dimensions(0, 0)
	{
		int w, h;
		if (SDL_QueryTexture(texture.Get(), &m_format, &m_access, &w, &h) != 0)
			throw LM::Exception("SDL_QueryTexture");
		m_dimensions.SetX(w);
		m_dimensions.SetY(h);
	}

	SDLTexture::SDLTexture(SDLRenderer* renderer, SDLSurface* surface, LM::Point2<int> dimensions) : m_dimensions(dimensions), m_pRenderer(renderer)
	{
		m_pTexture = SDL_CreateTextureFromSurface(renderer->Get(), surface->Get());
		if (!m_pTexture)
			throw LM::Exception("SDL_CreateTextureFromSurface");
		if (SDL_QueryTexture(m_pTexture, &m_format, &m_access, nullptr, nullptr) != 0)
			throw LM::Exception("SDL_QueryTexture");
	}

	SDLTexture::SDLTexture(SDLRenderer* renderer, SDLSurface* surface) : m_pRenderer(renderer), m_dimensions(0, 0)
	{
		int w, h;
		m_pTexture = SDL_CreateTextureFromSurface(renderer->Get(), surface->Get());
		if (!m_pTexture)
			throw LM::Exception("SDL_CreateTextureFromSurface");
		if (SDL_QueryTexture(m_pTexture, &m_format, &m_access, &w, &h) != 0)
			throw LM::Exception("SDL_QueryTexture");
		m_dimensions.SetX(w);
		m_dimensions.SetY(h);
	}

	SDLTexture::~SDLTexture()
	{
		Destroy();
	}

	void SDLTexture::Destroy()
	{
		if (m_pTexture != nullptr)
		{
			SDL_DestroyTexture(m_pTexture);
		}
	}

	SDL_Texture* SDLTexture::Get() const
	{
		return m_pTexture;
	}

	SDLRenderer* SDLTexture::GetRenderer() const
	{
		return m_pRenderer;
	}

	int SDLTexture::Query(LM::Point2<int> &dimensions)
	{
		int w, h;
		int res = SDL_QueryTexture(m_pTexture, nullptr, nullptr, &w, &h);
		if (res != 0)
			throw LM::Exception("SDL_QueryTexture");
		dimensions.SetX(w);
		dimensions.SetY(h);
		return res;
	}

	int SDLTexture::Query(Uint32 &format, int &access, LM::Point2<int> &dimensions)
	{
		int w, h;
		int res = SDL_QueryTexture(m_pTexture, &format, &access, &w, &h);
		if (res != 0)
			throw LM::Exception("SDL_QueryTexture");
		dimensions.SetX(w);
		dimensions.SetY(h);
		return res;
	}

	int SDLTexture::GetAlphaMod(Uint8 &alpha) const
	{
		int res = SDL_GetTextureAlphaMod(m_pTexture, &alpha);
		if (res != 0)
			throw LM::Exception("SDL_GetTextureAlphaMod");
		return res;
	}

	int SDLTexture::GetColorMod(ColorRGB &rgb) const
	{
		int res = SDL_GetTextureColorMod(m_pTexture, &rgb.r, &rgb.g, &rgb.b);
		if (res != 0)
			throw LM::Exception("SDL_GetTextureColorMod");
		return res;
	}

	int SDLTexture::GetBlendMode(SDL_BlendMode &blendMode) const
	{
		int res = SDL_GetTextureBlendMode(m_pTexture, &blendMode);
		if (res != 0)
			throw LM::Exception("SDL_GetTextureBlendMode");
		return res;
	}

	int SDLTexture::SetAlphaMod(Uint8 alpha)
	{
		int res = SDL_SetTextureAlphaMod(m_pTexture, alpha);
		if (res != 0)
			throw LM::Exception("SDL_SetAlphaMod");
		return res;
	}

	int SDLTexture::SetColorMod(ColorRGB rgb)
	{
		int res = SDL_SetTextureColorMod(m_pTexture, rgb.r, rgb.g, rgb.b);
		if (res != 0)
			throw LM::Exception("SDL_SetTextureColorMod");
		return res;
	}

	int SDLTexture::SetBlendMode(SDL_BlendMode blendMode)
	{
		int res = SDL_SetTextureBlendMode(m_pTexture, blendMode);
		if (res != 0)
			throw LM::Exception("SDL_SetTextureBlendMode");
		return res;
	}
}