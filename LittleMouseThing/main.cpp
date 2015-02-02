//#include "SDLWindowComponentInterface.h"
#include "SDLWindow.h"
#include "SDLRenderer.h"

int main(int argc, char* args[])
{
	//LM::SDLWindowComponentInterface* video = new LM::SDLWindowComponentInterface();
	LM::SDLWindow window("Project", 640, 480);
	//video->CreateWindow("someName", "Window", 640, 480);

	LM::SDLRenderer render(window.GetWindow(), -1, 0);

	//delete render;
	//delete window;
	//delete video;

	return 0;
}