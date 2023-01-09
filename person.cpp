#include <iostream>
#include <string>
#include "person.hpp"

Person::Person (std::string fname, std::string lname, int age):
	first_name(fname), last_name(lname), age(age) {
}

void Person::getInfo() {
	std::string str = "First Name: "+first_name+"\n"+"Last Name: "+last_name+"\n"+"Age: "+std::to_string(age)+"\n";
	std::cout << str;
}
