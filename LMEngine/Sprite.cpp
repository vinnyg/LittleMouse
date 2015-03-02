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

	}

	void Sprite::Draw(LM::Point2 position, int frame, LM::Point2 scale, float angle, float alpha)
	{
		drawPosition.SetX(position.GetX());
		drawPosition.SetY(position.GetY());
		drawPosition.SetWidth(frameDimensions.GetWidth() * scale.GetX());
		drawPosition.SetHeight(frameDimensions.GetHeight() * scale.GetY());
		texture->CopyToRenderer()
	}
}
