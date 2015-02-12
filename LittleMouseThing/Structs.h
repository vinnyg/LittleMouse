#pragma once

#include <SDL.h>

namespace LM
{
	struct ColorRGB
	{
		Uint8 r;
		Uint8 g;
		Uint8 b;

		/*ColorRGB(const ColorRGBA& c) : r(c.r), g(c.g), b(c.b)
		{
		}*/
	};

	struct ColorRGBA
	{
		Uint8 r;
		Uint8 g;
		Uint8 b;
		Uint8 a;

		/*ColorRGBA(const ColorRGB &c) : r(c.r), g(c.g), b(c.b), a(255)
		{
		}*/
	};

	
	struct MaskRGBA
	{
		Uint32 r;
		Uint32 g;
		Uint32 b;
		Uint32 a;
	};
}