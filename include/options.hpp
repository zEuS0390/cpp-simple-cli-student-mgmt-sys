#ifndef OPTIONS_H
#define OPTIONS_H
#include <functional>
#include <string>
#include <array>
#include "class.hpp"

namespace option {
	void exit(bool*);
	void addStudent(Class*); 
	void updateStudent(Class*); 
	void deleteStudent(Class*);
	void displayStudents(Class*);
}

#endif
