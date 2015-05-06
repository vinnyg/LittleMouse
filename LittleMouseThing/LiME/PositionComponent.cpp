#include "PositionComponent.h"

namespace LiME
{
	PositionComponent::PositionComponent(int id) : Component(id), position(0.0f, 0.0f) {}

	PositionComponent::~PositionComponent() {}

	LM::Point2<float> PositionComponent::GetPosition() const
	{
		return position;
	}

	/*void PositionComponent::Update()
	{

	}*/
}