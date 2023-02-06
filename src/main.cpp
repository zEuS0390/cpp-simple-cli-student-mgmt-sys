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
#define OPTION [](Class &section, bool &isRunning)
#define SET_LAMBDA(name, expr) auto name = expr

template <std::size_t SIZE>
using ArrayOptions = std::array<std::pair<std::string, void(*)(Class&,bool&)>, SIZE>;

template <std::size_t SIZE>
void displayOptions(ArrayOptions<SIZE>&);

// Main function
int main (void) {
	SET_LAMBDA(clear, []{std::system(CLEAR_COMMAND);});
	SET_LAMBDA(wait, []{std::cout << "\n\tPress any key to continue...";std::cin.get();});
	bool isRunning = true;
	std::string select;
	Class section("CPE1FB3");
	ArrayOptions<5> options {{
		{"Exit", OPTION{option::exit(&isRunning);}},
		{"Add Student", OPTION{option::addStudent(&section);}},
		{"Update Student", OPTION{option::updateStudent(&section);}},
		{"Delete Student", OPTION{option::deleteStudent(&section);}},
		{"Display Students", OPTION{option::displayStudents(&section);}}
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
			wait(); clear();
			continue;
		}
		if (index < options.size()) {
			options[index].second(section, isRunning);
		} else {
			std::cout << "\n\tSelected option is out of range!\n";
		}
		wait(); clear();
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
