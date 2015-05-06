#include "ExampleProject\SimpleObject.h"

namespace LiME
{
	SimpleObject::SimpleObject(int id) : Entity(id), draw(GetID()) {}

	SimpleObject::~SimpleObject() {}

	void SimpleObject::Update()
	{
		draw.Draw();
	}
}
