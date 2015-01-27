#include "SDLWrapper.h"


int main(int argc, char* args[])
{
	LM::SDLWrapper* engine = new LM::SDLWrapper();
	engine->CreateWindow("someName", "Window", 640, 480);

	delete engine;

	return 0;
}