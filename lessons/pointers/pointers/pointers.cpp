#include "stdafx.h"
#include <iostream>
using namespace std;

void functionSomething(int &a)
{
	a + 1
		;
}


int main()
{
	int x = 20;
	int *something = &x;              // pointer koji pokazuje na int vrijednost
	cout << something << endl;
	cout << *something << endl;       // dereferenciranje pointera
	cout << &x << endl;
	something++;
	cout << something << endl;
	cout << *something << endl;
	cout << &x << endl;
	cout << *something << endl;
	*something++;
	cout << x << endl;
	cout << *something << endl;


	functionSomething(x);
	cout << x << endl;

	system("pause");
	return 0;
}
