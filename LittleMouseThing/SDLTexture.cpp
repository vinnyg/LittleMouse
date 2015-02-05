#include "SDLTexture.h"

namespace LM
{
	SDLTexture::SDLTexture(SDL_Texture* texture) : m_pTexture(texture), m_frameCount(1)
	{
		SDL_QueryTexture(m_pTexture, &m_format, &m_access, &m_width, &m_height);
	}

	SDLTexture::SDLTexture(SDL_Texture* texture, int width, int height) : m_pTexture(texture), m_width(width), m_height(height), m_frameCount(1)
	{
		SDL_QueryTexture(m_pTexture, &m_format, &m_access, nullptr, nullptr);
	}

	SDLTexture::SDLTexture(SDL_Texture* texture, int frames) : m_pTexture(texture), m_frameCount((frames > 0 ? frames : 1))
	{
		int tmp_width, tmp_height;
		SDL_QueryTexture(m_pTexture, &m_format, &m_access, (m_frameCount > 1) ? &tmp_width : &m_width, (m_frameCount > 1) ? &tmp_height : &m_height);
		if (m_frameCount > 1)
		{
			m_width = tmp_width / m_frameCount;
			m_height = tmp_height / m_frameCount;
		}
	}

	SDLTexture::SDLTexture(SDL_Texture* texture, int width, int height, int frames) : m_pTexture(texture), m_width(width), m_height(height), m_frameCount(frames)
	{
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

	int SDLTexture::Query(int* width, int* height)
	{
		return SDL_QueryTexture(m_pTexture, nullptr, nullptr, width, height);
	}

	int SDLTexture::Query(Uint32* format, int* access, int* width, int* height)
	{
		return SDL_QueryTexture(m_pTexture, format, access, width, height);
	}

	int SDLTexture::GetWidth() const
	{
		return m_width;
	}

	int SDLTexture::GetHeight() const
	{
		return m_height;
	}

	int SDLTexture::GetFrameCount() const
	{
		return m_frameCount;
	}

	int SDLTexture::SetAlphaMod(Uint8 alpha)
	{
		return SDL_SetTextureAlphaMod(m_pTexture, alpha);
	}

	int SDLTexture::SetColorMod(Uint8 r, Uint8 g, Uint8 b)
	{
		return SDL_SetTextureColorMod(m_pTexture, r, g, b);
	}

	int SDLTexture::SetBlendMode(SDL_BlendMode blendMode)
	{
		return SDL_SetTextureBlendMode(m_pTexture, blendMode);
	}
}