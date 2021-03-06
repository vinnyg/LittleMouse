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
		SDL_Rect m_srcRect;
		SDL_Rect m_dstRect;
		SDL_Point m_center;

		LM::Point2<int> p = { 0, 0 };
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
		int SetAsRendererTarget();

		Point2<int> GetDimensions() const
		{
			return m_dimensions;
		}

		//template<typename rectType>
		void CopyToRenderer(Rect<int> &dstrect)
		{
			m_dstRect = dstrect.ToSDLRect();
			if (SDL_RenderCopy(m_pRenderer->Get(), m_pTexture, nullptr, &m_dstRect) != 0)
				throw LM::Exception("SDL_RenderCopyEx");
		}

		//template<typename rectType>
		void CopyToRenderer(Rect<int> &srcrect, Rect<int> &dstrect, Point2<int> &center, double angle, SDLRenderFlipEnum flip)
		{
			m_srcRect = srcrect.ToSDLRect();
			m_dstRect = dstrect.ToSDLRect();
			m_center = center.ToSDLPoint();
			if (SDL_RenderCopyEx(m_pRenderer->Get(), m_pTexture, &m_srcRect, &m_dstRect, angle, &m_center, static_cast<SDL_RendererFlip>(flip)) != 0)
				throw LM::Exception("SDL_RenderCopyEx");
		}
	};
}