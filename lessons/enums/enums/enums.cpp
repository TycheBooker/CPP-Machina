#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;
enum suit
{
	hearts,
	spades,
	clubs,
	diamonds,
	//hearts = 0,
	//spades = 1,
	//clubs = 2,
	//diamonds = 3,
};

int main()
{
	int currentSuit = suit::clubs;
	cout << currentSuit << endl;        // prints 2
	system("pause");
	return 0;
}
