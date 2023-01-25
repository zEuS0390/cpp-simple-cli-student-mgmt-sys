#include <iostream>
#include <string>
#include <functional>
#include <map>
#include <stdexcept>
#include <array>
#include <cstdlib> 
#include "student.hpp"
#include "class.hpp"

template <std::size_t SIZE>
using ArrayOptions = std::array<std::pair<std::string, std::function<void()>>, SIZE>;

template <std::size_t SIZE>
void displayOptions(ArrayOptions<SIZE>&);
void option_exit(bool*);
void option_addStudent(Class*);
void option_updateStudent(Class*);
void option_deleteStudent(Class*);
void option_displayStudents(Class*);

// Main function
int main (void) {
	auto clear = []{
		#ifdef _WIN32
		std::system("cls");
		#else
		std::system("clear");
		#endif
	};
	auto wait = []{
		std::cout << "\n\tPress any key to continue...";
		std::cin.get();
	};
	bool isRunning = true;
	std::string select;
	Class section("CPE1FB3");

	ArrayOptions<5> options{{
		{"Exit", std::bind(option_exit, &isRunning)},
		{"Add Student", std::bind(option_addStudent, &section)},
		{"Update Student", std::bind(option_updateStudent, &section)},
		{"Delete Student", std::bind(option_deleteStudent, &section)},
		{"Display Students", std::bind(option_displayStudents, &section)}
	}};

	clear();
	while (isRunning) {
		std::cout << "\n\t" + std::string(50, '%') + "\n";
		displayOptions(options);
		std::cout << "\tSelect an option [0-" + std::to_string(options.size()-1) + "]: ";
		std::getline(std::cin, select);
		unsigned int index;
		try {
			index = std::stoi(select);
		} catch (std::invalid_argument&) {
			std::cout << "\n\tInvalid input!\n";
			wait();
			clear();
			continue;
		}
		if (index < options.size()) {
			options[index].second();
		} else {
			std::cout << "\n\tSelected option is out of range!\n";
		}
		wait();
		clear();
	}

	return 0;
}

template <std::size_t SIZE>
void displayOptions(ArrayOptions<SIZE> &options) {
	std::cout << "\n\tOptions:\n\n";
	for (std::size_t i = 1; i < options.size(); i++) {
		std::cout << "\t[" << std::to_string(i) + "] " + options[i].first + "\n";
	}
	std::cout << "\n";
}

void option_exit(bool *state) {
	*state = false;
}

void option_addStudent(Class *section) {
	Student *student = Student::createStudent();
	section->addStudent(student);
}

void option_updateStudent(Class *section) {
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

void option_deleteStudent(Class *section) {
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

void option_displayStudents(Class *section) {
	section->displayAllStudents();
}
