lass#ifndef SDLWINDOWFACTORY_H
#define SDLWINDOWFACTORY_H

#include <memory>
//#include <map>
#include <vector>
#include "SDLWindow.h"

namespace LM 
{
	class SDLWindowFactory
	{
	private:
		std::vector<std::unique_ptr<SDLWindow>> m_windowVector;
		//std::map<std::string, std::unique_ptr<SDLWindow>> m_windowMap;
	public:
		SDLWindowFactory();
		~SDLWindowFactory();
		//Window Subsystem
		void CreateWindow(std::string windowRef, std::string title, int w, int h);
		void DestroyWindow(std::string windowRef);
	};
}
#endif