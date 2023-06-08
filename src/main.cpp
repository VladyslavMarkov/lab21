#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::find;
using std::numeric_limits;
using std::streamsize;
using std::string;

#include "Student.h"
#include "Demo_vector.h"

int main()
{
	Student student1(1, "Джек", "Річард", 2018, 19);
	Student student2(1, "Том", "Лінкольн", 2022, 21);
	Student student3(0, "Алекс", "Нільсон", 2020, 18);
	Student student4(2, "Боб", "Шоун", 2019, 24);
	Student student5(0, "Джон", "Кенеді", 2018, 18);
	Student student6(0, "Карл", "Марс", 2018, 20);

	Demo_vector<Student> vector_class;
	vector_class.push_back(student1);
	vector_class.push_back(student2);
	vector_class.push_back(student3);
	vector_class.push_back(student4);
	vector_class.push_back(student5);

	Demo_vector<int> vector_int;
	vector_int.push_back(235);
	vector_int.push_back(567);
	vector_int.push_back(123);
	vector_int.push_back(76);
	vector_int.push_back(489);

	cout << endl << "Робота класу шаблоний список" << endl;


	cout << "=======================================" << endl << endl;


	cout << "Демострація роботи метода виводу вмісту масива на екран" << endl;

	cout << endl << "Вміст масиву типу -->[int]<--" << endl << "---" << endl;
	vector_int.print_scr();
	cout << "---" << endl;

	cout << endl << "Вміст масиву типу -->[class Student]<--" << endl << "---" << endl;
	vector_class.print_scr();
	cout << "---" << endl;


	cout << endl << "=======================================" << endl << endl;


	cout << "Демострація роботи метода отримання індексу переданого елемента у масив" << endl;

	cout << endl << "Переданий елемент [567]" << endl << "---" << endl;
	cout << vector_int.find_i(567) << endl << "---" << endl;

	cout << endl << "Переданий елемент [ні; Алекс; Нільсон; 2020; 18;]" << endl << "---" << endl;
	cout << vector_class.find_i(student3) << endl << "---" << endl;


	cout << endl << "=======================================" << endl << endl;


	cout << "Демострація роботи метода для пошуку мінімального значення у масиві" << endl;

	cout << endl << "Мінімальний елемент у масиві типу -->[int]<-- це (76)" << endl << "---" << endl;
	cout << vector_int.find_min() << endl << "---" << endl;

	cout << endl << "Мінімальний елемент у масиві типу -->[class Student]<-- це (так; Джек; Річард; 2018; 19;)" << endl << "---" << endl;
	cout << vector_class.find_min() << endl << "---" << endl;


	cout << endl << "=======================================" << endl << endl;


	cout << "Демострація роботи метода для додавання елемента у масив" << endl;

	cout << endl << "Поточний маисв типу -->[int]<--" << endl << "---" << endl;
	vector_int.print_scr();
	cout << "---" << endl;
	cout << endl << "Елемент який додаємо у масив типу -->[int]<-- це (100)" << endl << "---" << endl;
	vector_int.push_back(100);
	vector_int.print_scr();
	cout << "---" << endl;

	cout << endl << "Поточний маисв типу -->[class Student]<--" << endl << "---" << endl;
	vector_class.print_scr();
	cout << "---" << endl;
	cout << endl << "Елемент який додаємо у масив типу -->[class Student]<-- це (ні ;Карл; Марс; 2018; 20)" << endl << "---" << endl;
	vector_class.push_back(student6);
	vector_class.print_scr();
	cout << "---" << endl;


	cout << endl << "=======================================" << endl << endl;


	cout << "Демострація роботи метода для видалення елемента з масиву" << endl;

	cout << endl << "Поточний маисв типу -->[int]<--" << endl << "---" << endl;
	vector_int.print_scr();
	cout << "---" << endl;
	cout << endl << "Елемент який видаляємо з масива типу -->[int]<-- це (100), інедекс(6) при розрахунку з 1 " << endl << "---" << endl;
	vector_int.remove_elem(6);
	vector_int.print_scr();
	cout << "---" << endl;

	cout << endl << "Поточний маисв типу -->[class Student]<--" << endl << "---" << endl;
	vector_class.print_scr();
	cout << "---" << endl;
	cout << endl
	     << "Елемент який видаляємо з масива типу -->[class Student]<-- це (ні ;Карл; Марс; 2018; 20), інедекс(6) при розрахунку з 1" << endl
	     << "---" << endl;
	vector_class.remove_elem(6);
	vector_class.print_scr();
	cout << "---" << endl;


	cout << endl << "=======================================" << endl << endl;


	cout << "Демострація роботи метода для сортування масиву" << endl;

	cout << endl << "Поточний маисв типу -->[int]<--" << endl << "---" << endl;
	vector_int.print_scr();
	cout << "---" << endl;
	cout << endl << "Відсортований масив від найменшого значення до найбільшого" << endl << "---" << endl;
	vector_int.sort_arr();
	vector_int.print_scr();
	cout << "---" << endl;

	cout << endl << "Поточний маисв типу -->[class Student]<--" << endl << "---" << endl;
	vector_class.print_scr();
	cout << "---" << endl;
	cout << endl << "Відсортований масив від найменшого року вступу до найбільшого" << endl << "---" << endl;
	vector_class.sort_arr();
	vector_class.print_scr();
	cout << "---" << endl;

	return 0;
}
