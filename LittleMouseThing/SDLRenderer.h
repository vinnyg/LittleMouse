#ifndef SDLRENDERER_H
#define SDLRENDERER_H

#include <SDL.h>
#include "Geometry.h"
#include "SDLRenderFlipEnum.h"


namespace LM
{
	class SDLRenderer
	{
	private:
		SDL_Renderer* m_pRenderer;
	public:
		SDLRenderer(SDL_Window* window, int index = -1, Uint32 flags = 0);
		~SDLRenderer();
		void RenderCopy(SDL_Texture* tex, Rect &srcrect, Rect &dstrect, Point2 &center, double angle, SDLRenderFlipEnum flip);

		void Render();	//Defunct
		void SetDrawColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
		void Clear();
		void Present();
		void SetTarget(SDL_Texture* tex);
	};
}

#endif