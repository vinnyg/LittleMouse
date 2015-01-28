#ifndef SDLWRAPPER_H
#define SDLWRAPPER_H

#include <map>
#include "SDLWindow.h"
#include "SDLRenderer.h"

namespace LM 
{
	class SDLWrapper
	{
	private:
		std::map<std::string, SDLWindow*> m_windowMap;
	public:
		SDLWrapper();
		~SDLWrapper();
		//Window Subsystem
		void CreateWindow(std::string windowRef, std::string title, int w, int h);
		void DestroyWindow(std::string windowRef);
	};
}
#endif