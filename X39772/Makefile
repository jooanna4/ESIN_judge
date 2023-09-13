OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O0 -g -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: main.o mcj_enters.o
	g++ -o program.exe main.o mcj_enters.o
	rm *.o

solution.exe: main.o mcj_enters.o
	g++ -o solution.exe main.o mcj_enters.o
	rm *.o

main.o: main.cpp mcj_enters.hpp mcj_enters.rep
	g++ -c main.cpp $(OPCIONS)

mcj_enters.o: mcj_enters.cpp mcj_enters.hpp mcj_enters.rep
	g++ -c mcj_enters.cpp $(OPCIONS)

clean:
	rm *.o
	rm *.exe
	rm *.gch
