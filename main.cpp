#include <iostream>
#include <string>
#include <functional>
#include <map>
#include "student.hpp"
#include "classes.hpp"
#include "menu.hpp"

void option_addStudent(Classes *section) {
	Student *student = Student::createStudent();
	section->addStudent(student);
}

void option_displayStudents(Classes *section) {
	section->displayAllStudents();
}

// Main function
int main (void) {
	int select;
	Classes *section = new Classes("CPE1FB3");
	std::map<int, std::function<void()>> options;
	options.insert(std::make_pair(1, std::bind(option_addStudent, section)));
	options.insert(std::make_pair(2, std::bind(option_displayStudents, section)));
	while (true) {
		std::cout << "Select an Option [1-" + std::to_string(options.size()) + "]: ";
		std::cin >> select;
		std::cin.ignore();
		std::map<int, std::function<void()>>::iterator it = options.find(select);
		if (it != options.end()) {
			it->second();
		} else {
			std::cout << "Option not found!" << std::endl;
		}
	}
	return 0;
}
