#include <string>
#include "classes.hpp"

Classes::Classes (std::string class_name):
	total_students(0),
	class_name(class_name) {
}

void Classes::addStudent(Student *student) {
	(*students) = student;
	total_students++;
}

void Classes::displayAllStudents() {
	for (int i = 0; i < total_students; i++) {
		students[i]->getInfo();
	}
}
