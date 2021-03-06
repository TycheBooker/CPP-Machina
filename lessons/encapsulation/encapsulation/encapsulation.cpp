#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

struct EngineType
{
	int fuelType;
	string stroke;
	float volume;
	int BHP;
};

class Vehicle
{
public:
	int wheels;
	int doors;
	string color;
	float velocity;
protected:
	EngineType type;
};

class Car : public Vehicle
{
public:
	string brand;
	int price;
	int getPrice();
	void setPrice(int value);

	// vidi protected varijablu, ali za manipulaciju njima treba getter i setter, nema pristup direktno
	EngineType getEngineType() { return type; }
	void setEngineType(int fuelType, string stroke, float volume, int BHP);
};

void Car::setEngineType(int fuelType, string stroke, float volume, int BHP)
{
	type.fuelType = fuelType; // 1 = Diesel, 2 = Petrol, 3 = Electric, 0 = Kremenko
	type.stroke = stroke; // 2T = 2-taktni, 4T = taktni, 0T = bicikl
	type.volume = volume;
	type.BHP = BHP;
}

int Car::getPrice()
{
	return this->price;
}

void Car::setPrice(int value)
{
	this->price = value;
}

// enkapsulacija - grupiranje sličnih podataka na istom mjestu i extendanje


// template klase koji prima bilo koji podatak
template <typename T>
T sum(T a, T b)
{
	return a + b;
}

int main()
{
	Car igorsAutomobil;
	igorsAutomobil.setEngineType(0, "0T", 20, 1);
	igorsAutomobil.wheels = 2;
	igorsAutomobil.color = "pink";
	igorsAutomobil.brand = "Pony";
	igorsAutomobil.doors = 0;
	igorsAutomobil.velocity = 25;
	igorsAutomobil.price = 300;
	EngineType myBikeEngine = igorsAutomobil.getEngineType();
	return 0;
}