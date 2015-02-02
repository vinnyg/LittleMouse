//#include "SDLWindowComponentInterface.h"
#include "SDLWindow.h"
#include "SDLRenderer.h"

int main(int argc, char* args[])
{
	//LM::SDLWindowComponentInterface* video = new LM::SDLWindowComponentInterface();

	//Testing multiple windows.
	LM::SDLWindow window("Project", 640, 480);
	LM::SDLWindow window2("Project", 320, 240);
	window2.SetPosition(20, 40);
	//video->CreateWindow("someName", "Window", 640, 480);

	LM::SDLRenderer render(window.GetWindow(), -1, 0);

	//delete render;
	//delete window;
	//delete video;

	return 0;
}