#include "Geometry.h"

namespace LiME
{
	struct SpriteAnimationProperties
	{
		int frameCount;
		float frameIndex;
		float animationSpeed;
		LM::Rect<int> frameRegion;

		SpriteAnimationProperties() = delete;

		SpriteAnimationProperties(LM::Rect<int> frameRegion) : SpriteAnimationProperties(frameRegion, 1, 0.0f, 0.0f) {}

		SpriteAnimationProperties(LM::Rect<int> frameRegion, int frameCount, float frameIndex, float animationSpeed) :
			frameRegion(frameRegion),
			frameCount(frameCount),
			frameIndex(frameIndex),
			animationSpeed(animationSpeed)
		{}
	};
}