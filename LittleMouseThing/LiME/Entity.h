#pragma once
#include <vector>
#include "Component.h"

namespace LiME
{
	class Entity
	{
	private:
		int id;
		std::vector<Component*> componentContainer;
	public:
		Entity(int id);
		virtual ~Entity();
		int GetID() const;
		void AddComponent(Component* component);
		void RemoveComponent(Component* component);
		virtual void Update();
	};
}