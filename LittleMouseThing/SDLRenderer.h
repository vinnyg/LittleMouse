#pragma once

#include <SDL.h>
#include "Geometry.h"
#include "SDLRenderFlipEnum.h"

#include "Structs.h"

namespace LM
{
	class SDLRenderer
	{
	private:
		SDL_Renderer* m_pRenderer;
	public:
		SDLRenderer(SDLRenderer* r);
		SDLRenderer(SDL_Window* window, int index = -1, Uint32 flags = 0);
		~SDLRenderer();
		/*void RenderCopy(SDL_Texture* tex, Rect &srcrect, Rect &dstrect, Point2 &center, double angle, SDLRenderFlipEnum flip);*/

		void Render();	//Defunct

		SDL_Renderer* Get() { return m_pRenderer; }
		int SetDrawColor(ColorRGB c);
		int SetDrawColor(ColorRGBA c);
		int SetDrawBlendMode(SDL_BlendMode blendMode);
		int GetDrawColor(ColorRGBA* c);
		int GetDrawBlendMode(SDL_BlendMode* blendMode);
		void Clear();
		void Present();
		void SetTarget(SDL_Texture* tex);

		//SDLTexture* BindWithTexture(SDLTexture* texture);
	};
}