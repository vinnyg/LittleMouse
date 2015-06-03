#include "SpriteComponent.h"

namespace LiME
{
	SpriteComponent::SpriteComponent(int id, std::shared_ptr<Sprite> sprite) : Component(id),
		//properties(LM::Rect<int>({ 0, 0 }, {0, 0})),
		//srcRegion_(LM::Rect<int>({ 0, 0 }, { 0, 0 })),
		//frameRegion_(LM::Rect<int>(0, 0, 0, 0)),
		origin_(0, 0), scale_(1.0f, 1.0f),
		sprite_(sprite),
		drawRegion_(sprite->GetFrameRegion()),
		texturePtr_(sprite->GetTexture())
	{
		angle_ = 0;
		alpha_ = 255;
		currentFrame_ = 0;
	}

	SpriteComponent::~SpriteComponent() {}
	
	void SpriteComponent::Free()
	{
		texturePtr_.reset();
	}

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

	std::shared_ptr<Sprite> SpriteComponent::GetSprite() const
	{
		return sprite_;
	}

	float SpriteComponent::GetAngle() const
	{
		return angle_;
	}

	Uint8 SpriteComponent::GetAlpha() const
	{
		return alpha_;
	}

	/*int SpriteComponent::GetFrameCount() const
	{
		return properties.frameCount_;
	}*/

	int SpriteComponent::GetCurrentFrame() const
	{
		return currentFrame_;
	}

	LM::Rect<int> SpriteComponent::GetDrawRegion() const
	{
		return drawRegion_;
	}

	LM::Point2<int> SpriteComponent::GetPosition() const
	{
		return drawRegion_.GetPosition();
	}
	
	/*void SpriteComponent::SetTexture(std::shared_ptr<LM::SDLTexture> texture)
	{
		this->texture = texture;
		properties.frameRegion_.SetDimension(texture->GetDimensions());
		drawRegion_.SetDimension(LM::Point2<float>(float(texture->GetDimensions().GetX()), float(texture->GetDimensions().GetY())));
	}*/

	void SpriteComponent::SetOrigin(LM::Point2<int> &origin)
	{
		origin_ = origin;
	}

	/*void SpriteComponent::SetPosition(LM::Point2<float> position)
	{
		drawRegion_.SetX(position.GetX());
		drawRegion_.SetY(position.GetY());
	}*/

	/*void SpriteComponent::SetSprite(Sprite* sprite)
	{
		sprite_ = sprite;
		texturePtr_ = sprite_->GetTexture();
	}*/

	void SpriteComponent::SetScale(LM::Point2<float> &scale)
	{
		scale_ = scale;
		drawRegion_.SetWidth(int(sprite_->GetFrameRegion().GetWidth() * scale.GetX()));
		drawRegion_.SetHeight(int(sprite_->GetFrameRegion().GetHeight() * scale.GetY()));
	}

	/*void SpriteComponent::SetFrameRegion(LM::Rect<int> frameRegion)
	{
		properties.frameRegion_.SetPosition(frameRegion.GetPosition());
		drawRegion_.SetPosition(LM::Point2<float>(float(frameRegion.GetPosition().GetX()), float(frameRegion.GetPosition().GetY())));
		properties.frameRegion_.SetDimension(texture->GetDimensions());
		drawRegion_.SetDimension(LM::Point2<float>(float(texture->GetDimensions().GetX()), float(texture->GetDimensions().GetY())));
		SetScale(properties.scale_);
	}*/

	void SpriteComponent::SetAngle(float angle)
	{
		angle_ = angle;
	}

	void SpriteComponent::SetAlpha(Uint8 alpha)
	{
		alpha_ = alpha;
		if (alpha_ < 255)
		{
			texturePtr_->SetBlendMode(SDL_BLENDMODE_BLEND);
			texturePtr_->SetAlphaMod(alpha_);
		}
	}

	/*void SpriteComponent::SetFrameCount(int frames)
	{
		properties.frameCount_ = frames;
	}*/

	void SpriteComponent::SetCurrentFrame(int frame)
	{
		currentFrame_ = frame;
	}

	void SpriteComponent::SetPosition(LM::Point2<int> &position)
	{
		drawRegion_.SetPosition(position);
	}

	/*void SpriteComponent::Draw()
	{
		//If animation reaches the end (or start) of its cycle, loop it.
		/*if (animProperties.frameIndex_ > animProperties.frameCount_)
			animProperties.frameIndex_ = animProperties.frameIndex_ - animProperties.frameCount_;
		else if (animProperties.frameIndex_ < 0)
			animProperties.frameIndex_ = animProperties.frameIndex_ + anim Properties.frameCount_;*/

		//Animate if there is more than a single frame in the sprite.
		/*if (animProperties.frameCount_ > 1)
		{
			animProperties.frameIndex_ = animProperties.frameIndex_ + animProperties.animationSpeed_;

			animProperties.frameRegion_.SetX(animProperties.frameRegion_.GetWidth() * (int)std::floor(animProperties.frameIndex_));
		}*/

		//Render the sprite.
		/*texture->CopyToRenderer<float>(properties.frameRegion_, drawRegion_, properties.origin_, properties.angle_, LM::SDLRenderFlipEnum::kNoFlip);*/
		/*currentFrame_ * sprite_->GetFrameRegion().GetWidth();
		texturePtr_->CopyToRenderer(, drawRegion_, origin_, angle_, LM::SDLRenderFlipEnum::kNoFlip);
	}*/
}