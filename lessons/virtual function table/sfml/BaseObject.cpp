#include "stdafx.h"
#include "BaseObject.h"


BaseObject::BaseObject()
{
	this->registerObject();
}

BaseObject::~BaseObject()
{
}

unsigned int BaseObject::id = 0;
std::map<int, BaseObject*> BaseObject::objects;

void BaseObject::registerObject()
{
	this->objectId = BaseObject::id;
	BaseObject::id++;
	BaseObject::objects.insert(std::pair<int, BaseObject*>(this->objectId, this));
}

std::map<int, BaseObject*> BaseObject::getObjects()
{
	return BaseObject::objects;
}

//void BaseObject::update()									// uklonjena default definicija update() funkcije
//{															// sada svaka izvedena klasa MORA imati svoju implementaciju updatea
//	std::cout << "Base update" << std::endl;				// pure virtual function funkcija nema vlastitu definiciju
//}
