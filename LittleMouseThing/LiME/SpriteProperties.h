#include "../Geometry.h"

namespace LiME
{
	struct SpriteProperties
	{
		float angle_;
		Uint8 alpha_;
		LM::Point2<int> origin_;
		LM::Point2<float> scale_;
		LM::Rect<int> srcRegion_;

		SpriteProperties() = delete;
		SpriteProperties(LM::Rect<int> srcRegion) : SpriteProperties(srcRegion, 0.0f, 255, { 0, 0 }, { 1.0f, 1.0f }) {}
		SpriteProperties(LM::Rect<int> srcRegion, float angle, Uint8 alpha, LM::Point2<int> origin, LM::Point2<float> scale) : srcRegion_(srcRegion), angle_(angle), alpha_(alpha), origin_(origin), scale_(scale) {}
	};
}