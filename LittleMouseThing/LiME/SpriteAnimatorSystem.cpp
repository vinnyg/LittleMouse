#include "SpriteAnimatorSystem.h"

namespace LiME
{
	int SpriteAnimatorSystem::currentID_ = 0;

	SpriteAnimatorSystem::SpriteAnimatorSystem() {}

	SpriteAnimatorSystem::~SpriteAnimatorSystem() {}

	std::shared_ptr<AnimationComponent> SpriteAnimatorSystem::AddComponent(std::shared_ptr<SpriteComponent> sprCom)
	{
		std::shared_ptr<AnimationComponent> tmp(new AnimationComponent(currentID_++, sprCom));
		components_.push_back(tmp);
		return tmp;
	}

	void SpriteAnimatorSystem::RemoveComponent(std::shared_ptr<AnimationComponent> component)
	{
		std::vector<std::shared_ptr<AnimationComponent>>::iterator it;
		it = std::find(components_.begin(), components_.end(), component);
		if (it != components_.end())
		{
			(*it)->Free();
			components_.erase(it);
		}
	}

	void SpriteAnimatorSystem::Update()
	{
		std::vector<std::shared_ptr<AnimationComponent>>::iterator it = components_.begin();

		while (it != components_.end())
		{
			std::shared_ptr<AnimationComponent> component = (*it);
			component->SetTimeline(component->GetTimeline() + component->GetAnimationSpeed());
			component->GetSpriteComponent()->SetCurrentFrame(int(component->GetTimeline()));
			if (component->GetTimeline() > component->GetSpriteComponent()->GetSprite()->GetFrameCount())
				component->SetTimeline(component->GetTimeline() - component->GetSpriteComponent()->GetSprite()->GetFrameCount());
			//tmpSprite_ = (*it)->GetSprite();
			//tmpFrameRegion_ = tmpSprite_->GetFrameRegion();
			//Render the appropriate image depending on our current frame.
			//tmpFrameRegion_.SetX(tmpFrameRegion_.GetX() + ((*it)->GetCurrentFrame() * tmpFrameRegion_.GetWidth()));
			/*tmpDrawRegion = (*it)->GetDrawRegion();
			tmpOrigin = (*it)->GetOrigin();
			tmpAngle = (*it)->GetAngle();
			tmpSprite->GetTexture()->CopyToRenderer(tmpFrameRegion, tmpDrawRegion, tmpOrigin, tmpAngle, LM::SDLRenderFlipEnum::kNoFlip);*/
			//tmpSprite_->GetTexture()->CopyToRenderer(tmpFrameRegion_, (*it)->GetDrawRegion(), (*it)->GetOrigin(), (*it)->GetAngle(), LM::SDLRenderFlipEnum::kNoFlip);
			++it;
		}
	}
}
