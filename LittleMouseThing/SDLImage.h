#pragma once

#include "SDLExtensionConfig.h"

#ifdef INCLUDE_SDL_IMAGE

#include <SDL_image.h>

namespace LM
{
	class SDLImage
	{
	public:
		SDLImage();
		SDLImage(int flags);
		SDLImage(SDLImage const &other) = delete;
		~SDLImage();
		int InitLibs(int flags);
		int GetInitFlags() const;
	};
}

#endif