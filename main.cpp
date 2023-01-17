#include <iostream>
#include <string>
#include <functional>
#include <map>
#include <stdexcept>
#include "student.hpp"
#include "classes.hpp"

void displayOptions(std::string*, int);
void option_exit(bool*);
void option_addStudent(Classes*);
void option_displayStudents(Classes*);

// Main function
int main (void) {
	bool running = true;
	std::string select;
	Classes *section = new Classes("CPE1FB3");
	std::map<int, std::function<void()>> options;
	options.insert(std::make_pair(0, std::bind(option_exit, &running)));
	options.insert(std::make_pair(1, std::bind(option_addStudent, section)));
	options.insert(std::make_pair(2, std::bind(option_displayStudents, section)));
	std::string str_options[options.size()] = {
		"Exit",
		"Add Student",
		"Display Students"
	};
	while (running) {
		std::cout << "\n\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
		displayOptions(str_options, sizeof(str_options)/sizeof(str_options[0]));
		std::cout << "\tSelect an option [0-" + std::to_string(options.size()-1) + "]: ";
		std::getline(std::cin, select);
		try {
			std::map<int, std::function<void()>>::iterator it = options.find(std::stoi(select));
			if (it != options.end()) {
				it->second();
			} else {
				std::cout << "Option not found!" << std::endl;
			}
		} catch (std::invalid_argument) {
			std::cout << "Invalid input!" << std::endl;
		}
	}
	return 0;
}

void displayOptions(std::string *str_options, int length) {
	std::cout << "\n\tOptions:\n\n";
	for (int i = 0; i < length; i++) {
		std::cout << "\t" << std::to_string(i) + " - " + str_options[i] + "\n";
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
