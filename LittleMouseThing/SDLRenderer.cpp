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

	int SDLRenderer::SetDrawColor(ColorRGBA c)
	{
		return SDL_SetRenderDrawColor(m_pRenderer, c.r, c.g, c.b, c.a);
	}

	int SDLRenderer::SetDrawColor(ColorRGB c)
	{
		return SDL_SetRenderDrawColor(m_pRenderer, c.r, c.g, c.b, 255);
	}

	int SDLRenderer::SetDrawBlendMode(SDL_BlendMode blendMode)
	{
		return SDL_SetRenderDrawBlendMode(m_pRenderer, blendMode);
	}

	int SDLRenderer::GetDrawColor(ColorRGBA* c)
	{
		return SDL_GetRenderDrawColor(m_pRenderer, &(c->r), &(c->g), &(c->b), &(c->a));
	}

	int SDLRenderer::GetDrawBlendMode(SDL_BlendMode* blendMode)
	{
		return SDL_GetRenderDrawBlendMode(m_pRenderer, blendMode);
	}

	void SDLRenderer::Clear()
	{
		SDL_RenderClear(m_pRenderer);
	}

	void SDLRenderer::Present()
	{
		SDL_RenderPresent(m_pRenderer);
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