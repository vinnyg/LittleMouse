#include <iterator>
#include "SDLWrapper.h"

SDLWrapper::SDLWrapper()
{

}

SDLWrapper::~SDLWrapper()
{
	std::map<std::string, SDLWindow*>::iterator it = m_windowMap.begin();
	while (it != m_windowMap.end())
	{
		//*it->second;
		delete it->second;

		++it;
	}

	SDL_QuitSubSystem(SDL_INIT_VIDEO);

	m_windowMap.clear();

	SDL_Quit();
}

//Creates an SDL Window
void SDLWrapper::CreateWindow(std::string windowRef, std::string title, int w, int h)
{
	if (!(SDL_WasInit(SDL_INIT_VIDEO) > 0))
	{
		SDL_Init(SDL_INIT_VIDEO);
	}

	if (SDL_WasInit(SDL_INIT_VIDEO) != 0)
	{
		m_windowMap.insert(std::make_pair(windowRef, new SDLWindow(title, w, h)));
	}
}

void SDLWrapper::DestroyWindow(std::string windowRef)
{
	m_windowMap.erase(windowRef);
}