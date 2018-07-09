#include "stdafx.h"
#include "Animation.h"


Animation::Animation(sf::RectangleShape* gameObject, sf::Texture* texture, sf::Vector2u imageCount, float switchTime) :
	gameObject(gameObject), texture(texture), imageCount(imageCount), switchTime(switchTime)
{
	this->imageCount = imageCount;
	this->switchTime = switchTime;
	currentImage.x = 0;
	currentImage.y = 0;
	elapsedTime = 0;

	textureRect.width = texture->getSize().x / this->imageCount.x;
	textureRect.height = texture->getSize().y / this->imageCount.y;
}

Animation::~Animation()
{
}

void Animation::update(float deltaTime)
{
	elapsedTime += deltaTime;
	if (elapsedTime >= switchTime)
	{
		if (currentImage.x < imageCount.x - 1)
		{
			currentImage.x++;
		}
		else if (currentImage.y < imageCount.y - 1)
		{
			currentImage.y++;
			currentImage.x = 0;
		}
		else
		{
			currentImage.x = 0;
			currentImage.y = 0;
		}
		elapsedTime -= switchTime;
	}

	textureRect.left = currentImage.x * textureRect.width;
	textureRect.top = currentImage.y * textureRect.height;
	gameObject->setTextureRect(textureRect);
	gameObject->setTexture(texture);   // referenca na teksturu da ne radimo novu instancu
}
