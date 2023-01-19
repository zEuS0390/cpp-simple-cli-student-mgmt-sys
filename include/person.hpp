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
		virtual void getInfo();
		virtual void setFirstName(std::string);
		virtual void setLastName(std::string);	
		virtual void setAge(int);
};

#endif
