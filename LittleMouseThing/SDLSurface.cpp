#include "SDLSurface.h"

namespace LM
{
	SDLSurface::SDLSurface(SDL_Surface* surface) : m_pSurface(surface) {}

	SDLSurface::SDLSurface(int width, int height, int depth, Uint32 Rmask, Uint32 GMask, Uint32 Bask, Uint32 Amask)
	{
		m_pSurface = SDL_CreateRGBSurface(0, width, height, depth, Rmask, GMask, Bask, Amask);
	}

	SDLSurface::SDLSurface(void* pixels, int width, int height, int depth, int pitch, Uint32 Rmask, Uint32 GMask, Uint32 Bask, Uint32 Amask)
	{
		m_pSurface = SDL_CreateRGBSurfaceFrom(pixels, width, height, depth, pitch, Rmask, GMask, Bask, Amask);
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
		SDL_BlitSurface(m_pSurface, &srcRect, dst->Get(), &dstRect);
	}

	int SDLSurface::GetAlphaMod(Uint8* alpha) const
	{
		return SDL_GetSurfaceAlphaMod(m_pSurface, alpha);
	}

	int SDLSurface::GetColorMod(Uint8* r, Uint8* g, Uint8* b) const
	{
		return SDL_GetSurfaceColorMod(m_pSurface, r, g, b);
	}

	int SDLSurface::GetBlendMode(SDL_BlendMode* blendMode) const
	{
		return SDL_GetSurfaceBlendMode(m_pSurface, blendMode);
	}

	SDL_Surface* SDLSurface::Get() const
	{
		return m_pSurface;
	}

	int SDLSurface::SetAlphaMod(Uint8 alpha)
	{
		return SDL_SetSurfaceAlphaMod(m_pSurface, alpha);
	}

	int SDLSurface::SetColorMod(Uint8 r, Uint8 g, Uint8 b)
	{
		return SDL_SetSurfaceColorMod(m_pSurface, r, g, b);
	}

	int SDLSurface::SetBlendMode(SDL_BlendMode blendMode)
	{
		return SDL_SetSurfaceBlendMode(m_pSurface, blendMode);
	}
}

