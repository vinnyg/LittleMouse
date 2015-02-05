#include <iterator>
#include "ImageLoader.h"

namespace LM
{
	ImageLoader::ImageLoader()
	{
	}


	ImageLoader::~ImageLoader()
	{
		
	}

	/*SDLTexture* LoadTexture(std::string filepath, SDLRenderer* renderer)
	{
		SDL_Surface* img = SDL_LoadBMP(filepath.c_str());
		std::shared_ptr<SDL_Texture> tex = std::make_shared<SDL_Texture>(SDL_CreateTextureFromSurface(renderer->GetRenderer(), img));
		SDLTexture* texture;
		//SDL_DestroySurface
	}*/

	SDLTexture* LoadImage(std::string filepath)
	{
		SDL_Surface* img = SDL_LoadBMP(filepath.c_str());
		/*std::shared_ptr<SDL_Texture> tex = std::make_shared<SDL_Texture>(SDL_CreateTextureFromSurface(renderer->GetRenderer(), img));*/
		SDLTexture* texture;
		//SDL_DestroySurface
	}
}