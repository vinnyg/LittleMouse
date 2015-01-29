//#include <iterator>
#include "SDLWindowComponentInterface.h"

namespace LM
{
	SDLWindowComponentInterface::SDLWindowComponentInterface()
	{

	}

	SDLWindowComponentInterface::~SDLWindowComponentInterface()
	{
		/*std::map<std::string, SDLWindow*>::iterator it = m_windowMap.begin();
		while (it != m_windowMap.end())
		{
		delete it->second;

		++it;
		}*/

		SDL_QuitSubSystem(SDL_INIT_VIDEO);

		m_windowVector.clear();

		//sm_windowMap.clear();

		SDL_Quit();
	}

	//Creates an SDL Window.
	void SDLWindowComponentInterface::CreateWindow(std::string windowRef, std::string title, int w, int h)
	{
		if (!(SDL_WasInit(SDL_INIT_VIDEO) > 0))
		{
			SDL_Init(SDL_INIT_VIDEO);
		}

		if (SDL_WasInit(SDL_INIT_VIDEO) != 0)
		{
			m_windowVector.push_back(std::make_unique<LMSDLWindow>(title, w, h));
			//m_windowMap.insert(std::make_pair(windowRef, std::make_unique<SDLWindow>(title, w, h)));
		}
	}

	//Destroy SDL Window.
	void SDLWindowComponentInterface::DestroyWindow(std::string windowRef)
	{
		//m_windowMap.erase(windowRef);
	}

}
