#pragma once
#include "../LiME/Entity.h"
#include "../LiME/SpriteComponent.h"
#include "../LiME/SpriteComponent.h"

namespace LiME
{
	class SimpleObject :
		public Entity
	{
	private:
		SpriteComponent draw;
	public:
		SimpleObject(int id);
		virtual ~SimpleObject();
		virtual void Update();
	};
}
