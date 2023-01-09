#include <iostream>
#include <string>
#include "student.hpp"
#include "classes.hpp"

int main (void) {
	std::string first_name, last_name;
	int age, n, times;
	n = 0;
	times = 2;
	Classes section_1("Section 1");
	while (n < times) {
		std::cout << "First Name?: ";
		getline(std::cin, first_name);
		std::cout << "Last Name?: ";
		getline(std::cin, last_name);
		std::cout << "Age?: ";
		std::cin >> age;
		std::cin.ignore();
		Student *student = new Student(first_name, last_name, age);
		section_1.addStudent(student);
		n++;
	}
	section_1.displayAllStudents();
	return 0;
}
