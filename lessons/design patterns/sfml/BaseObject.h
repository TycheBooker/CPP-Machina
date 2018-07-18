// #pragma once						// zamjena za ifndef

#ifndef BASE_OBJECT
#define BASE_OBJECT

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class BaseObject
{
public:
	BaseObject();
	~BaseObject();

	virtual void update() = 0;				// deklaracija pure virtual funkcije
	void registerObject();
	std::map<int, BaseObject*> getObjects();
private:
	static unsigned int id;					// base id od kojeg se kasnije inkrementiranjem rade pojedinaèni id-evi (failsafe od 2 ista id-a)
	static std::map<int, BaseObject*> objects;				// mapa instanciranih èlanova - static da svi shareaju isti podatak, mapa id-eva i pointera
	unsigned int objectId;
};

#endif
