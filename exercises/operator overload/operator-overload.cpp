// #include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct position
{
	int axisX;
	int axisY;
	int axisZ;
	position(int X, int Y, int Z) : axisX(X), axisY(Y), axisZ(Z) {}
	position operator+(position const &a)
	{
		axisX = axisX + a.axisX;
		axisY = axisY + a.axisY;
		axisZ = axisZ + a.axisZ;
		return *this;
	}

	bool operator<(position const &a)
	{
		if (axisX < a.axisX && axisY < a.axisY && axisZ < a.axisZ)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator<=(position const &a)
	{
		if (axisX <= a.axisX && axisY <= a.axisY && axisZ <= a.axisZ)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator>(position const &a)
	{
		if (axisX > a.axisX && axisY > a.axisY && axisZ > a.axisZ)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator>=(position const &a)
	{
		if (axisX >= a.axisX && axisY >= a.axisY && axisZ >= a.axisZ)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator==(position const &a)
	{
		if (axisX == a.axisX && axisY == a.axisY && axisZ == a.axisZ)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator!=(position const &a)
	{
		if (axisX != a.axisX && axisY != a.axisY && axisZ != a.axisZ)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

int main()
{
	position firstPos(1, 2, 3);
	position secondPos(4, 5, 6);
	firstPos = firstPos + secondPos;

	cout << firstPos.axisX << endl;
	cout << firstPos.axisY << endl;
	cout << firstPos.axisZ << endl;

	// system("pause");
	return 0;
}