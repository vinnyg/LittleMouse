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
	public:
		SpriteDrawingSystem();
		virtual ~SpriteDrawingSystem();
		SpriteComponent* AddComponent(int id);
		void RemoveComponent(SpriteComponent* component);
		void Update();
	};
}

