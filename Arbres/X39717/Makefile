OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: main.o abin.o solution.o
	g++ -o program.exe main.o abin.o solution.o
	rm *.o

solution.exe: main.o abin.o solution.o
	g++ -o solution.exe main.o abin.o solution.o
	rm *.o

solution.o: solution.cpp abin.hpp
	g++ -c solution.cpp $(OPCIONS)

main.o: main.cpp abin.hpp
	g++ -c main.cpp $(OPCIONS)

abin.o: abin.cpp abin.hpp
	g++ -c abin.cpp $(OPCIONS)

clean:
	rm *.o
	rm *.exe
	rm *.gch
