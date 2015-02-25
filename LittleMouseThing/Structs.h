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
		
		ColorRGBA(int _r, int _g, int _b, int _a) : r(_r), g(_g), b(_b), a(_a)
		{
		}

		ColorRGBA(ColorRGBA const &rhs) : r(rhs.r), g(rhs.g), b(rhs.b), a(rhs.a)
		{
		}

		ColorRGBA(ColorRGB const &rhs) : r(rhs.r), g(rhs.g), b(rhs.b), a(255)
		{
		}
	};
	
	struct MaskRGBA
	{
		Uint32 r;
		Uint32 g;
		Uint32 b;
		Uint32 a;
	};

	namespace Color
	{
		ColorRGB const RED = { 255, 0, 0 };
		ColorRGB const GREEN = { 0, 255, 0 };
		ColorRGB const BLUE = { 0, 0, 255 };
		ColorRGB const LBLUE = { 0, 255, 255 };
		ColorRGB const PURPLE = { 255, 0, 255 };
		ColorRGB const YELLOW = { 255, 255, 0 };
		ColorRGB const WHITE = { 255, 255, 255 };
		ColorRGB const BLACK = { 0, 0, 0 };
	}
}