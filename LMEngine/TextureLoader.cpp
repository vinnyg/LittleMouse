#include "TextureLoader.h"

namespace LiME
{
	TextureLoader::TextureLoader()
	{
	}

	TextureLoader::~TextureLoader()
	{
		//if (!textureList.empty())
			textureList.clear();
	}

	std::shared_ptr<LM::SDLTexture> TextureLoader::LoadTexture(std::string filePath)
	{
		std::shared_ptr<LM::SDLTexture> t = LM::SDLTexture(filePath)
		textureList.push_back(t);
	}

	void TextureLoader::FreeTexture(std::shared_ptr<LM::SDLTexture>)
	{

	}
}
