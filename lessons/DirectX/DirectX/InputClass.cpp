#include "InputClass.h"



InputClass::InputClass()
{
}

InputClass::InputClass(const InputClass& copy)
{
}


InputClass::~InputClass()
{
}

void InputClass::init()
{
	for (size_t i = 0; i < 256; i++)
	{
		keys[i] = false;
	}
}

void InputClass::keyDown(unsigned int input)
{
	keys[input] = true;
}

void InputClass::keyUp(unsigned int input)
{
	keys[input] = false;
}

bool InputClass::isKeyDown(unsigned int key)
{
	return keys[key];
}
