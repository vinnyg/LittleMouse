#include "AnimationComponent.h"

namespace LiME
{
	AnimationComponent::AnimationComponent(int id) : Component(id) {}

	AnimationComponent::~AnimationComponent()
	{
	}

	float AnimationComponent::GetAnimationSpeed() const
	{
		return animationSpeed_;
	}

	void AnimationComponent::SetAnimationSpeed(float speed)
	{
		animationSpeed_ = speed;
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
	}
}
