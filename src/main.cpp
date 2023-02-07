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
#include "constants.hpp"

inline void clear() { std::system(CLEAR_COMMAND); }
inline void wait() { std::cout << "\n\tPress any key to continue..."; std::cin.get(); }

// Main function
int main (void) {
	bool isRunning = true;
	std::string select;
	Class section("CPE1FB3");
	Options options = {
		{"Exit", OPTION{ option::exit(&isRunning); }}, 
		{"Add Student", OPTION{ option::addStudent(&section); }},
		{"Update Student", OPTION{ option::updateStudent(&section); }},
		{"Delete Student", OPTION{ option::deleteStudent(&section); }},
		{"Display Students", OPTION{ option::displayStudents(&section); }}
	};
	clear();
	while (isRunning) {
		std::cout << "\n\t" + std::string(50, '%') + "\n";
		options.display();
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
			options.execute(index, section, isRunning);
		} else {
			std::cout << "\n\tSelected option is out of range!\n";
		}
		wait(); clear();
	}
	return 0;
}
