#pragma once
#include <vector>
#include <memory>
#include <string>
#include "../SDLRenderer.h"
#include "../SDLTexture.h"

namespace LiME
{
	class TextureLoader
	{
	private:
		LM::SDLRenderer &renderer;
		std::vector<std::shared_ptr<LM::SDLTexture>> textureList;
	public:
		TextureLoader(LM::SDLRenderer &renderer);
		~TextureLoader();
		std::shared_ptr<LM::SDLTexture> LoadTexture(std::string const filePath);
	};
}
