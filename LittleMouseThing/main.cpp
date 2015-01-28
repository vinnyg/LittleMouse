#include "SDLWindowFactory.h"


int main(int argc, char* args[])
{
	LM::SDLWindowFactory* engine = new LM::SDLWindowFactory();
	engine->CreateWindow("someName", "Window", 640, 480);

	delete engine;

	return 0;
}