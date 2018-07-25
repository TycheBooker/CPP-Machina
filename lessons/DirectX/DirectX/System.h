#pragma once
#include <Windows.h>
#include "GraphicsClass.h"
#include "InputClass.h"

class System
{
public:
	System();
	System(const System&);
	~System();

	bool init();
	void shutDown();     // neki win threadovi ne pozivaju sami destructore

	void run();          // zbog multithreadinga

	LRESULT CALLBACK messageHandler(HWND window, UINT msg, WPARAM wparam, LPARAM lparam);
private:
	bool frame();
	void initWindow(int& width, int& height);

	LPCSTR applicationName;
	HINSTANCE hInstance;
	HWND hWindow;

	InputClass* input;
	GraphicsClass* graphics;
};

static LRESULT CALLBACK windowProc(HWND window, UINT msg, WPARAM wparam, LPARAM lparam);
static System* applicationHandle = 0;			// static pointer na samu klasu - za sluèaj da se klasa ne instancira

