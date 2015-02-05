#pragma once

#include <SDL.h>
#include "Geometry.h"

namespace LM
{
	class SDLTexture
	{
	private:
		SDL_Texture* m_pTexture;
		int m_width;
		int m_height;
		int m_frameCount;
		Uint32 m_format;
		int m_access;

		//float m_animationSpeed;
	public:
		SDLTexture(SDL_Texture* texture);
		SDLTexture(SDL_Texture* texture, int width, int height);
		SDLTexture(SDL_Texture* texture, int frames);
		SDLTexture(SDL_Texture* texture, int width, int height, int frames);
		~SDLTexture();
		int QueryTexture(int* width, int* height);
		int QueryTexture(Uint32* format, int* access, int* width, int* height);
		int GetWidth() { return m_width; }	//Returns the width of an individual frame.
		int GetHeight() { return m_height; }	//Returns the height of an individual frame.
		int GetFrameCount() { return m_frameCount; }
		//float GetAnimationSpeed() { return m_animationSpeed; }
		//float SetAnimationSpeed(float speed) { m_animationSpeed = speed; }
	};
}