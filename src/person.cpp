#include <iostream>
#include <string>
#include <vector>
#include <variant>
#include "person.hpp"

Person::Person (const std::string &fname, const std::string &lname, int age):
	first_name(fname), last_name(lname), age(age) {
}

std::vector<std::variant<std::string, int>> Person::getInfo() {
	std::vector<std::variant<std::string, int>> vec;
	vec.push_back(first_name);
	vec.push_back(last_name);
	vec.push_back(age);
	return vec;
}

void Person::setFirstName(std::string fname) {
	this->first_name = fname;
}

void Person::setLastName(std::string lname) {
	this->last_name = lname;
}

void Person::setAge(int a) {
	this->age = a;
}
