#include "stdafx.h"

// template ne generira funkcije i typeove pri compile time-u (yay JS xD)
// compile on demand - compileira se samo što se koristi u programu

//template<typename T>		// bilo kakav tip

template<typename T, int N>

class Array
{
public:
	T memberArray[N];
};

//typedef		// definicija vlastitog tipa podatka
// size_t iz VS-ovog for loopa
typedef unsigned int ui;

int main()
{
	int arraySize = 5;
	int length;
	for (ui i = 0; i < length; i++)
	{

	}
    return 0;
}

