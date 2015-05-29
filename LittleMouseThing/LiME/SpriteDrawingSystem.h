#pragma once
#include <algorithm>
#include <iterator>
#include <vector>
#include "System.h"
#include "SpriteComponent.h"

namespace LiME
{
	class SpriteDrawingSystem :
		public System
	{
	private:
		std::vector<LiME::SpriteComponent*> components_;
		//Temp test
		LiME::Sprite* tmpSprite;
		LM::Rect<int> tmpFrameRegion;
		LM::Rect<int> tmpDrawRegion;
		LM::Point2<int> tmpOrigin;
		double tmpAngle;
	public:
		SpriteDrawingSystem();
		virtual ~SpriteDrawingSystem();
		SpriteComponent* AddComponent(int id, Sprite* sprite);
		void RemoveComponent(SpriteComponent* component);
		void Update();
	};
}

