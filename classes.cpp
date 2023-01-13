#include <iostream>
#include <string>
#include "classes.hpp"

Classes::Classes (std::string class_name):
	total_students(0),
	class_name(class_name) {
}

void Classes::addStudent(Student *student) {
	*(students + total_students) = student;
	total_students++;
}

void Classes::displayAllStudents() {
	std::cout << "\n\t=========================================\n";
	for (int i = 0; i < total_students; i++) {
		std::cout << "\t-----------------------------------------\n";
		std::cout << "\tStudent Number: " << std::to_string(students[i]->getStudentNumber()) + "\n";
		students[i]->getInfo();
		std::cout << "\t-----------------------------------------\n";
	}
	std::cout << "\n\t=========================================\n";
}

