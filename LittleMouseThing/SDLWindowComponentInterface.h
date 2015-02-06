#pragma once

#include <memory>
//#include <map>
#include <vector>
#include "SDLWindow.h"

namespace LM 
{
	class SDLWindowComponentInterface
	{
	private:
		std::vector<std::unique_ptr<SDLWindow>> m_windowVector;
		//std::map<std::string, std::unique_ptr<SDLWindow>> m_windowMap;
	public:
		SDLWindowComponentInterface();
		~SDLWindowComponentInterface();
		void CreateSDLWindow(std::string windowRef, std::string title, int w, int h);
		void DestroySDLWindow(std::string windowRef);
	};
}