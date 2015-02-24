#pragma once

#include <SDL.h>

namespace LM
{
	struct ColorRGB
	{
		Uint8 r;
		Uint8 g;
		Uint8 b;
	};

	struct ColorRGBA
	{
		Uint8 r;
		Uint8 g;
		Uint8 b;
		Uint8 a;
	};

	
	struct MaskRGBA
	{
		Uint32 r;
		Uint32 g;
		Uint32 b;
		Uint32 a;
	};
}