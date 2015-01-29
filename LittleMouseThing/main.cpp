#include "SDLWindowComponentInterface.h"


int main(int argc, char* args[])
{
	LM::SDLWindowComponentInterface* video = new LM::SDLWindowComponentInterface();
	video->CreateWindow("someName", "Window", 640, 480);

	delete video;

	return 0;
}