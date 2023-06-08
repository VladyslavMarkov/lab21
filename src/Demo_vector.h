#ifndef Arr_Student_H
#define Arr_Student_H

using std::ostream;

template <typename T> 
class Demo_vector {
    public:
	Demo_vector();
	Demo_vector(const size_t n_val, const T &value);
	Demo_vector(const Demo_vector &src);
	~Demo_vector();

	friend bool operator==(const Student &student_classic, const Student &student_other);
	friend bool operator>(const Student &student_classic, const Student &student_other);
	friend ostream &operator<<(ostream &os, const Student &student);

	void reserve(size_t n);
	void print_scr();
	size_t find_i(const T &elements);
	T find_min();
	void sort_arr();
	void push_back(const T &value);
	void remove_elem(size_t index);

    private:
	T *array;
	size_t n_elem;
	size_t n_memory;
};

#include "Demo_vector.inl"

#endif
