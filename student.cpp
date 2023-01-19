#include <iostream>
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

Student* Student::createStudent() {
	std::string first_name, last_name, age;
	std::cout << "\n";
	while (true) {
		std::cout << "\tFirst Name?: ";
		getline(std::cin, first_name);
		if (first_name.length() > 0) {
			break;
		}
	}
	while (true) {
		std::cout << "\tLast Name?: ";
		getline(std::cin, last_name);
		if (last_name.length() > 0) {
			break;
		}
	}
	while (true) {
		std::cout << "\tAge?: ";
		getline(std::cin, age);
		if (age.length() > 0) {
			break;
		}
	}
	return new Student(first_name, last_name, std::stoi(age));
}
