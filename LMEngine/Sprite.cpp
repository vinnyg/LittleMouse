#include "Sprite.h"

namespace LiME
{
	Sprite::Sprite(std::shared_ptr<LM::SDLTexture> texture) :
		Sprite(texture, 1, LM::Rect<int>({ 0, 0 }, texture->GetDimensions())) {}

	Sprite::Sprite(std::shared_ptr<LM::SDLTexture> texture, int numFrames) :
		Sprite(texture, numFrames, LM::Rect<int>({ 0, 0 }, texture->GetDimensions())) {}

	Sprite::Sprite(std::shared_ptr<LM::SDLTexture> texture, int numFrames, LM::Rect<int> sheetSrcRegion) :
		texture(texture), properties(sheetSrcRegion),
		animProperties(LM::Rect<int>(0, 0, sheetSrcRegion.GetDimensions().GetX() / numFrames, sheetSrcRegion.GetDimensions().GetY()), numFrames, 0.0f, ((numFrames > 1) ? 1.0f : 0.0f)),
		drawRegion(animProperties.frameRegion) {}

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
		animProperties.animationSpeed = speed;
	}

	LM::Point2<int> Sprite::GetOrigin() const
	{
		return properties.origin;
	}

	float Sprite::GetAnimationSpeed() const
	{
		return animProperties.animationSpeed;
	}

	void Sprite::SetOrigin(LM::Point2<int> origin)
	{
		properties.origin = origin;
	}

	void Sprite::SetPosition(LM::Point2<float> position)
	{
		drawRegion.SetX(position.GetX());
		drawRegion.SetY(position.GetY());
	}

	void Sprite::SetScale(LM::Point2<float> scale)
	{
		properties.scale = scale;
		drawRegion.SetWidth(animProperties.frameRegion.GetWidth() * scale.GetX());
		drawRegion.SetHeight(animProperties.frameRegion.GetHeight() * scale.GetY());
	}

	void Sprite::SetAlpha(Uint8 alpha)
	{
		properties.alpha = alpha;
	}

	void Sprite::Draw()
	{
		if (properties.alpha < 255)
		{
			texture->SetBlendMode(SDL_BLENDMODE_BLEND);
			texture->SetAlphaMod(properties.alpha);
		}

		//If animation reaches the end (or start) of its cycle, loop it.
		if (animProperties.frameIndex > animProperties.frameCount)
			animProperties.frameIndex = animProperties.frameIndex - animProperties.frameCount;
		else if (animProperties.frameIndex < 0)
			animProperties.frameIndex = animProperties.frameIndex + animProperties.frameCount;
		
		//Animate if there is more than a single frame in the sprite.
		if (animProperties.frameCount > 1)
		{
			animProperties.frameIndex = animProperties.frameIndex + animProperties.animationSpeed;

			animProperties.frameRegion.SetX(animProperties.frameRegion.GetWidth() * (int)std::floor(animProperties.frameIndex));
		}

		//Render the sprite.
		texture->CopyToRenderer<float>(animProperties.frameRegion, drawRegion, properties.origin, properties.angle, LM::SDLRenderFlipEnum::kNoFlip);
	}
}
