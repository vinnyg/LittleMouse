#include "SDLTexture.h"

namespace LM
{
	SDLTexture::SDLTexture(SDL_Texture* texture) : m_pTexture(texture), m_frameCount(1)
	{
		SDL_QueryTexture(m_pTexture, &m_format, &m_access, &m_frameWidth, &m_frameHeight);
	}

	SDLTexture::SDLTexture(SDL_Texture* texture, int width, int height) : m_pTexture(texture), m_frameWidth(width), m_frameHeight(height), m_frameCount(1)
	{
		SDL_QueryTexture(m_pTexture, &m_format, &m_access, nullptr, nullptr);
	}

	SDLTexture::SDLTexture(SDL_Texture* texture, int frames) : m_pTexture(texture), m_frameCount((frames > 0 ? frames : 1))
	{
		int tmp_width, tmp_height;
		SDL_QueryTexture(m_pTexture, &m_format, &m_access, (m_frameCount > 1) ? &tmp_width : &m_frameWidth, (m_frameCount > 1) ? &tmp_height : &m_frameHeight);
		if (m_frameCount > 1)
		{
			m_frameWidth = tmp_width / m_frameCount;
			m_frameHeight = tmp_height / m_frameCount;
		}
	}

	SDLTexture::SDLTexture(SDL_Texture* texture, int width, int height, int frames) : m_pTexture(texture), m_frameWidth(width), m_frameHeight(height), m_frameCount(frames)
	{
	}

	/*SDLTexture::SDLTexture(SDLSurface* surface)
	{
		m_pTexture = SDL_CreateTextureFromSurface(surface->Get());
	}*/

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

	int SDLTexture::Query(int* width, int* height)
	{
		return SDL_QueryTexture(m_pTexture, nullptr, nullptr, width, height);
	}

	int SDLTexture::Query(Uint32* format, int* access, int* width, int* height)
	{
		return SDL_QueryTexture(m_pTexture, format, access, width, height);
	}

	int SDLTexture::GetAlphaMod(Uint8* alpha) const
	{
		return SDL_GetTextureAlphaMod(m_pTexture, alpha);
	}

	int SDLTexture::GetColorMod(ColorRGB &rgb) const
	{
		return SDL_GetTextureColorMod(m_pTexture, &rgb.red, &rgb.green, &rgb.blue);
	}

	int SDLTexture::GetBlendMode(SDL_BlendMode* blendMode) const
	{
		return SDL_GetTextureBlendMode(m_pTexture, blendMode);
	}

	int SDLTexture::GetWidth() const
	{
		return m_frameWidth;
	}

	int SDLTexture::GetHeight() const
	{
		return m_frameHeight;
	}

	int SDLTexture::GetFrameCount() const
	{
		return m_frameCount;
	}

	int SDLTexture::SetAlphaMod(Uint8 alpha)
	{
		return SDL_SetTextureAlphaMod(m_pTexture, alpha);
	}

	int SDLTexture::SetColorMod(ColorRGB rgb)
	{
		return SDL_SetTextureColorMod(m_pTexture, rgb.red, rgb.green, rgb.blue);
	}

	int SDLTexture::SetBlendMode(SDL_BlendMode blendMode)
	{
		return SDL_SetTextureBlendMode(m_pTexture, blendMode);
	}
}