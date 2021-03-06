// 1. Napraviti program sa slijedećim funkcijama:
// funkcija za zbrajanje 2 broja
// funkcija za oduzimanje 2 broja
// funkcija za množenje 2 broja
// funkcija za dijeljenje 2 broja
// funkcija za potenciranje broja

// 2. Napraviti program koji će primiti 2 polja/vectora, recimo polje 2 studenta, Mario i Nikolina.
// Polja moraju sadržavati brojeve, tj ocjene Marija i Nikoline od 1 - 5, 5 ocjena.
// Korisnik mora unijeti te ocjene.
// Napraviti funkciju koja će uspoređivati ocjene Marija i Nikoline i dodavati bodove zasebno od područja
// u kojem tko ima bolje ocjene, te ispisati te bodove. 1 bod po usporedbi.

// 3. Napraviti funkciju koja će primiti integer tip i ispuniti sve preostale bitove koji su prazni

// 4. Napraviti funkciju koja će primiti integer tip i ispisati njegov komplement

// 5. Napraviti funkciju koja će promiti integer tip i napraviti stepenice od njega
// input: 5
// output:
/*
#
##
###
####
#####
*/

// 6. Napraviti vector brojeva, dinamičan broj polja, users choice
// Napraviti funkciju koja će zbrojiti sve brojeve bez korištenja for, dowhile i while petlje

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int add(int num1, int num2)
{
	return num1 + num2;
}

int subtract(int num1, int num2)
{
	return num2 - num2;
}

int multiply(int num1, int num2)
{
	return num1 * num2;
}

float divide(int num1, int num2)
{
	if (num2 == 0)
	{
		return 0;
	}
	else
	{
		return num1 / num2;
	}
}

int exponent(int num1, int num2)
{
	if (num2 == 1)
	{
		return 1;
	}
	else
	{
		int exp = num1;
		for (size_t i = 1; i < num2; i++)
		{
			exp *= num1;
		}
		return exp;
	}
}

/////////////////////////////////////////////////////

vector<int> MarioGrades;
vector<int> NikolinaGrades;
int MarioPoints = 0;
int NikolinaPoints = 0;
int checkInputIncrement(int min, int max)
{
	int temp;
	cin >> temp;
	if (temp >= min && temp <= max)
	{
		return temp;
	}
	else
	{
		cout << "Please enter a number between 1 and 5." << endl;
		checkInputIncrement(min, max);
	}
}

void inputGrades()
{
	cout << "Please enter Mario's grades. Enter 5 numbers from 1 to 5." << endl;
	for (size_t i = 0; i < 5; i++)
	{
		MarioGrades.push_back(checkInputIncrement(1, 5));
	}
	cout << "Please enter Nikolina's grades. Enter 5 numbers from 1 to 5." << endl;
	for (size_t i = 0; i < 5; i++)
	{
		NikolinaGrades.push_back(checkInputIncrement(1, 5));
	}
}

void compareGrades()
{
	for (size_t i = 0; i < 5; i++)
	{
		if (MarioGrades[i] > NikolinaGrades[i])
		{
			MarioPoints++;
		}
		else if (NikolinaGrades[i] > MarioGrades[i])
		{
			NikolinaPoints++;
		}
	}
}

void outputResult()
{
	cout << "Mario scored " << MarioPoints << " points." << endl;
	cout << "Nikolina scored " << NikolinaPoints << " points." << endl;
}

///////////////////////////////////////////////////////////

void maxBitwise(int num)
{
	int result = num | 1111111111111111;
	cout << result << endl;
}

void complement(int num)
{
	int result = ~num
		;
	cout << result << endl;
}

////////////////////////////////////////////////////////

void drawLadders(int num)
{
	for (size_t i = 0; i < num; i++)
	{
		string row = "#";
		for (size_t j = 0; j < i; j++)
		{
			row += "#";
		}
		cout << row << endl;
	}
}

/////////////////////////////////////////////////////
vector<int> getVectorInput()
{
	int vectorLength;
	vector<int> tempVector;
	int tempInt;
	cout << "How many numbers would you like to add?" << endl;
	cin >> vectorLength;
	cout << "Please enter your " << vectorLength << " numbers!" << endl;
	for (size_t i = 0; i < vectorLength; i++)
	{
		cin >> tempInt;
		tempVector.push_back(tempInt);
	}
	return tempVector;
}

int result = 0;
int addVectorNumbers(vector<int> myVector, int it)
{
	if (it < myVector.size())
	{
		result += myVector[it];
		addVectorNumbers(myVector, it + 1);
	}
	else
	{
		return result;
	}
}


int main()
{
	addVectorNumbers(getVectorInput(), 0);
	cout << result << endl;
	system("pause");
	return 0;
}
