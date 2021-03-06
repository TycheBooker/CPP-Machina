#include "stdafx.h"
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "GameState.h"
#include "BaseObject.h"
#include "Player.h"
#include "Enemy.h"

#include "Singleton.h"

int main()
{
	Singleton::getSingleton()->update();

	GameState::getSingleton()->createGameObject(GameState::GameObject::player);
	GameState::getSingleton()->createGameObject(GameState::GameObject::enemy);

	GameState::getSingleton()->updateObjectsInGame();

	system("pause");
	return 0;
}