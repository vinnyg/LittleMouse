#include "../Geometry.h"
#pragma once

namespace LiME
{
	struct AnimatedSpriteProperties
	{
		LM::Rect<int> frameRegion_;		//The region from the texture which will be used for rendering.
		float angle_;
		Uint8 alpha_;
		LM::Point2<int> origin_;
		LM::Point2<float> scale_;
		int frameCount_;				//Number of frames in animation
		float frameIndex_;				//Current frame in animation cycle as a float
		int currentFrame_;				//Current frame in animation cycle
		//float animationSpeed_;

		AnimatedSpriteProperties() = delete;

		AnimatedSpriteProperties(LM::Rect<int> srcRegion) :
			AnimatedSpriteProperties(srcRegion,  { 0, 0 }, 1) {}

		AnimatedSpriteProperties(LM::Rect<int> frameRegion, LM::Point2<int> origin, int frameCount) : frameRegion_(frameRegion), origin_(origin), scale_(1.0f, 1.0f), frameCount_(frameCount)
		{
			angle_ = 0.0f;
			alpha_ = 255;
			frameIndex_ = 0.0f;
			currentFrame_ = 0;
		}
	};
}