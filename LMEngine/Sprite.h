#pragma once
#include <memory>
#include "SDLTexture.h"

namespace LiME
{
	class Sprite
	{
	private:
		int frameCount;
		float currentFrame;
		float animationSpeed;
		float angle;
		Uint8 alpha;
		std::shared_ptr<LM::SDLTexture> texture;
		LM::Point2<int> origin;
		LM::Rect<int> frameDimensions;
		LM::Rect<float> drawPosition;
		LM::Rect<float> frameDimensionsFloatCast;
	public:
		Sprite(std::shared_ptr<LM::SDLTexture> texture);
		Sprite(std::shared_ptr<LM::SDLTexture> texture, LM::Point2<int> origin);
		~Sprite();
		LM::Point2<int> GetOrigin() const;
		Uint8 GetAlpha() const;
		void SetAnimationSpeed(float speed);
		void SetPosition(LM::Point2<float> position);
		void SetScale(LM::Point2<float> scale);
		void SetAlpha(Uint8 alpha);
		void Draw();
	};
}
