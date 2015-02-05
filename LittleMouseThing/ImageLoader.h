#pragma once

#include <string>
#include <vector>
//#include <memory>
#include "SDLSurface.h"

namespace LM
{

	class ImageLoader
	{
	private:
		int m_imageCount;
		std::vector<SDLSurface*> m_images;
	public:
		ImageLoader();
		~ImageLoader();
		//SDLTexture* LoadTexture(std::string filepath, SDLRenderer* renderer);
		SDLSurface* CreateSurfaceFromFile(std::string filepath);
		int GetImageCount() { return m_imageCount; }
	};
}