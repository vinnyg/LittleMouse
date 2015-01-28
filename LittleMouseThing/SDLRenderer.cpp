#include "SDLRenderer.h"

LM::SDLRenderer::SDLRenderer(SDL_Window* window)
{
	m_pRenderer = SDL_CreateRenderer(window, -1, 0);
	SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 255);
	SDL_RenderClear(m_pRenderer);
	SDL_RenderPresent(m_pRenderer);
}

LM::SDLRenderer::~SDLRenderer()
{
	if (m_pRenderer != nullptr)
	{
		SDL_DestroyRenderer(m_pRenderer);
	}
}

//Add a simple texture to the draw queue.
void LM::SDLRenderer::DrawTexture(SDL_Texture* tex, float src_x, float src_y, float src_w, float src_h, float dst_x, float dst_y, float dst_w, float dst_h)
{
	SDL_Rect src, dst;
	src.x = src_x;
	src.y = src_y;
	src.w = src_w;
	src.h = src_h;
	dst.x = dst_x;
	dst.y = dst_y;

	SDL_RenderCopy(m_pRenderer, tex, &src, &dst);
	//SDL_RenderCopyEx(m_pRenderer, tex, NULL, &dst, 0, NULL, SDL_FLIP_NONE);
}

//Add a texture to the draw queue with additional parameters.
void LM::SDLRenderer::DrawTexture(SDL_Texture* tex, float src_x, float src_y, float src_w, float src_h, float dst_x, float dst_y, float dst_w, float dst_h, float offset_x, float offset_y, double angle)
{

}

void LM::SDLRenderer::Render()
{
	SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 255);
	SDL_RenderClear(m_pRenderer);
	SDL_RenderPresent(m_pRenderer);
}