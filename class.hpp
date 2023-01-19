#ifndef CLASS_H
#define CLASS_H
#include <string>
#include <array>
#include "student.hpp"
#define MAX_STUDENTS 40

class Class {
	private:
		std::string class_name;
		std::array<Student*, MAX_STUDENTS> students;
		int total_students;
	public:
		Class(std::string);
		void addStudent(Student*);
		void updateStudent(int);
		void deleteStudent(int);
		void displayAllStudents();
		int findStudent(int);
};

#endif
