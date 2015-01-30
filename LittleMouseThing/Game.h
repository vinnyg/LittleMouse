#ifndef GAME_H
#define GAME_H
#include<SDL.h>

//Try again

class Game
{
private:
	bool mIsRunning;
	SDL_Renderer* m_pRenderer = nullptr;
public:
	Game();
	~Game();
	int Init();
	void Render();
	void Update();
	void HandleInput();
	void Clean();
	bool IsRunning();
};

#endif