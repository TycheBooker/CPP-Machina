#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void outputSortedArray(vector<int> givenVector)
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
	vector<int> ourVector;
	cout << "How many numbers would you like to enter? (Maximum 10)" << endl;
	cin >> arrayLength;
	while (arrayLength > 10 || arrayLength < 0)
	{
		cout << "Please enter a number between 1 and 10!" << endl;
		cin >> arrayLength;
	}
	cout << "Please enter your numbers: " << endl;
	for (int i = 0; i < arrayLength; i++)
	{
		int temporary;
		cin >> temporary;
		ourVector.push_back(temporary);
	}
	cout << "There are your numbers in order from smallest to largest: " << endl;
	outputSortedArray(ourVector);
	system("pause");
    return 0;
}

