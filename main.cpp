#include <iostream>
#include <string>
#include "student.hpp"
#include "classes.hpp"

Student* createStudent() {
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

int main (void) {
	int n, times;
	n = 0;
	times = 2;
	Classes section_1("Section 1");
	while (n < times) {
		Student* student = createStudent();
		section_1.addStudent(student);
		n++;
	}
	section_1.displayAllStudents();
	return 0;
}
