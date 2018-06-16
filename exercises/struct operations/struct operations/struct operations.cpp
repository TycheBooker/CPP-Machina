// Napraviti funkcije koje će zbrojiti, oduzeti, pomnožiti i podijeliti 2 broja koristeći strukturu podataka, i ispisati rezulatat

#include "stdafx.h"
#include <iostream>

using namespace std;

struct dummyData
{
	int first;
	int second;
};

struct dummyData userStructInput()
{
	int userInput;
	struct dummyData myStruct;
	cout << "Please enter two numbers: " << endl;
	cin >> userInput;
	myStruct.first = userInput;
	cin >> userInput;
	myStruct.second = userInput;
	return myStruct;
}

void addStructData(struct dummyData myStruct)
{
	int result;
	result = myStruct.first + myStruct.second;
	cout << result << endl;
}

void subtractStructData(struct dummyData myStruct)
{
	int result;
	result = myStruct.first - myStruct.second;
	cout << result << endl;
}

void multiplyStructData(struct dummyData myStruct)
{
	int result;
	result = myStruct.first * myStruct.second;
	cout << result << endl;
}

void divideStructData(struct dummyData myStruct)
{
	float result = 0;
	if (myStruct.second != 0)
	{
		result = myStruct.first + myStruct.second;
	}
	cout << result << endl;
}

int main()
{
	addStructData(userStructInput());
	system("pause");
	return 0;
}
