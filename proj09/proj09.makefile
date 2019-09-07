proj09: /user/cse320/Projects/project09.driver.o proj09.support.o
		gcc /user/cse320/Projects/project09.driver.o proj09.support.o -o proj09

proj09.support.o: proj09.support.s /user/cse320/Projects/project09.support.h
		gcc -march=native -c proj09.support.s

clean:
		rm -f run proj09.support.o
