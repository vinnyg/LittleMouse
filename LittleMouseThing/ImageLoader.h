#pragma once

#include <string>
#include <vector>
#include <memory>
#include "SDLTexture.h"
//#include "SDLRenderer.h"

namespace LM
{

	class ImageLoader
	{
	private:
		int m_imageCount;
		std::vector<SDLTexture*> m_images;
	public:
		ImageLoader();
		~ImageLoader();
		//SDLTexture* LoadTexture(std::string filepath, SDLRenderer* renderer);
		SDLTexture* LoadImage(std::string filepath);
		int GetImageCount() { return m_imageCount; }
	};

}