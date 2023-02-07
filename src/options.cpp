#include <iostream>
#include <string>
#include <stdexcept>
#include <utility>
#include "student.hpp"
#include "class.hpp"
#include "options.hpp"
#include "constants.hpp"

using OptionItem = std::pair<std::string, void(*)(Class&,bool&)>;

Options::Options (std::initializer_list<OptionItem> list) {
	if (list.size() > opts.size()) throw std::length_error("Number of options must not exceed to "+std::to_string(constants::OPT_MAX_SIZE));
	total_size = 0;
	for (auto i: list) {
		opts[total_size] = {i.first, i.second};
		total_size++;
	}
}

void Options::execute(unsigned int index, Class &cls, bool &state) {
	if (index > total_size) return;
	opts[index].second(cls, state);
}

void Options::display() {
	std::cout << "\n\tOptions:\n\n";
	for (std::size_t i = 1; i < total_size; i++) {
		if (opts[i].second == nullptr) continue;
		std::cout << "\t[" << std::to_string(i) + "] " + opts[i].first + "\n";
	}
	std::cout << "\n";
}

OptionItem Options::operator[](unsigned int index) {
	return opts[index];
}

unsigned int Options::size() {
	return total_size;
}

namespace option {
	void exit(bool *state) {
		*state = false;
	}
	void addStudent(Class *section) {
		Student *student = Student::createStudent();
		section->addStudent(student);
	}
	void updateStudent(Class *section) {
		std::string str_student_number;
		int student_number;
		while (true) {
			std::cout << "\n\tEnter student number: ";
			std::getline(std::cin, str_student_number);
			try {
				student_number = std::stoi(str_student_number);
				break;
			} catch (std::invalid_argument&) {
				std::cout << "\n\tInvalid input!\n";
				continue;
			}
		}
		section->updateStudent(student_number);
	}
	void deleteStudent(Class *section) {
		std::string str_student_number;
		int student_number;
		while (true) {
			std::cout << "\n\tEnter student number: ";
			std::getline(std::cin, str_student_number);
			try {
				student_number = std::stoi(str_student_number);
				break;
			} catch (std::invalid_argument&) {
				std::cout << "\n\tInvalid input!\n";
				continue;
			}
		}
		section->deleteStudent(student_number);
	}
	void displayStudents(Class *section) {
		section->displayAllStudents();
	}
}
