#include <iostream>
#include <string>
#include "class.hpp"

Class::Class (std::string class_name):
	total_students{0},
	class_name{class_name} {
}

void Class::addStudent(Student *student) {
	if (total_students == MAX_STUDENTS) {
		std::cout << "\n\tThe array is already full.\n";
		return;
	}
	students[total_students] = student;
	total_students++;
}

void Class::displayAllStudents() {
	std::cout << "\n\t=========================================\n";
	for (int i = 0; i < total_students; i++) {
		std::cout << "\t-----------------------------------------\n";
		std::cout << "\tStudent Number: " << std::to_string(students[i]->getStudentNumber()) + "\n";
		students[i]->getInfo();
		std::cout << "\t-----------------------------------------\n";
	}
	std::cout << "\n\t=========================================\n";
}

int Class::findStudent(int student_number) {
	int left = 0;
	int right = total_students - 1;
	int middle;
	while (left <= right) {
		middle = left + (right - left) / 2;
		if (students[middle]->getStudentNumber() == student_number) {
			return middle;
		}
		if (students[middle]->getStudentNumber() < student_number) {
			left = middle + 1; 
		} else {
			right = middle - 1;
		}
	}
	return -1;
}

void Class::deleteStudent(int student_number) {
	if (total_students == 0) {
		std::cout << "\n\tThe class is empty.\n";
		return;
	}
	int index = findStudent(student_number);
	if (index != -1) {
		delete students[index];
		students[index] = nullptr;
		while (index < total_students-1) {
			students[index] = students[index+1];
			index++;
		}
		students[index] = nullptr;
		total_students--;
	} else {
		std::cout << "\n\tStudent number doesn't exist!\n";
	}	
	return;
}
