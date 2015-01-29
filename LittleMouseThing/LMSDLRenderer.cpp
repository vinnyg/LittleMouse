#include "LMSDLRenderer.h"

namespace LM
{
	LMSDLRenderer::LMSDLRenderer(SDL_Window* window, int index, Uint32 flags)
	{
		if (SDL_WasInit(SDL_INIT_VIDEO) != 0)
		{
			m_pRenderer = SDL_CreateRenderer(window, -1, 0);
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
	void LMSDLRenderer::RenderCopy(SDL_Texture* tex, int src_x, int src_y, int src_w, int src_h, int dst_x, int dst_y, int dst_w, int dst_h, int offset_x, int offset_y, double angle)
	{
		SDL_Rect src, dst;
		src.x = src_x;
		src.y = src_y;
		src.w = src_w;
		src.h = src_h;
		dst.x = dst_x;
		dst.y = dst_y;

		SDL_Point center;
		center.x = offset_x;
		center.y = offset_y;

		SDL_RenderCopyEx(m_pRenderer, tex, &src, &dst, angle, &center, SDL_FLIP_NONE);
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