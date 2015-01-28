#ifndef SDLTEXTURE_H
#define SDLTEXTURE_H

#include <SDL.h>

class SDLTexture
{
private:
	SDL_Texture* m_pTexture;
	int m_textureWidth;
	int m_textureHeight;
	int m_textureFrames;
public:
	SDLTexture(int width, int height, int frames);
	~SDLTexture();
	int GetWidth() { return m_textureWidth; }
	int GetHeight() { return m_textureHeight; }
	int GetFrames() { return m_textureFrames; }
};

#endif