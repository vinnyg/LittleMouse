#include "Component.h"

namespace LiME
{
	Component::Component(int id) : entityID(id) {}

	Component::~Component() {}

	int Component::GetID() const
	{
		return entityID;
	}
}