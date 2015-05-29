#pragma once
#include <iterator>
#include <vector>
#include <memory>
#include "Sprite.h"

namespace LiME
{
	class SpriteManager
	{
	private:
		std::vector<std::shared_ptr<Sprite>> spriteList;
	public:
		SpriteManager();
		~SpriteManager();
		std::shared_ptr<Sprite> CreateSprite(std::shared_ptr<LM::SDLTexture> texture);
		std::shared_ptr<Sprite> CreateSprite(std::shared_ptr<LM::SDLTexture> texture, int numFrames, LM::Rect<int> &sheetSrcRegion);
		//void Draw();
	};
}

