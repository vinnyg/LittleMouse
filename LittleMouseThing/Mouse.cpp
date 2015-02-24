#include "Mouse.h"

namespace LM
{
	Mouse::Mouse()
	{

	}

	Mouse::~Mouse()
	{

	}

	Uint32 Mouse::GetState(int* x, int*y)
	{
		return SDL_GetMouseState(x, y);
	}

	Uint32 Mouse::GetRelativeState(int* x, int*y)
	{
		return SDL_GetRelativeMouseState(x, y);
	}

	int Mouse::SetRelativeMode(bool enabled)
	{
		return SDL_SetRelativeMouseMode(static_cast<SDL_bool>(enabled));
	}

	bool Mouse::ButtonIsPressed(Button mb)
	{
		bool isPressed;

		switch (mb)
		{
		case Button::MB_Left:
			isPressed = (GetState(nullptr, nullptr) & SDL_BUTTON(SDL_BUTTON_LEFT));
			break;
		case Button::MB_Middle:
			isPressed = (GetState(nullptr, nullptr) & SDL_BUTTON(SDL_BUTTON_MIDDLE));
			break;
		case Button::MB_Right:
			isPressed = (GetState(nullptr, nullptr) & SDL_BUTTON(SDL_BUTTON_RIGHT));
			break;
		case Button::MB_X1:
			isPressed = (GetState(nullptr, nullptr) & SDL_BUTTON(SDL_BUTTON_X1));
			break;
		case Button::MB_X2:
			isPressed = (GetState(nullptr, nullptr) & SDL_BUTTON(SDL_BUTTON_X2));
			break;
		default:
			isPressed = false;
		}

		return isPressed;
	}
}

