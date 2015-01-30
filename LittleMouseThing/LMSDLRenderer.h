#ifndef LMSDLRENDERER_H
#define LMSDLRENDERER_H

#include <SDL.h>
#include "Geometry.h"
#include "SDLRenderFlipEnum.h"


namespace LM
{
	class LMSDLRenderer
	{
	private:
		SDL_Renderer* m_pRenderer;
	public:
		LMSDLRenderer(SDL_Window* window, int index = -1, Uint32 flags = 0);
		~LMSDLRenderer();
		void RenderCopy(SDL_Texture* tex, LMRect &srcrect, LMRect &dstrect, LMPoint &center, double angle, SDLRenderFlipEnum flip);
		void Render();	//Defunct
		void SetDrawColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
		void Clear();
		void Present();
		void SetTarget(SDL_Texture* tex);
	};
}

#endif