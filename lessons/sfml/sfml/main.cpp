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
#define FPS 0.3f


int main()
{
	std::vector<int> myVector;
	sf::Context context();
	sf::RenderWindow window(sf::VideoMode(800, 600), "I created my first Window! YAY!");

	sf::Keyboard keyboardController;

	sf::RectangleShape player(sf::Vector2f(100.0f, 150.0f));
	sf::Texture playerTexture;
	playerTexture.loadFromFile(GRAPHICS_PATH "Player/p1_spritesheet.png");

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

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			player.move(-0.1, 0);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			player.move(0, -0.1);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			player.move(0, 0.1);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			player.move(0.1, 0);
		}

		PlayerAnimation.update(deltaTime);

		window.clear();
		window.draw(player);
		window.display();
	}
    return 0;
}

