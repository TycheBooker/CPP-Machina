#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

sf::Mutex updateMutex;

void update()
{
	updateMutex.lock();						// zaključavanje s muteksom

	for (size_t i = 0; i < 50; i++)
	{
		std::cout << "update thread" << std::endl;
	}

	updateMutex.unlock();					// problem exception errora unutar mutex - thread ostaje zaključan i nikad se ne izvrši
}

void updateAudio()
{
	updateMutex.lock();						// zaključavanje s muteksom

	for (size_t i = 0; i < 50; i++)
	{
		std::cout << "audio thread" << std::endl;
	}

	updateMutex.unlock();					// problem exception errora unutar mutex - thread ostaje zaključan i nikad se ne izvrši
}

void functionExample()
{
	sf::Thread example(&update);			// loš primjer threada unutar scopea - thread nestaje izvan scopea, primjenjivo jedino unutar klase (npr singleton)
	example.launch();
}

void functionExample(int a, int b)
{
	int c = a + b;
}

// MUTEX
// Mutual Exclusion (async await)

int main()
{
	sf::Thread updateThread(&update);		// instanciranje novog threada, prima pointer funkcije u konstruktoru
	sf::Thread audioThread(&updateAudio);
	sf::Thread exampleThread(&functionExample, 1, 1); // proslijeđivanje pointera na funkciju koja prima parametre


	updateThread.launch();					// pokretanje novog threada
	audioThread.launch();

	updateMutex.lock();						// zaključavanje s muteksom
	
	for (size_t i = 0; i < 50; i++)
	{
		std::cout << "main thread" << std::endl;
	}

	updateMutex.unlock();					// problem exception errora unutar mutex - thread ostaje zaključan i nikad se ne izvrši


	updateThread.wait();					// gašenje threada
	audioThread.wait();
	system("pause");
	return 0;
}
