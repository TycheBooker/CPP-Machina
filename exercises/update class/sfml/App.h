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
};

