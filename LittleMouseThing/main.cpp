/* #include "SDLWindowComponentInterface.h"
#include "SDLExtensionConfig.h"
#include "LMWrapper.h"
#include "SDLTTFont.h"
#include "TTFText.h"*/

#include "LMWrapper.h"
#include "SDLImage.h"
#include "LiME/LiME.h"

#include "LiME/SpriteComponent.h"
#include "LiME/PositionComponent.h"

#include "LiME/SpriteDrawingSystem.h"
#include "LiME/SpriteAnimatorSystem.h"

//#include "ExampleProject/SimpleObject.h"

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
	LM::RectPrimitive<int> rec(render, rct, true, ra);

	bool isRunning = true;
	std::shared_ptr<LM::SDLTexture> t = tLoader.LoadTexture("./Assets/Testing/retro_block_exclamation.png");
	std::shared_ptr<LM::SDLTexture> t2 = tLoader.LoadTexture("C:/Users/Vinny/Google Drive/Sham & Vinny/Fotos/GAF (NOT JIF)/Cute/Cutedash.png");
	std::shared_ptr<LM::SDLTexture> t3 = tLoader.LoadTexture("C:/Users/Vinny/Google Drive/Sham & Vinny/Fotos/GAF (NOT JIF)/Cute/pinkiewalk.png");
	std::shared_ptr<LiME::Sprite> spr = manager.CreateSprite(t);
	std::shared_ptr<LiME::Sprite> spr_dash = manager.CreateSprite(t2);
	LM::Rect<int> pinkieRect(0, 0, 64, 65);
	std::shared_ptr<LiME::Sprite> spr_pink = manager.CreateSprite(t3, 16, pinkieRect);
	/*spr->SetPosition(LM::Point2<float>(20.0f, 20.0f));
	spr->SetScale(LM::Point2<float>(2.0f, 2.0f));
	spr->SetAlpha(220);

	spr_dash->SetPosition(LM::Point2<float>(50, 70));
	spr_dash->SetScale(LM::Point2<float>(0.75f, 0.75f));*/

	//LiME::Entity simpleObject(0);
	//LiME::SpriteComponent simpleObjectDrawable(0);
	//LiME::PositionComponent simpleObjectPosition(0);
	//simpleObject.AddComponent(&simpleObjectDrawable);
	//simpleObjectDrawable.SetTexture(t2);//SetSprite(*(spr_dash.get()));
	//simpleObjectDrawable.SetScale(LM::Point2<float>(0.75f, 0.75f));

	LiME::SpriteDrawingSystem dSys;
	LiME::SpriteAnimatorSystem aSys;
	std::shared_ptr<LiME::SpriteComponent> ponyCom = dSys.AddComponent(0, spr_dash);
	std::shared_ptr<LiME::SpriteComponent> blockCom = dSys.AddComponent(1, spr);
	std::shared_ptr<LiME::SpriteComponent> pinkieCom = dSys.AddComponent(2, spr_pink);
	std::shared_ptr<LiME::AnimationComponent> pinkieAnimCom = aSys.AddComponent(pinkieCom);
	LM::Rect<int> sqr = blockCom->GetDrawRegion();
	LM::Point2<float> blockScale = { 0.0f, 0.0f };
	blockCom->SetScale(blockScale);
	ponyCom->SetScale(LM::Point2<float>(0.4f, 0.4f));
	//ponyCom->SetSprite(spr_dash.get());

	pinkieAnimCom->SetAnimationSpeed(0.01f);

	float x = 0.f, y = 0.f;

	LM::Point2<int> o(0, 0);
	LM::Point2<int> q(0, 0);
	t->Query(q);
	LM::Rect<int> sr({ 0, 0 }, q);
	LM::Rect<int> dr({ 150, 200 }, q*x);
	LM::Point2<float> scale({ x, y });
	
	while (isRunning)
	{
		SDL_Event e;
		while (SDL_PollEvent(&e))
		{
			/*switch (e.type)
			{
			case SDL_QUIT: {} break;

			case SDL_KEYDOWN: {} break;

			}*/
		}

		if (keyboard.KeyIsHeld(LM::Key::Key_ESCAPE))/* && keyboard.IsKeyHeld(LM::Key::Key_a) *//*&& keyboard.IsKeyHeld(LM::Key::Key_w))*/
		{
			isRunning = !isRunning;
		}

		if (mouse.ButtonIsPressed(LM::Button::MB_Left))
		{

			rec.SetDrawColor(LM::Color::YELLOW);
		}

		x = x + .0001f;
		y = y + .0001f;

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
		tex2.CopyToRenderer(src, dst, pt, 0.0, LM::SDLRenderFlipEnum::kNoFlip);
		pix.SetDrawColor(LM::Color::WHITE);
		lin.SetDrawColor(LM::Color::WHITE);
		pix.Draw();
		lin.Draw();*/

		//simpleObject.Update();
		/*simpleObjectDrawable.Draw();
		rec.Draw();
		spr->Draw();
		spr_dash->Draw();
		manager.Draw();*/
		//spr->Draw(LM::Point2<float>(x, y), LM::Point2<float>(200.f, 200.f));

		//blockCom->SetScale(LM::Point2<float>(x, y));
		//dr.SetDimension();
		//t->CopyToRenderer(sr, dr, o, 0.0, LM::SDLRenderFlipEnum::kNoFlip);
		/*t->CopyToRenderer(dr);*/

		/*int qw, qh;
		SDL_QueryTexture(t->Get(), nullptr, nullptr, &qw, &qh);
		SDL_Rect src_r = { 0, 0, qw, qh };
		SDL_Rect dst_r = { 320, 30, qw * 1.5, qh * 1.5 };
		SDL_Point p = { 0, 0 };
		//SDL_RenderCopyEx(render.Get(), t->Get(), &src_r, &dst_r, 0.0f, &p, SDL_FLIP_NONE);
		SDL_Rect src_r2 = sr.ToSDLRect();
		SDL_Rect dst_r2 = dr.ToSDLRect();
		LM::SDLRenderFlipEnum flip = LM::SDLRenderFlipEnum::kNoFlip;
		/*if (SDL_RenderCopyEx(render.Get(), t->Get(), &src_r2, &dst_r2, 0.0f, &p, static_cast<SDL_RendererFlip>(flip)));*/

		blockScale.SetX(x);
		blockScale.SetY(y);
		blockCom->SetScale(blockScale);

		dSys.Update();
		aSys.Update();

		render.Present();
		render2.Present();

		//sqr = blockCom->GetDrawRegion();
	}

	return 0;
}