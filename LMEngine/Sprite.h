#pragma once
#include <memory>
#include "SDLTexture.h"

namespace LiME
{
	class Sprite
	{
	private:
		int frameCount;
		float animationTimeline;
		float animationSpeed;
		std::shared_ptr<LM::SDLTexture> texture;

		LM::Rect drawPosition;

		LM::Rect frameDimensions;

	public:
		Sprite(std::shared_ptr<LM::SDLTexture> texture);
		~Sprite();
		void SetAnimationSpeed(float speed);
		void Draw(LM::Point2 position);
		void Draw(LM::Point2 position, int frame, LM::Point2 scale, float angle, float alpha);
	};
}
