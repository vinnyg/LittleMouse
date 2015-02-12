#pragma once

#include "SDLExtensionConfig.h"

#include <memory>
#include "Geometry.h"
#include "SDLRenderer.h"
#include "Structs.h"

#ifdef INCLUDE_SDL_GFX
#include <SDL2_gfxPrimitives.h>
#endif

namespace LM
{
	class Primitive
	{
	private:
		//std::shared_ptr<SDLRenderer> m_pRenderer;
		SDLRenderer* m_pRenderer;
		ColorRGB m_drawColor;
		Uint8 m_drawAlpha;
	public:
		Primitive(SDLRenderer* renderer);
		Primitive(SDLRenderer* renderer, ColorRGB color);
		Primitive(SDLRenderer* renderer, ColorRGBA color);
		~Primitive();
		void SetDrawColor(ColorRGB color);
		void SetDrawAlpha(Uint8 alpha);
		SDLRenderer* GetRenderer() const;
		ColorRGB GetDrawColor() const;
		Uint8 GetDrawAlpha() const;
		virtual int Draw() = 0;
	};
}
