app.exe: main.o User.o Cat.o Quiz.o
	g++ -std=c++17 -o app.exe main.o User.o Cat.o Quiz.o

main.o: main.cpp User.hpp Cat.hpp
	g++ -std=c++17 -c main.cpp

User.o: User.cpp User.hpp Cat.hpp
	g++ -std=c++17 -c User.cpp

Cat.o: Cat.cpp Cat.hpp
	g++ -std=c++17 -c Cat.cpp

Quiz.o: Quiz.cpp Quiz.hpp
	g++ -std=c++17 -c Quiz.cpp

clean:
	del /Q *.o *.exe 2> nul || rm -f *.o *.exe

