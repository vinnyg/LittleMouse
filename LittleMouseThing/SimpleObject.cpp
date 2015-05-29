#include "ExampleProject\SimpleObject.h"

namespace LiME
{
	SimpleObject::SimpleObject(int id) : Entity(id), draw(GetID(), nullptr) {}

	SimpleObject::~SimpleObject() {}

	void SimpleObject::Update()
	{
		//draw.Draw();
	}
}
