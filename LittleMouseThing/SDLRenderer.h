#ifndef SDLRENDERER_H
#define SDLRENDERER_H

#include <SDL.h>

class SDLRenderer
{
private:
	SDL_Renderer* m_pRenderer;
public:
	SDLRenderer(SDL_Window* window);
	~SDLRenderer();
	void DrawTexture(SDL_Texture* tex, float src_x, float src_y, float src_w, float src_h, float dst_x, float dst_y, float dst_w, float dst_h);
	void DrawTexture(SDL_Texture* tex, float src_x, float src_y, float src_w, float src_h, float dst_x, float dst_y, float dst_w, float dst_h, float offsetX, float offsetY, double angle);
	void Render();
};

#endif