CMAKE_MINIMUM_REQUIRED(VERSION 3.0)
PROJECT(simple_student_mgmt_sys) 
INCLUDE_DIRECTORIES(include)
ADD_EXECUTABLE(
	simple_student_mgmt_sys
	src/main.cpp
	src/person.cpp
	src/student.cpp
	src/class.cpp
	src/options.cpp
)
