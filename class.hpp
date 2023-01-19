#ifndef CLASS_H
#define CLASS_H
#include <string>
#include "student.hpp"
#define MAX_STUDENTS 40

class Class {
	private:
		std::string class_name;
		Student *students[MAX_STUDENTS];
		int total_students;
	public:
		Class(std::string);
		void addStudent(Student*);
		void displayAllStudents();
};

#endif
