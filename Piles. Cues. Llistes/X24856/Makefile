OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: main.o cua.o solution.o
	g++ -o program.exe main.o cua.o solution.o
	rm *.o

solution.exe: main.o cua.o solution.o
	g++ -o solution.exe main.o cua.o solution.o
	rm *.o

solution.o: solution.cpp cua.hpp
	g++ -c solution.cpp $(OPCIONS)

main.o: main.cpp cua.hpp
	g++ -c main.cpp $(OPCIONS)

cua.o: cua.cpp cua.hpp
	g++ -c cua.cpp $(OPCIONS)

clean:
	rm *.o
	rm *.exe
	rm *.gch
