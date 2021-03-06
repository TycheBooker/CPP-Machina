#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void outputSortedNumberArray(vector<int> givenVector)
{
	sort(givenVector.begin(), givenVector.end());
	for (int i = 0; i < givenVector.size(); i++)
	{
		cout << givenVector[i] << endl;
	}
}

void outputSortedStringArray(vector<string> givenVector)
{
	sort(givenVector.begin(), givenVector.end());
	for (int i = 0; i < givenVector.size(); i++)
	{
		cout << givenVector[i] << endl;
	}
}


int main()
{
	int arrayLength;
	string sortingType;
	vector<int> ourNumberVector;
	vector<string> ourNameVector;
	cout << "Would you like to sort names of numbers?" << endl;
	cin >> sortingType;
	while (sortingType != "names" && sortingType != "numbers")
	{
		cout << "Please enter either 'names' or 'numbers'!" << endl;
		cin >> sortingType;
	}
	cout << "How many items would you like to enter? (Maximum 10)" << endl;
	cin >> arrayLength;
	while (arrayLength > 10 || arrayLength < 0)
	{
		cout << "Please enter a number between 1 and 10!" << endl;
		cin >> arrayLength;
	}
	if (sortingType == "numbers")
	{
		cout << "Please enter your numbers: " << endl;
		for (int i = 0; i < arrayLength; i++)
		{
			int temporary;
			cin >> temporary;
			ourNumberVector.push_back(temporary);
		}
		cout << "These are your numbers in order from smallest to largest: " << endl;
		outputSortedNumberArray(ourNumberVector);
	}
	else if (sortingType == "names")
	{
		cout << "Please enter your names: " << endl;
		for (int i = 0; i < arrayLength; i++)
		{
			string temporary;
			cin >> temporary;
			ourNameVector.push_back(temporary);
		}
		cout << "These are your names in alphabetical order: " << endl;
		outputSortedStringArray(ourNameVector);
	}
	system("pause");
	return 0;
}

