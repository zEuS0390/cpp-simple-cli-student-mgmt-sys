#include <string>
#include "student.hpp"

int Student::student_number = 0;

Student::Student (std::string fname, std::string lname, int age):
	Person(fname, lname, age) {
		student_number++;
}

int Student::getStudentNumber() {
	return student_number;
}
