#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Animation.h"

#define GRAPHICS_PATH "data/graphics/"
#define FPS 1.0f


int main()
{
	std::vector<int> myVector;
	sf::Context context();
	sf::RenderWindow window(sf::VideoMode(800, 600), "I created my first Window! YAY!");

	sf::Keyboard keyboardController;

	sf::RectangleShape player(sf::Vector2f(73.0f, 97.0f));
	sf::Texture playerTexture;
	playerTexture.loadFromFile(GRAPHICS_PATH "Player/p1_walk/p1_walk.png");

	float deltaTime = 0.0f;
	sf::Clock clock;

	//sf::Vector2f       sf grafički vectori (float, integer i unsigned)
	//sf::Vector2i
	//sf::Vector2u

	sf::Vector2u playerWalkImageCount;
	playerWalkImageCount.x = 3;
	playerWalkImageCount.y = 3;

	Animation PlayerAnimation(&player, &playerTexture, playerWalkImageCount, FPS);

	while (window.isOpen())
	{
		deltaTime = clock.restart().asSeconds();
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		PlayerAnimation.update(deltaTime);

		window.clear();
		window.draw(player);
		window.display();
	}
    return 0;
}

