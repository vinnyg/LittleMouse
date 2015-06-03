#pragma once
#include <algorithm>
#include <iterator>
#include <memory>
#include <vector>
#include "System.h"
#include "SpriteComponent.h"

namespace LiME
{
	class SpriteDrawingSystem :
		public System
	{
	private:
		std::vector<std::shared_ptr<SpriteComponent>> components_;
		//Temp test
		std::shared_ptr<Sprite> tmpSprite_;
		LM::Rect<int> tmpFrameRegion_;
		/*LM::Rect<int> tmpDrawRegion;
		LM::Point2<int> tmpOrigin;
		double tmpAngle;*/
	public:
		SpriteDrawingSystem();
		virtual ~SpriteDrawingSystem();
		std::shared_ptr<SpriteComponent> AddComponent(int id, std::shared_ptr<Sprite> sprite);
		void RemoveComponent(std::shared_ptr<SpriteComponent> component);
		void Update();
	};
}

