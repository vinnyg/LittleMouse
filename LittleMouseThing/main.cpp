// #include "SDLWindowComponentInterface.h"
// #include "SDLWindow.h"
// #include "SDLRenderer.h"
// #include "SDLTexture.h"
// #include "Primitives.h"
// #include "SDLSurface.h"
// #include "Keyboard.h"
// #include "Mouse.h"

#include "SDLExtensionConfig.h"
#include "LMWrapper.h"
#include "SDLImage.h"
#include "SDLTTFont.h"
#include "TTFText.h"

int main(int argc, char* args[])
{
	SDL_Init(SDL_INIT_EVERYTHING);
	//Testing multiple windows.
#ifdef INCLUDE_SDL_IMAGE
	LM::SDLImage img(IMG_INIT_PNG);
#endif
	LM::SDLWindow window("Project", 640, 480);
	LM::SDLWindow window2("Project", 320, 240);
	window.SetMode(LM::SDLWindowMode::kBorderless);
	window2.SetPosition(20, 40);

	LM::SDLRenderer render(window.Get(), -1, 0);

#ifndef INCLUDE_SDL_IMAGE
	LM::SDLSurface sur("C:\\LittleMouse\\LittleMouseThing\\Assets\\Testing\\retro_block_exclamation.bmp");
#else
	LM::SDLSurface sur("./Assets/Testing/retro_block_exclamation.png");
#endif

	LM::SDLTexture tex(&render, &sur);
	TTF_Init();

	LM::SDLTTFont fon("C:/windows/fonts/arial.ttf", 24);
	LM::TTFText text1("this is text!!465ty", &fon, LM::CharEncoding::ENC_LATIN1);
	LM::Keyboard keyboard;
	LM::Mouse mouse;

	bool isRunning = true;

	LM::ColorRGBA ra =
	{
		255, 0, 0, 128
	};

	LM::Rect src(0, 0, 128, 128);
	LM::Rect dst(0, 0, 256, 256);
	LM::Rect rct(100, 100, 300, 310);
	LM::Point2 pt(0, 0);

	LM::Point2 pt2(300, 300);
	LM::PixelPrimitive pix(&render, pt2, LM::Color::WHITE);
	LM::LinePrimitive lin(&render, pt, pt2, LM::Color::WHITE);
	LM::RectPrimitive rec(&render, rct, true, ra);

	LM::SDLSurface texSurface = text1.RenderToSurface(LM::RenderMode::RenderShaded, LM::Color::WHITE, LM::Color::BLACK);
	LM::SDLTexture text1rend(&render, &texSurface);
	int t_w, t_h;
	text1rend.Query(&t_w, &t_h);
	LM::Rect dstText(200, 250, t_w, t_h);

	//sur.Blit(src, window.GetSurface(), dst);

	while (isRunning)
	{
		SDL_Event e;
		while (SDL_PollEvent(&e))
		{
			switch (e.type)
			{
			case SDL_QUIT:
				{

				} break;

			case SDL_KEYDOWN:
				{

				} break;
				
			}
		}
		
		if (keyboard.KeyIsHeld(LM::Key::Key_ESCAPE)/* && keyboard.IsKeyHeld(LM::Key::Key_a) *//*&& keyboard.IsKeyHeld(LM::Key::Key_w)*/)
		{
			isRunning = !isRunning;
		}

		if (mouse.ButtonIsPressed(LM::Button::MB_Left))
		{
			rec.SetDrawColor(LM::Color::YELLOW);
		}

		if (mouse.ButtonIsPressed(LM::Button::MB_Right))
		{
			rec.SetDrawColor(LM::Color::BLUE);
		}

		render.SetDrawColor(LM::Color::BLACK);
		render.SetDrawBlendMode(SDL_BLENDMODE_BLEND);
		render.Clear();

		text1rend.CopyToRenderer(&render, dstText);
		tex.CopyToRenderer(&render, src, dst, pt, 0.0, LM::SDLRenderFlipEnum::kNoFlip);
		pix.SetDrawColor(LM::Color::WHITE);
		lin.SetDrawColor(LM::Color::WHITE);
		pix.Draw();
		lin.Draw();
		rec.Draw();

		render.Present();
	}

	//TTF_Quit();

	return 0;
}