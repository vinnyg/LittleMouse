//#include "SDLWindowComponentInterface.h"
#include "SDLWindow.h"
#include "SDLRenderer.h"
#include "SDLTexture.h"
#include "SDLSurface.h"

int main(int argc, char* args[])
{
	//LM::SDLWindowComponentInterface* video = new LM::SDLWindowComponentInterface();

	//Testing multiple windows.
	LM::SDLWindow window("Project", 640, 480);
	LM::SDLWindow window2("Project", 320, 240);
	window2.SetPosition(20, 40);

	LM::SDLRenderer render(window.Get(), -1, 0);

	/*SDL_Surface* img = SDL_LoadBMP(".\\Assets\\retro_block_exclamation.bmp");
	LM::SDLSurface sur(img);*/

	return 0;
}