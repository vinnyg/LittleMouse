#pragma once

#include <SDL.h>
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
		int m_frameWidth;
		int m_frameHeight;
		int m_frameCount;
		Uint32 m_format;
		int m_access;

		//float m_animationSpeed;
	public:
		SDLTexture(SDL_Texture* texture);
		SDLTexture(SDLRenderer* renderer, SDLSurface* surface);
		SDLTexture(SDLRenderer* renderer, SDLSurface* surface, int frameWidth, int frameHeight);
		SDLTexture(SDLRenderer* renderer, SDLSurface* surface, int frameCount);
		SDLTexture(SDLRenderer* renderer, SDLSurface* surface, int frameWidth, int frameHeight, int frameCount);
		~SDLTexture();
		void Destroy();
		int Query(int* width, int* height);
		int Query(Uint32* format, int* access, int* width, int* height);
		int GetAlphaMod(Uint8* alpha) const;
		int GetColorMod(ColorRGB &rgb) const;
		int GetBlendMode(SDL_BlendMode* blendMode) const;
		int GetWidth() const;	//Returns the width of an individual frame.
		int GetHeight() const;	//Returns the height of an individual frame.
		int GetFrameCount() const;
		int SetAlphaMod(Uint8 alpha);
		int SetColorMod(ColorRGB rgb);
		int SetBlendMode(SDL_BlendMode blendMode);
		void CopyToRenderer(SDLRenderer* renderer);
		void CopyToRenderer(SDLRenderer* renderer, Rect &dstrect);
		void CopyToRenderer(SDLRenderer* renderer, Rect &srcrect, Rect &dstrect, Point2 &center, double angle, SDLRenderFlipEnum flip);
	};
}