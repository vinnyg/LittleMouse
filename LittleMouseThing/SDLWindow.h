#pragma once

#include <SDL.h>
#include <string>
#include "SDLWindowModeEnum.h"

namespace LM
{
	class SDLWindow
	{
	private:
		SDL_Window* m_pWindow;
		SDLWindowMode m_windowMode;
	public:
		SDLWindow(std::string title, int w, int h);
		~SDLWindow();
		std::string GetTitle() const;
		void GetSize(int &w, int &h) const;
		void GetPosition(int &x, int &y) const;
		SDLWindowMode GetMode() const;
		SDL_Window* Get() const;
		void SetTitle(std::string title);
		void SetSize(int w, int h);
		void SetPosition(int x, int y);
		void SetMode(SDLWindowMode mode);
		void SetProperties(std::string title, int w, int h, SDLWindowMode mode);
	};
}