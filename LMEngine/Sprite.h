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
		LM::Rect frameDimensions;
		std::shared_ptr<LM::SDLTexture> texture;
	public:
		Sprite(std::shared_ptr<LM::SDLTexture> texture);
		~Sprite();
		void SetAnimationSpeed(float speed);
		void Draw(LM::Point2 position);
	};
}
