#ifndef LMSDLRENDERER_H
#define LMSDLRENDERER_H

#include <SDL.h>

namespace LM
{
	class LMSDLRenderer
	{
	private:
		SDL_Renderer* m_pRenderer;
	public:
		LMSDLRenderer(SDL_Window* window, int index, Uint32 flags);
		~LMSDLRenderer();
		void RenderCopy(SDL_Texture* tex, int src_x = 0, int src_y = 0, int src_w = -1, int src_h = -1, int dst_x = 0, int dst_y = 0, int dst_w = -1, int dst_h = -1, int offset_x = 0, int offset_y = 0, double angle = 0.0);
		void Render();	//Defunct
		void SetDrawColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
		void Clear();
		void Present();
		void SetTarget(SDL_Texture* tex);
	};
}

#endif