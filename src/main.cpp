#include <iostream>
#include <string>
#include <stdexcept>
#include <cstdlib> 
#include "student.hpp"
#include "class.hpp"
#include "options.hpp"
#include "constants.hpp"
#ifdef _WIN32
#define CLEAR_COMMAND "cls"
#else
#define CLEAR_COMMAND "clear"
#endif
#define OPTION [](Class &section, bool &isRunning)

inline void clear() { std::system(CLEAR_COMMAND); }
inline void wait() { std::cout << "\n\tPress any key to continue..."; std::cin.get(); }

// Main function
int main () {
	bool isRunning = true;
	std::string select;
	Class section("CPE1FB3");

	// Create option items
	Options options = {
		{"Exit", OPTION{ option::exit(&isRunning); }}, 
		{"Add Student", OPTION{ option::addStudent(&section); }},
		{"Update Student", OPTION{ option::updateStudent(&section); }},
		{"Delete Student", OPTION{ option::deleteStudent(&section); }},
		{"Display Students", OPTION{ option::displayStudents(&section); }}
	};

	clear();

	while (isRunning) {
		// Display options
		options.display();

		// Get input from the user
		std::cout << "\tSelect an option [0-" + std::to_string(options.size()-1) + "]: ";
		std::getline(std::cin, select);
		
		// Convert input string to unsigned int
		unsigned int index;
		try {
			index = std::stoi(select);
		} catch (std::invalid_argument&) {
			std::cout << "\n\tInvalid input!\n";
			wait(); clear();
			continue;
		}

		// Execute the requested function
		if (index < options.size()) {
			options.execute(index, section, isRunning);
		} else {
			std::cout << "\n\tSelected option is out of range!\n";
		}

		wait(); clear();
	}
	return 0;
}
