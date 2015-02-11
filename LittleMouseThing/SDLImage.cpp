#include "SDLImage.h"

namespace LM
{
	SDLImage::SDLImage()
	{
		IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF | IMG_INIT_WEBP);
	}

	SDLImage::SDLImage(int flags)
	{
		IMG_Init(flags);
	}

	SDLImage::~SDLImage()
	{
		if (!GetInitFlags())
			IMG_Quit();
	}

	int SDLImage::InitLibs(int flags)
	{
		return IMG_Init(flags);
	}

	int SDLImage::GetInitFlags() const
	{
		return IMG_Init(0);
	}
}