#include <iostream>
#include <string>
#include "student.hpp"

int Student::total_student_no = 0;

Student::Student (std::string fname, std::string lname, int age):
	Person{fname, lname, age} {
		student_number = ++total_student_no;
}

int Student::getStudentNumber() {
	return student_number;
}

Student* Student::createStudent() {
	std::string first_name, last_name, str_age;
	int age;
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
		getline(std::cin, str_age);
		try {
			if (str_age.length() > 0) {
				age = std::stoi(str_age);
				break;
			}
		} catch (std::invalid_argument) {
			continue;
		}
	}
	return new Student(first_name, last_name, age);
}
