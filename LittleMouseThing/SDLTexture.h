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
		LM::Point2<int> m_dimensions;
		Uint32 m_format;
		int m_access;
	public:
		/*SDLTexture(SDL_Texture* texture);*/
		SDLTexture(SDLTexture const &texture);
		SDLTexture(SDLRenderer* renderer, SDLSurface* surface);
		SDLTexture(SDLRenderer* renderer, SDLSurface* surface, LM::Point2<int> dimensions);
		~SDLTexture();
		void Destroy();
		SDL_Texture* Get() const;
		SDLRenderer* GetRenderer() const;
		int Query(LM::Point2<int> &dimensions);
		int Query(Uint32& format, int& access, LM::Point2<int> &dimensions);
		int GetAlphaMod(Uint8 &alpha) const;
		int GetColorMod(ColorRGB &rgb) const;
		int GetBlendMode(SDL_BlendMode &blendMode) const;
		int SetAlphaMod(Uint8 alpha);
		int SetColorMod(ColorRGB rgb);
		int SetBlendMode(SDL_BlendMode blendMode);

		Point2<int> GetDimensions() const
		{
			return m_dimensions;
		}

		template<typename rectType>
		void CopyToRenderer(Rect<rectType> &dstrect)
		{
			if (SDL_RenderCopy(m_pRenderer->Get(), m_pTexture, nullptr, &dstrect) != 0)
				throw LM::Exception("SDL_RenderCopyEx");
		}

		template<typename rectType>
		void CopyToRenderer(Rect<int> &srcrect, Rect<rectType> &dstrect, Point2<int> &center, double angle, SDLRenderFlipEnum flip)
		{
			if (SDL_RenderCopyEx(m_pRenderer->Get(), m_pTexture, &srcrect, &dstrect, angle, &center, static_cast<SDL_RendererFlip>(flip)) != 0)
				throw LM::Exception("SDL_RenderCopyEx");
		}
	};
}