#pragma once

#include <SDL.h>
#include "Exception.h"
#include "SDLRenderer.h"
#include "SDLSurface.h"
#include "Geometry.h"
#include "Structs.h"

namespace LM
{
	class SDLTexture
	{
	private:
		SDL_Texture* m_pTexture;
		SDLRenderer* m_pRenderer;
		int m_width;
		int m_height;
		int m_frameCount;
		Uint32 m_format;
		int m_access;
	public:
		/*SDLTexture(SDL_Texture* texture);*/
		SDLTexture(SDLTexture const &texture);
		SDLTexture(SDLRenderer* renderer, SDLSurface* surface);
		SDLTexture(SDLRenderer* renderer, SDLSurface* surface, int frameWidth, int frameHeight);
		SDLTexture(SDLRenderer* renderer, SDLSurface* surface, int frameCount);
		SDLTexture(SDLRenderer* renderer, SDLSurface* surface, int frameWidth, int frameHeight, int frameCount);
		~SDLTexture();
		void Destroy();
		SDL_Texture* Get() const;
		SDLRenderer* GetRenderer() const;
		int Query(int* width, int* height);
		int Query(Uint32* format, int* access, int* width, int* height);
		int GetAlphaMod(Uint8* alpha) const;
		int GetColorMod(ColorRGB &rgb) const;
		int GetBlendMode(SDL_BlendMode* blendMode) const;
		Rect GetDimensions() const;
		int GetFrameCount() const;
		int SetAlphaMod(Uint8 alpha);
		int SetColorMod(ColorRGB rgb);
		int SetBlendMode(SDL_BlendMode blendMode);
		void CopyToRenderer(Rect &dstrect);
		void CopyToRenderer(Rect &srcrect, Rect &dstrect, Point2 &center, double angle, SDLRenderFlipEnum flip);
	};
}