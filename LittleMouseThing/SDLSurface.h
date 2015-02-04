#pragma once
#include <SDL.h>
#include "Geometry.h"

namespace LM
{
	class SDLSurface
	{
	private:
		SDL_Surface* m_pSurface;
	public:
		SDLSurface(SDL_Surface* surface);
		SDLSurface(int width, int height, int depth, Uint32 Rmask, Uint32 GMask, Uint32 Bask, Uint32 Amask);
		SDLSurface(void* pixels, int width, int height, int depth, int pitch, Uint32 Rmask, Uint32 GMask, Uint32 Bask, Uint32 Amask);
		~SDLSurface();
		void FreeSurface();
		SDLSurface Convert(SDL_PixelFormat* format);
		SDLSurface Convert(Uint32 pixelFormat);
		int Blit(Rect &srcRect, SDLSurface* dst, Rect &dstRect);
		int GetAlphaMod(Uint8* alpha) const;
		int GetColorMod(Uint8* r, Uint8* g, Uint8* b) const;
		int GetBlendMode(SDL_BlendMode* blendMode) const;
		SDL_Surface* GetSurface() const;
		//SDLSurface* GetWindowSurface();
		int SetAlphaMod(Uint8 alpha);
		int SetColorMod(Uint8 r, Uint8 g, Uint8 b);
		int SetBlendMode(SDL_BlendMode blendMode);
		int SetPalette(SDL_Palette* palette);
		//int SetRLE(int flag);
	};


}
