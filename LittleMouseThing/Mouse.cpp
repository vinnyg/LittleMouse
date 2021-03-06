#include "Mouse.h"

namespace LM
{
	Mouse::Mouse() : position(0, 0) {}

	Mouse::~Mouse() {}

	Uint32 Mouse::GetState()
	{
		return SDL_GetMouseState(nullptr, nullptr);
	}

	Point2<int> Mouse::GetPosition()
	{
		int x, y;
		SDL_GetMouseState(&x, &y);
		return Point2<int>(x, y);
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
			isPressed = ((GetState() & SDL_BUTTON(SDL_BUTTON_LEFT)) != 0);
			break;
		case Button::MB_Middle:
			isPressed = ((GetState() & SDL_BUTTON(SDL_BUTTON_MIDDLE)) != 0);
			break;
		case Button::MB_Right:
			isPressed = ((GetState() & SDL_BUTTON(SDL_BUTTON_RIGHT)) != 0);
			break;
		case Button::MB_X1:
			isPressed = ((GetState() & SDL_BUTTON(SDL_BUTTON_X1)) != 0);
			break;
		case Button::MB_X2:
			isPressed = ((GetState() & SDL_BUTTON(SDL_BUTTON_X2)) != 0);
			break;
		default:
			isPressed = false;
		}

		return isPressed;
	}
}

