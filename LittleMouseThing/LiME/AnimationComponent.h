#pragma once
#include "C:\LittleMouse\LittleMouseThing\LiME\Component.h"
#include "SpriteAnimationProperties.h"

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

		float animationSpeed_;
		bool canLoop;
	public:
		AnimationComponent(int id);
		virtual ~AnimationComponent();
		/*float GetAnimationSpeed() const;
		int GetCurrentFrame() const;
		int GetFrameCount() const;
		LM::Rect<int> GetFrameRegion() const;
		void SetAnimationSpeed(float speed);
		void SetCurrentFrame(int currentFrame);
		void SetFrameCount(int frameCount);
		void SetFrameRegion(LM::Rect<int> frameRegion);*/

		float GetAnimationSpeed() const;
		bool CanLoop() const;
		void SetAnimationSpeed(float speed);
		void SetCanLoop(bool loop);
	};
}
