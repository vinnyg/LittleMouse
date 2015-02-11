#pragma once

#define INCLUDE_SDL_IMAGE

#include <SDL_image.h>

namespace LM
{
	class SDLImage
	{
	public:
		SDLImage();
		SDLImage(int flags);
		SDLImage(const SDLImage &other) = delete;
		~SDLImage();
		int InitLibs(int flags);
		int GetInitFlags() const;
	};
}