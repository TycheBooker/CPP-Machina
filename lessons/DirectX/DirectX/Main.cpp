#include "System.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hprevInstance, PSTR pScmdline, int iCmdshow)
{
	System* systemObject;
	bool result;

	systemObject = new System;
	if (!systemObject)
	{
		return 0;
	}

	result = systemObject->init();
	if (result)
	{
		systemObject->run();
	}

	systemObject->shutDown();
	delete systemObject;
	return 0;
}