
all: student.o Source.o
	gcc -o output  student.cpp Source.cpp student.h

student.o: student.cpp student.h
	gcc -c student.cpp student.h

Source.o: student.h Source.cpp
	gcc -c student.h Source.cpp

