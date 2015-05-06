#pragma once
#include "Component.h"

namespace LiME
{
	class InputComponent :
		public Component
	{
	public:
		InputComponent(int id);
		virtual ~InputComponent();
	};
}