#include "SDLWindow.h"

namespace LM
{
	SDLWindow::SDLWindow(std::string title, int w, int h)
	{
		if (!(SDL_WasInit(SDL_INIT_VIDEO) > 0))
		{
			SDL_Init(SDL_INIT_VIDEO);
		}

		if (SDL_WasInit(SDL_INIT_VIDEO) != 0)
		{
			m_pWindow = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, SDL_WINDOW_SHOWN);
		}
	}

	SDLWindow::~SDLWindow()
	{
		SDL_DestroyWindow(m_pWindow);
	}

	void SDLWindow::SetTitle(std::string title)
	{
		SDL_SetWindowTitle(m_pWindow, title.c_str());
	}

	void SDLWindow::SetSize(int w, int h)
	{
		SDL_SetWindowSize(m_pWindow, w, h);
	}

	void SDLWindow::SetMode(SDLWindowMode mode)
	{
		m_windowMode = mode;

		switch (m_windowMode)
		{
		case SDLWindowMode::kWindowed:
		{
			SDL_SetWindowBordered(m_pWindow, SDL_FALSE);
			SDL_SetWindowFullscreen(m_pWindow, SDL_FALSE);
		}
		break;
		case SDLWindowMode::kBorderless:
		{
			SDL_SetWindowBordered(m_pWindow, SDL_TRUE);
			SDL_SetWindowFullscreen(m_pWindow, SDL_FALSE);
		}
		break;
		case SDLWindowMode::kFullscreen:
		{
			SDL_SetWindowBordered(m_pWindow, SDL_FALSE);
			SDL_SetWindowFullscreen(m_pWindow, SDL_TRUE);
		}
		break;
		}
	}

	//Change and apply window settings at once.
	void SDLWindow::SetProperties(std::string title, int w, int h, SDLWindowMode mode)
	{
		if (SDL_GetWindowTitle(m_pWindow) != title.c_str())
		{
			SetTitle(title);
		}

		int currentW, currentH;
		SDL_GetWindowSize(m_pWindow, &currentW, &currentH);
		if ((w != currentW) || (h != currentH))
		{
			SetSize(w, h);
		}

		if (m_windowMode != mode)
		{
			SetMode(mode);
		}
	}
}