#include "SDLWrapper.h"

int main(int argc, char* args[])
{
	SDLWrapper* engine = new SDLWrapper();
	engine->CreateWindow("someName", "Window", 640, 480);

	delete engine;

	return 0;
}