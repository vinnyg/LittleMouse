#pragma once

#include <map>

namespace LM
{

	class Keyboard
	{
	private:
		std::map<int, bool> m_state;
	public:
		Keyboard();
		~Keyboard();
		bool IsKeyHeld();
		bool IsKeyHit();
	};
}
