#include <iostream>
#include <string>
#include <functional>
#include <stdexcept>
#include <array>
#include <cstdlib> 
#include "student.hpp"
#include "class.hpp"
#include "options.hpp"
#ifdef _WIN32
#define CLEAR_COMMAND "cls"
#else
#define CLEAR_COMMAND "clear"
#endif

template <std::size_t SIZE>
using ArrayOptions = std::array<std::pair<std::string, std::function<void()>>, SIZE>;

template <std::size_t SIZE>
void displayOptions(ArrayOptions<SIZE>&);

// Main function
int main (void) {
	auto clear = []{std::system(CLEAR_COMMAND);};
	auto wait = []{
		std::cout << "\n\tPress any key to continue...";
		std::cin.get();
	};
	bool isRunning = true;
	std::string select;
	Class section("CPE1FB3");

	ArrayOptions<5> options{{
		{"Exit", std::bind(option::exit, &isRunning)},
		{"Add Student", std::bind(option::addStudent, &section)},
		{"Update Student", std::bind(option::updateStudent, &section)},
		{"Delete Student", std::bind(option::deleteStudent, &section)},
		{"Display Students", std::bind(option::displayStudents, &section)}
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
