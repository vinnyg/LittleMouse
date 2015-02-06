#pragma once

#include <SDL.h>
#include <SDL_syswm.h>
#include <string>
#include "SDLWindowModeEnum.h"
#include "SDLSurface.h"

namespace LM
{
	class SDLWindow
	{
	private:
		SDL_Window* m_pWindow;
		SDLSurface* m_pWindowSurface;
		SDLWindowMode m_windowMode;
	public:
		SDLWindow(std::string title, int w, int h);
		SDLWindow(const void* data);
		~SDLWindow();
		void Destroy();
		SDL_Window* Get() const;
		void* GetData(const char* name);
		float GetBrightness();
		int GetDisplayIndex();
		int GetDisplayMode(SDL_DisplayMode* mode);
		int GetGammaRamp(Uint16* red, Uint16* green, Uint16* blue);
		int GetGrabMode();
		Uint32 GetID();
		void GetMaximumSize(int* w, int* h);
		void GetMinimumSize(int* w, int* h);
		Uint32 GetPixelFormat();
		std::string GetTitle() const;
		void GetSize(int &w, int &h) const;
		void GetPosition(int &x, int &y) const;
		SDLWindowMode GetMode() const;
		SDLSurface* GetSurface() const;
		void SetTitle(std::string title);
		void SetSize(int w, int h);
		void SetPosition(int x, int y);
		void SetMode(SDLWindowMode mode);
		void SetProperties(std::string title, int w, int h, SDLWindowMode mode);
		SDL_bool GetWMInfo(SDL_SysWMinfo* info);
	};
}