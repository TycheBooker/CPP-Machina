// #pragma once						// zamjena za ifndef

#ifndef PLAYER
#define PLAYER

#include "BaseObject.h"

class Player : public BaseObject
{
public:
	Player();
	~Player();

	void update() override;
};

#endif