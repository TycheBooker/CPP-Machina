#include "stdafx.h"
#include <iostream>
#include <string>
#include <map>

using namespace std;


class Student
{
public:
	string firstName;
	string lastName;
	int semester;
	string getJMBAG() { return JMBAG; }
	void setJMBAG(string jmbag) { JMBAG = jmbag; }
	pair<string, string> makePair()
	{
		pair <string, string> student;
		student.first = getJMBAG();
		student.second = lastName;
		return student;
	}
	Student(string firstName, string lastName, int semester, string JMBAG) : 
		firstName(firstName), lastName(lastName), semester(semester), JMBAG(JMBAG) {}

private:
	string JMBAG;
};



int main()
{
	Student Tihana("Tihana", "Bihler", 5, "123456789");
	map<string, string> students;
	students.insert(Tihana.makePair());

	for (auto it : students)
	{
		cout << it.first << " : " << it.second << endl;
	}

	system("pause");
    return 0;
}

