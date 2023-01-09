#include <iostream>
#include <string>
#include "student.hpp"

int main (void) {
	std::string first_name, last_name;
	int age, n, times;
	n = 0;
	times = 2;
	while (n < times) {
		std::cout << "First Name?: ";
		getline(std::cin, first_name);
		std::cout << "Last Name?: ";
		getline(std::cin, last_name);
		std::cout << "Age?: ";
		std::cin >> age;
		std::cin.ignore();

		Student student(first_name, last_name, age);
		std::cout << "----------\n";
		student.getInfo();
		std::cout << "Student Number: " + std::to_string(student.getStudentNumber()) + "\n";
		std::cout << "----------\n";

		n++;
	}
	return 0;
}
