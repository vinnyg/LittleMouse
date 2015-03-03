#include "SDLTexture.h"

namespace LM
{
	/*SDLTexture::SDLTexture(SDL_Texture* texture) : m_pTexture(texture), m_frameCount(1)
	{
	if (SDL_QueryTexture(texture, &m_format, &m_access, &m_frameWidth, &m_frameHeight) != 0)
	throw LM::Exception("SDL_QueryTexture");
	}*/

	SDLTexture::SDLTexture(SDLTexture const &texture) : m_pTexture(texture.Get()), m_pRenderer(texture.GetRenderer())
	{
		if (SDL_QueryTexture(texture.Get(), &m_format, &m_access, &m_width, &m_height) != 0)
			throw LM::Exception("SDL_QueryTexture");
	}

	SDLTexture::SDLTexture(SDLRenderer* renderer, SDLSurface* surface, int width, int height) : m_width(width), m_height(height), m_frameCount(1), m_pRenderer(renderer)
	{
		m_pTexture = SDL_CreateTextureFromSurface(renderer->Get(), surface->Get());
		if (!m_pTexture)
			throw LM::Exception("SDL_CreateTextureFromSurface");
		if (SDL_QueryTexture(m_pTexture, &m_format, &m_access, nullptr, nullptr) != 0)
			throw LM::Exception("SDL_QueryTexture");
	}

	SDLTexture::SDLTexture(SDLRenderer* renderer, SDLSurface* surface, int frames) : m_frameCount((frames > 0 ? frames : 1)), m_pRenderer(renderer)
	{
		int tmp_width, tmp_height;
		m_pTexture = SDL_CreateTextureFromSurface(renderer->Get(), surface->Get());
		if (!m_pTexture)
			throw LM::Exception("SDL_CreateTextureFromSurface");

		if (SDL_QueryTexture(m_pTexture, &m_format, &m_access, (m_frameCount > 1) ? &tmp_width : &m_width, (m_frameCount > 1) ? &tmp_height : &m_height) != 0)
			throw LM::Exception("SDL_QueryTexture");

		if (m_frameCount > 1)
		{
			m_width = tmp_width / m_frameCount;
			m_height = tmp_height / m_frameCount;
		}
	}

	SDLTexture::SDLTexture(SDLRenderer* renderer, SDLSurface* surface, int width, int height, int frames) : m_width(width), m_height(height), m_frameCount(frames)
	{
		m_pTexture = SDL_CreateTextureFromSurface(renderer->Get(), surface->Get());
		if (!m_pTexture)
			throw LM::Exception("SDL_CreateTextureFromSurface");
	}

	SDLTexture::SDLTexture(SDLRenderer* renderer, SDLSurface* surface) : m_pRenderer(renderer)
	{
		m_pTexture = SDL_CreateTextureFromSurface(renderer->Get(), surface->Get());
		if (!m_pTexture)
			throw LM::Exception("SDL_CreateTextureFromSurface");
		if (SDL_QueryTexture(m_pTexture, &m_format, &m_access, &m_width, &m_height) != 0)
			throw LM::Exception("SDL_QueryTexture");
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

	int SDLTexture::Query(int* width, int* height)
	{
		int res = SDL_QueryTexture(m_pTexture, nullptr, nullptr, width, height);
		if (res != 0)
			throw LM::Exception("SDL_QueryTexture");
		return res;
	}

	int SDLTexture::Query(Uint32* format, int* access, int* width, int* height)
	{
		int res = SDL_QueryTexture(m_pTexture, format, access, width, height);
		if (res != 0)
			throw LM::Exception("SDL_QueryTexture");
		return res;
	}

	int SDLTexture::GetAlphaMod(Uint8* alpha) const
	{
		int res = SDL_GetTextureAlphaMod(m_pTexture, alpha);
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

	int SDLTexture::GetBlendMode(SDL_BlendMode* blendMode) const
	{
		int res = SDL_GetTextureBlendMode(m_pTexture, blendMode);
		if (res != 0)
			throw LM::Exception("SDL_GetTextureBlendMode");
		return res;
	}

	/*Rect SDLTexture::GetDimensions() const
	{
		return Rect(0, 0, m_width, m_height);
	}*/

	int SDLTexture::GetFrameCount() const
	{
		return m_frameCount;
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

	/*void SDLTexture::CopyToRenderer(Rect &dstrect)
	{
		if (SDL_RenderCopy(m_pRenderer->Get(), m_pTexture, nullptr, &dstrect) != 0)
			throw LM::Exception("SDL_RenderCopyEx");
	}

	//Add a texture to the draw queue with additional parameters.
	void SDLTexture::CopyToRenderer(Rect &srcrect, Rect &dstrect, Point2<int> &center, double angle, SDLRenderFlipEnum flip)
	{
		if (SDL_RenderCopyEx(m_pRenderer->Get(), m_pTexture, &srcrect, &dstrect, angle, &center, static_cast<SDL_RendererFlip>(flip)) != 0)
			throw LM::Exception("SDL_RenderCopyEx");
	}*/

	void SDLTexture::IncrementRef(SDLTexturePassKey)
	{
		++refCount;
	}

	void SDLTexture::DecrementRef(SDLTexturePassKey)
	{
		--refCount;
	}
}