#pragma once
#include <string>
#include "BaseObject.h"
#include "Player.h"
#include "Enemy.h"


class GameState
{
public:
	GameState();
	~GameState();
	enum GameObject { player, enemy };
	void createGameObject(GameObject objectType);
	void updateObjectsInGame();
private:
	static std::map<int, BaseObject*> objectsInGame;
	void createPlayer();
	void createEnemy();
};

