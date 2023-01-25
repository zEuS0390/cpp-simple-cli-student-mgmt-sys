#include <iostream>
#include <string>
#include <vector>
#include <variant>
#include "class.hpp"

Class::Class (const std::string &class_name):
	class_name{class_name} {
		total_students = 0;
}

void Class::addStudent(Student *student) {
	if (total_students == MAX_STUDENTS) {
		std::cout << "\n\tThe array is already full.\n";
		return;
	}
	students[total_students] = student;
	total_students++;
}

void Class::updateStudent(int student_number) {
	if (total_students == 0) {
		std::cout << "\n\tThe class is empty.\n";
		return;
	}
	int index = findStudent(student_number);
	if (index != -1) {
		std::string first_name, last_name, str_age;
		std::cout << "\n\tFirst Name: ";
		std::getline(std::cin, first_name);	
		std::cout << "\tLast Name: ";
		std::getline(std::cin, last_name);
		while (true) {
			std::cout << "\tAge: ";
			std::getline(std::cin, str_age);
			try {
				int age = std::stoi(str_age);	
				students[index]->setFirstName(first_name);
				students[index]->setLastName(last_name);
				students[index]->setAge(age);
				break;
			} catch (std::invalid_argument&) {
				continue;
			}
		}
	} else {
		std::cout << "\n\tStudent doesn't exist!\n";
	}
	return;
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
		std::cout << "\n\tStudent doesn't exist!\n";
	}	
	return;
}

void Class::displayAllStudents() {
	std::cout << "\n\t" + std::string(100, '=') + "\n";
	if (total_students == 0) {
		std::cout << "\n\tThe class is empty.\n";
	} else {
		std::cout << "\tStudent Number\t\tFirst Name\t\tLast Name\t\tAge\n";
		std::cout << "\t"+ std::string(100, '-') + "\n";
		for (int i = 0; i < total_students; i++) {
			std::vector<std::variant<std::string, int>> student_personal_info = students[i]->getInfo();
			std::string first_name = std::get<std::string>(student_personal_info[0]);
			std::string last_name = std::get<std::string>(student_personal_info[1]);
			int age = std::get<int>(student_personal_info[2]);
			const int student_number = students[i]->getStudentNumber();
			std::string str = "\t" + std::to_string(student_number) + "\t\t\t" + first_name + "\t\t" + last_name + "\t\t" + std::to_string(age) + "\n";
			std::cout << str;
			std::cout << "\t"+ std::string(100, '-') + "\n";
		}
	}
	std::cout << "\n\t" + std::string(100, '=') + "\n";
}

int Class::findStudent(int student_number) {
	int left = 0;
	int right = total_students - 1;
	while (left <= right) {
		int middle = left + (right - left) / 2;
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

