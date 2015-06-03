#include "SpriteDrawingSystem.h"

namespace LiME
{
	SpriteDrawingSystem::SpriteDrawingSystem() : tmpFrameRegion_({ 0, 0, 0, 0 })/*, tmpDrawRegion({ 0, 0, 0, 0 }), tmpOrigin({ 0, 0 }) */{}

	SpriteDrawingSystem::~SpriteDrawingSystem() {}

	std::shared_ptr<SpriteComponent> SpriteDrawingSystem::AddComponent(int id, std::shared_ptr<Sprite> sprite)
	{
		std::shared_ptr<SpriteComponent> tmp(new SpriteComponent(id, sprite));
		components_.push_back(tmp);
		return tmp;
	}

	void SpriteDrawingSystem::RemoveComponent(std::shared_ptr<SpriteComponent> component)
	{
		//TODO: This is not very efficient and requires review!
		std::vector<std::shared_ptr<SpriteComponent>>::iterator it;
		it = std::find(components_.begin(), components_.end(), component);
		if (it != components_.end())
		{
			(*it)->Free();
			components_.erase(it);
		}
	}

	void SpriteDrawingSystem::Update()
	{
		std::vector<std::shared_ptr<SpriteComponent>>::iterator it = components_.begin();

		while (it != components_.end())
		{
			tmpSprite_ = (*it)->GetSprite();
			tmpFrameRegion_ = tmpSprite_->GetFrameRegion();
			//Render the appropriate image depending on our current frame.
			tmpFrameRegion_.SetX(tmpFrameRegion_.GetX() + ((*it)->GetCurrentFrame() * tmpFrameRegion_.GetWidth()));
			/*tmpDrawRegion = (*it)->GetDrawRegion();
			tmpOrigin = (*it)->GetOrigin();
			tmpAngle = (*it)->GetAngle();
			tmpSprite->GetTexture()->CopyToRenderer(tmpFrameRegion, tmpDrawRegion, tmpOrigin, tmpAngle, LM::SDLRenderFlipEnum::kNoFlip);*/
			tmpSprite_->GetTexture()->CopyToRenderer(tmpFrameRegion_, (*it)->GetDrawRegion(), (*it)->GetOrigin(), (*it)->GetAngle(), LM::SDLRenderFlipEnum::kNoFlip);
			it++;
		}
	}
}
