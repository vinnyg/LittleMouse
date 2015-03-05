#include "SDLSurface.h"

namespace LM
{
	SDLSurface::SDLSurface(SDLSurface const &surface) : m_pSurface(surface.Get()) {}

	SDLSurface::SDLSurface(std::string const filepath)
	{
	#ifndef INCLUDE_SDL_IMAGE
		{
			if ((m_pSurface = SDL_LoadBMP(filepath.c_str())) == nullptr)
				throw LM::Exception("SDL_LoadBMP");
		}
	#else
		if ((m_pSurface = IMG_Load(filepath.c_str())) == nullptr)
			throw LM::Exception("IMG_Load");
	#endif
	}

	SDLSurface::SDLSurface(SDL_Surface* surface) : m_pSurface(surface) {}

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
		if (!surface)
			throw LM::Exception("SDL_CreateRGBSurface");
		return surface;
	}

	SDLSurface SDLSurface::Convert(Uint32 pixelFormat)
	{
		SDL_Surface* surface = SDL_ConvertSurfaceFormat(m_pSurface, pixelFormat, 0);
		if (!surface)
			throw LM::Exception("SDL_CreateRGBSurface");
		return surface;
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

