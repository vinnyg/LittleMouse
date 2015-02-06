#pragma once

#include <SDL.h>

namespace LM
{
	struct ColorRGB
	{
		Uint8 red;
		Uint8 blue;
		Uint8 green;
	};

	struct ColorRGBA
	{
		Uint8 red;
		Uint8 blue;
		Uint8 green;
		Uint8 alpha;
	};

	struct MaskRGBA
	{
		Uint32 red;
		Uint32 blue;
		Uint32 green;
		Uint32 alpha;
	};
}