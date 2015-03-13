#pragma once

#include <SDL.h>
#include "Exception.h"
#include "Geometry.h"
#include "SDLRenderFlipEnum.h"
#include "SDLWindow.h"

#include "Structs.h"

namespace LM
{
	class SDLRenderer
	{
	private:
		SDL_Renderer* m_pRenderer;
	public:
		SDLRenderer(SDLRenderer* r);
		SDLRenderer(SDLWindow &window, int index = -1, Uint32 flags = 0);
		~SDLRenderer();
		SDL_Renderer* Get() { return m_pRenderer; }
		int SetDrawColor(ColorRGB c);
		int SetDrawColor(ColorRGBA c);
		int SetDrawBlendMode(SDL_BlendMode blendMode);
		int GetDrawColor(ColorRGBA* c);
		int GetDrawBlendMode(SDL_BlendMode* blendMode);
		int Clear();
		void Present();
		int SetTarget(SDL_Texture* tex);
	};
}