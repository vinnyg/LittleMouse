#ifndef SDLWINDOW_H
#define SDLWINDOW_H
#include <SDL.h>
#include <string>
#include "SDLWindowEnums.h"

namespace LM
{
	class SDLWindow
	{
	private:
		SDL_Window* m_pWindow = nullptr;
		SDLWindowMode m_windowMode;
	public:
		SDLWindow(std::string title, int w, int h);
		~SDLWindow();
		void SetWindowTitle(std::string title);
		void SetWindowSize(int w, int h);
		void SetWindowPosition(int x, int y);
		void SetWindowMode(SDLWindowMode mode);
		void ApplyWindowSettings();
		void SetWindowSettings(std::string title, int w, int h, SDLWindowMode mode);
	};
}

#endif