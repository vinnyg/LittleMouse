//#include "SDLWindowComponentInterface.h"
#include "SDLWindow.h"
#include "SDLRenderer.h"
#include "SDLTexture.h"
#include "SDLExtensionConfig.h"

#include "SDLImage.h"

#include "SDLRenderFlipEnum.h"
//#include "Primitive.h"
#include "PrimPixel.h"
#include "SDLSurface.h"



int main(int argc, char* args[])
{
	//LM::SDLWindowComponentInterface* video = new LM::SDLWindowComponentInterface();

	//Testing multiple windows.
#ifdef INCLUDE_SDL_IMAGE
	LM::SDLImage img(IMG_INIT_PNG);
#endif
	LM::SDLWindow window("Project", 640, 480);
	LM::SDLWindow window2("Project", 320, 240);
	window.SetMode(LM::SDLWindowMode::kBorderless);
	window2.SetPosition(20, 40);

	LM::SDLRenderer render(window.Get(), -1, 0);

	//LM::SDLSurface sur("/Assets/Testing/retro_block_exclamation.bmp");
#ifndef INCLUDE_SDL_IMAGE
	LM::SDLSurface sur("C:\\LittleMouse\\LittleMouseThing\\Assets\\Testing\\retro_block_exclamation.bmp");
#else
	LM::SDLSurface sur("C:\\LittleMouse\\LittleMouseThing\\Assets\\Testing\\retro_block_exclamation.png");
#endif

	LM::SDLTexture tex(&render, &sur);

	LM::ColorRGBA c =
	{
		0, 0, 0, 255
	};

	LM::ColorRGBA white =
	{
		255, 255, 255, 255
	};

	LM::Rect src(0, 0, 128, 128);
	LM::Rect dst(0, 0, 256, 256);
	LM::Point2 pt(0, 0);

	LM::Point2 pt2(300, 300);
	LM::PrimPixel pix(&render, pt2, white);

	//sur.Blit(src, window.GetSurface(), dst);

	render.SetDrawColor(c);
	render.Clear();

	tex.CopyToRenderer(&render, src, dst, pt, 0.0, LM::SDLRenderFlipEnum::kNoFlip);
	
	pix.Draw();

	render.Present();

	system("Pause");

	//delete render;

	return 0;
}