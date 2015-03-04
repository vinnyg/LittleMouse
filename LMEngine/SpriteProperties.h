#include "Geometry.h"

namespace LiME
{
	struct SpriteProperties
	{
		float angle;
		Uint8 alpha;
		LM::Point2<int> origin;
		LM::Point2<float> scale;
		LM::Rect<int> srcRegion;

		SpriteProperties() = delete;
		SpriteProperties(LM::Rect<int> srcRegion) : SpriteProperties(srcRegion, 0.0f, 255, { 0, 0 }, { 1.0f, 1.0f }) {}
		SpriteProperties(LM::Rect<int> srcRegion, float angle, Uint8 alpha, LM::Point2<int> origin, LM::Point2<float> scale) : angle(angle), alpha(alpha), origin(origin), scale(scale) {}
	};
}