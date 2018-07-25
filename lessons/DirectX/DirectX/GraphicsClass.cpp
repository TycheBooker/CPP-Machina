#include "GraphicsClass.h"



GraphicsClass::GraphicsClass()
{
}

GraphicsClass::GraphicsClass(const GraphicsClass& copy)
{
}


GraphicsClass::~GraphicsClass()
{
}

bool GraphicsClass::init(int width, int height, HWND window)
{
	return true;
}

void GraphicsClass::shutDown()
{
}

bool GraphicsClass::frame()
{
	return false;
}

bool GraphicsClass::render()
{
	return true;
}
