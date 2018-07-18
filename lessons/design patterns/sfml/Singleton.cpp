#include "stdafx.h"
#include "Singleton.h"


Singleton::Singleton()
{
}


Singleton::~Singleton()
{
}

Singleton *Singleton::instance;

Singleton *Singleton::getSingleton()
{
	if (instance == NULL)
	{
		instance = new Singleton();
	}
	return instance;
}

void Singleton::update()
{
	std::cout << "I am Singleton!" << std::endl;
}
