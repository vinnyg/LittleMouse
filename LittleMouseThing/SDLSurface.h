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
		~SDLSurface();
		void Free();
		SDLSurface Convert(SDL_PixelFormat* format);
		SDLSurface Convert(Uint32 pixelFormat);
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

		template<typename rectType>
		SDLSurface(Rect<rectType> dimensions, int depth, MaskRGBA mask)
		{
			if ((m_pSurface = SDL_CreateRGBSurface(0, dimensions.GetWidth(), dimensions.GetHeight(), depth, mask.r, mask.g, mask.b, mask.a)) == nullptr)
				throw LM::Exception("SDL_CreateRGBSurface");
		}

		template<typename rectType>
		SDLSurface(void* pixels, Rect<rectType> dimensions, int depth, int pitch, MaskRGBA mask)
		{
			if ((m_pSurface = SDL_CreateRGBSurfaceFrom(pixels, dimensions.GetWidth(), dimensions.GetHeight(), depth, pitch, mask.r, mask.g, mask.b, mask.a)) == nullptr)
				throw LM::Exception("SDL_CreateRGBSurface");
		}

		template<typename rectType>
		int Blit(Rect<rectType> &srcRect, SDLSurface* dst, Rect<rectType> &dstRect)
		{
			int res = SDL_BlitSurface(m_pSurface, &srcRect, dst->Get(), &dstRect);
			if (!res)
				throw LM::Exception("SDL_BlitSurface");
			return res;
		}
	};


}
