#ifndef CLASSES_H
#define CLASSES_H
#include <string>
#include "student.hpp"
#define MAX_STUDENTS 40

class Classes {
	private:
		std::string class_name;
		Student *students[MAX_STUDENTS];
		int total_students;
	public:
		Classes(std::string);
		void addStudent(Student*);
		void displayAllStudents();
};

#endif
