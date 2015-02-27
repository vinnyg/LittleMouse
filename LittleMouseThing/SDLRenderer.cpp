#include "SDLRenderer.h"

namespace LM
{
	SDLRenderer::SDLRenderer(SDLRenderer* r)
	{
		m_pRenderer = r->Get();
	}

	SDLRenderer::SDLRenderer(SDL_Window* window, int index, Uint32 flags)
	{
		if (m_pRenderer = SDL_CreateRenderer(window, index, flags))
		{
			if (m_pRenderer)
			{
				SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 255);
				SDL_RenderClear(m_pRenderer);
				SDL_RenderPresent(m_pRenderer);
			}
		}
		else
			throw LM::Exception("SDLRenderer");
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
		int res = SDL_SetRenderDrawColor(m_pRenderer, c.r, c.g, c.b, c.a);
		if (res != 0)
			throw LM::Exception("SDL_SetRenderDrawColor");
		return res;
	}

	int SDLRenderer::SetDrawColor(ColorRGB c)
	{
		int res = SDL_SetRenderDrawColor(m_pRenderer, c.r, c.g, c.b, 255);
		if (res != 0)
			throw LM::Exception("SDL_SetRenderDrawColor");
		return res;
	}

	int SDLRenderer::SetDrawBlendMode(SDL_BlendMode blendMode)
	{
		int res = SDL_SetRenderDrawBlendMode(m_pRenderer, blendMode);
		if (res != 0)
			throw LM::Exception("SDL_SetRenderBlendMode");
		return res;
	}

	int SDLRenderer::GetDrawColor(ColorRGBA* c)
	{
		int res = SDL_GetRenderDrawColor(m_pRenderer, &(c->r), &(c->g), &(c->b), &(c->a));
		if (res != 0)
			throw LM::Exception("SDL_GetRendererDrawColor");
		return res;
	}

	int SDLRenderer::GetDrawBlendMode(SDL_BlendMode* blendMode)
	{
		int res = SDL_GetRenderDrawBlendMode(m_pRenderer, blendMode);
		if (res != 0)
			throw LM::Exception("SDL_GetRendererDrawBlendMode");
		return res;
	}

	int SDLRenderer::Clear()
	{
		int res = SDL_RenderClear(m_pRenderer);
		if (res != 0)
			throw LM::Exception("SDL_RenderClear");
		return res;
	}

	void SDLRenderer::Present()
	{
		SDL_RenderPresent(m_pRenderer);
	}
	
	int SDLRenderer::SetTarget(SDL_Texture* tex)
	{
		int res = SDL_SetRenderTarget(m_pRenderer, tex);
		if (res != 0)
			throw LM::Exception("SDL_SetRenderTarget");
		return res;
	}
}