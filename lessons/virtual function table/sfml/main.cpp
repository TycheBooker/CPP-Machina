#include "stdafx.h"
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "GameState.h"
#include "BaseObject.h"
#include "Player.h"
#include "Enemy.h"

int main()
{
	////BaseObject* base = new BaseObject();
	//Player* player = new Player();
	//Enemy* enemy = new Enemy();
	////base->update();
	//player->update();
	//enemy->update();

	//BaseObject* playerBase = player;
	//BaseObject* enemyBase = enemy;
	//playerBase->update();
	//enemyBase->update();

	GameState myGame;
	myGame.createGameObject(GameState::GameObject::player);
	myGame.createGameObject(GameState::GameObject::enemy);

	myGame.updateObjectsInGame();

	system("pause");
	return 0;
}