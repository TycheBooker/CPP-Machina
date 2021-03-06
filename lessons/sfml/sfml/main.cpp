#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


int main()
{
	std::vector<int> myVector;
	sf::Context context();
	sf::RenderWindow window(sf::VideoMode(800, 600), "I created my first Window! YAY!"); // ,sf::Style::Fullscreen
	sf::CircleShape ourFirstGraphic(20.0f);
	ourFirstGraphic.setFillColor(sf::Color::Red);
	sf::Keyboard keyboardController;

	while (window.isOpen())
	{
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
			ourFirstGraphic.move(-0.1, 0);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			ourFirstGraphic.move(0, -0.1);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			ourFirstGraphic.move(0, 0.1);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			ourFirstGraphic.move(0.1, 0);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			if (ourFirstGraphic.getFillColor() == sf::Color::Red)
			{
				ourFirstGraphic.setFillColor(sf::Color::Green);
			}
			else if (ourFirstGraphic.getFillColor() == sf::Color::Green)
			{
				ourFirstGraphic.setFillColor(sf::Color::Red);
			}
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			ourFirstGraphic.setPosition(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y);
		}

		window.clear();
		window.draw(ourFirstGraphic);
		window.display();
	}
	return 0;
}
