#include "../Geometry.h"

namespace LiME
{
	struct SpriteAnimationProperties
	{
		int frameCount_;
		float frameIndex_;
		float animationSpeed_;
		LM::Rect<int> frameRegion_;

		SpriteAnimationProperties() = delete;

		SpriteAnimationProperties(LM::Rect<int> frameRegion) : SpriteAnimationProperties(frameRegion, 1, 0.0f, 0.0f) {}

		SpriteAnimationProperties(LM::Rect<int> frameRegion, int frameCount, float frameIndex, float animationSpeed) :
			frameRegion_(frameRegion),
			frameCount_(frameCount),
			frameIndex_(frameIndex),
			animationSpeed_(animationSpeed)
		{}
	};
}