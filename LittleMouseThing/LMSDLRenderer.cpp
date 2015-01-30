#include "LMSDLRenderer.h"

//This is a change.

namespace LM
{
	LMSDLRenderer::LMSDLRenderer(SDL_Window* window, int index, Uint32 flags)
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

	LMSDLRenderer::~LMSDLRenderer()
	{
		if (m_pRenderer != nullptr)
		{
			SDL_DestroyRenderer(m_pRenderer);
		}
	}

	//Add a texture to the draw queue with additional parameters.
	void LMSDLRenderer::RenderCopy(SDL_Texture* tex, LMRect &srcrect, LMRect &dstrect, LMPoint &center, double angle = 0.0)
	{
		SDL_RenderCopyEx(m_pRenderer, tex, (&srcrect != nullptr) ? &srcrect : nullptr, (&dstrect != nullptr) ? &dstrect : nullptr, angle, (&center != nullptr) ? &center : nullptr, SDL_FLIP_NONE);
	}

	void LMSDLRenderer::SetDrawColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
	{
		SDL_SetRenderDrawColor(m_pRenderer, r, g, b, a);
	}

	void LMSDLRenderer::Clear()
	{
		SDL_RenderClear(m_pRenderer);
	}


	void LMSDLRenderer::Present()
	{
		SDL_RenderPresent(m_pRenderer);
	}

	void LMSDLRenderer::Render() //Defunct
	{
		//SDL_SetRenderDrawColor(m_pRenderer, r, g, b, a);
		//SDL_RenderClear(m_pRenderer);
		//SDL_RenderPresent(m_pRenderer);
	}
	
	void LMSDLRenderer::SetTarget(SDL_Texture* tex)
	{
		SDL_SetRenderTarget(m_pRenderer, tex);
	}
}