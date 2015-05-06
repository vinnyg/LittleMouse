#pragma once
#include <vector>
#include "Component.h"

namespace LiME
{
	class System
	{
	private:

	public:
		System();
		virtual ~System();
		virtual void Update() = 0;
	};
}