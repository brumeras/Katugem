app.exe: main.o User.o Cat.o
	g++ -std=c++17 -o app.exe main.o User.o Cat.o

main.o: main.cpp User.h Cat.h
	g++ -std=c++17 -c main.cpp

User.o: User.cpp User.h Cat.h
	g++ -std=c++17 -c User.cpp

Cat.o: Cat.cpp Cat.h
	g++ -std=c++17 -c Cat.cpp
