#include <iostream>
#include <string>
#include "student.hpp"
#include "classes.hpp"

int main (void) {
	int n, times;
	n = 0;
	times = 5;
	Classes section_1("Section 1");
	while (n < times) {
		Student* student = Student::createStudent();
		section_1.addStudent(student);
		n++;
	}
	section_1.displayAllStudents();
	return 0;
}
