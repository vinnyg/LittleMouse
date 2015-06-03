#pragma once
#include <vector>
#include "System.h"
#include "AnimationComponent.h"

namespace LiME
{
	class SpriteAnimatorSystem :
		public System
	{
	private:
		std::vector<std::shared_ptr<LiME::AnimationComponent>> components_;
		static int currentID_;
	public:
		SpriteAnimatorSystem();
		virtual ~SpriteAnimatorSystem();
		std::shared_ptr<AnimationComponent> AddComponent(std::shared_ptr<SpriteComponent> sprCom);
		void RemoveComponent(std::shared_ptr<AnimationComponent> component);
		void Update();
	};
}