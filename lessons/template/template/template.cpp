// template.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

// generički tipovi (JS xD)
template <typename T> T sum(T a, T b)
{
	return a + b;
}


// function override
//int sum(int a, int b)
//{
//	return a + b;
//}
//
//float sum(float a, float b)
//{
//	return a + b;
//}

// više korištenih tipova
// reference na proslijeđene argumente - direktno ih mijenja
template <typename T, typename U> void someFunction(T *a, U *b)
{
	++*a;
	++*b;
}

// template klase
template <typename T> T Point<T>::getPoint() {return point}

template <typename T> T subtract(T a, T b)
{
	return a - b;
}

template <typename T> T multiply (T a, T b)
{
	return a * b;
}

template <typename T> T divide(T a, T b)
{
	if (b == 0)
	{
		return 0;
	}
	else
	{
		return a / b;
	}
}

int main()
{
	int a = 5;
	int b = 10;
	float c = 2.5;
	float d = 1.8;

	cout << sum(a, b) << endl;
	cout << sum(c, d) << endl;

	someFunction(&a, &c);
	system("pause");
    return 0;
}

