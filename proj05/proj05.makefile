run: proj05.driver.o
		gcc proj05.driver.o -o run
	
proj05.driver.o: proj05.driver.c proj05.support.c
		gcc -Wall -c proj05.driver.c proj05.support.c
