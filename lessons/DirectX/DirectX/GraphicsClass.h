#pragma once
#include <Windows.h>

const bool FULL_SCREEN = false;
const bool VSYNC = false;
const float SCREEN_DEPTH = 1000.0f;
const float SCREEN_NEAR = 0.1f;

class GraphicsClass
{
public:
	GraphicsClass();
	GraphicsClass(const GraphicsClass&);
	~GraphicsClass();

	bool init(int width, int height, HWND window);
	void shutDown();
	bool frame();
private:
	bool render();
};

