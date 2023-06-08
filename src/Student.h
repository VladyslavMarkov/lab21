#ifndef Student_H
#define Student_H

using std::ostream;
using std::string;

class Student {
    public:
	Student();
	Student(unsigned int budget_edu, string name_student, string famile_name, unsigned int enroll_year, unsigned int age);
	Student(const Student &student);

	~Student();

	friend ostream &operator<<(ostream &os, const Student &student);

	string get_budget_edu() const;

	string get_name_student() const;

	string get_name_famile() const;

	unsigned int get_enroll_year() const;
	
	unsigned int get_age() const;
	

    private:
	unsigned int budget_edu;
	string name_student;
	string famile_name;
	unsigned int enroll_year;
	unsigned int age;
};

#endif
