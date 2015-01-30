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
		if (m_pTexture != nullptr)
		{
			SDL_DestroyTexture(m_pTexture);
		}
	}

	int SDLTexture::QueryTexture(int* width, int* height)
	{
		return SDL_QueryTexture(m_pTexture, nullptr, nullptr, width, height);
	}

	int SDLTexture::QueryTexture(Uint32* format, int* access, int* width, int* height)
	{
		return SDL_QueryTexture(m_pTexture, format, access, width, height);
	}
}