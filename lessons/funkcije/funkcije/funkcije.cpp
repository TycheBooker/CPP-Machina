#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int sumTwoNumbers(int first, int second)        // automatski castanje u int (ako je moguće)
{
	return (int)(first + second);				// casting
}

float myFirstFloatFunction()
{
	return 2.0;
}

string myWordFunction()
{
	return "Hello World!";
}

char myCharacterFunction(int numb)
{
	return (char)numb;
}

void functionWithoutReturnValue()
{
	// some code
}

int main()
{
	char character = 'a';								// jednostruki navodnici - char
	string word = "Hello World";						// dvostruki navodnici - string
	character = word[5];
	int operand = 10;
	int result = sumTwoNumbers(operand, operand);

	cout << "Sum of two operands is: " << result << endl;
	cout << myWordFunction() << endl;

	system("pause");
	return 0;
}
