#pragma once
#include "Component.h"
#include "../Point2.h"

namespace LiME
{
	class PositionComponent : public Component
	{
	private:
		LM::Point2<float> position;
	public:
		PositionComponent(int id);
		virtual ~PositionComponent();
	};
}
