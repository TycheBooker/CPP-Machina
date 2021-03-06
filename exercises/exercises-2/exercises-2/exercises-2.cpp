/*
1. Napisati program koji prima string od 8 znakova za datum rodenj npr "20.02.93" i ispisuje slijedece :

Dan rodenja : 20
Mjesec rodenja : 02
Godina rodenja : 93

2. Napisati program za hrvatsku lutriju.Korisnik radi unos od 7 brojeva u rasponu od 1 - 49, nakon toga program radi "izvlacenje" tj.radnom generira 7 brojeva od 1 - 49, te ispisuje korisnikov unos, zatim izvucene brojeve te na kraju koliko pogodataka korisnik ima.

3. Napisati program koji ce dati korisniku da unese jedan broj i ispisati 30 brojeva Fibonacijevog niza, pocevsi od broja koji je korisnik unio.

4. Napisati program koji ce primiti unos texta i ispisati isti unazad.

5. Napisati program koji prima unos 3 broja koji ce simulirati kuteve.Ispisati korisniku jel moguce da se napravi trokut od tih kuteva.

6. Napisati program koji prima text i character od strane korisnika, te ispisuje taj text bez tog charactera.

7. Napisati program koji će primiti vector brojeva, i ispisati korisniku koji brojevi su parni, a koji neparni

*/

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;
//////////////////////////////   1

string getBirthDate()
{
	string userInput;
	cout << "Please enter your birth date in the following format: DD.MM.YY :" << endl;
	cin >> userInput;
	return userInput;
}

vector<string> parseBirthDateInput(string birthDate)
{
	istringstream stringStream(birthDate);
	vector<string> parsedDate;
	string datePart;
	while (getline(stringStream, datePart, '.')) {
		if (!datePart.empty())
			parsedDate.push_back(datePart);
	}
	return parsedDate;
}

void outputParsedBirthDate(vector<string> parsedBirthDate)
{
	cout << "Dan rodenja : " << parsedBirthDate[0] << endl;
	cout << "Mjesec rodenja : " << parsedBirthDate[1] << endl;
	cout << "Godina rodenja : " << parsedBirthDate[2] << endl;
}

// 	outputParsedBirthDate(parseBirthDateInput(getBirthDate()));

/////////////////////////////////  2

vector<int> getUserInput(int vectorLength, int min, int max)
{
	int temp;
	vector<int> userInput;
	cout << "Please enter " << vectorLength << " numbers, between " << min << " and " << max << " ." << endl;
	for (size_t i = 0; i < vectorLength; i++)
	{
		cin >> temp;
		while (temp < min || temp > max)
		{
			cout << "Please enter a number between " << min << " and " << max << " ." << endl;
			cin >> temp;
		}
		userInput.push_back(temp);
	}
	return userInput;
}


vector<int> getRandomNumbers(int vectorLength, int min, int max)
{
	vector<int> randomNumbers;
	for (size_t i = 0; i < vectorLength; i++)
	{
		int randomNumber = rand() % max + min;
		randomNumbers.push_back(randomNumber);
	}
	return randomNumbers;
}

void outputNumbers(vector<int> numbers, string message)
{
	cout << message;
	for (size_t i = 0; i < numbers.size(); i++)
	{
		cout << numbers[i] << ", ";
	}
	cout << endl;
}

int compareNumberLists(vector<int> firstArray, vector<int> secondArray)
{
	int points = 0;
	if (firstArray.size() != secondArray.size())
	{
		cout << "Error! Compairing two arrays of different sizes!" << endl;
		return 0;
	}
	for (size_t i = 0; i < firstArray.size(); i++)
	{
		if (firstArray[i] == secondArray[i])
		{
			points++;
		}
	}
	return points;
}

void outputResults(vector<int> userNumbers, vector<int> randomNumbers)
{
	outputNumbers(userNumbers, "Your chosen numbers are: ");
	outputNumbers(randomNumbers, "Randomly generated numbers are: ");
	int points = compareNumberLists(userNumbers, randomNumbers);
	cout << "You have guessed " << points << " numbers!" << endl;
}

// outputResults(getUserInput(7, 1, 49), getRandomNumbers(7, 1, 49));


///////////////////////////////  3

void Fibonacci30()
{
	int first;
	cout << "Please enter a number: " << endl;
	cin >> first;

	cout << "Here is a Fibonacci-like sequence generated from your number: " << endl;
	int second = first + 1;
	int next;
	cout << first << endl;
	cout << second << endl;
	for (size_t i = 0; i < 30; i++)
	{
		next = first + second;
		first = second;
		second = next;
		cout << next << endl;
	}
	cout << endl << "If you would like to see the actual Fibonacci series, please enter 0 or 1" << endl;
}

// Fibonacci30();

////////////////////////////////  4

string userStringInput()
{
	string userInput;
	cout << "Please enter some text: " << endl;
	cin >> userInput;
	return userInput;
}

void outputReverseString(string userInput)
{

	for (int i = userInput.size()-1; i > -1; i--)
	{
		cout << userInput[i];
	}
	cout << endl;
}

// reverseString(userStringInput());

////////////////////////////////  5

vector<int> userNumberInput(int length)
{
	vector<int> userInput;
	int temp;
	cout << "Please enter " << length << " numbers: " << endl;
	for (size_t i = 0; i < length; i++)
	{
		cin >> temp;
		userInput.push_back(temp);
	}
	return userInput;
}

bool isTriangle(int first, int second, int third)
{
	if (first > 0 && second > 0 && third > 0 && first + second + third == 180)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void checkAngles()
{
	vector<int> userInput = userNumberInput(3);
	if (isTriangle(userInput[0], userInput[1], userInput[2]))
	{
		cout << "These could represent a triangle!" << endl;
	}
	else
	{
		cout << "No triangle here!" << endl;
	}
}

// checkAngles();


////////////////////////////////  6

char userCharInput()
{
	char userInput;
	cout << "Now enter a single character: " << endl;
	cin >> userInput;
	return userInput;
}

string excludeCharFromString(char character, string text)
{
	text.erase(remove(text.begin(), text.end(), character), text.end());
	cout << "Here is your text with the character excluded: " << endl;
	cout << text << endl;
	return text;
}

// excludeCharFromString(userCharInput(), userStringInput());

////////////////////////////////  7

vector<int> userVectorInput()
{
	int length;
	int temp;
	vector<int> userInput;
	cout << "How many numbers would you like to input?" << endl;
	cin >> length;
	cout << "Please enter your " << length << " numbers: " << endl;
	for (size_t i = 0; i < length; i++)
	{
		cin >> temp;
		userInput.push_back(temp);
	}
	return userInput;
}

void outputOddEven(vector<int> numbers)
{
	vector<int> even;
	vector<int> odd;
	for (size_t i = 0; i < numbers.size(); i++)
	{
		if (numbers[i] % 2)
		{
			odd.push_back(numbers[i]);
		}
		else {
			even.push_back(numbers[i]);
		}
	}
	cout << "These numbers are even: " << endl;
	for (size_t i = 0; i < even.size(); i++)
	{
		cout << even[i] << endl;
	}
	cout << "These numbers are odd: " << endl;
	for (size_t i = 0; i < odd.size(); i++)
	{
		cout << odd[i] << endl;
	}
}

int main()
{
	outputOddEven(userVectorInput());
	system("pause");
    return 0;
}

