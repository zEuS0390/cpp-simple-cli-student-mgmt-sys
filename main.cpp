#include <iostream>
#include <string>
#include <functional>
#include <map>
#include <stdexcept>
#include "student.hpp"
#include "class.hpp"

template <std::size_t SIZE>
void displayOptions(std::array<std::pair<std::string, std::function<void()>>, SIZE>&);
void option_exit(bool*);
void option_addStudent(Class*);
void option_displayStudents(Class*);

// Main function
int main (void) {
	bool isRunning = true;
	std::string select;
	Class section("CPE1FB3");

	std::array<std::pair<std::string, std::function<void()>>, 3> options{{
		{"Exit", std::bind(option_exit, &isRunning)},
		{"Add Student", std::bind(option_addStudent, &section)},
		{"Display Students", std::bind(option_displayStudents, &section)}
	}};

	while (isRunning) {
		std::cout << "\n\t" + std::string(50, '%') + "\n";
		displayOptions(options);
		std::cout << "\tSelect an option [0-" + std::to_string(options.size()-1) + "]: ";
		std::getline(std::cin, select);
		int index;
		try {
			index = std::stoi(select);
		} catch (std::invalid_argument) {
			std::cout << "\n\tInvalid input!\n";
			continue;
		}
		if (index >= 0 && index < options.size()) {
			options[index].second();
		} else {
			std::cout << "\n\tSelected option is out of range!\n";
		}
	}

	return 0;
}

template <std::size_t SIZE>
void displayOptions(std::array<std::pair<std::string, std::function<void()>>, SIZE> &options) {
	std::cout << "\n\tOptions:\n\n";
	for (int i = 0; i < options.size(); i++) {
		std::cout << "\t" << std::to_string(i) + " - " + options[i].first + "\n";
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

void option_displayStudents(Class *section) {
	section->displayAllStudents();
}
