#pragma once
#include <iostream>
#include <string>

class Singleton
{
public:
	static Singleton *getSingleton();

	void update();

private:
	Singleton();
	~Singleton();

	static Singleton *instance;
};

