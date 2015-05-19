#include "SpriteDrawingSystem.h"

namespace LiME
{
	SpriteDrawingSystem::SpriteDrawingSystem() {}

	SpriteDrawingSystem::~SpriteDrawingSystem() {}

	SpriteComponent* SpriteDrawingSystem::AddComponent(int id)
	{
		SpriteComponent* tmp = new SpriteComponent(id);
		components_.push_back(tmp);
		return tmp;
	}

	void SpriteDrawingSystem::RemoveComponent(SpriteComponent* component)
	{
		//This is not very efficient and requires review!
		std::vector<LiME::SpriteComponent*>::iterator it;
		it = std::find(components_.begin(), components_.end(), component);
		if (it != components_.end())
		{
			(*it)->Free();
			components_.erase(it);
		}
	}

	void SpriteDrawingSystem::Update()
	{
		std::vector<LiME::SpriteComponent*>::iterator it;

		while (it++ != components_.end())
		{
			//std::shared_ptr<LM::SDLTexture> spr = (*it)->GetSprite()->GetTexture();
			LiME::Sprite* spr = (*it)->GetSprite();
			spr->GetTexture()->CopyToRenderer<float>(spr->GetFrameRegion(), (*it)->GetDrawRegion(), (*it)->GetOrigin(), (*it)->GetAngle(), LM::SDLRenderFlipEnum::kNoFlip);
		}
	}
}
