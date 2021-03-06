#include "stdafx.h"
#include <iostream>

using namespace std;

struct date
{
	int day;
	int month;
	int year;
	date(int D, int M, int Y) : day(D), month(M), year(Y) {}
};

class Student
{
public:
	string firstName;
	string lastName;
	int semester;
	string getJMBAG() { return JMBAG; }
	void setJMBAG(string jmbag) { JMBAG = jmbag; }
	date dateOfBirth;

	// defaultni constructor - za mogućnost stvaranja praznog objekta, u tom slučaju nužno pozivanje constructora korištenog structa
	// Student() {}
	Student(string firstName, string lastName, int semester, date dateOfBirth) : firstName(firstName), lastName(lastName), semester(semester), dateOfBirth(dateOfBirth) {}

private:
	string JMBAG;

	// protected:
};

// proslijeđivanje reference na objekt funkciji - inače funkcija napravi kopiju objekta i mi ne mijenjamo pravi objekt

void setStudentData(Student &someStudent, string firstName, string lastName, int semester, date dateOfBirth)
{
	someStudent.firstName = firstName;
	someStudent.lastName = lastName;
	someStudent.semester = semester;
	someStudent.dateOfBirth = dateOfBirth;
}

int main()
{
	system("pause");

	date myDate(12, 6, 1988);
	Student Tihana("Tihana", "Bihler", 3, myDate);
	setStudentData(Tihana, "Tihana", "Bihler", 3, myDate);
	return 0;
}