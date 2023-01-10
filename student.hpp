#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include "person.hpp"

class Student: public Person {
	private:
		static int total_student_no;
		int student_number;
	public:
		Student(std::string, std::string, int);
		int getStudentNumber();
		static Student* createStudent();
};

#endif
