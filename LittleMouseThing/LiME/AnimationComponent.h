#pragma once
#include <memory>
#include "..\LiME\Component.h"
#include "..\LiME\SpriteComponent.h"
//#include "SpriteAnimationProperties.h"

namespace LiME
{
	class AnimationComponent :
		public Component
	{
	private:
		/*SpriteAnimationProperties animProperties;
		int frameCount_;
		float frameIndex_;
		float animationSpeed_;
		int currentFrame_;
		LM::Rect<int> frameRegion_;*/
		std::shared_ptr<SpriteComponent> spriteComponent_;
		//This will break if the number of frames in a sprite's animation cycle is changed after this component is constructed.
		int frameCount_;
		float timeline_;
		float animationSpeed_;
		bool canLoop_;
	public:
		AnimationComponent(int id, std::shared_ptr<SpriteComponent> component);
		AnimationComponent(int id, std::shared_ptr<SpriteComponent> component, float animationSpeed, bool loop);
		virtual ~AnimationComponent();
		/*float GetAnimationSpeed() const;
		int GetCurrentFrame() const;
		int GetFrameCount() const;
		LM::Rect<int> GetFrameRegion() const;
		void SetAnimationSpeed(float speed);
		void SetCurrentFrame(int currentFrame);
		void SetFrameCount(int frameCount);
		void SetFrameRegion(LM::Rect<int> frameRegion);*/
		void Free();
		std::shared_ptr<SpriteComponent> GetSpriteComponent() const;
		float GetTimeline() const;
		float GetAnimationSpeed() const;
		bool CanLoop() const;
		void SetTimeline(float timeline);
		void SetAnimationSpeed(float speed);
		void SetCanLoop(bool loop);
	};
}
