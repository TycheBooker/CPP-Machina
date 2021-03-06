#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

/*
Operatori:
+, -, /, *, =
Logički opertori:
&&, ||, !, ==, <, >, <=, >=
Bitwise operatori:
&, |, ~, ^

0000000000000101
&
0000000000010100
=
0000000000000100

/////////////////////

0000000000000101
|
0000000000010100
=
0000000000010101

/////////////////////

~
0000000000000101
=
1111111111111010

/////////////////////

0000000000000101
^
0000000000010100
=
0000000000010001

*/

char character;				// 1 byte memorije
int number;					// 2 byte memorije; 16 bit 1111111111111111 2^16 -1
long int extendedIntNumber;	// 4 byte memorije;
float floatingPointNumber;	// 4 byte memorije
bool trueOrFalse;

int main()
{
	character = 0b10011111;
	int result = 10 + 10;
	int diff = 15 - 10;
	bool first = true;
	bool second = false;

	if (result && diff)
	{
		cout << "Both have values" << endl;
	}

	if (first || second)
	{
		cout << "I'm running" << endl;
	}

	if (!second)
	{
		cout << "I'm running" << endl;
	}

	if (result == diff)
	{
		cout << "I'm running" << endl;
	}

	if (result != diff)
	{
		cout << "I'm running" << endl;
	}

	if (result <= diff)
	{
		cout << "I'm running" << endl;
	}

	if (result >= diff)
	{
		cout << "I'm running" << endl;
	}

	if (result < diff)
	{
		cout << "I'm running" << endl;
	}

	if (result > diff)
	{
		cout << "I'm running" << endl;
	}

	// Bitwise

	if (first)
	{
		cout << ~diff << endl;
	}

	system("pause");
	return 0;
}
