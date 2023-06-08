#include <iostream>

using std::string;

#include "Student.h"
#include "Demo_vector.h"

#include <gtest/gtest.h>

TEST(ClassDemo_vector, test_find_index)
{
	Student student1(1,"Джек","Річард", 2019, 19);
	Demo_vector<Student> vector_class(5, student1);
	
	//Перевірка на пошук пошук индекса певного елемента
	size_t expected_index = 0;
	
	ASSERT_EQ(vector_class.find_i(student1), expected_index);
	
	//Перевірка на те як що у масиві не буде знайдене такий елемент метод поверне кількість елементів в цілому
	size_t expected_value = 5;
	
	ASSERT_EQ(vector_class.find_i(student1), expected_index);
}

TEST(ClassDemo_vector, test_find_min_element)
{
	Student student1(1,"Джек","Річард", 2018, 19);
	Student student2(1,"Том","Лінкольн", 2022, 21);
	Student student3(0,"Алекс","Нільсон", 2020, 18);
	Student student4(2,"Боб","Шоун", 2019, 24);
	Student student5(0,"Джон","Кенеді", 2018, 18);
	
	Demo_vector<Student> vector_class;
	vector_class.push_back(student1);
	vector_class.push_back(student2);
	vector_class.push_back(student3);
	vector_class.push_back(student4);
	vector_class.push_back(student5);
	
	//Мінімальний елемент визначається за роком вступу, в данному випадку найменший це 2018
	ASSERT_EQ(vector_class.find_min(), student1);
}

TEST(ClassDemo_vector, test_add_element)
{
	Student student1(1,"Джек","Річард", 2018, 19);
	Student student2(1,"Том","Лінкольн", 2022, 21);
	Demo_vector<Student> vector_class(4,student2);
	size_t expected_value = 4;
	
	vector_class.push_back(student1);
	
	//Як що студент був доданий успішно його індекс буде 4 при розрахунку з 0
	ASSERT_EQ(vector_class.find_i(student1), expected_value);	
}

TEST(ClassDemo_vector, test_delete_element)
{
	Student student1(1,"Джек","Річард", 2018, 19);
	Student student2(1,"Том","Лінкольн", 2022, 21);
	Student student3(0,"Алекс","Нільсон", 2020, 18);
	Student student4(2,"Боб","Шоун", 2019, 24);
	Student student5(0,"Джон","Кенеді", 2018, 18);
	
	Demo_vector<Student> vector_class;
	vector_class.push_back(student1);
	vector_class.push_back(student2);
	vector_class.push_back(student3);
	vector_class.push_back(student4);
	vector_class.push_back(student5);
	
	size_t expected_value = 4;
	
	vector_class.remove_elem(2);
	
	//Як що елемент був видалений успішно метод для пошук індекса елемента поверне кількість елементів так як не знайде той що ми видалили
	ASSERT_EQ(vector_class.find_i(student2), expected_value);
}

TEST(ClassDemo_vector, test_sort_arr)
{
	Student student1(1,"Джек","Річард", 2018, 19);
	Student student2(1,"Том","Лінкольн", 2022, 21);
	Student student3(0,"Алекс","Нільсон", 2020, 18);
	Student student4(2,"Боб","Шоун", 2019, 24);
	Student student5(0,"Джон","Кенеді", 2018, 18);
	
	Demo_vector<Student> vector_class;
	vector_class.push_back(student1);
	vector_class.push_back(student2);
	vector_class.push_back(student3);
	vector_class.push_back(student4);
	vector_class.push_back(student5);
	
	vector_class.sort_arr();
	
	//Перевіряється що елемнти були відсортовані правильно и відповідають своєму індексу у масиві
	ASSERT_EQ(vector_class.find_i(student1), 0);
	ASSERT_EQ(vector_class.find_i(student5), 1);
	ASSERT_EQ(vector_class.find_i(student4), 2);
	ASSERT_EQ(vector_class.find_i(student3), 3);
	ASSERT_EQ(vector_class.find_i(student2), 4);
}












