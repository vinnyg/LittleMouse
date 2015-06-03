#pragma once
#include "Component.h"
#include "Sprite.h"

#include <memory>
#include "../SDLTexture.h"
#include "SpriteProperties.h"
#include "SpriteAnimationProperties.h"
#include "AnimatedSpriteProperties.h"

namespace LiME
{
	class SpriteComponent :
		public Component
	{
	private:
		std::shared_ptr<Sprite> sprite_;
		std::shared_ptr<LM::SDLTexture> texturePtr_;
		//std::shared_ptr<LM::SDLTexture> texture;
		//SpriteProperties properties;
		//LM::Rect<int> frameRegion_;			//The region from the texture which will be used for rendering.
		//LiME::AnimatedSpriteProperties properties;
		//int spriteComponentID;			//Reference for other components
		LM::Point2<int> origin_;		//Origin position of sprite, used for rotations
		float angle_;
		Uint8 alpha_;
		LM::Point2<float> scale_;		//x and y scaling for sprite
		//float frameIndex_;			//Current frame in animation cycle as a float
		int currentFrame_;				//Current frame in animation cycle
		LM::Rect<int> drawRegion_;		//A rectangle representing the resulting region to which the texture will be rendered to after position and scale are applied.

		//float angle_;
		//Uint8 alpha_;
		//LM::Point2<int> origin_;
		//LM::Point2<float> scale_;
		//LM::Rect<int> srcRegion_;
	public:
		SpriteComponent(int id, std::shared_ptr<Sprite> sprite);
		virtual ~SpriteComponent();
		void Free();
		LM::Point2<int> GetOrigin() const;
		std::shared_ptr<Sprite> GetSprite() const;
		float GetAngle() const;
		Uint8 GetAlpha() const;
		float GetScale() const;
		int GetCurrentFrame() const;
		LM::Rect<int> GetDrawRegion() const;
		LM::Point2<int> GetPosition() const;
		void SetOrigin(LM::Point2<int> &origin);
		void SetSprite(Sprite* sprite);
		void SetScale(LM::Point2<float> &scale);
		void SetAngle(float angle);
		void SetAlpha(Uint8 alpha);
		void SetCurrentFrame(int frame);
		void SetPosition(LM::Point2<int> &position);
		//void Draw();
		//int GetFrameCount() const;
		//std::shared_ptr<LM::SDLTexture> GetTexture() const;
		//virtual void Update();
		//void SetSprite(Sprite &spr);
		//void SetTexture(std::shared_ptr<LM::SDLTexture> texture);
		//void SetFrameDimensions(LM::Point2<float> dimensions);
		//void SetFrameRegion(LM::Rect<int> frameRegion);
		//void SetPosition(LM::Point2<float> position);
		//void SetFrameCount(int frames);
	};
}