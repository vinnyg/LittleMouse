#include <iterator>
#include "ImageLoader.h"

namespace LM
{
	ImageLoader::ImageLoader()
	{
	}


	ImageLoader::~ImageLoader()
	{
		std::vector<SDLSurface*>::iterator it = m_images.begin();
		while (it != m_images.end())
		{
			delete *it;
			++it;
		}
		m_images.clear();
	}

	SDLSurface* ImageLoader::CreateSurfaceFromFile(std::string filepath)
	{
		SDL_Surface* img = SDL_LoadBMP(filepath.c_str());
		SDLSurface* surf = new SDLSurface(img);
		m_images.push_back(surf);

		return surf;
	}
}