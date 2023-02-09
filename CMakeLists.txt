cmake_minimum_required(VERSION 3.0)
project(simple_student_mgmt_sys) 
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/include")
add_executable(
	simple_student_mgmt_sys
	src/main.cpp
	src/person.cpp
	src/student.cpp
	src/class.cpp
	src/options.cpp
)
target_include_directories(
	simple_student_mgmt_sys 
	PUBLIC
	"${EXTRA_INCLUDES}"
)
