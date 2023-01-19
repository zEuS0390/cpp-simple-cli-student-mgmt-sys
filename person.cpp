#include <iostream>
#include <string>
#include "person.hpp"

Person::Person (std::string fname, std::string lname, int age):
	first_name(fname), last_name(lname), age(age) {
}

void Person::getInfo() {
	std::string str = "\tFirst Name: "+first_name+"\n\tLast Name: "+last_name+"\n\tAge: "+std::to_string(age)+"\n";
	std::cout << str;
}

void Person::setFirstName(std::string fname) {
	first_name = fname;
}

void Person::setLastName(std::string lname) {
	last_name = lname;
}

void Person::setAge(int a) {
	age = a;
}
