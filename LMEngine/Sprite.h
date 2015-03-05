#pragma once
#include <memory>
#include "SDLTexture.h"
#include "SpriteProperties.h"
#include "SpriteAnimationProperties.h"

namespace LiME
{
	class Sprite
	{
	private:
		std::shared_ptr<LM::SDLTexture> texture;
		SpriteProperties properties;
		SpriteAnimationProperties animProperties;
		LM::Rect<float> drawRegion;
	public:
		Sprite(std::shared_ptr<LM::SDLTexture> texture);
		Sprite(std::shared_ptr<LM::SDLTexture> texture, int numFrames);
		Sprite(std::shared_ptr<LM::SDLTexture> texture, int numFrames, LM::Rect<int> sheetSrcRegion);
		~Sprite();
		void Free();
		LM::Point2<int> GetOrigin() const;
		Uint8 GetAlpha() const;
		float GetScale() const;
		float GetAnimationSpeed() const;
		void SetOrigin(LM::Point2<int> origin);
		void SetAnimationSpeed(float speed);
		void SetPosition(LM::Point2<float> position);
		void SetScale(LM::Point2<float> scale);
		void SetAlpha(Uint8 alpha);
		void Draw();
	};
}
