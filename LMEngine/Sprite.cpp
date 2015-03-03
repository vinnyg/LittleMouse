#include "Sprite.h"

namespace LiME
{
	Sprite::Sprite(std::shared_ptr<LM::SDLTexture> texture) : frameCount(1), currentFrame(0), animationSpeed(1.0f), angle(0), alpha(255), texture(texture), frameDimensions(LM::Point2<int>(0, 0), texture->GetDimensions()), origin(0, 0), drawPosition(frameDimensions), frameDimensionsFloatCast(LM::Point2<float>(0.0f, 0.0f), static_cast<LM::Point2<float>>(frameDimensions.GetDimensions()))
	{
		texture->IncrementRef(LM::SDLTexturePassKey());
	}

	Sprite::Sprite(std::shared_ptr<LM::SDLTexture> texture, LM::Point2<int> origin) : frameCount(1), currentFrame(0), animationSpeed(1.0f), angle(0), alpha(255), texture(texture), frameDimensions(LM::Point2<int>(0, 0), texture->GetDimensions()), origin(origin), drawPosition(frameDimensions), frameDimensionsFloatCast(LM::Point2<float>(0.0f, 0.0f), static_cast<LM::Point2<float>>(frameDimensions.GetDimensions()))
	{
		texture->IncrementRef(LM::SDLTexturePassKey());
	}

	Sprite::~Sprite()
	{
		texture->DecrementRef(LM::SDLTexturePassKey());
	}

	void Sprite::SetAnimationSpeed(float speed)
	{
		animationSpeed = speed;
	}

	LM::Point2<int> Sprite::GetOrigin() const
	{
		return origin;
	}

	void Sprite::SetPosition(LM::Point2<float> position)
	{
		drawPosition.SetX(position.GetX());
		drawPosition.SetY(position.GetY());
	}

	void Sprite::SetScale(LM::Point2<float> scale)
	{
		drawPosition.SetWidth(frameDimensions.GetWidth() * scale.GetX());
		drawPosition.SetHeight(frameDimensions.GetHeight() * scale.GetY());
	}

	void Sprite::SetAlpha(Uint8 alpha)
	{
		this->alpha = alpha;
	}

	void Sprite::Draw()
	{
		if (alpha < 255)
		{
			texture->SetBlendMode(SDL_BLENDMODE_BLEND);
			texture->SetAlphaMod(alpha);
		}

		texture->CopyToRenderer<float>(frameDimensionsFloatCast, drawPosition, origin, angle, LM::SDLRenderFlipEnum::kNoFlip);
	}
}
