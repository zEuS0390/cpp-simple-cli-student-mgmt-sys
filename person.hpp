#ifndef PERSON_H
#define PERSON_H
#include <string>

class Person {
	private:
		std::string first_name;
		std::string last_name;
		int age;
	public:
		Person (std::string, std::string, int);
		void getInfo();
};

#endif
