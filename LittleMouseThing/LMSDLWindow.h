#ifndef LMSDLWINDOW_H
#define LMSDLWINDOW_H
#include <SDL.h>
#include <string>
#include "SDLWindowEnums.h"

namespace LM
{
	class LMSDLWindow
	{
	private:
		SDL_Window* m_pWindow;
		SDLWindowMode m_windowMode;
	public:
		LMSDLWindow(std::string title, int w, int h);
		~LMSDLWindow();
		void SetWindowTitle(std::string title);
		void SetWindowSize(int w, int h);
		void SetWindowPosition(int x, int y);
		void SetWindowMode(SDLWindowMode mode);
		void SetWindowSettings(std::string title, int w, int h, SDLWindowMode mode);
		SDL_Window* GetWindow() { return m_pWindow; }
	};
}

#endif