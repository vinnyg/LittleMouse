#pragma once
#include <SDL.h>
#include <String>

#include "Geometry.h"
#include "SDLImage.h"
#include "Structs.h"

namespace LM
{
	class SDLSurface
	{
	private:
		SDL_Surface* m_pSurface;
	public:
		SDLSurface(const std::string filepath);
		SDLSurface(SDL_Surface* surface);
		SDLSurface(Rect dimensions, int depth, MaskRGBA mask);
		SDLSurface(void* pixels, Rect dimensions, int depth, int pitch, MaskRGBA mask);
		~SDLSurface();
		void Free();
		SDLSurface Convert(SDL_PixelFormat* format);
		SDLSurface Convert(Uint32 pixelFormat);
		int Blit(Rect &srcRect, SDLSurface* dst, Rect &dstRect);
		int GetAlphaMod(Uint8* alpha) const;
		int GetColorMod(ColorRGB &rgb) const;
		int GetBlendMode(SDL_BlendMode* blendMode) const;
		int GetColorKey(Uint32* key) const;
		SDL_Surface* Get() const;
		int SetAlphaMod(Uint8 alpha);
		int SetColorMod(ColorRGB rgb);
		int SetBlendMode(SDL_BlendMode blendMode);
		int SetPalette(SDL_Palette* palette);
		int SetColorKey(bool isEnabled, Uint32 key);
		int SetRLE(bool isEnabled);
	};


}
