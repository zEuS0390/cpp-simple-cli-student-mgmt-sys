#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include "person.hpp"

class Student: public Person {
	public:
		Student(std::string, std::string, int);
		virtual ~Student();
		int getStudentNumber();
		static Student* createStudent();
	private:
		static int total_student_no;
		int student_number;
};

#endif
