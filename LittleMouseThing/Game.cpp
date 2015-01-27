#include "Game.h"


Game::Game()
{
}


Game::~Game()
{
}


int Game::Init()
{
	mIsRunning = true;

	/*if (m_pWindow != nullptr)
	{
	m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
	}*/

	//else
	{
		return 1; // sdl could not initialize
	}
}


void Game::Render()
{
	SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 255);
	// clear the window to black
	SDL_RenderClear(m_pRenderer);
	// show the window
	SDL_RenderPresent(m_pRenderer);
}


void Game::Update()
{
}


void Game::HandleInput()
{
}


void Game::Clean()
{
}

bool Game::IsRunning()
{
	return mIsRunning;
}