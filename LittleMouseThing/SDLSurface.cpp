#include "SDLSurface.h"

namespace LM
{
	SDLSurface::SDLSurface(const SDLSurface &surface) : m_pSurface(surface.Get())
	{
	}

	SDLSurface::SDLSurface(const std::string filepath)
	{
	#ifndef INCLUDE_SDL_IMAGE
		m_pSurface = SDL_LoadBMP(filepath.c_str());
	#else
		m_pSurface = IMG_Load(filepath.c_str());
	#endif
	}

	SDLSurface::SDLSurface(SDL_Surface* surface) : m_pSurface(surface) {}

	SDLSurface::SDLSurface(Rect dimensions, int depth, MaskRGBA mask)
	{
		m_pSurface = SDL_CreateRGBSurface(0, dimensions.GetWidth(), dimensions.GetHeight(), depth, mask.r, mask.g, mask.b, mask.a);
	}

	SDLSurface::SDLSurface(void* pixels, Rect dimensions, int depth, int pitch, MaskRGBA mask)
	{
		m_pSurface = SDL_CreateRGBSurfaceFrom(pixels, dimensions.GetWidth(), dimensions.GetHeight(), depth, pitch, mask.r, mask.g, mask.b, mask.a);
	}

	SDLSurface::~SDLSurface()
	{
		Free();
	}

	void SDLSurface::Free()
	{
		SDL_FreeSurface(m_pSurface);
	}

	SDLSurface SDLSurface::Convert(SDL_PixelFormat* format)
	{
		SDL_Surface* surface = SDL_ConvertSurface(m_pSurface, format, 0);

		return surface;
	}

	SDLSurface SDLSurface::Convert(Uint32 pixelFormat)
	{
		SDL_Surface* surface = SDL_ConvertSurfaceFormat(m_pSurface, pixelFormat, 0);

		return surface;
	}

	int SDLSurface::Blit(Rect &srcRect, SDLSurface* dst, Rect &dstRect)
	{
		return SDL_BlitSurface(m_pSurface, &srcRect, dst->Get(), &dstRect);
	}

	int SDLSurface::GetAlphaMod(Uint8* alpha) const
	{
		return SDL_GetSurfaceAlphaMod(m_pSurface, alpha);
	}

	int SDLSurface::GetColorMod(ColorRGB &rgb) const
	{
		return SDL_GetSurfaceColorMod(m_pSurface, &rgb.r, &rgb.g, &rgb.b);
	}

	int SDLSurface::GetBlendMode(SDL_BlendMode* blendMode) const
	{
		return SDL_GetSurfaceBlendMode(m_pSurface, blendMode);
	}

	int SDLSurface::GetColorKey(Uint32* key) const
	{
		return SDL_GetColorKey(m_pSurface, key);
	}

	SDL_Surface* SDLSurface::Get() const
	{
		return m_pSurface;
	}

	int SDLSurface::SetAlphaMod(Uint8 alpha)
	{
		return SDL_SetSurfaceAlphaMod(m_pSurface, alpha);
	}

	int SDLSurface::SetColorMod(ColorRGB rgb)
	{
		return SDL_SetSurfaceColorMod(m_pSurface, rgb.r, rgb.g, rgb.b);
	}

	int SDLSurface::SetBlendMode(SDL_BlendMode blendMode)
	{
		return SDL_SetSurfaceBlendMode(m_pSurface, blendMode);
	}

	int SDLSurface::SetColorKey(bool isEnabled, Uint32 key)
	{
		return SDL_SetColorKey(m_pSurface, static_cast<SDL_bool>(isEnabled), key);
	}

	int SDLSurface::SetRLE(bool isEnabled)
	{
		return SDL_SetSurfaceRLE(m_pSurface, static_cast<int>(isEnabled));
	}
}

