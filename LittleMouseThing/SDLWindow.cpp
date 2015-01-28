#include "SDLWindow.h"
namespace LM
{

	SDLWindow::SDLWindow(std::string title, int w, int h)
	{
		m_pWindow = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, SDL_WINDOW_SHOWN);
	}

	SDLWindow::~SDLWindow()
	{
		SDL_DestroyWindow(m_pWindow);
	}

	void SDLWindow::SetWindowTitle(std::string title)
	{
		if (SDL_GetWindowTitle(m_pWindow) != title.c_str())
		{
			SDL_SetWindowTitle(m_pWindow, title.c_str());
		}
	}

	void SDLWindow::SetWindowSize(int w, int h)
	{
		int currentW, currentH;
		SDL_GetWindowSize(m_pWindow, &currentW, &currentH);
		if ((w != currentW) || (h != currentH))
		{
			SDL_SetWindowSize(m_pWindow, w, h);
		}
	}

	void SDLWindow::SetWindowMode(SDLWindowMode mode)
	{
		if (m_windowMode != mode)
		{
			m_windowMode = mode;

			switch (m_windowMode)
			{
			case SDLWindowMode::WM_WINDOWED:
			{
				SDL_SetWindowBordered(m_pWindow, SDL_FALSE);
				SDL_SetWindowFullscreen(m_pWindow, SDL_FALSE);
			}
			break;
			case SDLWindowMode::WM_BORDERLESS:
			{
				SDL_SetWindowBordered(m_pWindow, SDL_TRUE);
				SDL_SetWindowFullscreen(m_pWindow, SDL_FALSE);
			}
			break;
			case SDLWindowMode::WM_FULLSCREEN:
			{
				SDL_SetWindowBordered(m_pWindow, SDL_FALSE);
				SDL_SetWindowFullscreen(m_pWindow, SDL_TRUE);
			}
			break;
			}
		}
	}

	//Change and apply window settings at once.
	void SDLWindow::SetWindowSettings(std::string title, int w, int h, SDLWindowMode mode)
	{
		SetWindowTitle(title);
		SetWindowSize(w, h);
		SetWindowMode(mode);
	}
}