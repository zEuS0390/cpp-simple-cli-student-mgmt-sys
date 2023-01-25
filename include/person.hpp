#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <vector>
#include <variant>

class Person {
	private:
		std::string first_name;
		std::string last_name;
		int age;
	public:
		Person (const std::string&, const std::string&, int);
		virtual std::vector<std::variant<std::string, int>> getInfo();
		virtual void setFirstName(std::string);
		virtual void setLastName(std::string);	
		virtual void setAge(int);
};

#endif
