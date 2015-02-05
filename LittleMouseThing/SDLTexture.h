#pragma once

#include <SDL.h>
#include "Geometry.h"

namespace LM
{
	class SDLTexture
	{
	private:
		SDL_Texture* m_pTexture;
		int m_frameWidth;
		int m_frameHeight;
		int m_frameCount;
		Uint32 m_format;
		int m_access;

		//float m_animationSpeed;
	public:
		SDLTexture(SDL_Texture* texture);
		SDLTexture(SDL_Texture* texture, int frameWidth, int frameHeight);
		SDLTexture(SDL_Texture* texture, int frameCount);
		SDLTexture(SDL_Texture* texture, int frameWidth, int frameHeight, int frameCount);
		~SDLTexture();
		void Destroy();
		int Query(int* width, int* height);
		int Query(Uint32* format, int* access, int* width, int* height);
		int GetAlphaMod(Uint8* alpha) const;
		int GetColorMod(Uint8* r, Uint8* g, Uint8* b) const;
		int GetBlendMode(SDL_BlendMode* blendMode) const;
		int GetWidth() const;	//Returns the width of an individual frame.
		int GetHeight() const;	//Returns the height of an individual frame.
		int GetFrameCount() const;
		int SetAlphaMod(Uint8 alpha);
		int SetColorMod(Uint8 r, Uint8 g, Uint8 b);
		int SetBlendMode(SDL_BlendMode blendMode);
	};
}