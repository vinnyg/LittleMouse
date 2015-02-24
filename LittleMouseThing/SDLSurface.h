#pragma once
#include <SDL.h>
#include <String>
#include "SDLExtensionConfig.h"
#include "Exception.h"
#include "Geometry.h"
#include "Structs.h"
#ifdef INCLUDE_SDL_IMAGE
#include "SDLImage.h"
#endif


namespace LM
{
	class SDLSurface
	{
	private:
		SDL_Surface* m_pSurface;
	public:
		SDLSurface(SDLSurface const &surface);
		SDLSurface(std::string const filepath);
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
