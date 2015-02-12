#include "SDLRenderer.h"

namespace LM
{
	SDLRenderer::SDLRenderer(SDLRenderer* r)
	{
		m_pRenderer = r->Get();
	}

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

	void SDLRenderer::SetDrawColor(ColorRGBA c)
	{
		SDL_SetRenderDrawColor(m_pRenderer, c.r, c.g, c.b, c.a);
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

	//SDLTexture* SDLRenderer::BindWithTexture(SDLTexture* texture)
	//{
	//	//texture = new SDLTexture();
	//	return texture;
	//}
}