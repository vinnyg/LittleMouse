// #include "SDLWindowComponentInterface.h"
/*#include "SDLExtensionConfig.h"
#include "LMWrapper.h"
#include "SDLTTFont.h"
#include "TTFText.h"*/
#include "LMWrapper.h"

#include "SDLImage.h"

#include "LiME/TextureLoader.h"
#include "LiME/SpriteManager.h"
#include "LiME/Sprite.h"

int main(int argc, char* args[])
{
	SDL_Init(SDL_INIT_EVERYTHING);
	//Testing multiple windows.
#ifdef INCLUDE_SDL_IMAGE
	LM::SDLImage img(IMG_INIT_PNG);
#endif
	LM::SDLWindow window("Project", 640, 480);
	LM::SDLWindow window2("Project", 640, 480);
	window.SetMode(LM::SDLWindowMode::kBorderless);
	window2.SetPosition(20, 40);

	LM::SDLRenderer render(window, -1, 0);
	LM::SDLRenderer render2(window2, -1, 0);
	/*
#ifndef INCLUDE_SDL_IMAGE
	LM::SDLSurface sur("C:\\LittleMouse\\LittleMouseThing\\Assets\\Testing\\retro_block_exclamation.bmp");
#else
	LM::SDLSurface sur("./Assets/Testing/retro_block_exclamation.png");
#endif

	LM::SDLTexture tex(&render, &sur);
	LM::SDLTexture tex2(&render2, &sur);
	TTF_Init();

	LM::SDLTTFont fon("C:/windows/fonts/arial.ttf", 24);
	LM::TTFText text1("this is text!!465ty", &fon, LM::CharEncoding::ENC_LATIN1);

	LM::Rect<int> src(0, 0, 128, 128);
	LM::Rect<int> dst(0, 0, 256, 256);
	
	LM::Point2<double> d_pt(0.0, 0.0);
	LM::Point2<double> d_ptu = d_pt;
	LM::Point2<int> pt(20, 20);
	pt = pt + d_pt;

	LM::Point2<int> pt2(300, 300);
	LM::PixelPrimitive<float> pix(&render, pt2, LM::Color::WHITE);
	LM::LinePrimitive<int> lin(&render, pt, pt2, LM::Color::WHITE);

	LM::SDLSurface texSurface = text1.RenderToSurface(LM::RenderMode::RenderShaded, LM::Color::WHITE, LM::Color::BLACK);
	LM::SDLTexture text1rend(&render, &texSurface);
	int t_w, t_h;
	text1rend.Query(&t_w, &t_h);
	LM::Rect<int> dstText(200, 250, t_w, t_h);

	//sur.Blit(src, window.GetSurface(), dst);*/

	//TTF_Quit();

	LiME::TextureLoader tLoader(render);
	LiME::SpriteManager manager;

	LM::Keyboard keyboard;
	LM::Mouse mouse;

	LM::ColorRGBA ra =
	{
		255, 0, 0, 128
	};

	LM::Rect<int> rct(100, 100, 300, 310);
	LM::RectPrimitive<int> rec(&render, rct, true, ra);

	bool isRunning = true;
	std::shared_ptr<LM::SDLTexture> t = tLoader.LoadTexture("./Assets/Testing/retro_block_exclamation.png");
	std::shared_ptr<LM::SDLTexture> t2 = tLoader.LoadTexture("C:/Users/Vinny/Google Drive/Sham & Vinny/Fotos/GAF (NOT JIF)/Cute/Cutedash.png");
	std::shared_ptr<LiME::Sprite> spr = manager.CreateSprite(t);
	std::shared_ptr<LiME::Sprite> spr_dash = manager.CreateSprite(t2);
	spr->SetPosition(LM::Point2<float>(20.0f, 20.0f));
	spr->SetScale(LM::Point2<float>(2.0f, 2.0f));
	spr->SetAlpha(220);

	spr_dash->SetPosition(LM::Point2<float>(50, 70));
	spr_dash->SetScale(LM::Point2<float>(0.75f, 0.75f));

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

		if (keyboard.KeyIsHeld(LM::Key::Key_ESCAPE))/* && keyboard.IsKeyHeld(LM::Key::Key_a) *//*&& keyboard.IsKeyHeld(LM::Key::Key_w))*/
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

		/*render2.SetDrawColor(LM::Color::BLACK);
		render2.SetDrawBlendMode(SDL_BLENDMODE_BLEND);
		render2.Clear();*/

		/*text1rend.CopyToRenderer(dstText);
		tex.CopyToRenderer(src, dst, pt, 0.0, LM::SDLRenderFlipEnum::kNoFlip);
		tex2.CopyToRenderer(src, dst, pt, 0.0, LM::SDLRenderFlipEnum::kNoFlip);
		pix.SetDrawColor(LM::Color::WHITE);
		lin.SetDrawColor(LM::Color::WHITE);
		pix.Draw();
		lin.Draw();*/
		rec.Draw();
		manager.Draw();

		render.Present();
		render2.Present();
	}

	return 0;
}