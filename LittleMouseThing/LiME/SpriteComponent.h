#pragma once
#include "Component.h"
#include "Sprite.h"

#include <memory>
#include "../SDLTexture.h"
#include "SpriteProperties.h"
#include "SpriteAnimationProperties.h"

namespace LiME
{
	class SpriteComponent :
		public Component
	{
	private:
		//Sprite* sprite;
		
		std::shared_ptr<LM::SDLTexture> texture;
		//SpriteProperties properties;
		LM::Rect<int> frameRegion_;
		LM::Rect<float> drawRegion_;
		float angle_;
		Uint8 alpha_;
		LM::Point2<int> origin_;
		LM::Point2<float> scale_;
		LM::Rect<int> srcRegion_;
	public:
		SpriteComponent(int id);
		virtual ~SpriteComponent();
		void Free();
		LM::Point2<int> GetOrigin() const;
		Uint8 GetAlpha() const;
		float GetScale() const;
		//virtual void Update();
		//void SetSprite(Sprite &spr);
		void SetTexture(std::shared_ptr<LM::SDLTexture> texture);
		//void SetFrameDimensions(LM::Point2<float> dimensions);
		void SetOrigin(LM::Point2<int> origin);
		void SetFrameRegion(LM::Rect<int> frameRegion);
		//void SetPosition(LM::Point2<float> position);
		void SetScale(LM::Point2<float> scale);
		void SetAlpha(Uint8 alpha);
		void Draw();
	};
}