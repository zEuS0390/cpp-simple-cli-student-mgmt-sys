cmake_minimum_required(VERSION 3.0)
project(simple_student_mgmt_sys) 
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
include_directories(include)
add_executable(
	simple_student_mgmt_sys
	src/main.cpp
	src/person.cpp
	src/student.cpp
	src/class.cpp
	src/options.cpp
)
