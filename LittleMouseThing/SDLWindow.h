#ifndef SDLWINDOW_H
#define SDLWINDOW_H
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
		void SetTitle(std::string title);
		void SetSize(int w, int h);
		void SetPosition(int x, int y);
		void SetMode(SDLWindowMode mode);
		void SetProperties(std::string title, int w, int h, SDLWindowMode mode);

		std::string GetTitle() { return SDL_GetWindowTitle(m_pWindow); }
		void GetSize(int &w, int &h) { return SDL_GetWindowSize(m_pWindow, &w, &h); }
		void GetPosition(int &x, int &y) { return SDL_GetWindowPosition(m_pWindow, &x, &y); }
		SDLWindowMode GetMode() { return m_windowMode; }

		SDL_Window* GetWindow() { return m_pWindow; }
	};
}

#endif