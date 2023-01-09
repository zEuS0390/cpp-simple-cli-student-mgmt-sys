#include <string>
#include "student.hpp"

int Student::total_student_no = 0;

Student::Student (std::string fname, std::string lname, int age):
	Person(fname, lname, age) {
		student_number = ++total_student_no;
}

int Student::getStudentNumber() {
	return student_number;
}
