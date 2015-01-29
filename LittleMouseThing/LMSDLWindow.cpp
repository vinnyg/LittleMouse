#include "LMSDLWindow.h"

namespace LM
{
	LMSDLWindow::LMSDLWindow(std::string title, int w, int h)
	{
		m_pWindow = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, SDL_WINDOW_SHOWN);
	}

	LMSDLWindow::~LMSDLWindow()
	{
		SDL_DestroyWindow(m_pWindow);
	}

	void LMSDLWindow::SetWindowTitle(std::string title)
	{
		SDL_SetWindowTitle(m_pWindow, title.c_str());
	}

	void LMSDLWindow::SetWindowSize(int w, int h)
	{
		SDL_SetWindowSize(m_pWindow, w, h);
	}

	void LMSDLWindow::SetWindowMode(SDLWindowMode mode)
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

	//Change and apply window settings at once.
	void LMSDLWindow::SetWindowSettings(std::string title, int w, int h, SDLWindowMode mode)
	{
		//We do these checks out here to reduce function calls.
		if (SDL_GetWindowTitle(m_pWindow) != title.c_str())
		{
			SetWindowTitle(title);
		}

		int currentW, currentH;
		SDL_GetWindowSize(m_pWindow, &currentW, &currentH);
		if ((w != currentW) || (h != currentH))
		{
			SetWindowSize(w, h);
		}

		if (m_windowMode != mode)
		{
			SetWindowMode(mode);
		}
	}
}