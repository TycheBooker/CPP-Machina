#include "stdafx.h"
#include "GameState.h"

GameState::GameState()
{
}


GameState::~GameState()
{
}

std::map<int, BaseObject*> GameState::objectsInGame;

void GameState::createGameObject(GameState::GameObject objectType)
{
	switch (objectType)
	{
	case player:
		this->createPlayer();
		break;
	case enemy:
		this->createEnemy();
		break;
	default:
		break;
	}
}

void GameState::createPlayer()
{
	BaseObject * player = new Player();
	GameState::objectsInGame = player->getObjects();
}

void GameState::createEnemy()
{
	BaseObject * enemy = new Enemy();
	GameState::objectsInGame = enemy->getObjects();
}

void GameState::updateObjectsInGame()
{
	std::map<int, BaseObject*>::iterator it = GameState::objectsInGame.begin();

	//for (auto it : this->objects)
	for (std::map<int, BaseObject*>::iterator it = GameState::objectsInGame.begin(); it != GameState::objectsInGame.end(); ++it)
	{
		it->second->update();
	}
}
