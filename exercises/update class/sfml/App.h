#pragma once
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class App
{
public:
	App();
	~App();
	void execute();

protected:	
	void init();
	sf::Thread thread;				// thread as a class member

	sf::RenderWindow* window;
	sf::Keyboard keyboard;
	sf::Texture playerTexture;
	sf::Texture backgroundTexture;
	sf::Vector2f currentPlayerPosition;
	sf::Vector2f minCameraPosition;
	sf::Vector2f maxCameraPosition;
};

