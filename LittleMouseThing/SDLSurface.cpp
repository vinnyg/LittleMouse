#include "SDLSurface.h"

namespace LM
{
	SDLSurface::SDLSurface(const std::string filepath)
	{
		m_pSurface = SDL_LoadBMP(filepath.c_str());
		
	}

	SDLSurface::SDLSurface(SDL_Surface* surface) : m_pSurface(surface) {}

	SDLSurface::SDLSurface(Rect dimensions, int depth, MaskRGBA mask)
	{
		m_pSurface = SDL_CreateRGBSurface(0, dimensions.GetWidth(), dimensions.GetHeight(), depth, mask.red, mask.green, mask.blue, mask.alpha);
	}

	SDLSurface::SDLSurface(void* pixels, Rect dimensions, int depth, int pitch, MaskRGBA mask)
	{
		m_pSurface = SDL_CreateRGBSurfaceFrom(pixels, dimensions.GetWidth(), dimensions.GetHeight(), depth, pitch, mask.red, mask.green, mask.blue, mask.alpha);
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

	int SDLSurface::GetColorMod(ColorRGB &rgb) const
	{
		return SDL_GetSurfaceColorMod(m_pSurface, &rgb.red, &rgb.green, &rgb.blue);
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

	int SDLSurface::SetColorMod(ColorRGB rgb)
	{
		return SDL_SetSurfaceColorMod(m_pSurface, rgb.red, rgb.green, rgb.blue);
	}

	int SDLSurface::SetBlendMode(SDL_BlendMode blendMode)
	{
		return SDL_SetSurfaceBlendMode(m_pSurface, blendMode);
	}
}

