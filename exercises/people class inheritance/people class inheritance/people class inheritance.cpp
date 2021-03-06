#include "stdafx.h"
#include <string>
#include <vector>
#include <ctype.h>

using namespace std;

struct birthDate
{
	birthDate() {};
	birthDate(int day, int month, int year) : day(day), month(month), year(year) {}
	void setBirthDate(int day, int month, int year)
	{
		day = day;
		month = month;
		year = year;
	}
	int day;
	int month;
	int year;
};

class Person
{
	Person(string firstName, string lastName, int day, int month, int year, string taxId,
		string OIB, bool isMedicallyInsured) : firstName(firstName), lastName(lastName)
	{}
public:
	void setPerson(string firstName, string lastName, int day, int month, int year,
		string taxId, string OIB, bool isMedicallyInsured)
	{
		firstName = firstName;
		lastName = lastName;
		birthDate.setBirthDate(day, month, year);
		taxId = taxId;
		if (isOIBValid(OIB))
		{

		}
		isMedicallyInsured = isMedicallyInsured;
	}
	bool isOIBValid(string OIB)
	{
		if (OIB.size() != 11)
		{
			return false;
		}
		for (size_t i = 0; i < OIB.size(); i++)
		{
			if (!isdigit(OIB[i]))
			{
				return false;
			}
		}
		return true;
	}
	string firstName;
	string lastName;
	birthDate birthDate;
private:
	string taxId;
protected:
	string OIB;
	bool isMedicallyInsured;
};

class Student : public Person
{
public:
	string faculty;
	string major;
	int semester;
	void addGrade(int grade);
	void undoLastGrade();
	int getGradesMedian();
	bool getStudentRights();
	void setStudentRights(bool studentRightsStatus);
private:
	int JMBAG;
	vector<int> grades;
	bool hasStudentRights;
	bool getMedicallyInsured() { return isMedicallyInsured; }
	void setMedicalInsurence();
};

void Student::addGrade(int grade)
{
	this->grades.push_back(grade);
}
void Student::undoLastGrade()
{
	this->grades.pop_back();
}
int Student::getGradesMedian()
{
	int acc = 0;
	for (size_t i = 0; i < this->grades.size(); i++)
	{
		acc += this->grades[i];
	}
	return acc / this->grades.size();
}
bool Student::getStudentRights()
{
	return this->hasStudentRights;
}
void Student::setStudentRights(bool studentRightsStatus)
{
	this->hasStudentRights = studentRightsStatus;
	this->setMedicalInsurence();
}
void Student::setMedicalInsurence()
{
	this->isMedicallyInsured = this->hasStudentRights;
}

int main()
{
	system("pause");
	return 0;
}
