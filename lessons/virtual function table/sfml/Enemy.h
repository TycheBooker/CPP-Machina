#pragma once
#include "BaseObject.h"

class Enemy : public BaseObject
{
public:
	Enemy();
	~Enemy();

	void update() override;			// keyword override je optional, ali poma�e prilikom snala�enja da postoji superklasa i virtual metoda
};

