// ConsoleApplication28.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

vector<int> myVector = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
map<string, int> students;        // "array" pairova
pair<string, int> student;        // tip podatka kojeg mapa sprema

int main()
{
	student.first = "Renato";
	student.second = 1254;
	students.insert(student);

	student.first = "Tyche";
	student.second = 1345;
	students.insert(student);

	student.first = "Deni";
	student.second = 1524;
	students.insert(student);

	student.first = "Igor";
	student.second = 3145;
	students.insert(student);

	/*
	map<string, int>::iterator it = students.begin();     // iterator koji
	//postavljamo na prvu poziciju mape (pointer)
	for (it; it != students.end(); ++it)
	{
	pair<string, int> currentStudent = *it;
	cout << currentStudent.first << " : " << currentStudent.second << endl;

	}
	int id = students[("Tyche")];
	cout << id << endl;
	*/

	for (auto it : students)     // keyword auto sam nalazi najprikladniji iterator (forEach)
	{
		cout << it.first << " : " << it.second << endl;
	}

	students.insert(make_pair("Marijan", 12487));  // automatsko deklariranje pair-a
	system("pause");
	return 0;
}

