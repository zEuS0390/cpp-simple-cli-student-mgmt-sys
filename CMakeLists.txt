CMAKE_MINIMUM_REQUIRED(VERSION 3.0)
PROJECT(simple_student_mgmt_sys) 
SET(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_STANDARD_REQUIRED True)
INCLUDE_DIRECTORIES(include)
ADD_EXECUTABLE(
	simple_student_mgmt_sys
	src/main.cpp
	src/person.cpp
	src/student.cpp
	src/class.cpp
	src/options.cpp
)
