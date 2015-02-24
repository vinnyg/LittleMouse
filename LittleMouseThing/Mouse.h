#pragma once

#include <SDL.h>

namespace LM
{
	enum class Button
	{
		MB_Left,
		MB_Middle,
		MB_Right,
		MB_X1,
		MB_X2
	};

	class Mouse
	{
	private:

	public:
		Mouse();
		~Mouse();
		Uint32 GetState(int* x, int*y);
		Uint32 GetRelativeState(int* x, int*y);
		int SetRelativeMode(bool enabled);
		bool ButtonIsPressed(Button mb);
	};

}

