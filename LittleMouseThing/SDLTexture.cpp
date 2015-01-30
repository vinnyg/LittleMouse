#include "SDLTexture.h"

namespace LM
{
	SDLTexture::SDLTexture(SDL_Texture* texture)
	{
		m_pTexture = texture;
		SDL_QueryTexture(m_pTexture, &m_format, &m_access, &m_width, &m_height);
		m_frameCount = 1;
	}

	SDLTexture::SDLTexture(SDL_Texture* texture, int width, int height)
	{
		m_pTexture = texture;
		m_width = width;
		m_height = height;
		SDL_QueryTexture(m_pTexture, &m_format, &m_access, nullptr, nullptr);
		m_frameCount = 1;
	}

	SDLTexture::SDLTexture(SDL_Texture* texture, int frames)
	{
		//m_animationSpeed = 1.0f;
		//m_pTexture = SDL_CreateTexture();
	}

	SDLTexture::SDLTexture(SDL_Texture* texture, int width, int height, int frames) : m_pTexture(texture), m_width(width), m_height(height), m_frameCount(frames)
	{
		//m_animationSpeed = 1.0f;
		//m_pTexture = SDL_CreateTexture();
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