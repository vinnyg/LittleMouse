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
		int GetFrameCount() const;
		int SetAlphaMod(Uint8 alpha);
		int SetColorMod(ColorRGB rgb);
		int SetBlendMode(SDL_BlendMode blendMode);

		Point2<int> GetDimensions() const
		{
			return Point2<int>(m_width, m_height);
		}

		template<typename rectType>
		void CopyToRenderer(Rect<rectType> &dstrect)
		{
			if (SDL_RenderCopy(m_pRenderer->Get(), m_pTexture, nullptr, &dstrect) != 0)
				throw LM::Exception("SDL_RenderCopyEx");
		}

		template<typename rectType>
		void CopyToRenderer(Rect<rectType> &srcrect, Rect<rectType> &dstrect, Point2<int> &center, double angle, SDLRenderFlipEnum flip)
		{
			if (SDL_RenderCopyEx(m_pRenderer->Get(), m_pTexture, &srcrect, &dstrect, angle, &center, static_cast<SDL_RendererFlip>(flip)) != 0)
				throw LM::Exception("SDL_RenderCopyEx");
		}
	};
}