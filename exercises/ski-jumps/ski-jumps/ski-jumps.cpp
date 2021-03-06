// Napraviti program koji će omogućiti računanje bodova skijaških skokova. 5 sudaca dijeli po jednu ocjenu od 1-20
// Najniža i najviša ocjena se odbijaju, od ostalih se računa prosjek.
// Samo se jedanput izbijaju najviša i najniža ocjena

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

vector<int> scores = { 10, 5, 19, 13, 7 };
bool compareBigger(int firstNumber, int secondNumber)
{
	if (firstNumber > secondNumber)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool compareSmaller(int firstNumber, int secondNumber)
{
	if (firstNumber < secondNumber)
	{
		return true;
	}
	else
	{
		return false;
	}
}

float getFinalScore(vector<int> scores)
{
	for (size_t i = 0; i < scores.size(); i++)
	{
		int j = 1;
		while (compareBigger(scores[i], scores[j]))
		{
			if (j = scores.size())
			{
				scores.erase(scores.begin() + i);
				break;
			}
			compareBigger(scores[i], scores[j]);
		}
		while (compareSmaller(scores[i], scores[j]))
		{
			if (j = scores.size())
			{
				scores.erase(scores.begin() + i);
				break;
			}
			compareSmaller(scores[i], scores[j]);
		}
	}

	float sumOfScores = 0;
	for (size_t k = 0; k < scores.size(); k++)
	{
		sumOfScores += scores[k];
	}

	return sumOfScores / scores.size();
}

vector<int> bubbleSortFunction(vector<int> numbers)
{
	vector<int> result;
	result.push_back(numbers[0]);
	for (size_t i = 0; i < numbers.size(); i++)
	{
		for (size_t j = 0; j < result.size(); j++)
		{
			vector<int>::iterator it = result.begin();
			if (numbers[i] <= result[j])
			{
				result.insert(it + j, numbers[i]);
				break;
			}
			else if (j == result.size() - 1)
			{
				result.push_back(numbers[i]);
				break;
			}
		}
	}
	return result;
}


vector<int> grades = { 20, 5, 10, 12, 15 };
float solutionOne(vector<int> judgesGrades)
{
	vector<int> result = bubbleSortFunction(judgesGrades);
	float average = 0;
	result.erase(result.end() - 1);
	result.erase(result.begin());
	for (size_t i = 0; i < result.size(); i++)
	{
		average += result[i];
	}
	return average / result.size();
}

int main()
{
	/*
	int result = getFinalScore(scores);
	cout << result << endl;
	*/

	int resultGrades = solutionOne(grades);
	cout << resultGrades << endl;

	system("pause");
	return 0;
}
