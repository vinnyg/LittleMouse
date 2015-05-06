#include "SpriteComponent.h"

namespace LiME
{
	SpriteComponent::SpriteComponent(int id) : Component(id),
		//properties(LM::Rect<int>({ 0, 0 }, {0, 0})),
		srcRegion_(LM::Rect<int>({ 0, 0 }, { 0, 0 })),
		frameRegion_(LM::Rect<int>(0, 0, 0, 0)),
		drawRegion_(LM::Rect<float>(0.0f, 0.0f, 0.0f, 0.0f)) {}

	SpriteComponent::~SpriteComponent() {}

	/*void SpriteComponent::Update()
	{
		//Component::Update();
		
		if (sprite) { sprite->Draw(); }
	}*/

	/*void SpriteComponent::SetSprite(Sprite &spr)
	{
		sprite = &spr;
	}*/

	LM::Point2<int> SpriteComponent::GetOrigin() const
	{
		return origin_;
	}

	void SpriteComponent::SetTexture(std::shared_ptr<LM::SDLTexture> texture)
	{
		this->texture = texture;
		frameRegion_.SetDimension(texture->GetDimensions());
		drawRegion_.SetDimension(LM::Point2<float>(float(texture->GetDimensions().GetX()), float(texture->GetDimensions().GetY())));
	}

	void SpriteComponent::SetOrigin(LM::Point2<int> origin)
	{
		origin_ = origin;
	}

	/*void SpriteComponent::SetPosition(LM::Point2<float> position)
	{
		drawRegion_.SetX(position.GetX());
		drawRegion_.SetY(position.GetY());
	}*/

	void SpriteComponent::SetScale(LM::Point2<float> scale)
	{
		scale_ = scale;
		drawRegion_.SetWidth(frameRegion_.GetWidth() * scale.GetX());
		drawRegion_.SetHeight(frameRegion_.GetHeight() * scale.GetY());
	}

	void SpriteComponent::SetFrameRegion(LM::Rect<int> frameRegion)
	{
		frameRegion_.SetPosition(frameRegion.GetPosition());
		drawRegion_.SetPosition(LM::Point2<float>(float(frameRegion.GetPosition().GetX()), float(frameRegion.GetPosition().GetY())));
		frameRegion_.SetDimension(texture->GetDimensions());
		drawRegion_.SetDimension(LM::Point2<float>(float(texture->GetDimensions().GetX()), float(texture->GetDimensions().GetY())));
		SetScale(scale_);
	}

	void SpriteComponent::SetAlpha(Uint8 alpha)
	{
		alpha_ = alpha;
		if (alpha_ < 255)
		{
			texture->SetBlendMode(SDL_BLENDMODE_BLEND);
			texture->SetAlphaMod(alpha_);
		}
	}

	void SpriteComponent::Draw()
	{
		//If animation reaches the end (or start) of its cycle, loop it.
		/*if (animProperties.frameIndex_ > animProperties.frameCount_)
			animProperties.frameIndex_ = animProperties.frameIndex_ - animProperties.frameCount_;
		else if (animProperties.frameIndex_ < 0)
			animProperties.frameIndex_ = animProperties.frameIndex_ + animProperties.frameCount_;*/

		//Animate if there is more than a single frame in the sprite.
		/*if (animProperties.frameCount_ > 1)
		{
			animProperties.frameIndex_ = animProperties.frameIndex_ + animProperties.animationSpeed_;

			animProperties.frameRegion_.SetX(animProperties.frameRegion_.GetWidth() * (int)std::floor(animProperties.frameIndex_));
		}*/

		//Render the sprite.
		texture->CopyToRenderer<float>(frameRegion_, drawRegion_, origin_, angle_, LM::SDLRenderFlipEnum::kNoFlip);
	}
}