# Simple CLI-based Student Management System
I just made it to review C++ and to practice modern ways by following the C++ Core Guidelines. Feel free to use my code if you come across this repository by chance. Use the latest GCC or any compiler to make an executable file. I used Cppcheck static analysis tool to help me avoid dangerous coding constructs and bugs.
```
g++ -O3 -Wall -I include/ src/main.cpp src/person.cpp src/student.cpp src/class.cpp -o ./main.exe
```
```
cppcheck --enable=all --suppress=missingIncludeSystem -I include/ src/main.cpp src/person.cpp src/student.cpp src/class.cpp
```
