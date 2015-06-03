#include "AnimationComponent.h"

namespace LiME
{
	/*AnimationComponent::AnimationComponent(int id) : Component(id), frameRegion_(0.0f, 0.0f, 0.0f, 0.0f) {}

	AnimationComponent::~AnimationComponent()
	{
	}

	float AnimationComponent::GetAnimationSpeed() const
	{
		return animationSpeed_;
	}

	int AnimationComponent::GetCurrentFrame() const
	{
		return currentFrame_;
	}

	int AnimationComponent::GetFrameCount() const
	{
		return frameCount_;
	}

	LM::Rect<int> AnimationComponent::GetFrameRegion() const
	{
		return frameRegion_;
	}

	void AnimationComponent::SetAnimationSpeed(float speed)
	{
		animationSpeed_ = speed;
	}

	void AnimationComponent::SetCurrentFrame(int currentFrame)
	{
		currentFrame_ = currentFrame;
	}

	void AnimationComponent::SetFrameCount(int frameCount)
	{
		frameCount_ = frameCount;
	}

	void AnimationComponent::SetFrameRegion(LM::Rect<int> frameRegion)
	{
		frameRegion_ = frameRegion;
	}*/
	
	AnimationComponent::AnimationComponent(int id, std::shared_ptr<SpriteComponent> component) : AnimationComponent(id, component, 1.0f, true) {}

	AnimationComponent::AnimationComponent(int id, std::shared_ptr<SpriteComponent> component, float animationSpeed, bool loop) : Component(id), spriteComponent_(component)
	{
		//This will break if the number of frames in a sprite's animation cycle is changed after this component is constructed.
		frameCount_ = spriteComponent_->GetSprite()->GetFrameCount();
		timeline_ = 0;
		animationSpeed_ = animationSpeed;
		canLoop_ = loop;
	}

	AnimationComponent::~AnimationComponent()
	{
		Free();
	}

	void AnimationComponent::Free()
	{
		spriteComponent_.reset();
	}

	std::shared_ptr<SpriteComponent> AnimationComponent::GetSpriteComponent() const
	{
		return spriteComponent_;
	}


	float AnimationComponent::GetTimeline() const
	{
		return timeline_;
	}

	float AnimationComponent::GetAnimationSpeed() const
	{
		return animationSpeed_;
	}

	bool AnimationComponent::CanLoop() const
	{
		return canLoop_;
	}

	void AnimationComponent::SetTimeline(float timeline)
	{
		timeline_ = timeline;
	}

	void AnimationComponent::SetAnimationSpeed(float speed)
	{
		animationSpeed_ = speed;
	}

	void AnimationComponent::SetCanLoop(bool loop)
	{
		canLoop_ = loop;
	}

}
