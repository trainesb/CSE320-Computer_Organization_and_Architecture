run: proj07.student.o
		gcc proj07.student.o -o run

proj07.student.o: proj07.student.s
		gcc -Wall -c proj07.student.s
