#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

int number, number2, number3;
int result;
char character;
float decimalNumber;
bool isTrueOrFalse;
// std::string word;
string word;
int arrayOfNumbers[5];

int main()
{
	number = 2;
	number2 = 5;
	arrayOfNumbers[0] = 1;
	arrayOfNumbers[1] = 2;
	arrayOfNumbers[2] = 3;
	arrayOfNumbers[3] = 4;
	arrayOfNumbers[4] = 5;
	word = "Hello World!";
	result = number + number2;
	result = number2 - number;

	if (number < number2)
	{
		word = "number is bigger than number2";
	}
	else
	{
		word = "number is not bigger than number2";
	}

	while (number < number2)
	{
		cout << word << endl;
		// number = number + 1;
		// number ++;
		++number;
	}

	for (int i = 0; i < 5; i++)
	{
		cout << arrayOfNumbers[i] << endl;
	}
	// do
	// {
	// } while (true);
	// cout << word << endl;
	cout << result;
	cout << "\n";
	system("pause");
	return 0;
}