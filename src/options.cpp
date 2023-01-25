#include <iostream>
#include <string>
#include <stdexcept>
#include "student.hpp"
#include "class.hpp"
#include "options.hpp"

namespace option {
	void exit(bool *state) {
		*state = false;
	}
	void addStudent(Class *section) {
		Student *student = Student::createStudent();
		section->addStudent(student);
	}
	void updateStudent(Class *section) {
		std::string str_student_number;
		int student_number;
		while (true) {
			std::cout << "\n\tEnter student number: ";
			std::getline(std::cin, str_student_number);
			try {
				student_number = std::stoi(str_student_number);
				break;
			} catch (std::invalid_argument&) {
				std::cout << "\n\tInvalid input!\n";
				continue;
			}
		}
		section->updateStudent(student_number);
	}
	void deleteStudent(Class *section) {
		std::string str_student_number;
		int student_number;
		while (true) {
			std::cout << "\n\tEnter student number: ";
			std::getline(std::cin, str_student_number);
			try {
				student_number = std::stoi(str_student_number);
				break;
			} catch (std::invalid_argument&) {
				std::cout << "\n\tInvalid input!\n";
				continue;
			}
		}
		section->deleteStudent(student_number);
	}
	void displayStudents(Class *section) {
		section->displayAllStudents();
	}
}
