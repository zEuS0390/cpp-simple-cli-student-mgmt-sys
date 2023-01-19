#include <iostream>
#include <string>
#include <functional>
#include <map>
#include <stdexcept>
#include "student.hpp"
#include "classes.hpp"

template <std::size_t SIZE>
void displayOptions(std::array<std::pair<std::string, std::function<void()>>, SIZE>&);
void option_exit(bool*);
void option_addStudent(Classes*);
void option_displayStudents(Classes*);

// Main function
int main (void) {
	bool isRunning = true;
	std::string select;
	Classes section("CPE1FB3");

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
		try {
			int index = std::stoi(select);
			if (index >= 0 && index < options.size()) {
				options[index].second();
			} else {
				std::cout << "Selected option is out of range!\n";
			}
		} catch (std::invalid_argument) {
			std::cout << "\n\tInvalid input!\n";
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

void option_addStudent(Classes *section) {
	Student *student = Student::createStudent();
	section->addStudent(student);
}

void option_displayStudents(Classes *section) {
	section->displayAllStudents();
}
