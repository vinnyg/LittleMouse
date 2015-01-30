//#include "SDLWindowComponentInterface.h"
#include "LMSDLWindow.h"
#include "LMSDLRenderer.h"

int main(int argc, char* args[])
{
	//LM::SDLWindowComponentInterface* video = new LM::SDLWindowComponentInterface();
	LM::LMSDLWindow* window = new LM::LMSDLWindow("Project", 640, 480);
	//video->CreateWindow("someName", "Window", 640, 480);

	LM::LMSDLRenderer* render = new LM::LMSDLRenderer(window->GetWindow(), -1, 0);

	delete render;
	delete window;
	//delete video;

	return 0;
}