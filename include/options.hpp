#ifndef OPTIONS_H
#define OPTIONS_H
#include <string>
#include <array>
#include <utility>
#include <functional>
#include "class.hpp"
#include "constants.hpp"

using OptionItem = std::pair<std::string, void(*)(Class&,bool&)>;
using ArrayOptions = std::array<OptionItem, constants::OPT_MAX_SIZE>;

class Options {
	public:
		Options();
		Options(std::initializer_list<OptionItem>);
		void execute(unsigned int, Class&, bool&);
		void display();
		OptionItem operator[](unsigned int);
		unsigned int size();
	private:
		unsigned int total_size;
		ArrayOptions opts;
};

namespace option {
	void exit(bool*);
	void addStudent(Class*); 
	void updateStudent(Class*); 
	void deleteStudent(Class*);
	void displayStudents(Class*);
}

#endif
