#pragma once
#include "Window.h"
#include "World.h"
#include "Snake.h"

class Game
{
public:
	Game();
	~Game();

	void handleInput();
	void update();
	void render();
	Window * getWindow();
	sf::Time getElapsed();
	void restartClock();
private:
	Window m_window;
	sf::Clock m_clock;
	sf::Time m_elapsed;
    World m_world;
    Snake m_snake;
};