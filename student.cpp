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
	std::string first_name, last_name;
	int age;
	std::cout << "First Name?: ";
	getline(std::cin, first_name);
	std::cout << "Last Name?: ";
	getline(std::cin, last_name);
	std::cout << "Age?: ";
	std::cin >> age;
	std::cin.ignore();
	return new Student(first_name, last_name, age);
}
