#pragma once
#include <SFML/Graphics.hpp>

class Animation
{
public:
	Animation(sf::RectangleShape* gameObject, sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
	~Animation();

	void update(float deltaTime);

	sf::RectangleShape* gameObject;
	sf::Texture* texture;
	sf::IntRect textureRect;
private:
	sf::Vector2u textureSize;
	sf::Vector2u imageCount;
	sf::Vector2u currentImage;

	float elapsedTime;
	float switchTime;
};

