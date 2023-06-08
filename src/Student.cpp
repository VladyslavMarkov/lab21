#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::streamsize;
using std::string;

#include "Student.h"

//--------------------------------------------------------
//----------(Student)-------------------------------------

Student::Student() : budget_edu(2), name_student("не вказано"), famile_name("не вказано"), enroll_year(0), age(0)
{
	cout << endl << "Був викликаний конструктор за замовчуванням" << endl;
}

Student::Student(unsigned int budget_edu, string name_student, string famile_name, unsigned int enroll_year, unsigned int age)
	: budget_edu(budget_edu), name_student(name_student), famile_name(famile_name), enroll_year(enroll_year), age(age)
{
	cout << endl << "Був викликаний конструктор з параметрами" << endl;
}

Student::Student(const Student &student)
	: budget_edu(student.budget_edu), name_student(student.name_student), famile_name(student.famile_name), enroll_year(student.enroll_year),
	  age(student.age)
{
	cout << endl << "Був виклакений конструктор копіювання" << endl;
}

Student::~Student()
{
	cout << endl << "Був виклакений деструктор Student" << endl;
}

//--------------------------------------------------------
//----------(budget_edu)----------------------------------

string Student::get_budget_edu() const
{
	if (budget_edu == 1)
		return "так";
	else if (budget_edu == 0)
		return "ні";
	else
		return "не вказано";
};

//--------------------------------------------------------
//----------(name_student)--------------------------------

string Student::get_name_student() const
{
	return name_student;
};

//--------------------------------------------------------
//----------(name_famile)---------------------------------

string Student::get_name_famile() const
{
	return famile_name;
};

//--------------------------------------------------------
//----------(enroll_year)---------------------------------

unsigned int Student::get_enroll_year() const
{
	return enroll_year;
};

//--------------------------------------------------------
//----------(age)-------------------------------------

unsigned int Student::get_age() const
{
	return age;
};
