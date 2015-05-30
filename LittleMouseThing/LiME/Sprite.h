#pragma once
#include <memory>
#include "../SDLTexture.h"
#include "SpriteProperties.h"
#include "SpriteAnimationProperties.h"

namespace LiME
{
	class Sprite
	{
	private:
		std::shared_ptr<LM::SDLTexture> texture_;	//Texture for sprite
		//SpriteProperties properties;
		int frameCount_;							//Number of frames in animation
		LM::Rect<int> frameRegion_;					//Region of the texture which represents a single frame in the animation
		
		//SpriteAnimationProperties animProperties;
		//LM::Rect<float> drawRegion;
	public:
		Sprite(std::shared_ptr<LM::SDLTexture> texture);
		//Sprite(std::shared_ptr<LM::SDLTexture> texture, int numFrames);
		Sprite(std::shared_ptr<LM::SDLTexture> texture, int numFrames, LM::Rect<int> srcRegion);
		~Sprite();
		void Free();
		std::shared_ptr<LM::SDLTexture> GetTexture() const;
		int GetFrameCount() const;
		LM::Rect<int> GetFrameRegion() const;
		void SetFrameCount(int count);
		void SetFrameRegion(LM::Rect<int> &region);
		//LM::Point2<int> GetOrigin() const;
		//Uint8 GetAlpha() const;
		//float GetScale() const;
		//float GetAnimationSpeed() const;
		//void SetOrigin(LM::Point2<int> origin);
		//void SetAnimationSpeed(float speed);
		//void SetPosition(LM::Point2<float> position);
		//void SetScale(LM::Point2<float> scale);
		//void SetAlpha(Uint8 alpha);
		//void Draw(LM::Point2<float> scale, LM::Point2<float> position);
	};
}