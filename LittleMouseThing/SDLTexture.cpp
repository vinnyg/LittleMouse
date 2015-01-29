#include "SDLTexture.h"

namespace LM
{
	SDLTexture::SDLTexture(int width, int height, int frames) : m_width(width), m_height(height), m_frameCount(frames)
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
}