proj08: proj08.driver.o proj08.support.o
		gcc proj08.driver.o proj08.support.o -o proj08
		
proj08.driver.o: proj08.driver.c /user/cse320/Projects/project08.support.h
		gcc -Wall -c proj08.driver.c
		
proj08.support.o: proj08.support.s /user/cse320/Projects/project08.support.h
		gcc -march=native -c proj08.support.s
		
clean:
		rm -f run proj08.driver.o proj08.support.o
