#include <iostream>

using std::string;

#include "Student.h"
#include <gtest/gtest.h>

TEST(ClassStudent, test_default_construcotr)
{
	Student student_actual;
	string expected_str_value = "не вказано";
	unsigned int expected_num_value = 0;

	ASSERT_EQ(expected_str_value, student_actual.get_budget_edu());
	ASSERT_EQ(expected_str_value, student_actual.get_name_student());
	ASSERT_EQ(expected_str_value, student_actual.get_name_famile());
	ASSERT_EQ(expected_num_value, student_actual.get_enroll_year());
	ASSERT_EQ(expected_num_value, student_actual.get_age());
}

TEST(ClassStudent, test_construcotr_with_param)
{
	Student student_actual(0, "не вказано", "не вказано", 0, 0);
	string expected_str_value[] = { "не вказано", "ні" };
	unsigned int expected_num_value = 0;

	ASSERT_EQ(expected_str_value[1], student_actual.get_budget_edu());
	ASSERT_EQ(expected_str_value[0], student_actual.get_name_student());
	ASSERT_EQ(expected_str_value[0], student_actual.get_name_famile());
	ASSERT_EQ(expected_num_value, student_actual.get_enroll_year());
	ASSERT_EQ(expected_num_value, student_actual.get_age());
}

TEST(ClassStudent, test_construcotr_cpy)
{
	Student student_expect(1, "не вказано", "не вказано", 0, 0);
	Student student_actual(student_expect);

	ASSERT_EQ(student_expect.get_budget_edu(), student_actual.get_budget_edu());
	ASSERT_EQ(student_expect.get_name_student(), student_actual.get_name_student());
	ASSERT_EQ(student_expect.get_name_famile(), student_actual.get_name_famile());
	ASSERT_EQ(student_expect.get_enroll_year(), student_actual.get_enroll_year());
	ASSERT_EQ(student_expect.get_enroll_year(), student_actual.get_age());
}











