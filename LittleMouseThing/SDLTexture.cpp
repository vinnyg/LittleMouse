#include "SDLTexture.h"

SDLTexture::SDLTexture(int width, int height, int frames) : m_textureWidth(width), m_textureHeight(height), m_textureFrames(frames)
{
	m_pTexture = SDL_CreateTexture()
}

SDLTexture::~SDLTexture()
{
	if (m_pTexture != nullptr)
	{ 
		SDL_DestroyTexture(m_pTexture);
	}
}
