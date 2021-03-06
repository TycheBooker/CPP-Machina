#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#define IMAGE_DATA "data/"


int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Generic title", sf::Style::Close);
	sf::Keyboard keyboard;
	sf::Texture playerTexture;
	sf::Texture backgroundTexture;
	sf::Vector2f currentPlayerPosition;
	sf::Vector2f minCameraPosition;
	sf::Vector2f maxCameraPosition;

	sf::View camera(sf::FloatRect(0.0f, 0.0f, 800, 600));				// prima 4 parametra, 2 vectora ili floatrect

	playerTexture.loadFromFile(IMAGE_DATA "8_bit_sprites__link_by_toshirofrog-d5h8f42.png");
	backgroundTexture.loadFromFile(IMAGE_DATA "big ol ssss_0.png");

	sf::RectangleShape player(sf::Vector2f(40.0f, 40.0f));
	sf::RectangleShape background(sf::Vector2f(1600.0f, 1200.0f));
	player.setTexture(&playerTexture);
	background.setTexture(&backgroundTexture);

	player.setPosition(sf::Vector2f(800.0f, 600.0f));

	minCameraPosition.x = window.getSize().x / 2;
	minCameraPosition.y = window.getSize().y / 2;
	maxCameraPosition.x = background.getSize().x - minCameraPosition.x;
	maxCameraPosition.y = background.getSize().y - minCameraPosition.y;

	while (window.isOpen())
	{
		sf::Event windowEvent;
		while (window.pollEvent(windowEvent))
		{
			if (windowEvent.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				window.close();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				window.close();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				player.move(-3, 0);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				player.move(0, -3);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				player.move(0, 3);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				player.move(3, 0);
			}
		}

		currentPlayerPosition.x = player.getPosition().x + player.getSize().x / 2;   // getPosition vraća gornju lijevu točku playera
		currentPlayerPosition.y = player.getPosition().y + player.getSize().y / 2;
		sf::Vector2f currentCameraPosition = sf::Vector2f(camera.getCenter());
		if (currentPlayerPosition.x < minCameraPosition.x || currentPlayerPosition.x > maxCameraPosition.x)
		{
			if (currentPlayerPosition.y > minCameraPosition.y && currentPlayerPosition.y < maxCameraPosition.y)
			{
				camera.setCenter(sf::Vector2f(currentCameraPosition.x, currentPlayerPosition.y));
			}
		}
		else if (currentPlayerPosition.y < minCameraPosition.y || currentPlayerPosition.y > maxCameraPosition.y)
		{
			if (currentPlayerPosition.x > minCameraPosition.x && currentPlayerPosition.x < maxCameraPosition.x)
			{
				camera.setCenter(sf::Vector2f(currentPlayerPosition.x, currentCameraPosition.y));
			}
		}
		else
		{
			camera.setCenter(currentPlayerPosition);
		}
		window.setView(camera);								// view setting
		window.clear();
		window.draw(background);
		window.draw(player);
		window.display();
	}
	return 0;
}
