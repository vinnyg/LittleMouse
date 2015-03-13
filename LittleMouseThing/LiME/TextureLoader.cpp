#include "TextureLoader.h"
#include "../SDLRenderer.h"

namespace LiME
{
	TextureLoader::TextureLoader(LM::SDLRenderer &renderer) : renderer(renderer) {}

	TextureLoader::~TextureLoader()
	{
		textureList.clear();
	}

	std::shared_ptr<LM::SDLTexture> TextureLoader::LoadTexture(std::string const filePath)
	{
		std::unique_ptr<LM::SDLSurface> s(new LM::SDLSurface(filePath));
		std::shared_ptr<LM::SDLTexture> t(new LM::SDLTexture(&renderer, s.get()));
		textureList.push_back(t);
		s.reset();
		return t;
	}
}
