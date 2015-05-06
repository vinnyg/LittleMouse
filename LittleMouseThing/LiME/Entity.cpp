#include "Entity.h"

namespace LiME
{
	Entity::Entity(int id) : id(id) {}

	Entity::~Entity()
	{
		componentContainer.clear();
	}

	void Entity::AddComponent(Component* component)
	{
		componentContainer.push_back(component);

	}

	void Entity::Update()
	{
		/*std::vector<Component*>::iterator it;
		for (Component* &it : componentContainer)
		{
			it->Update();
		}*/
	}

	int Entity::GetID() const
	{
		return id;
	}
}

