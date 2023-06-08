#include <iostream>
#include <memory>

using std::cin;
using std::cout;
using std::endl;
using std::uninitialized_copy;

#include "Student.h"
#include "Demo_vector.h"

//--------------------------------------------------------
//----------(constructor & destructor)--------------------------
template <typename T> Demo_vector<T>::Demo_vector() : array(NULL), n_elem(0), n_memory(0)
{
	cout << endl << "Був виклакений конструктор за замовчуванням Demo_vector" << endl;
}

template <typename T> Demo_vector<T>::Demo_vector(const size_t n_val, const T &value) : n_elem(n_val), n_memory(n_val)
{
	array = reinterpret_cast<T *>(new int8_t[n_val * sizeof(T)]);

	size_t i = 0;
	try {
		for (; i < n_val; i++)
			new (array + i) T(value);
	} catch (...) {
		for (size_t j = 0; j < i; j++)
			array[i].~T();
		throw;
	}

	cout << endl << "Був виклакений конструктор з папрметрами Demo_vector" << endl;
}

template <typename T> Demo_vector<T>::~Demo_vector()
{
	if (array != NULL) {
		for (size_t i = 0; i < n_elem; i++)
			array[i].~T();
		delete[] reinterpret_cast<int8_t *>(array);
	}

	cout << endl << "Був виклакений деструктор Demo_vector" << endl;
}

//--------------------------------------------------------
//----------(overload operators)--------------------------

bool operator==(const Student &student_classic, const Student &student_other)
{
	return (student_classic.get_budget_edu() == student_other.get_budget_edu()) &&
	       (student_classic.get_name_student() == student_other.get_name_student()) &&
	       (student_classic.get_name_famile() == student_other.get_name_famile()) &&
	       (student_classic.get_enroll_year() == student_other.get_enroll_year()) && (student_classic.get_age() == student_other.get_age());
}

ostream &operator<<(ostream &os, const Student &student)
{
	os << student.get_budget_edu() << "; " << student.name_student << "; " << student.famile_name << "; " << student.enroll_year << "; "
	   << student.age << ";";
	return os;
}

bool operator>(const Student &student_classic, const Student &student_other)
{
	return (student_classic.get_enroll_year() > student_other.get_enroll_year());
}

//--------------------------------------------------------
//----------(methoods)------------------------------------

template <typename T> void Demo_vector<T>::reserve(size_t n)
{
	if (n <= n_memory)
		return;

	T *newarr = reinterpret_cast<T *>(new int8_t[n * sizeof(T)]);

	try {
		uninitialized_copy(array, array + n_elem, newarr);
	} catch (...) {
		delete[] reinterpret_cast<int8_t *>(newarr);
		throw;
	}

	for (size_t i = 0; i < n_elem; i++)
		array[i].~T();

	if (array != NULL)
		delete[] reinterpret_cast<int8_t *>(array);

	array = newarr;
	n_memory = n;
}

template <typename T> void Demo_vector<T>::print_scr()
{
	if (n_elem == 0)
		return;

	for (size_t i = 0, j = 1; i < n_elem; i++, j++)
		cout << array[i] << endl;
}

template <typename T> size_t Demo_vector<T>::find_i(const T &elements)
{
	if (n_elem == 0)
		return n_elem;

	for (size_t i = 0; i < n_elem; i++)
		if (array[i] == elements)
			return i;

	return n_elem;
}

template <typename T> T Demo_vector<T>::find_min()
{
	if (n_elem == 0) {
		cout << endl << "value(cur_n_elem) <= 0" << endl;
		abort();
	}

	T min_elem = array[0];

	for (size_t i = 1; i < n_elem; i++)
		if (min_elem > array[i])
			min_elem = array[i];

	return min_elem;
}

template <typename T> void Demo_vector<T>::sort_arr()
{
	if (n_elem == 0) {
		cout << endl << "value(cur_n_elem) <= 0" << endl;
		abort();
	}

	for (unsigned int i = 0; i < n_elem - 1; i++) {
		for (unsigned int j = 0; j < n_elem - i - 1; j++) {
			if (array[j] > array[j + 1]) {
				T element = array[j];
				array[j] = array[j + 1];
				array[j + 1] = element;
			}
		}
	}
}

template <typename T> void Demo_vector<T>::push_back(const T &value)
{
	if (n_memory == n_elem)
		reserve(2 * (n_elem == 0 ? 1 : n_elem));

	new (array + n_elem) T(value);
	n_elem++;
}

template <typename T> void Demo_vector<T>::remove_elem(size_t index)
{
	if (index > n_elem)
		return;

	n_elem--;

	T *newarr = reinterpret_cast<T *>(new int8_t[n_elem * sizeof(T)]);

	try {
		for (size_t i = 0, j = 0; i < n_elem; i++) {
			if (i != (index - 1)) {
				new (newarr + j) T(array[i]);
				j++;
			}
		}
	} catch (...) {
		delete[] reinterpret_cast<int8_t *>(newarr);
		throw;
	}

	for (size_t i = 0; i < n_elem; i++)
		array[i].~T();

	delete[] reinterpret_cast<int8_t *>(array);
	array = newarr;
	n_memory--;
}
