#include "Sprite.h"

namespace LiME
{
	Sprite::Sprite(std::shared_ptr<LM::SDLTexture> texture) : texture(texture), frameDimensions(texture->GetDimensions()), animationSpeed(1.0f) {}

	Sprite::~Sprite() {}

	void Sprite::SetAnimationSpeed(float speed)
	{
		animationSpeed = speed;
	}

	void Sprite::Draw(LM::Point2 position)
	{
		texture->CopyToRenderer()
	}
}
