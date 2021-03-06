#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct book
{
	// struct members
	string naslov;
	string pisac;
	int izdanje;
	int cijena;

	// constructor
	book() {}                                  // default
	book(string naslov, string pisac, int izdanje, int cijena) :
		naslov(naslov), pisac(pisac), izdanje(izdanje), cijena(cijena)
	{}
} myFirstBook;

vector<int> myVec = {};

struct fruit
{
	int cijena;
	string name;
	string origin;
};

struct position
{
	int axisX;
	int axisY;
	int axisZ;
	position(int X, int Y, int Z) : axisX(X), axisY(Y), axisZ(Z) {}
	position operator +(position const &a)
	{
		axisX = axisX + a.axisX;
		axisY = axisX + a.axisY;
		axisZ = axisZ + a.axisZ;
		return *this;
	}

	position operator =(position const &a)
	{
		axisX = a.axisX;
		axisY = a.axisY;
		axisZ = a.axisZ;
		return *this;
	}

};

int main()
{
	book myFirstBook("Harry Potter", "J.K. Rowling", 1, 30);

	//myFirstBook.cijena = 30;
	//myFirstBook.izdanje = 1;
	//myFirstBook.naslov = "Harry Potter";
	//myFirstBook.pisac = "J.K. Rowling";

	cout << "Pisac: " << myFirstBook.pisac << endl;
	cout << "Naslov: " << myFirstBook.naslov << endl;
	cout << "Izdanje: " << myFirstBook.izdanje << endl;
	cout << "Cijena: " << myFirstBook.cijena << endl;

	fruit banana;
	banana.cijena = 100;
	banana.name = "Chiquita Banana";
	banana.origin = "Madagaskar";

	cout << "Name of our fruit: " << banana.name << endl;
	cout << "Price per kiloram: " << banana.cijena << endl;
	cout << "Origin of fruit: " << banana.origin << endl;

	position firstPos(1, 2, 3);
	position secondPos(4, 5, 6);
	firstPos = firstPos + secondPos;

	cout << firstPos.axisX << endl;
	cout << firstPos.axisY << endl;
	cout << firstPos.axisZ << endl;

	system("pause");
	return 0;
}
