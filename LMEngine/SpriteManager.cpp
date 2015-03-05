#include "SpriteManager.h"

namespace LiME
{
	SpriteManager::SpriteManager() {}

	SpriteManager::~SpriteManager()
	{
		spriteList.clear();
	}

	std::shared_ptr<Sprite> SpriteManager::CreateSprite(std::shared_ptr<LM::SDLTexture> texture, int numFrames, LM::Rect<int> sheetSrcRegion)
	{
		std::shared_ptr<Sprite> spr(new Sprite(texture, numFrames, sheetSrcRegion));
		spriteList.push_back(spr);
		return spr;
	}

	void SpriteManager::Draw()
	{
		std::vector<std::shared_ptr<Sprite>>::iterator it;
		for (it = spriteList.begin; it != spriteList.end; ++it)
		{
			(*it)->Draw();
		}
	}
}