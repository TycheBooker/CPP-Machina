#pragma once
#include <string>
#include "BaseObject.h"
#include "Player.h"
#include "Enemy.h"


class GameState
{
public:
	static GameState *getSingleton();

	enum GameObject { player, enemy };
	void createGameObject(GameObject objectType);
	void updateObjectsInGame();
private:
	static GameState *instance;
	std::map<int, BaseObject*> objectsInGame;
	void createPlayer();
	void createEnemy();

	GameState();
	~GameState();

};

