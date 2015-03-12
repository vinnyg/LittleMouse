#include "Sprite.h"

namespace LiME
{
	Sprite::Sprite(std::shared_ptr<LM::SDLTexture> texture) :
		Sprite(texture, 1, LM::Rect<int>({ 0, 0 }, texture->GetDimensions())) {}

	Sprite::Sprite(std::shared_ptr<LM::SDLTexture> texture, int numFrames) :
		Sprite(texture, numFrames, LM::Rect<int>({ 0, 0 }, texture->GetDimensions())) {}

	Sprite::Sprite(std::shared_ptr<LM::SDLTexture> texture, int numFrames, LM::Rect<int> sheetSrcRegion) :
		texture(texture), properties(sheetSrcRegion),
		animProperties(LM::Rect<int>(0, 0, properties.srcRegion_.GetDimensions().GetX() / numFrames, properties.srcRegion_.GetDimensions().GetY()), numFrames, 0.0f, ((numFrames > 1) ? 1.0f : 0.0f)),
		drawRegion(animProperties.frameRegion_) {}

	Sprite::~Sprite()
	{
		Free();
	}

	void Sprite::Free()
	{
		texture.reset();
	}

	void Sprite::SetAnimationSpeed(float speed)
	{
		animProperties.animationSpeed_ = speed;
	}

	LM::Point2<int> Sprite::GetOrigin() const
	{
		return properties.origin_;
	}

	float Sprite::GetAnimationSpeed() const
	{
		return animProperties.animationSpeed_;
	}

	void Sprite::SetOrigin(LM::Point2<int> origin)
	{
		properties.origin_ = origin;
	}

	void Sprite::SetPosition(LM::Point2<float> position)
	{
		drawRegion.SetX(position.GetX());
		drawRegion.SetY(position.GetY());
	}

	void Sprite::SetScale(LM::Point2<float> scale)
	{
		properties.scale_ = scale;
		drawRegion.SetWidth(animProperties.frameRegion_.GetWidth() * scale.GetX());
		drawRegion.SetHeight(animProperties.frameRegion_.GetHeight() * scale.GetY());
	}

	void Sprite::SetAlpha(Uint8 alpha)
	{
		properties.alpha_ = alpha;
	}

	void Sprite::Draw()
	{
		if (properties.alpha_ < 255)
		{
			texture->SetBlendMode(SDL_BLENDMODE_BLEND);
			texture->SetAlphaMod(properties.alpha_);
		}

		//If animation reaches the end (or start) of its cycle, loop it.
		if (animProperties.frameIndex_ > animProperties.frameCount_)
			animProperties.frameIndex_ = animProperties.frameIndex_ - animProperties.frameCount_;
		else if (animProperties.frameIndex_ < 0)
			animProperties.frameIndex_ = animProperties.frameIndex_ + animProperties.frameCount_;
		
		//Animate if there is more than a single frame in the sprite.
		if (animProperties.frameCount_ > 1)
		{
			animProperties.frameIndex_ = animProperties.frameIndex_ + animProperties.animationSpeed_;

			animProperties.frameRegion_.SetX(animProperties.frameRegion_.GetWidth() * (int)std::floor(animProperties.frameIndex_));
		}

		//Render the sprite.
		texture->CopyToRenderer<float>(animProperties.frameRegion_, drawRegion, properties.origin_, properties.angle_, LM::SDLRenderFlipEnum::kNoFlip);
	}
}
