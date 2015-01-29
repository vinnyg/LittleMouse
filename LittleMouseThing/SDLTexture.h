#ifndef SDLTEXTURE_H
#define SDLTEXTURE_H

#include <SDL.h>

namespace LM
{
	class SDLTexture
	{
	private:
		SDL_Texture* m_pTexture;
		int m_width;
		int m_height;
		int m_frameCount;
		//float m_animationSpeed;
	public:
		SDLTexture(int width, int height, int frames);
		~SDLTexture();
		int GetWidth() { return m_width; }
		int GetHeight() { return m_height; }
		int GetFrameCount() { return m_frameCount; }
		//float GetAnimationSpeed() { return m_animationSpeed; }
		//float SetAnimationSpeed(float speed) { m_animationSpeed = speed; }
	};

}

#endif