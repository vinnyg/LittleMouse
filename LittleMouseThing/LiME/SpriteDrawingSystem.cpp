#include "SpriteDrawingSystem.h"

namespace LiME
{
	SpriteDrawingSystem::SpriteDrawingSystem() : tmpFrameRegion({ 0, 0, 0, 0 }), tmpDrawRegion({ 0, 0, 0, 0 }), tmpOrigin({ 0, 0 }) {}

	SpriteDrawingSystem::~SpriteDrawingSystem() {}

	SpriteComponent* SpriteDrawingSystem::AddComponent(int id, Sprite* sprite)
	{
		SpriteComponent* tmp = new SpriteComponent(id, sprite);
		components_.push_back(tmp);
		return tmp;
	}

	void SpriteDrawingSystem::RemoveComponent(SpriteComponent* component)
	{
		//TODO: This is not very efficient and requires review!
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
		std::vector<LiME::SpriteComponent*>::iterator it = components_.begin();

		while (it != components_.end())
		{
			tmpSprite = (*it)->GetSprite();
			tmpFrameRegion = tmpSprite->GetFrameRegion();
			tmpDrawRegion = (*it)->GetDrawRegion();
			tmpOrigin = (*it)->GetOrigin();
			tmpAngle = (*it)->GetAngle();
			tmpSprite->GetTexture()->CopyToRenderer(tmpFrameRegion, tmpDrawRegion, tmpOrigin, tmpAngle, LM::SDLRenderFlipEnum::kNoFlip);
			/*tmpSprite->GetTexture()->CopyToRenderer(tmpSprite->GetFrameRegion(), (*it)->GetDrawRegion(), (*it)->GetOrigin(), (*it)->GetAngle(), LM::SDLRenderFlipEnum::kNoFlip);*/
			it++;
		}
	}
}
