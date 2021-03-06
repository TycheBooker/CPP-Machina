#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// napravi funkciju koja prima 1 broj, 1 polje. Prvi jednoznamenkasti, drugi proizvoljno.
// funkcija mora vratiti sve brojeve u kojima se pojvljuje prvi, jednoznamenkasni broj.
// Primjer: broj 5, polje {}

int numberOne = 5;
int numberTwo;
vector<int> inputVector = { 5, 10, 15, 23, 46, 57 };
vector<int> resultVector;
vector<int> ourVector;


vector<int> arrayIncludesNumber(int number, vector<int> ourVector)
{
	vector<int> result;
	for (int i = 0; i < ourVector.size(); i++)
	{
		int VectorItem = ourVector[i];
		while (VectorItem > 0) {
			if (VectorItem % 10 == number)
			{
				result.push_back(ourVector[i]);
			}
			VectorItem /= 10;
		}
	}
	return result;
}

int main()
{
	resultVector = arrayIncludesNumber(numberOne, inputVector);
	for (int i = 0; i < resultVector.size(); i++)
	{
		cout << resultVector[i] << endl;
	}
	system("pause");
	return 0;
}


vector<int> taskFirstFunction(int num, vector<int> checkingNumbers)
{
	vector<int> result;
	for (size_t i = 0; i < checkingNumbers.size(); i++)
	{
		int currentNumber = checkingNumbers[i];
		do
		{
			if ((currentNumber % 10) == num)
			{
				result.push_back(currentNumber);
				break;
			}
			currentNumber /= 10;
		} while (true);
	}
	return result;
}

/*
int main()
{
bool firstTry = false;
int vectorSize;
do
{
if (firstTry)
{
cout << "You have entered a number greater of equal to 10: " << endl;
}
cout << "Enter first number: " << endl;
cin >> numberOne;
firstTry = true;
} while (numberOne / 10 >= 1);
cout << "Finally, what took you so long?" << endl;
cout << "How many numbers are you going to enter?" << endl;
cin >> vectorSize;
for (size_t i = 0; i < vectorSize; i++)
{
int temporary;
cin >> temporary;
ourVector.push_back(temporary);
}
resultVector = taskFirstFunction(numberOne, ourVector);

system("pause");
return 0;
*/