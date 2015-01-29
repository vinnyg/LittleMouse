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
		void RenderCopy(SDL_Texture* tex, int src_x, int src_y, int src_w, int src_h, int dst_x, int dst_y, int dst_w, int dst_h, int offset_x, int offset_y, double angle);
		void Render();	//Defunct
		void SetDrawColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
		void Clear();
		void Present();
		void SetTarget(SDL_Texture* tex);
		SDL_Renderer* GetRenderer() { return m_pRenderer; }
	};
}

#endif