#include "SDLRenderer.h"

namespace LM
{
	SDLRenderer::SDLRenderer(SDL_Window* window, int index, Uint32 flags)
	{
		if (SDL_WasInit(SDL_INIT_VIDEO) != 0)
		{
			m_pRenderer = SDL_CreateRenderer(window, index, flags);
		}

		if (m_pRenderer != nullptr)
		{
			SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 255);
			SDL_RenderClear(m_pRenderer);
			SDL_RenderPresent(m_pRenderer);
		}
	}

	SDLRenderer::~SDLRenderer()
	{
		if (m_pRenderer != nullptr)
		{
			SDL_DestroyRenderer(m_pRenderer);
		}
	}

	//Add a texture to the draw queue with additional parameters.
	void SDLRenderer::RenderCopy(SDL_Texture* tex, Rect &srcrect, Rect &dstrect, Point2 &center, double angle, SDLRenderFlipEnum flip)
	{
		SDL_RenderCopyEx(m_pRenderer, tex, (&srcrect != nullptr) ? &srcrect : nullptr, (&dstrect != nullptr) ? &dstrect : nullptr, angle, (&center != nullptr) ? &center : nullptr, static_cast<SDL_RendererFlip>(flip));
	}

	void SDLRenderer::SetDrawColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
	{
		SDL_SetRenderDrawColor(m_pRenderer, r, g, b, a);
	}

	void SDLRenderer::Clear()
	{
		SDL_RenderClear(m_pRenderer);
	}


	void SDLRenderer::Present()
	{
		SDL_RenderPresent(m_pRenderer);
	}

	void SDLRenderer::Render() //Defunct
	{
		//SDL_SetRenderDrawColor(m_pRenderer, r, g, b, a);
		//SDL_RenderClear(m_pRenderer);
		//SDL_RenderPresent(m_pRenderer);
	}
	
	void SDLRenderer::SetTarget(SDL_Texture* tex)
	{
		SDL_SetRenderTarget(m_pRenderer, tex);
	}

	SDLTexture* SDLRenderer::BindWithTexture(SDLTexture* texture)
	{
		//texture = new SDLTexture();
		return texture;
	}
}