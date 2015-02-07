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
			this->title = title;
			m_pWindowSurface = new SDLSurface(SDL_GetWindowSurface(m_pWindow));
		}
	}

	SDLWindow::SDLWindow(const void* data)
	{
		m_pWindow = SDL_CreateWindowFrom(data);
	}

	SDLWindow::~SDLWindow()
	{
		Destroy();
	}

	void SDLWindow::Destroy()
	{
		if (m_pWindowSurface != nullptr)
		{
			delete m_pWindowSurface;
		}
		if (m_pWindow != nullptr)
		{
			SDL_DestroyWindow(m_pWindow);
		}
	}

	void* SDLWindow::GetData(const char* name)
	{
		return SDL_GetWindowData(m_pWindow, name);
	}

	float SDLWindow::GetBrightness()
	{
		return SDL_GetWindowBrightness(m_pWindow);
	}

	int SDLWindow::GetDisplayIndex()
	{
		return SDL_GetWindowDisplayIndex(m_pWindow);
	}

	int SDLWindow::GetDisplayMode(SDL_DisplayMode* mode)
	{
		return SDL_GetWindowDisplayMode(m_pWindow, mode);
	}

	int SDLWindow::GetGammaRamp(Uint16* red, Uint16* green, Uint16* blue)
	{
		return SDL_GetWindowGammaRamp(m_pWindow, red, green, blue);
	}

	int SDLWindow::GetGrabMode()
	{
		return SDL_GetWindowGrab(m_pWindow);
	}

	Uint32 SDLWindow::GetID()
	{
		return SDL_GetWindowID(m_pWindow);
	}

	void SDLWindow::GetMaximumSize(int* w, int* h)
	{
		SDL_GetWindowMaximumSize(m_pWindow, w, h);
	}

	void SDLWindow::GetMinimumSize(int* w, int* h)
	{
		SDL_GetWindowMinimumSize(m_pWindow, w, h);
	}

	Uint32 SDLWindow::GetPixelFormat()
	{
		return SDL_GetWindowPixelFormat(m_pWindow);
	}

	std::string SDLWindow::GetTitle() const
	{
		return title;
	}

	SDLSurface* SDLWindow::GetSurface() const
	{
		return m_pWindowSurface;
	}

	void SDLWindow::GetSize(int &w, int &h) const
	{
		return SDL_GetWindowSize(m_pWindow, &w, &h);
	}

	void SDLWindow::GetPosition(int &x, int &y) const
	{
		return SDL_GetWindowPosition(m_pWindow, &x, &y);
	}

	SDLWindowMode SDLWindow::GetMode() const
	{
		return m_windowMode;
	}

	SDL_Window* SDLWindow::Get() const
	{
		return m_pWindow;
	}

	void SDLWindow::SetTitle(std::string title)
	{
		SDL_SetWindowTitle(m_pWindow, title.c_str());
		this->title = title;
	}

	void SDLWindow::SetSize(int w, int h)
	{
		SDL_SetWindowSize(m_pWindow, w, h);
	}

	void SDLWindow::SetPosition(int x, int y)
	{
		SDL_SetWindowPosition(m_pWindow, x, y);
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

	SDL_bool SDLWindow::GetWMInfo(SDL_SysWMinfo* info)
	{
		return SDL_GetWindowWMInfo(m_pWindow, info);
	}
}