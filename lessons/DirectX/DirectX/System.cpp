#include "System.h"



System::System()
{
}

System::System(const System& copy)
{
}


System::~System()
{
}

bool System::init()
{
	WNDCLASSEX windowClass;
	// DEVMODE devModeSettings;
	int positionX, positionY;
	applicationName = "My App";
	windowClass.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	windowClass.lpfnWndProc = windowProc;
	windowClass.cbClsExtra = 0;
	windowClass.cbWndExtra = 0;
	windowClass.hInstance = hInstance;
	windowClass.hIcon = LoadIcon(NULL, IDI_WINLOGO);
	windowClass.hIconSm = windowClass.hIcon;
	windowClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	windowClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	windowClass.lpszMenuName = NULL;
	windowClass.lpszClassName = applicationName;
	windowClass.cbSize = sizeof(WNDCLASSEX);

	RegisterClassEx(&windowClass);
	int screenWidth = GetSystemMetrics(SM_CXSCREEN);
	int screenHeight = GetSystemMetrics(SM_CYSCREEN);

	if (FULL_SCREEN)
	{

	}
	else
	{
		screenHeight = 800;
		screenWidth = 600;

		positionX = GetSystemMetrics(SM_CXSCREEN) - screenWidth / 2;
		positionY = GetSystemMetrics(SM_CYSCREEN) - screenHeight / 2;
	}
	hWindow = CreateWindowEx(WS_EX_APPWINDOW, applicationName, applicationName,
		WS_CLIPCHILDREN | WS_CLIPSIBLINGS | WS_POPUP,
		positionX, positionY, screenWidth, screenHeight, NULL, NULL, hInstance, NULL);

	ShowWindow(hWindow, SW_SHOW);
	SetForegroundWindow(hWindow);
	SetFocus(hWindow);

	ShowCursor(false);

	return true;
}

void System::shutDown()
{
	ShowCursor(true);
	if(FULL_SCREEN)
	{ }
	DestroyWindow(hWindow);
	// hWindow = NULL;
	UnregisterClass(applicationName, hInstance);
}

void System::run()
{
	MSG message;
	bool done = false;
	bool result = false;

	ZeroMemory(&message, sizeof(MSG));

	while (!done)
	{
		if (PeekMessage(&message, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&message);
			DispatchMessage(&message);
		}

		if (message.message == WM_QUIT)
		{
			done = true;
		}
		else
		{
			result = frame();
			if (!result)
			{
				done = true;
			}
		}
	}
	return;
}

LRESULT CALLBACK System::messageHandler(HWND window, UINT msg, WPARAM wparam, LPARAM lparam)
{
	switch (msg)
	{
	case WM_KEYDOWN:
	{
		input->keyDown(wparam);
		return 0;
	}
	case WM_KEYUP:
	{
		input->keyUp(wparam);
		return 0;
	}
	default:
		return DefWindowProc(window, msg, wparam, lparam);
		break;
	}
}

bool System::frame()
{
	return false;
}

void System::initWindow(int & width, int & height)
{
}

LRESULT CALLBACK windowProc(HWND window, UINT msg, WPARAM wparam, LPARAM lparam)
{
	switch (msg)
	{
	case WM_DESTROY: 
	{
		PostQuitMessage(0);
		return 0;
	}
	case WM_CLOSE:
	{
		PostQuitMessage(0);
		return 0;
	}
	default:
		return applicationHandle->messageHandler(window, msg, wparam, lparam);
	}
}
